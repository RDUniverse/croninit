#include "CrontabFileEditor.h"

void CrontabFileEditor::init(Parser* PAR) {
  _s = PAR->getSeconds();
  _m = PAR->getMinutes();
  _h = PAR->getHours();
  _commandCT = PAR->getCommandCT();
  _tasksCount = PAR->getTasksCount();
}

void CrontabFileEditor::run(Parser* PAR) {
  if(PAR->getSetTimeMode()) 
    _setTime();
  system("touch ctf");
  system("rm ctf");
  std::ofstream fstrm;
  fstrm.open("ctf");
  std::string result = "";
  int mode = 0;
  int arg1 = 0;
  int arg2 = 0;
  int arg3 = 0;
  int arg4 = 0;
  for(int i = 0; i < _tasksCount; i++) {
    PAR->getTask(i,mode,arg1,arg2,arg3,arg4);
    if(mode == 1) {
      std::stringstream ss;
      ss << arg1;
      std::string minutes = ss.str();
      result += "*/";
      result += minutes;
      result += " * * * * ";
      result += _commandCT;
      result += "\n";
    }
    if(mode == 2) {
      std::stringstream ss;
      ss << arg2;
      std::string hours = ss.str();
      result += "0 */";
      result += hours;
      result += " * * * ";
      result += _commandCT;
      result += "\n";
    }
    if(mode == 3) {
      std::stringstream ss1;
      ss1 << arg1;
      std::string minutes = ss1.str();
      std::stringstream ss2;
      ss2 << arg2;
      std::string hours = ss2.str();
      if(arg1 != -1)
        result += minutes;
      else
        result += "*";
      result += " ";
      if(arg2 != -1)
        result += hours;
      else
        result += "*";
      result += " * * * ";
      result += _commandCT;
      result += "\n";
    }
  }
  fstrm << result;
  fstrm.close();
  system("crontab ctf");  
}

void CrontabFileEditor::_setTime() {
  FILE* strm;
  char buf[100];
  strm = popen("date +%D","r");
  while(!fgets(buf,100,strm));
  pclose(strm);
  std::string strDate = std::string(buf);
  std::string strMonth = strDate.substr(0,2);
  std::string strDay = strDate.substr(3,2);
  FILE* strm2;
  char buf2[100];
  strm2 = popen("date +%T","r");
  while(!fgets(buf2,100,strm2));
  pclose(strm2);
  std::string strTime = std::string(buf2);
  std::string strHour = strTime.substr(0,2);
  std::string strMinute = strTime.substr(3,2);
  std::string strSecond = strTime.substr(6,2);
  std::string beginning = "date ";
  std::string dot = ".";
  std::cout << _h << _m << _s << "\n";
  if(_h > -1) {
    std::stringstream ss;
    ss << _h;
    strHour = ss.str();
    if(_h<10)
      strHour = "0"+strHour;
  }
  if(_m > -1) {
    std::stringstream ss;
    ss << _m;
    strMinute = ss.str();
    if(_m<10)
      strMinute = "0"+strMinute;
  }
  if(_s > -1) {
    std::stringstream ss;
    ss << _s;
    strSecond = ss.str();
    if(_s<10)
      strSecond = "0"+strSecond;
  }
  std::string result = beginning + strMonth + strDay + strHour + strMinute + dot + strSecond;
  system(result.c_str()); 
}

