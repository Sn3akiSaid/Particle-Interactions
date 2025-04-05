#include"nucleus.h"
#include"photon.h"
#include<iostream>
#include<utility>
#include<stdexcept>

  bool Nucleus::isValidNucleus(const std::string& nType) const
  {
    return nucleusType.find("Fe") != std::string::npos || 
           nucleusType.find("Co") != std::string::npos ||
           nucleusType.find("Cs") != std::string::npos ||
           nucleusType.find("Na") != std::string::npos;
  }

  // Nucleus::Nucleus() : nucleusType{"none"}, atomicMass{}, atomicNumber{}{} 

  // The parameterised constructor dynamically allocates the std::vector containing the four-vector elements
  Nucleus::Nucleus(const std::string &nType, double aMassIn, int aNumIn, double lambdaIn) :
  nucleusType{nType}, atomicMass{aMassIn}, atomicNumber{aNumIn}, lambda{lambdaIn}
  {
  // The parameterised constructor checks the validity of the energy component
    if (atomicMass < 0) 
    {
      throw std::invalid_argument("Atomic mass cannot be negative.");
    }
    if (atomicNumber < 1 || atomicNumber > 118) // Checks if the atomic number is a valid one according to the periodic table
    {
      throw std::invalid_argument("Atomic number must be within the range of atomic numbers of the periodic table.");
    }
    if (!nType.empty() && nType != "none" && !isValidNucleus(nType))
    {
      throw std::invalid_argument("Invalid Nucleus name used.");
    }
  }

  bool Nucleus::isDecayed() {return decayed;}
  void Nucleus::decay()
  {
    std::cout << "Base nucleus decay method called" << std::endl;
  }

  void Nucleus::printData() const
  {
    std::cout << "Nucleus: " << nucleusType 
    << " || Atomic Mass: " << atomicMass 
    << " || Atomic Number: " << atomicNumber 
    << " || Lambda:" << lambda
    << " || Decay Status: " << (decayed ? "Yes" : "No") << std::endl;

    if (decayed && emittedPhoton)
    {
      std::cout << "Emitted Photon Info: " << std::endl;
      emittedPhoton->printData(); 
    }
  }

  // bool Nucleus::getDecayStatus() const {return decayed;}
  // std::shared_ptr<Photon> Nucleus::getEmittedPhoton() const {return emittedPhoton;}
  // void Nucleus::setDecayed(bool hasDecayed) {decayed = hasDecayed;}
  // void Nucleus::setEmittedPhoton(const std::shared_ptr<Photon>& photon)
  // {
  //   emittedPhoton = photon;
  // }