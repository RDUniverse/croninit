#pragma once
#include <iostream>
#define private protected
#include <Parser.h>

class ParserMock : public Parser {
  public:
    ParserMock() : Parser(0,0) {};
    int setTimeInCrontabFileMock(const std::string& par1, const std::string par2, Arguments& task) {
      _parameters.clear();
      _parameters.push_back("--time");
      _parameters.push_back(par1);
      _parameters.push_back(par2);
      _isParameterChecked.push_back(0);
      _isParameterChecked.push_back(0);
      _isParameterChecked.push_back(0);
      Parser::_setTimeInCrontabFile(0);
      if(_task.size()) {
        task = _task[0];
        return 0;
      } else {
        return 1;
      }  
    }
}; 
