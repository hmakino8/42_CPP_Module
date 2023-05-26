#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type_(type) {};

const std::string& Weapon::getType() const {
  return type_;
}

void Weapon::setType(std::string const type) {
  type_ = type;
};
