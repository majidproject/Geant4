#include <iostream>
#include "G4Types.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "ActionInitialization.hh"

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
#include "Randomize.hh"


int main(int argc, char** argv)
{
    
    G4RunManager *runManager = new G4RunManager();
    
    runManager->SetUserInitialization(new DetectorConstruction);
    runManager->SetUserInitialization(new PhysicsList);   
    runManager->SetUserInitialization(new ActionInitialization());        
    runManager->Initialize();
    

    
    G4VisManager *visManager = new G4VisExecutive();
    visManager -> Initialize();
    
    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    

    if ( argc>1 )
     {

       G4String command = "/control/execute ";
       G4String fileName = argv[1];
       UImanager->ApplyCommand(command+fileName);
     }
    else 
    {
       G4UIExecutive *ui = new G4UIExecutive(argc, argv);
       UImanager->ApplyCommand("/control/execute vis.mac");
       ui->SessionStart();
       delete ui;
    }

    delete visManager;
    delete runManager;
    
    return 0;
}
