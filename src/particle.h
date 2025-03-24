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
private:
  double restMass;
  double energy;

    
public:
  Particle();
  ~Particle();
};

Particle::Particle()
{
}

Particle::~Particle()
{
}


#endif