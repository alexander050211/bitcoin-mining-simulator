#include "Account.h"
#include "Blockchain.h"
#include "Transaction.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <chrono>
#include <vector>

Blockchain::Blockchain(uint32_t difficulty) : difficulty(difficulty)
{
  // Create system account for mining rewards
  createAccount("Network", 1000000.0); // Large balance for mining rewards
  createAccount("Miner", 0.0);         // Initial miner account

  // Create genesis block with no transactions
  std::vector<Transaction> genesisTransactions;
  chain.emplace_back(Block(0, genesisTransactions));
  chain.back().mineBlock(difficulty);
}

void Blockchain::addBlock(const std::vector<Transaction> &transactions)
{
  std::cout << "\n"
            << "Creating new block with " << transactions.size() << " transactions...\n";

  Block newBlock(chain.size(), transactions);

  // Get the reward transaction
  auto tx = newBlock.getTransactions().back();

  newBlock.prevHash = chain.back().getHash();

  std::cout << "Mining block #" << chain.size() << "...\n";
  auto startTime = std::chrono::steady_clock::now();

  newBlock.mineBlock(difficulty);

  // Measure time spend in mining
  auto endTime = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);

  std::cout << "Block mined! Nonce: " << newBlock.getNonce() << "\n";
  std::cout << "Mining took: " << duration.count() << " seconds\n";
  std::cout << "Block hash: " << newBlock.getHash() << "\n";
  std::cout << "Reward given: " << tx.getFrom() << " -> " << tx.getTo() << ": " << tx.getAmount() << " coins\n\n";

  chain.push_back(newBlock);
  updateAccountBalances(newBlock.getTransactions());
  pendingTransactions.clear();
}

bool Blockchain::addTransaction(const Transaction &transaction)
{
  if (!isTransactionValid(transaction))
  {
    std::cout << "Transaction invalid: Insufficient balance or invalid account\n";
    return false;
  }
  std::cout << "Transaction added: " << transaction.getFrom() << " -> " << transaction.getTo() << ": " << transaction.getAmount() << " coins\n";
  pendingTransactions.push_back(transaction);

  // Empty pendingTransactions if it is full
  if (pendingTransactions.size() >= MAX_TRANSACTIONS_PER_BLOCK)
  {
    addBlock(pendingTransactions);
  }

  return true;
}

bool Blockchain::createAccount(const std::string &address, double initialBalance)
{
  if (accounts.find(address) != accounts.end())
  {
    return false; // Account already exists
  }

  Account newAccount = Account(address, initialBalance);
  accounts.emplace(address, newAccount);
  return true;
}

bool Blockchain::isTransactionValid(const Transaction &transaction) const
{
  // Check if accounts exist
  auto fromIter = accounts.find(transaction.getFrom());
  auto toIter = accounts.find(transaction.getTo());

  if (fromIter == accounts.end() || toIter == accounts.end())
  {
    return false;
  }

  // Skip balance check for mining rewards
  if (transaction.getFrom() == "Network")
  {
    return true;
  }

  // Check if sender has enough balance
  return fromIter->second.getBalance() >= transaction.getAmount();
}

double Blockchain::getBalance(const std::string &address) const
{
  auto it = accounts.find(address);
  if (it != accounts.end())
  {
    return it->second.getBalance();
  }
  return 0.0;
}

std::vector<std::string> Blockchain::getAccountAddresses() const
{
  std::vector<std::string> addresses;
  for (const auto &pair : accounts)
  {
    addresses.push_back(pair.first);
  }
  return addresses;
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

const std::vector<Transaction> &Blockchain::getPendingTransactions() const
{
  return pendingTransactions;
}

const std::vector<Block> &Blockchain::getChain() const
{
  return chain;
}

void Blockchain::updateAccountBalances(const std::vector<Transaction> &transactions)
{
  for (const auto &tx : transactions)
  {
    // The sender and getter should be an existing account
    if (accounts.find(tx.getFrom()) != accounts.end())
    {
      accounts.at(tx.getFrom()).adjustBalance(-tx.getAmount());
    }
    if (accounts.find(tx.getTo()) != accounts.end())
    {
      accounts.at(tx.getTo()).adjustBalance(tx.getAmount());
    }
  }
}