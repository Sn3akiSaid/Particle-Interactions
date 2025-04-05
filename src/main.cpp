// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// See slides for guidance

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
// Nuclei
#include"nucleus.h"
#include"stablenucleus.h"
#include"radioactivenucleus.h"
// Particles
#include"particle.h"

using std::string;

// Beginning of nucleus class 
// class Nucleus
// {
// private:
//   //...
// public:
//   //...
// protected: 
//   //...

// };
// End of nucleus class and associated member functions

// Derived classes for radioactive and stable nuclei, photon and electron classes

// Note: implementation of functions from a class should be done outside the class in the cpp file

// Main program
int main()
{
  try
  {
    // Here auto is used to make objects on the heap, managed by shared_ptr's
    auto Iron = std::make_shared<StableNucleus>("Fe", 55.845, 26);
    Iron->printData();
    // Particle Electron;
  }
  catch(const std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
    return 1;
  }
}
