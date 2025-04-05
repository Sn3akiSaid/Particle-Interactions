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
              << " || Lambda: " << lambda
              << " || Decay Status: " << (decayed ? "Yes" : "No") << std::endl;

    if (decayed && emittedPhoton)
    {
      std::cout << "Emitted Photon Info: " << std::endl;
      emittedPhoton->printData(); 
    }
  }

  // Copy Constructor
  Nucleus::Nucleus(const Nucleus& other) :
           nucleusType(other.nucleusType),
           atomicMass(other.atomicMass),
           atomicNumber(other.atomicNumber),
           lambda(other.lambda),
           decayed(other.decayed),
           emittedPhoton(other.emittedPhoton)
           {
            std::cout << "Calling Nucleus Copy Constructor" << std::endl;
           }
  // Copy Assigment
  Nucleus& Nucleus::operator=(const Nucleus& other)
  {
    std::cout << "Calling Nucleus Copy Assignment" << std::endl;
    if (this != &other)
    {
      nucleusType = other.nucleusType;
      atomicMass = other.atomicMass;
      atomicNumber = other.atomicNumber;
      lambda = other.lambda;
      decayed = other.decayed;
      emittedPhoton = other.emittedPhoton;
    }
    return *this;
  }
  // Move Constructor
  Nucleus::Nucleus(Nucleus&& other) noexcept :
           nucleusType(std::move(other.nucleusType)),
           atomicMass(other.atomicMass),
           atomicNumber(other.atomicNumber),
           lambda(other.lambda),
           decayed(other.decayed),
           emittedPhoton(std::move(other.emittedPhoton))
           {
            std::cout << "Calling Nucleus Move Constructor" << std::endl;
            // Resetting moved-from object
            other.atomicMass = 0.0;
            other.atomicNumber = 0;
            other.lambda = 0.0;
            other.decayed = false;
           }
  // Move Assignment
  Nucleus& Nucleus::operator=(Nucleus&& other) noexcept
  {
    std::cout << "Calling Nucleus Move Assignment" << std::endl;
    if (this != &other)
    {
      nucleusType = std::move(other.nucleusType);
      atomicMass = other.atomicMass;
      atomicNumber = other.atomicNumber;
      lambda = other.lambda;
      decayed = other.decayed;
      emittedPhoton = std::move(other.emittedPhoton);

      other.atomicMass = 0.0;
      other.atomicNumber = 0;
      other.lambda = 0.0;
      other.decayed = false;
      
    }
    return *this;
  }

