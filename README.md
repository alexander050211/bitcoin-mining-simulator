## How to use SHA256
You don't have to create an instance of the SHA256 class to use it. Just call the static function ```std::string sha256(std::string input);```
### Example code
```cpp
std::string input = "202124";
std::string output1 = sha256(input);
std::cout << "sha256('" << input << "'):" << output1 << std::endl;
```
## How to use Block
The Block class implements the concept of a block in a blockchain. It can be created and mined with the code below.
```cpp
Block block1 = Block(0, "Block 1 Data");
block1.mineBlock(5);
std::cout << block1.getNonce() << std::endl;
```

## How to use Blockchain
You can create an instance of the Blockchain with a specific mining difficulty. When the instance is created, the genesis block is added to the chain. You can then start adding blocks to the chain by only giving the data of the next block.
### Example code
```cpp
Blockchain blockchain(4);
blockchain.addBlock("Transaction Data 1");
```
After adding blocks, you can print the information of the blockchain using range-based for statements.
```cpp
for (const auto &block : blockchain.getChain())
{
  std::cout << "Index: " << block.blockIndex << std::endl;
  std::cout << "Hash: " << block.hash << std::endl;
  std::cout << "Previous Hash: " << block.prevHash << std::endl;
  std::cout << "------------------------" << std::endl;
}
```