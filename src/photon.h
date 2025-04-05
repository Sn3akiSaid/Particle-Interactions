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
class Photon;
// Forward declarations of friend functions
// These allows other code which has #include"photon.h" to call the functions
// Makes them seen in the global namespace
double photoelectricEffect(const std::shared_ptr<Photon>& photon);
double comptonEffect(const std::shared_ptr<Photon>& photon, double theta = 0.5);
std::vector<std::shared_ptr<Electron>> pairProduction(const std::shared_ptr<Photon>& photon);

class Photon : public Particle
{
private:
  std::unique_ptr<std::vector<std::shared_ptr<Electron>>> pairProduction; // shared allows multiple objects sharing ownership, prevents circular ownership

public:
  Photon(double energyIn = 0.0);
  ~Photon() override;

  void printData() const override;
  void addElectron(const std::shared_ptr<Electron>& electronIn);

  // Friend functions for special access privileges to the private members of Photon
  friend double photoelectricEffect(const std::shared_ptr<Photon>& photon);
  friend double comptonEffect(const std::shared_ptr<Photon>& photon, double theta);
  friend std::vector<std::shared_ptr<Electron>> pairProduction(const std::shared_ptr<Photon>& photon);
};

#endif