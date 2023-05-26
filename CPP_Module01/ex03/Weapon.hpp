#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
  public:
    Weapon(const std::string& type);
    const std::string& getType() const;
    void setType(std::string const type);

  private:
    std::string type_;
};

#endif
