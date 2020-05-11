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
/// \file electromagnetic/TestEm4/src/RunAction.cc
/// \brief Implementation of the RunAction class
//
// $Id: RunAction.cc 75839 2013-11-06 17:27:26Z gcosmo $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "RunAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"

#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction()
 : G4UserRunAction()
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->SetVerboseLevel(1);  
  analysisManager->SetFirstHistoId(0);
    
  //Creating Ntuple
  analysisManager->CreateNtuple("Tracks", "Track collection");
  analysisManager->CreateNtupleDColumn("KinEnergy");
  analysisManager->CreateNtupleDColumn("Time");
  analysisManager->CreateNtupleIColumn("Particle");
  analysisManager->CreateNtupleDColumn("Mx");
  analysisManager->CreateNtupleDColumn("My");
  analysisManager->CreateNtupleDColumn("Mz");
  analysisManager->CreateNtupleIColumn("CPcode");
  analysisManager->CreateNtupleDColumn("VTxx");
  analysisManager->CreateNtupleDColumn("VTxy");
  analysisManager->CreateNtupleDColumn("VTxz");
  analysisManager->CreateNtupleDColumn("VTxMx");
  analysisManager->CreateNtupleDColumn("VTxMy");
  analysisManager->CreateNtupleDColumn("VTxMz");
  analysisManager->CreateNtupleDColumn("VTxKinEnergy");
  analysisManager->CreateNtupleIColumn("ParentID");
  analysisManager->CreateNtupleIColumn("Nstep");
   analysisManager->CreateNtupleIColumn("EventID");
  analysisManager->FinishNtuple();

  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{
   delete G4AnalysisManager::Instance();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


void RunAction::BeginOfRunAction(const G4Run*)
{
  // save Rndm status
  //G4RunManager::GetRunManager()->SetRandomNumberStore(true);
  G4Random::showEngineStatus();

  
   // Get analysis manager
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

  // Open an output file
  //
  G4String fileName = analysisManager->GetFileName();
  if(fileName == ""){
      fileName = "OutFile";
  }

  analysisManager->OpenFile(fileName);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run*)
{  
  // show Rndm status
  G4Random::showEngineStatus();         

  //save histograms      
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager->Write();
  analysisManager->CloseFile();
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
