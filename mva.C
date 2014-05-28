
#include<vector>
#include<iostream>
#include<cmath>

#include "TChain.h"
#include "TString.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TNtuple.h"
#include "TLorentzVector.h"
#include "TMVA/Types.h"
#include "TMVA/Factory.h"
#include "TMVA/Reader.h"
#include "TFile.h"


using namespace std ;

void mva()
{

TFile *outFile = new TFile("myAnalysisFile.root","RECREATE");

TMVA::Factory *factory = new TMVA::Factory("MVAnalysis",outFile,"");

double sigWeight = 3.461;
double bkgWeight = 1.465;

TFile *MySignalFile = new TFile("ntuEWK_mu_e.root","READ");
TTree* sigTree = (TTree*)MySignalFile->Get("EWK");
factory->AddSignalTree(sigTree,sigWeight);

TFile *MyBkgFile = new TFile("ntuQCD_mu_e.root","READ");
TTree* bkgTree = (TTree*)MyBkgFile->Get("QCD");
factory->AddBackgroundTree(bkgTree,bkgWeight);
/*
TFile *MySignalTrainFile = new TFile("ntuEWK_mu_mu_train.root","READ");
TTree* sigTreeTrain = (TTree*)MySignalTrainFile->Get( "EWK_train");

TFile *MyBkgTrainFile = new TFile("ntuQCD_mu_mu_train.root","READ");
TTree* bkgTreeTrain = (TTree*)MyBkgTrainFile->Get( "QCD_train");
*/

factory->AddVariable("lep_pt_h");
factory->AddVariable("lep_pt_l");
factory->AddVariable("lep_eta_h");
factory->AddVariable("lep_eta_l");
factory->AddVariable("jet_pt0");
factory->AddVariable("jet_eta0");
factory->AddVariable("jet_pt1");
factory->AddVariable("jet_eta1");
factory->AddVariable("jet_pt2");
factory->AddVariable("jet_eta2");
factory->AddVariable("jet_pt3");
factory->AddVariable("jet_eta3");
factory->AddVariable("jet_ptR");
factory->AddVariable("jet_deta");
factory->AddVariable("jet_mjj");
factory->AddVariable("MET");
factory->AddVariable("MET_phi");
factory->AddVariable("dRjj");
factory->AddVariable("dRll");
factory->AddVariable("dRlhj0");
factory->AddVariable("dRlhj1");
factory->AddVariable("dRllj0");
factory->AddVariable("dRllj1");


factory->PrepareTrainingAndTestTree("",950000,950000,950000,950000);
cout<<"I've prepared trees"<<endl;
factory->BookMethod( TMVA::Types::kFisher, "Fisher","");
//factory->BookMethod(TMVA::Types::kBDT, "BDT","");

cout<<"I've booked method"<<endl;
//factory->BookMethod( TMVA::Types::kLikelihood, "LikelihoodD","!H:!V:!TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=Decorrelate" );

factory->TrainAllMethods();
cout<<"I've trained all methods"<<endl;
factory->TestAllMethods();
cout<<"I've tested all methods"<<endl;
factory->EvaluateAllMethods();
cout<<"I've evaluated all methods"<<endl;

TMVA::Reader* reader = new TMVA::Reader("");

float lep_pt_h;
float lep_pt_l;
float lep_eta_h;
float lep_eta_l;
float jet_pt0;
float jet_eta0;
float jet_pt1;
float jet_eta1;
float jet_pt2;
float jet_eta2;
float jet_pt3;
float jet_eta3;
float jet_ptR;
float jet_deta;
float jet_mjj;
float MET;
float MET_phi;
float dRjj;
float dRll;
float dRlhj0;
float dRlhj1;
float dRllj0;
float dRllj1;

reader->AddVariable("lep_pt_h",&lep_pt_h);
reader->AddVariable("lep_pt_l",&lep_pt_l);
reader->AddVariable("lep_eta_h",&lep_eta_h);
reader->AddVariable("lep_eta_l",&lep_eta_l);
reader->AddVariable("jet_pt0",&jet_pt0);
reader->AddVariable("jet_eta0",&jet_eta0);
reader->AddVariable("jet_pt1",&jet_pt1);
reader->AddVariable("jet_eta1",&jet_eta1);
reader->AddVariable("jet_pt2",&jet_pt2);
reader->AddVariable("jet_eta2",&jet_eta2);
reader->AddVariable("jet_pt3",&jet_pt3);
reader->AddVariable("jet_eta3",&jet_eta3);
reader->AddVariable("jet_ptR",&jet_ptR);
reader->AddVariable("jet_deta",&jet_deta);
reader->AddVariable("jet_mjj",&jet_mjj);
reader->AddVariable("MET",&MET);
reader->AddVariable("MET_phi",&MET_phi);
reader->AddVariable("dRjj",&dRjj);
reader->AddVariable("dRll",&dRll);
reader->AddVariable("dRlhj0",&dRlhj0);
reader->AddVariable("dRlhj1",&dRlhj1);
reader->AddVariable("dRllj0",&dRllj0);
reader->AddVariable("dRllj1",&dRllj1);

reader->BookMVA("Fisher", "weights/MVAnalysis_Fisher.weights.xml");
//reader->BookMVA("BDT", "weights/MVAnalysis_Fisher.weights.xml");
//cout<<"I've read all methods"<<endl;

//double mvaValue = reader->EvaluateMVA("Fisher");
//cout<<mvaValue<<endl;
TH1F *h = new TH1F ("h","h",1000,-10.,10.);
float value;

TFile *MyEvtFile = new TFile("ntuTOT_mu_e.root","READ");
TTree* evtTree = (TTree*)MyEvtFile->Get("TOT");


evtTree->SetBranchAddress("lep_pt_h",&lep_pt_h);
evtTree->SetBranchAddress("lep_pt_l",&lep_pt_l);
evtTree->SetBranchAddress("lep_eta_h",&lep_eta_h);
evtTree->SetBranchAddress("lep_eta_l",&lep_eta_l);
evtTree->SetBranchAddress("jet_pt0",&jet_pt0);
evtTree->SetBranchAddress("jet_eta0",&jet_eta0);
evtTree->SetBranchAddress("jet_pt1",&jet_pt1);
evtTree->SetBranchAddress("jet_eta1",&jet_eta1);
evtTree->SetBranchAddress("jet_pt2",&jet_pt2);
evtTree->SetBranchAddress("jet_eta2",&jet_eta2);
evtTree->SetBranchAddress("jet_pt3",&jet_pt3);
evtTree->SetBranchAddress("jet_eta3",&jet_eta3);
evtTree->SetBranchAddress("jet_ptR",&jet_ptR);
evtTree->SetBranchAddress("jet_deta",&jet_deta);
evtTree->SetBranchAddress("jet_mjj",&jet_mjj);
evtTree->SetBranchAddress("MET",&MET);
evtTree->SetBranchAddress("MET_phi",&MET_phi);
evtTree->SetBranchAddress("dRjj",&dRjj);
evtTree->SetBranchAddress("dRll",&dRll);
evtTree->SetBranchAddress("dRlhj0",&dRlhj0);
evtTree->SetBranchAddress("dRlhj1",&dRlhj1);
evtTree->SetBranchAddress("dRllj0",&dRllj0);
evtTree->SetBranchAddress("dRllj1",&dRllj1);

for (int i = 0; i < evtTree->GetEntries(); ++i)
{
evtTree->GetEntry(i);
value = reader->EvaluateMVA("Fisher");
h->Fill(value);
if(i == 156) cout<<value<<endl;
}
h->Draw();

}
