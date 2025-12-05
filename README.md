# spherePlacement
---

## Aim of the pogram


After trying to minimize the energy of an atom cluster in 2D plan, I decided to try a spherical starting configuration. 
However, as of now, no method allows us place N equidistant points on the surface of the sphere.

This program based, on the paper "How to generate equidistributed points on the surface of a sphere" written by Markus 
Deserno (see proper reference below in **References**), tries to solve this problem.
As mentioned in the paper, the results are approximate; still, after a few tries with different N values, the program
seems to provide accurate results, which can be really helpful if small error margins are tolerated (see **Results** 
section).


## Getting started


This project was built on a Linux OS. For other OS, I don't have the necessary knowledge to help with installation ;
therefore, any help with completing this README is welcome.
However, it should be kept in mind that the aim of this project is not to just place equidistant points on the 
surface of a sphere, but rather to provide an example of how this can be done in C++, so that it can be done for other,
larger projects.


### Prerequisites

**A C++ compiler** : may vary depending on your OS. On Linux, I used GCC.
**Gnuplot _(optional, recommended for visualisation)_** : the results produced by this program are stored in a text
file; however, for those who want to check them visually, a Gnuplot script is included.
Gnuplot can be installed using the following commands : 

* Linux : `sudo apt install gnuplot`

* macOs : `brew install gnuplot`

* Windows : `choco install gnuplot`


### Build system

The executable is made using a makefile, which may need some adaptation if the executable is created on a 
Windows/macOS OS.


## Summary of the code


### General things

#### Inputs-related methods

**getDatas** allows the user to enter desired parameters (radius and number of elements to place) by interacting with 
the console.

**computeValuesFromDatas** computes the values of variables that won't be changed later on in the program, but that
depend of the chosen parameters.

#### Placement methods

**placeX/Y/Z** simply converts polar coordinates into cartesian coordinates.

**computeResults** is the core method of the program. The output is a 1D vector, whose size is approx. (see "Outputs" 
section) three times the number of elements the user asked to place. It takes 3 fixed parameters, and creates three
other ones (mPhi, theta and phi) whose values will change based on the number of the iterations at which it is
calculated. The first loop allows to compute the value of the theta angle, and the value of mPhi, which will later be
used to compute the value of the phi angle. The second loop (nested in the first one), computes the phi angle, and 
places an element according to the current values of theta and phi.

### Inputs

There are two inputs : the radius and the number of elements the user wants to place on the sphere.

For the **radius**, it is STRONGLY recommanded to set it at 1.0 . Not doing so will result in the program placing 
either a lot more or a lot less elements than the user required. If for some reason you need your sphere to have a 
bigger radius, upcoming additions to the current code will allow it. For now however, it is not handled.

### Outputs

## Results

## References

## Coming soon