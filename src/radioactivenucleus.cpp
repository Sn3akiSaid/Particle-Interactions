#include"radioactivenucleus.h"
#include<random>

  // Default Constructor
  RadioactiveNucleus::RadioactiveNucleus() 
    : Nucleus("Cs", 137.0, 55, 0.023), halfLife(30.17)
    {
      photonEnergies.push_back(0.661);
    }

  // Parameterized Constructor
  RadioactiveNucleus::RadioactiveNucleus(const std::string &nType, double aMassIn, int aNumberIn, double halfLifeIn)
    : Nucleus(nType, aMassIn, aNumberIn, std::log(2)/halfLifeIn), halfLife(halfLifeIn)
    {
      // Here for each decay case the respective photon energy is 
      // added into the vector of emitted photon energies.
      if (nType == "Cs")
      {
        // Cs Decay --> Photon emission with energy 661 keV = 0.661 MeV
        photonEnergies.push_back(0.661);
      }
      else if (nType == "Na")
      {
        // Na Decay --> Photon emission with energy 1274.5 keV = 1.2745 MeV
        photonEnergies.push_back(1.2745);
      }
      else if (nType == "Co")
      {
        // Co Decay --> Emission of 2 Photons with energies
        // 1173 keV = 1.173 MeV and 1333 keV = 1.333 MeV
        photonEnergies.push_back(1.173);
        photonEnergies.push_back(1.333);
      }
    }
  // Copy Constructor
  RadioactiveNucleus::RadioactiveNucleus(const RadioactiveNucleus& other)
    : Nucleus(other), halfLife(other.halfLife), photonEnergies(other.photonEnergies)
    {
      std::cout << "\nCalling Radioactive Nucleus Copy Constructor." << std::endl;
    }

  // Copy Assignment 
  RadioactiveNucleus& RadioactiveNucleus::operator=(const RadioactiveNucleus& other)
  {
    std::cout << "\nCalling Radioactive Nucleus Copy Assignment." << std::endl;
    if (this != &other)
    {
      Nucleus::operator=(other);
      halfLife = other.halfLife;
      photonEnergies = other.photonEnergies;
    }
    return *this;
  }

  // Move Constructor
  RadioactiveNucleus::RadioactiveNucleus(RadioactiveNucleus&& other) noexcept
    : Nucleus(std::move(other)), halfLife(other.halfLife),
      photonEnergies(std::move(other.photonEnergies))
    {
      std::cout << "\nCalling Radioactive Nucleus Move Constructor." << std::endl;
      other.halfLife = 0.0;
    }
  
  // Move Assignment
  RadioactiveNucleus& RadioactiveNucleus::operator=(RadioactiveNucleus&& other) noexcept
  {
    std::cout << "\nCalling Radioactive Nucleus Move Assignment Operator." << std::endl;
    if (this != &other)
    {
      Nucleus::operator=(std::move(other));
      halfLife = other.halfLife;
      photonEnergies = std::move(other.photonEnergies);
      other.halfLife = 0.0;
    }
    return *this;
  }

  // Destructor
  RadioactiveNucleus::~RadioactiveNucleus() = default;

  // Add energy vvalue to photon emissions
  void RadioactiveNucleus::addPhotonEnergy(double energy)
  {
    photonEnergies.push_back(energy);
  }

  // Return decay status
  bool RadioactiveNucleus::isDecayed()
  {
    return getDecayStatus();
  }

  // Simulate radioactive decay
  // Emits photons with specific energies
  void RadioactiveNucleus::decay()
  {
    // Check if decayed
    if (isDecayed())
    {
      std::cout << getType() << " Nucleus has already decayed." << std::endl;
      return; 
    }

    // Check if energies are defined
    if (photonEnergies.empty())
    {
      std::cout << "No photon energies defined for " << getType() << std::endl;
      return;
    }

    // Set decay to true
    setDecayed(true);

    // Emit photons with energies from list
    for (const auto& energy : photonEnergies)
    {
      auto photon = std::make_shared<Photon>(energy);
      setEmittedPhoton(photon);
      std::cout << "Nucleus " << getType() << " has decayed, emitting ";
      
      if (photon)
      {
        photon->printData();
      }
    }
  }

  // Display radioactive nucleus data
  void RadioactiveNucleus::printData() const
  {
    std::cout << "\nRadioactive ";
    Nucleus::printData();
    std::cout << "\nHalf-Life:" << halfLife << " years" << std::endl;

    std::cout << "Photon energies: ";
    for (size_t i = 0; i < photonEnergies.size(); ++i)
    {
      std::cout << photonEnergies[i] << " MeV";
      if(i < photonEnergies.size() - 1)
      {
        std::cout << ", ";
      }
    }
    std::cout << std::endl;
  }