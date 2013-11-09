#include <vector>
#include <string>
#include <iostream>

class OutputHandler {
  public:
    void printHelp();
    void printMistakes(const std::vector<std::string>&);
};
