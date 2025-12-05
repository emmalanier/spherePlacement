///////////////////////////
//SPHERE PLACEMENT - MAIN//
///////////////////////////

#include "header.h"

int main()
{
  //VARIABLES
  double radius = 0.0;
  double surfDensity = 0.0;
  double sqrtSurfDensity = 0.0;

  double mTheta = 0.0;
  double dTheta = 0.0;
  double dPhi = 0.0;

  int n = 0; //Number of elements to be placed
  std::vector<double> coordinates;
  std::vector<pos> coordinates2;

  //PROGRAM
  getDatas(n, radius, maxIter, numberOfInc);
  computeValuesFromDatas(n, radius, surfDensity, sqrtSurfDensity, mTheta, dTheta, dPhi);
  
  coordinates = computeResults(radius, mTheta, dPhi);

  //RESULTS OUTPUT
  std::ofstream coordinatesFile("sphere_positions.txt");

  for(int i=0; i<(coordinates.size()/3); i++)
    coordinatesFile << std::setw(15) << coordinates[3*i] << " ; " << std::setw(15) << coordinates[3*i+1] << " ; " << std::setw(15) << coordinates[3*i+2] << std::endl;



  return 0;
}