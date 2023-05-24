#include <iostream>
#include <unistd.h>

const std::string kCommandMsg =
"\nPlease input one of the following commands.\n\n"
"ADD             : save a new contact\n"
"SEARCH          : display a specific contact\n"
"EXIT or CTRL-D  : exit\n\n"
"> ";
const std::string kInvalidCommandMsg = "Invalid command\n";
const std::string kAddContactMsg = "\nPlease fill in the following\n";
const std::string kSearchContactMsg = "\nPlease input User ID\n";
const std::string kTerminateMsg = "Bye!\n";
const int kUserIdMax = 8;
const int kContactInfoMax = 4;
const std::string kHomeHeader =
"\n"
"********************************************\n"
"                    HOME                    \n"
"********************************************\n";
const std::string kAddContactHeader =
"\n"
"********************************************\n"
"                 ADD CONTACT                \n"
"********************************************\n";
const std::string kSearchContactHeader =
"\n"
"********************************************\n"
"                SEARCH CONTACT              \n"
"********************************************\n";

class Contact {
  public:
    Contact();
    std::string getContactInfo(int index);
    void setContactInfo(int index, std::string info);
  private:
    std::string contact_info_[kContactInfoMax];
};

std::string Contact::getContactInfo(int index) {
  return contact_info_[index];
}

void Contact::setContactInfo(int index, std::string info) {
  contact_info_[index] = info;
}

Contact::Contact() {
    contact_info_[0] = "first name";
    contact_info_[1] = "last name";
    contact_info_[2] = "nick name";
    contact_info_[3] = "phone number";
};

class PhoneBook {
  public:
    PhoneBook() : index_(0) {};
    void interactive(PhoneBook *phone_book);
    void addContact(PhoneBook *phone_book);
    void searchContact(PhoneBook *phone_book);
    void getContact(Contact contact);
    void terminate();
    std::string readLine();
    bool is_full_;
  private:
    std::string command_;
    Contact contact_list_[kUserIdMax];
    int index_;
};

void PhoneBook::terminate() {
  std::cout << "Bye!" << "\n";
  std::exit(EXIT_SUCCESS);
}

std::string PhoneBook::readLine() {
    std::string line;
    if (!std::getline(std::cin, line)) {
      std::cout << "^D\n";
      terminate();
    }
    return line;
}

void PhoneBook::addContact(PhoneBook *phone_book) {
  std::cout << kAddContactHeader << kAddContactMsg;
  Contact contact;
  for (int i = 0; i < kContactInfoMax; ++i) {
    std::cout << contact.getContactInfo(i) << "\n> ";
    std::string info = readLine();
    if (info == "") {
      std::cout << "Empty characters cannot be registered\n\n";
      --i;
      continue;
    }
    contact.setContactInfo(i, info);
  }
  std::cout << "\nRegistered in the Phonebook.\n";
  phone_book->contact_list_[index_++] = contact;
  if (index_ >= 8) {
    is_full_ = true;
    index_ = 0;
  }
}

void PhoneBook::searchContact(PhoneBook *phone_book) {
  std::cout << kSearchContactHeader << kSearchContactMsg << "> ";
  try {
    int id = std::stoi(readLine());
    if (id <= 0 || id > kUserIdMax || (!is_full_ && id > index_)) {
      throw std::invalid_argument("");
    }
    getContact(phone_book->contact_list_[id - 1]);
  } catch (...) {
    std::cout << "Invalid ID\n";
  }
}

void PhoneBook::getContact(Contact contact) {
  std::cout << contact.getContactInfo(0) << "\n";
}

void PhoneBook::interactive(PhoneBook *phone_book) {
  while (1) {
    std::cout << kHomeHeader << kCommandMsg;
      command_ = readLine();
      if (command_ == "EXIT") {
        break ;
      } else if (command_ == "ADD") {
        addContact(phone_book);
      } else if (command_ == "SEARCH") {
        searchContact(phone_book);
      } else {
        std::cout << kInvalidCommandMsg;
      }
    }
  std::cout << kTerminateMsg;
}

int	main() {
  PhoneBook phone_book;
  phone_book.interactive(&phone_book);
  return 0;
}
