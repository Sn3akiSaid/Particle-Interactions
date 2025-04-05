#include<iostream>
#include<random>
#include"electron.h"
#include"photon.h"

Electron::Electron(double massIn, double energyIn) : 
									 Particle(massIn, energyIn)//, charge(chargeIn)
{
	radiation = std::make_unique<std::vector<std::shared_ptr<Photon>>>();
	radiationEnergy = energyIn * 0.01;
}

Electron::~Electron()
{
	std::cout << "Electron destruction" << std::endl;
}

void Electron::printData() const
{
	std::cout << "Electron rest mass" << getRestMass() << " MeV, Energy = " <<getEnergy() << "radiation = " << radiation->size() <<std::endl;
	Particle::printData();
}
void Electron::addPhoton(const std::shared_ptr<Photon>& photon)
{
	radiation->push_back(photon);
}

std::vector<std::shared_ptr<Photon>>& Electron::getRadiation() {return *radiation;}
