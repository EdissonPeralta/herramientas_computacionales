#include <cstdio>
#include <cmath>
#include <random>
#include <cstdlib>
#include "mpi.h"

void print(int * m, int nx, int ny);

int main(int argc, char **argv) 
{
  int N = std::atoi(argv[1]);

  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  //double tstart = MPI_Wtime();
  // N = number of columns -> y
  // nlocal = number of rows -> x
  int nlocal = N/np;
  int * data = new int [nlocal*N] {0};
  // llenar los sitios correspondientes
  for (int irow = 0; irow < nlocal; ++irow) {
    int iy = pid*nlocal + irow;
    int ix = irow;
    // data[ix][iy] -> data[ix*N + iy]
    data[ix*N + iy] = 1;
  }
  //double tend = MPI_Wtime();
  //std::printf("Time from pid %d: %lf\n", pid, tend-tstart);
  // imprimir y enviar
  if (0 != pid) {
    MPI_Send(data, nlocal*N, MPI_INT, 0, 0, MPI_COMM_WORLD);
  } else if (0 == pid) {
    print(data, nlocal, N);
    for (int ii = 1; ii < np; ++ii) {
      MPI_Recv(data, nlocal*N, MPI_INT, ii, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      print(data, nlocal, N);
    }
  }

  MPI_Finalize();
  delete [] data;
  
  return 0;
}

void print(int * m, int nx, int ny)
{
  for (int ii = 0; ii < nx; ++ii) {
    for (int jj = 0; jj < ny; ++jj) {
      std::printf("%d ", m[ii*ny + jj]);
    }
    std::printf("\n");
  }
}
