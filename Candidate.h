#ifndef CANDIDATE_H
#define CANDIDATE_H

using namespace std;

/*****************************************
* CREATE A CLASS TO REPRESENT JOB       **
*   CANDIDATES, THEIR NAMES, AND        **
*   THEIR RESPONSES TO THE QUESTIONS    **
*****************************************/
class Candidate {
  public:
    Candidate(string name, int yearsOfWorkExperience, int degree, int hasCPPExperience);

    string getName();

    double calculateFitnessScore();

  private:
    string name;

    int yearsOfWorkExperience;

    int degree;

    int hasCPPExperience;
};

#endif
