#include "hello.h"

std::ostream &hello(std::ostream &os) {
  os << "Goodbye, World";
  return os;
}