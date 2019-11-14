/* C++ STL */
#include <string>
#include <iostream>
#include <sstream>

/* ROOT Libraries */
#include "TFile.h"
#include "TKey.h"
#include "TString.h"
#include "TH1.h"


int main(int argc, char **argv)
{
    std::cout << " Input FileName: " << argv[1] << "\n"
              << std::endl;
    TFile *f1 = TFile::Open(argv[1], "READ");
    TFile *f2 = new TFile(Form("Cleaned_%s", argv[1]), "RECREATE");
    TH1D *hist=nullptr;

    if (!f1 || f1->IsZombie())
    {
        printf("Error opening file: %s", argv[1]);
        exit(-1);
    }
    else
    {
        TIter next(f1->GetListOfKeys());
        TKey *key=nullptr;
        TKey *subkey=nullptr;
        TDirectory *dir = nullptr;
        TDirectory *newDir = nullptr;

        while (key = (TKey *)next())
        {
            dir = (TDirectory *)f1->Get(key->GetName());
            f2->mkdir(key->GetName());
            f2->cd(key->GetName());
            TIter subnext(dir->GetListOfKeys());
            while (subkey = (TKey *)subnext())
            {
                if (std::string(subkey->GetClassName()) == "TH1D")
                {
                    hist=(TH1D*)dir->Get(subkey->GetName());
                    hist->SetName(subkey->GetName());
                    hist->Write();
                }
            }
        }
        f2->Write();
        f1->Close();
        f2->Close();

        std::cout<<Form("Cleaned_%s was created successfully..!", argv[1])<<std::endl;
        return 0;
    }
}