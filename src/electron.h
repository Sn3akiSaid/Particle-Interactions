#ifndef ELECTRON_H
#define ELECTRON_H
#include"particle.h"
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<cmath>
#include<initializer_list>

class Photon;

class Electron : public Particle
{
	private:
	int charge;
	// double restMass = 0.511;
	std::unique_ptr<std::vector<std::shared_ptr<Photon>>> radiation;

	public:
	Electron(double eMass = 0.511, double energyIn = 0.0, int eCharge = -1);
	~Electron() override; //{std::cout<<"Electron destruction"<<std::endl;}

	int getCharge() const {return charge;}
	double setCharge(int eCharge) {return charge = eCharge;}


	void print_data() const override;
	void addPhoton(const std::shared_ptr<Photon>& photon);
};

Electron::Electron(double massIn, double energyIn, int chargeIn) : 
									 Particle(massIn, energyIn), charge(chargeIn)
{
	radiation = std::make_unique<std::vector<std::shared_ptr<Photon>>>();
}

Electron::~Electron()
{
	std::cout << "Electron destruction" << std::endl;
}

void Electron::addPhoton(const std::shared_ptr<Photon>& photon)
{
	radiation->push_back(photon);
}

#endif