#include <iostream>
#include <string>
#include "Candidate.h"

using namespace std;

Candidate::    Candidate(string name, int yearsOfWorkExperience, int degree, int hasCPPExperience) {
  this->name = name;
  this->yearsOfWorkExperience = yearsOfWorkExperience;
  this->degree = degree;
  this->hasCPPExperience = hasCPPExperience;
}

string Candidate::getName() {
  return this->name;
}

double Candidate::calculateFitnessScore() {
  return (0.5 * this->yearsOfWorkExperience) + (0.45 * this->degree) + (0.05 * this->hasCPPExperience);
}
