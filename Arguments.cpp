#include "Arguments.h"

Arguments::Arguments(const ModeAndValue& xArg1, const ModeAndValue& xArg2, const ModeAndValue& xArg3, const ModeAndValue& xArg4) {
  arg1.value = xArg1.value;
  arg2.value = xArg2.value;
  arg3.value = xArg3.value;
  arg4.value = xArg4.value;
  arg1.mode = xArg1.mode;
  arg2.mode = xArg2.mode;
  arg3.mode = xArg3.mode;
  arg4.mode = xArg4.mode;
}

void Arguments::convertToVector(std::vector<ModeAndValue>& vec) {
  vec.push_back(arg1);
  vec.push_back(arg2);
  vec.push_back(arg3);
  vec.push_back(arg4);
}
