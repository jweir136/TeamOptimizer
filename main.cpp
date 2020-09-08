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
vector<string> RolesList;
vector<Candidate> CandidateList;

/********************************
*   CREATE INIT FUNCTIONS      **
********************************/
void initRolesList() {
  RolesList.insert(RolesList.end(), "Project Manager");
  RolesList.insert(RolesList.end(), "Senior Dev");
  RolesList.insert(RolesList.end(), "Junior Dev");
}

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

int main() {
  /************************************
  *   DECLARE VARS                   **
  ************************************/
  int modeSelection = 0;
  string candidateInputName;

  /************************************
  *   CALL ALL INIT FUNCTIONS        **
  ************************************/
  initRolesList();

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

      if (NewCandidate->getName().compare("quit") != 0 && NewCandidate->getName().compare("") != 0)
        CandidateList.insert(CandidateList.end(), *NewCandidate);
    } while (candidateInputName.compare("quit") != 0);

    /************************************
    *   ASSIGN CANIDATES ROLES IN A    **
    *    FIRST COME FIRST SERVER ORDER **
    ************************************/
    for (int i = 0; i < RolesList.size(); i++)
      RoleMap.insert(pair<string, string>(RolesList[i], CandidateList[i].getName()));

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
