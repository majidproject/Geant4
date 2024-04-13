#include "DetectorConstruction.hh"

DetectorConstruction::DetectorConstruction():G4VUserDetectorConstruction()
{
scoreLogic1 = 0;
scoreLogic4 = 0;
scoreLogic5 = 0;
scoreLogic6 = 0;
}

DetectorConstruction::~DetectorConstruction()
{}

G4VPhysicalVolume *DetectorConstruction::Construct()
{
// Color

    G4Color white      (1.0 ,1.0, 1.0); 
    G4Color red        (1.0 ,0.0, 0.0); 
    G4Color magenta    (1.0 ,0.0, 1.0); 
    G4Color yellow     (1.0 ,1.0, 0.0);   
    G4Color green      (0.0 ,1.0, 0.0);   
    G4Color cyan       (0.0 ,1.0, 1.0);        
    G4Color black      (0.0 ,0.0, 0.0);
    G4Color Gray       (0.5 ,0.5, 0.5); 
    G4Color orange     (1.0 ,0.5, 0.5);
    G4Color blue       (0.0 ,0.0, 1.0);    
    G4Color l1red      (1.0 ,0.25, 0.25);                  
    G4Color l1blue     (0.67 ,0.85, 0.90, 0.5);        
    
// Material 
    G4NistManager *mat = G4NistManager :: Instance();

    G4Material * air      = mat -> FindOrBuildMaterial ("G4_AIR");
    G4Material * water    = mat -> FindOrBuildMaterial ("G4_WATER");
    G4Material * copper   = mat -> FindOrBuildMaterial ("G4_Cu");
    G4Material * tungsten = mat -> FindOrBuildMaterial ("G4_W");
    G4Material * lead     = mat -> FindOrBuildMaterial ("G4_Pb");
    G4Material * iron     = mat -> FindOrBuildMaterial ("G4_Fe");
    G4Material * galactic = mat -> FindOrBuildMaterial ("G4_Galactic");    
    
//World    

    G4Box *solidWorld = new G4Box ("solidWorld", 1.5*m, 1.5*m, 1.5*m);
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, air, "logicWorld");
    G4VPhysicalVolume *phyWorld = new G4PVPlacement (0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0, true);   

//Vacuum in Copper Cylinder

    G4RotationMatrix *rot1 = new G4RotationMatrix();
    rot1 -> rotateX(270.0*deg);
//  rot1 -> rotateY(0.0*deg);
//  rot1 -> rotateZ(0.0*deg);

    G4Tubs *SVacuum = new G4Tubs("SVacuum", 0.0*mm, 6.0*mm, 180.5*mm, 0.0*deg, 360.0*deg);
    G4LogicalVolume *LVacuum = new G4LogicalVolume(SVacuum, galactic, "LVacuum");
    G4VPhysicalVolume *PVacuum = new G4PVPlacement(rot1, G4ThreeVector(0.0, 207.5*mm, 0.0), LVacuum, "PVacuum", logicWorld, false, 0, true);   
    G4VisAttributes *CVacuum = new G4VisAttributes (white);
    CVacuum -> SetVisibility(true);
    CVacuum -> SetForceSolid(false);
    LVacuum -> SetVisAttributes(CVacuum);  

//Copper Cylinder

    G4Tubs *SCopper1 = new G4Tubs("SCopper1", 6.0*mm, 7.5*mm, 180.5*mm, 0.0*deg, 360.0*deg);
    G4LogicalVolume *LCopper1 = new G4LogicalVolume(SCopper1, copper, "LCopper1");
    G4VPhysicalVolume *PCopper1 = new G4PVPlacement(rot1, G4ThreeVector(0.0, 207.5*mm, 0.0), LCopper1, "PCopper1", logicWorld, false, 0, true);   
    G4VisAttributes *CCopper1 = new G4VisAttributes (orange);
    CCopper1 -> SetVisibility(true);
    CCopper1 -> SetForceSolid(true);
    LCopper1 -> SetVisAttributes(CCopper1);
    
//Lead cylinder that covers the Copper cylinder
     
    G4Tubs *SLead21 = new G4Tubs("SLead21", 0.0*mm, 8.5*mm, 196.6*mm, 0.0*deg, 360.0*deg);
    G4Tubs *SLead22 = new G4Tubs("SLead22", 0.0*mm, 28.5*mm, 196.5*mm, 0.0*deg, 360.0*deg);
    G4SubtractionSolid *SLead2 = new G4SubtractionSolid("SLead2", SLead22, SLead21, 0, G4ThreeVector());   
    G4LogicalVolume *LLead2 = new G4LogicalVolume(SLead2, lead, "LLead2");
    G4VPhysicalVolume *PLead2 = new G4PVPlacement(rot1, G4ThreeVector(0.0, 196.5*mm, 0.0), LLead2, "PLead2", logicWorld, false, 0, true);   
    G4VisAttributes *CLead2 = new G4VisAttributes (blue);
    CLead2 -> SetVisibility(true);
    CLead2 -> SetForceSolid(true);
    LLead2 -> SetVisAttributes(CLead2);  

//Lead Box that covers the Lead cylinder    
  
    G4Tubs *SLead31 = new G4Tubs("SLead31", 0.0*mm, 28.5*mm, 98.5*mm, 0.0*deg, 360.0*deg);  
    G4Box *SLead32 = new G4Box("SLead32", 68.5*mm, 68.5*mm, 98.25*mm);    
    G4SubtractionSolid *SLead3 = new G4SubtractionSolid("SLead3", SLead32, SLead31, 0, G4ThreeVector());   
    G4LogicalVolume *LLead3 = new G4LogicalVolume(SLead3, lead, "LLead3");
    G4VPhysicalVolume *PLead3 = new G4PVPlacement(rot1, G4ThreeVector(0.0, 98.25*mm, 0.0), LLead3, "PLead3", logicWorld, false, 0, true);   
    G4VisAttributes *CLead3 = new G4VisAttributes (l1red);
    CLead3 -> SetVisibility(true);
    CLead3 -> SetForceSolid(true);
    LLead3 -> SetVisAttributes(CLead3);                
        
//Tungsten Target Disk

    G4Tubs *STarget = new G4Tubs("STarget", 0.0*mm, 6.0*mm, 0.32*mm, 0.0*deg, 360.0*deg);
    G4LogicalVolume *LTarget = new G4LogicalVolume(STarget, tungsten, "LTarget");
    G4VPhysicalVolume *PTarget = new G4PVPlacement(rot1, G4ThreeVector(0.0, 25.18*mm, 0.0), LTarget, "PTarget", logicWorld, false, 0, true);   
    G4VisAttributes *CTarget = new G4VisAttributes (cyan);
    CTarget -> SetVisibility(true);
    CTarget -> SetForceSolid(true);
    LTarget -> SetVisAttributes(CTarget);    
    
//The Copper covering the Tungsten Target Disk

    G4Tubs *SCopper21 = new G4Tubs("SCopper21", 5.5*mm, 7.5*mm, 12.25*mm, 0.0*deg, 360.0*deg);  
    G4Tubs *SCopper22 = new G4Tubs("SCopper22", 0.0*mm, 6.0*mm, 0.32*mm, 0.0*deg, 360.0*deg);   
    G4SubtractionSolid *SCopper2 = new G4SubtractionSolid("SCopper2", SCopper21, SCopper22, 0, G4ThreeVector(0, 0, -11.93*mm));  
    G4LogicalVolume *LCopper2 = new G4LogicalVolume(SCopper2, copper, "LCopper2"); 
    G4VPhysicalVolume *PCopper2 = new G4PVPlacement(rot1, G4ThreeVector(0, 13.25*mm, 0.0), LCopper2, "PCopper2", logicWorld, false, 0, true); 
    G4VisAttributes *CCopper2 = new G4VisAttributes (orange);
    CCopper2 -> SetVisibility(true);
    CCopper2 -> SetForceSolid(true);
    LCopper2 -> SetVisAttributes(CCopper2); 
    
//Tungsten Collimator 

    G4RotationMatrix *rot2 = new G4RotationMatrix();
    rot2 -> rotateX(90.0*deg);
//  rot2 -> rotateY(0.0*deg);
//  rot2 -> rotateZ(0.0*deg);
    G4Cons *SCollimator1 = new G4Cons("SCollimator1", 0.0 *mm, 6*mm, 0.0 *mm, 25.0735 *mm, 40.01 *mm, 0.0 *deg, 360.0 *deg);
    G4Tubs *SCollimator2 = new G4Tubs("SCollimator2", 0.0*mm, 65.0*mm, 40.0*mm, 0.0*deg, 360.0*deg);
    G4SubtractionSolid *SCollimator = new G4SubtractionSolid("SCollimator", SCollimator2, SCollimator1, 0, G4ThreeVector());
    G4LogicalVolume *LCollimator = new G4LogicalVolume(SCollimator, tungsten, "LCollimator");
    G4VPhysicalVolume *PCollimator = new G4PVPlacement(rot1, G4ThreeVector(0.0, -40.0*mm, 0.0), LCollimator, "PCollimator", logicWorld, false, 0, true);   
    G4VisAttributes *CCollimator = new G4VisAttributes (cyan);
    CCollimator -> SetVisibility(true);
    CCollimator -> SetForceSolid(true);
    LCollimator -> SetVisAttributes(CCollimator); 
   
//The Lead covering the Tungsten collimator
    
    G4Box *SLead11 = new G4Box("SLead11", 105.0*mm, 105.0*mm, 40.0*mm);
    G4Tubs *SLead12 = new G4Tubs("SLead12", 0.0*mm, 65.0*mm, 40.01*mm, 0.0*deg, 360.0*deg);
    G4SubtractionSolid *SLead1 = new G4SubtractionSolid("SLead1", SLead11, SLead12, 0, G4ThreeVector());   
    G4LogicalVolume *LLead1 = new G4LogicalVolume(SLead1, lead, "LLead1");
    G4VPhysicalVolume *PLead1 = new G4PVPlacement(rot1, G4ThreeVector(0.0*mm, -40.0*mm, 0.0), LLead1, "PLead1", logicWorld, false, 0, true);   
    G4VisAttributes *CLead1 = new G4VisAttributes (blue);
    CLead1 -> SetVisibility(true);
    CLead1 -> SetForceSolid(true);
    LLead1 -> SetVisAttributes(CLead1); 
    
//The Iron that covers the Lead around the collimator    
     
    G4Box *SIron21 = new G4Box("SIron21", 105.0*mm, 40.01*mm, 105.0*mm);
    G4Box *SIron22 = new G4Box("SIron22", 125.0*mm, 40.0*mm, 125.0*mm);
    G4SubtractionSolid *SIron2 = new G4SubtractionSolid("SIron2", SIron22, SIron21, 0, G4ThreeVector());
    G4LogicalVolume *LIron2 = new G4LogicalVolume(SIron2, iron, "LIron2");
    G4VPhysicalVolume *PIron2 = new G4PVPlacement(0, G4ThreeVector(0.0*mm , -40.0*mm, 0.0*mm), LIron2, "PIron2", logicWorld, false, 0, true);   
    G4VisAttributes *CIron2 = new G4VisAttributes (green);
    CIron2 -> SetVisibility(true);
    CIron2 -> SetForceSolid(true);
    LIron2 -> SetVisAttributes(CIron2); 
    
//Iron case
    
    G4Box *SIron111 = new G4Box("SIron111", 125.0*mm, 125.0*mm, 25.0*mm);
    G4Box *SIron112 = new G4Box("SIron112", 349.5*mm, 195.0*mm, 195.0*mm);
    G4Tubs *SIron113 = new G4Tubs("SIron113", 7.5*mm, 28.5*mm, 20.0*mm, 0.0*deg, 360.0*deg);
    G4Box *SIron114 = new G4Box("SIron114", 351.0*mm, 196.5*mm, 196.5*mm);
    G4UnionSolid *SIron121 = new G4UnionSolid("SIron121", SIron112, SIron111, 0, G4ThreeVector(-100.0*mm, 0*mm, -195.0*mm));
    G4UnionSolid *SIron122 = new G4UnionSolid("SIron122", SIron121, SIron113, 0, G4ThreeVector(-100.0*mm, 0*mm, 195.0*mm)); 
    G4SubtractionSolid *SIron1 = new G4SubtractionSolid("SIron1", SIron114, SIron122, 0, G4ThreeVector());
    G4LogicalVolume *LIron1 = new G4LogicalVolume(SIron1, iron, "LIron1");
    G4VPhysicalVolume *PIron1 = new G4PVPlacement(rot2, G4ThreeVector(100.0*mm ,196.5*mm, 0.0), LIron1, "PIron1", logicWorld, false, 0, true);   
    G4VisAttributes *CIron1 = new G4VisAttributes (l1blue);
    CIron1 -> SetVisibility(true);
    CIron1 -> SetForceSolid(true);
    LIron1 -> SetVisAttributes(CIron1); 
    
//The Lead Cylinder on Iron casing  

    G4Tubs *SLead41 = new G4Tubs("SLead41", 0.0*mm, 28.5*mm, 27.0*mm, 0.0*deg, 360.0*deg);
    G4Tubs *SLead42 = new G4Tubs("SLead42", 0.0*mm, 8.5*mm, 17.1*mm, 0.0*deg, 360.0*deg); 
    G4SubtractionSolid *SLead4 = new G4SubtractionSolid("SLead4", SLead41, SLead42, 0, G4ThreeVector(0, 0, -10.1*mm));       
    G4LogicalVolume *LLead4 = new G4LogicalVolume(SLead4, iron, "LLead4");
    G4VPhysicalVolume *PLead4 = new G4PVPlacement(rot2, G4ThreeVector(0 , 420.0*mm, 0), LLead4, "PLead4", logicWorld, false, 0, true);   
    G4VisAttributes *CLead4 = new G4VisAttributes (red);
    CLead4 -> SetVisibility(true);
    CLead4 -> SetForceSolid(true);
    LLead4 -> SetVisAttributes(CLead4);       
    
//Voxcel

    G4Box *SVoxel = new G4Box("SVoxel", 100.0*mm, 7.5*mm, 100.0*mm);
    G4LogicalVolume *LVoxel = new G4LogicalVolume(SVoxel, water, "LVoxel");
    G4VPhysicalVolume *PVoxel = new G4PVPlacement(0, G4ThreeVector(0.0, -832.64*mm, 0.0), LVoxel, "PVoxel", logicWorld, false, 1, true);   
                                                  
    G4VisAttributes *CVoxel = new G4VisAttributes (magenta);
    CVoxel -> SetVisibility(true);
    CVoxel -> SetForceSolid(true);
    LVoxel -> SetVisAttributes(CVoxel);   

//Phantom_P4

    G4Box *SP4 = new G4Box("SP4", 10.0*mm, 10.0*mm, 10.0*mm);
    G4LogicalVolume *LP4 = new G4LogicalVolume(SP4, water, "LP4");
    G4VPhysicalVolume *PP4 = new G4PVPlacement(0, G4ThreeVector(511.0*mm, -40.0*mm, 0.0), LP4, "PP4", logicWorld, false, 4, true);   
    G4VisAttributes *CP4 = new G4VisAttributes (yellow);
    CP4 -> SetVisibility(true);
    CP4 -> SetForceSolid(true);
    LP4 -> SetVisAttributes(CP4);   
    
//Phantom_P5

    G4Box *SP5 = new G4Box("SP5", 10.0*mm, 10.0*mm, 10.0*mm);
    G4LogicalVolume *LP5 = new G4LogicalVolume(SP5, water, "LP5");
    G4VPhysicalVolume *PP5 = new G4PVPlacement(0, G4ThreeVector(511.0*mm, 10.0*mm, 0.0), LP5, "PP5", logicWorld, false, 5, true);   
    G4VisAttributes *CP5 = new G4VisAttributes (yellow);
    CP5 -> SetVisibility(true);
    CP5 -> SetForceSolid(true);
    LP5 -> SetVisAttributes(CP5);   
    
//Phantom_P6

    G4Box *SP6 = new G4Box("SP6", 10.0*mm, 10.0*mm, 10.0*mm);
    G4LogicalVolume *LP6 = new G4LogicalVolume(SP6, water, "LP6");
    G4VPhysicalVolume *PP6 = new G4PVPlacement(0, G4ThreeVector(511.0*mm, 100.0*mm, 0.0), LP6, "PP6", logicWorld, false, 6, true);   
    G4VisAttributes *CP6 = new G4VisAttributes (yellow);
    CP6 -> SetVisibility(true);
    CP6 -> SetForceSolid(true);
    LP6 -> SetVisAttributes(CP6);
    
    
    
    
     



    scoreLogic1 = LVoxel;
    scoreLogic4 = LP4;
    scoreLogic5 = LP5;
    scoreLogic6 = LP6;    
            
                              
    return phyWorld;
}



