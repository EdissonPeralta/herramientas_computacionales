#include <cstdio>
#include "mpi.h"

int main(int argc, char **argv) 
{
  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  int nveces = 3;
  int counter = 0;

  // ping pong
  for (int ii = 0; ii < nveces; ++ii) {
    int tag = 0;
    if (0 == pid) {
      MPI_Send(&counter, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
      MPI_Recv(&counter, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    } else if (1 == pid) {
      MPI_Recv(&counter, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      counter += 2;
      MPI_Send(&counter, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);    
    }
  }
  // print
  if (0 == pid) {
    std::printf("El valor de counter es %d\n", counter);
  }
  
  
  MPI_Finalize();
  
  return 0;
}
