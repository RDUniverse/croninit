#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include "Arguments.h"
#include "ModeInit.h"
#include <iostream>

class Parser {
  public:
    Parser(int, char**);
    ModeInit init();
    int getTasksCount();
    void getTask(int, Arguments&);
    void getServerList(std::string&);
    std::vector<std::string> getMistakes(); 
  private:
    std::vector<Arguments> _task;
    std::vector<int> _isParameterChecked;
    std::vector<std::string> _parameters;
    std::vector<int> _commandsPositions;
    std::vector<std::string> _commands;
    std::vector<std::string> _mistakes;
    std::stringstream _serverList;
    int _serverIsChangedFlag;
    void _addTask(Arguments);
    void _addServer(int);
    void _addMistake(const std::string&);
    void _addCommand(const std::string&, int);
    void _setTimeInCrontabFile(int);
    void _runCommands();
    void _checkIfAllParametersAreChecked();
};
