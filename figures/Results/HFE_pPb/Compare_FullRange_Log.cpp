#include <stdio.h>
#include <TStyle.h>
#include <TFile.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include "mystyle.C"

using namespace std;

Double_t minpT=0.4;
Double_t maxpT=11;

TGraphAsymmErrors* RebinFONLL2TeV (TGraphAsymmErrors *g){
   int points = 13;
   double x1,y1,x2,y2, x,y, ex, eylow, eyhigh;
   for (int i=10; i<points; i++) {
      g->GetPoint(i,x1,y1);
      g->GetPoint(i+1,x2,y2);
      x= (x1+x2)/2;
      y = (y1+y2)/2;
      ex = g->GetErrorXlow(i) + g->GetErrorXlow(i+1);
      eylow = (g->GetErrorYlow(i)+g->GetErrorYlow(i+1))/2;
      eyhigh = (g->GetErrorYhigh(i) + g->GetErrorYhigh(i+1))/2;
      g->SetPoint(i,x,y);
      g->SetPointError(i,ex,ex,eylow,eyhigh);
      g->RemovePoint(i+1);
   }
   return g;
}

TH1 *MakeHistogram_2TeV(TGraphAsymmErrors *g){
   int nbins = g->GetN();
   Double_t Binning[] = {0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1,1.2, 1.3,1.4, 1.5, 2., 2.5, 3., 3.5, 4., 4.5 , 5.0, 6.0, 7.0, 8.0,10.0};
   TString Name = g->GetName();
   Name += "R";
   TH1D *hist = new TH1D(Name, Name, 21, Binning);
   Int_t bin=0;
   for(Int_t ip = 0; ip < nbins; ip++){
      bin = hist->FindBin(g->GetX()[ip]);
      hist->SetBinContent(bin, g->GetY()[ip]);
      hist->SetBinError(bin, g->GetErrorY(ip));
   }
   return hist;
}

TH1 *MakeHistogram_7TeV(TGraphErrors *g){
   int nbins = g->GetN();
   Double_t Binning[] = {0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.75, 2., 2.25, 2.5, 2.75, 3., 3.5, 4., 4.5 , 5.0, 5.5, 6.0, 7.0, 8.0};
   TString Name = g->GetName();
   Name += "R";
   TH1D *hist = new TH1D(Name, Name, 24, Binning);
   Int_t bin=0;
   for(Int_t ip = 0; ip < nbins; ip++){
      bin = hist->FindBin(g->GetX()[ip]);
      hist->SetBinContent(bin, g->GetY()[ip]);
      hist->SetBinError(bin, g->GetErrorY(ip));
   }
   return hist;
}

TH1 *MakeHistogram_7TeV(TGraphAsymmErrors *g){
   int nbins = g->GetN();
   Double_t Binning[] = {0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.75, 2., 2.25, 2.5, 2.75, 3., 3.5, 4., 4.5 , 5.0, 5.5, 6.0, 7.0, 8.0};
   TString Name = g->GetName();
   Name += "R";
   TH1D *hist = new TH1D(Name, Name, 24, Binning);
   Int_t bin=0;
   for(Int_t ip = 0; ip < nbins; ip++){
      bin = hist->FindBin(g->GetX()[ip]);
      hist->SetBinContent(bin, g->GetY()[ip]);
      hist->SetBinError(bin, g->GetErrorY(ip));
   }
   return hist;
}


TH1 *MakeHistogram_5TeV(TGraphAsymmErrors *g){
   int nbins = g->GetN();
   Double_t Binning[] = {0.5, 0.6, 0.7, 0.8, 0.9, 1., 1.1, 1.2, 1.3, 1.4, 1.5, 1.75, 2., 2.25, 2.5, 2.75, 3., 3.5, 4., 4.5, 5.0, 5.5, 6.0,7.0,8.0,10.0};
   TString Name = g->GetName();
   Name += "R";
   TH1D *hist = new TH1D(Name, Name, 25, Binning);
   Int_t bin=0;
   for(Int_t ip = 0; ip < nbins; ip++){
      bin = hist->FindBin(g->GetX()[ip]);
      hist->SetBinContent(bin, g->GetY()[ip]);
      hist->SetBinError(bin, g->GetErrorY(ip));
   }
   return hist;
}

TH1 *MakeHistogram(TGraphAsymmErrors *g){
   int nbins = g->GetN();
   Double_t Binning[] =  {0.5, 0.6, 0.7, 0.8, 0.9, 1., 1.1, 1.2, 1.3, 1.4, 1.5, 1.75, 2., 2.25, 2.5, 2.75, 3., 3.5, 4.};
   TString Name = g->GetName();
   Name += "R";
   TH1D *hist = new TH1D(Name, Name, 18, Binning);
   Int_t bin=0;
   for(Int_t ip = 0; ip < nbins; ip++){
      bin = hist->FindBin(g->GetX()[ip]);
      hist->SetBinContent(bin, g->GetY()[ip]);
      hist->SetBinError(bin, g->GetErrorY(ip));
   }
   return hist;
}

TH1 *MakeHistogram(TGraphErrors *g){
   int nbins = g->GetN();
   Double_t Binning[] = {0.5, 0.6, 0.7, 0.8, 0.9, 1., 1.1, 1.2, 1.3, 1.4, 1.5, 1.75, 2., 2.25, 2.5, 2.75, 3., 3.5, 4.};
   TString Name = g->GetName();
   Name += "R";
   TH1D *hist = new TH1D(Name, Name, 18, Binning);
   Int_t bin=0;
   for(Int_t ip = 0; ip < nbins; ip++){
		bin = hist->FindBin(g->GetX()[ip]);
      hist->SetBinContent(bin, g->GetY()[ip]);
      hist->SetBinError(bin, g->GetErrorY(ip));
   }
   return hist;
}

TH1 *Rebin(TH1 *histo){

   int nNewBins = 18;
   Double_t Binning[19] = {0.5, 0.6, 0.7, 0.8, 0.9, 1., 1.1, 1.2, 1.3, 1.4, 1.5, 1.75, 2., 2.25, 2.5, 2.75, 3., 3.5, 4.};


   TH1D *Buffer = (TH1D*) histo->Clone();

   double pt, y, estat, width;
   // first bin stays

   for(int ip = 1; ip <= histo->GetNbinsX(); ip++){
      pt = Buffer->GetBinCenter(ip);
      y = Buffer->GetBinContent(ip);
      estat = Buffer->GetBinError(ip);
      width = Buffer->GetBinWidth(ip);

      Buffer->SetBinContent(ip,y*pt*width);
      Buffer->SetBinError(ip,estat*pt*width);
   }

   TString Name = histo->GetName();
   Name += "R";

   TH1D *histoRebinned = (TH1D*) Buffer->Rebin(nNewBins, Name, Binning);

   for(int ip = 1; ip <= nNewBins; ip++){
      pt = histoRebinned->GetBinCenter(ip);
      y = histoRebinned->GetBinContent(ip);
      estat = histoRebinned->GetBinError(ip);
      width = histoRebinned->GetBinWidth(ip);

      histoRebinned->SetBinContent(ip,y/(pt*width));
      histoRebinned->SetBinError(ip,estat/(pt*width));
   }

   return histoRebinned;
}

TH1 *RebinToData(TH1 *histo){

   int nNewBins = 15;
   Double_t Binning[] = {0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1,1.2, 1.3,1.4, 1.5, 2., 2.5, 3., 3.5, 4.};

   TH1D *Buffer = (TH1D*) histo->Clone();

   double pt, y, estat, width;
   // first bin stays

   for(int ip = 1; ip <= histo->GetNbinsX(); ip++){
      pt = Buffer->GetBinCenter(ip);
      y = Buffer->GetBinContent(ip);
      estat = Buffer->GetBinError(ip);
      width = Buffer->GetBinWidth(ip);

      Buffer->SetBinContent(ip,y*pt*width);
      Buffer->SetBinError(ip,estat*pt*width);
   }

   TString Name = histo->GetName();
   Name += "R";

   TH1D *histoRebinned = (TH1D*) Buffer->Rebin(nNewBins, Name, Binning);

   for(int ip = 1; ip <= nNewBins; ip++){
      pt = histoRebinned->GetBinCenter(ip);
      y = histoRebinned->GetBinContent(ip);
      estat = histoRebinned->GetBinError(ip);
      width = histoRebinned->GetBinWidth(ip);

      histoRebinned->SetBinContent(ip,y/(pt*width));
      histoRebinned->SetBinError(ip,estat/(pt*width));
   }

   return histoRebinned;
}

TH1 *RebinToData5(TH1 *histo){

   int nNewBins = 20;
   Double_t Binning[] = {0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 2., 2.5, 3., 3.5, 4., 4.5, 5.0, 6.,7.0, 8.0, 10.0};

   TH1D *Buffer = (TH1D*) histo->Clone();

   double pt, y, estat, width;
   // first bin stays

   for(int ip = 1; ip <= histo->GetNbinsX(); ip++){
      pt = Buffer->GetBinCenter(ip);
      y = Buffer->GetBinContent(ip);
      estat = Buffer->GetBinError(ip);
      width = Buffer->GetBinWidth(ip);

      Buffer->SetBinContent(ip,y*pt*width);
      Buffer->SetBinError(ip,estat*pt*width);
   }

   TString Name = histo->GetName();
   Name += "R";

   TH1D *histoRebinned = (TH1D*) Buffer->Rebin(nNewBins, Name, Binning);

   for(int ip = 1; ip <= nNewBins; ip++){
      pt = histoRebinned->GetBinCenter(ip);
      y = histoRebinned->GetBinContent(ip);
      estat = histoRebinned->GetBinError(ip);
      width = histoRebinned->GetBinWidth(ip);

      histoRebinned->SetBinContent(ip,y/(pt*width));
      histoRebinned->SetBinError(ip,estat/(pt*width));
   }

   return histoRebinned;
}

TH1 *RebinToData7(TH1 *histo){

   int nNewBins = 20;
   Double_t Binning[] = {0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 2., 2.5, 3., 3.5, 4., 4.5, 5.0, 6., 7., 8.};

   TH1D *Buffer = (TH1D*) histo->Clone();

   double pt, y, estat, width;
   // first bin stays

   for(int ip = 1; ip <= histo->GetNbinsX(); ip++){
      pt = Buffer->GetBinCenter(ip);
      y = Buffer->GetBinContent(ip);
      estat = Buffer->GetBinError(ip);
      width = Buffer->GetBinWidth(ip);

      Buffer->SetBinContent(ip,y*pt*width);
      Buffer->SetBinError(ip,estat*pt*width);
   }

   TString Name = histo->GetName();
   Name += "R";

   TH1D *histoRebinned = (TH1D*) Buffer->Rebin(nNewBins, Name, Binning);

   for(int ip = 1; ip <= nNewBins; ip++){
      pt = histoRebinned->GetBinCenter(ip);
      y = histoRebinned->GetBinContent(ip);
      estat = histoRebinned->GetBinError(ip);
      width = histoRebinned->GetBinWidth(ip);

      histoRebinned->SetBinContent(ip,y/(pt*width));
      histoRebinned->SetBinError(ip,estat/(pt*width));
   }

   return histoRebinned;
}

Double_t* Add_Remove_StatError(Double_t Error[], Double_t StatError[], Bool_t Add=1, const Int_t numberofdatapoints=24){

   Double_t* New_error = new Double_t [numberofdatapoints]();

   for (Int_t ibin=0; ibin < numberofdatapoints; ibin++){
      if (Add == 1) {
         New_error[ibin] = TMath::Sqrt(Error[ibin]*Error[ibin]+StatError[ibin]*StatError[ibin]);
      } else {
         New_error[ibin] = TMath::Sqrt(Error[ibin]*Error[ibin]-StatError[ibin]*StatError[ibin]);
      }
   }
   return New_error;
   delete New_error;
}

void Compare_FullRange_Log(TString file1="HFEspectrum_2017_FineBinning_NewSyst_2TeV.root",
                  TString file2="/home/michael/Universitaet/Masterarbeit/Heavy_Flavor_Electrons/CrossSection_Ratio/HFEspectrum_pp_final_newWeights.root",
                  TString file3="ComparisonFONLL_7tev.root",
                  TString file4= "HFECrossSec13TeV.root"){

   gROOT->SetStyle("Plain");
   gStyle->SetOptStat(0);
      gStyle->SetPadTopMargin(0.05);
   gStyle->SetPadBottomMargin(0.15);
   gStyle->SetPadRightMargin(0.05);
   gStyle->SetPadLeftMargin(0.15);
   //style area
//    gSystem->Load("/Users/tidus/Documents/Studium/Master/Master\ Analyses/Electron/mystyle_C.so");
//    mystyle();

   Double_t legTextSize = 0.04;


   Double_t NormUnc_2TeV = 1.9; //%
   Double_t NormUnc_5TeV = 2.1; //%
   Double_t NormUnc_7TeV = 3.5; //%
   Double_t NormUnc_13TeV = 5.; //%

   TString LegendTitle ="#bf{ALICE preliminary}";
   TString Measurement = "#kern[-0.18]{#bf{c,b #rightarrow e, |#it{y}| < 0.8}}";
   TString pTLabel= "#it{p}_{T} (GeV/#it{c})";
   TString yLable = "1/(2#pi#it{p}_{T}) d^{2}#kern[-0.7]{#sigma}#kern[0.5]{/}(d#it{p}_{T} d#it{y}) (mb/(GeV/#kern[-0.2]{#it{c}})^{2})";
   TString yLabelRatio = "Ratio of cross sections";
   // here you can change the name  of the first two curves for the legend
   TString Legend2TeV = "#bf{#sqrt{#it{s}} = 2.76 TeV}";
   TString Legend5TeV = "#bf{#sqrt{#it{s}} = 5.02 TeV}";
   TString Legend7TeV = "#bf{#sqrt{#it{s}} = 7 TeV}";
   TString Legend13TeV = "#bf{#sqrt{#it{s}} = 13 TeV}";
   TString LabelFONLL = "#bf{FONLL #scale[0.7]{(JHEP 05 (1998) 007)}}";
   TString WorkInProgress = "#bf{#it{working progress}}";

   TString NormUncText = "#bf{#pm %.1f %% lumi. unc. not shown}";

   // old results to extend the range
   // HFE 2TeV
   Double_t HFE_2TeV_xval[] = { 0.55, 0.6499999999999999, 0.75, 0.8500000000000001, 0.95, 1.05, 1.15, 1.25, 1.35, 1.45, 1.625, 1.875, 2.125, 2.375, 2.625, 2.875, 3.25, 3.75, 4.25, 4.75, 5.5, 6.5, 7.5, 9.0, 11.0 };
   Double_t HFE_2TeV_xerrminus[] = { 0.050000000000000044, 0.04999999999999993, 0.050000000000000044, 0.050000000000000044, 0.04999999999999993, 0.050000000000000044, 0.04999999999999982, 0.050000000000000044, 0.050000000000000044, 0.050000000000000044, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.25, 0.25, 0.25, 0.25, 0.5, 0.5, 0.5, 1.0, 1.0 };
   Double_t HFE_2TeV_xerrplus[] = { 0.04999999999999993, 0.050000000000000044, 0.050000000000000044, 0.04999999999999993, 0.050000000000000044, 0.050000000000000044, 0.050000000000000044, 0.050000000000000044, 0.04999999999999982, 0.050000000000000044, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.25, 0.25, 0.25, 0.25, 0.5, 0.5, 0.5, 1.0, 1.0 };
   Double_t HFE_2TeV_yval[] = { 19.58, 8.902, 7.438, 5.914, 3.64, 2.333, 1.694, 1.08, 1.237, 0.7166, 0.5536, 0.2903, 0.1756, 0.1035, 0.06608, 0.04384, 0.02174, 0.01383, 0.006796, 0.003306, 0.001664, 7.53E-4, 3.84E-4, 1.6E-4, 4.8E-5 };
   Double_t HFE_2TeV_yerrminus_original[] = { 14.00601299442493, 7.11655197409532, 4.035167902330707, 2.3827179858304675, 1.4889949630539387, 0.9269843580125827, 0.6120661728930948, 0.41292251089036064, 0.3157483174935379, 0.2211634011313807, 0.12102098991497301, 0.06001666435249463, 0.030992418427738096, 0.019112822920751397, 0.012453513560437472, 0.008021396387163522, 0.0042004285495649135, 0.002537892826736385, 0.0014131514426981985, 8.054321821233617E-4, 3.703093301552095E-4, 1.70578427709954E-4, 1.038315944209661E-4, 3.935733730830885E-5, 1.3892443989449805E-5 };
   Double_t HFE_2TeV_yerrplus_original[] = { 14.194594041394774, 7.2290926124929396, 4.102352983349921, 2.4218804677357633, 1.5141710603495235, 0.9423226623614653, 0.6225881463696525, 0.41949016675006817, 0.32020618357552055, 0.22401950807909565, 0.12270631605585754, 0.06073483349775481, 0.0313517144666763, 0.019277447963877377, 0.012551099553425588, 0.008072329279706076, 0.00422190715198712, 0.0025442091109026395, 0.0014165313268685586, 8.073295485735673E-4, 3.7126001669988653E-4, 1.70578427709954E-4, 1.038315944209661E-4, 3.935733730830885E-5, 1.3892443989449805E-5 };
   Double_t HFE_2TeV_ystatminus[] = { 1.72, 1.144, 0.628, 0.489, 0.375, 0.266, 0.18, 0.144, 0.144, 0.1115, 0.0428, 0.0266, 0.0137, 0.0109, 0.00826, 0.00552, 0.00294, 0.00197, 0.001169, 2.55E-4, 1.15E-4, 6.9E-5, 5.0E-5, 1.8E-5, 7.0E-6 };
   Double_t HFE_2TeV_ystatplus[] = { 1.72, 1.144, 0.628, 0.489, 0.375, 0.266, 0.18, 0.144, 0.144, 0.1115, 0.0428, 0.0266, 0.0137, 0.0109, 0.00826, 0.00552, 0.00294, 0.00197, 0.001169, 2.55E-4, 1.15E-4, 6.9E-5, 5.0E-5, 1.8E-5, 7.0E-6 };
   Int_t HFE_2TeV_numpoints = 25;

   for (int i=0; i<25; i++) {
      HFE_2TeV_yval[i]=HFE_2TeV_yval[i]/1000;
      HFE_2TeV_yerrminus_original[i]=HFE_2TeV_yerrminus_original[i]/1000;
      HFE_2TeV_yerrplus_original[i]=HFE_2TeV_yerrplus_original[i]/1000;
      HFE_2TeV_ystatminus[i]=HFE_2TeV_ystatminus[i]/1000;
      HFE_2TeV_ystatplus[i]=HFE_2TeV_ystatplus[i]/1000;
   }

   Double_t* HFE_2TeV_ysystminus = Add_Remove_StatError(HFE_2TeV_yerrminus_original, HFE_2TeV_ystatminus, 0, HFE_2TeV_numpoints);
   Double_t* HFE_2TeV_ysystplus = Add_Remove_StatError(HFE_2TeV_yerrplus_original, HFE_2TeV_ystatplus, 0, HFE_2TeV_numpoints);

   TGraphAsymmErrors* HFE_2TeV_syst = new TGraphAsymmErrors(HFE_2TeV_numpoints, HFE_2TeV_xval, HFE_2TeV_yval, HFE_2TeV_xerrminus, HFE_2TeV_xerrplus, HFE_2TeV_ysystminus, HFE_2TeV_ysystplus);
   TGraphAsymmErrors* HFE_2TeV_stat = new TGraphAsymmErrors(HFE_2TeV_numpoints, HFE_2TeV_xval, HFE_2TeV_yval, HFE_2TeV_xerrminus, HFE_2TeV_xerrplus, HFE_2TeV_ystatminus, HFE_2TeV_ystatplus);

   // HFE 7TeV
   Double_t HFE_7TeV_xval[] = { 0.55, 0.65, 0.75, 0.85, 0.95, 1.05, 1.15, 1.25, 1.35, 1.45, 1.62, 1.88, 2.12, 2.38, 2.62, 2.88, 3.25, 3.75, 4.25, 4.75, 5.25, 5.75, 6.5, 7.5 };
   Double_t HFE_7TeV_xerrminus[] = { 0.050000000000000044, 0.050000000000000044, 0.050000000000000044, 0.04999999999999993, 0.04999999999999993, 0.050000000000000044, 0.04999999999999982, 0.050000000000000044, 0.050000000000000044, 0.050000000000000044, 0.1200000000000001, 0.1299999999999999, 0.1200000000000001, 0.1299999999999999, 0.1200000000000001, 0.1299999999999999, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.5, 0.5 };
   Double_t HFE_7TeV_xerrplus[] = { 0.04999999999999993, 0.04999999999999993, 0.050000000000000044, 0.050000000000000044, 0.050000000000000044, 0.050000000000000044, 0.050000000000000044, 0.050000000000000044, 0.04999999999999982, 0.050000000000000044, 0.1299999999999999, 0.1200000000000001, 0.1299999999999999, 0.1200000000000001, 0.1299999999999999, 0.1200000000000001, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.5, 0.5 };
   Double_t HFE_7TeV_yval[] = { 41.94, 20.11, 11.79, 12.13, 8.227, 5.181, 3.61, 2.753, 2.121, 1.603, 0.9269, 0.674, 0.3239, 0.2643, 0.1738, 0.1214, 0.05985, 0.03067, 0.01725, 0.00978, 0.005136, 0.004041, 0.00221, 0.001533 };
   Double_t HFE_7TeV_yerrminus_original[] = { 35.737667803033816, 17.445606896866614, 9.69140340714388, 5.93461034946693, 3.6796854485132284, 2.239964731865214, 1.364003299116245, 0.9123842392325724, 0.6441777704950707, 0.4764714052280577, 0.32463297737598995, 0.17181676286090364, 0.0847917448812088, 0.054062371387130256, 0.03336854806550624, 0.02230807028857494, 0.01493482507430201, 0.007096766869497687, 0.005676072585864278, 0.003246849087962051, 0.0019404538129004772, 0.0014434680460612907, 7.923212732219172E-4, 6.207817651961115E-4 };
   Double_t HFE_7TeV_yerrplus_original[] = { 34.20767311583762, 16.545307491853997, 9.08916937899168, 5.5188766972999135, 3.4021236015171463, 1.959182737776137, 1.3195093785191525, 0.8828068871502986, 0.6243372486084745, 0.46111386880032135, 0.31691236959134306, 0.16835545729200463, 0.08268349291122142, 0.05307899772979893, 0.032794054339163374, 0.021982947936980607, 0.014790189315894505, 0.0070292602740259945, 0.0056583566518910765, 0.0032400390429746365, 0.001935819464722886, 0.0014419556165152934, 7.923212732219172E-4, 6.20029837991689E-4 };
   Double_t HFE_7TeV_ystatminus[] = { 21.85, 9.76, 4.97, 2.86, 1.654, 0.949, 0.612, 0.398, 0.274, 0.201, 0.2096, 0.105, 0.049, 0.0307, 0.0189, 0.0129, 0.00781, 0.00379, 0.00263, 0.001702, 0.001231, 9.44E-4, 5.02E-4, 4.09E-4 };
   Double_t HFE_7TeV_ystatplus[] = { 21.85, 9.76, 4.97, 2.86, 1.654, 0.949, 0.612, 0.398, 0.274, 0.201, 0.2096, 0.105, 0.049, 0.0307, 0.0189, 0.0129, 0.00781, 0.00379, 0.00263, 0.001702, 0.001231, 9.44E-4, 5.02E-4, 4.09E-4 };
   Int_t HFE_7TeV_numpoints = 24;

   for (int i=0; i<24; i++) {
      HFE_7TeV_yval[i]=HFE_7TeV_yval[i]/1000;
      HFE_7TeV_yerrminus_original[i]=HFE_7TeV_yerrminus_original[i]/1000;
      HFE_7TeV_yerrplus_original[i]=HFE_7TeV_yerrplus_original[i]/1000;
      HFE_7TeV_ystatminus[i]=HFE_7TeV_ystatminus[i]/1000;
      HFE_7TeV_ystatplus[i]=HFE_7TeV_ystatplus[i]/1000;
   }

   Double_t* HFE_7TeV_ysystminus = Add_Remove_StatError(HFE_7TeV_yerrminus_original, HFE_7TeV_ystatminus, 0, HFE_7TeV_numpoints);
   Double_t* HFE_7TeV_ysystplus = Add_Remove_StatError(HFE_7TeV_yerrplus_original, HFE_7TeV_ystatplus, 0, HFE_7TeV_numpoints);

   TGraphAsymmErrors* HFE_7TeV_syst = new TGraphAsymmErrors(HFE_7TeV_numpoints, HFE_7TeV_xval, HFE_7TeV_yval, HFE_7TeV_xerrminus, HFE_7TeV_xerrplus, HFE_7TeV_ysystminus, HFE_7TeV_ysystplus);
   TGraphAsymmErrors* HFE_7TeV_stat = new TGraphAsymmErrors(HFE_7TeV_numpoints, HFE_7TeV_xval, HFE_7TeV_yval, HFE_7TeV_xerrminus, HFE_7TeV_xerrplus, HFE_7TeV_ystatminus, HFE_7TeV_ystatplus);
   HFE_7TeV_stat->SetName("HFE_7TeV_stat");
   HFE_7TeV_syst->SetName("HFE_7TeV_syst");

   // 2.76 TeV
   TFile* HFE2TeV = TFile::Open(file1.Data());
   TH1D* Spectrum2TeVStat = (TH1D*) HFE2TeV->GetObjectChecked("hfespectrum","TH1D");
   setOPT_hists(Spectrum2TeVStat,pTLabel, yLable,510,20,1);
   Spectrum2TeVStat->SetTitle("");
   Spectrum2TeVStat->SetName("Spectrum2TeVStat");

   TGraphAsymmErrors* Spectrum2TeVSyst = (TGraphAsymmErrors*) HFE2TeV->GetObjectChecked("hfespectrumSys","TGraphAsymmErrors");
   setOPT_graph(Spectrum2TeVSyst,pTLabel, yLable,510,0,0.5);
   Spectrum2TeVSyst->SetTitle("");
   Spectrum2TeVSyst->SetFillStyle(0);
   Spectrum2TeVSyst->SetName("Spectrum2TeVSyst");

   TGraphAsymmErrors* gSpectrum2TeVStat = new TGraphAsymmErrors(Spectrum2TeVStat);
   while (gSpectrum2TeVStat->GetN() >= HFE_2TeV_syst->GetN()) {
      gSpectrum2TeVStat->RemovePoint(0);
   }

   Int_t PointToSwitch2TeV = 13;
   Double_t x,y,ex,eylow,eyhigh;
   for (int i = 16; i< HFE_2TeV_syst->GetN(); i++) {
      HFE_2TeV_syst->GetPoint(i,x,y);
      ex = HFE_2TeV_syst->GetErrorXlow(i);
      eylow = HFE_2TeV_syst->GetErrorYlow(i);
      eyhigh = HFE_2TeV_syst->GetErrorYhigh(i);
      Spectrum2TeVSyst->SetPoint(PointToSwitch2TeV,x,y);
      Spectrum2TeVSyst->SetPointError(PointToSwitch2TeV,ex,ex,eylow,eyhigh);

      gSpectrum2TeVStat->SetPoint(PointToSwitch2TeV,x,y);
      gSpectrum2TeVStat->SetPointError(PointToSwitch2TeV,ex,ex,HFE_2TeV_stat->GetErrorYlow(i),HFE_2TeV_stat->GetErrorYlow(i));

      PointToSwitch2TeV++;
   }

   Spectrum2TeVStat = (TH1D*) MakeHistogram_2TeV(gSpectrum2TeVStat);

   TCanvas *cHFE_2TeV = new TCanvas("cHFE_2TeV","HFE @ 2TeV");
   cHFE_2TeV->SetLogy();
   HFE_2TeV_syst->SetFillColor(0);
   HFE_2TeV_syst->SetFillStyle(0);
   HFE_2TeV_syst->DrawClone("A5");
   HFE_2TeV_stat->DrawClone("P same");
   Spectrum2TeVSyst->DrawClone("2same");
   Spectrum2TeVStat->DrawCopy("Esame");

   // 5.02 TeV
   TFile* HFE5TeV = TFile::Open(file2.Data());
   TH1D* Spectrum5TeVStat = (TH1D*) HFE5TeV->GetObjectChecked("hfespectrum","TH1D");
   setOPT_hists(Spectrum5TeVStat,pTLabel, yLable,510,20,1, kRed);
   Spectrum5TeVStat->SetTitle("");
   Spectrum5TeVStat->SetName("Spectrum5TeVStat");

   TGraphAsymmErrors* Spectrum5TeVSyst = (TGraphAsymmErrors*) HFE5TeV->GetObjectChecked("hfespectrumSys","TGraphAsymmErrors");
   setOPT_graph(Spectrum5TeVSyst,pTLabel, yLable,510,0,0.5, kRed);
   Spectrum5TeVSyst->SetTitle("");
   Spectrum5TeVSyst->SetFillStyle(0);
   Spectrum5TeVSyst->SetName("Spectrum5TeVSyst");

   // 7 TeV
   TFile* HFE7TeV = TFile::Open(file3.Data());
   TH1D* Spectrum7TeVStat = (TH1D*) HFE7TeV->GetObjectChecked("HFEspectrum_Stat","TH1D");
   setOPT_hists(Spectrum7TeVStat,pTLabel, yLable,510,20,1);
   Spectrum7TeVStat->SetTitle("");
   Spectrum7TeVStat->SetName("Spectrum7TeVStat");

   TGraphErrors* Spectrum7TeVSyst = (TGraphErrors*) HFE7TeV->GetObjectChecked("HFEspectrum_Syst","TGraphErrors");
   setOPT_graph(Spectrum7TeVSyst,pTLabel, yLable,510,0,0.5);
   Spectrum7TeVSyst->SetTitle("");
   Spectrum7TeVSyst->SetFillStyle(0);
   Spectrum7TeVSyst->SetName("Spectrum7TeVSyst");


   TGraphErrors* gSpectrum7TeVStat = new TGraphErrors(Spectrum7TeVStat);
   gSpectrum7TeVStat->RemovePoint(0);
   gSpectrum7TeVStat->RemovePoint(0);
   gSpectrum7TeVStat->RemovePoint(0);
   gSpectrum7TeVStat->RemovePoint(0);
   gSpectrum7TeVStat->RemovePoint(0);

   Int_t PointToSwitch7TeV = 18;
   Double_t x2,y2,ex2,ey2;
   for (int i = 18; i< HFE_7TeV_syst->GetN(); i++) {
      HFE_7TeV_syst->GetPoint(i,x2,y2);
      ex2 = HFE_7TeV_syst->GetErrorX(i);
      ey2 = HFE_7TeV_syst->GetErrorY(i);
      Spectrum7TeVSyst->SetPoint(PointToSwitch7TeV,x2,y2);
      Spectrum7TeVSyst->SetPointError(PointToSwitch7TeV,ex2,ey2);

      gSpectrum7TeVStat->SetPoint(PointToSwitch7TeV,x2,y2);
      gSpectrum7TeVStat->SetPointError(PointToSwitch7TeV,ex,HFE_7TeV_stat->GetErrorY(i));

      PointToSwitch7TeV++;
   }

   Spectrum7TeVStat = (TH1D*) MakeHistogram_7TeV(gSpectrum7TeVStat);

   TCanvas *cHFE_7TeV = new TCanvas("cHFE_7TeV","HFE @ 7TeV");
   cHFE_7TeV->SetLogy();
   HFE_7TeV_syst->SetFillColor(0);
   HFE_7TeV_syst->SetFillStyle(0);
   HFE_7TeV_syst->DrawClone("A5");
   HFE_7TeV_stat->DrawClone("P same");
	Spectrum7TeVSyst->DrawClone("2same");
   Spectrum7TeVStat->DrawCopy("Esame");

   // 13 TeV
   TFile* HFE13TeV = TFile::Open(file4.Data());
   TH1D* Spectrum13TeVStat = (TH1D*) HFE13TeV->GetObjectChecked("HFECrossSec","TH1F");
   setOPT_hists(Spectrum13TeVStat,pTLabel, yLable,510,20,1, kGreen-3);
   Spectrum13TeVStat->SetTitle("");
   Spectrum13TeVStat->SetName("Spectrum13TeVStat");

   TGraphErrors* Spectrum13TeVSyst = (TGraphErrors*) HFE13TeV->GetObjectChecked("HFECrossSecSyst","TGraphErrors");
   setOPT_graph(Spectrum13TeVSyst,pTLabel, yLable,510,0,0.5, kGreen -3);
   Spectrum13TeVSyst->SetTitle("");
   Spectrum13TeVSyst->SetFillStyle(0);
   Spectrum13TeVSyst->SetName("Spectrum13TeVSyst");

   TCanvas* c1 = new TCanvas("c1","Spectra");
   gPad->SetTickx();
   gPad->SetTicky();
   gPad->SetLogy();

   TLegend* leg = plotLegend("right_top",LegendTitle, 0.7,0.6,0.02,-0.03);
   leg->SetFillStyle(0);
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->AddEntry(Spectrum2TeVStat,Legend2TeV,"lp");
   leg->AddEntry(Spectrum5TeVStat,Legend5TeV,"lp");
   leg->AddEntry(Spectrum7TeVStat,Legend7TeV,"lp");
   leg->AddEntry(Spectrum13TeVStat,Legend13TeV,"lp");
   leg->AddEntry((TObject*)0,WorkInProgress,"");

   TH1D* Axis = new TH1D("", "", 1000,minpT,maxpT);
   setOPT_hists(Axis,pTLabel, yLable,510,20,1);
   Axis->GetXaxis()->SetRangeUser(0.41,9);
   Axis->GetYaxis()->SetRangeUser(7e-6,0.2);
   Axis->GetXaxis()->SetMoreLogLabels();
   Axis->GetXaxis()->SetNoExponent();
   Axis->GetXaxis()->SetTitleOffset(1.);

   Axis->DrawCopy("");
   Spectrum2TeVStat->DrawCopy("same");
   Spectrum2TeVSyst->Draw("2 same");

   Spectrum5TeVStat->DrawCopy("same");
   Spectrum5TeVSyst->Draw("2 same");

   Spectrum7TeVStat->DrawCopy("same");
   Spectrum7TeVSyst->Draw("2 same");

   Spectrum13TeVStat->DrawCopy("same");
   Spectrum13TeVSyst->Draw("2 same");

   leg->Draw();
   gPad->Update();

// FONLL
   TString Objectname = "Graph";

   TFile File1 ("FONLL/FONLLRatio_13_7.root");
   TGraphAsymmErrors* FONLLRatio_13_7 = (TGraphAsymmErrors*) File1.GetObjectChecked(Objectname,"TGraphAsymmErrors");
   FONLLRatio_13_7->SetName("FONLLRatio_13_7");

   TFile File2 ("FONLL/FONLLRatio_13_5.root");
   TGraphAsymmErrors* FONLLRatio_13_5 = (TGraphAsymmErrors*) File2.GetObjectChecked(Objectname,"TGraphAsymmErrors");
   FONLLRatio_13_5->SetName("FONLLRatio_13_5");

   TFile File4 ("FONLL/FONLLRatio_7_5.root");
   TGraphAsymmErrors* FONLLRatio_7_5 = (TGraphAsymmErrors*) File4.GetObjectChecked(Objectname,"TGraphAsymmErrors");
   FONLLRatio_7_5->SetName("FONLLRatio_7_5");

   TFile File3 ("FONLL/FONLLRatio_13_2.root");
   TGraphAsymmErrors* FONLLRatio_13_2 = (TGraphAsymmErrors*) File3.GetObjectChecked(Objectname,"TGraphAsymmErrors");
   FONLLRatio_13_2->SetName("FONLLRatio_13_2");

   TFile File5 ("FONLL/FONLLRatio_7_2.root");
   TGraphAsymmErrors* FONLLRatio_7_2 = (TGraphAsymmErrors*) File5.GetObjectChecked(Objectname,"TGraphAsymmErrors");
   FONLLRatio_7_2->SetName("FONLLRatio_7_2");

   TFile File6 ("FONLL/FONLLRatio_5_2.root");
   TGraphAsymmErrors* FONLLRatio_5_2 = (TGraphAsymmErrors*) File6.GetObjectChecked(Objectname,"TGraphAsymmErrors");
   FONLLRatio_5_2->SetName("FONLLRatio_5_2");

   FONLLRatio_13_2 = RebinFONLL2TeV(FONLLRatio_13_2);
   FONLLRatio_7_2 = RebinFONLL2TeV(FONLLRatio_7_2);
   FONLLRatio_5_2 = RebinFONLL2TeV(FONLLRatio_5_2);

	// converting systematic graph to histogram
   TH1D* hSpectrum2TeVSyst = (TH1D*) MakeHistogram_2TeV(Spectrum2TeVSyst);
   TH1D* hSpectrum5TeVSyst = (TH1D*) MakeHistogram_5TeV(Spectrum5TeVSyst);
   TH1D* hSpectrum7TeVSyst = (TH1D*) MakeHistogram_7TeV(Spectrum7TeVSyst);
   TH1D* hSpectrum13TeVSyst = (TH1D*) MakeHistogram(Spectrum13TeVSyst);

   // Ratio 5/2
   TCanvas* c_5_2 = new TCanvas("c_5_2","Ratio 5 to 2");
   gPad->SetTicks();
   gPad->SetLogx();

   TLegend* leg_5_2 = plotLegend("left_top",LegendTitle, 0.7,0.8,0.025, -0.05);
   leg_5_2->SetFillStyle(0);
   leg_5_2->SetBorderSize(0);
   leg_5_2->SetTextSize(legTextSize);
   leg_5_2->AddEntry((TObject*)0,Measurement,"");

   setOPT_hists(Axis,pTLabel, yLabelRatio,510,20,1);
   // Draw ratios
   Axis->GetYaxis()->SetRangeUser(0,4);
   Axis->DrawCopy("");

   TLatex thiswork;
   thiswork.SetTextSize(0.04);

   // Stat
   TH1D* hRatio_5_2_Stat = (TH1D*) RebinToData5(Spectrum5TeVStat);
   hRatio_5_2_Stat->Divide(hRatio_5_2_Stat, RebinToData5(Spectrum2TeVStat), 1, 1);
   setOPT_hists(hRatio_5_2_Stat,pTLabel, yLabelRatio,510,20,1);
   hRatio_5_2_Stat->SetName("hRatio_5_2_Stat");

   leg_5_2->AddEntry((TObject*)0, "#kern[-0.09]{#bf{pp, }" + Legend5TeV + " / " + Legend2TeV + "}","");
   leg_5_2->AddEntry((TObject*)0,"#kern[-0.115]{#bf{#sqrt{#it{s}} = 2.76 TeV #scale[0.7]{(JHEP 10 (2018) 061)}}}","");
   leg_5_2->AddEntry((TObject*)0,"#kern[-0.115]{#bf{#sqrt{#it{s}} = 5.02 TeV #scale[0.7]{(arXiv:1910.09110)}}}","");
   leg_5_2->AddEntry(hRatio_5_2_Stat, "#bf{Data}","p");
   leg_5_2->AddEntry(FONLLRatio_5_2,LabelFONLL,"f");
   // Syst
   TH1D* hRatio_5_2_Syst = (TH1D*) RebinToData5(hSpectrum5TeVSyst);
   hRatio_5_2_Syst->Divide(hRatio_5_2_Syst, RebinToData5(hSpectrum2TeVSyst), 1, 1);
   setOPT_hists(hRatio_5_2_Syst,pTLabel, yLabelRatio,510,20,1);
   hRatio_5_2_Syst->SetFillStyle(0);
   hRatio_5_2_Syst->SetName("hRatio_5_2_Syst");

   FONLLRatio_5_2->Draw("5same");
   hRatio_5_2_Syst->DrawCopy("E2same");
   TGraphErrors* GraphRatio_5_2_Stat = new TGraphErrors(hRatio_5_2_Stat);
   for(int i = 0; i < GraphRatio_5_2_Stat->GetN(); i++){
      GraphRatio_5_2_Stat->SetPointError(i,0,GraphRatio_5_2_Stat->GetErrorY(i));
   }
   GraphRatio_5_2_Stat->Draw("samepZ");
   leg_5_2->Draw("same");
   thiswork.DrawLatex(0.5,0.2, Form(NormUncText.Data(),TMath::Sqrt(NormUnc_5TeV*NormUnc_5TeV + NormUnc_2TeV*NormUnc_2TeV)));
   gPad->Update();
   c_5_2->SaveAs("Ratio_5_2_Log.pdf");

   // Ratio 7/2
   TCanvas* c_7_2 = new TCanvas("c_7_2","Ratio 7 to 2");
   gPad->SetTicks();
	gPad->SetLogx();

   TLegend* leg_7_2 = plotLegend("left_top",LegendTitle, 0.7,1.1,0.025, -0.05);
   leg_7_2->SetFillStyle(0);
   leg_7_2->SetBorderSize(0);
   leg_7_2->SetTextSize(legTextSize);
   leg_7_2->AddEntry((TObject*)0,Measurement,"");

   // Draw ratios
   Axis->GetYaxis()->SetRangeUser(0,8);
   Axis->DrawCopy("");
   // Low pT
   // Stat
   TH1D* hRatio_7_2_Stat = (TH1D*) RebinToData7(Spectrum7TeVStat);
   hRatio_7_2_Stat->Divide(hRatio_7_2_Stat, RebinToData7(Spectrum2TeVStat), 1, 1);
   setOPT_hists(hRatio_7_2_Stat,pTLabel, yLabelRatio,510,20,1);
   hRatio_7_2_Stat->SetName("hRatio_7_2_Stat");
	hRatio_7_2_Stat->GetXaxis()->SetRangeUser(0.5,4.);
   // Syst
   TH1D* hRatio_7_2_Syst = (TH1D*) RebinToData7(hSpectrum7TeVSyst);
   hRatio_7_2_Syst->Divide(hRatio_7_2_Syst, RebinToData7(hSpectrum2TeVSyst), 1, 1);
   setOPT_hists(hRatio_7_2_Syst,pTLabel, yLabelRatio,510,20,1);
   hRatio_7_2_Syst->SetFillStyle(0);
   hRatio_7_2_Syst->SetName("hRatio_7_2_Syst");
   hRatio_7_2_Syst->GetXaxis()->SetRangeUser(0.5,4.);
	// High pT
   //stat
   TH1D* hHFE_7TeV_stat =  (TH1D*) MakeHistogram_7TeV(HFE_7TeV_stat);
   TH1D* hRatio_7_2_Stat2 = (TH1D*) RebinToData7(hHFE_7TeV_stat);
   hRatio_7_2_Stat2->Divide(hRatio_7_2_Stat2, RebinToData7(Spectrum2TeVStat), 1, 1);
   setOPT_hists(hRatio_7_2_Stat2,pTLabel, yLabelRatio,510,24,1);
   hRatio_7_2_Stat2->SetName("hRatio_7_2_Stat2");
   hRatio_7_2_Stat2->GetXaxis()->SetRangeUser(4.,8.);
   //syst
   TH1D* hHFE_7TeV_syst =  (TH1D*) MakeHistogram_7TeV(HFE_7TeV_syst);
   TH1D* hRatio_7_2_Syst2 = (TH1D*) RebinToData7(hHFE_7TeV_syst);
   hRatio_7_2_Syst2->Divide(hRatio_7_2_Syst2, RebinToData7(hSpectrum2TeVSyst), 1, 1);
   setOPT_hists(hRatio_7_2_Syst2,pTLabel, yLabelRatio,510,24,1);
   hRatio_7_2_Syst2->SetFillStyle(0);
   hRatio_7_2_Syst2->SetName("hRatio_7_2_Syst2");
   hRatio_7_2_Syst2->GetXaxis()->SetRangeUser(4.,8.);

   leg_7_2->AddEntry((TObject*)0, "#kern[-0.09]{#bf{pp, }" + Legend7TeV + " / " + Legend2TeV + "}","");
   leg_7_2->AddEntry((TObject*)0,"#kern[-0.115]{#bf{#sqrt{#it{s}} = 2.76 TeV #scale[0.7]{(JHEP 10 (2018) 061)}}}","");
   leg_7_2->AddEntry(hRatio_7_2_Stat,"#bf{Data, #sqrt{#it{s}} = 7 TeV |#it{y}| < 0.8}","p");
   leg_7_2->AddEntry(hRatio_7_2_Stat2,"#bf{Data, #sqrt{#it{s}} = 7 TeV |#it{y}| < 0.5}","p");
   leg_7_2->AddEntry((TObject*)0,"#kern[-0.15]{#bf{#scale[0.7]{Phys.Rev. D86 (2012) 112007}}}","");
   leg_7_2->AddEntry(FONLLRatio_7_2,LabelFONLL,"f");

   FONLLRatio_7_2->Draw("5same");
   hRatio_7_2_Syst->DrawCopy("E2same");
   hRatio_7_2_Syst2->DrawCopy("E2same");
   hRatio_7_2_Stat->DrawCopy("same EX0");
   hRatio_7_2_Stat2->DrawCopy("same EX0");
//   leg_7_2->AddEntry((TObject*)0,WorkInProgress,"");
   leg_7_2->Draw("same");
   thiswork.DrawLatex(0.5,0.4, Form(NormUncText.Data(),TMath::Sqrt(NormUnc_7TeV*NormUnc_7TeV + NormUnc_2TeV*NormUnc_2TeV)));
   gPad->Update();
   c_7_2->SaveAs("Ratio_7_2_Log.eps");

   // Ratio 13/2
   TCanvas* c_13_2 = new TCanvas("c_13_2","Ratio 13 to 2");
   gPad->SetTicks();
   gPad->SetLogx();

   TLegend* leg_13_2 = plotLegend("left_top",LegendTitle, 0.7,0.8,0.025, -0.05);
   leg_13_2->SetFillStyle(0);
   leg_13_2->SetBorderSize(0);
   leg_13_2->SetTextSize(legTextSize);
   leg_13_2->AddEntry((TObject*)0,Measurement,"");

   // Draw ratios
   Axis->GetYaxis()->SetRangeUser(0,8);
   Axis->DrawCopy("");
   // Stat
   TH1D* hRatio_13_2_Stat = (TH1D*) RebinToData(Spectrum13TeVStat);
   hRatio_13_2_Stat->Divide(hRatio_13_2_Stat, RebinToData(Spectrum2TeVStat), 1, 1);
   setOPT_hists(hRatio_13_2_Stat,pTLabel, yLabelRatio,510,20,1);
   hRatio_13_2_Stat->SetName("hRatio_13_2_Stat");

   leg_13_2->AddEntry((TObject*)0, "#kern[-0.09]{#bf{pp, }" + Legend13TeV + " / " + Legend2TeV + "}","");
   leg_13_2->AddEntry((TObject*)0,"#kern[-0.115]{#bf{#sqrt{#it{s}} = 2.76 TeV #scale[0.7]{(JHEP 10 (2018) 061)}}}","");
   leg_13_2->AddEntry(hRatio_13_2_Stat, "#bf{Data}","p");
   leg_13_2->AddEntry(FONLLRatio_13_2,LabelFONLL,"f");
   // Syst
   TH1D* hRatio_13_2_Syst = (TH1D*) RebinToData(hSpectrum13TeVSyst);
   hRatio_13_2_Syst->Divide(hRatio_13_2_Syst, RebinToData(hSpectrum2TeVSyst), 1, 1);
   setOPT_hists(hRatio_13_2_Syst,pTLabel, yLabelRatio,510,20,1);
   hRatio_13_2_Syst->SetFillStyle(0);
   hRatio_13_2_Syst->SetName("hRatio_7_2_Syst");

   FONLLRatio_13_2->Draw("5same");
   hRatio_13_2_Syst->DrawCopy("E2same");
   TGraphErrors* GraphRatio_13_2_Stat = new TGraphErrors(hRatio_13_2_Stat);
   for(int i = 0; i < GraphRatio_13_2_Stat->GetN(); i++){
      GraphRatio_13_2_Stat->SetPointError(i,0,GraphRatio_13_2_Stat->GetErrorY(i));
   }
   GraphRatio_13_2_Stat->Draw("samepZ");
//   leg_13_2->AddEntry((TObject*)0,WorkInProgress,"");
   leg_13_2->Draw("same");
   thiswork.DrawLatex(0.5,0.4, Form(NormUncText.Data(),TMath::Sqrt(NormUnc_13TeV*NormUnc_13TeV + NormUnc_2TeV*NormUnc_2TeV)));
   gPad->Update();
   c_13_2->SaveAs("Ratio_13_2_Log.eps");

   Spectrum5TeVStat = (TH1D*) RebinToData5(Spectrum5TeVStat);
   Spectrum7TeVStat = (TH1D*) RebinToData5(Spectrum7TeVStat);
   Spectrum13TeVStat = (TH1D*) Rebin(Spectrum13TeVStat);

   // Ratio 13/5
   TCanvas* c_13_5 = new TCanvas("c_13_5","Ratio 13 to 5");
   gPad->SetTicks();
   gPad->SetLogx();

   TLegend* leg_13_5 = plotLegend("left_top",LegendTitle, 0.7,0.8,0.025, -0.05);
   leg_13_5->SetFillStyle(0);
   leg_13_5->SetBorderSize(0);
   leg_13_5->SetTextSize(legTextSize);
   leg_13_5->AddEntry((TObject*)0,Measurement,"");

   // Draw ratios
   Axis->GetYaxis()->SetRangeUser(0,6);
   Axis->DrawCopy("");
   // Stat
   TH1D* hRatio_13_5_Stat = (TH1D*) RebinToData(Spectrum13TeVStat);
   hRatio_13_5_Stat->Divide(hRatio_13_5_Stat, RebinToData(Spectrum5TeVStat), 1, 1);
   setOPT_hists(hRatio_13_5_Stat,pTLabel, yLabelRatio,510,20,1);
   hRatio_13_5_Stat->SetName("hRatio_13_5_Stat");

   TGraphErrors* GraphRatio_13_5_Stat = new TGraphErrors(hRatio_13_5_Stat);
   for(int i = 0; i < GraphRatio_13_5_Stat->GetN(); i++){
      GraphRatio_13_5_Stat->SetPointError(i,0,GraphRatio_13_5_Stat->GetErrorY(i));
   }

   leg_13_5->AddEntry((TObject*)0, "#kern[-0.1]{#bf{pp, }" + Legend13TeV + " / " + Legend5TeV + "}","");
   leg_13_5->AddEntry(hRatio_13_5_Stat, "#bf{Data}","p");
   leg_13_5->AddEntry(FONLLRatio_13_5,LabelFONLL,"f");

   // Syst
   TH1D* hRatio_13_5_Syst = (TH1D*) RebinToData(hSpectrum13TeVSyst);
   hRatio_13_5_Syst->Divide(hRatio_13_5_Syst, RebinToData(hSpectrum5TeVSyst), 1, 1);
   setOPT_hists(hRatio_13_5_Syst,pTLabel, yLabelRatio,510,20,1);
   hRatio_13_5_Syst->SetFillStyle(0);
   hRatio_13_5_Syst->SetName("hRatio_13_5_Syst");

   FONLLRatio_13_5->Draw("5same");
   hRatio_13_5_Syst->DrawCopy("E2same");
   GraphRatio_13_5_Stat->Draw("samepZ");
//   leg_13_5->AddEntry((TObject*)0,WorkInProgress,"");
   leg_13_5->Draw("same");
   thiswork.DrawLatex(0.5,0.3, Form(NormUncText.Data(),TMath::Sqrt(NormUnc_13TeV*NormUnc_13TeV + NormUnc_5TeV*NormUnc_5TeV)));
   gPad->Update();
   c_13_5->SaveAs("Ratio_13_5_Log.pdf");

   // Ratio 13/7
   TCanvas* c_13_7 = new TCanvas("c_13_7","Ratio 13 to 7");
   gPad->SetTicks();
   gPad->SetLogx();

   TLegend* leg_13_7 = plotLegend("left_top",LegendTitle, 0.7,0.8,0.025, -0.05);
   leg_13_7->SetFillStyle(0);
   leg_13_7->SetBorderSize(0);
   leg_13_7->SetTextSize(legTextSize);
   leg_13_7->AddEntry((TObject*)0,Measurement,"");

   // Draw ratios
   Axis->GetYaxis()->SetRangeUser(0,8);
   Axis->DrawCopy("");
   // Stat
   TH1D* hRatio_13_7_Stat = (TH1D*) RebinToData(Spectrum13TeVStat);
   hRatio_13_7_Stat->Divide(hRatio_13_7_Stat, RebinToData(Spectrum7TeVStat), 1, 1);
   setOPT_hists(hRatio_13_7_Stat,pTLabel, yLabelRatio,510,20,1);
   hRatio_13_7_Stat->SetName("hRatio_13_7_Stat");

   TGraphErrors* GraphRatio_13_7_Stat = new TGraphErrors(hRatio_13_7_Stat);
   for(int i = 0; i < GraphRatio_13_7_Stat->GetN(); i++){
      GraphRatio_13_7_Stat->SetPointError(i,0,GraphRatio_13_7_Stat->GetErrorY(i));
   }

   leg_13_7->AddEntry((TObject*)0, "#kern[-0.1]{#bf{pp, }" + Legend13TeV + " / " + Legend7TeV + "}","");
   leg_13_7->AddEntry(hRatio_13_7_Stat, "#bf{Data}","p");
   leg_13_7->AddEntry(FONLLRatio_13_7,LabelFONLL,"f");
   // Syst
   TH1D* hRatio_13_7_Syst = (TH1D*) RebinToData(hSpectrum13TeVSyst);
   hRatio_13_7_Syst->Divide(hRatio_13_7_Syst, RebinToData(hSpectrum7TeVSyst), 1, 1);
   setOPT_hists(hRatio_13_7_Syst,pTLabel, yLabelRatio,510,20,1);
   hRatio_13_7_Syst->SetFillStyle(0);
   hRatio_13_7_Syst->SetName("hRatio_13_7_Syst");

   FONLLRatio_13_7->Draw("5same");
   hRatio_13_7_Syst->DrawCopy("E2same");
   GraphRatio_13_7_Stat->Draw("samepZ");
//   leg_13_7->AddEntry((TObject*)0,WorkInProgress,"");
   leg_13_7->Draw("same");
   thiswork.DrawLatex(0.5,0.4, Form(NormUncText.Data(),TMath::Sqrt(NormUnc_13TeV*NormUnc_13TeV + NormUnc_7TeV*NormUnc_7TeV)));
   gPad->Update();
   c_13_7->SaveAs("Ratio_13_7_Log.eps");

   // Ratio 7/5
   TCanvas* c_7_5 = new TCanvas("c_7_5","Ratio 7 to 5");
   gPad->SetTicks();
   gPad->SetLogx();

   TLegend* leg_7_5 = plotLegend("left_top",LegendTitle, 0.7,1.0,0.025, -0.05);
   leg_7_5->SetFillStyle(0);
   leg_7_5->SetBorderSize(0);
   leg_7_5->SetTextSize(legTextSize);
   leg_7_5->AddEntry((TObject*)0,Measurement,"");

   // Draw ratios
   Axis->GetYaxis()->SetRangeUser(0,4);
   Axis->DrawCopy("");
   // Stat
   TH1D* hRatio_7_5_Stat = (TH1D*) Spectrum7TeVStat->Clone();
   hRatio_7_5_Stat->Divide(hRatio_7_5_Stat, Spectrum5TeVStat, 1, 1);
   setOPT_hists(hRatio_7_5_Stat,pTLabel, yLabelRatio,510,20,1);
   hRatio_7_5_Stat->SetName("hRatio_7_5_Stat");
   hRatio_7_5_Stat->GetXaxis()->SetRangeUser(0.5,4);
   // Syst
   TH1D* hRatio_7_5_Syst = (TH1D*) RebinToData5(hSpectrum7TeVSyst);
   hRatio_7_5_Syst->Divide(hRatio_7_5_Syst, RebinToData5(hSpectrum5TeVSyst), 1, 1);
   setOPT_hists(hRatio_7_5_Syst,pTLabel, yLabelRatio,510,20,1);
   hRatio_7_5_Syst->SetFillStyle(0);
   hRatio_7_5_Syst->SetName("hRatio_7_5_Syst");
   hRatio_7_5_Syst->GetXaxis()->SetRangeUser(0.5,4);

   // High pT
   //stat
   TH1D* hRatio_7_5_Stat2 = (TH1D*) RebinToData5(hHFE_7TeV_stat);
   hRatio_7_5_Stat2->Divide(hRatio_7_5_Stat2, RebinToData5(Spectrum5TeVStat), 1, 1);
   setOPT_hists(hRatio_7_5_Stat2,pTLabel, yLabelRatio,510,24,1);
   hRatio_7_5_Stat2->SetName("hRatio_7_5_Stat2");
   hRatio_7_5_Stat2->GetXaxis()->SetRangeUser(4.,8.);
   //syst
   TH1D* hRatio_7_5_Syst2 = (TH1D*) RebinToData5(hHFE_7TeV_syst);
   hRatio_7_5_Syst2->Divide(hRatio_7_5_Syst2, RebinToData5(hSpectrum5TeVSyst), 1, 1);
   setOPT_hists(hRatio_7_5_Syst2,pTLabel, yLabelRatio,510,24,1);
   hRatio_7_5_Syst2->SetFillStyle(0);
   hRatio_7_5_Syst2->SetName("hRatio_7_5_Syst2");
   hRatio_7_5_Syst2->GetXaxis()->SetRangeUser(4.,8.);

   leg_7_5->AddEntry((TObject*)0, "#kern[-0.09]{#bf{pp, }" + Legend7TeV + " / " + Legend5TeV + "}","");
   leg_7_5->AddEntry(hRatio_7_5_Stat,"#bf{Data, #sqrt{#it{s}} = 7 TeV |#it{y}| < 0.8}","p");
   leg_7_5->AddEntry(hRatio_7_5_Stat2,"#bf{Data, #sqrt{#it{s}} = 7 TeV |#it{y}| < 0.5}","p");
   leg_7_5->AddEntry((TObject*)0,"#kern[-0.15]{#bf{#scale[0.7]{Phys.Rev. D86 (2012) 112007}}}","");
   leg_7_5->AddEntry(FONLLRatio_7_5,LabelFONLL,"f");

   FONLLRatio_7_5->Draw("5same");
   hRatio_7_5_Syst->DrawCopy("E2same");
   hRatio_7_5_Syst2->DrawCopy("E2same");
   hRatio_7_5_Stat->DrawCopy("same EX0");
   hRatio_7_5_Stat2->DrawCopy("same EX0");
//   leg_7_5->AddEntry((TObject*)0,WorkInProgress,"");
   leg_7_5->Draw("same");
   thiswork.DrawLatex(0.5,0.2, Form(NormUncText.Data(),TMath::Sqrt(NormUnc_7TeV*NormUnc_7TeV + NormUnc_5TeV*NormUnc_5TeV)));
   gPad->Update();
   c_7_5->SaveAs("Ratio_7_5_Log.pdf");

   TFile *outf = new TFile("HFERatios.root","RECREATE");
   outf->cd();
   hRatio_5_2_Stat->Write();
   hRatio_7_2_Stat->Write();
   hRatio_13_2_Stat->Write();
   hRatio_13_5_Stat->Write();
   hRatio_13_7_Stat->Write();
   hRatio_7_5_Stat->Write();

   FONLLRatio_13_7->Write();
   FONLLRatio_13_5->Write();
   FONLLRatio_13_2->Write();
   FONLLRatio_7_5->Write();
   FONLLRatio_7_2->Write();
   FONLLRatio_5_2->Write();
   delete outf;

   // vertical stacking
   TString Measurement_vert = "#kern[-0.11]{#bf{c,b #rightarrow e, |#it{y}| < 0.8}}";

   TH1D* Axis_vert = new TH1D("", "", 1000,minpT,maxpT);
   setOPT_hists(Axis_vert,pTLabel, yLabelRatio,510,20,1);
   Axis_vert->GetXaxis()->SetMoreLogLabels();
   Axis_vert->GetXaxis()->SetNoExponent();
   Axis_vert->GetXaxis()->SetRangeUser(0.41,8.9);
   Axis_vert->GetYaxis()->SetRangeUser(0.1,8.4);

   Axis_vert->GetXaxis()->SetLabelSize(0.06);
   Axis_vert->GetXaxis()->SetLabelOffset(0.01);
   Axis_vert->GetXaxis()->SetTitleSize(0.07);
   Axis_vert->GetXaxis()->SetTitleOffset(1.2);

   Axis_vert->GetYaxis()->SetLabelSize(0.07);
   Axis_vert->GetYaxis()->SetLabelOffset(0.015);
   Axis_vert->GetYaxis()->SetTitleSize(0.06);
   Axis_vert->GetYaxis()->SetTitleOffset(1.1);

   thiswork.SetTextSize(0.05);
   TCanvas* cVertical = new TCanvas("cVertical","Cross sections",300,1000);
   TPad *pad5 = new TPad("pad1", "Pad for 2 TeV",0, 0.00, 1, 0.38, 0);
   TPad *pad4 = new TPad("pad1", "Pad for 5 TeV",0, 0.38, 1, 0.69, 0);
   TPad *pad3 = new TPad("pad2", "Pad for 7 TeV",0 ,0.69, 1, 1.00, 0);
   pad3->Draw();
   pad4->Draw();
   pad5->Draw();

   pad3->cd();
   pad3->SetTopMargin(0.003);
   pad3->SetBottomMargin(0);
   gPad->SetTicks();
   gPad->SetLogx();
   Axis_vert->DrawCopy("");

   TLegend* leg_5_2_vert = plotLegend("left_top",LegendTitle, 0.9,1.0,0.02, -0.05);
   leg_5_2_vert->SetFillStyle(0);
   leg_5_2_vert->SetBorderSize(0);
   leg_5_2_vert->SetTextSize(legTextSize+0.02);
   leg_5_2_vert->AddEntry((TObject*)0,Measurement_vert,"");
   leg_5_2_vert->AddEntry((TObject*)0, "#kern[-0.06]{#bf{pp, }" + Legend5TeV + " / " + Legend2TeV + "}","");
   leg_5_2_vert->AddEntry((TObject*)0,"#kern[-0.09]{#bf{#sqrt{#it{s}} = 2.76 TeV #scale[0.7]{(JHEP 10 (2018) 061)}}}","");
   leg_5_2_vert->AddEntry((TObject*)0,"#kern[-0.09]{#bf{#sqrt{#it{s}} = 5.02 TeV #scale[0.7]{(arXiv:1910.09110)}}}","");
   leg_5_2_vert->AddEntry(GraphRatio_5_2_Stat,"#bf{Data}","p");
   leg_5_2_vert->AddEntry(FONLLRatio_5_2,LabelFONLL,"f");

   FONLLRatio_5_2->Draw("5same");
   hRatio_5_2_Syst->DrawCopy("E2same");
   GraphRatio_5_2_Stat->Draw("pZsame");
   leg_5_2_vert->Draw("same");
   thiswork.DrawLatex(0.5,0.45, Form(NormUncText.Data(),TMath::Sqrt(NormUnc_5TeV*NormUnc_5TeV + NormUnc_2TeV*NormUnc_2TeV)));
   gPad->Update();

   pad4->cd();
   pad4->SetTopMargin(0);
   pad4->SetBottomMargin(0);
   gPad->SetTicks();
   gPad->SetLogx();
   Axis_vert->DrawCopy("");

   TLegend* leg_7_2_vert = plotLegend("left_top","", 0.9,0.7,0.02, -0.04);
   leg_7_2_vert->SetFillStyle(0);
   leg_7_2_vert->SetBorderSize(0);
   leg_7_2_vert->SetTextSize(legTextSize+0.02);
   leg_7_2_vert->AddEntry((TObject*)0, "#kern[-0.06]{#bf{pp, }" + Legend7TeV + " / " + Legend2TeV + "}","");
   leg_7_2_vert->AddEntry(hRatio_7_2_Stat,"#bf{Data, #sqrt{#it{s}} = 7 TeV |#it{y}| < 0.8}","p");
   leg_7_2_vert->AddEntry(hRatio_7_2_Stat2,"#bf{Data, #sqrt{#it{s}} = 7 TeV |#it{y}| < 0.5}","p");
   leg_7_2_vert->AddEntry((TObject*)0,"#kern[-0.08]{#bf{#scale[0.7]{Phys.Rev. D86 (2012) 112007}}}","");

   FONLLRatio_7_2->Draw("5same");
   hRatio_7_2_Syst->DrawCopy("E2same");
   hRatio_7_2_Syst2->DrawCopy("E2same");
   hRatio_7_2_Stat2->DrawCopy("sameEX0");
   hRatio_7_2_Stat->DrawCopy("sameEX0");
   leg_7_2_vert->Draw("same");
   thiswork.DrawLatex(0.5,0.45, Form(NormUncText.Data(),TMath::Sqrt(NormUnc_7TeV*NormUnc_7TeV + NormUnc_2TeV*NormUnc_2TeV)));
   gPad->Update();

   pad5->cd();
   Axis_vert->GetYaxis()->SetLabelSize(0.06);
   Axis_vert->GetYaxis()->SetLabelOffset(0.02);
   Axis_vert->GetYaxis()->SetTitleSize(0.05);
   Axis_vert->GetYaxis()->SetTitleOffset(1.3);

   thiswork.SetTextSize(0.04);
   pad5->SetTopMargin(0);
   pad5->SetBottomMargin(0.225);
   gPad->SetTicks();
   gPad->SetLogx();
   Axis_vert->DrawCopy("");

   TLegend* leg_13_2_vert = plotLegend("left_top","", 0.9,0.15,0.02, -0.05);
   leg_13_2_vert->SetFillStyle(0);
   leg_13_2_vert->SetBorderSize(0);
   leg_13_2_vert->SetTextSize(legTextSize+0.015);
   leg_13_2_vert->AddEntry((TObject*)0, "#kern[-0.07]{#bf{pp, }" + Legend13TeV + " / " + Legend2TeV + "}","");

   FONLLRatio_13_2->Draw("5same");
   hRatio_13_2_Syst->DrawCopy("E2same");
   GraphRatio_13_2_Stat->Draw("pZsame");
   leg_13_2_vert->Draw("same");
   thiswork.DrawLatex(0.5,0.45, Form(NormUncText.Data(),TMath::Sqrt(NormUnc_13TeV*NormUnc_13TeV + NormUnc_2TeV*NormUnc_2TeV)));

   cVertical->SaveAs("Ratios_Vertical.eps");

   // horizontal stacking
   TString Measurement_hor = "#kern[-0.13]{#bf{c,b #rightarrow e, |#it{y}| < 0.8}}";

   setOPT_graph(GraphRatio_5_2_Stat,pTLabel, yLabelRatio,510,20,1.5);
	setOPT_hists(hRatio_7_2_Stat,pTLabel, yLabelRatio,510,20,1.5);
   setOPT_hists(hRatio_7_2_Stat2,pTLabel, yLabelRatio,510,24,1.5);
   setOPT_hists(hRatio_7_2_Syst2,pTLabel, yLabelRatio,510,24,1.5);
   setOPT_graph(GraphRatio_13_2_Stat,pTLabel, yLabelRatio,510,20,1.5);

   TH1D* Axis_hor = new TH1D("", "", 1000,minpT,maxpT);
   setOPT_hists(Axis_hor,pTLabel, yLabelRatio,510,20,1);
   Axis_hor->GetXaxis()->SetMoreLogLabels();
   Axis_hor->GetXaxis()->SetNoExponent();
   Axis_hor->GetXaxis()->SetRangeUser(0.41,8.9);
   Axis_hor->GetYaxis()->SetRangeUser(0,8);

   Axis_hor->GetXaxis()->SetLabelOffset(0.009);
   Axis_hor->GetXaxis()->SetTitleOffset(1.1);
   Axis_hor->GetYaxis()->SetLabelOffset(0.01);

   thiswork.SetTextSize(0.0325);
   TCanvas* cHorizontal = new TCanvas("cHorizontal","Cross sections",2000,600);
   TPad *pad0 = new TPad("pad1", "Pad for 2 TeV",0.0, 0, 0.38,1.0,0);
   TPad *pad1 = new TPad("pad1", "Pad for 5 TeV",0.38, 0,0.69,1.0,0);
   TPad *pad2 = new TPad("pad2", "Pad for 7 TeV",0.69, 0,1,1.0,0);
   pad0->Draw();
   pad1->Draw();
   pad2->Draw();

   pad0->cd();
   pad0->SetRightMargin(0);
   pad0->SetLeftMargin(0.2);
   pad0->SetBottomMargin(0.2);
   gPad->SetTicks();
   gPad->SetLogx();
   Axis_hor->DrawCopy("");

   TLegend* leg_5_2_hor = plotLegend("left_top",LegendTitle, 0.8,0.8,0.025, -0.05);
   leg_5_2_hor->SetFillStyle(0);
   leg_5_2_hor->SetBorderSize(0);
   leg_5_2_hor->SetTextSize(legTextSize+0.005);
   leg_5_2_hor->AddEntry((TObject*)0,Measurement_hor,"");
   leg_5_2_hor->AddEntry((TObject*)0, "#kern[-0.06]{#bf{pp, }" + Legend5TeV + " / " + Legend2TeV + "}","");
   leg_5_2_hor->AddEntry((TObject*)0,"#kern[-0.095]{#bf{#sqrt{#it{s}} = 2.76 TeV #scale[0.7]{(JHEP 10 (2018) 061)}}}","");
   leg_5_2_hor->AddEntry((TObject*)0,"#kern[-0.095]{#bf{#sqrt{#it{s}} = 5.02 TeV #scale[0.7]{(arXiv:1910.09110)}}}","");
   leg_5_2_hor->AddEntry(GraphRatio_5_2_Stat,"#bf{Data}","p");
   leg_5_2_hor->AddEntry(FONLLRatio_5_2,LabelFONLL,"f");

   FONLLRatio_5_2->Draw("5same");
   hRatio_5_2_Syst->DrawCopy("E2same");
   GraphRatio_5_2_Stat->Draw("pZsame");
   leg_5_2_hor->Draw("same");
   thiswork.DrawLatex(0.5,0.4, Form(NormUncText.Data(),TMath::Sqrt(NormUnc_5TeV*NormUnc_5TeV + NormUnc_2TeV*NormUnc_2TeV)));
   gPad->Update();

   Axis_hor->GetXaxis()->SetTitleOffset(0.9);
   Axis_hor->GetXaxis()->SetTitleSize(0.075);
   Axis_hor->GetXaxis()->SetLabelOffset(0.00001);
   Axis_hor->GetXaxis()->SetLabelSize(0.06);

   Axis_hor->GetYaxis()->SetLabelOffset(0.01);
   Axis_hor->GetYaxis()->SetLabelOffset(0.01);
   pad1->cd();
   pad1->SetRightMargin(0.);
   pad1->SetLeftMargin(0.);
   pad1->SetBottomMargin(0.2);
   gPad->SetTicks();
   gPad->SetLogx();
   Axis_hor->DrawCopy("");
   thiswork.SetTextSize(0.04);

   TLegend* leg_7_2_hor = plotLegend("left_top","", 0.8,0.6,0.05, -0.05);
   leg_7_2_hor->SetFillStyle(0);
   leg_7_2_hor->SetBorderSize(0);
   leg_7_2_hor->SetTextSize(legTextSize+0.015);
   leg_7_2_hor->AddEntry((TObject*)0, "#kern[-0.06]{#bf{pp, }" + Legend7TeV + " / " + Legend2TeV + "}","");
   leg_7_2_hor->AddEntry(hRatio_7_2_Stat,"#bf{Data, #sqrt{#it{s}} = 7 TeV |#it{y}| < 0.8}","p");
   leg_7_2_hor->AddEntry(hRatio_7_2_Stat2,"#bf{Data, #sqrt{#it{s}} = 7 TeV |#it{y}| < 0.5}","p");
   leg_7_2_hor->AddEntry((TObject*)0,"#kern[-0.1]{#bf{#scale[0.7]{Phys.Rev. D86 (2012) 112007}}}","");

   FONLLRatio_7_2->Draw("5same");
   hRatio_7_2_Syst->DrawCopy("E2same");
   hRatio_7_2_Syst2->DrawCopy("E2same");
   hRatio_7_2_Stat2->DrawCopy("sameEX0");
   hRatio_7_2_Stat->DrawCopy("sameEX0");
   leg_7_2_hor->Draw("same");
   thiswork.DrawLatex(0.5,0.4, Form(NormUncText.Data(),TMath::Sqrt(NormUnc_7TeV*NormUnc_7TeV + NormUnc_2TeV*NormUnc_2TeV)));
   gPad->Update();

   pad2->cd();
   pad2->SetRightMargin(0.001);
   pad2->SetLeftMargin(0.);
   pad2->SetBottomMargin(0.2);
   gPad->SetTicks();
   gPad->SetLogx();
   Axis_hor->DrawCopy("");

   TLegend* leg_13_2_hor = plotLegend("left_top","", 0.8,0.15,0.05, -0.05);
   leg_13_2_hor->SetFillStyle(0);
   leg_13_2_hor->SetBorderSize(0);
   leg_13_2_hor->SetTextSize(legTextSize+0.015);
   leg_13_2_hor->AddEntry((TObject*)0, "#kern[-0.06]{#bf{pp, }" + Legend13TeV + " / " + Legend2TeV + "}","");

   FONLLRatio_13_2->Draw("5same");
   hRatio_13_2_Syst->DrawCopy("E2same");
   GraphRatio_13_2_Stat->Draw("pZsame");
   leg_13_2_hor->Draw("same");
   thiswork.DrawLatex(0.5,0.4, Form(NormUncText.Data(),TMath::Sqrt(NormUnc_13TeV*NormUnc_13TeV + NormUnc_2TeV*NormUnc_2TeV)));

   cHorizontal->SaveAs("Ratios_Horizontal.eps");

//   AliHEPDataParser * hepParser = new AliHEPDataParser(Spectrum2TeVStat, hSpectrum2TeVSyst);
//   hepParser->SetTitle("pt distribution of pi+-, arXiv:1805.04379");
//   hepParser->SetName("1/Nev 1/p_T 1/2pi d^2N/(dp_Tdy) (GeV/c)^{-1}");
//   hepParser->SetXaxisName("PT IN GEV/c");
//   hepParser->SetReaction("RE: P PB --> PI + X");
//   hepParser->SetEnergy("SQRT(SNN) : 5020.0 GeV");
//   hepParser->SetRapidityRange("YRAP : -0.5 - +0.5");
//   hepParser->SaveHEPDataFile("figTemplateHEPData.txt");
}
