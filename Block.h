// Block.h
#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>
#include <cstdint>

class Block
{
public:
  Block(const std::string &previousHash, const std::string &data);
  std::string calculateHash() const;

  // Getters
  std::string getPreviousHash() const;
  std::string getHash() const;
  uint32_t getNonce() const;
  time_t getTimestamp() const;

  // Proof-of-work setters
  void setNonce(uint32_t nonce);
  void setHash(const std::string &hash);

private:
  std::string previousHash;
  std::string data;
  uint32_t nonce;
  time_t timestamp;
  std::string hash;
};

#endif // BLOCK_H