#include"nucleus.h"
#include<iostream>
#include<utility>
#include<stdexcept>
  bool Nucleus::isValidNucleus(const std::string& nType) const
  {
    return nucleusType.find("He") != std::string::npos || 
           nucleusType.find("Co") != std::string::npos ||
           nucleusType.find("Cs") != std::string::npos ||
           nucleusType.find("Na") != std::string::npos;
  }

  Nucleus::Nucleus() : nucleusType{"none"}, atomicMass{}, atomicNumber{}, lambda{}{} 

  // The parameterised constructor dynamically allocates the std::vector containing the four-vector elements
  Nucleus::Nucleus(const std::string &nType, double aMassIn, int aNumIn, double lambdaIn) :
            nucleusType{nType}, atomicMass{aMassIn}, atomicNumber{aNumIn}, lambda{lambdaIn}
            {
            // The parameterised constructor checks the validity of the energy component
            if (atomicMass<0) 
             {
               throw std::invalid_argument("Atomic mass cannot be negative.");
             }
            if (atomicNumber<0 || atomicNumber>300)
            {
              throw std::invalid_argument("Atomic number must be within the range of atomic numbers of the periodic table.");
            }
            // Check validity of particle name
            if (!isValidNucleus(nucleusType))
            {
                throw std::invalid_argument("Invalid Nucleus name used. Must be He, Co, Cs or Na.");
            }
            // Check size of vector
            // if (fourMomentum->size() != 4)
            // {
            //  throw std::logic_error("Four-momentum cannot have more than 4 elements");
            // }
           }

  // // Copy constructor makes a deep copy of the std::vector holding the 4-momentum
  // Particle::Particle(const Particle& other) : particleName(other.particleName),
  //                                   fourMomentum(std::make_unique<std::vector<double>>(*other.fourMomentum))
  //                                   {
  //                                       std::cout << "\nCalling Copy Constructor." << std::endl;
  //                                   }

  // // Copy assignment operator avoids self-assignment using the *this pointer
  // Particle& Particle::operator=(const Particle &other)
  // {
  //   std::cout << "\nCalling Copy Assignment Operator." << std::endl;
  //   if (this != &other)
  //   {
  //     particleName = other.particleName;
  //     fourMomentum = std::make_unique<std::vector<double>>(*other.fourMomentum);
  //   } return *this;
  // }

  // // Move constructor steals the memory from the object you're calling it on
  // Particle::Particle(Particle &&other) noexcept : particleName(std::move(other.particleName)),
  //                                                 fourMomentum(std::move(other.fourMomentum))
  //                                                 {
  //                                                   std::cout << "\nCalling Move Constructor." << std::endl;
  //                                                 }


  // // Move assignment operator reassigns the memory from the original object
  // Particle& Particle::operator=(Particle &&other) noexcept
  // {
  //   std::cout << "\nCalling Move Assignment Operator." << std::endl;
  //   if (this != &other)
  //   {
  //     particleName = std::move(other.particleName);
  //     fourMomentum = std::move(other.fourMomentum);
  //   } return *this;
  // }

  // Destructor frees the memory allocated by the constructor
  Nucleus::~Nucleus() = default;

  // Getter functions (accessors) to individual elements of 4-momentum
  // double Nucleus::getE() const {return fourMomentum->at(0);}
  // double Particle::getPx() const {return fourMomentum->at(1);}
  // double Particle::getPy() const {return fourMomentum->at(2);}
  // double Particle::getPz() const {return fourMomentum->at(3);}

    // Setter functions, to change values of 4-momentum 
  // void Particle::setE(double E)
  // {
  // if (E<0)
  // {
  //   throw std::invalid_argument("Energy cannot be negative.");
  // }(*fourMomentum)[0]=E;
  // }
  // void Particle::setPx(double px) {(*fourMomentum)[1]=px;}
  // void Particle::setPy(double py) {(*fourMomentum)[2]=py;}
  // void Particle::setPz(double pz) {(*fourMomentum)[3]=pz;}

  // Function to print info about a particle 
  void Nucleus::print_data() const
  {
   std::cout << nucleusType << std::endl;
  }

  // Particle Particle::operator+(const Particle &other) const
  // {
  //   double newE = getE() + other.getE();
  //   double newPx = getPx() + other.getPx();
  //   double newPy = getPy() + other.getPy();
  //   double newPz = getPz() + other.getPz();
  //   return Particle("Combined Particle", newE, newPx, newPy, newPz);
  // }

  // double Particle::dot_product(const Particle &other) const
  // {
  //   std::cout << "\n\033[4mDot product between " << particleName << " and " << other.particleName << "\033[0m\n"<< std::endl;
  //   return getE() * other.getE() - 
  //         (getPx()* other.getPx() +
  //          getPy()* other.getPy() +
  //          getPz()* other.getPz());
  // }