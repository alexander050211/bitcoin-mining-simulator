#include <iostream>
#include "Blockchain.h"

int main()
{
  // Create blockchain
  std::cout << "Creating blockchain..." << std::endl;
  Blockchain blockchain(4);

  // Create some sample transactions
  Transaction tx1("Alice", "Bob", 50.0);
  Transaction tx2("Bob", "Charlie", 30.0);
  Transaction tx3("Charlie", "Alice", 20.0);

  // Add transactions to blockchain
  std::cout << "\nAdding transactions..." << std::endl;
  blockchain.addTransaction(tx1);
  blockchain.addTransaction(tx2);
  blockchain.addTransaction(tx3);

  // Mine the block (this will include pending transactions)
  std::cout << "\nMining block..." << std::endl;
  blockchain.addBlock(blockchain.getPendingTransactions());

  // Print balances
  std::cout << "\nFinal Balances:" << std::endl;
  std::cout << "Alice: " << blockchain.getBalance("Alice") << std::endl;
  std::cout << "Bob: " << blockchain.getBalance("Bob") << std::endl;
  std::cout << "Charlie: " << blockchain.getBalance("Charlie") << std::endl;

  // Verify blockchain integrity
  if (blockchain.isValid())
  {
    std::cout << "\nBlockchain is valid!" << std::endl;
  }
  else
  {
    std::cout << "\nBlockchain is invalid!" << std::endl;
  }

  return 0;
}