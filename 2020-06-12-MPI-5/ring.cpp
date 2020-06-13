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

  int val = -1;
  //double tstart = MPI_Wtime();
  MPI_Send(&pid, 1, MPI_INT, (pid+1)%np, 0, MPI_COMM_WORLD);
  MPI_Recv(&val, 1, MPI_INT, (pid-1+np)%np, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  
  std::printf("Rank: %d, received: %d\n", pid, val);
  
  MPI_Finalize();
  
  return 0;
}

