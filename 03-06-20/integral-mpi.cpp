 #include <cstdio>
#include "mpi.h"

/* Problem parameters */
double f(double x) {
  return x*x;
}

const int numberRects = 5000;
const double lowerLimit = 2.0;
const double upperLimit = 5.0;

int main(int argc, char **argv) 
{
  int i; 
  double area, at, heigth, width;

  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  int nrect = numberRects/np;
  int imin = pid*nrect;

  // PID |0 |0 |0 |1 |1 |1 |2 |2 |2 |
  // GID |0 |1 |2 |3 |4 |5 |6 |7 |8 |

  area = 0.0;
  width = (upperLimit - lowerLimit) / numberRects;

  for (i = imin; i < imin + nrect; ++i) {
    at = lowerLimit + i*width + width/2.0;
    heigth = f(at);
    area = area + width*heigth;
  }

  std::printf("The area (pid %d) from %lf to %lf is : %le\n", pid, lowerLimit + imin*width, lowerLimit + (imin+nrect)*width, area);

  int tag = 0;
  for (tag; tag<=pid; tag++)
    {
      if (0 == pid) {
	double total = area;
	MPI_Recv(&area, 1, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	total += area;
	std::printf("El area total es %lf\n", total);
      } else {
	int dest = 0;
    MPI_Send(&area, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
      }
    }
  
  MPI_Finalize();
  
  return 0;
}
