#ifndef PARTICLE_H
#define PARTICLE_H
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<cmath>
#include<initializer_list>

class Particle
{
protected: // Used instead of private for the purpose of inheritance
  double restMass;
  double energy;

    
public:
  Particle(double massIn = 0.0, double energyIn = 0.0);
  virtual ~Particle(); //virtual destructor, otherwise only base class destructor called ---> memory leaks

  // Getters
  double getRestMass() const {return restMass;}
  double getEnergy() const {return energy;}

  // Setters
  void setRestMass(double massIn) {restMass = massIn;}
  void setEnergy(double energyIn) {energy = energyIn;}
};

// Parameterized constructor
Particle::Particle(double massIn, double energyIn) : restMass{massIn}, energy{energyIn}
{
}

Particle::~Particle()
{
}


#endif