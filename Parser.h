#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Arguments.h"

class Parser {
  public:
    Parser(int, char**);
    int init();
    int getTasksCount();
    void getTask(int, Arguments&);
  private:
    std::vector<std::vector<int> > _task;
    std::vector<int> _isParameterChecked;
    std::vector<std::string> _parameters;
    std::vector<int> _commandsPositions;
    std::vector<std::string> _commands;
    std::vector<std::string> _mistakes;
    void _addTask(Arguments);
    void _printMistakes();
    void _printHelp();
    void _addMistake(const std::string&);
    void _addCommand(const std::string&, int);
    void _setInterval(int);
    void _setIntervalInMinutes(int);
    void _setIntervalInHours(int);
    void _setTimeInCrontabFile(int);
    void _runCommands();
    void _checkIfAllParametersAreChecked();
};
