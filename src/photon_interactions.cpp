#include"photon.h"
#include"electron.h"
#include"constants.h"
#include<iostream>
#include<cmath>
#include<memory>
#include<stdexcept>

using Constants::electronMass; // Bring electron mass from constants.h namespace

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

  const double electronMass = electronMass; // in MeV/c^2 with c=1
  double initialEnergy = photon->getEnergy();

  // Compton scattering formula
  double newEnergy = initialEnergy / (1 + (initialEnergy / electronMass) * (1 - std::cos(theta)));

  std::cout << "Compton Effect: Photon energy changed from " << initialEnergy
            << " MeV to " << newEnergy << " MeV, with collision angle = " << theta << " rad" << std::endl;

  photon->setEnergy(newEnergy);

  return newEnergy;
}

std::vector<std::shared_ptr<Electron>> pairProduction(const std::shared_ptr<Photon>& photon)
{
  std::vector<std::shared_ptr<Electron>> electrons;

  if (!photon)
  {
    std::cerr << "Error: Null photon pointer in pair production" << std::endl;
    return electrons;
  }

  const double thersholdEnergy = 2 * electronMass;
  double photonEnergy = photon->getEnergy();

  if (photonEnergy < thersholdEnergy)
  {
    std::cout << "Pair production error: Photon energy (" << photonEnergy
              << " MeV) is < threshold energy (" << thersholdEnergy
              << " MeV) for electron-positron pair production" << std::endl;
    return electrons;
  }

  double excessEnergy = photonEnergy - thersholdEnergy;
  auto electron = std::make_shared<Electron>(electronMass, electronMass + excessEnergy/2, -1);
  auto positron = std::make_shared<Electron>(electronMass, electronMass + excessEnergy/2, 1);

  photon->addElectron(electron);
  photon->addElectron(positron);

  electrons.push_back(electron);
  electrons.push_back(positron);

  std::cout << "Pair production: Photon of energy" << photonEnergy
            << " MeV created electron-positron pair, each with energy = "
            << (electronMass + excessEnergy/2) << " MeV" << std::endl;

  return electrons;

}