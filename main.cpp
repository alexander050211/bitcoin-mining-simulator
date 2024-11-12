#include "Interface.h"
#include <iostream>

int main(int argc, char *argv[])
{
  // Default difficulty set to 4
  uint32_t difficulty = 4;
  if (argc > 1)
  {
    try
    {
      difficulty = std::stoi(argv[1]);
    }
    catch (const std::exception &e)
    {
      std::cerr << "Invalid difficulty argument. Using default difficulty of 4." << std::endl;
    }
  }

  std::cout << "Creating blockchain with difficulty " << difficulty << "\n";
  Blockchain blockchain(difficulty);

  // Create system accounts
  blockchain.createAccount("Network", 1000000.0);
  blockchain.createAccount("Miner", 0.0);

  // Start CLI
  Interface cli(blockchain);
  cli.start();

  return 0;
}