#include "Parser.h"

Parser::Parser(int argc, char* argv[]) {
  _h = -1;
  _m = -1;
  _s = -1;
  _nom = 0;
  _tasksCount = 0;
  _commandsCount = 0;
  _setTimeMode = false;
  _commandCT = "/usr/bin/ntpdate pool.ntp.org";
  _nol = argc-1;
  _doneMas = new bool[_nol];
  for(int i = 0; i<_nol; i++)
    _doneMas[i] = false;
  _mas = new std::string[_nol];
  for(int i = 1; i < argc; i++)
    _mas[i-1] = std::string(argv[i]); 
}

std::string Parser::mgetpar(int n) {
  if(n < _nol && n > -1)
    return _mas[n];
  else 
    return "Error";
}

int Parser::init() {
  for(int i = 0; i < _nol; i++)
    if(_mas[i].substr(0,2) == "--")
      _addCommand(_mas[i], i);
  _runCommands();
  _checkDoneMas();
  if(_nom) {
    _printMistakes();
    std::cout << "\n"; 
    _printHelp();
    return 1;
  }
  if(!_tasksCount) _addTask(2,0,2);
  return 0;
}

int Parser::getTasksCount() {
  return _tasksCount;
}

void Parser::getTask(int numb, int& mode, int& arg1, int& arg2) {
  mode = _modeOut[numb];
  arg1 = _arg1Out[numb];
  arg2 = _arg2Out[numb];
}

void Parser::_addTask(int mode, int arg1, int arg2) {
  if(_tasksCount) {
    int *temp1 = new int[_tasksCount];
    int *temp2 = new int[_tasksCount];
    int *temp3 = new int[_tasksCount];
    for(int i = 0; i < _tasksCount; i++)
      temp1[i] = _modeOut[i];
    for(int i = 0; i < _tasksCount; i++)
      temp2[i] = _arg1Out[i];
    for(int i = 0; i < _tasksCount; i++)
      temp3[i] = _arg2Out[i];
    delete[] _modeOut;
    delete[] _arg1Out;
    delete[] _arg2Out;
    _modeOut = new int[_tasksCount+1];
    _arg1Out = new int[_tasksCount+1];
    _arg2Out = new int[_tasksCount+1];
    for(int i = 0; i < _tasksCount; i++)
      _modeOut[i] = temp1[i];
    for(int i = 0; i < _tasksCount; i++)
      _arg1Out[i] = temp2[i];
    for(int i = 0; i < _tasksCount; i++)
      _arg2Out[i] = temp3[i];
    _modeOut[_tasksCount] = mode;
    _arg1Out[_tasksCount] = arg1;
    _arg2Out[_tasksCount] = arg2;
    delete[] temp1;
    delete[] temp2;
    delete[] temp3;
    _tasksCount++;
  } else {
    _modeOut = new int[1];
    _modeOut[0] = mode;
    _arg1Out = new int[1];
    _arg1Out[0] = arg1;
    _arg2Out = new int[1];
    _arg2Out[0] = arg2;
    _tasksCount = 1;
  }
}

void Parser::_addMistake(const std::string& mist) {
  if(_nom) {
    std::string *temp = new std::string[_nom];
    for(int i = 0; i < _nom; i++)
      temp[i] = _mistakes[i];
    delete[] _mistakes;
    _mistakes = new std::string[_nom+1];
    for(int i = 0; i < _nom; i++)
      _mistakes[i] = temp[i];
    _mistakes[_nom] = mist;
    delete[] temp;
    _nom++;
  } else {
    _mistakes = new std::string[1];
    _mistakes[0] = mist;
    _nom = 1;
  }
}

void Parser::_addCommand(const std::string& comm, int pos) {
  if(_commandsCount) {
    std::string *temp = new std::string[_commandsCount];
    for(int i = 0; i < _commandsCount; i++)
      temp[i] = _commands[i];
    delete[] _commands;
    _commands = new std::string[_commandsCount+1];
    for(int i = 0; i < _commandsCount; i++)
      _commands[i] = temp[i];
    _commands[_commandsCount] = comm;
    delete[] temp;
    int* tempI = new int[_commandsCount];
    for(int i = 0; i < _commandsCount; i++)
      tempI[i] = _commandsPoss[i];
    delete[] _commandsPoss;
    _commandsPoss = new int[_commandsCount+1];
    for(int i = 0; i < _commandsCount; i++)
      _commandsPoss[i] = tempI[i];
    _commandsPoss[_commandsCount] = pos;
    delete[] tempI;
    _commandsCount++;
  } else {
    _commands = new std::string[1];
    _commands[0] = comm;
    _commandsPoss = new int[1];
    _commandsPoss[0] = pos;
    _commandsCount = 1;
  }
}

void Parser::_printMistakes() {
  for(int i = 0; i < _nom ; i++)
    std::cout << _mistakes[i] << "\n";
}

void Parser::_printHelp() {
  std::cout << "FEATURED OPTIONS\n\t--help\n\t\tprint help\n\t--settime XhYmZs\n\t\t";
  std::cout << "set time for the system: h - hours, m - minutes, s - seconds\n\t";
  std::cout << "--scct\n\t\tset command for crontab file. Wherever you need to print space, print '%' instead. Wherever you need to print '>', print '+' instead. ";
  std::cout << "By default it is /usr/sbin/ntpdate pool.ntp.org\n\t--siim\n\t\tset interval for cron in minutes\n\t--siih\n\t\t";
  std::cout << "set interval for cron in hours\n\t--roxmyh\n\t\tset an hour and a minute in crontab file\n";
}

void Parser::_runCommands() {
  bool flagSetTime = false;
  bool flagSetTimeMist = false;
  bool flagscct = false;
  bool flagscctMist = false;
  for(int i = 0; i < _commandsCount; i++) {
    std::string c = _commands[i];
    int p = _commandsPoss[i];
    _doneMas[p] = true;
    bool flag = false;
    if(c == "--help") {
      _printHelp();
      flag = true;
      _doneMas[p] = true;
    }
    if(c == "--settime") { 
      flag = true;
      if(!flagSetTime) {
        _setTime(p);
        flagSetTime = true;
      } else
	  if(!flagSetTimeMist) {
            _addMistake("There can be only one of the following command: --settime");
            flagSetTimeMist = true;
          }
    }
    if(c == "--siim") {
      flag = true;
      _setIntervalInMinutes(p);
    }
    if(c == "--siih") {
      flag = true;
      _setIntervalInHours(p);
    }
    if(c == "--roxmyh") {
      flag = true;
      _setHourAndMinuteInCrontabFile(p);
    }
    if(c == "--scct") { 
      flag = true;
      if(!flagscct) {
        _setCommandCT(p);
        flagscct = true;
      } else
	  if(!flagscctMist) {
            _addMistake("There can be only one of the following command: --scct");
            flagscctMist = true;
          }
    }
    if(!flag) {
      std::string m = "Unexpected command: ";
      _addMistake(m+c);
    }
  }
}

void Parser::_setTime(int pos) {
  if(pos+1 == _nol) {
    _addMistake("--settime: this command needs an argument");
    return;
  }
  _setTimeMode = true; 
  _doneMas[pos+1] = true;
  std::string arg = _mas[pos+1];
  int ph = -1;
  int pm = -1;
  int ps = -1;
  int ch = 0;
  int cm = 0;
  int cs = 0;
  for(int i = 0; i < arg.length(); i++) {
    if(arg.substr(i,1) == "h") {
      ph = i;
      ch++;
    }
    if(arg.substr(i,1) == "m") {
      pm = i;
      cm++;
    }
    if(arg.substr(i,1) == "s") {
      ps = i;
      cs++;
    }
  }
  bool flag = false;
  if(ch > 1) {
    _addMistake("--settime: unexpected number of hours modifiers");
    flag = true;
  }
  if(cm > 1) {
    _addMistake("--settime: unexpected number of minutes modifiers");
    flag = true;
  }
  if(cs > 1) {
    _addMistake("--settime: unexpected number of seconds modifiers");
    flag = true;
  }
  if(flag)
    return;
  int *tmp = new int[3];
  tmp[0] = ph;
  tmp[1] = pm;
  tmp[2] = ps;
  if(tmp[0]>tmp[1]) {
    int temp = tmp[0];
    tmp[0] = tmp[1];
    tmp[1] = temp;
  }
  if(tmp[1]>tmp[2]) {
    int temp = tmp[1];
    tmp[1] = tmp[2];
    tmp[2] = temp;
  }
  if(tmp[0]>tmp[1]) {
    int temp = tmp[0];
    tmp[0] = tmp[1];
    tmp[1] = temp;
  }
  if(tmp[2] == -1) {
    _addMistake("--settime: missing time modifiers (h,m,s)");
    return;
  }
  if(tmp[2] != arg.length()-1)
    _addMistake("--settime: unexpected argument");
  std::string minutes;
  bool ism = false;
  std::string hours;
  bool ish = false;
  std::string seconds;
  bool iss = false;
  if(tmp[0] > -1) {
    if(tmp[0] == ph) {
      ish = true;
      hours = arg.substr(0,ph);
    }
    if(tmp[0] == pm) {
      ism = true;
      minutes = arg.substr(0,pm);
    }
    if(tmp[0] == ps) {
      iss = true;
      seconds = arg.substr(0,ps);
    }
  }
  if(tmp[1] > -1) {
    if(tmp[1] == ph) {
      ish = true;
      hours = arg.substr(tmp[0]+1,ph-tmp[0]-1);
    }
    if(tmp[1] == pm) {
      ism = true;
      minutes = arg.substr(tmp[0]+1,pm-tmp[0]-1);
    }
    if(tmp[1] == ps) {
      iss = true;
      seconds = arg.substr(tmp[0]+1,ps-tmp[0]-1);
    }
  }
  if(tmp[2] > -1) {
    if(tmp[2] == ph) {
      ish = true;
      hours = arg.substr(tmp[1]+1,ph-tmp[1]-1);
    }
    if(tmp[2] == pm) {
      ism = true;
      minutes = arg.substr(tmp[1]+1,pm-tmp[1]-1);
    }
    if(tmp[2] == ps) {
      iss = true;
      seconds = arg.substr(tmp[1]+1,ps-tmp[1]-1);
    }
  }
  if(ish) {
    _h = atoi(hours.c_str());
    std::stringstream ss;
    ss << _h;
    std::string _hStr = ss.str();
    if(_hStr.length() != hours.length() || _h == 0)
      _addMistake("--settime: hours: unexpected number");
  }
  if(ism) {
    _m = atoi(minutes.c_str());
    std::stringstream ss;
    ss << _m;
    std::string _mStr = ss.str();
    if(_mStr.length() != minutes.length() || _m == 0)
      _addMistake("--settime: minutes: unexpected number");
  }
  if(iss) {
    _s = atoi(seconds.c_str());
    std::stringstream ss;
    ss << _s;
    std::string _sStr = ss.str();
    if(_sStr.length() != seconds.length() || _s == 0)
      _addMistake("--settime: seconds: unexpected number");
  }
  if(_h>23 || _h<-1)
    _addMistake("--settime: number of hours should be between 0 and 23");
  if(_m>59 || _m<-1)
    _addMistake("--settime: number of minutes should be between 0 and 59");
  if(_s>59 || _s<-1)
    _addMistake("--settime: number of seconds should be between 0 and 59");    
}

std::string Parser::getCommandCT() {
  return _commandCT;
}

void Parser::_setCommandCT(int pos) {
  if(pos+1 == _nol) {
    _addMistake("--scct: this command needs an argument");
    return;
  }
  _commandCT = _mas[pos+1];
  _doneMas[pos+1] = true;
  for(int i = 0; i < _commandCT.length(); i++) {
    if(_commandCT.substr(i,1) == "%") {
      std::string bl = " ";
      _commandCT = _commandCT.substr(0,i) + bl + _commandCT.substr(i+1,_commandCT.length()-i);
    }
    if(_commandCT.substr(i,1) == "+") {
      std::string bl = ">";
      _commandCT = _commandCT.substr(0,i) + bl + _commandCT.substr(i+1,_commandCT.length()-i);
    }
  }
}

void Parser::_setIntervalInHours(int pos) {
  if(pos+1 == _nol) {
    _addMistake("--siih: this command needs an argument");
    return;
  }
  _doneMas[pos+1] = true;
  int hours = atoi(_mas[pos+1].c_str());
  std::stringstream ss;
  ss << hours;
  std::string newArgHours = ss.str();
  bool flag = false;
  if(newArgHours.length() != _mas[pos+1].length()) {
    _addMistake("--siih: wrong argument. Argument of --siih should be number of hours");
    flag = true;
  }
  if(hours > 23 || hours < 0) {
    _addMistake("--siih: number of hours should be between 0 and 23");
    flag = true;
  }
  if(24%hours) {
    _addMistake("--siih: number of hours should be a divisor of 24");
    flag = true;
  }
  if(!flag)
    _addTask(2,0,hours);
}

void Parser::_setIntervalInMinutes(int pos) {
  if(pos+1 == _nol) {
    _addMistake("--siim: this command needs an argument");
    return;
  }
  _doneMas[pos+1] = true;
  int minutes = atoi(_mas[pos+1].c_str());
  std::stringstream ss;
  ss << minutes;
  std::string newArgMinutes = ss.str();
  bool flag = false;
  if(newArgMinutes.length() != _mas[pos+1].length()) {
    _addMistake("--siim: wrong argument. Argument of --siim should be number of minutess");
    flag = true;
  }
  if(minutes > 59 || minutes < 0) {
    _addMistake("--siim: number of minutess should be between 0 and 59");
    flag = true;
  }
  if(60%minutes) {
    _addMistake("--siim: number of minutess should be a divisor of 60");
    flag = true;
  }
  if(!flag)
    _addTask(1,minutes,0);
}

void Parser::_setHourAndMinuteInCrontabFile(int pos) {
  if(pos+1 == _nol  || pos+2 == _nol) {
    _addMistake("--roxmyh: this command needs two arguments");
    return;
  }
  _doneMas[pos+1] = true;
  _doneMas[pos+2] = true;
  bool astHflag = false;
  bool astMflag = false;
  if(_mas[pos+1] == "%")
    astMflag = true;
  if(_mas[pos+2] == "%")
    astHflag = true;
  int minutes = 0;
  int hours = 0;
  std::string newArgMinutes = "";
  std::string newArgHours = "";
  if(!astMflag) {
    minutes = atoi(_mas[pos+1].c_str());
    std::stringstream ss1;
    ss1 << minutes;
    newArgMinutes = ss1.str();
  }
  if(!astHflag) {
    hours = atoi(_mas[pos+2].c_str());
    std::stringstream ss2;
    ss2 << hours;
    newArgHours = ss2.str();
  }
  bool flag = false;
  if(!astMflag && (newArgMinutes.length() != _mas[pos+1].length())) {
    _addMistake("--roxmyh: wrong first argument. First argument of --roxmyh should be number of minutes or %");
    flag = true;
  }
  if(!astHflag && (newArgHours.length() != _mas[pos+2].length())) {
    _addMistake("--roxmyh: wrong second argument. Second argument of --roxmyh should be number of hours or %");
    flag = true;
  }
  if(!astMflag && (minutes > 59 || minutes < 0)) {
    _addMistake("--roxmyh: number of minutess should be between 0 and 59");
    flag = true;
  }
  if(!astHflag && (hours > 23 || hours < 0)) {
    _addMistake("--roxmyh: number of hours should be between 0 and 23");
    flag = true;
  }
  if(!flag) {
    if(astMflag && astHflag)
      _addTask(3,-1,-1);
    if(!astMflag && astHflag)
      _addTask(3,minutes,-1);
    if(astMflag && !astHflag)
      _addTask(3,-1,hours);
    if(!astMflag && !astHflag)
      _addTask(3,minutes,hours);
  }
}

int Parser::getMinutes() {
  return _m;
}

int Parser::getHours() {
  return _h;
}

int Parser::getSeconds() {
  return _s;
}

void Parser::_checkDoneMas() {
  for(int i = 0; i < _nol; i++)
    if(!_doneMas[i]) {
      std::string str1 = "Unknown argument: ";
      std::string str = str1 + _mas[i];
      _addMistake(str);
    }
}

bool Parser::getSetTimeMode() {
  return _setTimeMode;
}
