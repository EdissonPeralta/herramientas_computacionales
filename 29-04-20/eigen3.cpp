#include <iostream>
#include <Eigen/Dense>


int main(void)
{
  double sum=0;
  int L=100;
  srand(5);//controlo la semilla
  Eigen::MatrixXd A= Eigen::MatrixXd::Random(L,L);//genera una matriz de numeros aleatorios
  Eigen::VectorXd b= Eigen::VectorXd::Random(L);//genera una matriz de numeros aleatorios
  Eigen::MatrixXd x= A.fullPivHouseholderQr().solve(b);//resuelve el sistema
  //  AX=B
  //std::cout << A << std::endl;
  //std::cout << b << std::endl;
  std::cout << x << std::endl;  
  double DX=(A*x-b).norm()/b.norm();
  std::cout << DX << std::endl;  
}

