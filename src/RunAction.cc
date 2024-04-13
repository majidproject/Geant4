
#include "G4RunManager.hh"
#include "G4Run.hh" 
#include "Run.hh"
#include "RunAction.hh"

#include "G4SystemOfUnits.hh"

#include "Analysis.hh"
#include <fstream>

RunAction :: RunAction() : G4UserRunAction(), fRun(0)
{}

    RunAction::~RunAction()
{}


void RunAction :: BeginOfRunAction(const G4Run*)
{
}

G4Run* RunAction :: GenerateRun()
{
    fRun = new Run();
    return fRun;
}

void RunAction :: EndOfRunAction(const G4Run*)
{

    G4int nofEvents = fRun -> GetNumberOfEvent();
    

    std::ofstream file;
    file.open("output.txt", std::ios::app);  
    file   << " Total number of events is : "<< nofEvents << G4endl;     
    file.close();      
    if (isMaster) fRun -> EndOfRun();
}
