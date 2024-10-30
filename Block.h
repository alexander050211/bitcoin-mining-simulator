// Block.h
#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include <cstdint>

class Block
{
public:
  Block(const std::vector<uint8_t> &previousHash, const std::vector<uint8_t> &data);
  std::vector<uint8_t> calculateHash() const;

  std::vector<uint8_t> getPreviousHash() const;
  std::vector<uint8_t> getHash() const;
  uint32_t getNonce() const;
  time_t getTimestamp() const;

  void setNonce(uint32_t newNonce);
  void setHash(const std::vector<uint8_t> &newHash);

private:
  std::vector<uint8_t> previousHash;
  std::vector<uint8_t> data;
  std::vector<uint8_t> hash;
  uint32_t nonce;
  time_t timestamp;
};

#endif // BLOCK_H