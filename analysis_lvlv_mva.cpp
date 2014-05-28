// c++ -O2 -lm `root-config --cflags --glibs` -o analysis_lvlv_mva analysis_lvlv_mva.cpp 

/* TODOS:
- pt min on tag jets
- max deta jets instead of max pt jets
- jets ak5 are instead ak4
*/


#include<vector>
#include<iostream>
#include<cmath>

#include "delphes_tree.h"
#include "TChain.h"
#include "TString.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TNtuple.h"
#include "TLorentzVector.h"

using namespace std ;


TTree *QCD = new TTree("QCD","QCD");
//TTree *QCD = new TTree("nt","nt");

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
/*void init_tree(string TName)
    {
    TTree *nt = new TTree(TName,TName);

    float lep_num;
    float nu_num;
    float jet_num;
    float lep_pt_h;
    float lep_pt_l;
    float lep_eta_h;
    float lep_eta_l;
    float lep_phi_h;
    float lep_phi_l;
    float jet_pt0;
    float jet_pt1;
    float jet_pt2;
    float jet_pt3;
    float jet_phi0;
    float jet_phi1;
    float jet_phi2;
    float jet_phi3;
    float jet_eta0;
    float jet_eta1;
    float jet_eta2;
    float jet_eta3;
    float jet_deta;
    float jet_ptR;
    float jet_mjj;
    float MET;
    float MET_phi;
    float dRjj;
    float dRll;
    float dRlhj0;
    float dRlhj1;
    float dRllj0;
    float dRllj1;
    float lhe_nu_pt_h;
    float lhe_nu_pt_l;
    float lhe_nu_eta_h;
    float lhe_nu_eta_l;
    float lhe_nu_phi_h;
    float lhe_nu_phi_l;
    float lhe_MET;
    float lhe_MET_eta;
    float lhe_MET_phi;
    float M_inv_1;
    float M_inv_2;

    nt->Branch("lep_num",&lep_num,"lep_num");
    nt->Branch("nu_num",&nu_num,"nu_num");
    nt->Branch("jet_num",&jet_num,"jet_num");
    nt->Branch("lep_pt_h",&lep_pt_h,"lep_pt_h");
    nt->Branch("lep_pt_l",&lep_pt_l,"lep_pt_l");
    nt->Branch("lep_eta_h",&lep_eta_h,"lep_eta_h");
    nt->Branch("lep_eta_l",&lep_eta_l,"lep_eta_l");
    nt->Branch("lep_phi_h",&lep_phi_h,"lep_phi_h");
    nt->Branch("lep_phi_l",&lep_phi_l,"lep_phi_l");
    nt->Branch("jet_pt0",&jet_pt0,"jet_pt0");
    nt->Branch("jet_pt1",&jet_pt1,"jet_pt1");
    nt->Branch("jet_pt2",&jet_pt2,"jet_pt2");
    nt->Branch("jet_pt3",&jet_pt3,"jet_pt3");
    nt->Branch("jet_phi0",&jet_phi0,"jet_phi0");
    nt->Branch("jet_phi1",&jet_phi1,"jet_phi1");
    nt->Branch("jet_phi2",&jet_phi2,"jet_phi2");
    nt->Branch("jet_phi3",&jet_phi3,"jet_phi3");
    nt->Branch("jet_eta0",&jet_eta0,"jet_eta0");
    nt->Branch("jet_eta1",&jet_eta1,"jet_eta1");
    nt->Branch("jet_eta2",&jet_eta2,"jet_eta2");
    nt->Branch("jet_eta3",&jet_eta3,"jet_eta3");
    nt->Branch("jet_deta",&jet_deta,"jet_deta");
    nt->Branch("jet_ptR",&jet_ptR,"jet_ptR");
    nt->Branch("jet_mjj",&jet_mjj,"jet_mjj");
    nt->Branch("MET",&MET,"MET");
    nt->Branch("MET_phi",&MET_phi,"MET_phi");
    nt->Branch("dRjj",&dRjj,"dRjj");
    nt->Branch("dRll",&dRll,"dRll");
    nt->Branch("dRlhj0",&dRlhj0,"dRlhj0");
    nt->Branch("dRlhj1",&dRlhj1,"dRlhj1");
    nt->Branch("dRllj0",&dRllj0,"dRllj0");
    nt->Branch("dRllj1",&dRllj1,"dRllj1");
    nt->Branch("lhe_nu_pt_h",&lhe_nu_pt_h,"lhe_nu_pt_h");
    nt->Branch("lhe_nu_pt_l",&lhe_nu_pt_l,"lhe_nu_pt_l");
    nt->Branch("lhe_nu_eta_h",&lhe_nu_eta_h,"lhe_nu_eta_h");
    nt->Branch("lhe_nu_eta_l",&lhe_nu_eta_l,"lhe_nu_eta_l");
    nt->Branch("lhe_nu_phi_h",&lhe_nu_phi_h,"lhe_nu_phi_h");
    nt->Branch("lhe_nu_phi_l",&lhe_nu_phi_l,"lhe_nu_phi_l");
    nt->Branch("lhe_MET",&lhe_MET,"lhe_MET");
    nt->Branch("lhe_MET_eta",&lhe_MET_eta,"lhe_MET_eta");
    nt->Branch("lhe_MET_phi",&lhe_MET_phi,"lhe_MET_phi");
    nt->Branch("M_inv_1",&M_inv_1,"M_inv_1");
    nt->Branch("M_inv_2",&M_inv_2,"M_inv_2");
   
    }
*//*
int createHistos (TString suffix, map<TString, TH1F *> & histos) 
{

  TH1F * h_lepton_num = new TH1F (TString ("lepton_num_") + suffix,
                             TString ("lepton_num_") + suffix,
                             30, 0, 30) ; 
  histos["lepton_num"] = h_lepton_num ;

  TH1F * h_neutrino_num = new TH1F (TString ("neutrino_num_") + suffix,
                             TString ("neutrino_num_") + suffix,
                             30, 0, 30) ; 
  histos["neutrino_num"] = h_neutrino_num ;

  TH1F * h_jet_num = new TH1F (TString ("jet_num_") + suffix,             
                             TString ("jet_num_") + suffix,
                             100, 0, 100) ; 
  histos["jet_num"] = h_jet_num ;

  TH1F * h_lep_pt_h = new TH1F (TString ("lepton_pt_h_") + suffix,             
                             TString ("lepton_pt_h_") + suffix,
                             200, 0, 500) ; 
  histos["lepton_pt_h"] = h_lep_pt_h ;

  TH1F * h_lep_pt_l = new TH1F (TString ("lepton_pt_l_") + suffix,             
                             TString ("lepton_pt_l_") + suffix,
                             200, 0, 500) ; 
  histos["lepton_pt_l"] = h_lep_pt_l ;

  TH1F * h_lep_eta_h = new TH1F (TString ("leptn_eta_h_") + suffix,             
                             TString ("leptn_eta_h_") + suffix,
                             60, -3, 3) ; 
  histos["lepton_eta_h"] = h_lep_eta_h ;

  TH1F * h_lep_eta_l = new TH1F (TString ("leptn_eta_l_") + suffix,             
                             TString ("leptn_eta_l_") + suffix,
                             60, -3, 3) ; 
  histos["lepton_eta_l"] = h_lep_eta_l ;

  TH1F * h_lep_phi_h = new TH1F (TString ("lepton_phi_h_") + suffix,             
                             TString ("lepton_phi_h_") + suffix,
                             90, -3.14, 3.14) ; 
  histos["lepton_phi_h"] = h_lep_phi_h ;

  TH1F * h_lep_phi_l = new TH1F (TString ("lepton_phi_l_") + suffix,             
                             TString ("lepton_phi_l_") + suffix,
                             90, -3.14, 3.14) ; 
  histos["lepton_phi_l"] = h_lep_phi_l ;

  TH1F * h_jet_pt0 = new TH1F (TString ("jet_pt0_") + suffix,
                             TString ("jet_pt0_") + suffix,
                             1000, 0, 1000) ; 
  histos["jet_pt0"] = h_jet_pt0 ;
  
  TH1F * h_jet_eta0 = new TH1F (TString ("jet_eta0_") + suffix,
                             TString ("jet_eta0_") + suffix,
                             60, -3, 3) ; 
  histos["jet_eta0"] = h_jet_eta0 ;
  
  TH1F * h_jet_phi0 = new TH1F (TString ("jet_phi0_") + suffix,
                             TString ("jet_phi0_") + suffix,
                             360, -3.14, 3.14) ; 
  histos["jet_phi0"] = h_jet_phi0 ;

  TH1F * h_jet_pt1 = new TH1F (TString ("jet_pt1_") + suffix,
                             TString ("jet_pt1_") + suffix,
                             1000, 0, 1000) ; 
  histos["jet_pt1"] = h_jet_pt1 ;
  
  TH1F * h_jet_eta1 = new TH1F (TString ("jet_eta1_") + suffix,
                             TString ("jet_eta1_") + suffix,
                             60, -3, 3) ; 
  histos["jet_eta1"] = h_jet_eta1 ;
  
  TH1F * h_jet_phi1 = new TH1F (TString ("jet_phi1_") + suffix,
                             TString ("jet_phi1_") + suffix,
                             360, -3.14, 3.14) ; 
  histos["jet_phi1"] = h_jet_phi1 ;
  
  TH1F * h_jet_pt2 = new TH1F (TString ("jet_pt2_") + suffix,
                             TString ("jet_pt2_") + suffix,
                             1000, 0, 1000) ; 
  histos["jet_pt2"] = h_jet_pt2 ;
  
  TH1F * h_jet_eta2 = new TH1F (TString ("jet_eta2_") + suffix,
                             TString ("jet_eta2_") + suffix,
                             60, -3, 3) ; 
  histos["jet_eta2"] = h_jet_eta2 ;
  
  TH1F * h_jet_phi2 = new TH1F (TString ("jet_phi2_") + suffix,
                             TString ("jet_phi2_") + suffix,
                             90, -3.14, 3.14) ; 
  histos["jet_phi2"] = h_jet_phi2 ;
  
  TH1F * h_jet_pt3 = new TH1F (TString ("jet_pt3_") + suffix,
                             TString ("jet_pt3_") + suffix,
                             1000, 0, 1000) ; 
  histos["jet_pt3"] = h_jet_pt3 ;
  
  TH1F * h_jet_eta3 = new TH1F (TString ("jet_eta3_") + suffix,
                             TString ("jet_eta3_") + suffix,
                             60, -3, 3) ; 
  histos["jet_eta3"] = h_jet_eta3 ;
  
  TH1F * h_jet_phi3 = new TH1F (TString ("jet_phi3_") + suffix,
                             TString ("jet_phi3_") + suffix,
                             90, -3.14, 3.14) ; 
  histos["jet_phi3"] = h_jet_phi3 ;

  TH1F * h_jet_pt_tot = new TH1F (TString ("jet_pt_tot_") + suffix,
                             TString ("jet_pt_tot_") + suffix,
                             1000, 0, 1000) ; 
  histos["jet_pt_tot"] = h_jet_pt_tot ;
  
  TH1F * h_jet_eta_tot = new TH1F (TString ("jet_eta_tot_") + suffix,
                             TString ("jet_eta_tot_") + suffix,
                             600, -3, 3) ; 
  histos["jet_eta_tot"] = h_jet_eta_tot ;
  
  TH1F * h_jet_phi_tot = new TH1F (TString ("jet_phi_tot_") + suffix,
                             TString ("jet_phi_tot_") + suffix,
                             3600, -3.14, 3.14) ; 
  histos["jet_phi_tot"] = h_jet_phi_tot ;



  TH1F * h_jet_deta = new TH1F (TString ("jet_deta_") + suffix,
                             TString ("jet_deta_") + suffix,
                             100, 0., 10) ; 
  histos["jet_deta"] = h_jet_deta ;

  TH1F * h_jet_ptR = new TH1F (TString ("jet_ptR_") + suffix,
                             TString ("jet_ptR_") + suffix,
                             1000, 0, 1.) ; 
  histos["jet_ptR"] = h_jet_ptR ;
  
  TH1F * h_jet_mjj = new TH1F (TString ("jet_mjj_") + suffix,
                             TString ("jet_mjj_") + suffix,
                             500, 0, 5000) ; 
  histos["jet_mjj"] = h_jet_mjj ;

  TH1F * h_MET = new TH1F (TString ("MET_") + suffix,
                             TString ("MET_") + suffix,
                             500, 0, 5000) ; 
  histos["MET"] = h_MET ;

  TH1F * h_MET_phi = new TH1F (TString ("MET_phi_") + suffix,
                             TString ("MET_phi_") + suffix,
                             90, -3.14, 3.14) ; 
  histos["MET_phi"] = h_MET_phi ;

  TH1F * h_lhe_nu_pt_h = new TH1F (TString ("lhe_nu_pt_h_") + suffix,
                             TString ("lhe_nu_pt_h_") + suffix,
                             200, 0, 2000) ; 
  histos["lhe_nu_pt_h"] = h_lhe_nu_pt_h ;

  TH1F * h_lhe_nu_eta_h = new TH1F (TString ("lhe_nu_eta_h_") + suffix,
                             TString ("lhe_nu_eta_h_") + suffix,
                             100, 0, 10) ; 
  histos["lhe_nu_eta_h"] = h_lhe_nu_eta_h ;

  TH1F * h_lhe_nu_phi_h = new TH1F (TString ("lhe_nu_phi_h_") + suffix,
                             TString ("lhe_nu_phi_h_") + suffix,
                             90, -3.14, 3.14) ; 
  histos["lhe_nu_phi_h"] = h_lhe_nu_phi_h ;

  TH1F * h_lhe_nu_pt_l = new TH1F (TString ("lhe_nu_pt_l_") + suffix,
                             TString ("lhe_nu_pt_l_") + suffix,
                             200, 0, 2000) ; 
  histos["lhe_nu_pt_l"] = h_lhe_nu_pt_l ;

  TH1F * h_lhe_nu_eta_l = new TH1F (TString ("lhe_nu_eta_l_") + suffix,
                             TString ("lhe_nu_eta_l_") + suffix,
                             100, 0, 10) ; 
  histos["lhe_nu_eta_l"] = h_lhe_nu_eta_l ;

  TH1F * h_lhe_nu_phi_l = new TH1F (TString ("lhe_nu_phi_l_") + suffix,
                             TString ("lhe_nu_phi_l_") + suffix,
                             90, -3.14, 3.14) ; 
  histos["lhe_nu_phi_l"] = h_lhe_nu_phi_l ;

  TH1F * h_lhe_MET = new TH1F (TString ("lhe_MET_") + suffix,
                             TString ("lhe_MET_") + suffix,
                             200, 0, 2000) ; 
  histos["lhe_MET"] = h_lhe_MET ;

  TH1F * h_lhe_MET_eta = new TH1F (TString ("lhe_MET_eta_") + suffix,
                             TString ("lhe_MET_eta_") + suffix,
                             100, -3.14, 3.14) ; 
  histos["lhe_MET_eta"] = h_lhe_MET_eta ;

  TH1F * h_lhe_MET_phi = new TH1F (TString ("lhe_MET_phi_") + suffix,
                             TString ("lhe_MET_phi_") + suffix,
                             90, -3.14, 3.14) ; 
  histos["lhe_MET_phi"] = h_lhe_MET_phi ;

  TH1F * h_M_inv_1 = new TH1F (TString ("M_inv_1_") + suffix,
                             TString ("M_inv_1_") + suffix,
                             200, 0, 200) ; 
  histos["M_inv_1"] = h_M_inv_1 ;

  TH1F * h_M_inv_2 = new TH1F (TString ("M_inv_2_") + suffix,
                             TString ("M_inv_2_") + suffix,
                             200, 0, 200) ; 
  histos["M_inv_2"] = h_M_inv_2 ;

  TH1F * h_deltaR_jj = new TH1F (TString ("deltaR_jj_") + suffix,
                             TString ("deltaR_jj_") + suffix,
                             100, 0, 10) ; 
  histos["deltaR_jj"] = h_deltaR_jj ;

  TH1F * h_deltaR_ll = new TH1F (TString ("deltaR_ll_") + suffix,
                             TString ("deltaR_ll_") + suffix,
                             100, 0, 10) ; 
  histos["deltaR_ll"] = h_deltaR_ll ;

  TH1F * h_deltaR_lhj0 = new TH1F (TString ("deltaR_lhj0_") + suffix,
                             TString ("deltaR_lhj0_") + suffix,
                             100, 0, 10) ; 
  histos["deltaR_lhj0"] = h_deltaR_lhj0 ;

  TH1F * h_deltaR_lhj1 = new TH1F (TString ("deltaR_lhj1_") + suffix,
                             TString ("deltaR_lhj1_") + suffix,
                             100, 0, 10) ; 
  histos["deltaR_lhj1"] = h_deltaR_lhj1 ;

  TH1F * h_deltaR_llj0 = new TH1F (TString ("deltaR_llj0_") + suffix,
                             TString ("deltaR_llj0_") + suffix,
                             100, 0, 10) ; 
  histos["deltaR_llj0"] = h_deltaR_llj0 ;

  TH1F * h_deltaR_llj1 = new TH1F (TString ("deltaR_llj1_") + suffix,
                             TString ("deltaR_llj1_") + suffix,
                             100, 0, 10) ; 
  histos["deltaR_llj1"] = h_deltaR_llj1 ;

  return histos.size () ;
}
*//*

// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


void saveHistos (TFile * outfile, map<TString, TH1F *> histos, float cross_section = 1.)
{
  outfile->cd () ;
  for (map<TString, TH1F *>::iterator iMap = histos.begin () ;
       iMap != histos.end () ; ++iMap)
    {
      iMap->second->Scale (cross_section / iMap->second->Integral ()) ;
      iMap->second->Write () ;
    }
  return ;
}

*/
// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


int readDataset (TString datasetBaseName, TTree* nt)//(TString datasetBaseName, map<TString, TH1F *> histos) 
{
  TChain * ch = new TChain ("Delphes") ;
  ch->Add (datasetBaseName) ;
  cout << "read " << ch->GetEntries () << " events from " << datasetBaseName.Data () << endl ;
  delphes_tree dt ;
  dt.Init (ch) ;
 
  //create ntuple


    float lep_num;
    float nu_num;
    float jet_num;
    float lep_pt_h;
    float lep_pt_l;
    float lep_eta_h;
    float lep_eta_l;
    float lep_phi_h;
    float lep_phi_l;
    float jet_pt0;
    float jet_pt1;
    float jet_pt2;
    float jet_pt3;
    float jet_phi0;
    float jet_phi1;
    float jet_phi2;
    float jet_phi3;
    float jet_eta0;
    float jet_eta1;
    float jet_eta2;
    float jet_eta3;
    float jet_deta;
    float jet_ptR;
    float jet_mjj;
    float MET;
    float MET_phi;
    float dRjj;
    float dRll;
    float dRlhj0;
    float dRlhj1;
    float dRllj0;
    float dRllj1;
    float lhe_nu_pt_h;
    float lhe_nu_pt_l;
    float lhe_nu_eta_h;
    float lhe_nu_eta_l;
    float lhe_nu_phi_h;
    float lhe_nu_phi_l;
    float lhe_MET;
    float lhe_MET_eta;
    float lhe_MET_phi;
    float M_inv_1;
    float M_inv_2;

    nt->Branch("lep_num",&lep_num,"lep_num");
    nt->Branch("nu_num",&nu_num,"nu_num");
    nt->Branch("jet_num",&jet_num,"jet_num");
    nt->Branch("lep_pt_h",&lep_pt_h,"lep_pt_h");
    nt->Branch("lep_pt_l",&lep_pt_l,"lep_pt_l");
    nt->Branch("lep_eta_h",&lep_eta_h,"lep_eta_h");
    nt->Branch("lep_eta_l",&lep_eta_l,"lep_eta_l");
    nt->Branch("lep_phi_h",&lep_phi_h,"lep_phi_h");
    nt->Branch("lep_phi_l",&lep_phi_l,"lep_phi_l");
    nt->Branch("jet_pt0",&jet_pt0,"jet_pt0");
    nt->Branch("jet_pt1",&jet_pt1,"jet_pt1");
    nt->Branch("jet_pt2",&jet_pt2,"jet_pt2");
    nt->Branch("jet_pt3",&jet_pt3,"jet_pt3");
    nt->Branch("jet_phi0",&jet_phi0,"jet_phi0");
    nt->Branch("jet_phi1",&jet_phi1,"jet_phi1");
    nt->Branch("jet_phi2",&jet_phi2,"jet_phi2");
    nt->Branch("jet_phi3",&jet_phi3,"jet_phi3");
    nt->Branch("jet_eta0",&jet_eta0,"jet_eta0");
    nt->Branch("jet_eta1",&jet_eta1,"jet_eta1");
    nt->Branch("jet_eta2",&jet_eta2,"jet_eta2");
    nt->Branch("jet_eta3",&jet_eta3,"jet_eta3");
    nt->Branch("jet_deta",&jet_deta,"jet_deta");
    nt->Branch("jet_ptR",&jet_ptR,"jet_ptR");
    nt->Branch("jet_mjj",&jet_mjj,"jet_mjj");
    nt->Branch("MET",&MET,"MET");
    nt->Branch("MET_phi",&MET_phi,"MET_phi");
    nt->Branch("dRjj",&dRjj,"dRjj");
    nt->Branch("dRll",&dRll,"dRll");
    nt->Branch("dRlhj0",&dRlhj0,"dRlhj0");
    nt->Branch("dRlhj1",&dRlhj1,"dRlhj1");
    nt->Branch("dRllj0",&dRllj0,"dRllj0");
    nt->Branch("dRllj1",&dRllj1,"dRllj1");
    nt->Branch("lhe_nu_pt_h",&lhe_nu_pt_h,"lhe_nu_pt_h");
    nt->Branch("lhe_nu_pt_l",&lhe_nu_pt_l,"lhe_nu_pt_l");
    nt->Branch("lhe_nu_eta_h",&lhe_nu_eta_h,"lhe_nu_eta_h");
    nt->Branch("lhe_nu_eta_l",&lhe_nu_eta_l,"lhe_nu_eta_l");
    nt->Branch("lhe_nu_phi_h",&lhe_nu_phi_h,"lhe_nu_phi_h");
    nt->Branch("lhe_nu_phi_l",&lhe_nu_phi_l,"lhe_nu_phi_l");
    nt->Branch("lhe_MET",&lhe_MET,"lhe_MET");
    nt->Branch("lhe_MET_eta",&lhe_MET_eta,"lhe_MET_eta");
    nt->Branch("lhe_MET_phi",&lhe_MET_phi,"lhe_MET_phi");
    nt->Branch("M_inv_1",&M_inv_1,"M_inv_1");
    nt->Branch("M_inv_2",&M_inv_2,"M_inv_2");

  //PG loop over the events  
  for (int iEvent = 0 ; iEvent < ch->GetEntries () ; ++iEvent)
    {
      ch->GetEntry (iEvent) ;
      if (iEvent % 10000 == 0) cout << "reading event number " << iEvent << "\n" ;
      
      //number of isolated leptons
      lep_num = 0;//dt.lep_number -> at (0);     
      std::vector<float> isolated_lep_pt;
      std::vector<float> isolated_lep_eta;
      std::vector<float> isolated_lep_phi;
     
     for ( int i = 0 ; i < dt.lep_number -> at (0) ; ++i)
//      if (dt.lep_isolation -> at (i) * dt.lep_pt -> at (i) < 5)
        {
        isolated_lep_pt.push_back(dt.lep_pt->at(i));
        isolated_lep_eta.push_back(dt.lep_eta->at(i));
        isolated_lep_phi.push_back(dt.lep_phi->at(i));
        }  
      lep_num = isolated_lep_pt.size();  
//      histos["lepton_num"]->Fill (lep_num) ;
          
      // number of jets
      jet_num = dt.number_jet_ak5->at (0) ;
//      histos["jet_num"]->Fill (jet_num) ;

      //number of neutrinos
      nu_num = dt.lhe_nu_pt->size();     
//      histos["neutrino_num"]->Fill (nu_num) ;

//**********************************************	CUTS	***************************************************************************

	//consider only events with at least two isolated leptons, two neutrinos and two jets
      if (lep_num < 2) continue ;
      if (jet_num < 2) continue ;
      if (nu_num < 2) continue ;

      

      //consider only events with at least two isolated leptons with pt > 20GeV and |eta| < 2.5
      int nlep_gt20 = 0;

      for (int i = 0 ; i < lep_num ; ++i)                           
        {
        if ( isolated_lep_pt.at (i) > 20 )//&& fabs(isolated_lep_eta. at(i)) < 2.5 ) 
            {            
            ++ nlep_gt20 ;
            }
        }

      if (nlep_gt20 < 2 ) continue;

/*
      for (int i = 0 ; i < lep_num ; ++i)                           
        {
        if ( dt.lep_pt -> at (i) > 20 && fabs(dt.lep_eta -> at(i)) < 2.5 ) 
            {            
            ++ nlep_gt20 ;
            }
        }
*/

      //consider only events with at least two jets with pt > 20GeV and 1.0 < |eta| < 5.0
      int njet_gt20 = 0;

      for (int i = 0 ; i < jet_num ; ++i)                           
        {
        if ( dt.jet_ak5_pt -> at (i) > 20 )//&& fabs(dt.jet_ak5_eta -> at(i)))// < 5 && fabs(dt.jet_ak5_eta -> at(i)) > 1 ) 
            {            
            ++ njet_gt20 ;
            }
        }
      if (njet_gt20 < 2 ) continue;


	//consider only events with invariant mass of the the two most energetic jets system > 100GeV
      float theta = 2 * atan (exp (-1 * dt.jet_ak5_eta->at (0))) ;
      float energy = dt.jet_ak5_pt->at (0) / cos (theta) ;

      TLorentzVector jet0_tlv (0., 0., 0., 0.) ;
      jet0_tlv.SetPtEtaPhiE (dt.jet_ak5_pt->at (0), dt.jet_ak5_eta->at (0), dt.jet_ak5_phi->at (0), energy) ;

      theta = 2 * atan (exp (-1 * dt.jet_ak5_eta->at (1))) ;
      energy = dt.jet_ak5_pt->at (1) / cos (theta) ;

      TLorentzVector jet1_tlv (0., 0., 0., 0.) ;
      jet1_tlv.SetPtEtaPhiE (dt.jet_ak5_pt->at (1), dt.jet_ak5_eta->at (1), dt.jet_ak5_phi->at (1), energy) ;
      
      TLorentzVector diJet_tlv = jet1_tlv + jet0_tlv ; //lorentz_vector = (pt,eta,phi,E)
 
//    if (fabs(diJet_tlv.M ()) < 100) continue;  
      

      // get the two highest pt leptons 
      float maxPt_lep_h = 0 ; 			//h = higher
      float maxPt_lep_id_h = 0 ;

      float maxPt_lep_l = 0 ; 			//l = lower
      float maxPt_lep_id_l = 0 ;

	//look for the h-lepton
      
    for (int i = 0 ; i < lep_num ; ++i)
        {
          if (isolated_lep_pt.at (i) > maxPt_lep_h) 
            {
              maxPt_lep_h = isolated_lep_pt.at (i) ;
              maxPt_lep_id_h = i ;
            } 
        }

	//look for the l-lepton
      for (int i = 0 ; i < lep_num ; ++i)
        {
	  if (i == maxPt_lep_id_h) continue;	//don't consider h-lepton 
          if (isolated_lep_pt.at (i) > maxPt_lep_l) 
            {
              maxPt_lep_l = isolated_lep_pt.at (i) ;
              maxPt_lep_id_l = i ;
            } 
        }

      // order the neutrinos in pt 
      float nu_h = 0 ; 			//h = higher
      float nu_id_h = 0 ;

      float nu_l = 0 ; 			//l = lower
      float nu_id_l = 0 ;

	//look for the h-pt nu
      for (int i = 0 ; i < nu_num ; ++i)
        {
          if (dt.lhe_nu_pt->at (i) > nu_h) 
            {
              nu_h = dt.lhe_nu_pt->at (i) ;
              nu_id_h = i ;
            } 
        }

	//look for the l-pt nu
      for (int i = 0 ; i < nu_num ; ++i)
        {
	  if (i == nu_id_h) continue;	//don't consider h-nu 
          if (dt.lhe_nu_pt->at (i) > nu_l) 
            {
              nu_l = dt.lhe_nu_pt->at (i) ;
              nu_id_l = i ;
            } 
        }

	//consider only events with DeltaR between each couple of particles > 0.4

	//DeltaR (jj)
      float deta = min (fabs (dt.jet_ak5_eta->at (0) - dt.jet_ak5_eta->at (1)),
			fabs (dt.jet_ak5_eta->at (1) - dt.jet_ak5_eta->at (0))) ;     
	float dphi = fabs (dt.jet_ak5_phi->at (0) - dt.jet_ak5_phi->at (1));
	if ( dphi > TMath::Pi()) dphi = 2*TMath::Pi() - dphi; 
      float dRjj = sqrt(deta*deta + dphi*dphi);

	//DeltaR (ll)
      deta = min (fabs (isolated_lep_eta.at (maxPt_lep_id_h) - isolated_lep_eta.at (maxPt_lep_id_l)),
		  fabs (isolated_lep_eta.at (maxPt_lep_id_l) - isolated_lep_eta.at (maxPt_lep_id_h))) ;
      dphi = fabs (isolated_lep_phi.at (maxPt_lep_id_h) - isolated_lep_phi.at (maxPt_lep_id_l));
	if ( dphi > TMath::Pi()) dphi = 2*TMath::Pi() - dphi; 
      float dRll = sqrt(deta*deta + dphi*dphi);    

	//DeltaR (l_h j_0)
      deta = min (fabs (isolated_lep_eta.at (maxPt_lep_id_h) - dt.jet_ak5_eta->at (0)),
		  fabs (dt.jet_ak5_eta->at (0) - isolated_lep_eta.at (maxPt_lep_id_h))) ;
      dphi = fabs (isolated_lep_phi.at (maxPt_lep_id_h) - dt.jet_ak5_phi->at (0));
	if ( dphi > TMath::Pi()) dphi = 2*TMath::Pi() - dphi; 
      float dRlhj0 = sqrt(deta*deta + dphi*dphi);    
	float detalhj0 = deta;	
	
	//DeltaR (l_h j_1)
      deta = min (fabs (isolated_lep_eta.at (maxPt_lep_id_h) - dt.jet_ak5_eta->at (1)),
		  fabs (dt.jet_ak5_eta->at (1) - isolated_lep_eta.at (maxPt_lep_id_h))) ;
      dphi = fabs (isolated_lep_phi.at (maxPt_lep_id_h) - dt.jet_ak5_phi->at (1));
	if ( dphi > TMath::Pi()) dphi = 2*TMath::Pi() - dphi; 
      float dRlhj1 = sqrt(deta*deta + dphi*dphi);    
	float detalhj1 = deta;
             
	//DeltaR (l_l j_0)
      deta = min (fabs (isolated_lep_eta.at (maxPt_lep_id_l) - dt.jet_ak5_eta->at (0)),
		  fabs (dt.jet_ak5_eta->at (0) - isolated_lep_eta.at (maxPt_lep_id_l))) ;
      dphi = fabs (isolated_lep_phi.at (maxPt_lep_id_l) - dt.jet_ak5_phi->at (0));
	if ( dphi > TMath::Pi()) dphi = 2*TMath::Pi() - dphi; 
      float dRllj0 = sqrt(deta*deta + dphi*dphi);    
	float detallj0 = deta;

	//DeltaR (l_l j_1)
      deta = min (fabs (isolated_lep_eta.at (maxPt_lep_id_l) - dt.jet_ak5_eta->at (1)),
		  fabs (dt.jet_ak5_eta->at (1) - isolated_lep_eta.at (maxPt_lep_id_l))) ;
      dphi = fabs (isolated_lep_phi.at (maxPt_lep_id_l) - dt.jet_ak5_phi->at (1));
	if ( dphi > TMath::Pi()) dphi = 2*TMath::Pi() - dphi; 
      float dRllj1 = sqrt(deta*deta + dphi*dphi);    
	float detallj1 = deta;

//	if ( dRjj < 0.4 || dRll < 0.4 || dRlhj0 < 0.4 || dRlhj1 < 0.4 || dRllj0 < 0.4 || dRllj1 < 0.4 ) continue;	

	//consider only events with the two jets difference in eta > 4
	float detajj = min (fabs (dt.jet_ak5_eta->at (0) - dt.jet_ak5_eta->at (1)),
			    fabs (dt.jet_ak5_eta->at (1) - dt.jet_ak5_eta->at (0))) ;     

//	if ( detajj < 4 ) continue;

	//consider only events in which the invariant mass of the system made by a jet and its closest lepton is > 190GeV
      theta = 2 * atan (exp (-1 * isolated_lep_eta.at (maxPt_lep_id_h))) ;
      energy = isolated_lep_pt.at (maxPt_lep_id_h) / cos (theta) ;

      TLorentzVector lep_h_tlv (0., 0., 0., 0.) ;
      lep_h_tlv.SetPtEtaPhiM (isolated_lep_pt.at (maxPt_lep_id_h), isolated_lep_eta.at (maxPt_lep_id_h), isolated_lep_phi.at (maxPt_lep_id_h), 0.);//electrons are massless

      theta = 2 * atan (exp (-1 * isolated_lep_eta.at (maxPt_lep_id_l))) ;
      energy = isolated_lep_pt.at (maxPt_lep_id_l) / cos (theta) ;

      TLorentzVector lep_l_tlv (0., 0., 0., 0.) ;
      lep_l_tlv.SetPtEtaPhiM (isolated_lep_pt.at (maxPt_lep_id_l), isolated_lep_eta.at (maxPt_lep_id_l), dt.lep_phi->at (maxPt_lep_id_l), 0.);

      TLorentzVector couple_a_tlv (0., 0., 0., 0.) ;
      TLorentzVector couple_b_tlv (0., 0., 0., 0.) ;
      TLorentzVector couple_c_tlv (0., 0., 0., 0.) ;
      TLorentzVector couple_d_tlv (0., 0., 0., 0.) ;

      //consider all the four possible couples l-j:
	if ( detallj1 < detallj0 ) //the couples are: (l_l + j1) & (l_h + j0)	
		{
        	couple_a_tlv = jet1_tlv + lep_l_tlv ;	
       		couple_b_tlv = jet0_tlv + lep_h_tlv ;
		}
	else				//the couples are: (l_l + j0) & (l_h + j1)	
		{
        	couple_a_tlv = jet0_tlv + lep_l_tlv ;
       		couple_b_tlv = jet1_tlv + lep_h_tlv ;
		}
//	if (fabs(couple_a_tlv.M ()) < 190) continue;
//	if (fabs(couple_b_tlv.M ()) < 190) continue;

//*********************************************************************************************************************************************
//*******************************	FILLING NTUPLES	*******************************************************************************

//if the event passes all the cuts, save pt, eta, phi of the two most energetic leptons, of the four most energetics jets and of the two neutrinos...
      lep_pt_h = isolated_lep_pt.at (maxPt_lep_id_h);
      lep_eta_h = isolated_lep_eta.at (maxPt_lep_id_h);
      lep_phi_h = isolated_lep_phi.at (maxPt_lep_id_h);
      lep_pt_l = isolated_lep_pt.at (maxPt_lep_id_l);
      lep_eta_l = isolated_lep_eta.at (maxPt_lep_id_l);
      lep_phi_l = isolated_lep_phi.at (maxPt_lep_id_l);
      jet_pt0 = dt.jet_ak5_pt->at (0);
      jet_phi0 = dt.jet_ak5_phi->at (0);
      jet_eta0 = dt.jet_ak5_eta->at (0);
      jet_pt1 = dt.jet_ak5_pt->at (1);
      jet_phi1 = dt.jet_ak5_phi->at (1);
      jet_eta1 = dt.jet_ak5_eta->at (1);
      if (jet_num > 2)
          {
          jet_pt2 = dt.jet_ak5_pt->at (2);
          jet_phi2 = dt.jet_ak5_phi->at (2);
          jet_eta2 = dt.jet_ak5_eta->at (2);
          }
      if (jet_num > 3)
          {
          jet_pt3 = dt.jet_ak5_pt->at (3);
          jet_phi3 = dt.jet_ak5_phi->at (3);
          jet_eta3 = dt.jet_ak5_eta->at (3);
          }
      lhe_nu_pt_h = dt.lhe_nu_pt->at(nu_id_h);
      lhe_nu_phi_h = dt.lhe_nu_phi->at(nu_id_h);
      lhe_nu_eta_h = dt.lhe_nu_eta->at(nu_id_h);
      lhe_nu_pt_l = dt.lhe_nu_pt->at(nu_id_l);
      lhe_nu_phi_l = dt.lhe_nu_phi->at(nu_id_l);
      lhe_nu_eta_l = dt.lhe_nu_eta->at(nu_id_l);
      jet_ptR = dt.jet_ak5_pt->at (1) / dt.jet_ak5_pt->at (0);
      jet_mjj = fabs(diJet_tlv.M ());

      //building lhe missing transverse energy as the sum of prompt neutrinos 4-momenta
      TLorentzVector nu_h_tlv (0., 0., 0., 0.) ;
      TLorentzVector nu_l_tlv (0., 0., 0., 0.) ;
      TLorentzVector lhe_MET_tlv (0., 0., 0., 0.) ;

      nu_h_tlv.SetPtEtaPhiM (dt.lhe_nu_pt->at(nu_id_h),dt.lhe_nu_eta->at(nu_id_h),dt.lhe_nu_phi->at(nu_id_h),0.); //lorentz vector = (pt,eta,phi,mass=0)
      nu_l_tlv.SetPtEtaPhiM (dt.lhe_nu_pt->at(nu_id_l),dt.lhe_nu_eta->at(nu_id_l),dt.lhe_nu_phi->at(nu_id_l),0.);
      lhe_MET_tlv = nu_h_tlv + nu_l_tlv;

      lhe_MET = lhe_MET_tlv.Pt();
      lhe_MET_phi = lhe_MET_tlv.Phi();
      lhe_MET_eta = lhe_MET_tlv.Eta();

      //check: (lep_h + nu_l) & (lep_l + nu_h) systems should have m*~80GeV

      TLorentzVector system_1_tlv (0.,0.,0.,0.);
      TLorentzVector system_2_tlv (0.,0.,0.,0.);

      system_1_tlv = nu_h_tlv + lep_l_tlv;
      system_2_tlv = nu_l_tlv + lep_h_tlv;

      M_inv_1 = system_1_tlv.M();
      M_inv_2 = system_2_tlv.M();

      nt -> Fill();

    } //PG loop over the events  

  return 0 ;
}


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----



int main () 
{
  char InputName_EWK[180];
  sprintf(InputName_EWK, "/afs/cern.ch/user/g/govoni/work/NICOLO/eosdir/cms/store/user/govoni/Delphes/sample_ss/gen_ss_lvlv_126_1_mu_e/phamom_*.root");
  
  char InputName_QCD[180];
  sprintf(InputName_QCD, "/afs/cern.ch/user/g/govoni/work/NICOLO/eosdir/cms/store/user/govoni/Delphes/sample_ss/gen_ss_lvlv_126_2_mu_e/phamom_*.root");

  char InputName_TOT[180];
  sprintf(InputName_TOT, "/afs/cern.ch/user/g/govoni/work/NICOLO/eosdir/cms/store/user/govoni/Delphes/sample_ss/gen_ss_lvlv_126_3_mu_e/phamom_*.root");

  char OutputName[180];
  sprintf(OutputName, "gen_ss_mu_e/13TeV_nocuts_ntu.root");

  char EWKName[80];
  sprintf(OutputName, "EWK");
  
  char QCDName[80];
  sprintf(OutputName, "QCD");

  TTree *EWK = new TTree("EWK","EWK");
  EWK->SetDirectory(0);

  TFile *outfile = new TFile("ntuplone.root", "recreate");
  readDataset(InputName_EWK,EWK);  
  outfile->cd();
  EWK->Write();
  outfile->Close();
/*
  map<TString, TH1F *> EWK_histos ;
  createHistos ("EWK", EWK_histos) ;
  readDataset (InputName_EWK, EWK_histos) ;
  TFile * outfile = new TFile (OutputName, "recreate") ;
  saveHistos (outfile, EWK_histos, 3.461) ;  //pb


  map<TString, TH1F *> QCD_histos ;
  createHistos ("QCD", QCD_histos) ;
  readDataset (InputName_QCD, QCD_histos) ;
  //TFile * outfile = new TFile (OutputName_QCD, "recreate") ;
  saveHistos (outfile, QCD_histos, 1.465) ;    //pb
*/

 /* map<TString, TH1F *> TOT_histos ;
  createHistos ("TOT", TOT_histos) ;
  readDataset (InputName_TOT, TOT_histos) ;
//readDataset ("output.root", TOT_histos) ;
  TFile * outfile = new TFile (OutputName_TOT, "recreate") ;
  saveHistos (outfile, TOT_histos, 45040.) ;    //pb
*/


  
  return 0 ;
  
}
