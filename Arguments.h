#pragma once

enum modes {
  INTERVALMINUTES = 1,
  INTERVALHOURS = 2,
  SETTIME = 3
};

struct Arguments {
  modes mode;
  int arg1;
  int arg2;
  int arg3;
  int arg4;
  Arguments(modes,int,int,int,int);
};
