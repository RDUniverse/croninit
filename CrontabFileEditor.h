#include <string>
#include <fstream>
#include <sstream>
#include "Parser.h"

class CrontabFileEditor{
  public:
    void init(Parser*);
    void run(Parser*);
  private:
    int _h;
    int _m;
    int _s;
    int _tasksCount;
    std::string _commandCT;
    void _setTime();
};
