// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// See slides for guidance

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"nucleus.h"
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
    Nucleus test("Co", 60, 27, 5.272);
    test.print_data();
    return 0;
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}
