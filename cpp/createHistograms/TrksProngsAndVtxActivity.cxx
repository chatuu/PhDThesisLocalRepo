/**
 * @file createHistograms.cxx
 * 
 * @author Chatura Kuruppu (ckuruppu@fnal.gov)
 * 
 * @brief This program is made to generate histograms from the .root file created by CAFANA script: saveHisotgrams
 * 
 * @version 0.1
 * 
 * @date 2019-12-03
 * 
 * @copyright GNU Public License
 * 
 * @mainpage Histogram Generator
 * 
 * @section intro_sec Introduction
 * 
 * This code was developped to generate Histograms from the .root file created by saveHistograms script.
 * 
 * @section compile_sec Compilation
 * 
 * Here I would describe how to compile this code.
 * 
 * @subsection Step1
 * 
 * Run make.sh
 */

#include "headers.h"
#include "structs.h"
#include "makeHistograms.h"

/**
 * @brief This is the main function.
 *  
 * @param argv This contains the ROOT file name and it's path.
 * 
 */
int main(int argc, char **argv)
{
     std::vector<unsigned int> SignTrkNum = {0}; 
     std::vector<histDetails> nTrkSignal;
     nTrkSignal.push_back({2, "    Signal    "});

     std::vector<unsigned int> BacknTrkNum = {3}; 
     std::vector<histDetails> nTrkBack;
     nTrkBack.push_back({4, " Background "});

     std::vector<unsigned int> SvBnTrkNum = {3,0}; 
     std::vector<histDetails> nTrkSvB;
     nTrkSvB.push_back({4, " Background "});
     nTrkSvB.push_back({2, " Signal "});
    
    makeHistograms nTrks;
    nTrks.SetRootFile(argv[1]);
    nTrks.PrintHistograms(); 
    nTrks.SetHistInfo(nTrks.GetHists(SignTrkNum),
                                nTrkSignal,
                                "Number of Tracks from Coherent Signal",
                                "Number of Tracks",
                                "./plots/signalnTrks.png",
                                false);

    makeHistograms nTrkb;
    nTrkb.SetRootFile(argv[1]);
    nTrkb.SetHistInfo(nTrkb.GetHists(BacknTrkNum),
                                nTrkBack,
                                "Number of Tracks from Coherent Background",
                                "Number of Tracks",
                                "./plots/backgroundnTrks.png",
                                false);

    makeHistograms nTrkSigVBack;
    nTrkSigVBack.SetRootFile(argv[1]);
    nTrkSigVBack.SetHistInfo(nTrkSigVBack.GetHists(SvBnTrkNum),
                                nTrkSvB,
                                "Number of Tracks from Coherent Signal Vs Background",
                                "Number of Tracks",
                                "./plots/SigVsBacknTrks.png",
                                true);

    // Prong CVN part:

     std::vector<unsigned int> SignPrngNum = {1}; 
     std::vector<histDetails> nPrngSignal;
     nPrngSignal.push_back({2, "    Signal    "});

     std::vector<unsigned int> BacknPrngNum = {4}; 
     std::vector<histDetails> nPrngBack;
     nPrngBack.push_back({4, " Background "});

     std::vector<unsigned int> SvBnPrngNum = {4,1}; 
     std::vector<histDetails> nPrngSvB;
     nPrngSvB.push_back({4, " Background "});
     nPrngSvB.push_back({2, " Signal "});
    
    makeHistograms nPrngs;
    nPrngs.SetRootFile(argv[1]);
    nPrngs.PrintHistograms(); 
    nPrngs.SetHistInfo(nPrngs.GetHists(SignPrngNum),
                                nPrngSignal,
                                "Number of Prongs from Coherent Signal",
                                "Number of Prongs",
                                "./plots/signalnPrngs.png",
                                false);

    makeHistograms nPrngb;
    nPrngb.SetRootFile(argv[1]);
    nPrngb.SetHistInfo(nPrngb.GetHists(BacknPrngNum),
                                nPrngBack,
                                "Number of Prongs from Coherent Background",
                                "Number of Prongs",
                                "./plots/backgroundnPrngs.png",
                                false);

    makeHistograms nPrngSigVBack;
    nPrngSigVBack.SetRootFile(argv[1]);
    nPrngSigVBack.SetHistInfo(nPrngSigVBack.GetHists(SvBnPrngNum),
                                nPrngSvB,
                                "Number of Prongs from Coherent Signal Vs Background",
                                "Number of Prongs",
                                "./plots/SigVsBacknPrngs.png",
                                true);

    // Vertex Activity part:

    std::vector<unsigned int> SignVtxActNum = {2}; 
     std::vector<histDetails> nVtxActSignal;
     nVtxActSignal.push_back({2, "    Signal    "});

     std::vector<unsigned int> BacknVtxActNum = {5}; 
     std::vector<histDetails> nVtxActBack;
     nVtxActBack.push_back({4, " Background "});

     std::vector<unsigned int> SvBnVtxActNum = {5,2}; 
     std::vector<histDetails> nVtxActSvB;
     nVtxActSvB.push_back({4, " Background "});
     nVtxActSvB.push_back({2, " Signal "});
    
    makeHistograms nVtxActs;
    nVtxActs.SetRootFile(argv[1]);
    nVtxActs.PrintHistograms(); 
    nVtxActs.SetHistInfo(nVtxActs.GetHists(SignVtxActNum),
                                nVtxActSignal,
                                "Vtx activity of Coherent Signal",
                                "VTX Energy (GeV)",
                                "./plots/signalnVtxActs.png",
                                false);

    makeHistograms nVtxActb;
    nVtxActb.SetRootFile(argv[1]);
    nVtxActb.SetHistInfo(nVtxActb.GetHists(BacknVtxActNum),
                                nVtxActBack,
                                "Vtx activity of Coherent Background",
                                "VTX Energy (GeV)",
                                "./plots/backgroundnVtxActs.png",
                                false);

    makeHistograms nVtxActSigVBack;
    nVtxActSigVBack.SetRootFile(argv[1]);
    nVtxActSigVBack.SetHistInfo(nVtxActSigVBack.GetHists(SvBnVtxActNum),
                                nVtxActSvB,
                                "Vtx activity of Coherent Signal Vs Background",
                                "VTX Energy (GeV)",
                                "./plots/SigVsBacknVtxActs.png",
                                true);

    return 0;
}