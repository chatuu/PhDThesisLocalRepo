#include "headers.h"
#include "structs.h"
#include "makeHistograms.h"

int main(int argc, char **argv)
{
    makeHistograms canvas01;
    canvas01.SetRootFile("../../rootFiles/Cleaned_Aug_28_2020_OpeningAngleAndBPFFaliure_Corrected.root");
    canvas01.PrintHistograms();

    std::vector<unsigned int> SigAngle = {5, 6, 7, 8};
    std::vector<histDetails> lSigAngle;
    lSigAngle.push_back({1, "Containment"});
    lSigAngle.push_back({2, "MuonID"});
    lSigAngle.push_back({4, "Two Prong"});
    lSigAngle.push_back({6, "Pion ID"});

    canvas01.SetHistInfo(canvas01.GetHists(SigAngle),
                         lSigAngle,
                         "Signal Opening Angle",
                         "Opening Angle /#pi",
                         {0, 1},
                         0.71801,
                         4,
                         "./plots/SignalOpeningAngle.png");

    makeHistograms canvas02;
    canvas02.SetRootFile("../../rootFiles/Cleaned_Aug_28_2020_OpeningAngleAndBPFFaliure_Corrected.root");
    canvas02.PrintHistograms();

    std::vector<unsigned int> BackAngle = {15, 16, 17, 18};
    std::vector<histDetails> lBackAngle;
    lBackAngle.push_back({1, "Containment"});
    lBackAngle.push_back({2, "MuonID"});
    lBackAngle.push_back({4, "Two Prong"});
    lBackAngle.push_back({6, "Pion ID"});

    canvas02.SetHistInfo(canvas02.GetHists(BackAngle),
                         lBackAngle,
                         "Background Opening Angle",
                         "Opening Angle /#pi",
                         {0, 1},
                         0.71801,
                         4,
                         "./plots/BackgroundOpeningAngle.png");

    makeHistograms canvas03;
    canvas03.SetRootFile("../../rootFiles/Cleaned_Aug_28_2020_OpeningAngleAndBPFFaliure_Corrected.root");
    canvas03.PrintHistograms();

    std::vector<unsigned int> SigVsBackAngle = {18, 8};
    std::vector<histDetails> lSigVsBackAngle;
    //lSigVsBackAngle.push_back({1, "Containment"});
    //lSigVsBackAngle.push_back({2, "MuonID"});
    //lSigVsBackAngle.push_back({4, "Two Prong"});
    lSigVsBackAngle.push_back({4, "Pion ID Background"});
    lSigVsBackAngle.push_back({2, "Pion ID Signal"});

    canvas03.SetHistInfo(canvas03.GetHists(SigVsBackAngle),
                         lSigVsBackAngle,
                         "SignalVsBackground Opening Angle",
                         "Opening Angle /#pi",
                         {0, 1},
                         0.71801,
                         8,
                         "./plots/SignalVsBackgroundOpeningAngle.png");

    makeHistograms canvas04;
    canvas04.SetRootFile("../../rootFiles/Cleaned_Aug_28_2020_OpeningAngleAndBPFFaliure_Corrected.root");
    canvas04.PrintHistograms();

    std::vector<unsigned int> pionE = {3, 4};
    std::vector<histDetails> lpionE;
    //lpionE.push_back({1, "Containment"});
    //lpionE.push_back({2, "MuonID"});
    //lpionE.push_back({4, "Two Prong"});
    lpionE.push_back({4, "Pion ID only"});
    lpionE.push_back({2, "Pion ID With BPF Check"});

    canvas04.SetHistInfo(canvas04.GetHists(pionE),
                         lpionE,
                         "Signal True #pi^{+} K.E (GeV)",
                         "True #pi^{+} K.E (GeV)",
                         {0, 2},
                         0.71801,
                         2,
                         "./plots/SignalTruePionKE.png");

    
    return 0;
}
