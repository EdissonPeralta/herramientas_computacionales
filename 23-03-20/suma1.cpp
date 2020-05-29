#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main (void)
{
  int num,sing;
  float m,u;
  num=10;
  sing=-1;
  for (int i=1; i<=2*num; i++)
    {       
      m=(sing)*(1.0)*i/(i+1);
      u=u+m;
      sing=sing*(-1);
      std::cout<<i<<"\t"<<u<<"\t"<<m<<std::endl;
    }
  return u;
  
} 
