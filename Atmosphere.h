// System Headers
#include <math.h>

class Atmosphere
{
 private:
  //double ;    
 double atm_alt[1481],atm_temp[1481],atm_press[1481],atm_dens[1481];
 public:
  // Constructor of the class.

  Atmosphere();
  // Destructor of the class.
  ~Atmosphere();

  //Declaration of the methods
  double Init(double atm_alt[1481],double atm_temp[1481],double atm_press[1481],double atm_dens[1481]);
  double GetLevelIndexes(int& low_i, int& up_i, double atm_alt[1481], double alt);
  double GetAltitude(int i, double atm_alt[1481]);
  double GetTemperature(int i, double atm_temp[1481]);
  double GetPressure(int i, double atm_press[1481]);
  double GetDensity(int i, double atm_dens[1481]);
  double GetDepth(double& depth, double alt);
};





