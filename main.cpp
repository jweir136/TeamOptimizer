#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Candidate.h"

using namespace std;

/********************************
*   GLOBAL VARS                **
********************************/
map<string, Candidate> RoleMap;
vector<Candidate> CandidateList;

int main() {
  /************************************
  *   DECLARE VARS                   **
  ************************************/
  int modeSelection = 0;
  string candidateInputName;

  /************************************
  *   MSG OUTPUT                     **
  ************************************/
  cout << "Welcome to TEAM OPTIMIZER TOOL" << endl;
  cout << endl;
  cout << "Enter (1) to enter INPUT MODE" << endl;
  cout << "Enter (2) to enter OUTPUT MODE" << endl;

  /************************************
  *   MODE SELECTION INPUT           **
  ************************************/
  do {
    cin >> modeSelection;
  } while (modeSelection != 1 && modeSelection != 2);

  if (modeSelection == 1) {
    /***************************************
    *   GET CANDIDATE INPUTS              **
    *   ADD CANDIDATE INPUTS TO LIST      **
    *   ADD CANDIDATE INPUTS TO BEST ROLE **
    ***************************************/
    cout << "Enter candidate's name (enter 'quit' to exit input mode)" << endl;

    do {
      getline(cin, candidateInputName);

      Candidate *NewCandidate = new Candidate(candidateInputName);

      if (NewCandidate->getName().compare("quit") != 0)
        CandidateList.insert(CandidateList.begin(), *NewCandidate);

    } while (candidateInputName.compare("quit") != 0);

  } else if (modeSelection == 2) {

  }
}
