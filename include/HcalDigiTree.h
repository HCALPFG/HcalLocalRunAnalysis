//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jun  5 14:25:46 2014 by ROOT version 5.34/18
// from TTree digitree/HCAL Digi Info
// found on file: data/local/SelfTrigger/HcalFlatNtuple221165.root
//////////////////////////////////////////////////////////

#ifndef HcalDigiTree_h
#define HcalDigiTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class HcalDigiTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   std::vector<int>     *run;
   std::vector<int>     *event;
   std::vector<int>     *fed_number;
   std::vector<int>     *fed_bcn;
   std::vector<int>     *fed_orn;
   std::vector<int>     *digi_subdet;
   std::vector<int>     *digi_ieta;
   std::vector<int>     *digi_iphi;
   std::vector<int>     *digi_depth;
   std::vector<int>     *digi_presamples;
   std::vector<int>     *digi_nTS;
   std::vector<int>     *digi_fiberIdleOffset;
   std::vector<std::vector<int> > *digi_timeslice_dv;
   std::vector<std::vector<int> > *digi_timeslice_er;
   std::vector<std::vector<int> > *digi_timeslice_raw;
   std::vector<std::vector<int> > *digi_timeslice_adc;
   std::vector<std::vector<int> > *digi_timeslice_ladc;
   std::vector<std::vector<int> > *digi_timeslice_nomFC;
   std::vector<std::vector<int> > *digi_timeslice_fiber;
   std::vector<std::vector<int> > *digi_timeslice_fiberChan;
   std::vector<std::vector<int> > *digi_timeslice_capid;
   std::vector<std::vector<double> > *digi_timeslice_allFC;
   std::vector<std::vector<double> > *digi_timeslice_pedFC;
   std::vector<std::vector<double> > *digi_timeslice_FC;
   std::vector<std::vector<double> > *digi_timeslice_gain ;
   std::vector<std::vector<double> > *digi_timeslice_rcgain;
   std::vector<std::vector<double> > *digi_timeslice_energy;
   std::vector<double>  *reco_energy;
   std::vector<double>  *reco_time;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_fed_number;   //!
   TBranch        *b_fed_bcn;   //!
   TBranch        *b_fed_orn;   //!
   TBranch        *b_digi_subdet;   //!
   TBranch        *b_digi_ieta;   //!
   TBranch        *b_digi_iphi;   //!
   TBranch        *b_digi_depth;   //!
   TBranch        *b_digi_presamples;   //!
   TBranch        *b_digi_nTS;   //!
   TBranch        *b_digi_fiberIdleOffset;   //!
   TBranch        *b_digi_timeslice_dv;   //!
   TBranch        *b_digi_timeslice_er;   //!
   TBranch        *b_digi_timeslice_raw;   //!
   TBranch        *b_digi_timeslice_adc;   //!
   TBranch        *b_digi_timeslice_ladc;   //!
   TBranch        *b_digi_timeslice_nomFC;   //!
   TBranch        *b_digi_timeslice_fiber;   //!
   TBranch        *b_digi_timeslice_fiberChan;   //!
   TBranch        *b_digi_timeslice_capid;   //!
   TBranch        *b_digi_timeslice_allFC;   //!
   TBranch        *b_digi_timeslice_pedFC;   //!
   TBranch        *b_digi_timeslice_FC;   //!
   TBranch        *b_digi_timeslice_gain ;   //!
   TBranch        *b_digi_timeslice_rcgain;   //!
   TBranch        *b_digi_timeslice_energy;   //!
   TBranch        *b_reco_energy;   //!
   TBranch        *b_reco_time;   //!

   HcalDigiTree(TTree *tree=0);
   virtual ~HcalDigiTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef HcalDigiTree_cxx
HcalDigiTree::HcalDigiTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("data/local/SelfTrigger/HcalFlatNtuple221165.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("data/local/SelfTrigger/HcalFlatNtuple221165.root");
      }
      f->GetObject("digitree",tree);

   }
   Init(tree);
}

HcalDigiTree::~HcalDigiTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HcalDigiTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HcalDigiTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HcalDigiTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   run = 0;
   event = 0;
   fed_number = 0;
   fed_bcn = 0;
   fed_orn = 0;
   digi_subdet = 0;
   digi_ieta = 0;
   digi_iphi = 0;
   digi_depth = 0;
   digi_presamples = 0;
   digi_nTS = 0;
   digi_fiberIdleOffset = 0;
   digi_timeslice_dv = 0;
   digi_timeslice_er = 0;
   digi_timeslice_raw = 0;
   digi_timeslice_adc = 0;
   digi_timeslice_ladc = 0;
   digi_timeslice_nomFC = 0;
   digi_timeslice_fiber = 0;
   digi_timeslice_fiberChan = 0;
   digi_timeslice_capid = 0;
   digi_timeslice_allFC = 0;
   digi_timeslice_pedFC = 0;
   digi_timeslice_FC = 0;
   digi_timeslice_gain  = 0;
   digi_timeslice_rcgain = 0;
   digi_timeslice_energy = 0;
   reco_energy = 0;
   reco_time = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("fed_number", &fed_number, &b_fed_number);
   fChain->SetBranchAddress("fed_bcn", &fed_bcn, &b_fed_bcn);
   fChain->SetBranchAddress("fed_orn", &fed_orn, &b_fed_orn);
   fChain->SetBranchAddress("digi_subdet", &digi_subdet, &b_digi_subdet);
   fChain->SetBranchAddress("digi_ieta", &digi_ieta, &b_digi_ieta);
   fChain->SetBranchAddress("digi_iphi", &digi_iphi, &b_digi_iphi);
   fChain->SetBranchAddress("digi_depth", &digi_depth, &b_digi_depth);
   fChain->SetBranchAddress("digi_presamples", &digi_presamples, &b_digi_presamples);
   fChain->SetBranchAddress("digi_nTS", &digi_nTS, &b_digi_nTS);
   fChain->SetBranchAddress("digi_fiberIdleOffset", &digi_fiberIdleOffset, &b_digi_fiberIdleOffset);
   fChain->SetBranchAddress("digi_timeslice_dv", &digi_timeslice_dv, &b_digi_timeslice_dv);
   fChain->SetBranchAddress("digi_timeslice_er", &digi_timeslice_er, &b_digi_timeslice_er);
   fChain->SetBranchAddress("digi_timeslice_raw", &digi_timeslice_raw, &b_digi_timeslice_raw);
   fChain->SetBranchAddress("digi_timeslice_adc", &digi_timeslice_adc, &b_digi_timeslice_adc);
   fChain->SetBranchAddress("digi_timeslice_ladc", &digi_timeslice_ladc, &b_digi_timeslice_ladc);
   fChain->SetBranchAddress("digi_timeslice_nomFC", &digi_timeslice_nomFC, &b_digi_timeslice_nomFC);
   fChain->SetBranchAddress("digi_timeslice_fiber", &digi_timeslice_fiber, &b_digi_timeslice_fiber);
   fChain->SetBranchAddress("digi_timeslice_fiberChan", &digi_timeslice_fiberChan, &b_digi_timeslice_fiberChan);
   fChain->SetBranchAddress("digi_timeslice_capid", &digi_timeslice_capid, &b_digi_timeslice_capid);
   fChain->SetBranchAddress("digi_timeslice_allFC", &digi_timeslice_allFC, &b_digi_timeslice_allFC);
   fChain->SetBranchAddress("digi_timeslice_pedFC", &digi_timeslice_pedFC, &b_digi_timeslice_pedFC);
   fChain->SetBranchAddress("digi_timeslice_FC", &digi_timeslice_FC, &b_digi_timeslice_FC);
   fChain->SetBranchAddress("digi_timeslice_gain ", &digi_timeslice_gain , &b_digi_timeslice_gain );
   fChain->SetBranchAddress("digi_timeslice_rcgain", &digi_timeslice_rcgain, &b_digi_timeslice_rcgain);
   fChain->SetBranchAddress("digi_timeslice_energy", &digi_timeslice_energy, &b_digi_timeslice_energy);
   fChain->SetBranchAddress("reco_energy", &reco_energy, &b_reco_energy);
   fChain->SetBranchAddress("reco_time", &reco_time, &b_reco_time);
   Notify();
}

Bool_t HcalDigiTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HcalDigiTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HcalDigiTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HcalDigiTree_cxx
