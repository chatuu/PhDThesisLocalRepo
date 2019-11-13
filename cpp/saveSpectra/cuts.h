#include "headers.h"

const Cut kMyNuMuCCCoh([](const caf::SRProxy* sr)
{
  if(sr->mc.nnu==0) return false;
    return (sr->mc.nu[0].iscc &&
           (sr->mc.nu[0].pdg == 14) &&
           (sr->mc.nu[0].pdgorig == 14) &&
           (sr->mc.nu[0].mode == caf::kCoh));

});

const NuTruthCut kTrueMyNuMuCCCoh([](const caf::SRNeutrinoProxy* sr)
{
  //if(sr->nnu==0) return false;
    return (sr->iscc &&
           (sr->pdg == 14) &&
           (sr->pdgorig == 14) &&
           (sr->mode == caf::kCoh));

});

 const NuTruthCut kMyTrueFiducialST([](const caf::SRNeutrinoProxy* sr)
{
  const TVector3 vtxmin(-130, -130, 100);
  const TVector3 vtxmax( 140,  140, 1000);

  return (sr->vtx.X() <  vtxmax.X() &&
          sr->vtx.X() >  vtxmin.X() &&
          sr->vtx.Y() >  vtxmin.Y() &&
          sr->vtx.Y() <  vtxmax.Y() &&
          sr->vtx.Z() >  vtxmin.Z() &&
          sr->vtx.Z() <  vtxmax.Z() );
});

const Cut kNuMuCCCohSig = kMyNuMuCCCoh && CutFromNuTruthCut(kMyTrueFiducialST);
const NuTruthCut kTrueNuMuCCCohSig = kTrueMyNuMuCCCoh && kMyTrueFiducialST;



const Cut kNCBkgd([](const caf::SRProxy* sr)
{
  if(sr->mc.nnu==0) return false;
  return (!(sr->mc.nu[0].iscc)); // Is a NC interaction
});
