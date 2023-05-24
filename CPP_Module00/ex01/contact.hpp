#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "phonebook.hpp"

const int kContactInfoMax = 5;

class Contact {
  public:
    Contact() {
      info_[0] = "index       ";
      info_[1] = "first name  ";
      info_[2] = "last  name  ";
      info_[3] = "nick  name  ";
      info_[4] = "phone number";
    };

    std::string getInfo(int i) { return info_[i]; }
    void setInfo(int i, std::string info) { info_[i] = info; }

  private:
    std::string info_[kContactInfoMax];
};

#endif
