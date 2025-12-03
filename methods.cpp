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

/*std::vector <double> defineSmallAngles(double& dCircumference, double& phase)
{
  std::vector <double> results; //1D vector containing two elements : dtheta at index 0, dphi at index 1

  results.push_back(

  return results;
}*/

double distanceOnTheSurface(const pos& pos1, const pos& pos2, const double& radius)
{
  double results =0.0;
  
  double side = 0.0;
  double dx = pos1.x - pos2.x;
  double dy = pos1.y - pos2.y;
  double dz = pos1.z - pos2.z;
  double alpha = 0.0;

  side = sqrt(dx*dx + dy*dy + dz*dz);

  alpha = atan(side/radius);

  results = ((M_PI*2.0*radius)/360.0)*alpha;
  
  return results;
}

std::vector <double> smallDeplacement(double lambda, const double& radius)
{
  std::vector <double> results; //1D vector containing 3 elements : X, Y and Z deplacements
  double randTheta = ((2.0*(1.0*rand()/RAND_MAX)) - 1.0)*360.0*lambda ;
  double randPhi = ((2.0*(1.0*rand()/RAND_MAX)) - 1.0)*360.0*lambda ;

  double dx = radius*sin(randTheta)*cos(randPhi);
  double dy = radius*sin(randTheta)*sin(randPhi) ;
  double dz = radius*cos(randTheta);

  results.push_back(dx);
  results.push_back(dy);
  results.push_back(dz);

  return results;
}

std::vector <pos> newRandomPositions(const int& nElements, const int& maxIter, const int& numberOfInc, const double& radius, const std::vector <pos>& vec)
{
  std::vector <pos> results = vec;
  int iterPerInc = rint(maxIter/numberOfInc);

  for(int i=1; i<=numberOfInc; i++)
    {
      for(int j=1; j<=iterPerInc; j++)
        {
          for(int k=0; k<vec.size(); k++)
            {
              std::vector <double> dep = smallDeplacement(i*1.0, radius);
              results[k].x += dep[0];
              results[k].y += dep[1];
              results[k].z += dep[2];
            }
        }
    }

  return results;
}

bool compareVectors(const std::vector <pos>& oldVec, const std::vector <pos>& newVec, const double& radius)
{
  bool result = false;

  if((oldVec.size()/3)%2 == 0)
    {
      double sumOldVec = 0.0;
      double sumNewVec = 0.0;
      
      for(int i=0; i<(oldVec.size()/2); i++)
        {
          sumOldVec += pow(-1, i)*distanceOnTheSurface(oldVec[i*2], oldVec[1+i*2], radius);
        }

      for(int i=0; i<(newVec.size()/2); i++)
        {
          sumNewVec += pow(-1, i)*distanceOnTheSurface(newVec[i*2], newVec[1+i*2], radius);
        }

      if(sumNewVec < sumOldVec)
        result = true ;
    }

    else if((oldVec.size()/3)%2 != 0)
    {
      double sumOldVec = 0.0;
      double sumNewVec = 0.0;
      
      for(int i=0; i<((oldVec.size()-1)/2); i++)
        {
          sumOldVec += pow(-1, i)*distanceOnTheSurface(oldVec[i*2], oldVec[1+i*2], radius);
        }
      sumOldVec -= distanceOnTheSurface(oldVec[oldVec.size()-2], oldVec[oldVec.size()-1], radius);

      for(int i=0; i<((newVec.size()-1)/2); i++)
        {
          sumNewVec += pow(-1, i)*distanceOnTheSurface(newVec[i*2], newVec[1+i*2], radius);
        }
      sumNewVec -= distanceOnTheSurface(newVec[newVec.size()-2], newVec[newVec.size()-2], radius);

      if(sumNewVec < sumOldVec)
        result = true ;
    }

  return result;
}

std::vector <pos> getNewVector(const bool& b, const std::vector <pos>& oldVec, const std::vector <pos>& newVec)
{
  std::vector <pos> results;

  if(b==true)
    results = newVec;

  else
    results = oldVec;

  return results;
}