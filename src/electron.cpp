#include<iostream>
#include<random>
#include"electron.h"
#include"photon.h"

Electron::Electron(double massIn, double energyIn, int eChargeIn) 
	: Particle(massIn, energyIn), charge(eChargeIn) 
{
	radiation = std::make_unique<std::vector<std::shared_ptr<Photon>>>();
	radiationEnergy = energyIn * 0.01;
}

Electron::~Electron(){}

void Electron::printData() const
{
	std::cout << "Electron rest mass = " << getRestMass() 
						<< " MeV | Energy = " <<getEnergy() 
						<< " | Radiation counts = " << radiation->size() << std::endl;
						
	Particle::printData();
}
void Electron::addPhoton(const std::shared_ptr<Photon>& photon)
{
	radiation->push_back(photon);
}

int Electron::getCharge() const {return charge;}

void Electron::setCharge(int eChargeIn) {charge = eChargeIn;}

std::vector<std::shared_ptr<Photon>>& Electron::getRadiation() {return *radiation;}
