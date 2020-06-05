#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "mpi.h"

int main(int argc, char **argv) 
{
  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  int tamvector = 0;
  double sumatotal = 0;
  int p = 1;
  if (0 == pid) {
    std::printf("Por favor escriba el tamaño del vector:\n");
    std::scanf("%d", &tamvector);
    std::printf("%d\n", tamvector);
    
    std::printf("Por favor escriba el valor de p:\n");
    std::scanf("%d", &p);
    std::printf("%d\n", p);
  }
  MPI_Bcast(&tamvector, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast(&sumatotal, 1, MPI_INT, 0, MPI_COMM_WORLD);

  double tstart = MPI_Wtime();
  double suma = 0.0;
  std::vector<double> data(tamvector);
  for (int ii = 0; ii < tamvector; ++ii)
    {
    data[ii]=ii+1;
    suma += pow(data[ii],p);
    }
  sumatotal=std::pow(suma,1.0/p);
  double tend = MPI_Wtime();
  std::printf("Time from pid %d: %lf\n", pid, tend-tstart);
  
  //std::printf("The area (pid %d) from %lf to %lf is : %le\n", pid, lowerLimit + imin*width, lowerLimit + (imin+nrect)*width, area);

  double total = 0;
  MPI_Reduce(&suma, &total, 1.0, MPI_DOUBLE, MPI_SUM, 0.0, MPI_COMM_WORLD);
  
  if (0 == pid) {
    std::printf("el promedio es %f\n", sumatotal);
  }
  
  
  MPI_Finalize();
  
  return 0;
}
