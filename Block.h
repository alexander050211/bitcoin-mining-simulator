// Block.h
#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include <cstdint>

class Block
{
public:
  Block(uint32_t blockIndex, const std::string &data);
  std::string hash;
  std::string prevHash;

  std::string getHash();
  int64_t getNonce();
  void mineBlock(uint32_t difficulty);

private:
  std::string data;
  int64_t nonce;
  time_t timestamp;
  uint32_t blockIndex;

  std::string calculateHash() const;
};

#endif // BLOCK_H