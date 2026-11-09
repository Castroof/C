// System Headers
//#include <iostream.h>
//#include <strstream.h>
#include <math.h>

class Physics
{
 private:
  //double ;
  double F[3], q, v[3], B[3];
  double V[3], vo[3], a[3], r[3], ro[3], t;
  
 public:
  //! Constructor of the class.
  Physics ( );

  //! Destructor of the class.
  ~Physics ( );

  //declaration of the method Physics
  void FLorentz(double F[3], double q, double v[3], double B[3]);

  //declaration of the method Physics
  void varloop(double V[3], double vo[3], double a[3], double r[3], double ro[3], double t);
};









