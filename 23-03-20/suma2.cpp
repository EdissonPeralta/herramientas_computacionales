#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main (void)
{
  int num;
  double c,m,u,v;
  num=10;
  u=0;
  v=0;
  for (int i=1; i<=num; i++)
    {       
      m=(2.0*i-1)/(2*i);
      c=(2.0*i)/(2*i+1);
      u=u+m;
      v=v+c;
      std::cout<<i<<"\t"<<v-u<<"\t"<<m<<"\t"<<c<<std::endl;
      //std::cout<<i<<"\t"<<v<<"\t"<<c<<std::endl;
    }
  return v,u;
  
} 
