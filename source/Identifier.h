#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

class Identifier {
  public:
    int run();
    bool check(const std::string&);
    bool checkID(int);
    std::string getUsername();
  private:
    int _id;
    std::string _username;
    int _getUsernameSys();
};
