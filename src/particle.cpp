#include"particle.h"
#include<iostream>

// Parameterized constructor
Particle::Particle(double massIn, double energyIn) : restMass{massIn}, energy{energyIn}{}

// Destructor
Particle::~Particle(){}

void Particle::printData() const {}