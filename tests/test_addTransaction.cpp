#include <gtest/gtest.h>
#include "../Blockchain.h"
#include "../Transaction.h"

// Define the maximum number of transactions per block
const int MAX_TRANSACTIONS_PER_BLOCK = 10;

// Test fixture for Blockchain tests
class BlockchainTest : public ::testing::Test
{
protected:
  Blockchain blockchain;

  void SetUp() override
  {
    // Create some accounts for testing
    blockchain.createAccount("Alice", 100.0);
    blockchain.createAccount("Bob", 50.0);
  }
};

// Test adding a valid transaction
TEST_F(BlockchainTest, AddValidTransaction)
{
  Transaction tx("Alice", "Bob", 10.0);
  EXPECT_TRUE(blockchain.addTransaction(tx));
}

// Test adding an invalid transaction (insufficient balance)
TEST_F(BlockchainTest, AddInvalidTransactionInsufficientBalance)
{
  Transaction tx("Bob", "Alice", 100.0); // Bob doesn't have enough balance
  EXPECT_FALSE(blockchain.addTransaction(tx));
}

// Test adding an invalid transaction (non-existent account)
TEST_F(BlockchainTest, AddInvalidTransactionNonExistentAccount)
{
  Transaction tx("Charlie", "Alice", 10.0); // Charlie doesn't exist
  EXPECT_FALSE(blockchain.addTransaction(tx));
}

// Test adding multiple transactions to trigger block creation
TEST_F(BlockchainTest, AddMultipleTransactions)
{
  for (int i = 0; i < MAX_TRANSACTIONS_PER_BLOCK; ++i)
  {
    Transaction tx("Alice", "Bob", 1.0);
    EXPECT_TRUE(blockchain.addTransaction(tx));
  }
  // Check if pending transactions are cleared after block creation
  EXPECT_EQ(blockchain.getPendingTransactions().size(), 0);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}