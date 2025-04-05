#include<iostream>
#include<random>
#include"photon.h"
#include"electron.h"

Photon::Photon(double energyIn) : Particle(0.0, energyIn)
{
  pairProduction = std::make_unique<std::vector<std::shared_ptr<Electron>>>();
}

Photon::~Photon(){}
void Photon::printData() const
{
  std::cout << "Photon: Energy = " << getEnergy() << "Mev, "
            << "Pair Production count = " << pairProduction->size()
            << std::endl;
  Particle::printData();
}
void Photon::addElectron(const std::shared_ptr<Electron>& electron)
{
  pairProduction->push_back(electron);
}