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