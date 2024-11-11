#include "Interface.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>

// Constructor
Interface::Interface(Blockchain &bc) : blockchain(bc), running(true)
{
  // Register commands
  commands["create_account"] = [this](const auto &args)
  { handleCreateAccount(args); };
  commands["send"] = [this](const auto &args)
  { handleSendTransaction(args); };
  commands["mine"] = [this](const auto &args)
  { handleMineBlock(args); };
  commands["balances"] = [this](const auto &args)
  { handleShowBalances(args); };
  commands["pending"] = [this](const auto &args)
  { handleShowPending(args); };
  commands["help"] = [this](const auto &args)
  { handleHelp(args); };
  commands["exit"] = [this](const auto &args)
  { running = false; };
  commands["random"] = [this](const auto &args)
  { handleRandomTransactions(args); };
}

// Helper methods
std::vector<std::string> Interface::tokenize(const std::string &line)
{
  std::vector<std::string> tokens;
  std::stringstream ss(line);
  std::string token;
  while (ss >> token)
  {
    tokens.push_back(token);
  }
  return tokens;
}

void Interface::printBalance(const std::string &address)
{
  std::cout << std::setw(10) << address << ": "
            << std::fixed << std::setprecision(2)
            << blockchain.getBalance(address) << " coins" << std::endl;
}

// Generate a random transaction
Transaction Interface::generateRandomTransaction(const std::vector<std::string> &addresses)
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
  amount = std::round(amount * 100.0) / 100.0;
  return Transaction(from, to, amount);
}

// Command handlers
void Interface::handleCreateAccount(const std::vector<std::string> &args)
{
  if (args.size() != 2)
  {
    std::cout << "Usage: create_account <address> <initial_balance>" << std::endl;
    return;
  }

  try
  {
    double balance = std::stod(args[1]);
    if (blockchain.createAccount(args[0], balance))
    {
      std::cout << "Account created successfully" << std::endl;
    }
    else
    {
      std::cout << "Failed to create account (might already exist)" << std::endl;
    }
  }
  catch (const std::exception &e)
  {
    std::cout << "Invalid balance amount" << std::endl;
  }
}

void Interface::handleSendTransaction(const std::vector<std::string> &args)
{
  if (args.size() != 3)
  {
    std::cout << "Usage: send <from> <to> <amount>" << std::endl;
    return;
  }

  try
  {
    double amount = std::stod(args[2]);
    Transaction tx(args[0], args[1], amount);
    if (blockchain.addTransaction(tx))
    {
      std::cout << "Transaction added successfully" << std::endl;
    }
    else
    {
      std::cout << "Transaction failed (check balances and addresses)" << std::endl;
    }
  }
  catch (const std::exception &e)
  {
    std::cout << "Invalid amount" << std::endl;
  }
}

void Interface::handleMineBlock(const std::vector<std::string> &args)
{
  if (!blockchain.getPendingTransactions().empty())
  {
    blockchain.addBlock(blockchain.getPendingTransactions());
    std::cout << "Block mined and added to the chain" << std::endl;
  }
  else
  {
    std::cout << "No pending transactions to mine" << std::endl;
  }
}

void Interface::handleShowBalances(const std::vector<std::string> &args)
{
  std::cout << "\nCurrent Balances:" << std::endl;
  std::cout << std::string(30, '-') << std::endl;

  for (const auto &address : blockchain.getAccountAddresses())
  {
    printBalance(address);
  }

  std::cout << std::string(30, '-') << std::endl;
}

void Interface::handleShowPending(const std::vector<std::string> &args)
{
  const auto &pending = blockchain.getPendingTransactions();
  if (pending.empty())
  {
    std::cout << "No pending transactions" << std::endl;
    return;
  }

  std::cout << "\nPending Transactions:" << std::endl;
  std::cout << std::string(50, '-') << std::endl;
  for (const auto &tx : pending)
  {
    std::cout << tx.getFrom() << " -> " << tx.getTo() << ": "
              << std::fixed << std::setprecision(2) << tx.getAmount()
              << " coins" << std::endl;
  }
  std::cout << std::string(50, '-') << std::endl;
}

void Interface::handleRandomTransactions(const std::vector<std::string> &args)
{
  if (args.empty())
  {
    std::cout << "Usage: random <number_of_transactions>" << std::endl;
    return;
  }

  // Get all account addresses except system accounts
  std::vector<std::string> addresses;
  for (const auto &addr : blockchain.getAccountAddresses())
  {
    if (addr != "Network" && addr != "Miner")
    {
      addresses.push_back(addr);
    }
  }

  // Check if we have enough accounts
  if (addresses.size() < 2)
  {
    std::cout << "Need at least 2 regular accounts to generate random transactions" << std::endl;
    return;
  }

  try
  {
    int numTransactions = std::stoi(args[0]);
    if (numTransactions <= 0)
    {
      std::cout << "Number of transactions must be positive" << std::endl;
      return;
    }

    int successfulTx = 0;
    for (int i = 0; i < numTransactions; i++)
    {
      Transaction tx = generateRandomTransaction(addresses);
      if (blockchain.addTransaction(tx))
      {
        successfulTx++;
      }
    }

    std::cout << "Generated " << successfulTx << " successful transactions out of "
              << numTransactions << " attempts" << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cout << "Invalid number of transactions" << std::endl;
  }
}

void Interface::handleHelp(const std::vector<std::string> &args)
{
  std::cout << "\nAvailable commands:" << std::endl;
  std::cout << "  create_account <address> <initial_balance> - Create a new account" << std::endl;
  std::cout << "  send <from> <to> <amount>                  - Send coins from one account to another" << std::endl;
  std::cout << "  random <number>                            - Generate random transactions" << std::endl;
  std::cout << "  mine                                       - Mine pending transactions" << std::endl;
  std::cout << "  balances                                   - Show all account balances" << std::endl;
  std::cout << "  pending                                    - Show pending transactions" << std::endl;
  std::cout << "  help                                       - Show this help message" << std::endl;
  std::cout << "  exit                                       - Exit the program" << std::endl;
}

void Interface::start()
{
  std::cout << "Blockchain CLI" << std::endl;
  std::cout << "Type 'help' for available commands" << std::endl;

  while (running)
  {
    std::string line;
    std::cout << "\n> ";
    std::getline(std::cin, line);

    auto tokens = tokenize(line);
    if (tokens.empty())
      continue;

    std::string command = tokens[0];
    tokens.erase(tokens.begin()); // Remove command from arguments

    auto it = commands.find(command);
    if (it != commands.end())
    {
      it->second(tokens);
    }
    else
    {
      std::cout << "Unknown command. Type 'help' for available commands." << std::endl;
    }
  }
}