#include"particle.h"
#include<iostream>

// Parameterized constructor
Particle::Particle(double massIn, double energyIn) : restMass{massIn}, energy{energyIn}
{
}

Particle::~Particle()
{
  std::cout<<"Destroy Particle"<<std::endl;
}

void Particle::printData() const
{
  std::cout << "Particle: Rest Mass = " << restMass << ", Energy = " << energy << std::endl;
}