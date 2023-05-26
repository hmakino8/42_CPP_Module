#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name_(name), weapon_(NULL) {}

void HumanB::attack() {
  std::cout << name_ << " attacks with their " << weapon_->getType() << "\n";
}

void HumanB::setWeapon(Weapon& weapon) {
  weapon_ = &weapon;
}
