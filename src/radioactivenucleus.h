#ifndef RADIOACTIVENUCLEUS_H
#define RADIOACTIVENUCLEUS_H
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<cmath>
#include<initializer_list>
#include"nucleus.h"
#include"photon.h"

class RadioactiveNucleus : public Nucleus
{
private:
 double halfLife;
 std::vector<double> photonEnergies;
public:
  RadioactiveNucleus();
  RadioactiveNucleus(const std::string &nType, double aMassIn, int aNumberIn, double halfLifeIn);
  RadioactiveNucleus(const RadioactiveNucleus& other);
  RadioactiveNucleus& operator=(const RadioactiveNucleus& other);
  RadioactiveNucleus(RadioactiveNucleus&& other) noexcept;
  RadioactiveNucleus& operator=(RadioactiveNucleus&& other) noexcept;
  ~RadioactiveNucleus() override;

  // Getters
  double getHalfLife() const {return halfLife;}
  void setHalfLife(double halfLifeIn) {halfLife = halfLifeIn;}
  const std::vector<double>& getPhotonEnergies() const {return photonEnergies;}

  void addPhotonEnergy(double energy);

  bool isDecayed() override;
  void decay() override;
  void printData() const override;
};

#endif