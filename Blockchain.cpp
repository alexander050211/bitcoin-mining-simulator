#include "Blockchain.h"
#include <stdexcept>

Blockchain::Blockchain(uint32_t difficulty) : difficulty(difficulty)
{
  // Create genesis block with no transactions
  std::vector<Transaction> genesisTransactions;
  chain.emplace_back(Block(0, genesisTransactions));
  chain.back().mineBlock(difficulty);
}

void Blockchain::addBlock(const std::vector<Transaction> &transactions)
{
  Block newBlock(chain.size(), transactions);
  newBlock.prevHash = chain.back().getHash();
  newBlock.mineBlock(difficulty);
  chain.push_back(newBlock);

  // Clear processed transactions from pending pool
  pendingTransactions.clear();
}

bool Blockchain::addTransaction(const Transaction &transaction)
{
  // Validate transaction
  if (!isTransactionValid(transaction))
  {
    return false;
  }

  // Add to pending transactions
  pendingTransactions.push_back(transaction);

  // If we have enough transactions, create a new block
  if (pendingTransactions.size() >= MAX_TRANSACTIONS_PER_BLOCK)
  {
    addBlock(pendingTransactions);
  }

  return true;
}

bool Blockchain::isTransactionValid(const Transaction &transaction) const
{
  // Basic validation
  if (!transaction.isValid())
  {
    return false;
  }

  // Check if sender has enough balance (except for mining rewards)
  if (transaction.getFrom() != "Network")
  { // Skip check for mining rewards
    double senderBalance = getBalance(transaction.getFrom());
    if (senderBalance < transaction.getAmount())
    {
      return false;
    }
  }

  return true;
}

double Blockchain::getBalance(const std::string &address) const
{
  double balance = 0.0;

  // Go through all blocks and their transactions
  for (const Block &block : chain)
  {
    for (const Transaction &transaction : block.getTransactions())
    {
      if (transaction.getFrom() == address)
      {
        balance -= transaction.getAmount();
      }
      if (transaction.getTo() == address)
      {
        balance += transaction.getAmount();
      }
    }
  }

  // Check pending transactions too
  for (const Transaction &transaction : pendingTransactions)
  {
    if (transaction.getFrom() == address)
    {
      balance -= transaction.getAmount();
    }
    if (transaction.getTo() == address)
    {
      balance += transaction.getAmount();
    }
  }

  return balance;
}

bool Blockchain::isValid() const
{
  for (size_t i = 1; i < chain.size(); i++)
  {
    const Block &currentBlock = chain[i];
    const Block &previousBlock = chain[i - 1];

    // Verify block hash
    if (currentBlock.getHash() != currentBlock.calculateHash())
    {
      return false;
    }

    // Verify block link
    if (currentBlock.prevHash != previousBlock.getHash())
    {
      return false;
    }

    // Verify all transactions in block
    for (const Transaction &transaction : currentBlock.getTransactions())
    {
      if (!transaction.isValid())
      {
        return false;
      }
    }
  }
  return true;
}

const std::vector<Block> &Blockchain::getChain() const
{
  return chain;
}

const std::vector<Transaction> &Blockchain::getPendingTransactions() const
{
  return pendingTransactions;
}