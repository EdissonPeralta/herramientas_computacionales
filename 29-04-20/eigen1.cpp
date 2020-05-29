#include <iostream>
#include <Eigen/Dense>


int main()
{
  Eigen::MatrixXd m(8,8);
  std::cout << m << std::endl;
  for(int i=0;i<=7;++i){
    for(int j=0;j<=7;++j)
      {
	m(i,j)=0;
	  }      
  }
  //m(0,0) = 3;
  //m(1,0) = 2.5;
  //m(0,1) = -1;
  //m(1,1) = m(1,0) + m(0,1);
  //std::cout << m << std::endl;
}
