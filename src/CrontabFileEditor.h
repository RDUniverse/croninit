#include <string>
#include <fstream>
#include <sstream>
#include "Parser.h"
#include "Arguments.h"

class CrontabFileEditor{
  public:
    void init(Parser*);
    void run();
  private:
    int _tasksCount;
    std::string _linesForCrontabFile;
    std::string _serverList;
    std::string _getLinesForCrontabFile(Parser*);
};
