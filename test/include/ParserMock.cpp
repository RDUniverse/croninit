#include <ParserMock.h>

ParserMock::ParserMock(const std::string& par1, const std::string& par2) {
  _tasks.clear();
  _parameters.push_back("--time");
  _parameters.push_back(par1);
  _parameters.push_back(par2);
}

int ParserMock::setTimeInCrontabFileMock(Arguments& task) {
  Parser::_setTimeInCrontabFile(0);
  if(!_task.size()) {
    task = _task[0];
    return 0;
  } else {
    return 1;
  }  
}
