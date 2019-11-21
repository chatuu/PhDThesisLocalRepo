#include "headers.h"
#include "structs.h"
#include "makeHistograms.h"

makeHistograms::makeHistograms(/* args */)
{
    
}

makeHistograms::~makeHistograms()
{
    delete f1;
    delete key;
    delete subkey;

    hist.clear();
    selectedHists.clear();
    eventTable.clear();
}

void makeHistograms::SetRootFile(std::string fileName = "../rootFiles/Cleaned_20191028_backup.root")
{
    f1 = TFile::Open(fileName.c_str(), "READ");
    if (!f1 || f1->IsZombie())
    {
        exit(-1);
    }
    else
    {
        printf("ROOT file %s successfully opened..! \n", fileName.c_str());
    }
}

void makeHistograms::PrintHistograms()
{
    histNum = 0;
    TIter next(f1->GetListOfKeys());
    while ((key = (TKey *)next()))
    {
        dir = (TDirectory *)f1->Get(key->GetName());
        TIter subnext(dir->GetListOfKeys());
        while ((subkey = (TKey *)subnext()))
            if (std::string(subkey->GetClassName()) == "TH1D" && std::string(subkey->GetName()) == "hist")
            {
                printf("%d %s \n", histNum, std::string(key->GetName()).c_str());
                histNum++;
            }
    }
}

std::vector<histogram> makeHistograms::GetHists(std::vector<unsigned int> histNums)
{
    histNum = 0;
    TIter next(f1->GetListOfKeys());
    while ((key = (TKey *)next()))
    {
        dir = (TDirectory *)f1->Get(key->GetName());
        TIter subnext(dir->GetListOfKeys());
        while ((subkey = (TKey *)subnext()))
            if (std::string(subkey->GetClassName()) == "TH1D" && std::string(subkey->GetName()) == "hist")
            {
                TH1D *htemp = (TH1D *)dir->Get(subkey->GetName());
                htemp->SetDirectory(0);
                hist.push_back({histNum, std::string(key->GetName()), htemp});
                histNum++;
            }
    }
    histNum = 0;
    selectedHists.clear();
    for (auto it = selectedHists.begin(); it != selectedHists.end(); ++it)
        std::cout << it->number << it->name << std::endl;
    for (auto it = histNums.begin(); it != histNums.end(); ++it)
    {
        std::cout << *it << std::endl;
        selectedHists.push_back({histNum, hist.at(*it).name, hist.at(*it).hist});
        histNum++;
    }
    return selectedHists;
}

void makeHistograms::PrintNevents()
{
    for (auto it = selectedHists.begin(); it != selectedHists.end(); ++it)
        std::cout << " " << it->number << " " << it->name << " " << it->hist->GetEntries() << std::endl;
    
}

void makeHistograms::createCutTableFile(std::string fileName = "defaultCutTable.txt")
{
    std::ofstream output;
    output.open(fileName);
    output << "Histogram Number, Histogram Name, Number of Events\n";
    for (auto it = selectedHists.begin(); it != selectedHists.end(); ++it)
        output << it->number + 1 << "," << it->name << "," << it->hist->GetEntries() << "\n";

    output.close();
    std::cout << "File that contains cutTable : " << fileName << " is created..!" << std::endl;
}

void makeHistograms::drawHistograms(histogramInfo histInfo)
{
    int numPlots = histInfo.hist.size();
    auto c = new TCanvas("c", "title", 1024, 768);
    auto l = new TLegend(0.6, 0.7 - 0.04 * numPlots, 0.9, 0.9);
    THStack hs("hs", histInfo.title.c_str());
    TH1D *h[histInfo.hist.size()];
    for (auto it = histInfo.hist.begin(); it != histInfo.hist.end(); ++it)
    {
        h[it->number] = (TH1D *)it->hist;
        h[it->number]->Scale((8.09e+20) / (3.53871e+21));
        h[it->number]->SetLineColor(histInfo.lColorAndLeg.at(it->number).lineColor);
        h[it->number]->GetXaxis()->SetTitle(histInfo.axis.c_str());
        h[it->number]->GetYaxis()->SetNdivisions(1010);
        h[it->number]->GetXaxis()->SetNdivisions(1010);
       
        eventTable.push_back({histInfo.title, h[it->number]->Integral(1, -1)});

        l->AddEntry(h[it->number], histInfo.lColorAndLeg.at(it->number).legName.c_str(), "l");
        h[it->number]->Draw("hist same");
    }
    l->Draw();
    c->SaveAs(histInfo.saveAs.c_str());
    f1->Close();
    delete c;
    delete l;
}

void makeHistograms::makeEfficiencyCurve(std::vector<unsigned int> signalHists, std::vector<histDetails> histinfo,std::string fileName)
{
    std::vector<histogram> signalPlots = GetHists(signalHists);
    std::vector<histogramInfo> efficiencyCurves;
    TH1D *hTrue = nullptr;
    TH1D *hCut = nullptr;

    TCanvas *c1 = new TCanvas("c1", "Efficiency curves", 1024, 768);
    int numPlots = (signalPlots.size() - 1);
    TH1D *hEff[numPlots];
    auto l = new TLegend(0.6, 0.7 - 0.04 * numPlots, 0.9, 0.2);
    c1->cd();
    for (auto it = signalPlots.begin(); it != signalPlots.end(); ++it)
    {
        std::cout << "Signal Hists: " << it->number << it->name << std::endl;
        if (it->number == 0)
        {
            hTrue = (TH1D *)it->hist;
            std::cout << "Truth hist was selected" << std::endl;
        }
        else
        {
            hCut = (TH1D *)it->hist;
            hEff[it->number] = (TH1D *)hCut->Clone(TString::Format("h%d", it->number));
            hEff[it->number]->Divide(hTrue);
            std::cout << "Testing: " << hEff[it->number]->Integral() << "\n";
            hEff[it->number]->GetYaxis()->SetTitle("Efficiency");
            hEff[it->number]->Draw("hist same");
            std::cout << it->number << '\n';
            l->AddEntry(hEff[it->number], histinfo.at(it->number - 1).legName.c_str(), "l");
            l->Draw();
        }
    }
    c1->SaveAs(fileName.c_str());
    delete c1;
    delete l;
}

void makeHistograms::makePurityCurve(std::vector<unsigned int> signalHists, std::vector<unsigned int> backgroundHists, std::vector<histDetails> histinfo,std::string fileName)
{
    std::vector<histogram> signalPlots = GetHists(signalHists);
    std::vector<histogram> backgroundPlots = GetHists(backgroundHists);
    std::vector<purityBlock> purityHists;

    int numPlots = (signalPlots.size() - 1);

    for (auto itSig = signalPlots.begin(); itSig != signalPlots.end(); ++itSig)
        purityHists.push_back({signalPlots.at(itSig->number), backgroundPlots.at(itSig->number)});

    std::reverse(purityHists.begin(), purityHists.end());

    TCanvas *c1 = new TCanvas("c1", "Efficiency curves", 1200, 768);
    int numSigPlots = (signalPlots.size() - 1);
    int numBackPlots = (backgroundPlots.size() - 1);
    if (numSigPlots == numBackPlots)
    {
        TH1D *hSignal[numSigPlots];
        TH1D *hBack[numSigPlots];
        TH1D *hNorm[numSigPlots];
        TH1D *hDenom[numSigPlots];

        auto l = new TLegend(0.6, 0.7 - 0.04 * numPlots, 0.9, 0.9);
        c1->cd();
        for (auto it = purityHists.begin(); it != purityHists.end(); ++it)
        {
            hSignal[it->signal.number] = (TH1D *)it->signal.hist;
            hBack[it->background.number] = (TH1D *)it->background.hist;
            hDenom[it->signal.number] = (TH1D *)hSignal[it->signal.number]->Clone(TString::Format("h%d", it->signal.number));
            TH1D *htemp = (TH1D *)hBack[it->background.number]->Clone(TString::Format("hb%d", it->background.number));
            hDenom[it->signal.number]->Add(htemp);
            hNorm[it->signal.number] = (TH1D *)it->signal.hist;
            TH1D *htemp2 = (TH1D *)hDenom[it->signal.number]->Clone(TString::Format("hdenom%d", it->signal.number));
            hNorm[it->signal.number]->Divide(htemp2);

            if (it->signal.number != 0 && it->background.number != 0)
            {
                hNorm[it->signal.number]->GetYaxis()->SetTitle("Purity");
                hNorm[it->signal.number]->Draw("hist same");
                l->AddEntry(hNorm[it->signal.number], histinfo.at((it->signal.number - 1)).legName.c_str(), "l");
                std::cout << "Now Drawing: " << it->signal.name << "And it's legend: " << histinfo.at(it->signal.number - 1).legName.c_str() << '\n';
            }
        }
        l->Draw();
        c1->SaveAs(fileName.c_str());
    }
}

void makeHistograms::SetHistInfo(std::vector<histogram> hists,
                                 std::vector<histDetails> lColorAndLeg,
                                 std::string title,
                                 std::string axis,
                                 std::string saveAs)
{
    histInfo.hist = hists;
    histInfo.lColorAndLeg = lColorAndLeg;
    histInfo.title = title;
    histInfo.axis = axis;
    histInfo.saveAs = saveAs;

    drawHistograms(histInfo);
}
