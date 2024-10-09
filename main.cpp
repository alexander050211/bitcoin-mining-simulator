#include <bits/stdc++.h>
#include "SHA256.h"

int main()
{
  SHA256 sha256;
  std::string input = "Hello, world!";
  sha256.update(input);
  std::string hash = sha256.final();

  std::cout << "SHA256(\"" << input << "\") = " << hash << std::endl;

  std::string quickHash = SHA256::hash("abc");
  std::cout << "SHA256(\"abc\") = " << quickHash << std::endl;

  return 0;
}
