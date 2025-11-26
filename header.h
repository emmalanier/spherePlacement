/////////////////////////////
//SPHERE PLACEMENT - HEADER//
/////////////////////////////

#ifndef HEADER_H
#define HEADER_H

//INCLUDES//
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iomanip>

void getDatas(int&, double&);
void computeValuesFromDatas(const int&, const double&, double&, double&, double&, double&, double&);
double placeX(double&, double&, double&);
double placeY(double&, double&, double&);
double placeZ(double&, double&);
std::vector <double> computeResults(double&, double&, double&);

#endif//HEADER_H