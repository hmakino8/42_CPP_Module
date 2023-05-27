#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed {
 public:
  Sed(int argc, char **argv) throw(std::invalid_argument);
  void Replace(std::ifstream& ifs, std::ofstream& ofs);

  std::string filename_;
  std::string s1_;
  std::string s2_;
};

#endif
