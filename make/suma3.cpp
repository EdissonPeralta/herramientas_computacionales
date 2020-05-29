#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main (void)
{
  int num;
  float c,m,u,v;
  num=10;
  u=0;
  v=0;
  for (int i=1; i<=num; i++)
    {       
      m=1.0/((2*i)*(2*i+1));
      u=u+m;
      std::cout<<i<<"\t"<<u<<"\t"<<m<<std::endl;
    }
  return v,u;
  
} 
