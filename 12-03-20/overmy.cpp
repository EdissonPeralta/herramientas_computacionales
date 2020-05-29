#include <stdio.h>
#include <iostream>
#include <iomanip>

int main() 
{
  int n;
  float h,p;
  n=300;
  h=1.;
  for(int m=1; m < n; m++)
    {
      p=h/(m*m*m*m);
      std::cout<<m<<"\t"<<p<<std::endl;
      
    }
  
  return 0;
}
