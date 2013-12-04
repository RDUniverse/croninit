#pragma once
#include "Parser.h"
#include "CrontabFileEditor.h"

class CrontabFileEditorMock : public CrontabFileEditor {
  public:
    std::string getLinesForCrontabFileMock(const std::vector<Arguments>& vec, const std::string& servers) {
      _tasksCount = vec.size();
      for(int i = 0; i < _tasksCount; i++)
        _tasks.push_back(vec[i]);
      _serverList = servers;
      return CrontabFileEditor::_getLinesForCrontabFile();
    }  
};
