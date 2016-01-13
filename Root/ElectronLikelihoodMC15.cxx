#include "ttHMultilepton/ElectronLikelihoodMC15.h"

namespace ttHMultilepton {

  ElectronLikelihoodMC15::ElectronLikelihoodMC15(const bool isPrimaryxAOD,
						 const double ptcut,
						 const bool vetoCrack,
						 const std::string& operatingPoint,
						 const std::string& operatingPointLoose,
						 top::IsolationBase* isolation) :
    top::ElectronLikelihoodMC15(isPrimaryxAOD,
				ptcut,
				vetoCrack,
				operatingPoint,
				operatingPointLoose,
				isolation) {}
  
  bool ElectronLikelihoodMC15::passTTVACuts(const xAOD::Electron& el) const
  {

    if( !el.isAvailable<float>("d0sig") ){
      std::cout << "d0 significance not found for electron. "
		<< "Maybe no primary vertex? Won't accept." << std::endl;
      return false;
    }
  
    float d0sig = el.auxdataConst<float>("d0sig");
    if( std::abs(d0sig) >= 10 )
      return false;
  
    if( !el.isAvailable<float>("delta_z0_sintheta") ){
      std::cout << "delta z0*sin(theta) not found for electron. "
		<< "Maybe no primary vertex? Won't accept." << std::endl;
      return false;
    }
  
    float delta_z0_sintheta = el.auxdataConst<float>("delta_z0_sintheta");
    if( std::abs(delta_z0_sintheta) >= 2 )
      return false;
    
    return true;
  }
  
}
