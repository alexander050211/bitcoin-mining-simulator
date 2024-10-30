## How to use SHA256
You don't have to create an instance of the SHA256 class to use it. Just call the static function ```std::string sha256(std::string input);```
### Example code
```
std::string input = "202124";
std::string output1 = sha256(input);
std::cout << "sha256('" << input << "'):" << output1 << std::endl;
```
