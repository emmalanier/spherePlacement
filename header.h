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

//INPUTS//

void getDatas(int&, double&);


//1ST PROGRAM//

void computeValuesFromDatas(const int&, const double&, double&, double&, double&, double&, double&);

double placeX(double&, double&, const double&);
double placeY(double&, double&, const double&);
double placeZ(double&, const double&);

std::vector <double> computeResults(double&, double&, double&);

#endif//HEADER_H