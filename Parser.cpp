#include "Parser.h"

Parser::Parser(int argc, char* argv[]) {
  _h = -1;
  _m = -1;
  _s = -1;
  _setTimeMode = false;
  _commandCT = "/usr/bin/ntpdate pool.ntp.org";
  for(int i = 0; i < argc-1; i++)
    _doneMas.push_back(false);
  for(int i = 1; i < argc; i++)
    _massiveOfPar.push_back(argv[i]); 
}

std::string Parser::mgetpar(int n) {
  if(n < _massiveOfPar.size() && n > -1)
    return _massiveOfPar[n];
  else 
    return "Error";
}

int Parser::init() {
  for(int i = 0; i < _massiveOfPar.size(); i++)
    if(_massiveOfPar[i].substr(0,2) == "--")
      _addCommand(_massiveOfPar[i], i);
  _runCommands();
  _checkDoneMas();
  if(_mistakes.size()) {
    _printMistakes();
    std::cout << "\n"; 
    _printHelp();
    return 1;
  }
  if(!_task.size()) _addTask(2,0,2);
  return 0;
}

int Parser::getTasksCount() {
  return _task.size();
}

void Parser::getTask(int numb, int& mode, int& arg1, int& arg2) {
  mode = _task[numb][0];
  arg1 = _task[numb][1];
  arg2 = _task[numb][2];
}

void Parser::_addTask(int mode, int arg1, int arg2) {
  const std::vector<int> k;
  _task.push_back(k);
  _task[_task.size() - 1].push_back(mode);
  _task[_task.size() - 1].push_back(arg1);
  _task[_task.size() - 1].push_back(arg2);
}

void Parser::_addMistake(const std::string& mist) {
  _mistakes.push_back(mist);
}

void Parser::_addCommand(const std::string& comm, int pos) {
  _commands.push_back(comm);
  _commandsPoss.push_back(pos);
}

void Parser::_printMistakes() {
  for(int i = 0; i < _mistakes.size(); i++)
    std::cout << _mistakes[i] << "\n";
}

void Parser::_printHelp() {
  std::cout << "FEATURED OPTIONS\n\t--help\n\t\tprint help\n\t--settime XhYmZs\n\t\t";
  std::cout << "set time for the system: h - hours, m - minutes, s - seconds\n\t";
  std::cout << "--scct\n\t\tset command for crontab file. Wherever you need to print space, print '%' instead. Wherever you need to print '>', print '+' instead. ";
  std::cout << "By default it is /usr/sbin/ntpdate pool.ntp.org\n\t--interval\n\t\tset interval for cron in minutes(last symbol in parameter 'm') ";
  std::cout << "or in hours(last symbol in parameter 'h')\n\t--roxmyh\n\t\tset an hour and a minute in crontab file\n";
}

void Parser::_runCommands() {
  bool flagSetTime = false;
  bool flagSetTimeMist = false;
  bool flagscct = false;
  bool flagscctMist = false;
  for(int i = 0; i < _commands.size(); i++) {
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
    if(c == "--interval") {
      flag = true;
      _setInterval(p);
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
  if(pos+1 == _massiveOfPar.size()) {
    _addMistake("--settime: this command needs an argument");
    return;
  }
  _setTimeMode = true; 
  _doneMas[pos+1] = true;
  std::string arg = _massiveOfPar[pos+1];
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
  if(pos+1 == _massiveOfPar.size()) {
    _addMistake("--scct: this command needs an argument");
    return;
  }
  _commandCT = _massiveOfPar[pos+1];
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

void Parser::_setInterval(int pos) {
  if(pos+1 == _massiveOfPar.size()) {
    _addMistake("--interval: this command needs an argument");
    return;
  }
  _doneMas[pos+1] = true;
  std::string lastSymbol = _massiveOfPar[pos+1].substr(_massiveOfPar[pos+1].length()-1,1);
  if(lastSymbol == "h")
    _setIntervalInHours(pos);
  else if(lastSymbol == "m")
    _setIntervalInMinutes(pos);
  else
    _addMistake("--interval: last symbol of argument should be either 'm'(for minutes) or 'h'(for hours)");
}

void Parser::_setIntervalInHours(int pos) {
  int hours = atoi(_massiveOfPar[pos+1].c_str());
  std::stringstream ss;
  ss << hours;
  std::string newArgHours = ss.str();
  bool flag = false;
  if(newArgHours.length() != _massiveOfPar[pos+1].length()-1) {
    _addMistake("--interval: wrong argument. Argument of --interval(h) should be number of hours");
    flag = true;
  }
  if(hours > 23 || hours < 0) {
    _addMistake("--interval: number of hours should be between 0 and 23");
    flag = true;
  }
  if(24%hours) {
    _addMistake("--interval: number of hours should be a divisor of 24");
    flag = true;
  }
  if(!flag)
    _addTask(2,0,hours);
}

void Parser::_setIntervalInMinutes(int pos) {
  int minutes = atoi(_massiveOfPar[pos+1].c_str());
  std::stringstream ss;
  ss << minutes;
  std::string newArgMinutes = ss.str();
  bool flag = false;
  if(newArgMinutes.length() != _massiveOfPar[pos+1].length()-1) {
    _addMistake("--interval: wrong argument. Argument of --interval(m) should be number of minutes");
    flag = true;
  }
  if(minutes > 59 || minutes < 0) {
    _addMistake("--interval: number of minutess should be between 0 and 59");
    flag = true;
  }
  if(60%minutes) {
    _addMistake("--interval: number of minutess should be a divisor of 60");
    flag = true;
  }
  if(!flag)
    _addTask(1,minutes,0);
}

void Parser::_setHourAndMinuteInCrontabFile(int pos) {
  if(pos+1 == _massiveOfPar.size()  || pos+2 == _massiveOfPar.size()) {
    _addMistake("--roxmyh: this command needs two arguments");
    return;
  }
  _doneMas[pos+1] = true;
  _doneMas[pos+2] = true;
  bool astHflag = false;
  bool astMflag = false;
  if(_massiveOfPar[pos+1] == "%")
    astMflag = true;
  if(_massiveOfPar[pos+2] == "%")
    astHflag = true;
  int minutes = 0;
  int hours = 0;
  std::string newArgMinutes = "";
  std::string newArgHours = "";
  if(!astMflag) {
    minutes = atoi(_massiveOfPar[pos+1].c_str());
    std::stringstream ss1;
    ss1 << minutes;
    newArgMinutes = ss1.str();
  }
  if(!astHflag) {
    hours = atoi(_massiveOfPar[pos+2].c_str());
    std::stringstream ss2;
    ss2 << hours;
    newArgHours = ss2.str();
  }
  bool flag = false;
  if(!astMflag && (newArgMinutes.length() != _massiveOfPar[pos+1].length())) {
    _addMistake("--roxmyh: wrong first argument. First argument of --roxmyh should be number of minutes or %");
    flag = true;
  }
  if(!astHflag && (newArgHours.length() != _massiveOfPar[pos+2].length())) {
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
  for(int i = 0; i < _massiveOfPar.size(); i++)
    if(!_doneMas[i]) {
      std::string str1 = "Unknown argument: ";
      std::string str = str1 + _massiveOfPar[i];
      _addMistake(str);
    }
}

bool Parser::getSetTimeMode() {
  return _setTimeMode;
}
