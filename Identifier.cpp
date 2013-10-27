#include "Identifier.h"

int Identifier::_getUsernameSys() {
  FILE *mStream;
  const int bufS = 255;
  char buf[bufS];
  mStream = popen("whoami", "r");
  while(!fgets(buf, bufS, mStream));
  std::string rslt = std::string(buf);
  int l = rslt.length();
  _username = rslt.substr(0,l-1);
  pclose(mStream);
  char buf2[bufS];
  mStream = popen("id -u", "r");
  while(!fgets(buf2, bufS, mStream));
  std::string rslt2 = std::string(buf2);
  int l2 = rslt2.length();
  std::string idStr = rslt2.substr(0,l2-1);
  _id = atoi(idStr.c_str());
  pclose(mStream);
  return 0;
}

bool Identifier::check(const std::string& chStr) {
  if(chStr == _username) return true;
  else return false;
}

bool Identifier::checkID(int id) {
  if(_id == id) return true;
  else return false;
}

std::string Identifier::getUsername() {
  return _username;
}

int Identifier::run() {
  if(_getUsernameSys()) return 1;
  else return 0;
}
