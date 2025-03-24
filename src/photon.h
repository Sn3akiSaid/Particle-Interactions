#ifndef PHOTON_H
#define PHOTON_H
#include"particle.h"
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<cmath>
#include<initializer_list>

class Photon : Particle
{
private:
  std::unique_ptr<std::vector<double>> radiation;
};

#endif