// System Headers
//#include <iostream.h>
//#include <strstream.h>
#include <math.h>

class Mathematics
{
 private:
 	float a,d,c;
  	double A[3], b[3], C[3];
    
 public:
	#define pi 3.141592654
	#define rad2deg (180./pi)

  //! Constructor of the class.
  Mathematics ( );

  //! Destructor of the class.
  ~Mathematics ( );

  //Declaration of the method Mathematics
  void ProdVec(double C[3], double A[3], double b[3]);

  //Declaration of the method Mathematics
  double Modules(double A[3]);
};








