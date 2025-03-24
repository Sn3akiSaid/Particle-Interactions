#ifndef ELECTRON_H
#define ELECTRON_H
#include"particle.h"
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<cmath>
#include<initializer_list>

class Electron : Particle
{
	std::unique_ptr<std::vector<double>> pairProduction;
};

#endif