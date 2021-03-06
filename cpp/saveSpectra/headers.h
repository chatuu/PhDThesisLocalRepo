//CAF headers
#include "CAFAna/Core/Cut.h"
#include "CAFAna/Core/Utilities.h"
#include "StandardRecord/Proxy/SRProxy.h"
#include "CAFAna/Cuts/SpillCuts.h"
#include "CAFAna/Core/SpectrumLoader.h"
#include "CAFAna/Core/SpectrumLoaderBase.h"
#include "CAFAna/Core/HistAxis.h"
#include "CAFAna/Vars/Vars.h"
#include "CAFAna/Core/Binning.h"
#include "CAFAna/Core/Cut.h"
#include "CAFAna/Core/MultiVar.h"
#include "CAFAna/Core/Ratio.h"
#include "CAFAna/Cuts/Cuts.h"
#include "CAFAna/Cuts/SpillCuts.h"
#include "CAFAna/Cuts/NueCutsSecondAna.h"
#include "CAFAna/Vars/NumuVars.h"
#include "CAFAna/Vars/GenieWeights.h"
#include "CAFAna/Vars/PPFXWeights.h"
#include "CAFAna/XSec/GenieMultiverseSyst.h"
#include "CAFAna/XSec/FluxMultiverseSyst.h"
#include "CAFAna/Cuts/TruthCuts.h"
#include "CAFAna/Core/Spectrum.h"
#include "CAFAna/Core/SystShifts.h"
#include "CAFAna/Vars/XsecTunes.h"
#include "CAFAna/Vars/TruthVars.h"

#include "NDAna/numucc_inc/NumuCCIncVars.h"
#include "NDAna/numucc_inc/NumuCCIncCuts.h"

//STL
#include <map>
#include <string>

//ROOT
#include "TH1.h"

// This is no longer a test
using namespace ana;
/*
const SpillTruthCut kIsNumuCCST([](const caf::SRNeutrinoProxy *truth) {
  return (truth->iscc &&
          truth->pdg == 14 &&
          truth->pdgorig == 14);
});*/
/*******************************************************************************/

//const Cut kNuMuCCCoh_Selected = kNuMuCCCoh && kAllNumuCCCuts;
/*******************************************************************************/

