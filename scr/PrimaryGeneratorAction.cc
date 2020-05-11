//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file electromagnetic/TestEm4/src/PrimaryGeneratorAction.cc
/// \brief Implementation of the PrimaryGeneratorAction class
//
//
// $Id: PrimaryGeneratorAction.cc 67268 2013-02-13 11:38:40Z ihrivnac $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "CLHEP/Random/RandBreitWigner.h"
#include "TString.h"
#include "TFile.h"
#include "TTree.h"

#include "DetectorConstruction.hh"



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::PrimaryGeneratorAction()
    : G4VUserPrimaryGeneratorAction(),fParticleGun(0),
      nsegments(10)
{
    G4int n_particle = 3200000;
    fParticleGun  = new G4ParticleGun(n_particle);

    // default particle kinematic

    G4ParticleDefinition* particle
            = G4ParticleTable::GetParticleTable()->FindParticle("gamma");
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,-1.));
    fParticleGun->SetParticlePosition(G4ThreeVector(0,0,-470*mm));

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
 

    
/*
    //send two particles at different time
    fParticleGun->SetParticlePosition(G4ThreeVector(0,0,1048.1*cm));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
    fParticleGun->SetParticleEnergy(5*MeV);
    fParticleGun->SetParticleTime(0*ns);
    fParticleGun->GeneratePrimaryVertex(anEvent);

    fParticleGun->SetParticlePosition(G4ThreeVector(0,0,1048.1*cm));
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
    fParticleGun->SetParticleEnergy(5*MeV);
    fParticleGun->SetParticleTime(100*ns);
    fParticleGun->GeneratePrimaryVertex(anEvent);
*/

    //std::cout << "7" <<std::endl;

    

    //this function is called at the begining of event


    //
  //distribution uniform in solid angle
  //
 /* 
  G4double cosTheta = 2*G4UniformRand() - 1., phi = twopi*G4UniformRand();
  G4double sinTheta = std::sqrt(1. - cosTheta*cosTheta);
  G4double ux = sinTheta*std::cos(phi),
           uy = sinTheta*std::sin(phi),
           uz = cosTheta;
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(ux,uy,uz));
    fParticleGun->SetParticlePosition(G4ThreeVector(0.*cm,0.*cm,9.9*cm));
 /*   //
  //distribution uniform in the directions of the detector placed along the x direction
  //
    G4double d=6*cm; //diameter of the detector
    G4double D=14*cm;    //detector distance from target
    G4double varcosTheta = cos (pi/2-std::atan(d/(D*2) ));
    G4double varphi = std::atan(d/(2*D));
    G4double ux,uy,uz;
    do{
        G4double cosTheta = (2*varcosTheta)*G4UniformRand() - varcosTheta, phi = 2*varphi*G4UniformRand() - varphi;
        G4double sinTheta = std::sqrt(1. - cosTheta*cosTheta);
        ux = sinTheta*std::cos(phi),
        uy = sinTheta*std::sin(phi),
        uz = cosTheta;
    }while(uz*uz + uy*uy > 9/198.25);
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(ux,uy,uz));
    fParticleGun->SetParticlePosition(G4ThreeVector(0.*cm,-fNRSSEnvelopePositionVector.y(),9.9*cm));
*/
    /*     //
    //distribution uniform in a squared detector
    //
    G4double L=3*cm; //side of the square detector
    G4double D=7*cm;    //detector distance from target
    G4double ux,uy,uz;

    uy = (L/D)*G4UniformRand() - (L/(2*D));
    uz = (L/D)*G4UniformRand() - (L/(2*D));
    ux = 1;
*/
  
 /*     fParticleGun->SetParticlePosition(G4ThreeVector(0,0,-470*mm));
       G4double ux = 0,
           uy = 0,
           uz = 1; 
  
   fParticleGun->SetParticleMomentumDirection(G4ThreeVector(ux,uy,uz));

    //random energy of the primary
   G4double energy = 0.2 * MeV;
   //G4double gamma = 2.35 * 3 * energy / 1000;
  // G4double gamma = 1 * energy / 1000;
  // fParticleGun->SetParticleEnergy(CLHEP::RandBreitWigner::shoot(energy,gamma));
fParticleGun->SetParticleEnergy(energy);

  fParticleGun->GeneratePrimaryVertex(anEvent);*/
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
