#include "mpi.h"
#include <stdio.h>

int main(int argc, char **argv)
{
  int pid,np;
  
  MPI_Init(&argc, &argv);                                       /* Mandatory */
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  
  std::cout << "my pid:"<<pid<<std::endl;
  std::cout << "total:"<<np<<std::endl;

  MPI_Finalize();                                               /* Mandatory */

  return 0; 
}
