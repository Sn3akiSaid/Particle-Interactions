#include"electron.h"
#include"photon.h"
#include<iostream>
#include<memory>
#include<random>
#include<cmath>

std::shared_ptr<Photon> radiate(const std::shared_ptr<Electron>& electron)
{
  if (!electron)
  {
    std::cerr << "Error: Null electron pointer in radiation function." << std::endl;
    return nullptr;
  }

  double electronEnergy = electron->getEnergy();
  const double minEnergy = 0.01; // Minimum 10 keV threshold

  if (electronEnergy <= minEnergy)
  {
    std::cout << "Electron energy is not high enough for Bremsstrahlung radiation" << std::endl;
    return nullptr;
  }

  // Generates random energy for the photon
  std::random_device rd;
  std::mt19937 gen(rd());

  double maxFraction = 0.8; // Up to 80% of electron energy free for radiation
  std::uniform_real_distribution<> dist(0.01, maxFraction);

  // Calculates the photon energy as a fraction of the electron energy
  double fraction = dist(gen);
  double photonEnergy = electronEnergy * fraction;

  // Create photon
  auto photon = std::make_shared<Photon>(photonEnergy);

  // Conservation of energy
  electron->setEnergy(electronEnergy - photonEnergy);
  electron->addPhoton(photon);
  std::cout << "Brhemsstrahlung Radiation: Electron with initial energy " << electronEnergy
            << " MeV emitted a photon with energy " << photonEnergy
            << " MeV and now has energy " << electron->getEnergy() << " MeV" << std::endl;
  return photon;
}