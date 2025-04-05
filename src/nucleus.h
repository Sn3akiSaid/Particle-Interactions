// Particle header
#ifndef NUCLEUS_H
#define NUCLEUS_H
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<cmath>
#include<initializer_list>

class Photon;

class Nucleus
{
protected:
  std::string nucleusType;
  double atomicMass;
  int atomicNumber;
  double lambda; // Decay constant 
  bool decayed;
  std::shared_ptr<Photon> emittedPhoton;

  // Validate the nucleus type
  bool isValidNucleus(const std::string& nucleusType) const;

public:
  // Constructors
  Nucleus(const std::string &nType = "none", double aMassIn = 0.0, int aNumberIn = 0, double lambdaIn = 0.0);
  virtual ~Nucleus() = default;
  Nucleus(const Nucleus& other);
  Nucleus& operator=(const Nucleus& other);
  Nucleus(Nucleus&& other) noexcept;
  Nucleus& operator=(Nucleus&& other) noexcept;

  // Getters
  std::string getType() const {return nucleusType;}
  double getAtomicMass() const {return atomicMass;}
  int getAtomicNumber() const {return atomicNumber;}
  double getDecay() const {return lambda;}
  bool getDecayStatus() const {return decayed;}
  std::shared_ptr<Photon> getEmittedPhoton() const {return emittedPhoton;}

  // Setters
  void setType(std::string &nType) {nucleusType = nType;}
  void setAtomicMass(double aMassIn) {atomicMass = aMassIn;}
  void setAtomicNumber(int aNumberIn) {atomicNumber = aNumberIn;}
  void setDecay(double lambdaIn) {lambda = lambdaIn;}
  void setDecayed(bool hasDecayed) {decayed = hasDecayed;}
  void setEmittedPhoton(const std::shared_ptr<Photon>& photon) {emittedPhoton = photon;}

  // Virtual Methods for polymorphism
  virtual bool isDecayed();
  virtual void decay();
  virtual void printData() const;
};

#endif