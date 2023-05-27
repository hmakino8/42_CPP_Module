#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

enum : int {
  kDebug = 1,
  kInfo,
  kWarning,
  kError,
};

class Harl {
 public:
  int Usage();
  void Complain(std::string level);

 private:
  void Debug();
  void Info();
  void Warning();
  void Error();
};

#endif
