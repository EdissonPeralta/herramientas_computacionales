#include <omp.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <cmath>


const int N = 5;

int main(int argc, char *argv[]) 
{
  std::vector<double> data(N);
  double suma = 0.0;
 
  for (int ii = 0; ii < N; ++ii)
    {
    data[ii]=ii+1;
    suma += data[ii]*data[ii]; 
    }
  std::cout << "promedio del vector calculado: " << std::pow(suma,1.0/2) << std::endl;
  //std::cout << "mean esperada : " << 1.5 << std::endl;

  return 0;
}

