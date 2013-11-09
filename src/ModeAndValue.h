#pragma once

enum Modes {
  EVERY = 0,
  ONCE = 1,
  INTERVAL = 2
};

struct ModeAndValue {
  Modes mode;
  int value;
  ModeAndValue(const Modes& nMode = ONCE, const int& nValue = 0) : mode(nMode), value(nValue) {};
  ModeAndValue& operator=(const ModeAndValue&); 
};
