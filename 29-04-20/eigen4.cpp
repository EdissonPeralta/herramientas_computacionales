#include <iostream>
#include <Eigen/Dense>

int main()
{

  int L=5;
  srand(5);//controlo la semilla
  Eigen::MatrixXd A= Eigen::MatrixXd::Random(L,L);//genera una matriz de numeros aleatorios
  std::cout << "A:\n" << A <<std::endl;
  Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigensolver(A);
  if (eigensolver.info() !=Eigen::Success) abort();
  std::cout<<"autovalores de A:\n"<<eigensolver.eigenvalues()<<std::endl;
  std::cout<<"autovectores de A:\n"<<eigensolver.eigenvectors()<<std::endl;
}
