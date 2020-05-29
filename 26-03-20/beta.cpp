// requires c++17
#include <cstdio>
#include <cmath>

int main(void)
{
  const double XMIN = -3.0;
  const double XMAX = 3.0;
  const double YMIN = -3.0;
  const double YMAX = 3.0;
  const double DELTA = 0.01;
  const int NSTEPS = int((XMAX-XMIN)/DELTA);
  
  for(int ii = 0; ii < NSTEPS; ++ii) {
    double x = XMIN + ii*DELTA;
    for(int jj = 0; jj < NSTEPS; ++jj) {
      double y = YMIN + jj*DELTA;
      printf("%25.16e%25.16e%25.16e\n", x, y, std::beta(x, y));
    }
    printf("\n");
  }
  
  return 0;
}
