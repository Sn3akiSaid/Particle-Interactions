// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// See slides for guidance

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
// Nuclei
#include"nucleus.h"
#include"stablenucleus.h"
#include"radioactivenucleus.h"
// Particles
#include"particle.h"
#include"electron.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
  try
  {
    // Here auto is used to make objects on the heap, managed by shared_ptr's

    // Create the Nuclei

    // Stable:

    auto Iron = std::make_shared<StableNucleus>("Fe", 55.845, 26);
    cout << "Creating a stable nucleus: " << endl;
    Iron->printData();
    
    // Unstable:

    auto Cesium = std::make_shared<RadioactiveNucleus>("Cs", 137.0, 55, 30.17);
    auto Sodium = std::make_shared<RadioactiveNucleus>("Na", 22.0, 11, 2.603);
    auto Cobalt = std::make_shared<RadioactiveNucleus>("Co", 60.0, 27, 5.272);

    cout << "\nCreated radioactive nuclei:" << endl;
    Cesium->printData();
    Sodium->printData();
    Cobalt->printData();

    // Now put the nuclei in a vector to use polymorphism

    std::vector<std::shared_ptr<Nucleus>> nuclei = {Iron, Cesium, Sodium, Cobalt};

    // Show the decays

    cout << "\n==== Radioactive Decay ====\n" << endl;

    // First see what happens when we decay the stable Fe-56 nucleus
    cout << "Attempting to decay stable Fe-56:\n" << endl;
    Iron->decay();
    // Cesium->decay();

    std::vector<std::shared_ptr<Photon>> emittedPhotons;

    for (size_t i = 1; i < nuclei.size(); ++i)
    {
      cout << "\nDecaying " << nuclei[i]->getType() << ":" << endl;
      nuclei[i]->decay();

      if (nuclei[i]->getEmittedPhoton())
      {
        emittedPhotons.push_back(nuclei[i]->getEmittedPhoton());
      }
    }

    cout << "\n===== Photon Interactions =====\n" << endl;

    // Photoelectric effect with 1st photon
    if(!emittedPhotons.empty())
    {
      cout << "\n--- Photoelectric Effect ---\n" << endl;
      auto photon1 = emittedPhotons[0];
      photoelectricEffect(photon1);
    }

    //  Compton effect with 2nd photon
    if(emittedPhotons.size() > 1)
    {
      cout << "\n--- Compton Effect ---\n" << endl;
      auto photon2 = emittedPhotons[1];
      double initialEnergy = photon2->getEnergy();
      comptonEffect(photon2, 0.75);

    }

    // Pair Production with high energy photon
    if(emittedPhotons.size() > 2)
    {
      cout << "\n--- Pair Production ---\n" << endl;
      auto photon3 = emittedPhotons[10];
      // Co-60 photons with energy > 2*m_e
      auto electronPair = pairProduction(photon3);
      cout << "Created " << electronPair.size() << " particles from pair production" << endl;

      // Radiation from one of the created electrons
      if (!electronPair.empty())
      {
        cout << "\n---Electrons Radiating Photons (Bremsstrahlung)---\n" << endl;
        auto electron = electronPair[0];
        electron->printData();
        auto radiatedPhoton = radiate(electron);
        cout << "\nAfter Radiation:\n" << endl;
        electron->printData();
        if (radiatedPhoton)
        {
          cout << "Radiated ";
          radiatedPhoton->printData();
        }
      }
    }

    // Particle Electron;
  }
  catch(const std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
    return 1;
  }
}
