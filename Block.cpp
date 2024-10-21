// Block.cpp
#include "Block.h"
#include "SHA256.h"
#include <sstream>
#include <iomanip>

Block::Block(const std::string &previousHash, const std::string &data) : previousHash(previousHash), data(data), nonce(0), timestamp(std::time(nullptr))
{
  hash = calculateHash();
}

std::string Block::calculateHash() const
{
  std::stringstream ss;
  ss << previousHash << timestamp << data << nonce;
  return SHA256::hash(ss.str());
}

std::string Block::getPreviousHash() const
{
  return previousHash;
}

std::string Block::getHash() const
{
  return hash;
}

uint32_t Block::getNonce() const
{
  return nonce;
}

time_t Block::getTimestamp() const
{
  return timestamp;
}

void Block::setNonce(uint32_t newNonce)
{
  nonce = newNonce;
}

void Block::setHash(const std::string &newHash)
{
  hash = newHash;
}