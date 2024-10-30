#include "Block.h"
#include "SHA256.h"
#include <sstream>
#include <iomanip>
#include <iostream>

// Constructor implementation
Block::Block(uint32_t blockIndex, const std::string &data)
{
  this->blockIndex = blockIndex;
  this->data = data;
  this->nonce = 0;
  this->timestamp = time(nullptr);
}

// Get the current hash
std::string Block::getHash()
{
  return hash;
}

// Get the nonce value (for testing)
int64_t Block::getNonce()
{
  return this->nonce;
}

// Mine the block with given difficulty
void Block::mineBlock(uint32_t difficulty)
{
  // Create a string with difficulty number of zeros
  std::string str(difficulty, '0');

  // Keep calculating hash until we get hash with desired number of leading zeros
  do
  {
    nonce++;
    hash = calculateHash();
  } while (hash.substr(0, difficulty) != str);
  std::cout << "Block mined: " << hash << std::endl;
}

// Calculate hash of the block
std::string Block::calculateHash() const
{
  std::stringstream ss;
  ss << blockIndex << timestamp << data << nonce << prevHash;

  return sha256(ss.str());
}