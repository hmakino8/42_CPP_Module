#include "Sed.hpp"

int main(int argc, char **argv) {
  try {
    Sed Sed(argc, argv);
    std::ifstream ifs(Sed.filename_);
    if (ifs.fail()) throw std::invalid_argument("Failed to open file");
    std::ofstream ofs(Sed.filename_ + ".replace");
    if (ofs.fail()) throw std::invalid_argument("Failed to open file");

    Sed.Replace(ifs, ofs);
  } catch (std::invalid_argument e) {
    std::cout << e.what() << "\n";
  }
  return 0;
}
