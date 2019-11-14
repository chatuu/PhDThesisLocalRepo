/* C++ STL */
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>


/* ROOT Libraries */
#include "TFile.h"
#include "TKey.h"
#include "TString.h"
#include "TH1.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLegend.h"

struct histogram
{
    unsigned int number;
    std::string name;
    TH1D* hist;
};

struct histDetails
{
    Color_t lineColor;
    std::string legName;
};

struct cutTable
{
    std::string histName;
    double nevents;
};

struct histogramInfo{
    std::vector<histogram> hist;
    std::vector<histDetails> lColorAndLeg;
    std::string title;
    std::string axis;
    std::string saveAs;
};

class makeHistograms
{
private:
    TFile *f1=nullptr;
    unsigned int histNum=0;
    TKey *key=nullptr;
    TKey *subkey=nullptr;
    TDirectory *dir = nullptr;
    TDirectory *newDir = nullptr;
    histogramInfo histInfo;
    std::vector<histogram> hist;
    std::vector<histogram> selectedHists;
    //std::vector<double> nentries; 
    std::vector<cutTable> eventTable;

public:
    makeHistograms(/* args */);
    ~makeHistograms();

    void SetRootFile(std::string fileName="../rootFiles/Cleaned_20191028_backup.root"){
        f1 = TFile::Open(fileName.c_str(), "READ");
        if (!f1 || f1->IsZombie()){
            exit(-1); 
        }
        else{
            printf("ROOT file %s successfully opened..! \n",fileName.c_str());
        }
    }

    void PrintHistograms(){
        histNum=0;
        TIter next(f1->GetListOfKeys());
        while ((key = (TKey*)next()))
        {
            dir = (TDirectory *)f1->Get(key->GetName());
            TIter subnext(dir->GetListOfKeys());
            while ((subkey = (TKey*)subnext()))
                if (std::string(subkey->GetClassName()) == "TH1D" && std::string(subkey->GetName())=="hist"){
                    printf("%d %s \n",histNum,std::string(key->GetName()).c_str());
                    histNum++;   
                }
        }

    }

    std::vector<histogram> GetHists(std::vector<unsigned int> histNums){
        histNum=0;
        TIter next(f1->GetListOfKeys());
        while ((key = (TKey*)next()))
        {
            dir = (TDirectory *)f1->Get(key->GetName());
            TIter subnext(dir->GetListOfKeys());
            while ((subkey = (TKey*)subnext()))
                if (std::string(subkey->GetClassName()) == "TH1D" && std::string(subkey->GetName())=="hist"){
                    TH1D* htemp = (TH1D*)dir->Get(subkey->GetName());
                    htemp->SetDirectory(0);
                    hist.push_back({histNum,std::string(key->GetName()),htemp});
                    histNum++;   
                }
        }
        histNum=0;
        for(auto it=histNums.begin();it!=histNums.end();++it){
            selectedHists.push_back({histNum,hist.at(*it).name,hist.at(*it).hist});
            histNum++;
        }
        return selectedHists;
    }

    void PrintNevents(){
        for(auto it=selectedHists.begin();it!=selectedHists.end();++it){
            std::cout<<" "<<it->number<<" "<<it->name<<" "<<it->hist->GetEntries()<<std::endl;
        }
    }

    void createCutTableFile(std::string fileName="defaultCutTable.txt"){
        std::ofstream output;
        output.open(fileName);
        output<<"Histogram Number, Histogram Name, Number of Events\n";
        for (auto it = selectedHists.begin(); it != selectedHists.end();++it)
            output<<it->number+1<<","<<it->name<<","<<it->hist->GetEntries()<<"\n";

        output.close();
        std::cout<<"File that contains cutTable : "<<fileName<<" is created..!"<<std::endl;
    }

     void drawHistograms(histogramInfo histInfo){
        int numPlots=histInfo.hist.size();
        std::cout<<"size is: "<<histInfo.hist.size()<<std::endl;
        auto c=new TCanvas("c","title",1024,768);
        auto l=new TLegend(0.6,0.7-0.04*numPlots,0.9,0.9);
        THStack hs("hs",histInfo.title.c_str());
        std::cout<<"Debugging"<<std::endl;
        TH1D* h[histInfo.hist.size()];
        for(auto it=histInfo.hist.begin();it!=histInfo.hist.end();++it){
            //std::cout<<it->number<<it->name<<histInfo.lColorAndLeg.at(it->number).legName<<std::endl;
            h[it->number]=(TH1D*)it->hist;
            h[it->number]->Scale((8.09e+20)/(3.53871e+21));
            h[it->number]->SetLineColor(histInfo.lColorAndLeg.at(it->number).lineColor);
            h[it->number]->GetXaxis()->SetTitle(histInfo.axis.c_str());
            h[it->number]->GetYaxis()->SetNdivisions(1010);
            h[it->number]->GetXaxis()->SetNdivisions(1010);
            //h->GetYaxis()->SetTitle("Number of Events");
             //std::cout<<it->number<<it->name<<histInfo.lColorAndLeg.at(it->number).legName<<" "<<h->GetEntries()<<std::endl;
            eventTable.push_back({histInfo.title,h[it->number]->Integral(1,-1)});
           
            l->AddEntry(h[it->number],histInfo.lColorAndLeg.at(it->number).legName.c_str(),"l");
            //hs.Add(h);
            //delete h;
            h[it->number]->Draw("hist same");
        }
        std::cout<<histInfo.saveAs<<std::endl;
        //hs.Draw("hist");
        l->Draw();
        //hs.GetXaxis()->SetTitle(histInfo.axis.c_str());
        c->SaveAs(histInfo.saveAs.c_str());
        f1->Close();
        //delete f1;
        delete c;
        delete l;
    }

    void SetHistInfo(std::vector<histogram> hists,
                     std::vector<histDetails> lColorAndLeg,
                     std::string title,
                     std::string axis,
                     std::string saveAs){
        //std::reverse(lColorAndLeg.begin(),lColorAndLeg.end());
        
        //std::reverse(hists.begin(),hists.end());
    
        histInfo.hist=hists;
        histInfo.lColorAndLeg=lColorAndLeg;
        histInfo.title=title;
        histInfo.axis=axis;
        histInfo.saveAs=saveAs;  

        drawHistograms(histInfo);
    };
};

makeHistograms::makeHistograms(/* args */)
{
    std::cout<<"Constructor called..!"<<std::endl;
}

makeHistograms::~makeHistograms()
{
    std::cout<<"Destructor Called..!"<<std::endl;
    delete f1;
    delete key;
    delete subkey;

    hist.clear();
    selectedHists.clear();
    eventTable.clear();
}

int main(int argc, char **argv)
{
    std::vector<unsigned int> SighistNums={5,6,7,8,9};
    std::vector<histDetails> lSignal;
    lSignal.push_back({2,"Signal with No Cuts"});
    lSignal.push_back({4,"Signal with DQ Cuts"});
    lSignal.push_back({6,"Signal with Fiducial Cuts"});
    lSignal.push_back({7,"Signal with Containment Cuts"});
    lSignal.push_back({8,"Signal with muonID Cuts"});

    std::vector<unsigned int> BackhistNums={10,11,12,13,14};
    std::vector<histDetails> lBackground;
    lBackground.push_back({2,"Background with No Cuts"});
    lBackground.push_back({4,"Background with DQ Cuts"});
    lBackground.push_back({6,"Background with Fiducial Cuts"});
    lBackground.push_back({7,"Background with Containment Cuts"});
    lBackground.push_back({8,"Background with muonID Cuts"});
    
    std::vector<unsigned int> SigVBackhistNums={10,11,12,13,14,5,6,7,8,9};
    std::vector<histDetails> lColorAndLeg;
    lColorAndLeg.push_back({2,"Background with No Cuts"});
    lColorAndLeg.push_back({9,"Background with DQ Cuts"});
    lColorAndLeg.push_back({8,"Background with Fiducial Cuts"});
    lColorAndLeg.push_back({46,"Background with Containment Cuts"});
    lColorAndLeg.push_back({28,"Background with muonID Cuts"});
    lColorAndLeg.push_back({1,"Signal with No Cuts"});
    lColorAndLeg.push_back({40,"Signal with DQ Cuts"});
    lColorAndLeg.push_back({4,"Signal with Fiducial Cuts"});
    lColorAndLeg.push_back({6,"Signal with Containment Cuts"});
    lColorAndLeg.push_back({7,"Signal with muonID Cuts"});
    
   
    makeHistograms nuESignalPlots;
    nuESignalPlots.SetRootFile(argv[1]);
    nuESignalPlots.PrintHistograms();
    nuESignalPlots.SetHistInfo(nuESignalPlots.GetHists(SighistNums),
                             lSignal,
                             "#nu_{#mu} Energy of the Coherent Signal (GeV)",
                             "#nu_{#mu} Energy (GeV)",
                             "./plots/signal.png");

    makeHistograms nuEBackgroundPlots;
    nuEBackgroundPlots.SetRootFile(argv[1]);
    nuEBackgroundPlots.PrintHistograms();
    nuEBackgroundPlots.SetHistInfo(nuEBackgroundPlots.GetHists(BackhistNums),
                             lBackground,
                             "#nu_{#mu} Energy of the Coherent Background (GeV)",
                             "#nu_{#mu} Energy (GeV)",
                             "./plots/Background.png");

    makeHistograms nuESigVsBack;
    nuESigVsBack.SetRootFile(argv[1]);
    nuESigVsBack.PrintHistograms();

    nuESigVsBack.SetHistInfo(nuESigVsBack.GetHists(SigVBackhistNums),
                             lColorAndLeg,
                             "#nu_{#mu} Energy Signal Vs Background (GeV)",
                             "#nu_{#mu} Energy (GeV)",
                             "./plots/SigVsBack.png");

    nuESigVsBack.PrintNevents();
    nuESigVsBack.createCutTableFile("./csvFiles/cutTable.csv");

    std::cout<<"\n"<<Form("Cleaned_%s was created successfully..!", argv[1])<<std::endl;
    return 0;
}