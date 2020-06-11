#include <iostream>
#include <vector>
#include <cmath>
#include "mpi.h"

const double delta = 0.1;
const double L = 10;
const int N=int(L/delta)+1;
const int totalsteps=500;

typedef std::vector<double> Matrix;

void condiciones_iniciales(Matrix & m);
void condiciones_de_frontera(Matrix & m);
void evolucion(Matrix & m);
void print(const Matrix & m);

int main(int argc, char **argv)
{
  int pid, np;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &pid);
  MPI_Comm_size(MPI_COMM_WORLD, &np);

  Matrix data(N*N);
  condiciones_iniciales(data);
  condiciones_de_frontera(data);
  
  for (int step=0; step < totalsteps; ++step)
    {
      evolucion(data);
    }
  double total=0;
  MPI_Reduce(&evolucion(&data), &total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  print(data);
    
  if (0 == pid) {
    std::printf("El area total es %lf\n", total);
  }
  
  
  MPI_Finalize();
  
  return 0;
}

void condiciones_iniciales(Matrix & m)
{
  for (int ii=0 ; ii < N ; ++ii)
    {
      for (int jj = 0 ; jj < N ; ++jj)
	{
	  m[ii*N + jj] = 1.0;
	}
    }
}

void condiciones_de_frontera(Matrix & m)
{
  int ii = 0, jj = 0;
  
  ii = 0;
  for (jj = 0 ; jj < N ; ++jj)
    m[ii*N + jj] = 100;
  
  ii = N-1;
  for (jj = 0; jj < N-1; ++jj)
    m[ii*N + jj] = -100;
  
  jj = 0;
  for (ii = 1; ii < N-1; ++ii)
    m[ii*N + jj] = 0;
  
  jj = N-1;
  for(ii = 1; ii < N; ++ii)
    m[ii*N + jj] = 0;
 
  for(ii = 0; ii < N; ++ii)
    {
      for (jj = 0;jj < N; ++jj)
	{
	  if (std::pow(ii-(L*10)/2.0,2)+std::pow(jj-(L*10)/2.0,2) <= std::pow(40,2))
	    m[ii*N + jj] = 0;
	}
    }
}

void print(const Matrix & m)
{
  for(int ii=0; ii<N; ++ii)
    {
      for(int jj=0; jj<N; ++jj)
	{
	  std::cout << ii*delta << " " << jj*delta << " " << m[ii*N + jj] << "\n";
	}
      std::cout << "\n";
    }
}

void evolucion(Matrix & m)
{
  for (int ii=0; ii<N; ++ii)
    {
      for (int jj=0; jj<N; ++jj)
	{
	  if (ii == 0) continue;
	  if (ii == N-1) continue;
	  if (jj == 0) continue;
	  if (jj == N-1) continue;
	  if (std::pow(ii-(L*10)/2.0,2)+std::pow(jj-(L*10)/2.0,2) <= std::pow(40,2)) continue;
	  m[ii*N+jj]=(m[(ii+1)*N + jj]+
		      m[(ii-1)*N + jj]+
		      m[ii*N + jj + 1]+
		      m[ii*N + jj - 1])/4.0;
	}
    }
}
