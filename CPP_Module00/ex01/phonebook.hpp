#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "contact.hpp"

//text color
const std::string kRed     = "\x1b[31m";
const std::string kGreen   = "\x1b[32m";
const std::string kBlue    = "\x1b[34m";
const std::string kMagenta = "\x1b[35m";
const std::string kReset   = "\x1b[39m";

const std::string kAsciiArt =
"\n"
" _____ _____ _____ _____ _____ _____ _____ _____ _____ \n"
"|  _  |  |  |     |   | |   __| __  |     |     |  |  |\n"
"|   __|     |  |  | | | |   __| __ -|  |  |  |  |    -|\n"
"|__|  |__|__|_____|_|___|_____|_____|_____|_____|__|__|\n";

const std::string kHomeHeader =
"\n"
"*********************************************\n"
"                    HOME                     \n"
"*********************************************\n";
const std::string kAddContactHeader =
"\n"
"*********************************************\n"
"                 ADD CONTACT                 \n"
"*********************************************\n";
const std::string kSearchContactHeader =
"\n"
"*********************************************\n"
"                SEARCH CONTACT               \n"
"*********************************************\n";

const std::string kContactViewerBorder =
"---------------------------------------------\n";
const std::string kContactTableViewerHeader =
"\n"
"+----------+----------+----------+----------+\n"
"|     INDEX|FIRST NAME| LAST NAME| NICK NAME|\n"
"+----------+----------+----------+----------+\n";
const std::string kContactViewerFooter =
"\n"
"+----------+----------+----------+----------+\n";

const std::string kUsage =
"\n"
"Please input one of the following commands.\n\n"
"ADD            : save a new contact\n"
"SEARCH         : display a specific contact\n"
"EXIT or CTRL-D : exit\n\n";

const std::string kAddContactMsg     = "\nPlease fill in the following information\n\n";
const std::string kSearchContactMsg  = "\nUser ID";
const std::string kTerminateMsg      = "Bye!\n";
const std::string kRegisteredInfoMsg = "\n*** Successfully registered! ***\n";

const std::string kErrorCommandMsg       = "\n*** Invalid command ***\n";
const std::string kErrorIdMsg            = "\n*** Invalid ID ***\n";
const std::string kErrorNoInformationMsg = "\n*** No infomation is registered ***\n";
const std::string kErrorEmptyMsg         = "\n*** Empty characters cannot be registered ***\n\n";

const int kUserIdMax = 8;

class PhoneBook {
  public:
    PhoneBook() : index_(0), is_full_(false) {};
    ~PhoneBook() {};
    void run();
    void addContact(PhoneBook& phone_book);
    void searchContact(PhoneBook& phone_book);
    void contactViewer(Contact& contact);
    void contactTableViewer(Contact& contact);

  private:
    int index_;
    bool is_full_;
    std::string command_;
    Contact contacts_[kUserIdMax + 1];
};

#endif
