#include <random>
#include <iostream>

int main(void)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis (0,1);
  for (int n=0;n<100;n++)
    {
      std::cout<<dis(gen)<<std::endl;
    }
  std::cout<<'\n';
}
