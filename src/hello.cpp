#include "hello.h"

#include <fmt/format.h>
#include <fstream>
#include <string>

std::ostream &hello(std::ostream &os) {
  std::ifstream f("assets/string.txt", std::ios::ate);
  auto size = f.tellg();
  f.seekg(0);
  std::string buf(size, '\0');
  f.read(buf.data(), size);

  std::string s = fmt::format("{0}, World", buf);
  os << s;
  return os;
}