#include <gtest/gtest.h>
#include "../Blockchain.h"
#include "../Transaction.h"

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

// Test adding a block
TEST_F(BlockchainTest, AddBlock)
{
  Transaction tx("Alice", "Bob", 10.0);
  blockchain.addTransaction(tx);
  blockchain.addBlock(blockchain.getPendingTransactions());
  EXPECT_EQ(blockchain.getBalance("Alice"), 90.0);
  EXPECT_EQ(blockchain.getBalance("Bob"), 60.0);
  EXPECT_EQ(blockchain.getPendingTransactions().size(), 0);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}