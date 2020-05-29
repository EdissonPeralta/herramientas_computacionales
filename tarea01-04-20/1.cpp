#include <iostream>
#include <cmath>

double sin_pade(double x);
double sin_aux(double u);



int main(void)
{
  std::cout.precision(16); // 16 decimal places
  std::cout.setf(std::ios::scientific); // use scientific notation
  
  
  //Llamamos la función sin_aux para poder usar senu.
  
  double u;
  sin_aux(u); 
  
  
  //////////////////////// Primer for para variar los valores de x, en este caso miramos la  de x<10^-8 /////////////////
  
  double x;
  double E;
  double pi=3.14159265;
  double dx=0.01;
  double a,b,d,e,f; 
  double error;
  double senito;
  
  
  

  
  
  ////////////////////////// Segundo for para variar los valores de u ///////////////////////////////////////////////////
  
  for (double n=0.01 ; n <= 2*pi; n += dx )//Se varía x en los valores que se desee. 
    {
      b=n/(pi*2.0);
      a=b-int(b);
      if(a<=0.5)
	{
	  a=a*2.0;
	}
      else
	{
	  a=-a*2.0;
	}
      x=a-int(a);
      
      
          
      E=sin_pade(x);
      senito=std::sin(x);
      error=std::fabs((senito-E)/senito)*100;
      
      std::cout << n << "\t" << "\t"  << error << "\n";
      
    }

  
  return 0;
}


///////////////////////// Función sin_pade que va a tener los 3 condicionales ////////////////////////////////////////////


double sin_pade(double x)
{
  
  
  double senx;
  
///////// Primer condicinal para x<10^-8 /////////
  
  if (x < std::pow(10,-8))
    {
      
      senx=x;
      
    }			
  

///////// Segundo condicinal para x>pi/6 ///////////////
  
  double w=0.52359878; /// w es el valor de pi/6 en radianes
  double u;
  
  
  if (fabs(x) > w ){
	  
	  u=x/3;
	  
	  senx = (3-4*sin_aux(u)*sin_aux(u))*sin_aux(u);
	  
  }
    
///////// Tercer condicinal para x<pi/6 ///////////////    

  
  
  if (fabs(x) <= w ){
	  
	  u=x;
	  
	  senx = sin_aux(u);
  }
    
    
	return senx;
    
    }
    
    
    
    
    
    
    
 ///////////////////// Función sin_aux que va a tener la función especial y horrible de sin u ////////////////////////////   

double sin_aux(double u)
{
  double senu=0;
 
  double A=1.0*(29593.0/207636.0);
  double B=1.0*(34911.0/7613320.0);
  double C=1.0*(479249.0/11511339840.0);
  double D=1.0*(1671.0/69212.0);
  double E=1.0*(97.0/351384.0);
  double F=1.0*(2623.0/1644477120.0);
  
  senu = u*(1.0 - (A*u*u) + (B*std::pow(u,4)) - (C*std::pow(u,6))) / (1.0 + (D*u*u) + (E*std::pow(u,4)) + (F*std::pow(u,6)));
  
  //~ std::cout<< senu << "Holis" << "\n";
  
  return senu;
	
  
  
  
  // fill here the auxiliary sin from Pade
  // return u*(1- ...)/(1+ ...);
  // use the std::pow function for u^4 and u^6
}
