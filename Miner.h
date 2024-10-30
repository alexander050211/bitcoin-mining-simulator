// Miner.h
#ifndef MINER_H
#define MINER_H

#include "Block.h"
#include <cstdint>

class Miner
{
public:
  Miner(uint32_t difficulty);
  void mineBlock(Block &block);

private:
  uint32_t difficulty;
  bool isHashValid(const std::vector<uint8_t> &hash) const;
};

#endif // MINER_H