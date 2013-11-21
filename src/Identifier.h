#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

class Identifier {
  public:
    int run();
    bool checkID(int);
  private:
    int _id;
    int _getIdSys();
};
