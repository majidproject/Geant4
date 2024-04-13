
#ifndef Run_h
#define Run_h 1


#include "G4Run.hh"
#include "globals.hh"


class Run : public G4Run
{
public:

    Run();
    ~Run();
 
   
    void Energy1 (G4double);
    void Energy4 (G4double);
    void Energy5 (G4double);
    void Energy6 (G4double);
    
    virtual void Merge (const G4Run*);
    void EndOfRun ();

        
private:
 

    G4double Totalenergy1;
    G4double Totalenergy4;
    G4double Totalenergy5;
    G4double Totalenergy6;
 
};

#endif

