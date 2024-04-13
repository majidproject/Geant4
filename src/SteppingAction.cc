#include "G4Step.hh"
#include "SteppingAction.hh"
#include "G4RunManager.hh"
#include "G4Run.hh"
#include "Run.hh"
#include "G4SystemOfUnits.hh"

SteppingAction :: SteppingAction() : G4UserSteppingAction()
{}

SteppingAction :: ~SteppingAction()
{}


void SteppingAction::UserSteppingAction(const G4Step* step)
{
    G4int copyNum = step->GetPreStepPoint()->GetPhysicalVolume()->GetCopyNo();
    
    G4double totalEnergyDeposit = step->GetTotalEnergyDeposit();
    
    Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
    
    if (copyNum == 1)      {
        run->Energy1(totalEnergyDeposit);  } 
    else if (copyNum == 4) {
        run->Energy4(totalEnergyDeposit);  } 
    else if (copyNum == 5) {
        run->Energy5(totalEnergyDeposit);  } 
    else if (copyNum == 6) {
        run->Energy6(totalEnergyDeposit);  }
}

