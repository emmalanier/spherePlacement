/////////////////////////////
//SPHERE PLACEMENT - HEADER//
/////////////////////////////

#ifndef HEADER_H
#define HEADER_H

////////////
//INCLUDES//
////////////

#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <ctime>

//STRUCTURES//
struct pos
{
  double x;
  double y;
  double z;
};

double distanceOnTheSurface(const pos&, const pos&, const double &);

//INPUTS//

void getDatas(int&, double&);


//1ST PROGRAM//

void computeValuesFromDatas(const int&, const double&, double&, double&, double&, double&, double&);

double placeX(double&, double&, double&);
double placeY(double&, double&, double&);
double placeZ(double&, double&);

std::vector <double> computeResults(double&, double&, double&);


//2ND PROGRAM : MINIMISATION//

//std::vector <double> defineSmallAngles();
std::vector <double> smallDeplacement(double, const double&);
std::vector <pos> newRandomPositions(const int&, const int&, const int&, const double&, const std::vector <pos>&);

bool compareVectors(const std::vector <pos>&, const std::vector <pos>&);

std::vector <pos> getNewVector(const bool&, const std::vector <pos>&, const std::vector <pos>&);

#endif//HEADER_H