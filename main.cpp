#include <bits/stdc++.h>
#include "SHA256.h"

int main()
{
  std::string input = "202124";
  std::string output1 = sha256(input);
  std::cout << "sha256('" << input << "'):" << output1 << std::endl;
  return 0;
}