#include "ModeAndValue.h"

ModeAndValue& ModeAndValue::operator=(const ModeAndValue& given) {
  this->mode = given.mode;
  this->value = given.value;
  return *this;
}
