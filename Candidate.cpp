#include <iostream>
#include <string>
#include "Candidate.h"

using namespace std;

Candidate::Candidate(string name) {
  this->name = name;
}

string Candidate::getName() {
  return this->name;
}
