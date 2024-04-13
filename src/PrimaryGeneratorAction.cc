#include "PrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"


PrimaryGeneratorAction :: PrimaryGeneratorAction() : G4VUserPrimaryGeneratorAction(), fParticleGun(0)
{
  fParticleGun  = new G4ParticleGun(1);
}

PrimaryGeneratorAction :: ~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

void PrimaryGeneratorAction :: GeneratePrimaries (G4Event* event)
{
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition *particle = particleTable->FindParticle("e-");
    fParticleGun->SetParticleDefinition(particle); 


    fParticleGun->SetParticlePosition(G4ThreeVector (0, 30.0*mm, 0));

    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0, -1, 0));
    
    fParticleGun->SetParticleEnergy(6*MeV);
    
    fParticleGun->GeneratePrimaryVertex(event);
}

