#include <iostream>
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
  printBalance(blockchain, "Alice");
  printBalance(blockchain, "Bob");
  printBalance(blockchain, "Charlie");
  printBalance(blockchain, "David");
  printBalance(blockchain, "Miner");
  std::cout << std::string(30, '-') << std::endl;
}

int main()
{
  // Create blockchain with difficulty 4
  std::cout << "Creating blockchain...\n";
  Blockchain blockchain(4);

  // First block of transactions
  std::cout << "\nCreating first set of transactions...\n";
  blockchain.addTransaction(Transaction("Alice", "Bob", 50.0));
  blockchain.addTransaction(Transaction("Bob", "Charlie", 30.0));
  blockchain.addTransaction(Transaction("Charlie", "David", 20.0));
  blockchain.addTransaction(Transaction("David", "Alice", 15.0));
  blockchain.addTransaction(Transaction("Alice", "Charlie", 25.0));

  blockchain.addTransaction(Transaction("Alice", "Charlie", 25.0));

  printAllBalances(blockchain);

  // Second block of transactions
  std::cout << "\nCreating second set of transactions...\n";
  blockchain.addTransaction(Transaction("Bob", "Alice", 40.0));
  blockchain.addTransaction(Transaction("Charlie", "Bob", 25.0));
  blockchain.addTransaction(Transaction("David", "Charlie", 35.0));
  blockchain.addTransaction(Transaction("Alice", "David", 20.0));
  blockchain.addTransaction(Transaction("Bob", "David", 15.0));

  printAllBalances(blockchain);

  // Create final block for pending transactions
  if (blockchain.getPendingTransactions().size() > 0)
    blockchain.addBlock(blockchain.getPendingTransactions());
  printAllBalances(blockchain);

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