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
	private:
	int Charge;
	std::unique_ptr<std::vector<double>> pairProduction;
	public:
	Electron() : Charge{-1} {}
	~Electron() {std::cout<<"Electron destruction"<<std::endl;}
	void print_data()
	{
		std::cout<<"Electron: Charge= "<<Charge<<std::endl;
	}
};

#endif