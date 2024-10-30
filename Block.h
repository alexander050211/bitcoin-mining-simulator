#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <cstdint>

class Block
{
public:
  Block(uint32_t blockIndex, const std::string &data);

  std::string hash;
  std::string prevHash;
  uint32_t blockIndex; // Made public since it's accessed in main

  std::string getHash() const; // Made const
  int64_t getNonce() const;
  void mineBlock(uint32_t difficulty);
  std::string calculateHash() const; // Made public since it's needed for validation

private:
  std::string data;
  int64_t nonce;
  time_t timestamp;
};

#endif // BLOCK_H