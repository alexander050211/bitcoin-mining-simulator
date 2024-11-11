#include <iostream>
#include <random>
#include <string>
#include <iomanip>
#include "Blockchain.h"

void printBalance(const Blockchain &blockchain, const std::string &address)
{
  std::cout << std::setw(10) << address << ": "
            << std::fixed << std::setprecision(2)
            << blockchain.getBalance(address) << " coins" << std::endl;
}

void printAllBalances(const Blockchain &blockchain)
{
  std::cout << "\nCurrent Balances:" << std::endl;
  std::cout << std::string(30, '-') << std::endl;

  for (const auto &address : blockchain.getAccountAddresses())
  {
    printBalance(blockchain, address);
  }

  std::cout << std::string(30, '-') << std::endl;
}

// Generate a random transaction between accounts
Transaction generateRandomTransaction(const std::vector<std::string> &addresses, std::mt19937 &gen)
{
  std::uniform_int_distribution<> addressDist(0, addresses.size() - 1);
  std::uniform_real_distribution<> amountDist(10.0, 100.0);

  std::string from = addresses[addressDist(gen)];
  std::string to;
  do
  {
    to = addresses[addressDist(gen)];
  } while (to == from || to == "Network" || from == "Network");

  double amount = amountDist(gen);
  return Transaction(from, to, amount);
}

int main()
{
  // Create blockchain with difficulty 4
  std::cout << "Creating blockchain...\n";
  Blockchain blockchain(4);

  // Create multiple accounts
  std::vector<std::string> agents = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank"};
  for (const auto &agent : agents)
  {
    blockchain.createAccount(agent, 1000.0); // Each starts with 1000 coins
  }

  // Print initial balances
  std::cout << "\nInitial balances:" << std::endl;
  printAllBalances(blockchain);

  // Set up random number generator
  std::random_device rd;
  std::mt19937 gen(rd());

  // Create multiple blocks of random transactions
  for (int block = 1; block <= 3; ++block)
  {
    std::cout << "\nCreating block " << block << " transactions...\n";

    // Generate random transactions for this block
    for (int i = 0; i < 5; ++i)
    {
      auto tx = generateRandomTransaction(agents, gen);
      blockchain.addTransaction(tx);
    }

    // Mine the block and show updated balances
    if (!blockchain.getPendingTransactions().empty())
      blockchain.addBlock(blockchain.getPendingTransactions());
    printAllBalances(blockchain);
  }

  // Verify blockchain integrity
  if (blockchain.isValid())
  {
    std::cout << "\nBlockchain integrity verified!" << std::endl;
  }
  else
  {
    std::cout << "\nBlockchain integrity check failed!" << std::endl;
  }

  return 0;
}