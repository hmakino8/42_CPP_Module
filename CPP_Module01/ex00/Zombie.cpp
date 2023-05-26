#include "Zombie.hpp"

void Zombie::announce() {
    std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name) : name_(name) {
  std::cout << "constructor: " << name_ << " showed up!\n";
}

Zombie::~Zombie() {
  std::cout << "destructor: " << name_ << " dead!\n";
}
