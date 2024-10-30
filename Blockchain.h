#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include <vector>
#include <string>
#include <cstdint>

class Blockchain
{
public:
  Blockchain(uint32_t difficulty = 4);

  void addBlock(const std::string &data);
  const std::vector<Block> &getChain() const;

  // Additional methods that might be useful
  bool isValid() const;
  Block &getLatestBlock();

private:
  std::vector<Block> chain;
  uint32_t difficulty;
};

#endif // BLOCKCHAIN_H