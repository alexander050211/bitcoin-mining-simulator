#include <gtest/gtest.h>
#include "../Blockchain.h"

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

// Test getting balance
TEST_F(BlockchainTest, GetBalance)
{
  EXPECT_EQ(blockchain.getBalance("Alice"), 100.0);
  EXPECT_EQ(blockchain.getBalance("Bob"), 50.0);
  EXPECT_EQ(blockchain.getBalance("Charlie"), 0.0); // Account doesn't exist
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}