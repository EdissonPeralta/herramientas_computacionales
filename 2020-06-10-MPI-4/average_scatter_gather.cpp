#include <cstdio>
#include <cmath>
#include <random>
#include <cstdlib>
#include "mpi.h"

const double MU = 1.23;
const double SIGMA = 0.45;

int main(int argc, char **argv) 
{
  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  int N = 0;
  if (0 == pid) {
    std::printf("Por favor escriba el total de elementos N:\n");
    std::scanf("%d", &N);
  }
  MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

  // seeds
  int seed = pid;
  int * ibuffer = new int [np] {0}; 
  if (0 == pid) {
    for (int ii = 0; ii < np; ++ii) {
      ibuffer[ii] = 10 + ii;
    }
  }
  MPI_Scatter(ibuffer, 1, MPI_INT, &seed, 1, MPI_INT, 0, MPI_COMM_WORLD);
  printf("Pid: %d, seed: %d\n", pid, seed);
  
  double tstart = MPI_Wtime();
  std::mt19937 gen(seed);
  std::normal_distribution<double> d (MU, SIGMA); 
  int nlocal = N/np;
  double sum = 0.0;
  for (int ii = 0; ii < nlocal; ++ii) {
    sum += d(gen);
  }
  double tend = MPI_Wtime();
  std::printf("Time from pid %d: %lf\n", pid, tend-tstart);
  std::printf("Sum  from pid %d: %lf\n", pid, sum);
  
  double * dbuffer = new double [np] {0}; 
  MPI_Gather(&sum, 1, MPI_DOUBLE, dbuffer, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  
  if (0 == pid) {
    double total = 0;
    for (int ii = 0; ii < np; ++ii) {
      total += dbuffer[ii];
    }
    std::printf("El promedio es %lf\n", total/N);
  }
  

  MPI_Finalize();

  delete [] ibuffer;
  delete [] dbuffer;
  
  return 0;
}
