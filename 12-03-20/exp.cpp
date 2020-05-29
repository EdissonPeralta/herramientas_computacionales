#include <stdio.h>
#include <iostream>
#include <cmath>

int main(void) 
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  double term=1.0, sum =1.0, eps=1.0e-8;
  double x=0.1;
  int i=1;
  
  do
    {
      std::cout<<i<<"\t"<<sum<<"\n";
      term=-term*x/i;
      sum+=term;
      i++;
      
    }
  
  while(std::fabs(term/sum)>eps);

  std::cout<<"el valor de la exponecial es _"<<sum<<"\n";  
  return 0;
}
