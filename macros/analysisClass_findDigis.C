#include "analysisClass.h"
#include "fitResults.h"
#include "HcalDigiTree.h"

#include "TF1.h"
#include "TH1F.h"
#include "TChain.h"
#include "TMath.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <assert.h>  
#include <cmath>
#include <map>

bool test ( const std::vector<int> * digi ){
  bool pass = true;
  int nTS = digi -> size();
  for (int iTS = 1; iTS < nTS; ++iTS)
    pass &= ((*digi)[iTS] == (*digi)[0]);
  return pass;
}

void print_digi ( const std::vector<int> * digi ){
  int nTS = digi -> size();
  for (int iTS = 1; iTS < nTS; ++iTS){
    std::cout << (*digi)[iTS] << " ";
  }
  std::cout << std::endl;
}

void analysisClass::loop(){
  
  //--------------------------------------------------------------------------------
  // Declare HCAL tree(s)
  //--------------------------------------------------------------------------------
  
  HcalDigiTree * digi_tree = getTree<HcalDigiTree>("digi_tree");
  int n_events = digi_tree -> fChain -> GetEntries();

  //--------------------------------------------------------------------------------
  // Clean branches we don't need (later)
  //--------------------------------------------------------------------------------

  digi_tree -> fChain -> SetBranchStatus("*"                 , kFALSE);
  digi_tree -> fChain -> SetBranchStatus("event"             , kTRUE );
  digi_tree -> fChain -> SetBranchStatus("digi_ieta"         , kTRUE );
  digi_tree -> fChain -> SetBranchStatus("digi_iphi"         , kTRUE );
  digi_tree -> fChain -> SetBranchStatus("digi_depth"        , kTRUE );
  digi_tree -> fChain -> SetBranchStatus("digi_timeslice_adc", kTRUE );
  
  //--------------------------------------------------------------------------------
  // Declare histograms (later)
  //--------------------------------------------------------------------------------
  
  //--------------------------------------------------------------------------------
  // Loop over the events
  //--------------------------------------------------------------------------------
  
  for (int iEvent = 0; iEvent < n_events; ++iEvent){
    
    //--------------------------------------------------------------------------------
    // Tell the user where we are
    //--------------------------------------------------------------------------------

    if (iEvent%1000 == 0) std::cout << "Processing event " << iEvent << "/" << n_events << std::endl;
    
    //--------------------------------------------------------------------------------
    // Get each entry in the event
    //--------------------------------------------------------------------------------

    digi_tree -> GetEntry(iEvent);

    //--------------------------------------------------------------------------------
    // Loop over digis in the event
    //--------------------------------------------------------------------------------

    int event = (*(*digi_tree).event)[0];
    int n_digis = int(digi_tree -> digi_timeslice_adc -> size());
    int n_pass = 0;

    for (int iDigi = 0; iDigi < n_digis; ++iDigi){
      std::vector<int> * adc  = & (*(*digi_tree).digi_timeslice_adc)[iDigi];
      int ieta  = (*(*digi_tree).digi_ieta )[iDigi];
      int iphi  = (*(*digi_tree).digi_iphi )[iDigi];
      int depth = (*(*digi_tree).digi_depth)[iDigi];
      bool pass = test ( adc );
      if (pass){
	n_pass++;
      }
    }

    if ( n_pass <= 5 ) continue;
    std::cout << "N(pass) = " << n_pass << std::endl;
    
  }
}
