#include <string>
#include <fstream>
#include <sstream>
#include "Parser.h"
#include "Arguments.h"

class CrontabFileEditor{
  public:
    void init(Parser*);
    void run(Parser*);
  private:
    int _tasksCount;
};
