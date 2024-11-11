#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account
{
public:
  Account(const std::string &address, double initialBalance);

  std::string getAddress() const;
  double getBalance() const;
  void adjustBalance(double amount);

private:
  std::string address;
  double balance = 1000.0;
};

#endif // ACCOUNT_H