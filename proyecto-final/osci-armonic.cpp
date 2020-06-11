#include <iostream>
#include <array>

#include <boost/numeric/odeint.hpp>

const double W = 3.47;
const double b = 0.8;

typedef std::array< double , 2 > state_type;

void ho( const state_type &x , state_type &dxdt , double t );
void write_ho( const state_type &x , const double t );



int main(int argc, char **argv)
{
    state_type x = { 1.23 , 0.0}; // initial conditions
    boost::numeric::odeint::integrate( ho , x , 0.0 , 20.0 , 0.1 , write_ho );
}

void ho( const state_type &x , state_type &dxdt , double t )
{
    dxdt[0] = x[1];
    dxdt[1] = -W*W*x[0] - b*x[1];
}

void write_ho( const state_type &x , const double t )
{
    std::cout << t << '\t' << x[0] << '\t' << x[1] << std::endl;
}
