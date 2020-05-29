#include <iostream>
#include <vector>

/*
  Este programa simula un cuerpo que cae bajo accion de la gravedad y en el
  futuro va a rebotar contra el suelo y contra otros cuerpos.
*/

// cuerpo
struct body {
  double masa;
  double r[3], v[3], f[3];
};

// simulation conditions
const int N = 1;
const double G = 9.81;
const double DT = 0.1;

// helper function
void initial_conditions(std::vector<body> & bodies);
void timestep(std::vector<body> & bodies, double dt);
void start_timeintegration(std::vector<body> & bodies, double dt);
void compute_force(std::vector<body> & bodies);
void print_system(const std::vector<body> & bodies, double time);


int main(void)
{
  std::vector<body> bodies(N);

  return 0;
}
