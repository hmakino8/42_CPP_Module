#include "Harl.hpp"

int main(int argc, char **argv) {
  Harl harl;
  if (argc == 2) {
    harl.Complain(argv[1]);
  } else {
    harl.Usage();
  }
  return 0;
}
