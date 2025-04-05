#include"photon.h"
#include"electron.h"
#include<iostream>
#include<cmath>
#include<memory>
#include<stdexcept>

double photoelectricEffect(const std::shared_ptr<Photon>& photon)
{
  if (!photon)
  {
    std::cerr << "Error: Null photon pointer in photoelectric effect" << std::endl;
    return 0.0;
  }
  double energy = photon->getEnergy();
  std::cout << "Photoelectric effectr: Photon of energy " << energy
            << " MeV is absorved completely" << std::endl;
  
  return energy;
}

double comptonEffect(const std::shared_ptr<Photon>& photon, double theta)
{
  if (!photon)
  {
    std::cerr << "Error: Null photon pointer in photoelectric effect" << std::endl;
    return 0.0;
  }

  const double electronMass = 0.511; // in MeV/c^2 with c=1
  double initialEnergy = photon->getEnergy();

  // Compton scattering formula
  double newEnergy = initialEnergy / (1 + (initialEnergy / electronMass) * (1 - std::cos(theta)));

  std::cout << "Compton Effect: Photon energy changed from " << initialEnergy
            << " MeV to " << newEnergy << " MeV, with collision angle = " << theta << " rad" << std::endl;

}

std::vector<std::shared_ptr<Electron>> pairProduction(){}