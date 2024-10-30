#include "Blockchain.h"
#include "Block.h"

Blockchain::Blockchain(uint32_t difficulty) : difficulty(difficulty)
{
  // Create genesis block
  chain.emplace_back(Block(0, "Genesis Block"));
  chain.back().mineBlock(difficulty);
}

void Blockchain::addBlock(const std::string &data)
{
  Block newBlock(chain.size(), data);
  newBlock.prevHash = chain.back().getHash();
  newBlock.mineBlock(difficulty);
  chain.push_back(newBlock);
}

const std::vector<Block> &Blockchain::getChain() const
{
  return chain;
}

Block &Blockchain::getLatestBlock()
{
  return chain.back();
}

bool Blockchain::isValid() const
{
  for (size_t i = 1; i < chain.size(); i++)
  {
    const Block &currentBlock = chain[i];
    const Block &previousBlock = chain[i - 1];

    // Check if the hash is actually valid
    if (currentBlock.getHash() != currentBlock.calculateHash())
    {
      return false;
    }

    // Check if the previous hash matches
    if (currentBlock.prevHash != previousBlock.getHash())
    {
      return false;
    }
  }
  return true;
}