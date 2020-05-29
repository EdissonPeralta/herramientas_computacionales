#include <random>
#include <iostream>

int main(void)
{
  int seed = 4;
  std::mt19937 gen(seed);
  std::uniform_real_distribution<> dis(0, 1);
  for(int n = 0; n < 1000; ++n) {
    std::cout << dis(gen) << std::endl;
  }
}
