#ifndef STABLENUCLEUS_H
#define STABLENUCLEUS_H
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<cmath>
#include<initializer_list>
#include"nucleus.h"

class StableNucleus : public Nucleus
{
public:
  StableNucleus();
  StableNucleus(const std::string &nType, double aMassIn, int aNumberIn);
  StableNucleus(const StableNucleus& other);
  StableNucleus& operator=(const StableNucleus &other);
  StableNucleus(StableNucleus&& other) noexcept;
  StableNucleus& operator=(StableNucleus&& other) noexcept;
  ~StableNucleus() override = default;

  bool isDecayed() override;
  void decay() override;
  void printData() const override;
};

#endif