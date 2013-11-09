#include "Arguments.h"

Arguments& Arguments::operator=(const Arguments& given) {
  this->minute = given.minute;
  this->hour = given.hour;
  this->day = given.day;
  this->month = given.month;
  return *this;
}
