// Particle header
#ifndef NUCLEUS_H
#define NUCLEUS_H
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<cmath>
#include<initializer_list>

class Nucleus
{
private:
  std::string nucleusType;
  double atomicMass;
  int atomicNumber;
  double lambda;
  
  bool isValidNucleus(const std::string& nucleusType) const;
  bool isDecayed();
public:
  // Constructors
  Nucleus();
  Nucleus(const std::string &nType, double aMassIn, int aNumIn, double lambdaIn);
  ~Nucleus();

  // Getter functions
  // double getE() const;
  // double getPx() const;
  // double getPy() const;
  // double getPz() const;

  // Setter functions
  // void setE(double E);
  // void setPx(double px);
  // void setPy(double py);
  // void setPz(double pz);

  // Function to print Nucleus data and its memory location
  void print_data() const;

  // Overloaded operator for summing 
  // Nucleus operator+(const Nucleus &other) const;
  // Dot product 
  // double dot_product(const Nucleus &other) const;
};

#endif