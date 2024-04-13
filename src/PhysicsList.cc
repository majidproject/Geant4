#include "PhysicsList.hh"

PhysicsList::PhysicsList() : G4VModularPhysicsList()
{
   SetDefaultCutValue(0.5*mm);
   SetVerboseLevel(1);

   RegisterPhysics (new G4EmStandardPhysics_option3());
   RegisterPhysics (new G4EmStandardPhysics_option4());
   RegisterPhysics (new G4EmLivermorePhysics());      
   RegisterPhysics (new G4OpticalPhysics());   
   RegisterPhysics (new G4DecayPhysics());  
   RegisterPhysics (new G4EmPenelopePhysics());  


}

PhysicsList::~PhysicsList()
{}

