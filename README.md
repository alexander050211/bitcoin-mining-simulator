## How to use SHA256

### The safe way
```
SHA256 sha256;
std::string input;
sha256.update(input);
std::string hash = sha256.final();
```
### The immediate way
Doesn't need instance of SHA256 to get hash
```
std::string quickHash = SHA256::hash(input);
```