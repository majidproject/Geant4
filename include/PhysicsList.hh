#ifndef PhysicsList_h
#define PhysicsList_h 1


#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics_option3.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4OpticalPhysics.hh"
#include "G4eBremsstrahlung.hh"
#include "G4DecayPhysics.hh"
#include "G4EmLivermorePhysics.hh"
#include "G4EmPenelopePhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronInelasticQBBC.hh"
#include "G4IonBinaryCascadePhysics.hh"
#include "G4Decay.hh"

#include "G4SystemOfUnits.hh"
#include "G4ProductionCutsTable.hh"
#include "G4VPhysicsConstructor.hh"
#include "G4UnitsTable.hh"

#include "globals.hh"


class G4VPhysicsConstructor;

class PhysicsList : public G4VModularPhysicsList
{
  public:
    PhysicsList();
    virtual~PhysicsList();
    
    
};    

#endif
