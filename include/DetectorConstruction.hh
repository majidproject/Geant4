#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"

#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4LogicalVolume.hh"

#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4RotationMatrix.hh"

#include "G4Box.hh"
#include "G4Trap.hh"
#include "G4Tubs.hh"
#include "G4Trd.hh"
#include "G4Cons.hh"

#include "G4RotationMatrix.hh"
#include "G4UnionSolid.hh"
#include "G4IntersectionSolid.hh"
#include "G4SubtractionSolid.hh"

#include "G4VisAttributes.hh"
#include "G4Color.hh"

#include "G4SDManager.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4PSDoseDeposit.hh"
#include "G4VSDFilter.hh"
#include "G4SDParticleFilter.hh"

#include "G4UIcommand.hh"


class G4LogicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  
  
      DetectorConstruction();
      
      virtual~DetectorConstruction();
      virtual G4VPhysicalVolume* Construct();
      
      G4LogicalVolume* GetScoringVolume1() const {return scoreLogic1;};
      G4LogicalVolume* GetScoringVolume4() const {return scoreLogic4;};
      G4LogicalVolume* GetScoringVolume5() const {return scoreLogic5;};
      G4LogicalVolume* GetScoringVolume6() const {return scoreLogic6;};
private: 

      G4LogicalVolume* scoreLogic1;
      G4LogicalVolume* scoreLogic4;
      G4LogicalVolume* scoreLogic5;
      G4LogicalVolume* scoreLogic6;
          
};         
#endif
