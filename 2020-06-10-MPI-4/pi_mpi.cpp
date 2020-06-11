#include <cstdio>
#include <cmath>
#include <random>
#include <cstdlib>
#include "mpi.h"

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
  std::uniform_real_distribution<double> d (-1.0, 1.0); 
  int nlocal = N/np;
  int Nc = 0.0;
  for (int ii = 0; ii < nlocal; ++ii) {
    double x = d(gen);
    double y = d(gen);
    if (x*x + y*y < 1.0) {
      Nc++;
    }
  }
  double tend = MPI_Wtime();
  std::printf("Time from pid %d: %lf\n", pid, tend-tstart);
  std::printf("Nc   from pid %d: %d\n", pid, Nc);

  int Nc_total = 0;
  MPI_Reduce(&Nc, &Nc_total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  
  if (0 == pid) {
    std::printf("pi: %25.16le\n", 4.0*Nc_total/N);
  }
  

  MPI_Finalize();
  
  return 0;
}
