/**
 * @brief histogram is used to give a histogram an integer number, name and TH1 histogram.
 * 
 */
struct histogram
{
    unsigned int number; ///< This is the histogram number.
    std::string name; ///< The name of the histogram.
    TH1D *hist; ///< The pointer to the histogram.
};
/**
 * @brief histDetails structure used to assign histogram line color and the name of the legend.
 * 
 */
struct histDetails
{
    Color_t lineColor; ///< This is the histogram line color.
    std::string legName; ///< This is the string to put the legend.
};
/**
 * @brief cutTable is used to create the cut Table.
 * 
 */
struct cutTable
{
    std::string histName; ///< Name of the histogram.
    double nevents; ///< Number of events.
};
/**
 * @brief histogramInfo is used to store array of histograms, 
 * array of their line color and legend names, 
 * title of the canvas, 
 * Xaxis label and save path to save the canvas as a .png file.
 * 
 */
struct histogramInfo
{
    std::vector<histogram> hist;
    std::vector<histDetails> lColorAndLeg;
    std::string title;
    std::string axis;
    std::string saveAs;
    bool isLog;
};

struct purityBlock
{
    histogram signal;
    histogram background;
};
