#include <iostream>
#include "Blockchain.h"

int main()
{
  // Create blockchain with mining difficulty of 4
  std::cout << "Creating blockchain..." << std::endl;
  Blockchain blockchain(4);

  std::cout << "\nMining block 1..." << std::endl;
  blockchain.addBlock("Transaction Data 1");

  std::cout << "\nMining block 2..." << std::endl;
  blockchain.addBlock("Transaction Data 2");

  // Print the blockchain
  std::cout << "\nBlockchain:\n";
  for (const auto &block : blockchain.getChain())
  {
    std::cout << "Index: " << block.blockIndex << std::endl;
    std::cout << "Hash: " << block.hash << std::endl;
    std::cout << "Previous Hash: " << block.prevHash << std::endl;
    std::cout << "------------------------" << std::endl;
  }

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