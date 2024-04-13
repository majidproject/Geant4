#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"


class SteppingAction : public G4UserSteppingAction
{
public:
   SteppingAction();
   ~SteppingAction();
   virtual void UserSteppingAction(const G4Step*);
   
private:
//   G4double depdose1; 
//   G4double depdose4; 
//   G4double depdose5; 
//   G4double depdose6;        

};

#endif
