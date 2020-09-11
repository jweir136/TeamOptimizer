#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Candidate.h"

using namespace std;

/********************************
*   GLOBAL VARS                **
********************************/
map<string, string> RoleMap;
map<string, string>::iterator iter;
vector<Candidate> CandidateList;

/********************************
*   CREATE FUNCTION TO PRINT   **
*     ASSIGNED ROLES           **
********************************/
void printAssignedRoles() {
    iter = RoleMap.begin();

    cout << "Role" << "\t" << "Candidate" << endl;

    while (iter != RoleMap.end()) {
      cout << iter->first << "\t" << iter->second << endl;  
      iter++;
    }
}


/*********************************************
*   CREATE FUNCTION TO FIND THE CANDIDATE   **
*     WITH THE HIGHEST FITNESS SCORE AND    **
*     REMOVE THEM FROM THE LIST             **
*********************************************/
string getBestCandidateAndRemove() {
  // TODO
}

/********************************************
*   GET THE 3 BEST CANDIDATES AND ADD THEM **
*     TO THE ROLE MAP                      **
********************************************/
void assignRoles() {
  // todo
}

int main() {
  /************************************
  *   DECLARE VARS                   **
  ************************************/
  int modeSelection = 0;
  int candidateInputYearsOfExperience;
  int candidateInputDegree;
  int candidateInputHasCPPExperience;
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
    /***********************************************
    *   GET THE CANDIDATE NAME                    **
    *   GET THE NUMBER OF YEARS IN  EXPERIENCE    **
    *   GET THE DEGREE OF THE CANDIDATE           **
    *   GET WHETHER OF NOT THE USER HAS ANY C++   **
    *     EXPERIENCE                              **
    ***********************************************/
    do {
      cin.ignore();
      cout << "Enter candidate's name (enter 'quit' to exit input mode)" << endl;
      /////////// GET CANDIDATE NAME ////////////////
      getline(cin, candidateInputName);

      if (candidateInputName.compare("quit") == 0)
        break;

      ////////// GET CANDIDATE YEARS OF EXPERIENCE //
      cout << "Enter the number of years of experience: " << endl;
      cin >> candidateInputYearsOfExperience;

      ///////// GET CANDIDATE'S DEGREE //////////////
      cout << "Enter the degree (0 for None, 1 for Assoc., 2 for Bach., 3 for Masters, 4 for PHD): " << endl;

      do {
        cin >> candidateInputDegree;
      } while (candidateInputDegree != 0 && candidateInputDegree != 1 && candidateInputDegree != 2 && candidateInputDegree != 3 && candidateInputDegree != 4);

      ////////// GET WHETHER OR NOT THE CANDIDATE HAS C++ EXP ////
      cout << "Enter whether or not the candidate has any experience using C++ (0 for 'NO', 1 for 'YES'): " << endl;

      do {
        cin >> candidateInputHasCPPExperience;
      } while (candidateInputHasCPPExperience != 0 && candidateInputHasCPPExperience != 1);

      ////////// CREATE A CANDIDATE OBJECT AND ADD IT TO THE LIST /
      Candidate *NewCandidate = new Candidate(candidateInputName, candidateInputYearsOfExperience, candidateInputDegree, candidateInputHasCPPExperience);

      if (NewCandidate->getName().compare("") != 0)
        CandidateList.insert(CandidateList.end(), *NewCandidate);

    } while (candidateInputName.compare("quit") != 0);

    /************************************
    *   ASSIGN CANIDATES ROLES IN A    **
    *    BASED ON THEIR FITNESS SCORE  **
    ************************************/
    assignRoles();

    /*************************************
    *   DISPLAY THE ASSIGNED ROLES      **
    *************************************/
    printAssignedRoles();

  } else if (modeSelection == 2) {
    /********************************
    *   MODE SELECTION: OUTPUT     **
    ********************************/

    printAssignedRoles();
  }
}
