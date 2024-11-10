#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include <cstdint>
#include "Transaction.h"

class Block
{
public:
  Block(uint32_t blockIndex, const std::vector<Transaction> &transactions);

  std::string hash;
  std::string prevHash;
  uint32_t blockIndex;

  std::string getHash() const;
  void mineBlock(uint32_t difficulty);
  std::string calculateHash() const;
  const std::vector<Transaction> &getTransactions() const { return transactions; }
  double calculateBlockReward() const;
  int64_t getNonce() const; // Added nonce getter

private:
  std::vector<Transaction> transactions;
  int64_t nonce;
  time_t timestamp;
  const double BLOCK_REWARD = 50.0;
};

#endif // BLOCK_H