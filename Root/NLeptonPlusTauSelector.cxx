#include "ttHMultilepton/NLeptonPlusTauSelector.h"

NLeptonPlusTauSelector::NLeptonPlusTauSelector(const std::string& params) :
            SignValueSelector("NLEPTONPLUSTAU", params, true) {
    checkMultiplicityIsInteger();
}

bool NLeptonPlusTauSelector::apply(const top::Event& event) const {
    auto elFunc = [&](const xAOD::Electron* elPtr){return elPtr->pt() > value();};
    auto elCount = std::count_if(event.m_electrons.begin(), event.m_electrons.end(), elFunc);

    auto muFunc = [&](const xAOD::Muon* muPtr){return muPtr->pt() > value();};
    auto muCount = std::count_if(event.m_muons.begin(), event.m_muons.end(), muFunc);

    auto tauFunc = [&](const xAOD::TauJet* tauPtr){return tauPtr->pt() > value();};
    auto tauCount = std::count_if(event.m_tauJets.begin(), event.m_tauJets.end(), tauFunc);

    return checkInt(elCount+muCount+tauCount, multiplicity());
}

bool NLeptonPlusTauSelector::applyParticleLevel(const top::ParticleLevelEvent& event) const {
    // If any of the required collections is a nullptr (i.e. has not been
    // loaded) return false.
    return false;
    /*if ( not event.m_electrons
	 or not event.m_muons )
	return false;
    }

    auto elFunc = [&](const xAOD::TruthParticle* truElPtr){return truElPtr->pt() > value();};
    auto elCount = std::count_if(event.m_electrons->begin(), event.m_electrons->end(), elFunc);

    auto muFunc = [&](const xAOD::TruthParticle* truMuPtr){return truMuPtr->pt() > value();};
    auto muCount = std::count_if(event.m_muons->begin(), event.m_muons->end(), muFunc);

    return checkInt(elCount+muCount, multiplicity());*/
}

