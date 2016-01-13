#include "ttHMultilepton/NLeptonSelector.h"

NLeptonSelector::NLeptonSelector(const std::string& params) :
            SignValueSelector("NLEPTON", params, true) {
    checkMultiplicityIsInteger();
}

bool NLeptonSelector::apply(const top::Event& event) const {
    auto elFunc = [&](const xAOD::Electron* elPtr){return elPtr->pt() > value();};
    auto elCount = std::count_if(event.m_electrons.begin(), event.m_electrons.end(), elFunc);

    auto muFunc = [&](const xAOD::Muon* muPtr){return muPtr->pt() > value();};
    auto muCount = std::count_if(event.m_muons.begin(), event.m_muons.end(), muFunc);

    return checkInt(elCount+muCount, multiplicity());
}

bool NLeptonSelector::applyParticleLevel(const top::ParticleLevelEvent& event) const {
    // If any of the required collections is a nullptr (i.e. has not been
    // loaded) return false.
    if ( not event.m_electrons
	 or not event.m_muons ){
	return false;
    }

    auto elFunc = [&](const xAOD::TruthParticle* truElPtr){return truElPtr->pt() > value();};
    auto elCount = std::count_if(event.m_electrons->begin(), event.m_electrons->end(), elFunc);

    auto muFunc = [&](const xAOD::TruthParticle* truMuPtr){return truMuPtr->pt() > value();};
    auto muCount = std::count_if(event.m_muons->begin(), event.m_muons->end(), muFunc);

    return checkInt(elCount+muCount, multiplicity());
}
