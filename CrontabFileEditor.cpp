#include "CrontabFileEditor.h"

void CrontabFileEditor::init(Parser* parser) {
  _tasksCount = parser->getTasksCount();
  _serverList = "pool.ntp.org";
}

void CrontabFileEditor::run(Parser* parser) {
  system("touch ctf");
  system("rm ctf");
  std::ofstream fstrm;
  fstrm.open("ctf");
  std::string result = "";
  std::string commandCT = "/usr/bin/ntpdate ";
  ModeAndValue mav = {1,0};
  Arguments args(mav,mav,mav,mav);
  for(int i = 0; i < _tasksCount; i++) {
    parser->getTask(i,args);
    std::stringstream ss1;
    if(args.arg1.mode == 2) 
      ss1 << "*/";
    ss1 << args.arg1.value;
    std::string minute = ss1.str();
    std::stringstream ss2;
    if(args.arg2.mode == 2)
      ss2 << "*/";
    ss2 << args.arg2.value;
    std::string hour = ss2.str();
    std::stringstream ss3;
    if(args.arg3.mode == 2) 
      ss3 << "*/";
    ss3 << args.arg3.value;
    std::string day = ss3.str();
    std::stringstream ss4;
    if(args.arg4.mode == 2) 
      ss4 << "*/";
    ss4 << args.arg4.value;
    std::string month = ss4.str();
    if(args.arg1.mode)
      result += minute;
    else
      result += "*";
    result += " ";
    if(args.arg2.mode)
      result += hour; 
    else
      result += "*";
    result+=" ";
    if(args.arg3.mode)
      result += day;
    else
      result += "*";
    result+=" ";
    if(args.arg4.mode)
      result += month;
    else
      result += "*";
    result += " * ";
    result += commandCT;
    parser->getServerList(_serverList);
    result += _serverList;
    result += "\n";
  }
  fstrm << result;
  fstrm.close();
  system("crontab ctf");  
}

