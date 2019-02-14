#include "hello.h"

#include <fmt/format.h>
#include <string>

std::ostream &hello(std::ostream &os) {
  std::string s = fmt::format("{0}, World", "Goodbye");
  os << s;
  return os;
}