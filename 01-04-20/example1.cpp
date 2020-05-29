#include <iostream>
#include <cmath>

double f(int c);
int main(void)
{
  int a=6;
  int b=a;
  b=8;  
  f(b);
  return 0;
}
double f(int c)
{
  c = 2*c;
  return std::sin(c);
}

