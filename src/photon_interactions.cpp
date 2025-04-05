#include"photon.h"
#include"electron.h"
#include"constants.h"
#include<iostream>
#include<cmath>
#include<memory>
#include<stdexcept>

double photoelectricEffect(const std::shared_ptr<Photon>& photon)
{
  // Checks for photon
  if (!photon)
  {
    std::cerr << "Error: Null photon pointer in photoelectric effect" << std::endl;
    return 0.0;
  }

  // Get electron energy
  double energy = photon->getEnergy();
  std::cout << "Photoelectric effectr: Photon of energy " << energy
            << " MeV is absorved completely" << std::endl;
  
  return energy;
}

double comptonEffect(const std::shared_ptr<Photon>& photon, double theta) // theta in radians
{
  // Checks for photon
  if (!photon)
  {
    std::cerr << "Error: Null photon pointer in photoelectric effect" << std::endl;
    return 0.0;
  }

  // Get m_e from the namespace
  // Set an initial energy of photon
  const double electronMass = Constants::electronMass; // in MeV/c^2 with c=1
  double initialEnergy = photon->getEnergy();

  // Compton scattering formula with theta in radians
  
  double denominator = (1.0 + (initialEnergy / electronMass) * (1.0 - std::cos(theta)));
  double newEnergy = initialEnergy / denominator;
  // std::cout << initialEnergy << ", "<< electronMass<< ", " << newEnergy<< ", "<< std::cos(theta) <<std::endl;
  std::cout << "Compton Effect: Photon energy changed from " << initialEnergy
            << " MeV to " << newEnergy << " MeV, with collision angle = " << theta << " rad" << std::endl;

  // Set photon energy to the new calculated energy
  photon->setEnergy(newEnergy);

  return newEnergy;
}

std::vector<std::shared_ptr<Electron>> pairProduction(const std::shared_ptr<Photon>& photon)
{
  // Create the vector of electrons
  std::vector<std::shared_ptr<Electron>> electrons;

  // Check for photon
  if (!photon)
  {
    std::cerr << "Error: Null photon pointer in pair production" << std::endl;
    return electrons;
  }

  // Calculate the threshold energy for pair production 2*m_e
  const double thersholdEnergy = 2 * Constants::electronMass;
  double photonEnergy = photon->getEnergy();

  if (photonEnergy < thersholdEnergy)
  {
    std::cout << "Pair production error: Photon energy (" << photonEnergy
              << " MeV) is < threshold energy (" << thersholdEnergy
              << " MeV) for electron-positron pair production" << std::endl;
    return electrons;
  }

  // Calculate excess energy after accounting for rest mass
  double excessEnergy = photonEnergy - thersholdEnergy;

  // Create electron and positron by changing the charge 
  // Split the energy equally between the two
  auto electron = std::make_shared<Electron>(electronMass, electronMass + excessEnergy/2, -1);
  auto positron = std::make_shared<Electron>(electronMass, electronMass + excessEnergy/2, 1);

  // Make clear that the pair has been created by the photon
  photon->addElectron(electron);
  photon->addElectron(positron);

  // Return the particles
  electrons.push_back(electron);
  electrons.push_back(positron);

  std::cout << "Pair production: Photon of energy " << photonEnergy
            << " MeV created electron-positron pair, each with energy = "
            << (electronMass + excessEnergy/2) << " MeV" << std::endl;

  return electrons;

}