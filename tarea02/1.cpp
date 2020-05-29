#include <cstdio> // for printf
#include <cmath>

double myatan(double x, int n);

int main(void)
{
  const int NSTEPS = 53;
  const double X = 4.2;
  const double EXACT = std::atan(X);
  for(int n = 1; n <= NSTEPS; n+=2) {
    double my = myatan(X, n);
    double diff = std::fabs(1-my/exact);
    std::printf("%25d\t%25.16e\n", n, diff);
  }
  
  return 0;
}

double myatan(double x, int n)
{
  // fill here
}
