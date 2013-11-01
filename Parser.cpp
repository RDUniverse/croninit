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
    ModeAndValue arg1 = {0,0};
    ModeAndValue arg2 = {1,0};
    ModeAndValue arg3 = {2,2};
    Arguments args(arg2,arg3,arg1,arg1); 
    _addTask(args);
  }
  return 0;
}

int Parser::getTasksCount() {
  return _task.size();
}

void Parser::getTask(int numb, Arguments& args) {
  args.arg1.value = _task[numb][0].value;
  args.arg2.value = _task[numb][1].value;
  args.arg3.value = _task[numb][2].value;
  args.arg4.value = _task[numb][3].value;
  args.arg1.mode = _task[numb][0].mode;
  args.arg2.mode = _task[numb][1].mode;
  args.arg3.mode = _task[numb][2].mode;
  args.arg4.mode = _task[numb][3].mode;
}

void Parser::_addTask(Arguments args) {
  std::vector<ModeAndValue> k;
  args.convertToVector(k);
  _task.push_back(k);
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
  std::cout << "--time\n\t\t";
  std::cout << "set data and time for the updating data and time on the machine\n\t\tFormat:\n\t\t\t";
  std::cout << "Month/Day hour:minute, where:\n\t\t\t\t";
  std::cout << "Month: between 1 and 12 or 'every' for every month or 'every{'interval'}',\n\t\t\t\t\t";
  std::cout << "where interval is between 1 and 12\n\t\t\t\t";
  std::cout << "Day: between 1 and 31 or 'every' for every day or 'every{'interval'}',\n\t\t\t\t\t";
  std::cout << "where interval is between 1 and 31\n\t\t\t\t";
  std::cout << "hour: between 0 and 23 or 'every' for every hour or 'every{'interval'}',\n\t\t\t\t\t";
  std::cout << "where interval is between 1 and 23\n\t\t\t\t";
  std::cout << "minute: between 0 and 59 or 'every' for every minute or 'every{'interval'}',\n\t\t\t\t\t";
  std::cout << "where interval is between 1 and 59\n\t\t\t\t\n";
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

void Parser::_setTimeInCrontabFile(int pos) {
  if(pos+1 == _parameters.size()  || pos+2 == _parameters.size()) {
    _addMistake("--time: wrong format of date");
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
    _addMistake("--time:there should be only one separator '/', that devides month and day. Format : --time Month/Day hour:minute");
    flag = true;
  }
  if(sepCount == 0) {
    _addMistake("--time: missing separator '/'. Format : --time Month/Day hour:minute");
    flag = true;
  }
  sepCount = 0;
  for(int i = 0; i < par2.length(); i++)
    if(par2.substr(i,1) == ":") {
      sepCount++;
      pos2 = i;
    }
  if(sepCount > 1) {
    _addMistake("--time: there should be only one separator ':', that devides hour and minute. Format : --time Month/Day hour:minute");
    flag = true;
  }
  if(sepCount == 0) {
    _addMistake("--time: missing separator ':'. Format : --time Month/Day hour:minute");
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
  ModeAndValue monthI = {1,0};
  monthI.value = atoi(month.c_str());
  std::stringstream ss1;
  ss1 << monthI.value;
  std::string newArgMonth = ss1.str();
  flag = false;
  if((newArgMonth.length() != month.length() || (monthI.value == 0 && month != "0")) && month !="every") {
    _addMistake("--time: wrong argument in place of month or interval of months");
    flag = true;
  }
  if(monthI.value > 12 || monthI.value < 0 || (monthI.value == 0 && month == "0")) {
    _addMistake("--time: month or interval of months should be between 1 and 12");
    flag = true;
  }
  if(month == "every") 
    monthI.mode = 0;
  if(flagMonthEvery)
    monthI.mode = 2;
  ModeAndValue dayI = {1,0};
  dayI.value = atoi(day.c_str());
  std::stringstream ss2;
  ss2 << dayI.value;
  std::string newArgDay = ss2.str();
  if((newArgDay.length() != day.length() || (dayI.value == 0 && day != "0")) && day !="every") {
    _addMistake("--time: wrong argument in place of day or interval of days");
    flag = true;
  }
  if(dayI.value > 31 || dayI.value < 0 || (dayI.value == 0 && day == "0")) {
    _addMistake("--time: day or interval of days should be between 1 and 31");
    flag = true;
  }
  if(day == "every") 
    dayI.mode = 0;
  if(flagDayEvery)
    dayI.mode = 2;
  ModeAndValue hourI = {1,0};
  hourI.value = atoi(hour.c_str());
  std::stringstream ss3;
  ss3 << hourI.value;
  std::string newArgHour = ss3.str();
  if((newArgHour.length() != hour.length() || (hourI.value == 0 && hour != "0")) && hour !="every") {
    _addMistake("--time: wrong argument in place of hour or interval of hours");
    flag = true;
  }
  if(hourI.value > 23 || hourI.value < 0) {
    _addMistake("--time: hour or interval of hours should be between 0 and 23");
    flag = true;
  }
  if(hour == "every") 
    hourI.mode = 0;
  if(flagHourEvery && hourI.value == 0 && hour == "0") {
    _addMistake("--time: interval of hours shouldn't be 0");
    flag = true;
  }
  if(flagHourEvery)
    hourI.mode = 2;
  ModeAndValue minuteI = {1,0};
  minuteI.value = atoi(minute.c_str());
  std::stringstream ss4;
  ss4 << minuteI.value;
  std::string newArgMinute = ss4.str();
  if((newArgMinute.length() != minute.length() || (minuteI.value == 0 && minute != "0")) && minute !="every") {
    _addMistake("--time: wrong argument in place of minute or interval of minutes");
    flag = true;
  }
  if(minuteI.value > 59 || minuteI.value < 0) {
    _addMistake("--time: minute or interval of minutes should be between 0 and 59");
    flag = true;
  }
  if(minute == "every") 
    minuteI.mode = 0;
  if(flagMinuteEvery && minuteI.value == 0 && minute == "0") {
    _addMistake("--time: interval of minutes shouldn't be 0");
    flag = true;
  }
  if(flagMinuteEvery)
    minuteI.mode = 2;
  if(flag)
    return;
  Arguments args(minuteI, hourI, dayI, monthI);
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
