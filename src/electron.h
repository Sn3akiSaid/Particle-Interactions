#ifndef ELECTRON_H
#define ELECTRON_H
#include"particle.h"
#include"constants.h"
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<cmath>
#include<initializer_list>

using namespace Constants;

class Photon;
class Electron;

std::shared_ptr<Photon> radiate(const std::shared_ptr<Electron>& electron);

class Electron : public Particle
{
	private:
	int charge;
	double radiationEnergy;
	std::unique_ptr<std::vector<std::shared_ptr<Photon>>> radiation;

	public:
	Electron(double eMass = electronMass, double energyIn = 0.0, int eCharge = -1);
	~Electron() override; 

	int getCharge() const;
	void setCharge(int eCharge);

	void printData() const override;
	void addPhoton(const std::shared_ptr<Photon>& photon);

	std::vector<std::shared_ptr<Photon>>& getRadiation();

	friend std::shared_ptr<Photon> radiate(const std::shared_ptr<Electron>& electron);
};

#endif