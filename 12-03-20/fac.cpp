/*
#include <iostream>
#include <stdlib.h>

using namespace std;

int main ()
{
  int num;
  long long factorial=1,i;
  num=20;
    
    for (int i=1; i<num+1; i++)
      {       
	factorial=factorial*i;
	std::cout<<i<<"\t"<<factorial<<std::endl;
      }
    return factorial;
  
}
*/

//****************************************************************
//****************************************************************


// CPP code for implementing sin function 
#include <iostream> 
#include <math.h> 
using namespace std;

// Main function 
int main() 
{ 
  float n = 0.1;  
  int num=10;
  int j;
  long long factorial=1;

  
  
  
  // Function for calculating sin value 
  void cal_sin(float n); 
    for(j=1; j<num+1; j++)
      {       
	factorial=factorial*j;
	//std::cout<<j<<"\t"<<factorial<<std::endl;
      }
    // return factorial;
    
    float accuracy = 0.0001, denominator, sinx, sinval; 
    
    // Converting degrees to radian 
    n = n * (3.142 / 180.0);  
    
    float x1 = n; 
    
    // maps the sum along the series 
    sinx = n;          
      
    // holds the actual value of sin(n) 
    sinval = sin(n);
    int i=1;
    do
      { 
	denominator = 2 * i * (2 * i + 1);
	std::cout<<denominator<<std::endl;
	x1 = -x1 * n * n / denominator;
	//x1 = -x1 * n * n / factorial; 
	sinx = sinx + x1; 
	i = i + 1; 
      }
    while (accuracy <= fabs(sinval - sinx));
    
    std::cout<<"valor del seno"<<"\t"<<sinx<<std::endl;
    
  
    //cal_sin(n);
  
  return 0;
} 
