#include <bits/stdc++.h>
#include "SHA256.h"
#include "Block.h"

int main()
{
  Block block1 = Block(0, "Block 1 Data");
  block1.mineBlock(5);
  std::cout << block1.getNonce() << std::endl;
  return 0;
}