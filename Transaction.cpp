#include "Transaction.h"
#include "SHA256.h"
#include <sstream>

Transaction::Transaction(const std::string &from, const std::string &to, double amount)
    : fromAddress(from), toAddress(to), amount(amount)
{
  timestamp = time(nullptr);
}

std::string Transaction::calculateHash() const
{
  std::stringstream ss;
  ss << fromAddress << toAddress << amount << timestamp;
  return sha256(ss.str()); // Using the same SHA256 function as before
}

bool Transaction::isValid() const
{
  // Basic validation
  if (fromAddress.empty() || toAddress.empty())
    return false;
  if (amount <= 0)
    return false;
  return true;
}