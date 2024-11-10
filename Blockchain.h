#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <string>
#include <cstdint>
#include "Block.h"
#include "Transaction.h"

class Blockchain
{
public:
  Blockchain(uint32_t difficulty = 4);

  void addBlock(const std::vector<Transaction> &transactions);
  bool addTransaction(const Transaction &transaction);
  double getBalance(const std::string &address) const;
  const std::vector<Block> &getChain() const;
  const std::vector<Transaction> &getPendingTransactions() const;
  bool isValid() const;

private:
  std::vector<Block> chain;
  std::vector<Transaction> pendingTransactions; // Transaction pool
  uint32_t difficulty;
  const size_t MAX_TRANSACTIONS_PER_BLOCK = 5; // Limit transactions per block

  bool isTransactionValid(const Transaction &transaction) const;
};

#endif // BLOCKCHAIN_H