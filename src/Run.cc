#include "DetectorConstruction.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4Run.hh"
#include "Run.hh"
#include <fstream>

Run::Run() : G4Run()
{
 Totalenergy1 = 0;
 Totalenergy4 = 0;
 Totalenergy5 = 0;
 Totalenergy6 = 0;
}

Run::~Run()
{}

void Run :: Energy1 (G4double energy1) { Totalenergy1 += energy1; }
void Run :: Energy4 (G4double energy4) { Totalenergy4 += energy4; }
void Run :: Energy5 (G4double energy5) { Totalenergy5 += energy5; }
void Run :: Energy6 (G4double energy6) { Totalenergy6 += energy6; }

void Run :: Merge (const G4Run* run) {
   const Run *localRun1 = static_cast <const Run*>(run);
   Totalenergy1 += localRun1 -> Totalenergy1;
   G4Run :: Merge(run);  
   
                  
   const Run *localRun4 = static_cast <const Run*>(run);
   Totalenergy4 += localRun4 -> Totalenergy4;
   G4Run :: Merge(run); 
     
                  
   const Run *localRun5 = static_cast <const Run*>(run);
   Totalenergy5 += localRun5 -> Totalenergy5;
   G4Run :: Merge(run); 
    
                  
   const Run *localRun6 = static_cast <const Run*>(run);
   Totalenergy6 += localRun6 -> Totalenergy6;
   G4Run :: Merge(run); }
 
 
   
 void Run :: EndOfRun()
{
   const DetectorConstruction* det1 = static_cast <const DetectorConstruction*> (G4RunManager :: GetRunManager() -> GetUserDetectorConstruction());
   G4double mass1 = det1 -> GetScoringVolume1() -> GetMass();

   const DetectorConstruction* det4 = static_cast <const DetectorConstruction*> (G4RunManager :: GetRunManager() -> GetUserDetectorConstruction());
   G4double mass4 = det4 -> GetScoringVolume4() -> GetMass(); 
   
   const DetectorConstruction* det5 = static_cast <const DetectorConstruction*> (G4RunManager :: GetRunManager() -> GetUserDetectorConstruction());
   G4double mass5 = det5 -> GetScoringVolume5() -> GetMass();     

   const DetectorConstruction* det6 = static_cast <const DetectorConstruction*> (G4RunManager :: GetRunManager() -> GetUserDetectorConstruction());
   G4double mass6 = det6 -> GetScoringVolume6() -> GetMass();


       
   std::ofstream file;
   file.open("output.txt", std::ios::app);      

   file << "The total dose in Voxel is = " << G4BestUnit(Totalenergy1/mass1, "Dose") << G4endl;
   file << "The total dose in P4    is = " << G4BestUnit(Totalenergy4/mass4, "Dose") << G4endl;
   file << "The total dose in P5    is = " << G4BestUnit(Totalenergy5/mass5, "Dose") << G4endl;
   file << "The total dose in P6    is = " << G4BestUnit(Totalenergy6/mass6, "Dose") << G4endl;
            
   
   file.close();  
}   
