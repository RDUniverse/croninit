#include "OutputHandler.h"

void OutputHandler::printHelp() {
  std::cout << "FEATURED OPTIONS\n\t--help\n\t\tprint help\n\t";
  std::cout << "--server\n\t\tset an ntp server for time updating\n\t";
  std::cout << "--time\n\t\t";
  std::cout << "set data and time for the updating data and time on the machine\n\t\tFormat:\n\t\t\t";
  std::cout << "Month/Day hour:minute, where:\n\t\t\t\t";
  std::cout << "Month: between 1 and 12 or 'every' for every month or 'every{interval}',\n\t\t\t\t\t";
  std::cout << "where interval is between 1 and 12\n\t\t\t\t";
  std::cout << "Day: between 1 and 31 or 'every' for every day or 'every{interval}',\n\t\t\t\t\t";
  std::cout << "where interval is between 1 and 31\n\t\t\t\t";
  std::cout << "hour: between 0 and 23 or 'every' for every hour or 'every{interval}',\n\t\t\t\t\t";
  std::cout << "where interval is between 1 and 23\n\t\t\t\t";
  std::cout << "minute: between 0 and 59 or 'every' for every minute or 'every{interval}',\n\t\t\t\t\t";
  std::cout << "where interval is between 1 and 59\n\t\t\t\t\n";
}

void OutputHandler::printMistakes(const std::vector<std::string>& mistakes) {
  for(int i = 0; i < mistakes.size(); i++)
    std::cout << mistakes[i] << "\n";
}
