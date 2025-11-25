///////////////////////////
//SPHERE PLACEMENT - MAIN//
///////////////////////////

#include "header.h"

int main()
{
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;

  double theta = 0.0;
  double phi = 0.0;

  double radius = 0.0;
  double surfDensity = 0.0;
  double sqrtSurfDensity = 0.0;

  double mTheta = 0.0;
  double dTheta = 0.0;
  double dPhi = 0.0;

  int n = 0; //Number of elements to be placed
  std::vector<double> coordinates [n*3] = 0.0;

  getDatas(n, radius);
  computeValuesFromDatas(n, radius, surfDensity, sqrtSurfDensity, mTheta, dTheta, dPhi);
  

  return 0;
}