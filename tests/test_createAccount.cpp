#include <gtest/gtest.h>
#include "../Blockchain.h"

// Test fixture for Blockchain tests
class BlockchainTest : public ::testing::Test
{
protected:
  Blockchain blockchain;
};

// Test creating an account
TEST_F(BlockchainTest, CreateAccount)
{
  EXPECT_TRUE(blockchain.createAccount("Charlie", 200.0));
  EXPECT_FALSE(blockchain.createAccount("Alice", 100.0)); // Account already exists
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}