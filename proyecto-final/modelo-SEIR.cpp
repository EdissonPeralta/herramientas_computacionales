#include <iostream>
#include <array>
#include <boost/numeric/odeint.hpp>

/*significado de las variables:

S: indivuduos susceptibles
I: indivuos infectados
R: indibiudos recupedados
E: individuos expuestos
N: población total
beta: tasa de contagios (probabilidad que una persona se contagie al estar en contacto con alguien infectado)
1.0/gamma: tiempo promedio de infección
miu: tasa promedio de defunciones (probabilidad que un infectado muera por el virus) 
f: tasa promedio de perdida de inmunidad en individuos recuperados
1.0/epsilon: tiempo promedio de incubación
B: tasa promedio de nacimientos
M: infantes con inmunidad pasiva
delta: tiempo promedio de inmunidad temporal

 */

const double beta = 0.2;
const double gama = 1.0/30;
const double miu = 0.032;
const double f = 0.032;
const double epsilon = 1.0/12.0;
const double B = 0.15;
const double M = 0.0;
const double delta = 28.0;
const double N = 50000000;


typedef std::array< double , 4 > state_type;

void comportamiento( const state_type &x , state_type &dxdt , double t )
{
  dxdt[0] = miu * N - miu * x[0] - (beta * x[2] * x[0])/N;
  dxdt[1] = (beta * x[0] * x[2])/N - (epsilon + miu) * x[1];
  dxdt[2] = epsilon * x[1] - (gama + miu) * x[2];
  dxdt[3] = gama * x[2] - miu * x[3];
}

void write_comportamiento( const state_type &x , const double t )
{
  std::cout << t << '\t' << x[0] << '\t' << x[1] << '\t' << x[2] << '\t' << x[3] << std::endl;
}

int main(int argc, char **argv)
{
    state_type x = { 2000.0 , 1.0 , 1.0 }; // initial conditions
    boost::numeric::odeint::integrate( comportamiento , x , 0.0 , 1000.0 , 0.1 , write_comportamiento );
}
