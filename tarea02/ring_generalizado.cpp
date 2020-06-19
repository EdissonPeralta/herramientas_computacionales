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
  int suma = 0;
  //double tstart = MPI_Wtime();
  for (int ii = 0; ii < np; ++ii)
    {
      MPI_Send(&pid, 1, MPI_INT, (pid-ii+np)%np, 0, MPI_COMM_WORLD);
      MPI_Recv(&val, 1, MPI_INT,(pid+ii)%np, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      suma=suma + val;
    }
  std::printf("Rank: %d; suma total: %d\n", pid,suma);
  
  MPI_Finalize();
  
  return 0;
}
