#include "Block.h"
#include "SHA256.h"
#include <sstream>
#include <iomanip>
#include <cstdint>

Block::Block(uint32_t blockIndex, const std::vector<Transaction> &transactions)
{
  this->blockIndex = blockIndex;
  this->transactions = transactions;
  this->nonce = 0;
  this->timestamp = time(nullptr);

  // Add mining reward transaction
  // Only add mining reward if this isn't the genesis block
  if (blockIndex > 0)
  {
    Transaction rewardTx("Network", "Miner", calculateBlockReward());
    this->transactions.push_back(rewardTx);
  }
}
std::string Block::calculateHash() const
{
  std::stringstream ss;
  ss << blockIndex << timestamp << nonce << prevHash;

  // Include all transaction hashes in block hash
  for (const Transaction &tx : transactions)
  {
    ss << tx.calculateHash();
  }

  return sha256(ss.str());
}

std::string Block::getHash() const
{
  return hash;
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

double Block::calculateBlockReward() const
{
  // Simple reward halving every 100 blocks (for demonstration)
  uint32_t halvings = blockIndex / 100;
  return BLOCK_REWARD / (1 << halvings);
}

int64_t Block::getNonce() const
{
  return nonce;
}