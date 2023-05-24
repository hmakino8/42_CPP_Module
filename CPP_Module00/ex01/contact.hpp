#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "phonebook.hpp"

const int kContactInfoMax = 6;

class Contact {
  public:
    Contact() {
      info_[0] = "index          ";
      info_[1] = "first name     ";
      info_[2] = "last name      ";
      info_[3] = "nickname       ";
      info_[4] = "phone number   ";
      info_[5] = "darkest secret ";
    };
    ~Contact() {};

    std::string getInfo(int i) { return info_[i]; }
    void setInfo(int i, std::string info) { info_[i] = info; }

  private:
    std::string info_[kContactInfoMax];
};

#endif
