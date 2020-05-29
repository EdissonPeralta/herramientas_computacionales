#include <iostream>

/*
  Este programa simula un cuerpo que cae bajo accion de la gravedad y en el
  futuro va a rebotar contra el suelo y contra otros cuerpos.
*/

/*
  Cuerpo: 
  - masa (densidad)
  - (forma: esfera)
  - r[3], v[3], F[3]
  
  Condiciones externas
  - Gravedad
  
  Funciones
  - initial_conditions

  - timestep (nueva posicion y nueva velocidad)
  - start_timeintegration()
  - compute_force()
    - (implementar la fuerza de Hertz)
    - (Fuerza del rebote)
    - *(Fuerza de gravedad)
    - (Amortiguamiento)
    - (Fuerza de fricción, si es que se considera)
  - print_system
  
  - Visualization
*/

int main(void)
{
  return 0;
}
