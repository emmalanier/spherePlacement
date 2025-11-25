//////////////////////////////
//SPHERE PLACEMENT - METHODS//
//////////////////////////////

#include "header.h"

void getDatas(int& n, double& r)
{
  std::cout << "Number of elements to place ? " << std::endl;
  std::cin >> n;

  std::cout << "Desired sphere radius ? " << std::endl;
  std::cin >> r;
}

void computeValuesFromDatas(const int& n, const double& r, double& a, double& d, double& mT, double& dTheta, double& dPhi)
{
  a = (4.0*M_PI*r*r)/(1.0*n) ;
  d = sqrt(a);
  mT = M_PI/d ;
  dTheta = M_PI/mT;
  dPhi = a/dTheta;
}