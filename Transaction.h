#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>
#include <ctime>

class Transaction
{
public:
  Transaction(const std::string &from, const std::string &to, double amount);

  std::string calculateHash() const;
  bool isValid() const;

  // Getters
  std::string getFrom() const { return fromAddress; }
  std::string getTo() const { return toAddress; }
  double getAmount() const { return amount; }
  time_t getTimestamp() const { return timestamp; }

private:
  std::string fromAddress; // Sender's address
  std::string toAddress;   // Recipient's address
  double amount;           // Transaction amount
  time_t timestamp;        // Transaction timestamp
};

#endif // TRANSACTION_H