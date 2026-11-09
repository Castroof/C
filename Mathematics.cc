//Mathematics.cc

// System Headers:
#include <stdlib.h>

// Local Headers:
#include "Mathematics.h"

// Constructor
Mathematics::Mathematics ( )       
{
  
}

// Destructor
Mathematics::~Mathematics ( )
{
        
}

//Code of func1_1
void Mathematics::ProdVec(double C[3], double A[3], double b[3])
{
  // algorithm
  C[0] = A[1]*b[2] - A[2]*b[1];
  C[1] = A[2]*b[0] - A[0]*b[2];
  C[2] = A[0]*b[1] - A[1]*b[0];
  return;
}


//Code of func2_1
double Mathematics::Modules(double A[3])
{
  // algorithm
  double module = sqrt(A[0]*A[0] + A[1]*A[1] + A[2]*A[2]);
  return module;
}



