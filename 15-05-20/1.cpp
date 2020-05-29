#include <iostream>

int main(void)
{
#pragma omp parallel 
{  
  std::cout << "Hello world\n";
} 
  return 0;
}
