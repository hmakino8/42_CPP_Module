#include "Harl.hpp"

int Harl::Usage() {
  std::cerr << "Usage: DEBUG / INFO / WARNING / ERROR\n";
  exit(EXIT_FAILURE);
}

void Harl::Debug() {
  std::cout << "I love having extra bacon for "
            << "my 7XL-double-cheese-triple-pickle-specialketchup burger. "
            << "I really do!\n";
};
void Harl::Info() {
  std::cout << "I cannot believe adding extra bacon costs more money. "
            << "You didn't put enough bacon in my burger! "
            << "If you did, I wouldn't be asking for more!\n";
};
void Harl::Warning() {
  std::cout << "I think I deserve to have some extra bacon for free. "
            << "I've been coming for years whereas you started working here since last month.\n";
};
void Harl::Error() {
  std::cout << "This is unacceptable !I want to speak to the manager now.\n";
};

void Harl::Complain(std::string level) {
int command = (level == "DEBUG") * kDebug +
              (level == "INFO") * kInfo +
              (level == "WARNING") * kWarning +
              (level == "ERROR") * kError;

  switch (command) {
    case kDebug:
      this->Debug();
      break ;
    case kInfo:
      this->Info();
      break ;
    case kWarning:
      this->Warning();
      break ;
    case kError:
      this->Error();
      break ;
    default:
      Usage();
  }
};
