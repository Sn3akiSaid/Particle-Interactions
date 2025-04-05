#include"particle.h"
#include<iostream>

// Parameterized constructor
Particle::Particle(double massIn, double energyIn) : restMass{massIn}, energy{energyIn}
{
}

Particle::~Particle(){}

void Particle::printData() const
{
  // std::cout << "Particle: Rest Mass = " << restMass << ", Energy = " << energy << std::endl;
}