#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "stdlib.h"

class Parser {
  public:
    Parser(int, char**);
    std::string mgetpar(int);
    std::string getCommandCT();
    int getHours();
    int getMinutes();
    int getSeconds();
    int init();
    int getTasksCount();
    void getTask(int, int&, int&, int&);
    bool getSetTimeMode();
  private:
    std::string _commandCT;
    int _h; //number of hours
    int _m; //mumber of minutes
    int _s; //number of seconds
    std::vector<std::vector<int> > _task;
    std::vector<int> _doneMas;
    std::vector<std::string> _massiveOfPar;
    std::vector<int> _commandsPoss;
    std::vector<std::string> _commands;
    std::vector<std::string> _mistakes;
    void _addTask(int, int, int);
    void _printMistakes();
    void _printHelp();
    void _addMistake(const std::string&);
    void _addCommand(const std::string&, int);
    void _setIntervalInMinutes(int);
    void _setIntervalInHours(int);
    void _setHourAndMinuteInCrontabFile(int);
    void _runCommands();
    void _setTime(int);
    void _setCommandCT(int);
    void _checkDoneMas();
    bool _setTimeMode;
};
