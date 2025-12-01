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


//INPUTS//

void getDatas(int&, double&);


//1ST PROGRAM//

void computeValuesFromDatas(const int&, const double&, double&, double&, double&, double&, double&);

double placeX(double&, double&, double&);
double placeY(double&, double&, double&);
double placeZ(double&, double&);

std::vector <double> computeResults(double&, double&, double&);


//2ND PROGRAM : MINIMISATION//

std::vector <double> defineSmallAngles();
void smallDeplacement();
std::vector <double> newRandomPositions();

bool compareVectors();

std::vector <double> getNewVector();

#endif//HEADER_H