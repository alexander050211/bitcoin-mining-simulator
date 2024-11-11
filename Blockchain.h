#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <string>
#include <unordered_map>
#include "Block.h"
#include "Transaction.h"
#include "Account.h"

class Blockchain
{
public:
  Blockchain(uint32_t difficulty = 4);

  void addBlock(const std::vector<Transaction> &transactions);
  bool addTransaction(const Transaction &transaction);
  bool createAccount(const std::string &address, double initialBalance = 1000.0);
  double getBalance(const std::string &address) const;
  const std::vector<Block> &getChain() const;
  const std::vector<Transaction> &getPendingTransactions() const;
  std::vector<std::string> getAccountAddresses() const;
  bool isValid() const;

private:
  std::vector<Block> chain;
  std::vector<Transaction> pendingTransactions;
  std::unordered_map<std::string, Account> accounts;
  uint32_t difficulty;
  const size_t MAX_TRANSACTIONS_PER_BLOCK = 5;

  bool isTransactionValid(const Transaction &transaction) const;
  void updateAccountBalances(const std::vector<Transaction> &transactions);
};

#endif // BLOCKCHAIN_H