//////////////////////////////
//SPHERE PLACEMENT - METHODS//
//////////////////////////////

#include "header.h"

//////////
//INPUTS//
//////////

void getDatas(int& n, double& r)
{
  std::cout << "Number of elements to place ? " << std::endl;
  std::cin >> n;

  std::cout << "Desired sphere radius ? " << std::endl;
  std::cin >> r;
}


//////////////////////////
//FIRST PROGRAMM METHODS//
//////////////////////////

void computeValuesFromDatas(const int& n, const double& r, double& a, double& d, double& mT, double& dTheta, double& dPhi)
{
  a = (4.0*M_PI*r*r)/(1.0*n) ;
  d = sqrt(a);
  mT = round(M_PI/d) ;
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

  for(int i=0; i<rint(mTheta); i++)
    {
      theta = (M_PI*(i+0.5))/mTheta;
      mPhi = round((2.0*M_PI*sin(theta))/dPhi);

      for(int j=0; j < rint(mPhi); j++)
        {
          phi = (2.0*M_PI*j)/mPhi;
          results.push_back(placeX(theta, phi, r));
          results.push_back(placeY(theta, phi, r));
          results.push_back(placeZ(theta, r));
        }
      }
      

  return results;
}


//////////////////////////////////////
//2ND PROGRAM (MINIMISATION) METHODS//
//////////////////////////////////////

std::vector <double> defineSmallAngles(double& dCircumference, double& phase)
{
  std::vector <double> results; //1D vector containing two elements : dtheta at index 0, dphi at index 1

  results.push_back(

  return results;
}

std::vector <double> smallDeplacement()
{
  std::vector <double> results;

  return results;
}

std::vector <double> newRandomPositions()
{
  std::vector <double> results;

  return results;
}

bool compareVectors()
{
  bool result;

  return result;
}

std::vector <double> getNewVector()
{
  std::vector <double> results;

  return results;
}