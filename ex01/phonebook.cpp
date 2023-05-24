#include <iomanip>

#include "phonebook.hpp"

#define TRUE 1

void putColoredText(const std::string text, const std::string color) {
  std::cout << color << text << kReset;
}

std::string readLine() {
  std::string line;
  if (std::getline(std::cin, line)) {
    return line;
  } else {
    std::cout << "^D\n";
    putColoredText(kTerminateMsg, kMagenta);
    exit(EXIT_SUCCESS);
  }
}

void PhoneBook::addContact(PhoneBook& phone_book) {
  putColoredText(kAddContactHeader, kMagenta);
  putColoredText(kAddContactMsg, kBlue);

  Contact contact;
  contact.setInfo(0, std::to_string(index_ + 1));
  for (int i = 1; i < kContactInfoMax; ++i) {
    putColoredText(contact.getInfo(i), kBlue);
    std::cout << "> ";
    std::string info = readLine();
    try {
      if (info == "") throw kErrorEmptyMsg;
    } catch(const std::string msg) {
      putColoredText(msg, kRed);
      --i;
      continue;
    }
    contact.setInfo(i, info);
  }

  phone_book.contacts_[index_++] = contact;
  is_full_ = index_ >= kUserIdMax;
  if (is_full_) index_ = 0;

  putColoredText(kRegisteredInfoMsg, kGreen);
}

void PhoneBook::searchContact(PhoneBook& phone_book) {
  try {
    if (!is_full_ && index_ == 0) throw kErrorNoInformationMsg;

    putColoredText(kSearchContactHeader, kMagenta);
    putColoredText(kContactViewerHeader, kBlue);

    int count = is_full_ ? kUserIdMax : index_;
    for (int i = 0; i < count; ++i) {
      contactTableViewer(phone_book.contacts_[i]);
    }

    putColoredText(kSearchContactMsg, kBlue);
    std::cout << "> ";

    int id = std::stoi(readLine());
    if (id <= 0 || id > kUserIdMax || (!is_full_ && id > index_)) {
      throw kErrorNoInformationMsg;
    } else {
      contactViewer(phone_book.contacts_[id - 1]);
    }
  } catch (std::invalid_argument) {
    putColoredText(kErrorIdMsg, kRed);
  } catch (std::out_of_range) {
    putColoredText(kErrorIdMsg, kRed);
  } catch (const std::string e) {
    putColoredText(e, kRed);
  }
}

void PhoneBook::contactViewer(Contact& contact) {
  for (int i = 0; i < 4; ++i) {
    putColoredText("|", kBlue);
    if (contact.getInfo(i).size() < 10) {
      std::cout
        << std::setw(10)
        << std::setfill(' ')
        << contact.getInfo(i);
    } else {
      std::cout
        << contact.getInfo(i).substr(0, 9)
        << ".";
    }
  }
  putColoredText("|", kBlue);
  putColoredText(kContactViewerFooter, kBlue);
}

int PhoneBook::run() {
  putColoredText(kAsciiArt, kMagenta);

  PhoneBook phone_book;
  while (TRUE) {
    putColoredText(kHomeHeader, kMagenta);
    putColoredText(kUsage, kBlue);
    std::cout << "> ";

    command_ = readLine();
    if (command_ == "EXIT") {
      break ;
    } else if (command_ == "ADD") {
      addContact(phone_book);
    } else if (command_ == "SEARCH") {
      searchContact(phone_book);
    } else {
      putColoredText(kErrorCommandMsg, kRed);
    }
  }
  putColoredText(kTerminateMsg, kMagenta);
  return 0;
}
