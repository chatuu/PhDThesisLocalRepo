#ifndef MAKEHISTOGRAMS_H
#define MAKEHISTOGRAMS_H

#include "headers.h"

class makeHistograms
{
private:
    TFile *f1 = nullptr; ///< This pointer to handles input ROOT file.
    unsigned int histNum = 0; ///< histNum is used to store histogram Number.
    TKey *key = nullptr; ///< This key pointer is used to extract historgram information.
    TKey *subkey = nullptr; ///< This subkey pointer is used to extract historgram information.
    TDirectory *dir = nullptr; ///< This dir pointer is used to access folders in ROOT file and extract historgram information.
    TDirectory *newDir = nullptr; ///< Currently not in use.
    histogramInfo histInfo;
    std::vector<histogram> hist;
    std::vector<histogram> selectedHists;
    //std::vector<double> nentries;
    std::vector<cutTable> eventTable;

public:
    makeHistograms(/* args */);
    ~makeHistograms();

    std::vector<histogram> GetHists(std::vector<unsigned int> histNums);
    void SetRootFile(std::string fileName);
    void PrintHistograms();
    void PrintNevents();
    void createCutTableFile(std::string fileName);
    void drawHistograms(histogramInfo histInfo);
    void makeEfficiencyCurve(std::vector<unsigned int> signalHists, std::vector<histDetails> histinfo,std::string fileName);
    void makePurityCurve(std::vector<unsigned int> signalHists, std::vector<unsigned int> backgroundHist, std::vector<histDetails> histinfo,std::string fileName);
    void SetHistInfo(std::vector<histogram> hists,
                     std::vector<histDetails> lColorAndLeg,
                     std::string title,
                     std::string axis,
                     std::string saveAs,
                     bool isLog);
};

#endif //MAKEHISTOGRAMS_H