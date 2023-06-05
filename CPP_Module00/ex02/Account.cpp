#include <iostream>
#include <iomanip>
#include <time.h>
#include <unistd.h>

#include "Account.hpp"

#ifndef ORIGIN
  #define ORIGIN 0
#endif

const std::string kTestLog = "[19920104_091532] ";

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//unused function
int Account::checkAmount() const { return _amount; }
Account::Account() {}

//getter
int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void  Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";"
            << "total:" << _totalAmount << ";"
            << "deposits:" << _totalNbDeposits << ";"
            << "withdrawals:" << _totalNbWithdrawals << "\n";
}

Account::Account(int initial_deposit) : _nbDeposits(0), _nbWithdrawals(0)
{
  ++_nbAccounts;
  _accountIndex = _nbAccounts - 1;
  _amount = initial_deposit;
  _totalAmount += _amount;

  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "created\n";
};

Account::~Account() {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "closed\n";
}

void	Account::makeDeposit( int deposit ) {
  int p_amount = _amount;
  _amount += deposit;
  _totalAmount += deposit;
  ++_nbDeposits;
  ++_totalNbDeposits;

  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << p_amount << ";"
            << "deposit:" << deposit << ";"
            << "amount:" << _amount << ";"
            << "nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";";
  try {
    if (_amount < withdrawal) {
      throw std::invalid_argument("withdrawal:refused");
    } else {
      ++_nbWithdrawals;
      ++_totalNbWithdrawals;
      _amount -= withdrawal;
      _totalAmount -= withdrawal;

      std::cout << "withdrawal:" << withdrawal << ";"
                << "amount:" << _amount<< ";"
                << "nb_withdrawals:" << _nbWithdrawals << "\n";
      return kTrue;
    }
  } catch (std::invalid_argument e) {
    std::cout << e.what() << "\n";
    return false;
  }
}

void	Account::displayStatus() const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "deposits:" << _nbDeposits << ";"
            << "withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::_displayTimestamp() {
  //nullptr is not supported in c++98
  std::time_t now = std::time(NULL);
  const tm *local_time = localtime(&now);

  if (ORIGIN) {
    std::cout << kTestLog;
  } else {
    std::cout << "["
              << 1900 + local_time->tm_year
              << std::setw(2) << std::setfill('0') << local_time->tm_mon + 1
              << std::setw(2) << std::setfill('0') << local_time->tm_mday
              << '_'
              << std::setw(2) << std::setfill('0') << local_time->tm_hour
              << std::setw(2) << std::setfill('0') << local_time->tm_min
              << std::setw(2) << std::setfill('0') << local_time->tm_sec
              << "] ";
  }
}
