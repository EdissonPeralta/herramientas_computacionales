#include <cstdio>
#include <iostream>
#include <cmath>
#include <random>
#include <cstdlib>
#include <vector>
#include "mpi.h"

int main(int argc, char **argv) 
{
  typedef std::vector<double>Matrix;
  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  
  int N = 0;
  if (0 == pid)
    {
      std::printf("Por favor escriba el total de elementos N:\n");
      std::scanf("%d", &N);
    }
  MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
  int nlocal = N/np;
  Matrix data(N*N/nlocal);
  int imin=pid*nlocal;
  MPI_Bcast(&data, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Scatter(&data, 1, MPI_UNSIGNED_CHAR, &pid, 1, MPI_INT, 0, MPI_COMM_WORLD);
  
  for (int ii = imin ; ii < imin+nlocal; ++ii)
    {
      for (int jj =0; jj < N; ++jj)
	{
	  if (ii == jj)
	    {
	      data[ii*N + jj] = 1.0;
	    }
	  else
	    {
	      data[ii*N + jj]=0.0;
	    }
	}
    }
  Matrix q(N*N);
  MPI_Gather(&data, 1 , MPI_UNSIGNED_CHAR, &q, 1, MPI_INT, 0, MPI_COMM_WORLD);

  int tag =0;
  if(0==pid)
    {
      Matrix q(N*N);
      for (int ii=0; ii < np; ++ii)
	{
	  MPI_Recv(&q,1,MPI_UNSIGNED_CHAR,ii, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}
      //std::printf("El area total es %d:%lf\n", q);
    }
  else
    {
      int dest=0;
      MPI_Send(&data,1,MPI_UNSIGNED_CHAR,dest, tag, MPI_COMM_WORLD);
    }
  MPI_Finalize();
  
  return 0;
}
