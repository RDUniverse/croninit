#include <iostream>
#include <string>
#include "Identifier.h"
#include "Parser.h"
#include "CrontabFileEditor.h"

int main(int argc, char* argv[]) {
  //start of user identification process
  Identifier Id;
  std::string checkingName = "root";
  if(!Id.run()) {
    if(!Id.check(checkingName)) {
      std::cout << "In order for this program to be successefully executed, it must be run by a root user\n";
      return 0;
    }
  } else {
    std::cout << "Unexpected error. Abort...\n";
    return 0;
  }
  //end of user identification process
  //start of parsing
  Parser parser(argc, argv);
  if(parser.init()) 
    return 0;
  //end of parsing
  //start of creating crontab file
  CrontabFileEditor editor;
  editor.init(&parser);
  editor.run(&parser);
  //end of creating crontab file
  return 0;
}
