#include "headers.h"
#include "structs.h"
#include "makeHistograms.h"

int main(int argc, char **argv)
{
    makeHistograms canvas01;
    canvas01.SetRootFile(argv[1]);
    canvas01.PrintHistograms();

    std::vector<unsigned int> truePion = {4, 5, 6, 7};
    std::vector<histDetails> lTruePion;
    lTruePion.push_back({1, "Containment"});
    lTruePion.push_back({2, "MuonID"});
    lTruePion.push_back({4, "Two Prong"});
    lTruePion.push_back({6, "Pion ID"});

    canvas01.SetHistInfo(canvas01.GetHists(truePion),
                         lTruePion,
                         "Signal True #pi^{+} K.E (GeV)",
                         "True #pi^{+} K.E (GeV)",
                         {0, 3},
                         0.71801,
                         4,
                         "./plots/TruePionKE.png");

    makeHistograms canvas02;
    canvas02.SetRootFile(argv[1]);
    std::vector<unsigned int> truePion1 = {6, 7};
    std::vector<histDetails> lTruePion1;
    lTruePion1.push_back({4, "Two Prong"});
    lTruePion1.push_back({6, "Pion ID"});

    canvas02.SetHistInfo(canvas02.GetHists(truePion1),
                         lTruePion1,
                         "Signal True #pi^{+} K.E (GeV)",
                         "True #pi^{+} K.E (GeV)",
                         {0, 2},
                         0.71801,
                         4,
                         "./plots/TruePionKEWithLastTwoCuts.png");

    makeHistograms canvas03;
    canvas03.SetRootFile(argv[1]);
    std::vector<unsigned int> recoPion = {12, 13, 14, 15};
    std::vector<histDetails> lrecoPion;
    lrecoPion.push_back({1, "Containment"});
    lrecoPion.push_back({2, "MuonID"});
    lrecoPion.push_back({4, "Two Prong"});
    lrecoPion.push_back({6, "Pion ID"});

    canvas03.SetHistInfo(canvas03.GetHists(recoPion),
                         lrecoPion,
                         "Signal Reco #pi^{+} K.E (GeV)",
                         "Reco #pi^{+} K.E (GeV)",
                         {0, 3},
                         0.71801,
                         4,
                         "./plots/RecoPionKE.png");

    makeHistograms canvas04;
    canvas04.SetRootFile(argv[1]);
    std::vector<unsigned int> recoPion1 = {14, 15};
    std::vector<histDetails> lrecoPion1;
    lrecoPion1.push_back({4, "Two Prong"});
    lrecoPion1.push_back({6, "Pion ID"});

    canvas04.SetHistInfo(canvas04.GetHists(recoPion1),
                         lrecoPion1,
                         "Signal Reco #pi^{+} K.E (GeV)",
                         "Reco #pi^{+} K.E (GeV)",
                         {0, 2},
                         0.71801,
                         4,
                         "./plots/RecoPionKEWithLastTwoCuts.png");

    // makeHistograms canvas05;
    // canvas05.SetRootFile(argv[1]);
    // std::vector<histDetails> legend;
    // canvas05.drawResolutionPlot(7,
    //                             15,
    //                             legend,
    //                             "#pi^{+} resolution plot",
    //                             "(True-Reco)/True",
    //                             {-10, 10},
    //                             0.71801, 0,
    //                             "./plots/PionEresolution.png");

    makeHistograms canvas05;
    canvas05.SetRootFile(argv[1]);
    std::vector<unsigned int> trueMuon = {8, 9, 10, 11};
    std::vector<histDetails> ltrueMuon;
    ltrueMuon.push_back({1, "Containment"});
    ltrueMuon.push_back({2, "MuonID"});
    ltrueMuon.push_back({4, "Two Prong"});
    ltrueMuon.push_back({6, "Pion ID"});

    canvas05.SetHistInfo(canvas05.GetHists(trueMuon),
                         ltrueMuon,
                         "True #mu^{-} Energy (GeV)",
                         "True #mu^{-} Energy (GeV)",
                         {0, 3},
                         0.71801,
                         4,
                         "./plots/TrueMuonKE.png");

    makeHistograms canvas06;
    canvas06.SetRootFile(argv[1]);
    std::vector<unsigned int> trueMuon1 = {10, 11};
    std::vector<histDetails> ltrueMuon1;
    ltrueMuon1.push_back({4, "Two Prong"});
    ltrueMuon1.push_back({6, "Pion ID"});

    canvas06.SetHistInfo(canvas06.GetHists(trueMuon1),
                         ltrueMuon1,
                         "Signal Reco #mu^{-} K.E (GeV)",
                         "True #mu^{-} K.E (GeV)",
                         {0, 3},
                         0.71801,
                         4,
                         "./plots/TrueMuonKEWithLastTwoCuts.png");

    makeHistograms canvas07;
    canvas07.SetRootFile(argv[1]);
    std::vector<unsigned int> recoMuon = {16, 17, 18, 19};
    std::vector<histDetails> lrecoMuon;
    lrecoMuon.push_back({1, "Containment"});
    lrecoMuon.push_back({2, "MuonID"});
    lrecoMuon.push_back({4, "Two Prong"});
    lrecoMuon.push_back({6, "Pion ID"});

    canvas07.SetHistInfo(canvas07.GetHists(recoMuon),
                         lrecoMuon,
                         "Reco #mu^{-} Energy (GeV)",
                         "Reco #mu^{-} Energy (GeV)",
                         {0, 3},
                         0.71801,
                         4,
                         "./plots/recoMuonKE.png");

    makeHistograms canvas08;
    canvas08.SetRootFile(argv[1]);
    std::vector<unsigned int> recoMuon1 = {18, 19};
    std::vector<histDetails> lrecoMuon1;
    lrecoMuon1.push_back({4, "Two Prong"});
    lrecoMuon1.push_back({6, "Pion ID"});

    canvas08.SetHistInfo(canvas08.GetHists(trueMuon1),
                         lrecoMuon1,
                         "Signal Reco #mu^{-} K.E (GeV)",
                         "Reco #mu^{-} K.E (GeV)",
                         {0, 3},
                         0.71801,
                         4,
                         "./plots/RecoMuonKEWithLastTwoCuts.png");

    makeHistograms canvas09;
    canvas09.SetRootFile(argv[1]);
    std::vector<unsigned int> trueMuonSB = {39, 11};
    std::vector<histDetails> ltrueMuonSB;
    ltrueMuonSB.push_back({4, "Pion ID Background"});
    ltrueMuonSB.push_back({6, "Pion ID Signal"});

    canvas09.SetHistInfo(canvas09.GetHists(trueMuonSB),
                         ltrueMuonSB,
                         "Signal Reco #mu^{-} K.E (GeV)",
                         "Reco #mu^{-} K.E (GeV)",
                         {0, 3},
                         0.71801,
                         4,
                         "./plots/TrueMuonKESigVsBackground.png");

    makeHistograms canvas10;
    canvas10.SetRootFile(argv[1]);
    std::vector<unsigned int> recoMuonSB = {47, 19};
    std::vector<histDetails> lrecoMuonSB;
    lrecoMuonSB.push_back({4, "Pion ID Background"});
    lrecoMuonSB.push_back({6, "Pion ID Signal"});

    canvas10.SetHistInfo(canvas10.GetHists(recoMuonSB),
                         lrecoMuonSB,
                         "Signal Vs Background Reco #mu^{-} K.E (GeV)",
                         "Reco #mu^{-} K.E (GeV)",
                         {0, 3},
                         0.71801,
                         4,
                         "./plots/RecoMuonKESigVsBackground.png");

    makeHistograms canvas11;
    canvas11.SetRootFile(argv[1]);
    std::vector<unsigned int> truePionSB = {35, 7};
    std::vector<histDetails> ltruePionSB;
    ltruePionSB.push_back({4, "Pion ID Background"});
    ltruePionSB.push_back({6, "Pion ID Signal"});

    canvas11.SetHistInfo(canvas11.GetHists(truePionSB),
                         ltruePionSB,
                         "Signal True #pi^{+} K.E (GeV)",
                         "True #pi^{+} K.E (GeV)",
                         {0, 3},
                         0.71801,
                         4,
                         "./plots/TruePionKESigVsBackground.png");

    makeHistograms canvas12;
    canvas12.SetRootFile(argv[1]);
    std::vector<unsigned int> recoPionSB = {43, 15};
    std::vector<histDetails> lrecoPionSB;
    lrecoPionSB.push_back({4, "Pion ID Background"});
    lrecoPionSB.push_back({6, "Pion ID Signal"});

    canvas12.SetHistInfo(canvas12.GetHists(recoPionSB),
                         lrecoPionSB,
                         "Signal Vs Background Reco #pi^{+} K.E (GeV)",
                         "Reco #pi^{+} K.E (GeV)",
                         {0, 2},
                         0.71801,
                         4,
                         "./plots/RecoPionKESigVsBackground.png");

    makeHistograms canvas13;
    canvas13.SetRootFile("../../rootFiles/Cleaned_Aug_14_2020_muonAndpionEResolutionPlots.root");
    canvas13.PrintHistograms();
    std::vector<unsigned int> muonRes = {4, 5, 6, 7};
    std::vector<histDetails> lmuonRes;
    lmuonRes.push_back({1, "Containment"});
    lmuonRes.push_back({2, "MuonID"});
    lmuonRes.push_back({4, "Two Prong"});
    lmuonRes.push_back({6, "Pion ID"});

    canvas13.SetHistInfo(canvas13.GetHists(muonRes),
                         lmuonRes,
                         "Muon Energy Resolution",
                         "#mu^{-} Resolution",
                         {-1, 1},
                         0.71801,
                         0,
                         "./plots/muonResolutionPlots.png");

    makeHistograms canvas14;
    canvas14.SetRootFile("../../rootFiles/Cleaned_Aug_14_2020_muonAndpionEResolutionPlots.root");
    std::vector<unsigned int> muonRes1 = {6, 7};
    std::vector<histDetails> lmuonRes1;
    lmuonRes1.push_back({4, "Two Prong"});
    lmuonRes1.push_back({6, "Pion ID"});

    canvas14.SetHistInfo(canvas14.GetHists(muonRes1),
                         lmuonRes1,
                         "Muon Energy Resolution",
                         "#mu^{-} Resolution",
                         {-0.3, 0.3},
                         0.71801,
                         0,
                         "./plots/muonRes1olutionPlotsLastTwoCuts.png");

    makeHistograms canvas15;
    canvas15.SetRootFile("../../rootFiles/Cleaned_Aug_14_2020_muonAndpionEResolutionPlots.root");
    canvas15.PrintHistograms();
    std::vector<unsigned int> pionRes = {0, 1, 2, 3};
    std::vector<histDetails> lpionRes;
    lpionRes.push_back({1, "Containment"});
    lpionRes.push_back({2, "MuonID"});
    lpionRes.push_back({4, "Two Prong"});
    lpionRes.push_back({6, "Pion ID"});

    canvas15.SetHistInfo(canvas15.GetHists(pionRes),
                         lpionRes,
                         "pion Energy Resolution",
                         "#pi^{+} Resolution",
                         {-1.5, 1.5},
                         0.71801,
                         2,
                         "./plots/pionResolutionPlots.png");

    makeHistograms canvas16;
    canvas16.SetRootFile("../../rootFiles/Cleaned_Aug_14_2020_muonAndpionEResolutionPlots.root");
    std::vector<unsigned int> pionRes1 = {2, 3};
    std::vector<histDetails> lpionRes1;
    lpionRes1.push_back({4, "Two Prong"});
    lpionRes1.push_back({6, "Pion ID"});

    canvas16.SetHistInfo(canvas16.GetHists(pionRes1),
                         lpionRes1,
                         "Muon Energy Resolution",
                         "#mu^{-} Resolution",
                         {-1, 1},
                         0.71801,
                         2,
                         "./plots/pionRes1olutionPlotsLastTwoCuts.png");

    // lSignal.push_back({6, "Signal with muonID Cuts"});

    // std::vector<unsigned int> BackhistNums = {16, 11, 12, 13, 14};
    // std::vector<histDetails> lBackground;
    // lBackground.push_back({1, "Background with No Cuts"});
    // lBackground.push_back({4, "Background with DQ Cuts"});
    // lBackground.push_back({2, "Background with Fiducial Cuts"});
    // lBackground.push_back({8, "Background with Containment Cuts"});
    // lBackground.push_back({6, "Background with muonID Cuts"});

    // std::vector<unsigned int> SigVBackhistNums = {16, 11, 12, 13, 14, 15, 6, 7, 8, 9};
    // std::vector<histDetails> lColorAndLeg;
    // lColorAndLeg.push_back({1, "Background with No Cuts"});
    // lColorAndLeg.push_back({4, "Background with DQ Cuts"});
    // lColorAndLeg.push_back({2, "Background with Fiducial Cuts"});
    // lColorAndLeg.push_back({8, "Background with Containment Cuts"});
    // lColorAndLeg.push_back({6, "Background with muonID Cuts"});
    // lColorAndLeg.push_back({9, "Signal with No Cuts"});
    // lColorAndLeg.push_back({3, "Signal with DQ Cuts"});
    // lColorAndLeg.push_back({5, "Signal with Fiducial Cuts"});
    // lColorAndLeg.push_back({7, "Signal with Containment Cuts"});
    // lColorAndLeg.push_back({28, "Signal with muonID Cuts"});

    // makeHistograms nuESignalPlots;
    // nuESignalPlots.SetRootFile(argv[1]);
    // nuESignalPlots.PrintHistograms();
    // nuESignalPlots.SetHistInfo(nuESignalPlots.GetHists(SighistNums),
    //                            lSignal,
    //                            "#nu_{#mu} Energy of the Coherent Signal (GeV)",
    //                            "#nu_{#mu} Energy (GeV)",
    //                            "./plots/signal.png");

    // makeHistograms nuEBackgroundPlots;
    // nuEBackgroundPlots.SetRootFile(argv[1]);
    // nuEBackgroundPlots.PrintHistograms();
    // nuEBackgroundPlots.SetHistInfo(nuEBackgroundPlots.GetHists(BackhistNums),
    //                                lBackground,
    //                                "#nu_{#mu} Energy of the Coherent Background (GeV)",
    //                                "#nu_{#mu} Energy (GeV)",
    //                                "./plots/Background.png");

    // makeHistograms nuESigVsBack;
    // nuESigVsBack.SetRootFile(argv[1]);
    // nuESigVsBack.PrintHistograms();

    // nuESigVsBack.SetHistInfo(nuESigVsBack.GetHists(SigVBackhistNums),
    //                          lColorAndLeg,
    //                          "#nu_{#mu} Energy Signal Vs Background (GeV)",
    //                          "#nu_{#mu} Energy (GeV)",
    //                          "./plots/SigVsBack.png");

    // nuESigVsBack.PrintNevents();
    // nuESigVsBack.createCutTableFile("./csvFiles/cutTable.csv");

    // makeHistograms createCutTable;
    // createCutTable.SetRootFile(argv[1]);
    // std::vector<unsigned int> histlist = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    // std::vector<histDetails> lLeg;
    // lLeg.push_back({1, "Background with No Cuts"});
    // lLeg.push_back({4, "Background with DQ Cuts"});
    // lLeg.push_back({2, "Background with Fiducial Cuts"});
    // lLeg.push_back({8, "Background with Containment Cuts"});
    // lLeg.push_back({6, "Background with muonID Cuts"});
    // lLeg.push_back({9, "Signal with No Cuts"});
    // lLeg.push_back({3, "Signal with DQ Cuts"});
    // lLeg.push_back({5, "Signal with Fiducial Cuts"});
    // lLeg.push_back({7, "Signal with Containment Cuts"});
    // lLeg.push_back({28, "Signal with muonID Cuts"});
    // lLeg.push_back({7, "Signal with Containment Cuts"});
    // lLeg.push_back({28, "Signal with muonID Cuts"});

    // createCutTable.SetHistInfo(createCutTable.GetHists(histlist),
    //                            lLeg,
    //                            "#nu_{#mu} Energy Signal Vs Background (GeV)",
    //                            "#nu_{#mu} Energy (GeV)",
    //                            "./plots/testing.png");

    // createCutTable.createCutTableFile("./csvFiles/FinalcutTable.csv");

    // std::vector<histDetails> sigdetails;
    // sigdetails.push_back({1, "DQ Cuts"});
    // sigdetails.push_back({2, "Fiducial Cuts"});
    // sigdetails.push_back({3, "Containement Cuts"});
    // sigdetails.push_back({4, "Muon ID Cuts"});
    // createCutTable.makeEfficiencyCurve(SighistNums, sigdetails,"./plots/efficiency.png");

    // std::vector<histDetails> PurityLeg;
    // PurityLeg.push_back({1, "DQ Cuts"});
    // PurityLeg.push_back({2, "Fiducial Cuts"});
    // PurityLeg.push_back({3, "Containement Cuts"});
    // PurityLeg.push_back({4, "Muon ID Cuts"});

    // createCutTable.makePurityCurve(SighistNums, BackhistNums, PurityLeg,"./plots/purity.png");

    return 0;
}
