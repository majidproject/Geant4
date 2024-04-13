
#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

class Run;

class RunAction: public G4UserRunAction
{
public:
  RunAction();
  ~RunAction();

   virtual void BeginOfRunAction(const G4Run*);
   virtual void EndOfRunAction(const G4Run*);
   virtual G4Run *GenerateRun(); 
   
private:
   
   Run *fRun;    

};

#endif

