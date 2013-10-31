#pragma once

enum TimeModes {
  INTERVAL_MINUTES = 1,
  INTERVAL_HOURS = 2,
  FORMATTED_TIME = 3
};

struct Arguments {
  TimeModes mode;
  int arg1;
  int arg2;
  int arg3;
  int arg4;
  Arguments(TimeModes,int,int,int,int);
};
