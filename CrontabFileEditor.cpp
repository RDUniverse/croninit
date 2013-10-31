#include "CrontabFileEditor.h"

void CrontabFileEditor::init(Parser* parser) {
  _tasksCount = parser->getTasksCount();
}

void CrontabFileEditor::run(Parser* parser) {
  system("touch ctf");
  system("rm ctf");
  std::ofstream fstrm;
  fstrm.open("ctf");
  std::string result = "";
  std::string commandCT = "/usr/bin/ntpdate pool.ntp.org";
  Arguments args(FORMATTED_TIME,0,0,0,0);
  for(int i = 0; i < _tasksCount; i++) {
    parser->getTask(i,args);
    switch(args.mode) {
      case INTERVAL_MINUTES: {
        std::stringstream ss;
        ss << args.arg1;
        std::string minutes = ss.str();
        result += "*/";
        result += minutes;
        result += " * * * * ";
        result += commandCT;
        result += "\n";
        break;
      }
      case INTERVAL_HOURS: {
        std::stringstream ss;
        ss << args.arg2;
        std::string hours = ss.str();
        result += "0 */";
        result += hours;
        result += " * * * ";
        result += commandCT;
        result += "\n";
        break;
      }
      case FORMATTED_TIME: {
        std::stringstream ss1;
        if(args.arg1 < -1) {
          ss1 << "*/";
          args.arg1+=100;
        }
        ss1 << args.arg1;
        std::string minute = ss1.str();
        std::stringstream ss2;
        if(args.arg2 < -1) {
          ss2 << "*/";
          args.arg2+=100;
        }
        ss2 << args.arg2;
        std::string hour = ss2.str();
        std::stringstream ss3;
        if(args.arg3 < -1) {
          ss3 << "*/";
          args.arg3+=100;
        }
        ss3 << args.arg3;
        std::string day = ss3.str();
        std::stringstream ss4;
        if(args.arg4 < -1) {
          ss4 << "*/";
          args.arg4+=100;
        }
        ss4 << args.arg4;
        std::string month = ss4.str();
        if(args.arg1 != -1)
          result += minute;
        else
          result += "*";
        result += " ";
        if(args.arg2 != -1)
          result += hour; 
        else
          result += "*";
        result+=" ";
        if(args.arg3 != -1)
          result += day;
        else
          result += "*";
        result+=" ";
        if(args.arg4 != -1)
          result += month;
        else
          result += "*";
        result += " * ";
        result += commandCT;
        result += "\n";
        break;
      }
    }
  }
  fstrm << result;
  fstrm.close();
  system("crontab ctf");  
}

