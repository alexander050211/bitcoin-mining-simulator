#include "Block.h"
#include "SHA256.h"
#include <sstream>
#include <iomanip>

Block::Block(uint32_t blockIndex, const std::string &data)
{
  this->blockIndex = blockIndex;
  this->data = data;
  this->nonce = 0;
  this->timestamp = time(nullptr);
}

std::string Block::calculateHash() const
{
  std::stringstream ss;
  ss << blockIndex << timestamp << data << nonce << prevHash;

  return sha256(ss.str());
}

std::string Block::getHash() const
{ // Made const
  return hash;
}

int64_t Block::getNonce() const
{
  return nonce;
}

void Block::mineBlock(uint32_t difficulty)
{
  std::string str(difficulty, '0');

  do
  {
    nonce++;
    hash = calculateHash();
  } while (hash.substr(0, difficulty) != str);
}