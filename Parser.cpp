#include "Parser.h"

Parser::Parser(int argc, char* argv[]) {
  for(int i = 0; i < argc-1; i++)
    _isParameterChecked.push_back(false);
  for(int i = 1; i < argc; i++)
    _parameters.push_back(argv[i]); 
}

int Parser::init() {
  for(int i = 0; i < _parameters.size(); i++)
    if(_parameters[i].substr(0,2) == "--")
      _addCommand(_parameters[i], i);
  _runCommands();
  _checkIfAllParametersAreChecked();
  if(_mistakes.size()) {
    _printMistakes();
    std::cout << "\n"; 
    _printHelp();
    return 1;
  }
  if(!_task.size()) {
    Arguments args(INTERVALHOURS,0,2,0,0); 
    _addTask(args);
  }
  return 0;
}

int Parser::getTasksCount() {
  return _task.size();
}

void Parser::getTask(int numb, Arguments& args) {
  if(_task.size() < numb+1)
    return;
  switch(_task[numb][0]) {
    case 1:
      args.mode = INTERVALMINUTES;
      break;
    case 2:
      args.mode = INTERVALHOURS;
      break;
    case 3:
      args.mode = SETTIME;
      break;
  }
  args.arg1 = _task[numb][1];
  args.arg2 = _task[numb][2];
  args.arg3 = _task[numb][3];
  args.arg4 = _task[numb][4];
}

void Parser::_addTask(Arguments args) {
  const std::vector<int> k;
  _task.push_back(k);
  _task[_task.size() - 1].push_back(args.mode);
  _task[_task.size() - 1].push_back(args.arg1);
  _task[_task.size() - 1].push_back(args.arg2);
  _task[_task.size() - 1].push_back(args.arg3);
  _task[_task.size() - 1].push_back(args.arg4);
}

void Parser::_addMistake(const std::string& mist) {
  _mistakes.push_back(mist);
}

void Parser::_addCommand(const std::string& comm, int pos) {
  _commands.push_back(comm);
  _commandsPositions.push_back(pos);
}

void Parser::_printMistakes() {
  for(int i = 0; i < _mistakes.size(); i++)
    std::cout << _mistakes[i] << "\n";
}

void Parser::_printHelp() {
  std::cout << "FEATURED OPTIONS\n\t--help\n\t\tprint help\n\t";
  std::cout << "--interval\n\t\tset time interval in which system data and time will be updated: in minutes(last symbol in parameter 'm') ";
  std::cout << "or in hours(last symbol in parameter 'h')\n\t--time\n\t\t";
  std::cout << "set data and time on which system data and time will be updated. Format:";
  std::cout << "Month/Day hour:minute, you can use 'every' or 'every{'interval'}' instead of each instance\n";
}

void Parser::_runCommands() {
  for(int i = 0; i < _commands.size(); i++) {
    std::string c = _commands[i];
    int p = _commandsPositions[i];
    _isParameterChecked[p] = true;
    bool flag = false;
    if(c == "--help") {
      _printHelp();
      flag = true;
    }
    if(c == "--interval") {
      flag = true;
      _setInterval(p);
    }
    if(c == "--time") {
      flag = true;
      _setTimeInCrontabFile(p);
    }
    if(!flag) {
      std::string m = "Unexpected command: ";
      _addMistake(m+c);
    }
  }
}

void Parser::_setInterval(int pos) {
  if(pos+1 == _parameters.size()) {
    _addMistake("--interval: this command needs an argument");
    return;
  }
  _isParameterChecked[pos+1] = true;
  std::string lastSymbol = _parameters[pos+1].substr(_parameters[pos+1].length()-1,1);
  if(lastSymbol == "h")
    _setIntervalInHours(pos);
  else if(lastSymbol == "m")
    _setIntervalInMinutes(pos);
  else
    _addMistake("--interval: last symbol of argument should be either 'm'(for minutes) or 'h'(for hours)");
}

void Parser::_setIntervalInHours(int pos) {
  int hours = atoi(_parameters[pos+1].c_str());
  std::stringstream ss;
  ss << hours;
  std::string newArgHours = ss.str();
  bool flag = false;
  if(newArgHours.length() != _parameters[pos+1].length()-1 || (hours == 0 && _parameters[pos+1]!="0h")) {
    _addMistake("--interval: wrong argument. Argument of --interval(h) should be number of hours");
    flag = true;
  }
  if(hours > 23 || hours < 0 || (hours == 0 && _parameters[pos+1]=="0h")) {
    _addMistake("--interval: number of hours should be between 1 and 23");
    flag = true;
  }    
  if(!flag) {
    Arguments args(INTERVALHOURS,0,hours,0,0);
    _addTask(args);
  }
}

void Parser::_setIntervalInMinutes(int pos) {
  int minutes = atoi(_parameters[pos+1].c_str());
  std::stringstream ss;
  ss << minutes;
  std::string newArgMinutes = ss.str();
  bool flag = false;
  if(newArgMinutes.length() != _parameters[pos+1].length()-1 || (minutes == 0 && _parameters[pos+1]!="0m")) {
    _addMistake("--interval: wrong argument. Argument of --interval(m) should be number of minutes");
    flag = true;
  }
  if(minutes > 59 || minutes < 0 || (minutes == 0 && _parameters[pos+1]=="0m")) {
    _addMistake("--interval: number of minutess should be between 1 and 59");
    flag = true;
  }
  if(!flag) {
    Arguments args(INTERVALMINUTES,minutes,0,0,0);
    _addTask(args);
  }
}

void Parser::_setTimeInCrontabFile(int pos) {
  if(pos+1 == _parameters.size()  || pos+2 == _parameters.size()) {
    _addMistake("--time: this command needs two arguments");
    return;
  }
  _isParameterChecked[pos+1] = true;
  _isParameterChecked[pos+2] = true;
  std::string par1 = _parameters[pos+1];
  std::string par2 = _parameters[pos+2];
  std::string month;
  std::string day;
  std::string hour;
  std::string minute;
  int sepCount = 0;
  int flag = false;
  int pos1 = 0;
  int pos2 = 0;
  for(int i = 0; i < par1.length(); i++)
    if(par1.substr(i,1) == "/") {
      sepCount++;
      pos1 = i;
    }
  if(sepCount > 1) {
    _addMistake("--time: first argument: there should be only one separator '/' in this argument. format : --time Month/Day hour:minute");
    flag = true;
  }
  if(sepCount == 0) {
    _addMistake("--time: first argument: missing separator '/' in this argument. format : --time Month/Day hour:minute");
    flag = true;
  }
  sepCount = 0;
  for(int i = 0; i < par2.length(); i++)
    if(par2.substr(i,1) == ":") {
      sepCount++;
      pos2 = i;
    }
  if(sepCount > 1) {
    _addMistake("--time: second argument: there should be only one separator ':' in this argument. format : --time MM/DD hh:mm");
    flag = true;
  }
  if(sepCount == 0) {
    _addMistake("--time: second argument: missing separator ':' in this argument. format : --time MM/DD hh:mm");
    flag = true;
  }
  if(flag)
    return;
  month = par1.substr(0,pos1);
  day = par1.substr(pos1+1,par1.length()-pos1-1);
  hour = par2.substr(0,pos2);
  minute = par2.substr(pos2+1,par2.length()-pos2-1);
  int flagMonthEvery = 0;
  int flagDayEvery = 0;
  int flagHourEvery = 0;
  int flagMinuteEvery = 0;
  if(month.substr(0,6) == "every{" && month != "every" && month.substr(month.length()-1,1) == "}") {
    flagMonthEvery = 1;
    month = month.substr(6, month.length() - 7);
  }
  if(day.substr(0,6) == "every{" && day != "every" && day.substr(day.length()-1,1) == "}") {
    flagDayEvery = 1;
    day = day.substr(6, day.length() - 7);
  }
  if(hour.substr(0,6) == "every{" && hour != "every" && hour.substr(hour.length()-1,1) == "}") {
    flagHourEvery = 1;
    hour = hour.substr(6, hour.length() - 7);
  }
  if(minute.substr(0,6) == "every{" && minute != "every" && minute.substr(minute.length()-1,1) == "}") {
    flagMinuteEvery = 1;
    minute = minute.substr(6, minute.length() - 7);
  }
  int monthI = atoi(month.c_str());
  std::stringstream ss1;
  ss1 << monthI;
  std::string newArgMonth = ss1.str();
  flag = false;
  if((newArgMonth.length() != month.length() || (monthI == 0 && month != "0")) && month !="every") {
    _addMistake("--time: wrong argument in place of month or interval of months");
    flag = true;
  }
  if(monthI > 12 || monthI < 0 || (monthI == 0 && month == "0")) {
    _addMistake("--time: month or interval of months should be between 1 and 12");
    flag = true;
  }
  if(month == "every") 
    monthI = -1;
  if(flagMonthEvery)
    monthI -= 100;
  int dayI = atoi(day.c_str());
  std::stringstream ss2;
  ss2 << dayI;
  std::string newArgDay = ss2.str();
  if((newArgDay.length() != day.length() || (dayI == 0 && day != "0")) && day !="every") {
    _addMistake("--time: wrong argument in place of day or interval of days");
    flag = true;
  }
  if(dayI > 31 || dayI < 0 || (dayI == 0 && day == "0")) {
    _addMistake("--time: day or interval of days should be between 1 and 31");
    flag = true;
  }
  if(day == "every") 
    dayI = -1;
  if(flagDayEvery)
    dayI -= 100;
  int hourI = atoi(hour.c_str());
  std::stringstream ss3;
  ss3 << hourI;
  std::string newArgHour = ss3.str();
  if((newArgHour.length() != hour.length() || (hourI == 0 && hour != "0")) && hour !="every") {
    _addMistake("--time: wrong argument in place of hour or interval of hours");
    flag = true;
  }
  if(hourI > 23 || hourI < 0) {
    _addMistake("--time: hour or interval of hours should be between 0 and 23");
    flag = true;
  }
  if(hour == "every") 
    hourI = -1;
  if(flagHourEvery && !hourI) {
    _addMistake("--time: interval of hours shouldn't be 0");
    flag = true;
  }
  if(flagHourEvery)
    hourI -= 100;
  int minuteI = atoi(minute.c_str());
  std::stringstream ss4;
  ss4 << minuteI;
  std::string newArgMinute = ss4.str();
  if((newArgMinute.length() != minute.length() || (minuteI == 0 && minute != "0")) && minute !="every") {
    _addMistake("--time: wrong argument in place of minute or interval of minutes");
    flag = true;
  }
  if(minuteI > 59 || minuteI < 0) {
    _addMistake("--time: minute or interval of minutes should be between 0 and 59");
    flag = true;
  }
  if(minute == "every") 
    minuteI = -1;
  if(flagMinuteEvery && !minuteI) {
    _addMistake("--time: interval of minutes shouldn't be 0");
    flag = true;
  }
  if(flagMinuteEvery)
    minuteI -= 100;
  if(flag)
    return;
  Arguments args(SETTIME, minuteI, hourI, dayI, monthI);
  _addTask(args);
}

void Parser::_checkIfAllParametersAreChecked() {
  for(int i = 0; i < _parameters.size(); i++)
    if(!_isParameterChecked[i]) {
      std::string str1 = "Unknown argument: ";
      std::string str = str1 + _parameters[i];
      _addMistake(str);
    }
}
