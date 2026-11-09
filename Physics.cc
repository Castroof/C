//Physics.cc

// System Headers:
#include <stdlib.h>

// Local Headers:
#include "Physics.h"
#include "Mathematics.h"

Mathematics * Math = new Mathematics();

// Constructor
Physics::Physics ( )       
{

}

// Destructor
Physics::~Physics ( )
{
        
}

//Codigo da func1_2
void Physics::FLorentz(double F[3], double q, double v[3], double B[3])
{
  // algorithm
  Math -> ProdVec(F,v,B);
  for (int i = 0; i < 3; i++) F[i] = q * F[i];
  return;
}


//Code of func2_2
void Physics::varloop(double V[3], double vo[3], double a[3], double r[3], double ro[3], double t)
{
  // algorithm
  for (int j = 0; j < 3; j++)
  {
  	V[j] = vo[j] + a[j]*t;
    r[j] = ro[j] + vo[j]*t + 0.5*a[j]*(t*t);
  }
  return ;
}



