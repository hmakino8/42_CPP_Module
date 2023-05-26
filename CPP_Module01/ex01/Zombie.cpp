#include "Zombie.hpp"

void Zombie::setName(std::string name) {
  name_ = name;
}

void Zombie::announce() {
    std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}
