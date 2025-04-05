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
class Electron;

std::shared_ptr<Photon> radiate(const std::shared_ptr<Electron>& electron);

class Electron : public Particle
{
	private:
	double radiationEnergy;
	std::unique_ptr<std::vector<std::shared_ptr<Photon>>> radiation;

	public:
	Electron(double eMass = 0.511, double energyIn = 0.0);
	~Electron() override; 



	void printData() const override;
	void addPhoton(const std::shared_ptr<Photon>& photon);

	std::vector<std::shared_ptr<Photon>>& getRadiation();

	friend std::shared_ptr<Photon> radiate(const std::shared_ptr<Electron>& electron);
};

#endif