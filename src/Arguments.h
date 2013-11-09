#pragma once
#include "ModeAndValue.h"
#include <vector>

struct Arguments {
  ModeAndValue minute;
  ModeAndValue hour;
  ModeAndValue day;
  ModeAndValue month;
  Arguments(const ModeAndValue& nMinute = ModeAndValue(), 
            const ModeAndValue& nHour = ModeAndValue(),
            const ModeAndValue& nDay = ModeAndValue(),
            const ModeAndValue& nMonth = ModeAndValue()) : 
    minute(nMinute), hour(nHour), day(nDay), month(nMonth) {};
  Arguments& operator=(const Arguments&);
};
