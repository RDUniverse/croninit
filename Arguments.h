#pragma once
#include "ModeAndValue.h"
#include <vector>

struct Arguments {
  ModeAndValue arg1;
  ModeAndValue arg2;
  ModeAndValue arg3;
  ModeAndValue arg4;
  Arguments(const ModeAndValue&, const ModeAndValue&, const ModeAndValue&, const ModeAndValue&);
  void convertToVector(std::vector<ModeAndValue>&);
};
