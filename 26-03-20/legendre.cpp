#include <cmath>
#include <iostream>

int main ()
{
  const double XMIN = -1.0,XMAX = 1.0;
  const double DX = 0.01;
  const int N = 5;
  std::cout.precision(15);
  std::cout.setf(std::ios::scientific);

  for(double x = XMIN; x<= XMAX; x += DX)
    {
      std::cout << x <<"\t"<< std::legendre(N,x) <<"\n" << std::endl;
    }
  return 0;

}
