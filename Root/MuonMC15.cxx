#include "ttHMultilepton/MuonMC15.h"

namespace ttHMultilepton {

  MuonMC15::MuonMC15(const double ptcut, top::IsolationBase* isolation):
    top::MuonMC15(ptcut, isolation) {}
  
  bool MuonMC15::passTTVACuts(const xAOD::Muon& mu) const
  {
    if( !mu.isAvailable<float>("d0sig") ){
      std::cout << "d0 significance not found for muon. "
		<< "Maybe no primary vertex? Won't accept." << std::endl;
      return false;
    }
  
    float d0sig = mu.auxdataConst<float>("d0sig");
    if( std::abs(d0sig) >= 10 )
      return false;
  
    if( !mu.isAvailable<float>("delta_z0_sintheta") ){
      std::cout << "delta z0*sin(theta) not found for muon. "
		<< "Maybe no primary vertex? Won't accept." << std::endl;
      return false;
    }
  
    float delta_z0_sintheta = mu.auxdataConst<float>("delta_z0_sintheta");
    if( std::abs(delta_z0_sintheta) >= 2 )
      return false;
    
    return true;
  }
  
}
