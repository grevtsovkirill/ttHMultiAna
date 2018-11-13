/*
 Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
 */

/*
 * EffiCollection.cxx
 *
 *  Created on: Jun 21, 2014
 *      Author: goblirsc
 */

#include <MuonEfficiencyCorrections/EffiCollection.h>
#include <MuonEfficiencyCorrections/EfficiencyScaleFactor.h>
#include <TTree.h>
namespace CP {
    std::vector<std::string> ToRemove { "GeV", "MeV", "[", "]", "{", "}", "(", ")", "#", " " };

    EffiCollection::EffiCollection() :
                m_central_eff(),
                m_calo_eff(),
                m_forward_eff(),
                m_lowpt_central_eff(),
                m_lowpt_calo_eff(),
                m_lowpt_transition(20000.),
                m_sfType(CP::MuonEfficiencyType::Undefined) {
    }

    EffiCollection::EffiCollection(const asg::AsgTool* ref_asg_tool, const std::string &file_central, const std::string &file_calo, const std::string &file_forward, const std::string &file_lowpt_central, const std::string &file_lowpt_calo, MuonEfficiencySystType sysType, CP::MuonEfficiencyType effType, double lowPtTransition) :
                EffiCollection() {
        m_lowpt_transition = lowPtTransition;
        m_sfType = effType;
        bool KineSyst = effType == CP::MuonEfficiencyType::Reco || effType == CP::MuonEfficiencyType::BadMuonVeto;
        m_central_eff = CollectionContainer_Ptr(new CollectionContainer(ref_asg_tool, file_central, sysType, m_sfType, CollectionType::Central, false, KineSyst));
        m_calo_eff = CollectionContainer_Ptr(new CollectionContainer(ref_asg_tool, file_calo, sysType, m_sfType, CollectionType::Calo, false, KineSyst));
        m_forward_eff = CollectionContainer_Ptr(new CollectionContainer(ref_asg_tool, file_forward, sysType, m_sfType, CollectionType::Forward));

        // last argument tells this to respond to dedicated low pt systematic variations
        if (m_lowpt_transition > 0) {
            m_lowpt_central_eff = CollectionContainer_Ptr(new CollectionContainer(ref_asg_tool, file_lowpt_central, sysType, m_sfType, CollectionType::CentralLowPt, true));
            m_lowpt_calo_eff = CollectionContainer_Ptr(new CollectionContainer(ref_asg_tool,file_lowpt_calo, sysType, m_sfType, CollectionType::CaloLowPt, true));
        }
    }

    EffiCollection::EffiCollection(const EffiCollection* Nominal, const asg::AsgTool* ref_asg_tool, const std::string &file_central, const std::string &file_calo, const std::string &file_forward, const std::string &file_lowpt_central, const std::string &file_lowpt_calo, MuonEfficiencySystType sysType, CP::MuonEfficiencyType effType, double lowPtTransition) :
                EffiCollection() {
        m_lowpt_transition = lowPtTransition;
        m_sfType = effType;
        bool KineSyst = effType == CP::MuonEfficiencyType::Reco || effType == CP::MuonEfficiencyType::BadMuonVeto;
        m_central_eff = CollectionContainer_Ptr(new CollectionContainer(Nominal->retrieveContainer(CollectionType::Central), ref_asg_tool, file_central, sysType, m_sfType, CollectionType::Central, false, KineSyst));
        m_calo_eff = CollectionContainer_Ptr(new CollectionContainer(Nominal->retrieveContainer(CollectionType::Calo), ref_asg_tool, file_calo, sysType, m_sfType, CollectionType::Calo, false, KineSyst));
        m_forward_eff = CollectionContainer_Ptr(new CollectionContainer(Nominal->retrieveContainer(CollectionType::Forward), ref_asg_tool, file_forward, sysType, m_sfType, CollectionType::Forward));

        // last argument tells this to respond to dedicated low pt systematic variations
        if (m_lowpt_transition > 0) {
            m_lowpt_central_eff = CollectionContainer_Ptr(new CollectionContainer(Nominal->retrieveContainer(CollectionType::CentralLowPt), ref_asg_tool, file_lowpt_central, sysType, m_sfType, CollectionType::CentralLowPt, true));
            m_lowpt_calo_eff = CollectionContainer_Ptr(new CollectionContainer(Nominal->retrieveContainer(CollectionType::CaloLowPt), ref_asg_tool, file_lowpt_calo, sysType, m_sfType, CollectionType::CaloLowPt, true));
        }
    }
    EffiCollection::CollectionContainer_Ptr EffiCollection::retrieveContainer(CollectionType Type) const {
        if (Type == CollectionType::Central) return m_central_eff;
        if (Type == CollectionType::Forward) return m_forward_eff;
        if (Type == CollectionType::Calo) return m_calo_eff;
        if (Type == CollectionType::CentralLowPt) return m_lowpt_central_eff;
        if (Type == CollectionType::CaloLowPt) return m_lowpt_calo_eff;
        return nullptr;
    }
    bool EffiCollection::CheckConsistency() const {
        if (!m_central_eff || !m_central_eff->CheckConsistency()) {
            return false;
        }
        if (!m_calo_eff || !m_calo_eff->CheckConsistency()) {
            return false;
        }
        if (!m_forward_eff || !m_forward_eff->CheckConsistency()) {
            return false;
        }
        if (!m_central_eff || !m_central_eff->CheckConsistency()) {
            return false;
        }
        if (m_lowpt_transition < 0.) {
            return true;
        }
        if (!m_lowpt_central_eff || !m_lowpt_central_eff->CheckConsistency()) {
            return false;
        }
        if (!m_lowpt_calo_eff || !m_lowpt_calo_eff->CheckConsistency()) {
            return false;
        }
        return true;
    }

    EffiCollection::EffiCollection(const CP::EffiCollection & other) {

        m_central_eff = CollectionContainer_Ptr(new CP::EffiCollection::CollectionContainer(*(other.m_central_eff)));
        m_calo_eff = CollectionContainer_Ptr(new CP::EffiCollection::CollectionContainer(*(other.m_calo_eff)));
        m_forward_eff = CollectionContainer_Ptr(new CP::EffiCollection::CollectionContainer(*(other.m_forward_eff)));
        m_lowpt_transition = other.m_lowpt_transition;
        m_sfType = other.m_sfType;
        if (m_lowpt_transition > 0) {
            m_lowpt_central_eff = CollectionContainer_Ptr(new CP::EffiCollection::CollectionContainer(*(other.m_lowpt_central_eff)));
            m_lowpt_calo_eff = CollectionContainer_Ptr(new CP::EffiCollection::CollectionContainer(*(other.m_lowpt_calo_eff)));
        }

    }
    CP::EffiCollection & EffiCollection::operator =(const CP::EffiCollection & other) {
        if (this == &other) {
            return *this;
        }
        m_lowpt_transition = other.m_lowpt_transition;
        m_sfType = other.m_sfType;

        m_central_eff.reset();
        m_calo_eff.reset();

        m_forward_eff.reset();

        m_lowpt_central_eff.reset();
        m_lowpt_calo_eff.reset();

        m_central_eff = CollectionContainer_Ptr(new CP::EffiCollection::CollectionContainer(*(other.m_central_eff)));
        m_calo_eff = CollectionContainer_Ptr(new CP::EffiCollection::CollectionContainer(*(other.m_calo_eff)));
        m_forward_eff = CollectionContainer_Ptr(new CP::EffiCollection::CollectionContainer(*(other.m_forward_eff)));
        if (m_lowpt_transition > 0) {
            m_lowpt_central_eff = CollectionContainer_Ptr(new CP::EffiCollection::CollectionContainer(*(other.m_lowpt_central_eff)));
            m_lowpt_calo_eff = CollectionContainer_Ptr(new CP::EffiCollection::CollectionContainer(*(other.m_lowpt_calo_eff)));
        }
        return *this;

    }
    EffiCollection::CollectionContainer_Ptr EffiCollection::FindContainer(const xAOD::Muon& mu) const {
        // yes, we need the second check - negative pt does happen!
        if (mu.pt() < m_lowpt_transition && m_lowpt_transition > 0) {
            if (fabs(mu.eta()) >= 2.5) {
                return m_forward_eff;
            }
            if (mu.author() == xAOD::Muon::CaloTag) {
                return m_lowpt_calo_eff;
            }
            return m_lowpt_central_eff;
        }
        if (mu.author() == xAOD::Muon::CaloTag) {
            return m_calo_eff;
        } else if (fabs(mu.eta()) < 2.5) {
            return m_central_eff;
        } else {
            return m_forward_eff;
        }
    }

    EfficiencyScaleFactor_Ptr EffiCollection::retrieveSF(const xAOD::Muon& mu, unsigned int RunNumber) const {
        EffiCollection::CollectionContainer_Ptr Cont = FindContainer(mu);
        if (Cont.get() != nullptr) return Cont->retrieve(RunNumber);
        Warning("retrieveSF()", "Invalid muon");
        return EfficiencyScaleFactor_Ptr();
    }
    std::string EffiCollection::sysname(void) const {
        if (m_central_eff) return m_central_eff->sysname();
        else return "";
    }
    unsigned int EffiCollection::nBins() const {
        unsigned int Nbins = 0;
        if (m_central_eff) {
            Nbins += m_central_eff->nBins();
        }
        if (m_calo_eff) {
            Nbins += m_calo_eff->nBins();
        }
        if (m_forward_eff) {
            Nbins += m_forward_eff->nBins();
        }
        if (m_lowpt_central_eff) {
            Nbins += m_lowpt_central_eff->nBins();
        }
        if (m_lowpt_calo_eff) {
            Nbins += m_lowpt_calo_eff->nBins();
        }
        return Nbins;
    }
    bool EffiCollection::SetSystematicBin(unsigned int Bin) {
        EffiCollection::CollectionContainer_Ptr Cont = FindContainerFromBin(Bin);
        if (!Cont) return false;
        return Cont->SetSystematicBin(Bin);
    }
    EffiCollection::CollectionContainer_Ptr EffiCollection::FindContainerFromBin(unsigned int &Bin) const {
        if (Bin > nBins()) {
            return nullptr;
        }
        if (DoesBinFitInRange(m_central_eff, Bin)) {
            return m_central_eff;
        } else if (DoesBinFitInRange(m_calo_eff, Bin)) {
            return m_calo_eff;
        } else if (DoesBinFitInRange(m_forward_eff, Bin)) {
            return m_forward_eff;
        } else if (DoesBinFitInRange(m_lowpt_central_eff, Bin)) {
            return m_lowpt_central_eff;
        } else if (DoesBinFitInRange(m_lowpt_calo_eff, Bin)) {
            return m_lowpt_calo_eff;
        }
        return nullptr;
    }
    bool EffiCollection::IsLowPtBin(unsigned int Bin) const {
        if (DoesBinFitInRange(m_central_eff, Bin)) {
            return false;
        } else if (DoesBinFitInRange(m_calo_eff, Bin)) {
            return false;
        } else if (DoesBinFitInRange(m_forward_eff, Bin)) {
            return false;
        }
        return true;
    }
    bool EffiCollection::IsForwardBin(unsigned int Bin) const {
        if (DoesBinFitInRange(m_central_eff, Bin)) {
            return false;
        } else if (DoesBinFitInRange(m_calo_eff, Bin)) {
            return false;
        }
        return DoesBinFitInRange(m_forward_eff, Bin);
    }
    bool EffiCollection::DoesBinFitInRange(CollectionContainer_Ptr Container, unsigned int & Bin) const {
        if (Container) {
            if (Bin <= Container->nBins()) {
                return true;
            } else {
                Bin -= Container->nBins();
            }
        }
        return false;
    }
    EffiCollection::~EffiCollection() {

        m_central_eff.reset();
        m_calo_eff.reset();
        m_forward_eff.reset();

        m_lowpt_central_eff.reset();
        m_lowpt_calo_eff.reset();
    }
    std::string EffiCollection::FileTypeName(EffiCollection::CollectionType T) {
        if (T == CollectionType::Central) return "Central ";
        if (T == CollectionType::Calo) return "Calo ";
        if (T == CollectionType::Forward) return "Forward ";
        if (T == CollectionType::CentralLowPt) return "CentralLowPt ";
        if (T == CollectionType::CaloLowPt) return "CaloLowPt ";
        return "EffiCollection::FileTypeName() - WARNING: Unknown EffiCollection::CollectionType!";
    }

    std::string EffiCollection::GetBinName(unsigned int bin) const {
        EffiCollection::CollectionContainer_Ptr Cont = FindContainerFromBin(bin);
        if (Cont) {
            std::string BinName = FileTypeName(Cont->type()) + Cont->GetBinName(bin);
            for (auto R : ToRemove) {
                BinName = ReplaceExpInString(BinName, R, "");
            }
            return BinName;
        }
        Warning("EffiCollection::GetBinName()", "Unknown bin %u", bin);
        return "UNKNOWN_BIN";
    }
    int EffiCollection::getUnCorrelatedSystBin(const xAOD::Muon& mu) const {
        int Bin = 0;
        if (DoesMuonEnterBin(CollectionType::Central, mu, Bin)) return Bin;
        if (DoesMuonEnterBin(CollectionType::Calo, mu, Bin)) return Bin;
        if (DoesMuonEnterBin(CollectionType::Forward, mu, Bin)) return Bin;
        if (DoesMuonEnterBin(CollectionType::CentralLowPt, mu, Bin)) return Bin;
        if (DoesMuonEnterBin(CollectionType::CaloLowPt, mu, Bin)) return Bin;
        return Bin;
    }
    bool EffiCollection::DoesMuonEnterBin(CollectionType Type, const xAOD::Muon mu, int &Bin) const {
        EffiCollection::CollectionContainer_Ptr MuonCont = FindContainer(mu);
        EffiCollection::CollectionContainer_Ptr TypeCont = retrieveContainer(Type);
        if (!TypeCont || TypeCont != MuonCont) {
            if (TypeCont) Bin += TypeCont->nBins();
            return false;
        }
        int sfBin = TypeCont->FindBinSF(mu);
        if (sfBin < 0) Bin = sfBin;
        else Bin += sfBin;
        return true;
    }

    std::string EffiCollection::ReplaceExpInString(std::string str, const std::string &exp, const std::string &rep) const {
        size_t ExpPos = str.find(exp);
        if (ExpPos == std::string::npos) return str;
        size_t ExpLen = exp.size();

        str = str.substr(0, ExpPos) + rep + str.substr(ExpPos + ExpLen, std::string::npos);
        if (str.find(exp) != std::string::npos) return ReplaceExpInString(str, exp, rep);
        return str;
    }

    //################################################################################
    //                               EffiCollection::CollectionContainer
    //################################################################################
    EffiCollection::CollectionContainer::CollectionContainer(const asg::AsgTool* ref_asg_tool,const std::string &FileName, MuonEfficiencySystType sysType, CP::MuonEfficiencyType effType, EffiCollection::CollectionType FileType, bool isLowPt, bool hasPtDepSys) :
                CollectionContainer(CollectionContainer_Ptr(),ref_asg_tool, FileName, sysType, effType, FileType, isLowPt, hasPtDepSys) {
    }

    EffiCollection::CollectionContainer::CollectionContainer(CollectionContainer_Ptr Nominal, const asg::AsgTool* ref_asg_tool, const std::string &FileName, MuonEfficiencySystType sysType, CP::MuonEfficiencyType effType, EffiCollection::CollectionType FileType, bool isLowPt, bool hasPtDepSys) :
                m_SF(),
                m_currentSF(),
                m_FileType(FileType) {
        std::unique_ptr<TFile> fin (TFile::Open(FileName.c_str()));
        if (!fin) {
            Error("CollectionContainer", "%s", ("Unable to open file " + FileName).c_str());
            return;
        }
        TTree* intree = 0;
        fin->GetObject("LumiData", intree);
        std::map<std::string, RunRanges> map;
        // if no Lumi tree is found, we assume that the SF are not binned in time
        if (!intree) {
            map["All"] = RunRanges(1, 999999);
        } else {
            std::string *period = 0;
            unsigned int firstRun = 0;
            unsigned int lastRun = 0;
            intree->SetBranchAddress("Period", &period);
            intree->SetBranchAddress("FirstRun", &firstRun);
            intree->SetBranchAddress("LastRun", &lastRun);
            for (int t = 0; intree->GetEntry(t); t++) {
                map[*period] = RunRanges(firstRun, lastRun);
            }
        }
        fin->Close();
        for (auto& period : map) {
            EfficiencyScaleFactor_Ptr effi_factor(nullptr);
            if (!Nominal) {
                effi_factor = EfficiencyScaleFactor_Ptr (new EfficiencyScaleFactor(ref_asg_tool->name()+FileTypeName(m_FileType), FileName, period.first, sysType, effType, isLowPt, hasPtDepSys));
            } else {
                effi_factor = EfficiencyScaleFactor_Ptr (new EfficiencyScaleFactor(Nominal->retrieve(period.second.first).get(),ref_asg_tool->name()+FileTypeName(m_FileType), FileName, period.first, sysType, effType, isLowPt, hasPtDepSys));
            }
            effi_factor->setFirstLastRun(period.second.first, period.second.second);
            m_SF.push_back(effi_factor);
        }
        for (auto& period : m_SF)
            period->ApplySysVariation();
    }
    bool EffiCollection::CollectionContainer::CheckConsistency() const {
        if (m_SF.empty()) {
            Error("CollectionContainer", "Could not retrieve any SFs from the input file");
            return false;
        }
        for (size_t i = 0 ; i < m_SF.size(); ++i)  {
            EfficiencyScaleFactor_Ptr first_SF = m_SF[i];
            if (!first_SF->CheckConsistency()) return false;
            for (size_t j = i+1 ; j < m_SF.size(); ++j) {
                EfficiencyScaleFactor_Ptr second_SF = m_SF[j];
                if (first_SF->coversRunNumber(second_SF->firstRun()) || first_SF->coversRunNumber( second_SF->lastRun()) || second_SF->coversRunNumber(first_SF->firstRun()) || second_SF->coversRunNumber( first_SF->lastRun())){
                    Error("CollectionContainer", "Overlapping periods observed in filetype %i. As run %i is in period %i - %i. Please check your SF file!",  (int) m_FileType, first_SF->firstRun(), second_SF->firstRun(), second_SF->lastRun());
                    return false;
                }
            }
        }
        return true;
    }
    bool EffiCollection::CollectionContainer::LoadPeriod(unsigned int RunNumber) const {
        if (!m_currentSF || !m_currentSF->coversRunNumber(RunNumber)) {
            for (auto& period : m_SF) {
                if (period->coversRunNumber(RunNumber)) {
                    m_currentSF = period;
                    return true;
                }
            }
        } else return true;
        Error("CollectionContainer", "Could not find any SF period matching the run number %u", RunNumber);
        return false;
    }
    std::shared_ptr<EfficiencyScaleFactor> EffiCollection::CollectionContainer::retrieve(unsigned int RunNumber) const {
        if (!LoadPeriod(RunNumber)) {
            return (*m_SF.begin());
        }
        return m_currentSF;
    }
    std::string EffiCollection::CollectionContainer::sysname() const {
        if (m_SF.empty()) return "";
        return (*m_SF.begin())->sysname();
    }
    EffiCollection::CollectionContainer::~CollectionContainer() {

    }
    CP::EffiCollection::CollectionContainer& EffiCollection::CollectionContainer::operator =(const EffiCollection::CollectionContainer & other) {
        if (this == &other) {
            return *this;
        }
        m_SF.clear();
        for (auto& period : other.m_SF) {
            m_SF.push_back(EfficiencyScaleFactor_Ptr (new EfficiencyScaleFactor(*period)));
        }
        m_currentSF = EfficiencyScaleFactor_Ptr();
        return *this;
    }
    EffiCollection::CollectionContainer::CollectionContainer(const CollectionContainer & other) :
                m_FileType(other.m_FileType) {
        for (auto& period : other.m_SF) {
            m_SF.push_back(EfficiencyScaleFactor_Ptr (new EfficiencyScaleFactor(*period)));
        }
        m_currentSF = EfficiencyScaleFactor_Ptr();
    }
    bool EffiCollection::CollectionContainer::SetSystematicBin(unsigned int Bin) {
        for (auto& Period : m_SF) {
            if (!Period->SetSystematicBin(Bin)) {
                return false;
            }
        }
        return true;
    }
    unsigned int EffiCollection::CollectionContainer::nBins() const {
        return (*m_SF.begin())->nBinsSF();
    }
    EffiCollection::CollectionType EffiCollection::CollectionContainer::type() const {
        return m_FileType;
    }
    std::string EffiCollection::CollectionContainer::GetBinName(unsigned int Bin) const {
        return (*m_SF.begin())->GetBinName(Bin);
    }
    int EffiCollection::CollectionContainer::FindBinSF(const xAOD::Muon &mu) const {
        return (*m_SF.begin())->FindBinSF(mu);
    }

}
