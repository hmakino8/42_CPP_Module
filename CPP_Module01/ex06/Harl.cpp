#include "Harl.hpp"

int Harl::Usage() {
  std::cerr << "Usage: DEBUG / INFO / WARNING / ERROR\n";
  exit(EXIT_FAILURE);
}

void Harl::Debug() {
  std::cout << "[ DEBUG ]\n"
            << "I love having extra bacon for "
            << "my 7XL-double-cheese-triple-pickle-specialketchup burger. "
            << "I really do!\n";
};
void Harl::Info() {
  std::cout << "[ INFO ]\n"
            << "I cannot believe adding extra bacon costs more money. "
            << "You didn't put enough bacon in my burger! "
            << "If you did, I wouldn't be asking for more!\n";
};
void Harl::Warning() {
  std::cout << "[ WARNING ]\n"
            << "I think I deserve to have some extra bacon for free. "
            << "I've been coming for years whereas you started working here since last month.\n";
};
void Harl::Error() {
  std::cout << "[ ERROR ]\n"
            << "This is unacceptable !I want to speak to the manager now.\n";
};

void Harl::Other() {
  std::cout << "[Probably complaining about insignificant problems]\n";
}

void Harl::Complain(std::string level) {
int command = (level == "DEBUG") * kDebug +
              (level == "INFO") * kInfo +
              (level == "WARNING") * kWarning +
              (level == "ERROR") * kError;

  switch (command) {
    case kDebug:
      this->Debug();
    case kInfo:
      this->Info();
    case kWarning:
      this->Warning();
    case kError:
      this->Error();
      break;
    default:
      this->Other();
  }
};
