#include<iostream>
#include<random>
#include"electron.h"
#include"photon.h"

// Constructor creates electron and initializes radiation vector
Electron::Electron(double massIn, double energyIn, int eChargeIn) 
	: Particle(massIn, energyIn), charge(eChargeIn) 
{
	radiation = std::make_unique<std::vector<std::shared_ptr<Photon>>>();
	radiationEnergy = energyIn * 0.01; // Set energy to 1% of total energy
}

// Destructor
Electron::~Electron(){}

// Display electron properties and radiation info
void Electron::printData() const
{
	std::cout << "Electron rest mass = " << getRestMass() 
						<< " MeV | Energy = " <<getEnergy() 
						<< " | Radiation counts = " << radiation->size() << std::endl;
						
	Particle::printData();
}

// Add photon to radiation list for tracking Bremsstrahlung Radiation
void Electron::addPhoton(const std::shared_ptr<Photon>& photon)
{
	radiation->push_back(photon);
}

// Getter for electron charge (-1 or +1 for electron/ positron)
int Electron::getCharge() const {return charge;}

// Setter electron charge
void Electron::setCharge(int eChargeIn) {charge = eChargeIn;}

// Return reference to radiation vector
std::vector<std::shared_ptr<Photon>>& Electron::getRadiation() {return *radiation;}
