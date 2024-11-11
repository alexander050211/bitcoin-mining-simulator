#ifndef INTERFACE_H
#define INTERFACE_H

#include <map>
#include <string>
#include <vector>
#include <functional>
#include <random>
#include "Blockchain.h"

class Interface
{
private:
  Blockchain &blockchain;
  bool running;
  std::mt19937 gen;
  std::map<std::string, std::function<void(const std::vector<std::string> &)>> commands;

  // Helper methods
  std::vector<std::string> tokenize(const std::string &line);
  void printBalance(const std::string &address);
  Transaction generateRandomTransaction(const std::vector<std::string> &addresses);

  // Command handlers
  void handleCreateAccount(const std::vector<std::string> &args);
  void handleSendTransaction(const std::vector<std::string> &args);
  void handleMineBlock(const std::vector<std::string> &args);
  void handleShowBalances(const std::vector<std::string> &args);
  void handleShowPending(const std::vector<std::string> &args);
  void handleHelp(const std::vector<std::string> &args);
  void handleRandomTransactions(const std::vector<std::string> &args);

public:
  explicit Interface(Blockchain &bc);
  void start();
};

#endif // INTERFACE_H