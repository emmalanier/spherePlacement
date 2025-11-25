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
  std::vector<double> coordinates;

  getDatas(n, radius);
  computeValuesFromDatas(n, radius, surfDensity, sqrtSurfDensity, mTheta, dTheta, dPhi);
  
  coordinates = computeResults(radius, mTheta, dPhi);

  std::ofstream coordinatesFile("sphere_positions.txt");

  for(int i=0; i<(results.size()/3); i++)
    coordinatesFile << setw(15) << results[3*i] << " ; " << results[3*i+1] << " ; " << results[3*i+2] << std::endl;

  return 0;
}