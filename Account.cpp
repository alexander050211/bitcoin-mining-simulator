#include "Account.h"
#include <string>

Account::Account(const std::string &address, double initialBalance)
{
  this->address = address;
  this->balance = initialBalance;
}
std::string Account::getAddress() const
{
  return address;
}
double Account::getBalance() const
{
  return balance;
}
void Account::adjustBalance(double amount)
{
  balance += amount;
}