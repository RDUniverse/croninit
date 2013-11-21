#include "Identifier.h"

int Identifier::_getIdSys() {
  FILE *mStream;
  const int bufS = 255;
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

bool Identifier::checkID(int id) {
  if(_id == id)  
    return true;
  else 
    return false;
}

int Identifier::run() {
  if(_getIdSys()) 
    return 1;
  else 
    return 0;
}
