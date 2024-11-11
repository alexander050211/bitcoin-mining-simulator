#include "Interface.h"
#include <iostream>

int main()
{
  // Create blockchain with difficulty 4
  std::cout << "Creating blockchain...\n";
  Blockchain blockchain(4);

  // Create system accounts
  blockchain.createAccount("Network", 1000000.0);
  blockchain.createAccount("Miner", 0.0);

  // Start CLI
  Interface cli(blockchain);
  cli.start();

  return 0;
}