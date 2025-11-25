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
  mT = rint(M_PI/d) ;
  dTheta = M_PI/mT;
  dPhi = a/dTheta;
}

double placeX(double& theta, double& phi, double& r)
{
  double results;
  results = r*sin(theta)*cos(phi);
  return results;
}

double placeY(double& theta, double& phi, double& r)
{
  double results;
  results = r*sin(theta)*sin(phi);
  return results;
}

double placeZ(double& theta, double& r)
{
  double results;
  results = r*cos(theta);
  return results;
}

std::vector <double> computeResults(double& r, double& mTheta, double& dPhi)
{
  std::vector <double> results;
  double mPhi = 0.0;
  double theta = 0.0;
  double phi = 0.0;

  for(int i=0; i<mTheta; i++)
    {
      theta = (M_PI*(i+0.5))/mTheta;
      mPhi = rint((2.0*M_PI*sin(theta))/dPhi);

      for(int j=0; j < mPhi; j++)
        {
          phi = (2.0*M_PI*j)/mPhi;
          results.push_back(placeX(theta, phi, r));
          results.push_back(placeY(theta, phi, r));
          results.push_back(placeZ(theta, r));
        }
      }
      

  return results;
}