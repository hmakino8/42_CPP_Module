#include "Sed.hpp"

Sed::Sed(int argc, char **argv) throw(std::invalid_argument) {
  if (argc != 4) {
    throw std::invalid_argument("invalid argument");
  }
  filename_ = argv[1];
  s1_ = argv[2];
  s2_ = argv[3];
}

void Sed::Replace(std::ifstream& ifs, std::ofstream& ofs) {
  std::string line;
  while (std::getline(ifs, line)) {
    line += "\n";
    size_t pos = line.find(s1_);
    if (pos != std::string::npos) {
      size_t len = s1_.length();
      line.erase(pos, len);
      line.insert(pos, s2_);
      pos += len;
    }
    ofs << line;
  }
}
