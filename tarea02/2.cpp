#include <random>
#include <iostream>

void fill_array(double * array, int size, int seed, double mu, double sigma);
double get_mean(double * array, int size);

int main(void)
{
  const int N = 100000;
  const int seed = 1;
  double * data;
  data = new double [N];
  fill_array(data, N, seed, 1.5, 0.5);
  std::cout<< "The mean is : " << get_mean(data, N) << std::endl; //dentro del get_mean basta con poner N, se borró el + 1 
  
  
  return 0;
}

void fill_array(double * array, int size, int seed, double mu, double sigma)
{
  std::mt19937 gen(seed);
  std::normal_distribution<> dis(mu, sigma); //se cambia los "{}" por "()"
  for(int n = 1; n <= size; n++) //se modifica el '>=' por '<=' y se cambia 'n>=0' por 'n<=size'. De no hacer esto el for nunca se detiene.Ese era el problema, el for no se detenía.
    {   
      array[n] = dis(gen); //acá salía el error principal, en principio era porque ser porque nunca acababa el for. Quitamos el ++ dentro del array
      
    }
  
  
}

double get_mean(double * array, int size)
{
  double sum=0;// se define sum=0.
  for (int ii = 0; ii <= size; ii += 1) //se cambia en 2 por 1.
    {
      sum += array[ii];
    }
  //array = new double [size];//cambiamos 2 por size. La quitamos 
  return sum/size;
  delete [] array;
}
