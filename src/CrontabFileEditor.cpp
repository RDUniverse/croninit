#include "CrontabFileEditor.h"

void CrontabFileEditor::init(Parser* parser) {
  _tasksCount = parser->getTasksCount();
  _serverList = "pool.ntp.org";
  parser->getServerList(_serverList);
  for(int i = 0; i < _tasksCount; i++) {
    Arguments args;
    _tasks.push_back(args);
    parser->getTask(i, _tasks[i]);
  }
  _linesForCrontabFile = _getLinesForCrontabFile();
}

void CrontabFileEditor::run() {
  system("touch ctf");
  system("rm ctf");
  std::ofstream fstrm;
  fstrm.open("ctf");
  fstrm << _linesForCrontabFile;
  fstrm.close();
  system("crontab ctf");
  system("rm ctf")  
}

std::string CrontabFileEditor::_getLinesForCrontabFile() {
  std::string result = "";
  std::string commandCT = "/usr/bin/ntpdate ";
  Arguments args;
  for(int i = 0; i < _tasksCount; i++) {
    args = _tasks[i];
    std::stringstream ss1;
    if(args.minute.mode == INTERVAL) 
      ss1 << "*/";
    ss1 << args.minute.value;
    std::string minute = ss1.str();
    std::stringstream ss2;
    if(args.hour.mode == INTERVAL)
      ss2 << "*/";
    ss2 << args.hour.value;
    std::string hour = ss2.str();
    std::stringstream ss3;
    if(args.day.mode == INTERVAL) 
      ss3 << "*/";
    ss3 << args.day.value;
    std::string day = ss3.str();
    std::stringstream ss4;
    if(args.month.mode == INTERVAL) 
      ss4 << "*/";
    ss4 << args.month.value;
    std::string month = ss4.str();
    if(args.minute.mode != EVERY)
      result += minute;
    else
      result += "*";
    result += " ";
    if(args.hour.mode != EVERY)
      result += hour; 
    else
      result += "*";
    result+=" ";
    if(args.day.mode != EVERY)
      result += day;
    else
      result += "*";
    result+=" ";
    if(args.month.mode != EVERY)
      result += month;
    else
      result += "*";
    result += " * ";
    result += commandCT;
    result += _serverList;
    result += "\n";
  }
  return result;
}
