#include <omp.h>
#include <iostream>
#include <cstdlib>
#include <cmath>

const int N = 1000;

int main(int argc, char *argv[]) 
{
  int nthreads = std::atoi(argv[1]);

  double *A = new double [N*N] {0.0};
  double *B = new double [N*N] {0.0};
  double *C = new double [N*N] {0.0};

  // init
  for (int ii = 0; ii < N; ++ii) {
    for (int jj = 0; jj < N; ++jj) {
      A[ii*N +jj] = 1.0/(2*ii + jj + 1);
      B[ii*N +jj] = (3*ii + 7*jj);
    }
  }

  // mult
  for (int ii = 0; ii < N; ++ii) {
    for (int jj = 0; jj < N; ++jj) {
      for (int kk = 0; kk < N; ++kk) {
	C[ii*N + jj] += A[ii*N + kk]*B[kk*N + jj];
      }
    }
  }
  
  // print
  std::cout << C[0] << std::endl;

  // free memory
  delete [] A;
  delete [] B;
  delete [] C;
  
  return 0;
}
