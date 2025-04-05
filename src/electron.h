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

// Forward declarations
class Photon;
class Electron;

// Function simulating pair production radiation
std::shared_ptr<Photon> radiate(const std::shared_ptr<Electron>& electron);

class Electron : public Particle
{
	private:
	int charge;
	double radiationEnergy;
	std::unique_ptr<std::vector<std::shared_ptr<Photon>>> radiation;

	public:
	// Constructor
	// Creates electron with restmass from constants namespace
	Electron(double eMass = electronMass, double energyIn = 0.0, int eCharge = -1);

	// Virtual destructor
	~Electron() override; 

	// Getter and setter for the charge
	int getCharge() const;
	void setCharge(int eCharge);

	void printData() const override;
	void addPhoton(const std::shared_ptr<Photon>& photon);

	std::vector<std::shared_ptr<Photon>>& getRadiation();

	// Friend function for accesss to private radiate member
	friend std::shared_ptr<Photon> radiate(const std::shared_ptr<Electron>& electron);
};

#endif