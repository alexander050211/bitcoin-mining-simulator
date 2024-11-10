#include "Blockchain.h"
#include <stdexcept>
#include <iostream>
#include <bits/chrono.h>

Blockchain::Blockchain(uint32_t difficulty) : difficulty(difficulty)
{
  // Create genesis block with no transactions
  std::vector<Transaction> genesisTransactions;
  chain.emplace_back(Block(0, genesisTransactions));
  chain.back().mineBlock(difficulty);
}

void Blockchain::addBlock(const std::vector<Transaction> &transactions)
{
  std::cout << "Creating new block with " << transactions.size() << " transactions...\n";

  Block newBlock(chain.size(), transactions);
  newBlock.prevHash = chain.back().getHash();

  std::cout << "Mining block...\n";
  auto startTime = std::chrono::steady_clock::now();

  newBlock.mineBlock(difficulty);

  auto endTime = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

  std::cout << "Block mined! Nonce: " << newBlock.getNonce() << "\n";
  std::cout << "Mining took: " << duration.count() << " seconds\n";
  std::cout << "Block hash: " << newBlock.getHash() << "\n\n";

  chain.push_back(newBlock);
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

  /*
    // Check if sender has enough balance (except for mining rewards)
    if (transaction.getFrom() != "Network")
    { // Skip check for mining rewards
      double senderBalance = getBalance(transaction.getFrom());
      if (senderBalance < transaction.getAmount())
      {
        return false;
      }
    }
  */
  return true;
}

double Blockchain::getBalance(const std::string &address) const
{
  double balance = 0.0;

  // Go through all blocks
  for (const Block &block : chain)
  {
    const std::vector<Transaction> &transactions = block.getTransactions();
    for (const Transaction &tx : transactions)
    {
      // If this address is sender, subtract amount
      if (tx.getFrom() == address)
      {
        balance -= tx.getAmount();
      }
      // If this address is receiver, add amount
      if (tx.getTo() == address)
      {
        balance += tx.getAmount();
      }
    }
  }

  // Also check pending transactions
  for (const Transaction &tx : pendingTransactions)
  {
    if (tx.getFrom() == address)
    {
      balance -= tx.getAmount();
    }
    if (tx.getTo() == address)
    {
      balance += tx.getAmount();
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