#include <iomanip>

#include "PhoneBook.hpp"

void PutColoredTextedText(const std::string text, const std::string color) {
  std::cout << color << text << kReset;
}

std::string ReadLine() {
  std::string line;
  if (std::getline(std::cin, line)) {
    return line;
  } else {
    std::cout << "^D\n";
    PutColoredTextedText(kTerminateMsg, kMagenta);
    exit(EXIT_SUCCESS);
  }
}

void contactViewer(Contact& contact) {
  PutColoredTextedText(kContactViewerBorder, kBlue);

  Contact fields;
  for (int i = 0; i < kContactInfoMax; ++i) {
    PutColoredTextedText(fields.GetInfo(i) + ": ", kBlue);
    std::cout << contact.GetInfo(i) << "\n";
  }

  PutColoredTextedText(kContactViewerBorder, kBlue);
}

void contactTableViewer(Contact& contact) {
  for (int i = 0; i < 4; ++i) {
    PutColoredTextedText("|", kBlue);
    if (contact.GetInfo(i).size() < 10) {
      std::cout
        << std::setw(10)
        << std::setfill(' ')
        << contact.GetInfo(i);
    } else {
      std::cout
        << contact.GetInfo(i).substr(0, 9)
        << ".";
    }
  }

  PutColoredTextedText("|", kBlue);
  PutColoredTextedText(kContactViewerFooter, kBlue);
}

void PhoneBook::AddContact(PhoneBook& phone_book) {
  PutColoredTextedText(kAddContactHeader, kMagenta);
  PutColoredTextedText(kAddContactMsg, kBlue);

  Contact contact;
  contact.SetInfo(0, std::to_string(index_ + 1));
  for (int i = 1; i < kContactInfoMax; ++i) {
    PutColoredTextedText(contact.GetInfo(i), kBlue);
    std::cout << "> ";
    std::string info = ReadLine();
    try {
      if (info == "") throw kErrorEmptyMsg;
    } catch(const std::string msg) {
      PutColoredTextedText(msg, kRed);
      --i;
      continue;
    }
    contact.SetInfo(i, info);
  }

  phone_book.contacts_[index_++] = contact;
  if (!is_full_ && index_ == kUserIdMax) is_full_ = kTrue;
  index_ %= kUserIdMax;

  PutColoredTextedText(kRegisteredInfoMsg, kGreen);
}

void PhoneBook::SearchContact(PhoneBook& phone_book) {
  try {
    if (!is_full_ && index_ == 0) throw kErrorNoInfoMsg;

    PutColoredTextedText(kSearchContactHeader, kMagenta);
    PutColoredTextedText(kContactTableViewerHeader, kBlue);

    int count = is_full_ ? kUserIdMax : index_;
    for (int i = 0; i < count; ++i) {
      contactTableViewer(phone_book.contacts_[i]);
    }

    PutColoredTextedText(kSearchContactMsg, kBlue);
    std::cout << "> ";

    int id = std::stoi(ReadLine());
    if (id <= 0 || id > kUserIdMax || (!is_full_ && id > index_)) {
      throw kErrorNoInfoMsg;
    } else {
      contactViewer(phone_book.contacts_[id - 1]);
    }
  } catch (std::invalid_argument) {
    PutColoredTextedText(kErrorIdMsg, kRed);
  } catch (std::out_of_range) {
    PutColoredTextedText(kErrorIdMsg, kRed);
  } catch (const std::string e) {
    PutColoredTextedText(e, kRed);
  }
}

void PhoneBook::Run() {
  PutColoredTextedText(kAsciiArt, kGreen);

  PhoneBook phone_book;
  while (kTrue) {
    PutColoredTextedText(kHomeHeader, kMagenta);
    PutColoredTextedText(kUsage, kBlue);
    std::cout << "> ";

    command_ = ReadLine();
    if (command_ == "EXIT") {
      break ;
    } else if (command_ == "ADD") {
      AddContact(phone_book);
    } else if (command_ == "SEARCH") {
      SearchContact(phone_book);
    } else {
      PutColoredTextedText(kErrorCommandMsg, kRed);
    }
  }

  PutColoredTextedText(kTerminateMsg, kMagenta);
}
