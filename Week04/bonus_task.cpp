#include <iostream>

int main() {
  int num = 0, space = 0;
  std::cin >> num;
  for(int i = 1, k = 0; i <= num; i++, k = 0)
  {
    for(space = 1; space <= num - i; space++)
    {
      std::cout << " ";
    }
    while(k != 2*i-1)
    {
      std::cout <<"*";
      ++k;
    }
    std::cout << std::endl;
  }

  return 0;
}
