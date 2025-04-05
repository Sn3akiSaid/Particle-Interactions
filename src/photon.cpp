#include<iostream>
#include<random>
#include"photon.h"
#include"electron.h"

// Constructor creating photon as particle with 0 rest mass
// Initializes vector tracking pair production
Photon::Photon(double energyIn) : Particle(0.0, energyIn)
{
  pairProduction = std::make_unique<std::vector<std::shared_ptr<Electron>>>();
}

// Destructor
Photon::~Photon(){}

// Display photon energy and pair production informations
void Photon::printData() const
{
  std::cout << "photon with E = " << getEnergy() << " MeV"
            << " | Pair Production count = " << pairProduction->size()
            << std::endl;
  Particle::printData();
}

// Add electron to pair production
// Use to track electrons created by pair productions
void Photon::addElectron(const std::shared_ptr<Electron>& electron)
{
  pairProduction->push_back(electron);
}