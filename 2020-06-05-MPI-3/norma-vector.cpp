#include <omp.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <cmath>


const int N = 90000000;

int main(int argc, char *argv[]) 
{
  std::vector<double> data(N);
  double suma = 0.0;
  int p=4;
  for (int ii = 0; ii < N; ++ii)
    {
      data[ii]=2.0*(ii+1);
    suma += pow(data[ii],p); 
    }
  std::cout << "promedio del vector calculado: " << std::pow(suma,1.0/p) << std::endl;
  //std::cout << "mean esperada : " << 1.5 << std::endl;

  return 0;
}

