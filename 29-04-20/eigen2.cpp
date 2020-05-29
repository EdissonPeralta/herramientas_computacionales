#include <iostream>
#include <Eigen/Dense>


int main(void)
{
  double sum=0;
  int L=100;
  srand(5);//controlo la semilla
  Eigen::MatrixXd m= Eigen::MatrixXd::Random(L,L);//genera una matriz de numeros aleatorios
  //std::cout << sum << std::endl;
  for(int i=0;i<=(L-1);++i){
    for(int j=0;j<=(L-1);++j)
      {
	if (i==j)
	  {	    
	    sum +=m(i,j);//hace la traza	    
	  }
      }      
    
  }
  //std::cout << m << std::endl;
  std::cout << sum << std::endl;  
  //m(0,0) = 3;
  //m(1,0) = 2.5;
  //m(0,1) = -1;
  //m(1,1) = m(1,0) + m(0,1);
  //std::cout << m << std::endl;
}
