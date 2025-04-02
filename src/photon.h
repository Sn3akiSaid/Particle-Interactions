#ifndef PHOTON_H
#define PHOTON_H
#include"particle.h"
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<cmath>
#include<initializer_list>

// Forward declaration
class Electron; //Photon references electron and vice versa

class Photon : public Particle
{
private:
  std::unique_ptr<std::vector<std::shared_ptr<Electron>>> pairProduction; // shared allows multiple objects sharing ownership, prevents circular ownership

public:
  Photon(double energyIn = 0.0);
  ~Photon() override;

  void print_data() const override;
  void addElectron(const std::shared_ptr<Electron>& electronIn);
};

Photon::Photon(double energyIn) : Particle(0.0,energy)
{
  pairProduction = std::make_unique<std::vector<std::shared_ptr<Electron>>>();
}
Photon::~Photon()
{
  std::cout << "Photon Destruction" << std::endl;
}

void Photon::print_data() const
{
  std::cout << "Photon: Energy = " << getEnergy() << "Pair Production count="
            << pairProduction->size() << std::endl;
  Particle::print_data();
}

void Photon::addElectron(const std::shared_ptr<Electron>& electron)
{
  pairProduction->push_back(electron);
}

#endif