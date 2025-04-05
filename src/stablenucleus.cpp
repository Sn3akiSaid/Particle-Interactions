#include"stablenucleus.h"
#include<iostream>
// Implementing constructors

  // Default constructor
  StableNucleus::StableNucleus() : Nucleus("Fe", 55.845, 26, 0.0) {}
  // Parameterized Constructor
  StableNucleus::StableNucleus(const std::string &nType, double aMassIn, int aNumberIn)
       :Nucleus(nType, aMassIn, aNumberIn, 0.0) {}
  // Copy constructor
  StableNucleus::StableNucleus(const StableNucleus& other)
  {
    std::cout << "\nCalling StableNucleus Copy Constructor." << std::endl;
  } 
  // Copy assignment
  StableNucleus& StableNucleus::operator=(const StableNucleus& other)
  {
    std::cout << "\nCalling StableNucleus Copy Assignment" << std::endl;
    if (this != &other)
    {
      Nucleus::operator=(other);
    }
    return *this;
  }

  // Move constructor
  StableNucleus::StableNucleus(StableNucleus&& other) noexcept : Nucleus(std::move(other))
  {
    std::cout << "\nCalling StableNucleus Move Constructor" << std::endl;
  }

  // Move assignment
  StableNucleus& StableNucleus::operator=(StableNucleus&& other) noexcept
  {
    std::cout << "\nCalling Stable Nucleus Move Assignment." <<std::endl;
    
    if (this != &other)
    {
      Nucleus::operator=(std::move(other));
    }
    return *this;
  }

  // Override base methods
  // Override isDecayed 
  bool StableNucleus::isDecayed() {return false;}

  // Override decay
  void StableNucleus::decay()
  {
    std::cout << "Stable Nucleus- Cannot Decay.\n" << std::endl;
  }

  // Override printData
  void StableNucleus::printData() const
  {
    std::cout << "\nStable ";
    Nucleus::printData();
  }