#include <cstdio>
#include "mpi.h"


int main(int argc,char**argv)
{
  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  double counter = 0;
  int nveces=1;
  if (0 == pid) {
    MPI_Recv(&counter, 1, MPI_DOUBLE, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    total += area;
    }
  std::printf("valor de counter es %lf\n", );
} else {
    int dest = 0;
    MPI_Send(&nveces, 1, MPI_DOUBLE,dest, MPI_COMM_WORLD);
 }


if (0==pid)
  {
    std::printf("el valor de counter es %d\n",counter);
  }
  MPI_Finalize();
return 0;
}
