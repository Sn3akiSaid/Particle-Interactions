#include"electron.h"
#include"photon.h"
#include<iostream>
#include<memory>
#include<random>
#include<cmath>
/*

This function simulates Bremsstrahlung radiation from an electron:

- Occurs when charged particles are decelerated by interacting with another particle
  Here that is the atomic nucleus.
- The kinetic energy lost by the electron turns into photon due to CoE.

Physics Implemented:
1. Conservation of Energy
2. Energy Threshold
3. Randomness of the energy fraction converted to Bremsstrahlung radiation

*/
std::shared_ptr<Photon> radiate(const std::shared_ptr<Electron>& electron)
{
  // Check if there is an electron
  if (!electron)
  {
    std::cerr << "Error: Null electron pointer in radiation function." << std::endl;
    return nullptr;
  }

  // Get the electron energy
  double electronEnergy = electron->getEnergy();
  const double minEnergy = 0.01; // Minimum 10 keV threshold

  // Does the electron have enough energy to radiate?
  if (electronEnergy <= minEnergy)
  {
    std::cout << "Electron energy is not high enough for Bremsstrahlung radiation" << std::endl;
    return nullptr;
  }

  // Generates random energy for the photon
  // Models the quantum nature of the process
  std::random_device rd;
  std::mt19937 gen(rd());

  // Use 100% of the electron energy for radiation
  // This can be changed to lower percentages
  double maxFraction = 1; // Up to 80% of electron energy free for radiation
  std::uniform_real_distribution<> dist(0.01, maxFraction);

  // Calculates the photon energy as a fraction of the electron energy
  double fraction = dist(gen);
  double photonEnergy = electronEnergy * fraction;

  // Create photon with the calculated energy
  auto photon = std::make_shared<Photon>(photonEnergy);

  // Conservation of Energy
  electron->setEnergy(electronEnergy - photonEnergy);
  electron->addPhoton(photon);
  std::cout << "Bremsstrahlung Radiation: Electron with initial energy " << electronEnergy
            << " MeV emitted a photon with energy " << photonEnergy
            << " MeV and now has energy " << electron->getEnergy() << " MeV" << std::endl;
  return photon;
}