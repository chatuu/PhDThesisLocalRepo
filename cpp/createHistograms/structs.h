struct histogram
{
    unsigned int number;
    std::string name;
    TH1D *hist;
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

struct histogramInfo
{
    std::vector<histogram> hist;
    std::vector<histDetails> lColorAndLeg;
    std::string title;
    std::string axis;
    std::string saveAs;
};

struct purityBlock
{
    histogram signal;
    histogram background;
};
