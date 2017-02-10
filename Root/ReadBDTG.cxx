#include <ttHMultilepton/ReadBDTG.h>
#include <cmath>


double ReadBDTG::GetMvaValue__( const std::vector<double>& inputValues ) const
{
   double myMVA = 0;
   for (unsigned int itree=0; itree<fForest.size(); itree++){
      BDTGNode *current = fForest[itree];
      while (current->GetNodeType() == 0) { //intermediate node
         if (current->GoesRight(inputValues)) current=(BDTGNode*)current->GetRight();
         else current=(BDTGNode*)current->GetLeft();
      }
      myMVA += current->GetResponse();
   }
   return 2.0/(1.0+exp(-2.0*myMVA))-1.0;
}



void ReadBDTG::Initialize()
{
  // itree = 0
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.942337,0.0833108) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.182489,-0.0659531) , 
1, 2.7619, 1, 0, 0.302952,-0.197048) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.817975,0.0608167) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.950312,0.0847299) , 
8, -0.0235332, 1, 0, 0.920003,0.420003) , 
5, 3865.34, 1, 0, 0.481032,-0.0189678)    );
  // itree = 1
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.850949,0.0626262) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203147,-0.0566581) , 
1, 3.57143, 1, 0, 0.352332,-0.134328) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.732446,0.0439139) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.933143,0.076711) , 
2, 44600.6, 1, 0, 0.886569,0.362945) , 
4, 0.210385, 1, 0, 0.498953,0.00214905)    );
  // itree = 2
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.868334,0.0607946) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.205561,-0.0509744) , 
1, 3.95238, 1, 0, 0.355558,-0.116661) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.730074,0.0341428) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.956181,0.0750998) , 
7, -1.30715, 1, 0, 0.930937,0.367476) , 
5, 4518.57, 1, 0, 0.506048,0.00996514)    );
  // itree = 3
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.742101,0.0433103) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.125506,-0.065929) , 
6, 1.13065, 1, 0, 0.289887,-0.1664) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.862801,0.0598454) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528708,0.00347648) , 
6, 4.29418, 1, 0, 0.820896,0.267902) , 
4, 0.152324, 1, 0, 0.487948,-0.00440985)    );
  // itree = 4
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.837404,0.0488437) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.132073,-0.0580182) , 
1, 3.09524, 1, 0, 0.298289,-0.144173) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69783,0.0299594) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989405,0.0725097) , 
5, 10239.8, 1, 0, 0.764791,0.196822) , 
4, 0.134633, 1, 0, 0.491201,-0.00316179)    );
  // itree = 5
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.889091,0.0611775) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351047,-0.024313) , 
3, 0.047619, 1, 0, 0.825495,0.250999) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163481,-0.0512873) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.822269,0.044541) , 
4, 0.2096, 1, 0, 0.313044,-0.127814) , 
6, 1.24223, 1, 0, 0.48969,0.00276542)    );
  // itree = 6
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918164,0.0571849) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22477,-0.0373039) , 
1, 2.33333, 1, 0, 0.327595,-0.10152) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.97403,0.0651539) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.842983,0.0412712) , 
1, 10.3333, 1, 0, 0.943115,0.27984) , 
5, 4512.83, 1, 0, 0.483688,-0.00480845)    );
  // itree = 7
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.951606,0.0604245) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605898,0.00711939) , 
6, 1.83169, 1, 0, 0.902968,0.243748) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.136684,-0.048496) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.766682,0.0343763) , 
4, 0.153289, 1, 0, 0.367339,-0.0712164) , 
1, 3.95238, 1, 0, 0.497484,0.00531231)    );
  // itree = 8
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.939897,0.061893) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.646952,0.0158524) , 
6, 0.80995, 1, 0, 0.848047,0.211326) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.197582,-0.0393028) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.878935,0.048188) , 
4, 0.228088, 1, 0, 0.349365,-0.0790046) , 
6, 1.11755, 1, 0, 0.510775,0.0149678)    );
  // itree = 9
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.960585,0.058389) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.218806,-0.0323328) , 
1, 2.7619, 1, 0, 0.347296,-0.0673777) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.704907,0.0152989) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.921854,0.050488) , 
2, 39317.8, 1, 0, 0.884967,0.191572) , 
4, 0.210021, 1, 0, 0.493061,0.0028247)    );
  // itree = 10
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.941178,0.0522287) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.213177,-0.0313488) , 
1, 2.33333, 1, 0, 0.322807,-0.0765001) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.988366,0.0608171) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.902014,0.0452522) , 
1, 6.52381, 1, 0, 0.948569,0.218804) , 
5, 4519.02, 1, 0, 0.486093,0.000556695)    );
  // itree = 11
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.935025,0.0566056) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.619958,0.0164545) , 
6, 0.817866, 1, 0, 0.803261,0.159224) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175692,-0.0343616) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.828669,0.0325466) , 
4, 0.2096, 1, 0, 0.353841,-0.0590415) , 
6, 1.29063, 1, 0, 0.52924,0.026143)    );
  // itree = 12
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.865109,0.0391124) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.121626,-0.0418274) , 
1, 3.38095, 1, 0, 0.296264,-0.0819374) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.826799,0.040082) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474571,-0.0275372) , 
7, 1.56356, 1, 0, 0.795051,0.139488) , 
4, 0.13457, 1, 0, 0.498291,0.00774804)    );
  // itree = 13
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.794064,0.0349894) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328917,-0.026217) , 
3, 0.047619, 1, 0, 0.719505,0.0945425) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.10806,-0.0482531) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.77938,0.0298831) , 
5, 2432.59, 1, 0, 0.294033,-0.0916453) , 
6, 1.71967, 1, 0, 0.497446,-0.0026312)    );
  // itree = 14
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.864972,0.0414124) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.408183,-0.0120517) , 
3, 0.047619, 1, 0, 0.813657,0.129147) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.144441,-0.0385404) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.749277,0.0279914) , 
5, 2445.52, 1, 0, 0.330995,-0.0595263) , 
6, 1.27753, 1, 0, 0.503117,0.00775625)    );
  // itree = 15
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996758,0.0547467) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.945082,0.0547305) , 
6, 0.918947, 1, 0, 0.97883,0.182476) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.212685,-0.0250545) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.83822,0.028826) , 
4, 0.190494, 1, 0, 0.419579,-0.0246519) , 
1, 2.7619, 1, 0, 0.51003,0.00884805)    );
  // itree = 16
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.249277,-0.0247635) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.7334,0.0331807) , 
5, 2414.64, 1, 0, 0.369198,-0.0306304) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.926759,0.0403907) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996608,0.0570009) , 
5, 10990.2, 1, 0, 0.957797,0.151745) , 
5, 5632.53, 1, 0, 0.499569,0.0097645)    );
  // itree = 17
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.730567,0.0270997) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.117595,-0.0357356) , 
1, 4.28571, 1, 0, 0.31856,-0.0461706) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.846083,0.0354447) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506703,-0.0422424) , 
8, 0.0568595, 1, 0, 0.814669,0.10114) , 
4, 0.152425, 1, 0, 0.502116,0.00833314)    );
  // itree = 18
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0526288,-0.0565435) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.191357,-0.0812128) , 
4, 0.130538, 1, 0, 0.0950211,-0.21103) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608172,0.0170373) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.207104,-0.0453086) , 
8, 0.0601958, 1, 0, 0.547179,0.0259866) , 
8, -0.0748369, 1, 0, 0.500579,0.00155911)    );
  // itree = 19
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.981401,0.0527475) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.89009,0.0242895) , 
7, 1.05955, 1, 0, 0.968185,0.142822) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.157498,-0.0270877) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.687317,0.0162407) , 
4, 0.11546, 1, 0, 0.40184,-0.0197802) , 
1, 2.47619, 1, 0, 0.506952,0.0103984)    );
  // itree = 20
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.843452,0.0388109) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48666,-0.00359116) , 
1, 5.14286, 1, 0, 0.684503,0.0623343) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.128743,-0.0350673) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.760839,0.0189845) , 
5, 2432.59, 1, 0, 0.301097,-0.0592157) , 
6, 1.90533, 1, 0, 0.508952,0.00667984)    );
  // itree = 21
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.655207,0.0184929) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.213866,-0.0247741) , 
1, 5.42857, 1, 0, 0.391228,-0.0222197) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.850615,0.00622913) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.974433,0.0486448) , 
8, -0.0352573, 1, 0, 0.958439,0.118416) , 
5, 5632.97, 1, 0, 0.513982,0.00821615)    );
  // itree = 22
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694904,0.000325682) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.147756,-0.05446) , 
6, 1.13195, 1, 0, 0.245242,-0.131046) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580067,0.0165434) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202379,-0.0426112) , 
7, 1.9734, 1, 0, 0.543849,0.0343373) , 
7, -1.2841, 1, 0, 0.496266,0.0079837)    );
  // itree = 23
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.961827,0.0451588) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252599,-0.0168731) , 
1, 2.7619, 1, 0, 0.376082,-0.0248927) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.910281,0.0260864) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.988141,0.052412) , 
7, -0.995692, 1, 0, 0.972954,0.120762) , 
5, 5632.97, 1, 0, 0.499657,0.00526329)    );
  // itree = 24
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0485182,-0.0663017) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.197912,-0.0294424) , 
8, -0.116419, 1, 0, 0.110456,-0.144841) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248852,-0.0425283) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581297,0.0128339) , 
7, -1.55788, 1, 0, 0.545834,0.0217954) , 
8, -0.0760158, 1, 0, 0.495261,0.00243885)    );
  // itree = 25
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.02986,-0.0769044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.256385,-0.0266864) , 
8, -0.113701, 1, 0, 0.128309,-0.151512) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.618413,0.0175121) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322664,-0.0279791) , 
8, 0.0343514, 1, 0, 0.544778,0.0197255) , 
8, -0.0732779, 1, 0, 0.49886,0.000845632)    );
  // itree = 26
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.736442,0.0170247) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163378,-0.0232531) , 
1, 4.52381, 1, 0, 0.360112,-0.0274067) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.842458,0.0198493) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.974642,0.0516755) , 
4, 0.320281, 1, 0, 0.888822,0.0888708) , 
4, 0.191158, 1, 0, 0.516359,0.00695628)    );
  // itree = 27
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.963044,0.0542122) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.681373,0.00998315) , 
6, 0.669229, 1, 0, 0.807791,0.0777329) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.136452,-0.0261563) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.657193,0.0119854) , 
5, 1907.3, 1, 0, 0.340944,-0.0269337) , 
6, 1.24223, 1, 0, 0.503203,0.00944459)    );
  // itree = 28
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.736005,0.0147684) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.240568,-0.0254707) , 
1, 5, 1, 0, 0.409115,-0.0339539) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.751063,0.034852) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.239274,-0.0300284) , 
6, 5.07651, 1, 0, 0.679393,0.07145) , 
2, 76730, 1, 0, 0.49723,0.000409495)    );
  // itree = 29
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0589435,-0.0585762) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597538,0.0134684) , 
8, -0.102606, 1, 0, 0.553811,0.0250276) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44223,-0.00579004) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.135119,-0.0519835) , 
8, 0.0753374, 1, 0, 0.229288,-0.103071) , 
8, 0.0554896, 1, 0, 0.505136,0.00581424)    );
  // itree = 30
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.240839,-0.0320715) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.607866,0.012122) , 
8, -0.0404055, 1, 0, 0.530631,0.0107784) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.245499,-0.0287572) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0792997,-0.0669584) , 
7, 0.699443, 1, 0, 0.179215,-0.118182) , 
8, 0.0677417, 1, 0, 0.492066,-0.00337388)    );
  // itree = 31
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.261691,-0.0337289) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578871,0.01258) , 
7, -1.38227, 1, 0, 0.525164,0.0140855) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.191174,-0.0414752) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.123768,-0.0645233) , 
8, 0.00418392, 1, 0, 0.155513,-0.146202) , 
7, 1.8449, 1, 0, 0.491482,-0.000519743)    );
  // itree = 32
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.870624,0.0268916) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.116692,-0.0265846) , 
1, 3.66667, 1, 0, 0.298579,-0.0344559) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518726,-0.0347477) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.824102,0.0279533) , 
7, -1.54516, 1, 0, 0.794823,0.0621549) , 
4, 0.133239, 1, 0, 0.500962,0.00494474)    );
  // itree = 33
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72064,0.0184819) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.124507,-0.0260164) , 
6, 1.13065, 1, 0, 0.296878,-0.0273199) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.779837,0.0238444) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311489,-0.0384246) , 
6, 5.11902, 1, 0, 0.74282,0.0519291) , 
4, 0.114423, 1, 0, 0.497919,0.00840734)    );
  // itree = 34
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.980596,0.0566199) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.594135,0.00591013) , 
6, 0.587079, 1, 0, 0.692964,0.0426069) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.192323,-0.033958) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407852,0.00925672) , 
0, 66616.2, 1, 0, 0.30694,-0.0305805) , 
6, 1.91844, 1, 0, 0.509882,0.00789581)    );
  // itree = 35
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.906004,0.0365869) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674885,-0.00597235) , 
6, 0.843166, 1, 0, 0.848526,0.0582017) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233526,-0.0163823) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.907117,0.0282887) , 
4, 0.266877, 1, 0, 0.344339,-0.0247369) , 
6, 1.09445, 1, 0, 0.50139,0.00109788)    );
  // itree = 36
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.751849,0.0138032) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.177797,-0.0221919) , 
6, 1.27753, 1, 0, 0.382534,-0.0230878) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.816022,-0.00223529) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954365,0.0396197) , 
7, -0.982979, 1, 0, 0.929958,0.0707299) , 
4, 0.247929, 1, 0, 0.488828,-0.004871)    );
  // itree = 37
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.740408,0.017215) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0785558,-0.0333126) , 
1, 4.61905, 1, 0, 0.280861,-0.0380928) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.73602,0.0198721) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319619,-0.0423985) , 
7, 1.84532, 1, 0, 0.706446,0.0395809) , 
4, 0.0965829, 1, 0, 0.511535,0.00400767)    );
  // itree = 38
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.251586,-0.0283985) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58919,0.014875) , 
7, -1.36962, 1, 0, 0.534023,0.0204925) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233573,-0.0238962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0983165,-0.0774192) , 
7, 2.55761, 1, 0, 0.184871,-0.100311) , 
7, 1.85341, 1, 0, 0.500375,0.00885045)    );
  // itree = 39
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350331,-0.0185021) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617296,0.0148086) , 
8, -0.038237, 1, 0, 0.569074,0.0230561) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.120471,-0.04426) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453025,0.000733989) , 
0, 135409, 1, 0, 0.209342,-0.0732345) , 
6, 4.24829, 1, 0, 0.51538,0.0086837)    );
  // itree = 40
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.891299,0.0322109) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.638512,-0.0151924) , 
7, 1.15751, 1, 0, 0.853953,0.0552558) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.237455,-0.0172027) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.913495,0.0262538) , 
4, 0.266231, 1, 0, 0.362643,-0.0252618) , 
6, 1.10541, 1, 0, 0.514035,-0.000451108)    );
  // itree = 41
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0406321,-0.0580153) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395632,-0.00147946) , 
8, -0.0916708, 1, 0, 0.357397,-0.0149556) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9596,0.0408445) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971562,0.0330843) , 
4, 0.205655, 1, 0, 0.968275,0.060657) , 
5, 5632.53, 1, 0, 0.486955,0.00108069)    );
  // itree = 42
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.783249,0.0139066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.205814,-0.0143918) , 
6, 1.27753, 1, 0, 0.422373,-0.00935891) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.885108,0.0359011) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.985481,0.0411215) , 
5, 4903.09, 1, 0, 0.955315,0.0778881) , 
4, 0.266322, 1, 0, 0.508371,0.00471964)    );
  // itree = 43
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310767,-0.0123204) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680171,0.0161249) , 
4, 0.076352, 1, 0, 0.541101,0.0143958) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247359,-0.0203856) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.113254,-0.0609069) , 
7, 0.706323, 1, 0, 0.196574,-0.0830135) , 
8, 0.0702666, 1, 0, 0.504092,0.00393213)    );
  // itree = 44
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.171958,-0.0483283) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577336,0.0106814) , 
7, -1.85588, 1, 0, 0.546608,0.0154488) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.187549,-0.0304847) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0664471,-0.065645) , 
7, 0.701749, 1, 0, 0.132022,-0.0973383) , 
8, 0.0714358, 1, 0, 0.500803,0.00298756)    );
  // itree = 45
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.23268,-0.0355775) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.595852,0.0083662) , 
7, -1.37867, 1, 0, 0.538383,0.0045322) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258501,-0.0559339) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0880162,-0.0309936) , 
6, 2.23821, 1, 0, 0.174164,-0.0970603) , 
7, 1.85733, 1, 0, 0.507101,-0.00419347)    );
  // itree = 46
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721699,0.00660664) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208046,-0.0288464) , 
1, 4.04762, 1, 0, 0.394638,-0.0373804) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.297629,-0.0161679) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.807802,0.0302443) , 
4, 0.0777179, 1, 0, 0.606808,0.027248) , 
2, 61187.1, 1, 0, 0.4978,-0.00595638)    );
  // itree = 47
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.74199,0.0150241) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0566157,-0.0383503) , 
1, 4.57143, 1, 0, 0.270677,-0.0386641) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.429343,-0.0225883) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.71014,0.0189391) , 
2, 40281.3, 1, 0, 0.635694,0.0153195) , 
4, 0.0779317, 1, 0, 0.489118,-0.00635813)    );
  // itree = 48
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.701948,0.0124843) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167655,-0.032532) , 
1, 4.57143, 1, 0, 0.387317,-0.0280714) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613655,0.0175796) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.112323,-0.051722) , 
6, 7.50951, 1, 0, 0.582308,0.0289604) , 
2, 51750.1, 1, 0, 0.503897,0.00602646)    );
  // itree = 49
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.994508,0.0542549) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.318127,-0.0184416) , 
1, 1.80952, 1, 0, 0.391972,-0.0290305) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311232,-0.0146411) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.809211,0.0283864) , 
4, 0.0784842, 1, 0, 0.610802,0.025159) , 
2, 63377.3, 1, 0, 0.490236,-0.00469708)    );
  // itree = 50
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0228655,-0.0535342) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.20048,-0.0550925) , 
5, 1100.71, 1, 0, 0.107606,-0.0999502) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312366,-0.00950617) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.793036,0.0129278) , 
4, 0.133251, 1, 0, 0.528908,0.00279831) , 
7, -1.85764, 1, 0, 0.490552,-0.00655597)    );
  // itree = 51
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0487489,-0.0557294) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362819,-0.00360816) , 
8, -0.0928863, 1, 0, 0.138976,-0.0738777) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.630962,0.0208427) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307067,-0.0145951) , 
8, 0.0363518, 1, 0, 0.54937,0.0283716) , 
8, -0.0722079, 1, 0, 0.509459,0.0184278)    );
  // itree = 52
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.773003,0.0214929) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.33574,-0.0176415) , 
3, 0.047619, 1, 0, 0.700693,0.032201) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.225901,-0.0235852) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.438872,0.00578962) , 
0, 78595.5, 1, 0, 0.317183,-0.0248882) , 
6, 1.90533, 1, 0, 0.519782,0.00527061)    );
  // itree = 53
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.760395,0.0185088) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335038,-0.0184035) , 
3, 0.047619, 1, 0, 0.69004,0.0263924) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.127681,-0.045159) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.370578,-0.00195006) , 
7, -0.992393, 1, 0, 0.308948,-0.0240958) , 
6, 1.90533, 1, 0, 0.50331,0.0016539)    );
  // itree = 54
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579179,0.00937967) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.180977,-0.0423041) , 
7, 2.11951, 1, 0, 0.554784,0.0143192) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.182122,-0.0434563) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.194378,-0.0157674) , 
0, 64852.9, 1, 0, 0.187035,-0.0601674) , 
8, 0.0682065, 1, 0, 0.510531,0.00535584)    );
  // itree = 55
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244347,-0.0133577) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.741297,0.0217386) , 
5, 2785.11, 1, 0, 0.313146,-0.0141924) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588685,-0.0168392) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.812136,0.0195398) , 
8, -0.0447535, 1, 0, 0.779971,0.0333727) , 
4, 0.13331, 1, 0, 0.508876,0.00575061)    );
  // itree = 56
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.948266,0.018731) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 1,0.059322) , 
0, 45785.3, 1, 0, 0.95706,0.0418127) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.223079,-0.022341) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475071,0.00279544) , 
2, 45657.8, 1, 0, 0.395978,-0.0132125) , 
1, 2.38095, 1, 0, 0.490722,-0.00392105)    );
  // itree = 57
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.242593,-0.0460895) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376509,-0.0106638) , 
7, -0.692203, 1, 0, 0.33004,-0.0456217) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.688393,0.0222073) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385567,-0.0145982) , 
8, 0.0237603, 1, 0, 0.573798,0.0196961) , 
8, -0.0252597, 1, 0, 0.50827,0.00213709)    );
  // itree = 58
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0165916,-0.0473779) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.11815,-0.052394) , 
5, 1184.09, 1, 0, 0.0584848,-0.0765347) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.585576,0.00898519) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.133465,-0.0383412) , 
8, 0.0789161, 1, 0, 0.539406,0.0107991) , 
8, -0.0982992, 1, 0, 0.501834,0.00397626)    );
  // itree = 59
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.724698,0.0186315) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.158784,-0.0385448) , 
3, 0.047619, 1, 0, 0.645866,0.0219528) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0912035,-0.05116) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421184,-0.00515634) , 
2, 44937.5, 1, 0, 0.362595,-0.0287521) , 
1, 6.28571, 1, 0, 0.500966,-0.003984)    );
  // itree = 60
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.948676,0.0289793) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.139182,-0.021269) , 
1, 2.33333, 1, 0, 0.287497,-0.0256301) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.695375,0.0154593) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56163,-0.035302) , 
1, 14.7143, 1, 0, 0.686126,0.0247832) , 
4, 0.0952474, 1, 0, 0.500319,0.00128475)    );
  // itree = 61
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316745,-0.00467721) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.717215,0.0156716) , 
4, 0.0969519, 1, 0, 0.540157,0.015145) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.20654,-0.0265191) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0796076,-0.0780903) , 
7, 2.55233, 1, 0, 0.143945,-0.0790191) , 
7, 2.1427, 1, 0, 0.517746,0.00981888)    );
  // itree = 62
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0388164,-0.0544631) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.240318,-0.0543481) , 
5, 1607.2, 1, 0, 0.117905,-0.0844409) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57006,0.0082274) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.139182,-0.0438781) , 
8, 0.101006, 1, 0, 0.540883,0.0109918) , 
7, -1.85704, 1, 0, 0.507071,0.00336305)    );
  // itree = 63
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.964536,0.0417434) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388922,-0.0070499) , 
6, 0.640191, 1, 0, 0.489953,-0.00328281) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.779088,0.064349) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.300403,-0.0040628) , 
6, 6.01082, 1, 0, 0.595641,0.0723354) , 
0, 132062, 1, 0, 0.49808,0.00253225)    );
  // itree = 64
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575881,-0.00784265) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221612,-0.0342829) , 
1, 5.95238, 1, 0, 0.342606,-0.0459903) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344656,-0.00555686) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694904,0.0147801) , 
4, 0.0775898, 1, 0, 0.558222,0.0157537) , 
8, -0.0276375, 1, 0, 0.506102,0.000828542)    );
  // itree = 65
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996805,0.0595002) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.43916,-0.0214504) , 
6, 0.509015, 1, 0, 0.546915,-0.0253538) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513156,0.0228153) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222139,-0.0167307) , 
6, 4.42018, 1, 0, 0.428272,0.0237533) , 
0, 51633.9, 1, 0, 0.491058,-0.00223407)    );
  // itree = 66
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954293,0.0402493) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388921,-0.0037069) , 
6, 0.783474, 1, 0, 0.50416,0.00489644) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.103269,-0.0782499) , 
6, 7.84695, 1, 0, 0.490886,0.000261368)    );
  // itree = 67
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.256036,-0.0284802) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.960466,0.027011) , 
5, 5844.06, 1, 0, 0.376747,-0.0392919) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597629,0.0151328) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35094,-0.0146287) , 
8, 0.0285354, 1, 0, 0.536991,0.0163518) , 
7, -0.710708, 1, 0, 0.489651,-8.68728e-05)    );
  // itree = 68
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516155,0.000415101) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503749,0.0255868) , 
0, 69869, 1, 0, 0.513073,0.0131385) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.123574,-0.0423958) , 
6, 7.4589, 1, 0, 0.497682,0.00949526)    );
  // itree = 69
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0964658,-0.022203) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344525,-0.0374146) , 
5, 1997.22, 1, 0, 0.173213,-0.0518194) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346254,-0.00302483) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.673384,0.0164462) , 
4, 0.0762161, 1, 0, 0.55052,0.019487) , 
7, -1.85408, 1, 0, 0.518243,0.0133869)    );
  // itree = 70
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996458,0.0540454) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456253,-0.00326134) , 
1, 1.66667, 1, 0, 0.510895,0.000139193) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.33847,-0.0667825) , 
1, 15.6667, 1, 0, 0.504683,-0.00475211)    );
  // itree = 71
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.279989,-0.0152236) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603677,0.00916895) , 
7, -1.14731, 1, 0, 0.53743,0.0093111) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.255514,-0.0124793) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0994493,-0.0496243) , 
7, 2.18423, 1, 0, 0.153854,-0.0548252) , 
7, 1.85657, 1, 0, 0.502212,0.00342253)    );
  // itree = 72
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.929467,0.0230626) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.224569,-0.0304721) , 
1, 3, 1, 0, 0.314988,-0.0403422) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363663,-0.00259993) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.834323,0.0174061) , 
4, 0.133262, 1, 0, 0.574194,0.0129438) , 
8, -0.0289475, 1, 0, 0.509669,-0.000320812)    );
  // itree = 73
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971377,0.0357166) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313525,-0.0184796) , 
1, 1.7619, 1, 0, 0.386574,-0.0291008) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289933,-0.0171934) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.73381,0.0207831) , 
4, 0.0587458, 1, 0, 0.58707,0.0164861) , 
2, 59115.4, 1, 0, 0.485128,-0.00669259)    );
  // itree = 74
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.210517,-0.0399111) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.173406,-0.010663) , 
8, 0.0365143, 1, 0, 0.200813,-0.0557326) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572097,0.0097998) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.137718,-0.0422655) , 
7, 2.13005, 1, 0, 0.54074,0.0134294) , 
7, -1.56257, 1, 0, 0.500716,0.00528623)    );
  // itree = 75
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.829294,0.0237583) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345867,-0.00890054) , 
6, 2.14991, 1, 0, 0.738503,0.0315668) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.216478,-0.0140221) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9416,0.0230517) , 
4, 0.267263, 1, 0, 0.348048,-0.0167924) , 
1, 5.14286, 1, 0, 0.499773,0.00199932)    );
  // itree = 76
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208566,-0.0295656) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.660365,0.0138612) , 
8, -0.0480289, 1, 0, 0.563925,0.0120362) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.265399,-0.0276042) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529762,0.0128177) , 
2, 82963.8, 1, 0, 0.331586,-0.0334583) , 
8, 0.0261276, 1, 0, 0.50147,-0.000193116)    );
  // itree = 77
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523382,0.00280272) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296174,-0.0231824) , 
7, 1.28591, 1, 0, 0.481125,-0.00367347) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.691204,0.0840598) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918204,-0.0111726) , 
4, 0.192, 1, 0, 0.799434,0.0695688) , 
2, 148894, 1, 0, 0.499344,0.000518777)    );
  // itree = 78
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.030664,-0.0676417) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559852,0.0068242) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.21844,-0.0219537) , 
7, 1.57124, 1, 0, 0.518382,0.00723091) , 
8, -0.131659, 1, 0, 0.494425,0.00288076)    );
  // itree = 79
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316653,-0.0221375) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597463,0.00840855) , 
8, -0.0371552, 1, 0, 0.54565,0.00629876) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.943512,0.0497983) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230273,-0.0366172) , 
1, 3.28571, 1, 0, 0.339318,-0.0403739) , 
7, 1.00076, 1, 0, 0.497783,-0.0045287)    );
  // itree = 80
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.699455,0.00386317) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.198401,-0.024408) , 
6, 1.75952, 1, 0, 0.492836,-0.0153593) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102658,-0.0194216) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.675812,0.0311888) , 
4, 0.0583158, 1, 0, 0.498756,0.0370263) , 
0, 78532.9, 1, 0, 0.494331,-0.0021306)    );
  // itree = 81
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 1,0.0551058) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.92474,0.00323699) , 
1, 1.04762, 1, 0, 0.964927,0.0313858) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367564,-0.011408) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437359,0.00866331) , 
0, 69882.4, 1, 0, 0.391112,-0.010316) , 
1, 2.38095, 1, 0, 0.492011,-0.00298321)    );
  // itree = 82
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.377111,-0.00635521) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.687342,0.0134326) , 
8, -0.0237608, 1, 0, 0.572312,0.0125089) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.176785,-0.0222052) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.849059,0.0135627) , 
5, 3216.52, 1, 0, 0.348414,-0.0207167) , 
8, 0.0257083, 1, 0, 0.509389,0.00317139)    );
  // itree = 83
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0435684,-0.043738) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.210679,-0.0533782) , 
5, 1037.88, 1, 0, 0.12852,-0.0747453) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581382,-0.00724864) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.443572,0.00964162) , 
0, 48903, 1, 0, 0.514537,0.00148233) , 
7, -2.13793, 1, 0, 0.494099,-0.00255367)    );
  // itree = 84
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513132,-0.00223153) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.848635,0.0454741) , 
2, 211384, 1, 0, 0.523682,-0.00145148) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175958,-0.0402643) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.184311,-0.0131369) , 
0, 64834.4, 1, 0, 0.179659,-0.0449916) , 
8, 0.0678292, 1, 0, 0.48474,-0.00637994)    );
  // itree = 85
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0356565,-0.0296867) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0866764,-0.0497782) , 
4, 0.109773, 1, 0, 0.0525185,-0.0480982) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329173,-0.0104149) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617424,0.00885812) , 
4, 0.0590127, 1, 0, 0.52952,0.00635473) , 
8, -0.0982992, 1, 0, 0.491099,0.00196863)    );
  // itree = 86
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.958818,0.0252411) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.299875,-0.00622033) , 
1, 2.7619, 1, 0, 0.413223,-0.005095) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.967659,0.0411317) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.900292,-0.00619316) , 
1, 10.9048, 1, 0, 0.947974,0.0368862) , 
4, 0.267391, 1, 0, 0.498267,0.00158151)    );
  // itree = 87
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.700313,0.0178505) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.201409,-0.030911) , 
6, 1.49284, 1, 0, 0.360567,-0.0307594) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384921,-0.0177872) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599433,0.0102319) , 
7, -0.996138, 1, 0, 0.550568,0.00643106) , 
2, 41537.9, 1, 0, 0.500219,-0.00342414)    );
  // itree = 88
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.99565,0.0557958) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512277,-6.74231e-05) , 
6, 0.407717, 1, 0, 0.557214,0.00542805) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.201962,-0.0162609) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.272296,-0.056256) , 
1, 14.3333, 1, 0, 0.213382,-0.0409503) , 
6, 3.76187, 1, 0, 0.490766,-0.00353492)    );
  // itree = 89
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562854,-0.00253356) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504567,0.0138967) , 
0, 69903.6, 1, 0, 0.545981,0.00403157) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27578,-0.0143024) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.189137,-0.051288) , 
1, 11, 1, 0, 0.259483,-0.0353818) , 
7, 1.28091, 1, 0, 0.493741,-0.00315499)    );
  // itree = 90
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202861,-0.0331265) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49176,-0.001765) , 
8, -0.0538983, 1, 0, 0.309223,-0.0319937) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597474,0.00901709) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202876,-0.0227534) , 
6, 4.24829, 1, 0, 0.541171,0.00870274) , 
8, -0.0321214, 1, 0, 0.486794,-0.000838005)    );
  // itree = 91
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.782153,0.0204319) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403439,-0.00489221) , 
1, 5.14286, 1, 0, 0.565147,0.00956904) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359867,-0.0197945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22359,-0.0719315) , 
1, 11.9524, 1, 0, 0.341889,-0.0453416) , 
8, 0.0240742, 1, 0, 0.502597,-0.00581518)    );
  // itree = 92
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.709104,0.0133604) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.153387,-0.0308073) , 
3, 0.047619, 1, 0, 0.629745,0.0120692) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.352154,-0.0231341) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347786,0.00998632) , 
3, 0.047619, 1, 0, 0.350259,-0.0196498) , 
1, 6.52381, 1, 0, 0.487811,-0.00403901)    );
  // itree = 93
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364895,-0.00665502) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.236239,0.0389877) , 
0, 104614, 1, 0, 0.352111,-0.00405775) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.89244,0.027933) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806078,-0.0351949) , 
0, 137202, 1, 0, 0.882366,0.0364585) , 
4, 0.19041, 1, 0, 0.507407,0.00780828)    );
  // itree = 94
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493128,0.000406022) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.845613,0.0297778) , 
4, 0.0972461, 1, 0, 0.684065,0.0233516) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.140418,-0.0347751) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339475,0.00303904) , 
0, 44110.3, 1, 0, 0.302096,-0.00783361) , 
6, 1.89226, 1, 0, 0.492762,0.00773298)    );
  // itree = 95
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.267903,-0.0161999) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543239,0.00746778) , 
7, -1.28619, 1, 0, 0.498146,0.00701458) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388422,-0.0562055) , 
1, 16.8571, 1, 0, 0.495132,0.00412188)    );
  // itree = 96
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26834,-0.0102058) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.854035,0.0120209) , 
5, 2560.41, 1, 0, 0.501023,-0.00281318) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694904,0.0461503) , 
0, 185592, 1, 0, 0.507836,-0.000101289)    );
  // itree = 97
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.842658,0.0449308) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.815828,0.000645735) , 
4, 0.0392876, 1, 0, 0.822308,0.0226308) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.391534,0.00168991) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.186835,-0.0207359) , 
7, 1.01154, 1, 0, 0.337898,-0.00608655) , 
1, 4.52381, 1, 0, 0.489362,0.00289267)    );
  // itree = 98
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524239,0.000902581) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0511833,-0.047429) , 
8, 0.117758, 1, 0, 0.492529,-0.00171695) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447462,-0.0686095) , 
1, 16.8571, 1, 0, 0.491333,-0.00515201)    );
  // itree = 99
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.950188,0.0402937) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986711,0.0275912) , 
2, 35647.8, 1, 0, 0.975785,0.0367616) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306969,-0.0105383) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570384,0.0120708) , 
2, 73106.9, 1, 0, 0.404989,-0.00403709) , 
1, 2.7619, 1, 0, 0.507514,0.00329104)    );
  // itree = 100
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.36945,0.00907578) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.229696,-0.0146054) , 
4, 0.0438549, 1, 0, 0.287454,-0.00877485) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.744159,0.0139006) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.647238,-0.0234457) , 
1, 13.3333, 1, 0, 0.73313,0.015856) , 
4, 0.114489, 1, 0, 0.491801,0.00251866)    );
  // itree = 101
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248412,-0.00536457) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.83768,0.0123168) , 
5, 2492.91, 1, 0, 0.483014,0.00253829) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.747535,0.0507087) , 
0, 184795, 1, 0, 0.491632,0.00516827)    );
  // itree = 102
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404459,-0.000801942) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.953893,0.0287307) , 
4, 0.265824, 1, 0, 0.502515,0.00533255) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0989094,-0.0644004) , 
6, 8.66077, 1, 0, 0.490159,0.00211327)    );
  // itree = 103
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.688687,0.0196595) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.695956,0.00354914) , 
7, -0.438754, 1, 0, 0.693333,0.0159634) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262298,-0.0227136) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310198,0.0171347) , 
3, 0.047619, 1, 0, 0.280795,-0.0164223) , 
6, 1.90533, 1, 0, 0.492869,0.000226286)    );
  // itree = 104
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501596,0.0494106) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.259737,-0.0216002) , 
4, 0.0126948, 1, 0, 0.284183,-0.0178497) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614753,0.00996843) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512988,-0.00643169) , 
7, 0.430151, 1, 0, 0.576795,0.00729388) , 
4, 0.0587172, 1, 0, 0.490875,-8.90607e-05)    );
  // itree = 105
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.869844,0.0184875) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351667,-0.0053125) , 
6, 1.04828, 1, 0, 0.503432,0.000912856) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.165862,-0.0361906) , 
6, 7.04381, 1, 0, 0.487201,-0.0018135)    );
  // itree = 106
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.904178,0.0286161) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0761876,-0.0255705) , 
1, 3.66667, 1, 0, 0.295071,-0.0150738) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.743667,-0.00388097) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.645474,0.0224161) , 
1, 6.28571, 1, 0, 0.69391,0.0212759) , 
4, 0.0953875, 1, 0, 0.517822,0.00522747)    );
  // itree = 107
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.723403,0.00822518) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.662672,0.0534611) , 
0, 69161.7, 1, 0, 0.717233,0.0226016) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382183,-0.0114319) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32556,0.00966385) , 
3, 0.047619, 1, 0, 0.359839,-0.00744305) , 
1, 5.42857, 1, 0, 0.499188,0.00427148)    );
  // itree = 108
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.710143,-0.00116237) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503291,0.0173199) , 
0, 43762, 1, 0, 0.640748,0.00934679) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.14063,-0.0365994) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431374,-0.00339044) , 
2, 50535.9, 1, 0, 0.355677,-0.0188615) , 
1, 6.33333, 1, 0, 0.500703,-0.00451097)    );
  // itree = 109
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518961,0.00152354) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511785,0.022072) , 
0, 78532.1, 1, 0, 0.517291,0.0100827) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0276825,-0.0510699) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.141506,-0.0554522) , 
5, 1197.86, 1, 0, 0.0866764,-0.0739966) , 
7, 2.14024, 1, 0, 0.493179,0.00537473)    );
  // itree = 110
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526809,-0.00718192) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470379,0.0177366) , 
0, 66682.9, 1, 0, 0.509731,0.00031094) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407201,-0.0506284) , 
1, 15.7619, 1, 0, 0.506196,-0.00300998)    );
  // itree = 111
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.122782,-0.0477099) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.402511,-0.0138158) , 
7, -2.02074, 1, 0, 0.318493,-0.0371494) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434347,-0.00585322) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.692287,0.012052) , 
2, 65994.1, 1, 0, 0.54098,0.0010951) , 
7, -0.977693, 1, 0, 0.48935,-0.00777977)    );
  // itree = 112
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497815,-0.00148833) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548255,0.0302111) , 
0, 114737, 1, 0, 0.503032,0.00249531) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44517,-0.052186) , 
1, 17.2381, 1, 0, 0.501508,-0.000573467)    );
  // itree = 113
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.701844,0.0125071) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.183094,-0.0274864) , 
3, 0.047619, 1, 0, 0.62637,0.01124) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0250078,-0.0502188) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403557,-0.00763124) , 
4, 0.038281, 1, 0, 0.345454,-0.0214058) , 
1, 6.28571, 1, 0, 0.490417,-0.00455936)    );
  // itree = 114
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.210679,-0.000962509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357481,-0.0398548) , 
7, -1.76242, 1, 0, 0.277618,-0.0335684) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537028,0.00106084) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.593186,0.0331749) , 
0, 114745, 1, 0, 0.542996,0.00709536) , 
7, -1.27309, 1, 0, 0.502387,0.000872766)    );
  // itree = 115
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582969,-0.00685104) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374146,0.020354) , 
3, 0.047619, 1, 0, 0.529836,-0.000181854) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0720526,-0.0320984) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.259483,-0.0424039) , 
4, 0.118219, 1, 0, 0.129709,-0.044612) , 
8, 0.0714358, 1, 0, 0.483954,-0.00527651)    );
  // itree = 116
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893792,0.00159291) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440348,0.0165742) , 
1, 3.14286, 1, 0, 0.657887,0.0171395) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302717,-0.0118637) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954686,0.037351) , 
4, 0.323389, 1, 0, 0.380782,-0.0120452) , 
1, 6.90476, 1, 0, 0.52104,0.00272678)    );
  // itree = 117
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548975,-0.00132506) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.553066,0.0249006) , 
1, 9.66667, 1, 0, 0.549807,0.00730198) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.142204,-0.0460537) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.213618,0.016989) , 
3, 0.047619, 1, 0, 0.172869,-0.0280122) , 
6, 5.0883, 1, 0, 0.510745,0.00364236)    );
  // itree = 118
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517019,-0.00712162) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458305,0.0139862) , 
0, 69448.9, 1, 0, 0.500358,-0.00180582) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437087,-0.0385223) , 
1, 16.8571, 1, 0, 0.498744,-0.00376511)    );
  // itree = 119
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.940032,0.0236044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428302,-0.00311434) , 
6, 0.773425, 1, 0, 0.539168,0.00049386) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.136433,-0.0467617) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.162048,0.0146572) , 
3, 0.047619, 1, 0, 0.146347,-0.0338501) , 
6, 5.0883, 1, 0, 0.495556,-0.00331908)    );
  // itree = 120
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.957287,0.017309) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390097,-0.00387395) , 
1, 2.09524, 1, 0, 0.502521,-0.00201119) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.755161,0.0559205) , 
0, 185593, 1, 0, 0.510639,0.000955588)    );
  // itree = 121
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0565488,-0.0211012) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.207211,-0.05752) , 
5, 1568.02, 1, 0, 0.121808,-0.0692091) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.301789,-0.0110202) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.65226,0.00914885) , 
4, 0.0776328, 1, 0, 0.517872,0.00338772) , 
7, -2.1263, 1, 0, 0.494046,-0.000979581)    );
  // itree = 122
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479841,-0.00764528) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304297,0.0129702) , 
0, 49211.3, 1, 0, 0.415956,-0.000833464) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.676099,0.0191325) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202818,-0.0230736) , 
6, 7.50872, 1, 0, 0.633785,0.0211691) , 
2, 66794.9, 1, 0, 0.511548,0.00882214)    );
  // itree = 123
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.142731,-0.0484875) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.149976,0.00355544) , 
1, 8, 1, 0, 0.146033,-0.0298549) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332869,-0.00161137) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.734111,0.0144412) , 
4, 0.0965492, 1, 0, 0.551258,0.0117386) , 
8, -0.0695975, 1, 0, 0.501276,0.00660829)    );
  // itree = 124
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.946792,0.0305632) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411662,-0.00235421) , 
6, 0.627177, 1, 0, 0.496123,0.0012132) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328917,0.0554445) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893728,0.000866323) , 
4, 0.192715, 1, 0, 0.616742,0.0508469) , 
0, 132062, 1, 0, 0.505469,0.00505919)    );
  // itree = 125
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.762088,0.0138007) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.391734,-0.00254841) , 
1, 5.14286, 1, 0, 0.546593,0.00601708) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527317,-0.0561244) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.191215,-0.00786657) , 
6, 1.18978, 1, 0, 0.257389,-0.028754) , 
7, 1.2883, 1, 0, 0.496662,1.3859e-05)    );
  // itree = 126
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392722,-0.00138545) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.835924,-0.033093) , 
4, 0.245917, 1, 0, 0.431161,-0.00575634) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.936422,0.0207703) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.970611,0.0500284) , 
4, 0.366506, 1, 0, 0.946747,0.0392382) , 
4, 0.303426, 1, 0, 0.489091,-0.00070089)    );
  // itree = 127
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.934199,0.0282495) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.993833,0.0341004) , 
2, 40289.4, 1, 0, 0.969217,0.0281454) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345923,-0.0193354) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.436365,0.00303467) , 
7, -0.422219, 1, 0, 0.402435,-0.0081212) , 
1, 2.7619, 1, 0, 0.504364,-0.00159907)    );
  // itree = 128
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524367,-0.000120355) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.137117,-0.0254736) , 
6, 5.11493, 1, 0, 0.485753,-0.00359409) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466377,-0.0359073) , 
1, 17, 1, 0, 0.485246,-0.00535615)    );
  // itree = 129
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582429,0.0104444) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.115487,-0.0217686) , 
8, 0.102602, 1, 0, 0.552699,0.0145266) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0538737,-0.00677402) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545534,-0.0450567) , 
4, 0.170468, 1, 0, 0.181376,-0.0342201) , 
6, 5.11528, 1, 0, 0.515116,0.00959278)    );
  // itree = 130
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364038,0.00603067) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208113,0.0554926) , 
0, 120620, 1, 0, 0.353359,0.0138796) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.801567,-0.0177224) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.751067,0.0150733) , 
3, 0.047619, 1, 0, 0.788171,-0.0125961) , 
4, 0.153538, 1, 0, 0.517777,0.00386815)    );
  // itree = 131
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0834988,-0.0724324) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0453015,-0.0341715) , 
6, 2.52344, 1, 0, 0.0624397,-0.0449714) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.153003,-0.0211081) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55254,0.0113185) , 
7, -2.13274, 1, 0, 0.528529,0.0165041) , 
8, -0.112746, 1, 0, 0.500481,0.0128047)    );
  // itree = 132
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989745,0.0510043) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407128,-0.00163181) , 
6, 0.589189, 1, 0, 0.489572,0.00262233) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555225,-0.00176083) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697598,0.0641706) , 
3, 0.047619, 1, 0, 0.629901,0.0464862) , 
0, 132079, 1, 0, 0.501064,0.00621456)    );
  // itree = 133
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506203,0.000442772) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405446,-0.0268799) , 
1, 11.6667, 1, 0, 0.496296,-0.0041352) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545199,0.0436974) , 
1, 15.6667, 1, 0, 0.498352,-0.00109939)    );
  // itree = 134
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0627839,-0.0599371) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289128,-0.000244566) , 
7, -2.23813, 1, 0, 0.164373,-0.0387314) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37097,0.0400317) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535197,-0.000533083) , 
7, -1.62567, 1, 0, 0.529987,0.00124554) , 
7, -1.8576, 1, 0, 0.498629,-0.00218325)    );
  // itree = 135
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542157,0.00232144) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.630756,0.0346682) , 
1, 13.3333, 1, 0, 0.549661,0.0083618) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473814,-0.00098747) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326295,-0.0373534) , 
1, 9.85714, 1, 0, 0.440889,-0.0157935) , 
7, 0.435144, 1, 0, 0.508737,-0.00072619)    );
  // itree = 136
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.977795,0.032159) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.200074,-0.0241049) , 
1, 1.90476, 1, 0, 0.312131,-0.0271988) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590586,-0.00684893) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57916,0.0174484) , 
0, 51633.9, 1, 0, 0.585449,0.00725805) , 
4, 0.0572527, 1, 0, 0.501906,-0.00327412)    );
  // itree = 137
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.186754,-0.0317272) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603097,0.00663285) , 
7, -1.7628, 1, 0, 0.543434,0.00321056) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326924,-0.0265839) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577766,0.00333027) , 
2, 72829.1, 1, 0, 0.410036,-0.0277786) , 
7, 0.70376, 1, 0, 0.502531,-0.00629151)    );
  // itree = 138
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.136812,-0.00104679) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327161,0.0771026) , 
2, 65112.6, 1, 0, 0.207336,0.0341063) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551918,-0.001025) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.104587,-0.0442485) , 
6, 7.51529, 1, 0, 0.537699,-0.00391295) , 
8, -0.0706489, 1, 0, 0.499623,0.000468989)    );
  // itree = 139
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298296,-0.0192851) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.196728,0.0467778) , 
1, 12.9048, 1, 0, 0.290789,-0.0199101) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.632378,-0.0106231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.758308,0.0144007) , 
7, -0.699117, 1, 0, 0.723792,0.0110904) , 
4, 0.114489, 1, 0, 0.496609,-0.00517462)    );
  // itree = 140
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.804913,0.0048093) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.791497,0.0246068) , 
7, 0.463289, 1, 0, 0.800542,0.0170296) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.174574,-0.000590934) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.794895,-0.0185329) , 
4, 0.190427, 1, 0, 0.362994,-0.0102536) , 
1, 4.71429, 1, 0, 0.498356,-0.00181319)    );
  // itree = 141
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463415,-0.00242288) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535033,0.0245511) , 
0, 132062, 1, 0, 0.468544,-0.000682664) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971866,0.0472224) , 
4, 0.36148, 1, 0, 0.486499,0.00154117)    );
  // itree = 142
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509926,0.00107186) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.184983,-0.0164331) , 
3, 0.047619, 1, 0, 0.415047,-0.00575641) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.93447,0.0150121) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965535,0.0390896) , 
3, 0.047619, 1, 0, 0.943555,0.0252996) , 
4, 0.266854, 1, 0, 0.505461,-0.000443545)    );
  // itree = 143
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479745,-0.00022994) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492183,0.0405842) , 
1, 14.1429, 1, 0, 0.480147,0.00199562) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608295,-0.0416185) , 
0, 159617, 1, 0, 0.486143,-0.000633899)    );
  // itree = 144
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574038,0.00625216) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.195301,-0.0181909) , 
8, 0.0679305, 1, 0, 0.533211,0.00660306) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0913095,-0.0598409) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0340231,-0.0299247) , 
0, 48917.3, 1, 0, 0.0584848,-0.0408904) , 
7, 2.12578, 1, 0, 0.505369,0.0038176)    );
  // itree = 145
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316924,0.0365615) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559771,-0.0016633) , 
7, -1.55287, 1, 0, 0.531675,0.00273736) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307705,-0.0232464) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.958732,0.0330054) , 
4, 0.284186, 1, 0, 0.393045,-0.0256072) , 
8, 0.0195619, 1, 0, 0.488592,-0.00607139)    );
  // itree = 146
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614668,0.0158616) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202704,-0.0049803) , 
6, 1.96345, 1, 0, 0.416279,0.0114751) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304349,-0.0204964) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827316,0.00531383) , 
4, 0.096658, 1, 0, 0.581521,-0.00943549) , 
2, 57820.6, 1, 0, 0.503662,0.000417189)    );
  // itree = 147
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.438579,0.00554554) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.606752,0.0509187) , 
1, 13.3333, 1, 0, 0.450696,0.0142752) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442698,-0.011579) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954596,0.0229043) , 
4, 0.286123, 1, 0, 0.517734,-0.0131384) , 
7, -0.428016, 1, 0, 0.493665,-0.00329601)    );
  // itree = 148
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.879034,0.017345) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307179,-0.0170175) , 
6, 0.971863, 1, 0, 0.553239,-0.00969755) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445255,0.0260091) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426142,-0.00938916) , 
8, -0.00291834, 1, 0, 0.435435,0.0136197) , 
0, 51649.1, 1, 0, 0.498643,0.00110892)    );
  // itree = 149
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422155,0.0145259) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557837,-0.0149332) , 
4, 0.0406215, 1, 0, 0.533495,-0.0148791) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.232449,-0.00884751) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.625811,0.0303499) , 
4, 0.0965492, 1, 0, 0.428575,0.0196324) , 
7, 0.712333, 1, 0, 0.500503,-0.00402693)    );
  // itree = 150
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0343653,-0.0558008) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.150314,-0.00374666) , 
2, 61431.4, 1, 0, 0.078281,-0.0357941) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543857,0.00194984) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.789833,0.0538265) , 
0, 192318, 1, 0, 0.552349,0.00558287) , 
8, -0.0748369, 1, 0, 0.503033,0.00127857)    );
  // itree = 151
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.668529,0.00958614) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.029503,-0.0405554) , 
1, 6, 1, 0, 0.311046,-0.0169338) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440601,-0.00554706) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.643212,0.0155053) , 
8, -0.0183658, 1, 0, 0.585123,0.0155497) , 
4, 0.0586738, 1, 0, 0.502611,0.00577032)    );
  // itree = 152
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464412,-0.00200998) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971758,0.0326065) , 
4, 0.266292, 1, 0, 0.560251,0.00280606) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175263,-0.0310069) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.280934,-0.00196808) , 
3, 0.047619, 1, 0, 0.220614,-0.0295658) , 
6, 4.24913, 1, 0, 0.511108,-0.00187789)    );
  // itree = 153
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495038,-0.00181683) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.73309,0.054758) , 
0, 149664, 1, 0, 0.505285,0.000182599) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.454408,-0.0514652) , 
1, 15.8571, 1, 0, 0.503258,-0.00283848)    );
  // itree = 154
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538973,0.00338833) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434136,0.0365735) , 
1, 9.14286, 1, 0, 0.532034,0.00839156) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.446306,-0.0319798) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.438425,0.0124715) , 
3, 0.047619, 1, 0, 0.44233,-0.0175377) , 
1, 10.6667, 1, 0, 0.515781,0.00369362)    );
  // itree = 155
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.61915,0.0111861) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.408082,-0.0227408) , 
1, 9.33333, 1, 0, 0.582507,0.00751671) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288636,-0.0350145) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294911,0.0204926) , 
6, 2.75328, 1, 0, 0.291483,-0.0177731) , 
3, 0.047619, 1, 0, 0.49994,0.000341724)    );
  // itree = 156
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583171,0.00835179) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252699,-0.0250299) , 
8, 0.0534962, 1, 0, 0.536306,0.00608026) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203163,0.00800661) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.12852,-0.0478205) , 
1, 9.85714, 1, 0, 0.154286,-0.0431855) , 
6, 5.64613, 1, 0, 0.505374,0.00209127)    );
  // itree = 157
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.231401,0.00228606) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549841,-0.0301812) , 
4, 0.0965248, 1, 0, 0.38628,-0.0233573) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.684861,0.0108972) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392965,-0.00936663) , 
1, 6.52381, 1, 0, 0.542363,0.000655596) , 
7, -0.714075, 1, 0, 0.496147,-0.00645464)    );
  // itree = 158
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344968,0.00899107) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.77315,-0.00559387) , 
4, 0.135058, 1, 0, 0.524006,0.00390035) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.132337,-0.0460135) , 
6, 7.46873, 1, 0, 0.507311,0.00123067)    );
  // itree = 159
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252764,-0.00982214) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.812296,-0.0502156) , 
5, 4551.68, 1, 0, 0.373759,-0.0267915) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.59313,-0.00769827) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439341,0.0113577) , 
0, 51633.9, 1, 0, 0.526861,0.00228846) , 
7, -0.707306, 1, 0, 0.483604,-0.00592778)    );
  // itree = 160
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564456,0.00894136) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.165716,-0.0420818) , 
7, 2.43042, 1, 0, 0.548224,0.0114545) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22498,-0.0269599) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.138041,0.0147291) , 
7, 0.996098, 1, 0, 0.197944,-0.0182865) , 
6, 4.2365, 1, 0, 0.492649,0.00673585)    );
  // itree = 161
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.655373,0.00296521) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326279,-0.0151365) , 
1, 7, 1, 0, 0.513063,-0.00759192) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.025801,-0.0528022) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.742988,0.0339866) , 
4, 0.058697, 1, 0, 0.557424,0.0225814) , 
0, 114736, 1, 0, 0.5181,-0.00416583)    );
  // itree = 162
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.860767,0.0668739) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0114872,-0.0529936) , 
1, 5.04762, 1, 0, 0.43913,0.0378204) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.253768,-0.0190309) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.615929,0.00420685) , 
4, 0.0736665, 1, 0, 0.496907,-0.00306396) , 
4, 0.0192242, 1, 0, 0.493227,-0.000460188)    );
  // itree = 163
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.637758,0.00790869) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.342687,-0.0094178) , 
1, 6.47619, 1, 0, 0.49359,-0.00138829) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.781266,0.0495736) , 
0, 185593, 1, 0, 0.503307,0.000905917)    );
  // itree = 164
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577652,0.0111707) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403405,-0.013006) , 
8, 0.0195619, 1, 0, 0.526938,0.00637852) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424935,-0.031329) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311885,-0.00306102) , 
0, 48903, 1, 0, 0.369748,-0.0264678) , 
7, 0.715824, 1, 0, 0.478977,-0.00364334)    );
  // itree = 165
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503551,0.00122138) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.660786,0.0368276) , 
1, 14.3333, 1, 0, 0.509922,0.00424165) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0356193,-0.00768495) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400638,-0.0271114) , 
5, 1386.37, 1, 0, 0.139925,-0.0230747) , 
6, 5.64529, 1, 0, 0.477163,0.00182306)    );
  // itree = 166
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.710696,0.00169566) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.227173,-0.0240488) , 
6, 1.95837, 1, 0, 0.534161,-0.0113213) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505718,0.0285314) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262672,-0.00685554) , 
8, 0.0249105, 1, 0, 0.434437,0.0306957) , 
1, 8.04762, 1, 0, 0.505011,0.000960789)    );
  // itree = 167
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496497,0.00410331) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.155959,-0.0164225) , 
3, 0.047619, 1, 0, 0.401552,-0.00136292) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.907355,0.0340593) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.982096,0.0268708) , 
5, 5219.03, 1, 0, 0.957749,0.0338019) , 
4, 0.266382, 1, 0, 0.491785,0.004342)    );
  // itree = 168
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508806,0.00152195) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.136569,-0.0347649) , 
7, 1.85733, 1, 0, 0.476524,-0.00161756) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.927097,0.0449311) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.977795,0.0162907) , 
5, 6897.86, 1, 0, 0.958603,0.0407108) , 
4, 0.342315, 1, 0, 0.510311,0.00134908)    );
  // itree = 169
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918968,0.0121771) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.370056,-0.0111382) , 
6, 0.83915, 1, 0, 0.551135,-0.00910154) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469708,0.0254312) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.270441,-0.0149247) , 
8, 0.0210542, 1, 0, 0.404959,0.0220968) , 
1, 7.66667, 1, 0, 0.490942,0.00374548)    );
  // itree = 170
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534536,-0.00176364) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.452398,0.0245843) , 
0, 66682.9, 1, 0, 0.51515,0.00604802) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.127792,0.0181422) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.67507,-0.0428012) , 
4, 0.134062, 1, 0, 0.421891,-0.0331443) , 
1, 11.3333, 1, 0, 0.502405,0.000691689)    );
  // itree = 171
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.64035,0.008572) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307311,-0.0103914) , 
1, 6.2381, 1, 0, 0.485143,-0.000588935) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298325,0.0467243) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.93105,-0.00042519) , 
5, 4191.93, 1, 0, 0.606544,0.0415377) , 
0, 136084, 1, 0, 0.493578,0.00233811)    );
  // itree = 172
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.725766,-0.000528306) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.619705,0.0257779) , 
8, 0.027531, 1, 0, 0.702635,0.00885098) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517925,-0.0325483) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.277005,-0.00493946) , 
1, 3.95238, 1, 0, 0.295269,-0.0127838) , 
6, 1.90533, 1, 0, 0.501231,-0.00184533)    );
  // itree = 173
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.425121,-0.00386975) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329425,0.0228886) , 
0, 45843.4, 1, 0, 0.364823,0.0182636) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540055,-0.000545308) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0280231,-0.0833012) , 
7, 2.56534, 1, 0, 0.522139,-0.00297865) , 
7, -1.01497, 1, 0, 0.484749,0.0020701)    );
  // itree = 174
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374285,-0.0131186) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547348,0.00749346) , 
7, -0.697888, 1, 0, 0.497694,0.00305129) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.168777,0.00210988) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664311,-0.0588064) , 
4, 0.15289, 1, 0, 0.436049,-0.0551097) , 
1, 12.8095, 1, 0, 0.490982,-0.00328152)    );
  // itree = 175
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329654,-0.022949) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.152768,0.0302449) , 
7, 1.2708, 1, 0, 0.295445,-0.0229743) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.683169,0.012922) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504328,-0.000570183) , 
8, -0.00283906, 1, 0, 0.553753,0.00545822) , 
8, -0.0276375, 1, 0, 0.490318,-0.0015242)    );
  // itree = 176
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537804,0.00379803) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0129208,-0.0758768) , 
6, 4.52731, 1, 0, 0.517493,0.00237776) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292846,0.0190324) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492705,-0.0291227) , 
2, 68053.5, 1, 0, 0.450973,-0.0269201) , 
0, 78549.7, 1, 0, 0.501098,-0.00484294)    );
  // itree = 177
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.156056,0.000341702) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516474,-0.0305208) , 
4, 0.113853, 1, 0, 0.298339,-0.0207857) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.760899,0.0110688) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392953,-0.00765734) , 
1, 5.95238, 1, 0, 0.54133,-0.00106198) , 
8, -0.0247164, 1, 0, 0.479371,-0.00609126)    );
  // itree = 178
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.151061,-0.0368481) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554743,0.00534548) , 
7, -2.01599, 1, 0, 0.522752,0.00468734) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.199991,-0.0552669) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0595034,0.0125592) , 
6, 2.36156, 1, 0, 0.132159,-0.0366077) , 
7, 2.11818, 1, 0, 0.497388,0.00200574)    );
  // itree = 179
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.875942,-0.00704914) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.441389,0.0161474) , 
1, 3.14286, 1, 0, 0.646339,0.0113511) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339688,-0.0227359) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353206,0.00386047) , 
3, 0.047619, 1, 0, 0.345394,-0.019997) , 
1, 6.28571, 1, 0, 0.496762,-0.00422966)    );
  // itree = 180
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522478,-0.00460181) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426771,0.0185128) , 
0, 66682.9, 1, 0, 0.498094,0.00116142) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.650425,0.0494568) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167927,-0.0189334) , 
6, 5.14449, 1, 0, 0.496724,0.059417) , 
1, 13, 1, 0, 0.497956,0.00705126)    );
  // itree = 181
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.897555,0.00899305) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332505,-0.0153248) , 
1, 3.28571, 1, 0, 0.559643,-0.0101261) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422797,0.00979435) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0424848,-0.0693837) , 
7, 2.12827, 1, 0, 0.396505,0.00979268) , 
1, 7.90476, 1, 0, 0.496059,-0.00236257)    );
  // itree = 182
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996095,0.0439759) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.627389,-0.0104982) , 
1, 1.19048, 1, 0, 0.706556,-0.00801909) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509755,0.019116) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298458,0.00400821) , 
6, 1.98081, 1, 0, 0.379911,0.0171682) , 
1, 5.42857, 1, 0, 0.508991,0.00721494)    );
  // itree = 183
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562961,-0.00823509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431236,0.00828645) , 
0, 51644.7, 1, 0, 0.501577,-0.000767706) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466377,-0.0505455) , 
1, 16.1905, 1, 0, 0.500596,-0.00305928)    );
  // itree = 184
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48805,-0.0113605) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697605,0.017706) , 
8, -0.0210287, 1, 0, 0.64068,0.0147173) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307317,-0.0157292) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503988,0.0169003) , 
1, 12.9524, 1, 0, 0.351453,-0.0106794) , 
1, 6.90476, 1, 0, 0.500225,0.00238407)    );
  // itree = 185
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.884154,0.0130559) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202478,-0.00774242) , 
1, 3.66667, 1, 0, 0.351383,-0.00560389) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.934573,0.0325023) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.839708,-0.0146583) , 
7, 0.397801, 1, 0, 0.901923,0.0202502) , 
4, 0.210395, 1, 0, 0.497746,0.00126949)    );
  // itree = 186
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340183,-0.0293137) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307928,0.00621368) , 
7, 0.461393, 1, 0, 0.328248,-0.0231579) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.598136,-0.000818966) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453962,0.0156639) , 
1, 9, 1, 0, 0.555299,0.0072677) , 
8, -0.0232873, 1, 0, 0.493347,-0.00103413)    );
  // itree = 187
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319436,0.00635646) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353228,-0.0129743) , 
7, -0.144079, 1, 0, 0.33833,-0.00788312) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.848164,0.0189434) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.691204,-0.0371622) , 
1, 13.0476, 1, 0, 0.833368,0.0168765) , 
4, 0.172071, 1, 0, 0.501308,0.000268332)    );
  // itree = 188
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401269,-0.0105172) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.931315,0.0215133) , 
4, 0.22911, 1, 0, 0.528079,-0.00655413) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506596,0.0142209) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0960782,-0.0214192) , 
8, 0.105244, 1, 0, 0.475981,0.0176026) , 
7, 0.423152, 1, 0, 0.509137,0.00222901)    );
  // itree = 189
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358208,0.00470733) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.768815,0.022913) , 
4, 0.114149, 1, 0, 0.553116,0.0194899) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343453,-0.0395452) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458169,0.00256021) , 
3, 0.047619, 1, 0, 0.395228,-0.0341094) , 
1, 9.85714, 1, 0, 0.518103,0.00760383)    );
  // itree = 190
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498466,-0.027215) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518851,0.00443997) , 
2, 21587.3, 1, 0, 0.518021,0.00326203) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389403,-0.0415163) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.459253,-0.000616054) , 
3, 0.047619, 1, 0, 0.425443,-0.0351769) , 
1, 11.3333, 1, 0, 0.505455,-0.00195529)    );
  // itree = 191
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355061,0.00544749) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.890001,-0.0132222) , 
5, 3643.31, 1, 0, 0.50481,0.00236918) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384825,0.0437135) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.910281,-0.0101192) , 
5, 4615.41, 1, 0, 0.65549,0.0448224) , 
0, 132062, 1, 0, 0.516643,0.00570308)    );
  // itree = 192
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0649317,-0.0447607) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.277842,0.0574941) , 
8, -0.0335842, 1, 0, 0.214039,0.0403303) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.17121,0.0299276) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567064,-0.00185284) , 
8, -0.0732779, 1, 0, 0.529108,0.00031618) , 
7, -1.8521, 1, 0, 0.498356,0.00422178)    );
  // itree = 193
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.907283,0.0223857) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.066741,-0.0284691) , 
1, 3.66667, 1, 0, 0.271474,-0.0192245) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.678017,0.00964202) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.257043,-0.0398898) , 
8, 0.0598594, 1, 0, 0.629851,0.00703142) , 
4, 0.076352, 1, 0, 0.489569,-0.00324619)    );
  // itree = 194
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.935248,0.0257071) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.438262,-0.00740928) , 
6, 0.814257, 1, 0, 0.578481,-0.00344405) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.204325,-0.0177002) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332166,0.0284761) , 
8, -0.0247164, 1, 0, 0.288668,0.0196929) , 
6, 3.24764, 1, 0, 0.505634,0.00237161)    );
  // itree = 195
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264361,-0.0307189) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294862,0.00925541) , 
1, 8.04762, 1, 0, 0.275721,-0.0180923) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517103,0.0325661) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552821,0.000405652) , 
7, -1.079, 1, 0, 0.550968,0.00334967) , 
7, -1.28407, 1, 0, 0.508542,4.46894e-05)    );
  // itree = 196
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.83248,-0.0203441) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353305,0.000585359) , 
6, 1.10584, 1, 0, 0.503118,-0.006433) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.152835,0.0462629) , 
7, 2.42813, 1, 0, 0.489468,-0.00436801)    );
  // itree = 197
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493152,-0.00239406) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538521,0.0339482) , 
0, 111149, 1, 0, 0.495978,-0.000130061) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353175,-0.0552617) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.734447,0.0301649) , 
2, 170615, 1, 0, 0.510261,-0.0341461) , 
0, 145761, 1, 0, 0.496889,-0.00229969)    );
  // itree = 198
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501168,-0.0040739) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496204,0.0257101) , 
0, 83129.1, 1, 0, 0.500416,0.000697161) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.609847,-0.00612507) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420931,-0.065018) , 
7, 0.158066, 1, 0, 0.53748,-0.03866) , 
0, 136084, 1, 0, 0.502933,-0.00197537)    );
  // itree = 199
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.619121,-0.0094276) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348116,0.0146888) , 
6, 2.44973, 1, 0, 0.532651,-0.0022427) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.183848,0.00491191) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0956713,-0.0484093) , 
1, 8.04762, 1, 0, 0.126996,-0.0367471) , 
6, 5.0883, 1, 0, 0.490501,-0.0058279)    );
  // itree = 200
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343095,-0.0118425) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578812,0.00372274) , 
8, -0.0275184, 1, 0, 0.520524,2.27789e-06) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.637057,0.0325959) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322548,-0.000942353) , 
7, 1.29018, 1, 0, 0.490737,0.0277644) , 
7, 0.43568, 1, 0, 0.509021,0.0107234)    );
  // itree = 201
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.61762,-0.00267356) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.476972,0.0181272) , 
0, 51635, 1, 0, 0.554104,0.0107695) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506999,-0.0284384) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.280641,0.00132383) , 
8, 0.0454275, 1, 0, 0.366093,-0.0161243) , 
8, 0.0227751, 1, 0, 0.499905,0.00301671)    );
  // itree = 202
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557732,0.00471816) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.160274,-0.0212012) , 
6, 3.7533, 1, 0, 0.497805,0.00178729) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.762944,-0.00412135) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470999,0.0399305) , 
6, 3.2623, 1, 0, 0.563881,0.0441175) , 
0, 120607, 1, 0, 0.504238,0.00590826)    );
  // itree = 203
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.619497,0.00829638) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424588,-0.0126253) , 
0, 47260.6, 1, 0, 0.522639,-0.00359426) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0915541,-0.0463427) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510454,0.0171105) , 
8, -0.0548147, 1, 0, 0.454007,0.0184592) , 
7, 0.715456, 1, 0, 0.501791,0.00310467)    );
  // itree = 204
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.992854,0.0506624) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.117046,-0.0354841) , 
1, 2.71429, 1, 0, 0.332799,-0.0276442) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.792899,-0.0112607) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.418257,0.00996942) , 
1, 4.52381, 1, 0, 0.52678,0.00687109) , 
4, 0.0382385, 1, 0, 0.491255,0.000550071)    );
  // itree = 205
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289306,0.00343296) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424433,-0.0133784) , 
4, 0.0905395, 1, 0, 0.343683,-0.00774563) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9129,0.00664632) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.88613,0.0345126) , 
7, 0.954871, 1, 0, 0.907835,0.0155995) , 
4, 0.209201, 1, 0, 0.499968,-0.0012784)    );
  // itree = 206
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339375,-0.0179883) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.773333,0.000324365) , 
4, 0.114489, 1, 0, 0.559075,-0.0128438) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507225,0.0188612) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0579885,-0.0262206) , 
8, 0.110529, 1, 0, 0.412873,0.0187069) , 
8, 0.020861, 1, 0, 0.514034,-0.00312388)    );
  // itree = 207
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.171218,-0.00662509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.568713,-0.0401814) , 
4, 0.155321, 1, 0, 0.287591,-0.0233161) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312965,-0.0205669) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.589653,0.00847239) , 
7, -1.54577, 1, 0, 0.558522,0.00840796) , 
8, -0.0276375, 1, 0, 0.492359,0.000660768)    );
  // itree = 208
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554465,0.032304) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.699279,-0.00386602) , 
7, -1.26775, 1, 0, 0.679169,0.00297201) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.13337,-0.0472671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.324394,-0.010173) , 
0, 48956, 1, 0, 0.278987,-0.0254689) , 
6, 1.90533, 1, 0, 0.487797,-0.0106288)    );
  // itree = 209
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348068,-0.00436193) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597411,-0.0365142) , 
7, -0.928403, 1, 0, 0.394667,-0.0130667) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547779,0.00380714) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.157945,0.0586619) , 
7, 2.46969, 1, 0, 0.529483,0.00797988) , 
7, -0.710708, 1, 0, 0.490428,0.00188282)    );
  // itree = 210
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26145,0.00335664) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.290769,-0.0205274) , 
8, -0.00972059, 1, 0, 0.278805,-0.0146174) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351617,0.043937) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674606,0.00673493) , 
4, 0.0918734, 1, 0, 0.641677,0.0159473) , 
4, 0.076352, 1, 0, 0.506511,0.00456231)    );
  // itree = 211
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516123,0.00447283) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423955,-0.0396528) , 
7, 0.875326, 1, 0, 0.506482,-0.000970559) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.490146,0.0394567) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.249146,0.00863515) , 
7, 1.6205, 1, 0, 0.318969,0.0257164) , 
7, 1.2883, 1, 0, 0.47347,0.0037277)    );
  // itree = 212
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.992706,0.0481194) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.467897,-0.0011204) , 
6, 0.450535, 1, 0, 0.517425,0.000921041) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.228734,0.034925) , 
6, 7.54278, 1, 0, 0.505565,0.00306087)    );
  // itree = 213
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.342061,0.0276609) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363534,-0.0297796) , 
4, 0.0775292, 1, 0, 0.355905,-0.0203301) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579377,0.00507936) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163039,-0.0389974) , 
7, 1.83497, 1, 0, 0.546227,0.00285509) , 
2, 41135, 1, 0, 0.497397,-0.00309343)    );
  // itree = 214
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.33814,-0.00948544) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.682904,0.0072395) , 
4, 0.0776328, 1, 0, 0.55613,0.00253971) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.250609,0.013834) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336258,-0.0316943) , 
8, -0.0264806, 1, 0, 0.311341,-0.0284395) , 
7, 1.2844, 1, 0, 0.510445,-0.00324194)    );
  // itree = 215
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298745,-0.0210339) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.287276,0.00524179) , 
7, 0.426155, 1, 0, 0.29426,-0.0143465) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616222,-0.00842544) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.91154,0.0214741) , 
2, 54347.8, 1, 0, 0.800963,0.00773903) , 
4, 0.152037, 1, 0, 0.481245,-0.00619643)    );
  // itree = 216
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532454,0.0343276) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.105393,-0.0170121) , 
0, 69125.1, 1, 0, 0.388584,0.0226462) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390275,-0.00877025) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.943992,0.0195945) , 
4, 0.245031, 1, 0, 0.530087,-0.00601775) , 
4, 0.038281, 1, 0, 0.503322,-0.000595864)    );
  // itree = 217
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.173826,-0.0100116) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.441858,0.0110195) , 
5, 858.541, 1, 0, 0.342646,0.00946223) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.940682,0.000250396) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827672,-0.0700211) , 
1, 12.0476, 1, 0, 0.92201,-0.0131155) , 
5, 4512.83, 1, 0, 0.496699,0.00345879)    );
  // itree = 218
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163618,0.0346148) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.65494,-0.0117869) , 
5, 2621.07, 1, 0, 0.286794,0.0170063) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439442,-0.0174889) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56218,-0.00277838) , 
2, 34011.8, 1, 0, 0.542772,-0.00801583) , 
7, -1.28853, 1, 0, 0.497567,-0.00359708)    );
  // itree = 219
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295746,-0.0187785) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565913,0.00156913) , 
7, -1.28537, 1, 0, 0.523188,-0.00178818) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.241391,0.0778569) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163039,0.00418787) , 
0, 54870, 1, 0, 0.201962,0.0474127) , 
7, 2.1359, 1, 0, 0.504207,0.0011191)    );
  // itree = 220
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484867,0.00522626) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475857,0.0338353) , 
0, 78592.3, 1, 0, 0.482588,0.0167445) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538783,0.00215289) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507685,-0.0417192) , 
0, 106431, 1, 0, 0.534649,-0.00544334) , 
7, -0.425678, 1, 0, 0.516051,0.00248278)    );
  // itree = 221
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 1,0.058643) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.436379,-0.0114703) , 
6, 0.438819, 1, 0, 0.500401,-0.0112811) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0679335,-0.0362558) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592228,0.0226594) , 
4, 0.0395889, 1, 0, 0.497189,0.0200083) , 
0, 78266.4, 1, 0, 0.499613,-0.00360478)    );
  // itree = 222
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523391,0.0411042) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.746093,0.00641529) , 
7, -1.27106, 1, 0, 0.719067,0.015076) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.166804,-0.0263496) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337994,0.00294352) , 
2, 38457.5, 1, 0, 0.291754,-0.00720174) , 
6, 1.73277, 1, 0, 0.499021,0.00360404)    );
  // itree = 223
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457055,0.00146022) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.668746,-0.0237158) , 
2, 91513.7, 1, 0, 0.509677,-0.00487293) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613842,0.0205744) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322142,3.12077e-05) , 
7, 1.28666, 1, 0, 0.47306,0.0165852) , 
7, 0.429913, 1, 0, 0.495356,0.00351948)    );
  // itree = 224
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.859376,0.000431945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.748259,0.0213511) , 
0, 33833.5, 1, 0, 0.810448,0.0157977) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336097,-0.00745439) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.978253,0.0488678) , 
4, 0.361321, 1, 0, 0.365139,-0.00813587) , 
1, 4.71429, 1, 0, 0.501983,-0.000781052)    );
  // itree = 225
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330264,-0.00869448) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.867113,0.0107554) , 
4, 0.189856, 1, 0, 0.487468,-0.00440753) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.712148,0.0438419) , 
0, 180516, 1, 0, 0.495133,-0.00234359)    );
  // itree = 226
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534878,-0.00662638) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.187596,0.0240218) , 
7, 1.85091, 1, 0, 0.502924,-0.00629119) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0,-0.066538) , 
8, 0.166159, 1, 0, 0.484563,-0.00794796)    );
  // itree = 227
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.636877,-0.0166476) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.156309,0.0165838) , 
6, 1.29063, 1, 0, 0.317799,0.00538072) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.840217,-0.00591954) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581435,-0.0326573) , 
6, 3.44297, 1, 0, 0.79129,-0.0189374) , 
4, 0.153086, 1, 0, 0.493882,-0.00366277)    );
  // itree = 228
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539268,0.06944) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.373989,0.01267) , 
4, 0.0113504, 1, 0, 0.447542,0.045195) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560155,-0.00608678) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399503,0.00885985) , 
1, 7.66667, 1, 0, 0.495563,0.000125279) , 
4, 0.0195035, 1, 0, 0.492756,0.00275912)    );
  // itree = 229
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442906,0.025395) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.269525,-0.0147648) , 
4, 0.0137558, 1, 0, 0.288337,-0.0114845) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384669,0.0147068) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.811255,-0.00731949) , 
4, 0.17135, 1, 0, 0.581922,0.00850905) , 
4, 0.0572527, 1, 0, 0.496343,0.00268101)    );
  // itree = 230
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502973,0.00635137) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389905,0.0385269) , 
8, 0.0227751, 1, 0, 0.465273,0.0225828) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584237,-0.0318097) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479057,0.00357033) , 
7, 0.0643142, 1, 0, 0.50186,-0.0049252) , 
7, -0.42536, 1, 0, 0.48794,0.00554103)    );
  // itree = 231
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.886348,-0.00149188) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534706,0.0294846) , 
1, 3.14286, 1, 0, 0.797105,0.0125843) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.228147,-0.0174663) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521602,0.00155935) , 
2, 68487.8, 1, 0, 0.359339,-0.0128517) , 
1, 4.52381, 1, 0, 0.494508,-0.00499785)    );
  // itree = 232
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.259951,-0.0107207) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.607767,0.0179809) , 
7, -1.50151, 1, 0, 0.505323,0.0163328) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601766,-0.00792539) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35589,0.0178824) , 
7, 1.20201, 1, 0, 0.520544,-7.86419e-05) , 
7, -0.144079, 1, 0, 0.513731,0.00726769)    );
  // itree = 233
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.79642,0.00983767) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.280929,-0.00610579) , 
6, 1.38474, 1, 0, 0.523709,0.00109899) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423651,0.0431423) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471403,0.0089853) , 
0, 63199.7, 1, 0, 0.458484,0.029094) , 
1, 9.28571, 1, 0, 0.508155,0.0077747)    );
  // itree = 234
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472588,-0.00571756) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501849,-0.0452017) , 
0, 144073, 1, 0, 0.473633,-0.00961683) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.740062,0.0300169) , 
0, 192311, 1, 0, 0.483099,-0.00813349)    );
  // itree = 235
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.610295,0.0149663) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.245499,-0.00571629) , 
6, 3.78186, 1, 0, 0.546317,0.0169501) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0589897,-0.0105236) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.180609,-0.0645614) , 
5, 1436.7, 1, 0, 0.107044,-0.0407862) , 
7, 2.14278, 1, 0, 0.518232,0.0132587)    );
  // itree = 236
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.061651,-0.039948) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617633,0.0117842) , 
8, -0.104057, 1, 0, 0.559724,0.0128056) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.793219,-0.0263624) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283726,-0.00208902) , 
1, 3.95238, 1, 0, 0.385242,-0.010265) , 
8, 0.0195619, 1, 0, 0.50697,0.00583031)    );
  // itree = 237
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500566,0.00370439) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404514,-0.0430038) , 
0, 139622, 1, 0, 0.497284,0.003159) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.705489,0.051678) , 
0, 185592, 1, 0, 0.504355,0.00505933)    );
  // itree = 238
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.317913,-0.0108638) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.787167,0.0109085) , 
4, 0.115436, 1, 0, 0.541276,0.000203716) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.21572,-0.00811723) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.643673,-0.0360796) , 
4, 0.134598, 1, 0, 0.365949,-0.025087) , 
7, 0.715243, 1, 0, 0.487787,-0.00751199)    );
  // itree = 239
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359583,0.0148478) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.571816,-0.0124485) , 
4, 0.0589773, 1, 0, 0.51007,-0.00794338) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.798461,0.0284431) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325225,0.00202504) , 
1, 5, 1, 0, 0.470999,0.0138014) , 
7, 0.425916, 1, 0, 0.495517,0.000155936)    );
  // itree = 240
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56241,0.00733287) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474366,-0.0163974) , 
1, 15.8571, 1, 0, 0.559073,0.00905571) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.115895,-0.04653) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.206414,-0.00960313) , 
7, -0.428796, 1, 0, 0.167031,-0.0249799) , 
8, 0.0702666, 1, 0, 0.512189,0.00498542)    );
  // itree = 241
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306377,0.00353612) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603955,-0.011616) , 
4, 0.0927084, 1, 0, 0.458573,-0.00720371) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.949832,0.0177179) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.990842,0.0624495) , 
4, 0.366955, 1, 0, 0.9665,0.0276417) , 
4, 0.323503, 1, 0, 0.502071,-0.00421955)    );
  // itree = 242
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501266,0.0157549) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.661508,0.000664666) , 
2, 61187.1, 1, 0, 0.57368,0.0150623) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222267,-0.0183056) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.639185,0.0253153) , 
0, 118489, 1, 0, 0.297809,-0.0123954) , 
3, 0.047619, 1, 0, 0.496283,0.00735888)    );
  // itree = 243
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.634973,-0.0041912) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354236,0.0198213) , 
0, 31270.6, 1, 0, 0.439592,0.0189039) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669466,-0.0156586) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486255,0.00596867) , 
3, 0.047619, 1, 0, 0.610758,-0.00991369) , 
2, 63377.3, 1, 0, 0.517401,0.00580399)    );
  // itree = 244
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0110417,-0.110521) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.072243,-0.00588506) , 
7, -0.183721, 1, 0, 0.0447087,-0.0330836) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562658,0.00816787) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44293,-0.0113214) , 
1, 10.3333, 1, 0, 0.540601,0.00587207) , 
8, -0.0998582, 1, 0, 0.501519,0.00280193)    );
  // itree = 245
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.220069,-0.0242702) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.767004,0.00611431) , 
4, 0.152858, 1, 0, 0.397003,-0.0148391) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403688,0.0122158) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.884502,-0.0131801) , 
4, 0.2096, 1, 0, 0.536137,0.00980972) , 
7, -0.707306, 1, 0, 0.49699,0.00287457)    );
  // itree = 246
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.78704,-0.00981879) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354554,0.00507335) , 
1, 4.28571, 1, 0, 0.497643,0.000975299) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.66497,-0.0402772) , 
0, 184803, 1, 0, 0.503362,-0.000775087)    );
  // itree = 247
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394673,0.0378098) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529608,-0.00657777) , 
4, 0.112561, 1, 0, 0.457235,0.0290385) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167135,0.0253328) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563048,-0.00813) , 
8, -0.071317, 1, 0, 0.520187,-0.0071075) , 
2, 30909.7, 1, 0, 0.511492,-0.00211474)    );
  // itree = 248
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55609,0.00589446) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473469,-0.0117806) , 
7, 0.683171, 1, 0, 0.532844,0.00107941) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314846,0.0701111) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0714498,-0.00314834) , 
7, 2.59362, 1, 0, 0.195762,0.0475993) , 
7, 2.14686, 1, 0, 0.513846,0.00370135)    );
  // itree = 249
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424456,-0.0112247) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41684,0.0223626) , 
0, 88506.7, 1, 0, 0.423872,-0.0122031) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374759,-0.0264815) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.768573,0.0131957) , 
4, 0.0407281, 1, 0, 0.689138,0.00554681) , 
2, 81253.8, 1, 0, 0.503597,-0.0068684)    );
  // itree = 250
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.391332,0.0121979) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.417253,-0.0157717) , 
2, 37690, 1, 0, 0.40847,-0.00703477) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337194,-0.0116826) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.787702,0.0209808) , 
4, 0.0586439, 1, 0, 0.636691,0.0124384) , 
2, 73095.5, 1, 0, 0.49164,6.17745e-05)    );
  // itree = 251
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511522,-0.00718025) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.747872,0.0295137) , 
0, 131531, 1, 0, 0.525337,-0.00660682) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0858596,-0.0581361) , 
6, 8.05744, 1, 0, 0.509916,-0.00900931)    );
  // itree = 252
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.756235,0.00799684) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374522,-0.00522797) , 
1, 5.42857, 1, 0, 0.538411,0.000251406) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.157758,-0.0476687) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0752255,-0.000980983) , 
7, 2.61954, 1, 0, 0.13337,-0.0392365) , 
7, 1.85991, 1, 0, 0.504134,-0.00309029)    );
  // itree = 253
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.159526,-0.00905595) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.373313,0.0301603) , 
4, 0.0635626, 1, 0, 0.281196,0.017156) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362819,-0.0497742) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543276,0.000555694) , 
7, -1.35127, 1, 0, 0.536583,-0.00209406) , 
7, -1.56864, 1, 0, 0.506287,0.000189493)    );
  // itree = 254
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551234,-0.00497427) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.430336,-0.0256182) , 
0, 78542.6, 1, 0, 0.524364,-0.0133275) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.566252,0.052457) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.342999,-0.00237351) , 
7, 1.09759, 1, 0, 0.37034,0.00824932) , 
7, 1.0012, 1, 0, 0.486519,-0.00802591)    );
  // itree = 255
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.830042,0.0101717) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320118,-0.0111831) , 
6, 1.11755, 1, 0, 0.486025,-0.00709673) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494612,0.0328237) , 
1, 15.7619, 1, 0, 0.486394,-0.00439278)    );
  // itree = 256
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304255,-0.0379792) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.23333,-0.0102768) , 
0, 43702.9, 1, 0, 0.259752,-0.0268782) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.566807,0.038758) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537602,-0.000235612) , 
7, -1.08273, 1, 0, 0.538876,0.00244851) , 
7, -1.28813, 1, 0, 0.493546,-0.00231411)    );
  // itree = 257
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575425,0.0121912) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.452417,-0.0307439) , 
0, 147146, 1, 0, 0.569938,0.0155339) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.169714,-0.0334608) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577824,0.0425518) , 
0, 87842.1, 1, 0, 0.290992,-0.0109849) , 
3, 0.047619, 1, 0, 0.487976,0.00774191)    );
  // itree = 258
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328561,0.0369704) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42527,-0.0207953) , 
4, 0.0397483, 1, 0, 0.404229,-0.014497) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694053,0.0233989) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505928,0.000427399) , 
7, -0.173792, 1, 0, 0.542273,0.00715241) , 
7, -0.702656, 1, 0, 0.501834,0.000810446)    );
  // itree = 259
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.715234,0.0142042) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586388,-0.0572274) , 
0, 69869.8, 1, 0, 0.704333,0.010631) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.196084,-0.0217655) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.397903,0.00611565) , 
2, 57369.5, 1, 0, 0.293898,-0.0127492) , 
6, 1.73371, 1, 0, 0.485429,-0.00183874)    );
  // itree = 260
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355936,0.00188153) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.829376,0.028683) , 
4, 0.200065, 1, 0, 0.404372,0.00796091) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.702559,-0.06384) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.930053,0.000726883) , 
2, 38435.6, 1, 0, 0.896732,-0.0152119) , 
4, 0.247286, 1, 0, 0.507163,0.00312306)    );
  // itree = 261
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319081,-0.00626163) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.834142,0.00957457) , 
4, 0.152494, 1, 0, 0.506946,-0.00090992) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431565,-0.0343293) , 
1, 15.0952, 1, 0, 0.503749,-0.00316782)    );
  // itree = 262
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470603,-0.00986592) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.185512,0.0152209) , 
6, 3.33477, 1, 0, 0.410192,-0.00682074) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.342194,-0.00243264) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.828327,0.0210723) , 
4, 0.077566, 1, 0, 0.654559,0.0161655) , 
2, 73373.3, 1, 0, 0.493473,0.00101308)    );
  // itree = 263
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.136746,-0.0202541) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552545,0.00552137) , 
8, -0.0695975, 1, 0, 0.508845,0.00457991) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.573722,0.0299845) , 
1, 14.8095, 1, 0, 0.512099,0.00695414)    );
  // itree = 264
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434615,0.0171929) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.255505,-0.0178658) , 
4, 0.0334334, 1, 0, 0.299899,-0.0122116) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.796924,0.0168634) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.776198,-0.0563797) , 
0, 159630, 1, 0, 0.795275,0.0166808) , 
4, 0.13457, 1, 0, 0.507532,-0.000101573)    );
  // itree = 265
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.301693,-0.0129132) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586811,0.00690366) , 
4, 0.0587458, 1, 0, 0.502989,0.00246987) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424668,-0.0473286) , 
1, 16.8571, 1, 0, 0.500556,5.76792e-05)    );
  // itree = 266
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0450031,-0.0243165) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.215327,-0.0351018) , 
5, 1223.46, 1, 0, 0.114939,-0.0280951) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47094,0.00699668) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.687968,-0.00963786) , 
2, 76730, 1, 0, 0.544606,0.00366009) , 
7, -1.85228, 1, 0, 0.508455,0.000988293)    );
  // itree = 267
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548833,-0.0451512) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.189046,-0.017742) , 
1, 4.52381, 1, 0, 0.264505,-0.0284243) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.663392,0.021855) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506582,-0.00298571) , 
7, -0.465236, 1, 0, 0.541571,0.00393105) , 
7, -1.27977, 1, 0, 0.499117,-0.00102671)    );
  // itree = 268
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498065,0.00684784) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.912217,-0.0600467) , 
4, 0.342849, 1, 0, 0.526121,0.00636027) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.287893,-0.0371922) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.132524,0.0110495) , 
8, 0.0571407, 1, 0, 0.248769,-0.0314372) , 
7, 1.57124, 1, 0, 0.492163,0.00173247)    );
  // itree = 269
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0487953,0.0169497) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.412936,0.0451635) , 
5, 1045.16, 1, 0, 0.23019,0.0401985) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517976,-0.0103311) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501948,0.00727552) , 
7, -0.0139836, 1, 0, 0.509023,-0.000327974) , 
7, -1.85633, 1, 0, 0.487281,0.00283197)    );
  // itree = 270
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.20835,-0.00752745) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.60394,0.0284279) , 
5, 1744.05, 1, 0, 0.288656,0.00335674) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.691246,-0.0255567) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534847,0.00359256) , 
3, 0.047619, 1, 0, 0.647337,-0.025468) , 
4, 0.0969543, 1, 0, 0.474896,-0.0116101)    );
  // itree = 271
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456658,0.00394109) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506836,0.0538649) , 
1, 13.3333, 1, 0, 0.460518,0.0118999) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322176,0.0123773) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559104,-0.010298) , 
4, 0.0574849, 1, 0, 0.492914,-0.00586081) , 
7, -0.429117, 1, 0, 0.48111,0.000610439)    );
  // itree = 272
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588694,0.00396405) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26403,-0.019432) , 
3, 0.047619, 1, 0, 0.502559,-0.00139266) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475309,-0.0243348) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528818,0.0515126) , 
7, -0.738306, 1, 0, 0.509334,0.0402718) , 
1, 13.3333, 1, 0, 0.503075,0.00177765)    );
  // itree = 273
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371665,-0.00277675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.880986,0.0114443) , 
4, 0.172677, 1, 0, 0.54416,0.00210869) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0833192,0.00135398) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437087,-0.0582172) , 
4, 0.174485, 1, 0, 0.172369,-0.0276778) , 
6, 5.07651, 1, 0, 0.506178,-0.000934335)    );
  // itree = 274
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.425569,0.00651169) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.901687,-0.018297) , 
4, 0.248152, 1, 0, 0.516555,0.00455442) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.633414,0.0725782) , 
0, 192318, 1, 0, 0.519577,0.00660036)    );
  // itree = 275
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533397,-0.0069688) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448564,0.00851545) , 
7, 0.875504, 1, 0, 0.513928,-0.00410697) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0838403,-0.0626694) , 
7, 2.42139, 1, 0, 0.496712,-0.00593398)    );
  // itree = 276
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.352553,-0.00126351) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536671,-0.0339167) , 
7, -1.03913, 1, 0, 0.407037,-0.0165271) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363721,0.0226671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.667873,0.00179554) , 
4, 0.0763886, 1, 0, 0.553588,0.0120201) , 
7, -0.711053, 1, 0, 0.51183,0.00388598)    );
  // itree = 277
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.786364,0.0323748) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.818428,0.00221484) , 
7, -0.555178, 1, 0, 0.809267,0.0145281) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288098,-0.0171861) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424042,0.00503409) , 
0, 78309.1, 1, 0, 0.334072,-0.0141158) , 
1, 4.52381, 1, 0, 0.477594,-0.00546458)    );
  // itree = 278
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572884,0.0268721) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.81871,0.00662894) , 
2, 38206.8, 1, 0, 0.733881,0.0215033) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396984,-0.00960856) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345072,0.00824361) , 
3, 0.047619, 1, 0, 0.376225,-0.0056244) , 
1, 5.14286, 1, 0, 0.518889,0.00519648)    );
  // itree = 279
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502455,4.91283e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396021,-0.0281154) , 
1, 12.5238, 1, 0, 0.49428,-0.00359298) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578492,0.0490013) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674041,0.00907648) , 
2, 131435, 1, 0, 0.631762,0.0556416) , 
0, 132062, 1, 0, 0.503692,0.000462011)    );
  // itree = 280
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599069,-0.00337304) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.103968,-0.0399827) , 
6, 2.80668, 1, 0, 0.526374,-0.0107233) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421068,0.0137197) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.668509,-0.0404249) , 
2, 143719, 1, 0, 0.45812,0.0100301) , 
0, 65716.6, 1, 0, 0.504235,-0.00399168)    );
  // itree = 281
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285342,0.0110384) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.450271,-0.0104956) , 
8, -0.0262084, 1, 0, 0.405614,-0.00848049) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.961618,0.0441209) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.929833,-0.00451842) , 
4, 0.351081, 1, 0, 0.95038,0.0242384) , 
4, 0.28582, 1, 0, 0.485127,-0.00370494)    );
  // itree = 282
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340479,-0.0107998) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.840649,0.00578791) , 
4, 0.152296, 1, 0, 0.534389,-0.00670986) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.410218,0.016283) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0984514,-0.0420685) , 
6, 5.69907, 1, 0, 0.381181,0.0145071) , 
8, 0.0227751, 1, 0, 0.491013,-0.000702968)    );
  // itree = 283
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517385,-0.0159372) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.953296,0.0168069) , 
5, 2571.83, 1, 0, 0.714992,-0.00972346) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.113514,0.0220483) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.648968,0.00103466) , 
4, 0.115614, 1, 0, 0.371588,0.013369) , 
1, 5.14286, 1, 0, 0.509923,0.0040666)    );
  // itree = 284
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383365,0.00940471) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.917035,-0.0228344) , 
5, 4944.59, 1, 0, 0.498891,0.00752705) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.769866,-0.0711773) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.829322,0.0395438) , 
0, 182068, 1, 0, 0.792892,-0.0325186) , 
2, 142119, 1, 0, 0.520647,0.00456362)    );
  // itree = 285
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583372,1.94477e-07) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395122,0.0162414) , 
1, 7.66667, 1, 0, 0.5121,0.00879729) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407026,-0.0213314) , 
1, 15.7619, 1, 0, 0.50779,0.0068852)    );
  // itree = 286
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574894,-0.0391179) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5585,-0.0098461) , 
4, 0.0194822, 1, 0, 0.559572,-0.0159724) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28655,0.0387888) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411828,-0.00235327) , 
8, -0.0347783, 1, 0, 0.380466,0.00862318) , 
1, 7.90476, 1, 0, 0.484244,-0.00562813)    );
  // itree = 287
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507667,-0.00281988) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.673058,0.0488532) , 
0, 136084, 1, 0, 0.516916,-0.000450112) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340237,0.0690458) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.779882,0.00628399) , 
4, 0.209673, 1, 0, 0.562015,0.0652263) , 
1, 14.3333, 1, 0, 0.519348,0.00309126)    );
  // itree = 288
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288854,-0.0132731) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58198,0.0148146) , 
4, 0.0590474, 1, 0, 0.489401,0.0103398) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.61878,0.00267169) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375253,-0.0153124) , 
7, 0.906502, 1, 0, 0.508245,-0.00719319) , 
7, -0.140011, 1, 0, 0.499875,0.000594198)    );
  // itree = 289
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501874,0.00640843) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513379,-0.0225037) , 
0, 104899, 1, 0, 0.503182,0.00486791) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58123,0.0300862) , 
1, 17, 1, 0, 0.505155,0.00632771)    );
  // itree = 290
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335905,0.0229568) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591581,-0.00032892) , 
7, -1.15317, 1, 0, 0.532236,0.00575344) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.193388,-0.000182518) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389115,-0.0338441) , 
4, 0.0796517, 1, 0, 0.306416,-0.0277317) , 
7, 1.29006, 1, 0, 0.49371,4.08038e-05)    );
  // itree = 291
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203573,-0.0191919) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.856431,0.0132154) , 
4, 0.208437, 1, 0, 0.327139,-0.0131088) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586221,0.00815498) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.205271,-0.023448) , 
7, 2.1337, 1, 0, 0.565567,0.00991748) , 
8, -0.0244109, 1, 0, 0.504634,0.00403288)    );
  // itree = 292
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248149,0.00653999) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.280219,-0.0200408) , 
2, 48472.1, 1, 0, 0.268373,-0.0131525) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25392,-0.0316169) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.722427,0.0091275) , 
7, -1.83278, 1, 0, 0.690188,0.00884322) , 
4, 0.0948686, 1, 0, 0.500926,-0.0010259)    );
  // itree = 293
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0838403,-0.04335) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554665,0.00529739) , 
7, -2.13759, 1, 0, 0.524311,0.00432801) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.945835,0.0132244) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315105,-0.0160349) , 
1, 2.33333, 1, 0, 0.408957,-0.017648) , 
8, 0.0135064, 1, 0, 0.481557,-0.00381705)    );
  // itree = 294
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.635426,-0.00509085) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.459769,0.0140907) , 
0, 40610, 1, 0, 0.549584,0.00526544) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233942,-0.0443738) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457893,-0.00508543) , 
8, -0.0257209, 1, 0, 0.403093,-0.019492) , 
1, 8.04762, 1, 0, 0.503996,-0.00243906)    );
  // itree = 295
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75365,0.00112003) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252744,-0.0259336) , 
6, 1.96112, 1, 0, 0.556677,-0.0147864) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.148262,-0.0196176) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.462085,0.0246692) , 
0, 62443.6, 1, 0, 0.301289,0.00371409) , 
3, 0.047619, 1, 0, 0.482339,-0.00940136)    );
  // itree = 296
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0407614,-0.0188503) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.280655,0.0706234) , 
8, -0.136701, 1, 0, 0.16503,0.039515) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54283,-0.00106725) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217164,0.0356189) , 
6, 7.50951, 1, 0, 0.530656,0.000711668) , 
8, -0.0760158, 1, 0, 0.494798,0.00451723)    );
  // itree = 297
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488498,0.00124823) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.883615,-0.0534015) , 
4, 0.343093, 1, 0, 0.518931,-0.00148477) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330174,0.0968135) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.219305,0.013762) , 
2, 42191.5, 1, 0, 0.257263,0.054954) , 
7, 1.85733, 1, 0, 0.493186,0.00406806)    );
  // itree = 298
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.695409,0.0025877) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.263483,-0.0124178) , 
6, 1.73277, 1, 0, 0.469499,-0.00705714) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.914008,0.0375086) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 1,0.0492366) , 
5, 10721.2, 1, 0, 0.953211,0.0375079) , 
4, 0.342466, 1, 0, 0.499742,-0.00427073)    );
  // itree = 299
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75114,0.00235821) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.553201,-0.0362096) , 
0, 45843.4, 1, 0, 0.698727,-0.0132965) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27752,0.000966272) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368291,0.0227004) , 
3, 0.047619, 1, 0, 0.312965,0.0104993) , 
6, 1.79485, 1, 0, 0.501029,-0.00110147)    );
  // itree = 300
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.615603,-0.0162601) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395772,0.00225448) , 
0, 37682, 1, 0, 0.47316,-0.00569073) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515005,-0.0383106) , 
0, 158163, 1, 0, 0.475296,-0.00785922)    );
  // itree = 301
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564637,-2.80061e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.427935,0.0436983) , 
6, 3.25916, 1, 0, 0.554734,0.0043544) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0973823,-0.00761431) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694904,-0.0300959) , 
4, 0.206579, 1, 0, 0.24462,-0.0210737) , 
6, 3.78885, 1, 0, 0.49737,-0.000349274)    );
  // itree = 302
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315053,-0.00549429) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.799839,0.0125214) , 
4, 0.13457, 1, 0, 0.506888,0.00226089) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.446759,-0.0312289) , 
1, 15.0952, 1, 0, 0.504864,0.000249698)    );
  // itree = 303
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.632113,0.0085879) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.152231,-0.0237108) , 
0, 39953.6, 1, 0, 0.321516,-0.0112665) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877257,-0.0135449) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509607,0.0117718) , 
1, 3.95238, 1, 0, 0.592181,0.0115954) , 
4, 0.058682, 1, 0, 0.512458,0.00486148)    );
  // itree = 304
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563249,-0.0128423) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.234509,0.0276281) , 
8, 0.0667612, 1, 0, 0.527831,-0.0124944) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.225033,-0.0205974) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513221,0.0228841) , 
2, 46886.4, 1, 0, 0.410113,0.00997975) , 
7, 0.715243, 1, 0, 0.492055,-0.00566419)    );
  // itree = 305
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522953,-0.00242365) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664944,0.025131) , 
7, 0.430484, 1, 0, 0.547888,0.00395713) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.807205,0.00326658) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.197677,-0.037327) , 
1, 5, 1, 0, 0.352376,-0.0338516) , 
7, 1.00139, 1, 0, 0.502698,-0.00478186)    );
  // itree = 306
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.107433,-0.0349229) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588027,0.0102249) , 
7, -2.22318, 1, 0, 0.559391,0.0108809) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.237104,-0.0192275) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.915389,0.055863) , 
4, 0.285322, 1, 0, 0.322322,-0.0125487) , 
7, 1.00527, 1, 0, 0.501187,0.00512861)    );
  // itree = 307
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614283,0.0259633) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680342,-0.000603575) , 
2, 40911, 1, 0, 0.666188,0.0098664) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.113309,-0.0379988) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.331923,-0.00133948) , 
0, 47270.5, 1, 0, 0.281475,-0.0121332) , 
6, 1.90533, 1, 0, 0.478147,-0.000886629)    );
  // itree = 308
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.977414,0.0187317) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.976189,0.0476047) , 
0, 42762.5, 1, 0, 0.977201,0.0176234) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.413485,-0.0143972) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367774,0.00515307) , 
1, 8, 1, 0, 0.390375,-0.00681926) , 
1, 2.7619, 1, 0, 0.486525,-0.00281439)    );
  // itree = 309
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.172887,-0.0620235) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.240534,0.0161499) , 
7, -0.143788, 1, 0, 0.209287,-0.023473) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.710953,-0.00597543) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340322,0.00766231) , 
6, 1.90533, 1, 0, 0.544789,0.000157174) , 
8, -0.0522124, 1, 0, 0.498594,-0.0030964)    );
  // itree = 310
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0350709,0.0200213) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.284994,0.0596061) , 
5, 1102.1, 1, 0, 0.150728,0.0421568) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.198966,0.0319594) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546924,-0.007587) , 
8, -0.0681849, 1, 0, 0.5088,-0.00585527) , 
7, -2.13793, 1, 0, 0.48679,-0.0029041)    );
  // itree = 311
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0752255,-0.0141901) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.187866,-0.0619892) , 
4, 0.128584, 1, 0, 0.104245,-0.0342492) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392962,-0.000507046) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.907697,0.0197515) , 
4, 0.210161, 1, 0, 0.542279,0.00659666) , 
8, -0.0722079, 1, 0, 0.498629,0.00252633)    );
  // itree = 312
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569287,0.00457427) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273029,0.0527199) , 
6, 4.74225, 1, 0, 0.55113,0.0100479) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350579,0.0164259) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445639,-0.0153665) , 
7, -0.974237, 1, 0, 0.42172,-0.0099153) , 
1, 9, 1, 0, 0.511171,0.00388368)    );
  // itree = 313
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221612,0.0539427) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592547,0.000280226) , 
8, -0.0644857, 1, 0, 0.556597,0.0055509) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.105711,0.00560709) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.723308,-0.0407463) , 
4, 0.209376, 1, 0, 0.269202,-0.0157828) , 
6, 3.76187, 1, 0, 0.500777,0.00140726)    );
  // itree = 314
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580336,0.0341868) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.722744,0.00673012) , 
7, -1.55052, 1, 0, 0.707682,0.013844) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247404,-0.0190075) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322288,0.00178306) , 
7, -0.425762, 1, 0, 0.295763,-0.0064407) , 
6, 1.90533, 1, 0, 0.509979,0.00410827)    );
  // itree = 315
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502938,0.00416116) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49779,0.0204889) , 
1, 12.3333, 1, 0, 0.502562,0.00719827) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396505,-0.0313325) , 
1, 15.7619, 1, 0, 0.498094,0.00472502)    );
  // itree = 316
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544762,-0.00568129) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382851,0.00568279) , 
8, 0.0261276, 1, 0, 0.499797,-0.00379589) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.449496,-0.0340403) , 
1, 15.6667, 1, 0, 0.498199,-0.00558814)    );
  // itree = 317
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.951959,0.0342778) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.271038,-0.0181773) , 
1, 2.33333, 1, 0, 0.362819,-0.0156879) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605043,0.010976) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0432923,-0.0411332) , 
8, 0.125585, 1, 0, 0.563862,0.0118942) , 
8, -0.0232873, 1, 0, 0.510793,0.0046133)    );
  // itree = 318
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.436587,0.00310681) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605217,-0.0165179) , 
2, 51222.1, 1, 0, 0.540689,-0.0101409) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493677,-0.00191303) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393272,0.0283352) , 
1, 7.66667, 1, 0, 0.451543,0.0161511) , 
7, 0.701251, 1, 0, 0.512363,-0.00178667)    );
  // itree = 319
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785211,-0.00828777) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.429082,0.0179701) , 
1, 4.52381, 1, 0, 0.535321,0.0146593) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264928,-0.0219426) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.967085,0.0285183) , 
5, 4323.68, 1, 0, 0.452428,-0.0190606) , 
7, 0.439563, 1, 0, 0.503831,0.00184948)    );
  // itree = 320
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.129778,0.0998761) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325348,0.0064544) , 
7, -1.83091, 1, 0, 0.302931,0.013481) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344384,-0.0131846) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.840966,0.0026855) , 
4, 0.187615, 1, 0, 0.555064,-0.0103242) , 
4, 0.0572325, 1, 0, 0.483371,-0.00355523)    );
  // itree = 321
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.253239,-0.00689452) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76004,-0.0459865) , 
4, 0.172177, 1, 0, 0.408729,-0.0246641) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303455,-0.0230558) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586432,0.00270394) , 
8, -0.0359783, 1, 0, 0.530485,-0.0022611) , 
7, -0.711066, 1, 0, 0.495591,-0.00868167)    );
  // itree = 322
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.585266,-0.00601016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361959,0.00891038) , 
6, 3.76942, 1, 0, 0.543544,-0.00394876) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492914,0.0323564) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.218405,0.00336094) , 
3, 0.047619, 1, 0, 0.39145,0.0323957) , 
7, 0.987524, 1, 0, 0.505691,0.0050966)    );
  // itree = 323
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.67798,-0.0104005) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.161156,0.0126793) , 
6, 1.27753, 1, 0, 0.351092,0.00436661) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.662898,-0.0256225) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.926691,-0.00626835) , 
4, 0.268426, 1, 0, 0.799218,-0.0231631) , 
4, 0.170919, 1, 0, 0.505371,-0.00511117)    );
  // itree = 324
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359822,0.0182675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319614,-0.00763096) , 
4, 0.0365835, 1, 0, 0.328647,-0.00355748) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.916662,0.0309104) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.82561,-0.00187309) , 
1, 7.19048, 1, 0, 0.875752,0.0161905) , 
4, 0.190494, 1, 0, 0.488966,0.0022293)    );
  // itree = 325
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405402,0.000523642) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.178091,-0.0258197) , 
1, 11.5714, 1, 0, 0.378655,-0.00388775) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.84087,0.0360807) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.917338,0.00247118) , 
4, 0.261171, 1, 0, 0.900784,0.0151015) , 
4, 0.228416, 1, 0, 0.502376,0.000611839)    );
  // itree = 326
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510913,-0.00447751) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564397,-0.0227798) , 
7, 0.171083, 1, 0, 0.520967,-0.0108894) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513969,-0.0107166) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379661,0.0272044) , 
0, 48903, 1, 0, 0.447912,0.0117838) , 
7, 0.701251, 1, 0, 0.497526,-0.0036143)    );
  // itree = 327
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.672119,0.0418508) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.04158,-0.0168651) , 
1, 6.42857, 1, 0, 0.383298,0.0286501) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353561,-0.0133052) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.59016,-0.000875858) , 
8, -0.0232873, 1, 0, 0.52612,-0.00553624) , 
4, 0.038281, 1, 0, 0.503971,-0.000234536)    );
  // itree = 328
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.162604,-0.0359148) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5194,0.000281383) , 
7, -1.85273, 1, 0, 0.486716,-0.00286112) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.672119,0.0406361) , 
0, 158163, 1, 0, 0.495294,-0.000390146)    );
  // itree = 329
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574568,0.0120337) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.166176,-0.0254439) , 
6, 4.84516, 1, 0, 0.532454,0.0109899) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.178664,-0.0135185) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0347145,-0.0931266) , 
7, 2.55307, 1, 0, 0.11015,-0.0434904) , 
7, 2.1427, 1, 0, 0.503326,0.00723224)    );
  // itree = 330
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432956,-0.0344434) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535595,0.00104333) , 
4, 0.0194822, 1, 0, 0.527709,-0.0019474) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485331,0.0245084) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238727,-0.0171034) , 
8, 0.0291815, 1, 0, 0.4187,0.0209846) , 
1, 8.38095, 1, 0, 0.491459,0.00567841)    );
  // itree = 331
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.410954,0.0416433) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102239,-0.0219786) , 
6, 3.28311, 1, 0, 0.31613,0.033193) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.520267,-0.0046182) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603406,0.0261209) , 
0, 104908, 1, 0, 0.53075,-0.00131561) , 
7, -1.28207, 1, 0, 0.492393,0.0048517)    );
  // itree = 332
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721312,-0.00590682) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.157118,0.0182484) , 
1, 4.57143, 1, 0, 0.340656,0.013403) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559193,-0.0460825) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.875033,0.00166247) , 
2, 39317.8, 1, 0, 0.817708,-0.0139265) , 
4, 0.172482, 1, 0, 0.495096,0.00455541)    );
  // itree = 333
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.627868,0.00843118) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312965,-0.013954) , 
3, 0.047619, 1, 0, 0.543913,0.00457702) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533395,-0.0299804) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22601,0.00609536) , 
6, 2.45654, 1, 0, 0.415355,-0.0205285) , 
7, 0.715824, 1, 0, 0.505851,-0.00285604)    );
  // itree = 334
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247634,-0.0278595) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578674,0.00645439) , 
8, -0.0365758, 1, 0, 0.513868,0.0016291) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0872803,-0.00814881) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.703979,0.0265193) , 
4, 0.0969519, 1, 0, 0.466832,0.0246849) , 
1, 9.85714, 1, 0, 0.502526,0.00718877)    );
  // itree = 335
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455992,0.0129006) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.150769,-0.0120453) , 
3, 0.047619, 1, 0, 0.368684,0.0112728) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.841635,-0.0571507) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.922407,-0.00717363) , 
2, 47290.3, 1, 0, 0.913182,-0.0124901) , 
5, 4415.08, 1, 0, 0.519474,0.00469202)    );
  // itree = 336
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302948,-0.0244908) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.239878,0.0267786) , 
4, 0.0518686, 1, 0, 0.294468,-0.0201285) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0627839,-0.0418192) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617788,0.00696527) , 
8, -0.110579, 1, 0, 0.58431,0.00746718) , 
4, 0.0573165, 1, 0, 0.503614,-0.000215804)    );
  // itree = 337
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511245,0.00511177) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.728714,-0.0301428) , 
2, 117136, 1, 0, 0.541066,0.00228757) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360522,-0.0409698) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.219067,-0.00965632) , 
7, 1.61703, 1, 0, 0.263199,-0.0273109) , 
7, 1.2883, 1, 0, 0.493852,-0.00274169)    );
  // itree = 338
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313924,-0.00409278) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.714013,-0.0552149) , 
4, 0.264834, 1, 0, 0.35402,-0.0152171) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366821,-0.00260031) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.913824,0.0205939) , 
4, 0.17223, 1, 0, 0.554085,0.0048277) , 
2, 43488.3, 1, 0, 0.493077,-0.00128484)    );
  // itree = 339
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.443812,0.00623005) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.647421,-0.01478) , 
8, -0.0146668, 1, 0, 0.527096,-0.00386548) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601854,0.0205016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.150427,-0.0158669) , 
8, 0.0753528, 1, 0, 0.487515,0.0175883) , 
8, 0.0094569, 1, 0, 0.510326,0.00522413)    );
  // itree = 340
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0315125,-0.0773934) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493579,-0.00194469) , 
7, -2.41235, 1, 0, 0.47632,-0.00460163) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98166,0.0516804) , 
4, 0.361398, 1, 0, 0.494618,-0.00268023)    );
  // itree = 341
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.373381,0.0198284) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526551,-0.00391863) , 
7, -1.00154, 1, 0, 0.49107,0.00122714) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.454214,0.0458538) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481876,0.0125775) , 
0, 124680, 1, 0, 0.46939,0.0447727) , 
1, 13.3333, 1, 0, 0.489559,0.00426189)    );
  // itree = 342
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420831,0.0151333) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547603,-0.00114693) , 
8, -0.0214898, 1, 0, 0.511358,0.00475897) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474119,-0.03302) , 
1, 16.8571, 1, 0, 0.510242,0.00279327)    );
  // itree = 343
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.711826,-0.0342935) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.956037,0.00441297) , 
5, 1781.66, 1, 0, 0.872937,-0.0193462) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387655,0.0117202) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414542,-0.0101945) , 
1, 9.33333, 1, 0, 0.395995,0.00719318) , 
1, 3.95238, 1, 0, 0.509088,0.000900125)    );
  // itree = 344
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537432,0.00470897) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480247,-0.0173706) , 
7, 0.349987, 1, 0, 0.516491,-0.00515843) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181481,0.0574928) , 
7, 2.41019, 1, 0, 0.501109,-0.00255616)    );
  // itree = 345
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.618916,0.00222286) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343927,0.0357218) , 
6, 2.45032, 1, 0, 0.592785,0.00785855) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233596,-0.0234316) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329654,-0.000321246) , 
3, 0.047619, 1, 0, 0.274269,-0.0206167) , 
6, 2.85053, 1, 0, 0.4924,-0.00111586)    );
  // itree = 346
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489225,0.00405647) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.568107,-0.0243908) , 
7, -0.221613, 1, 0, 0.514477,-0.00719899) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.730074,0.0446522) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458619,0.0068593) , 
7, 0.556421, 1, 0, 0.479758,0.0135339) , 
7, 0.432507, 1, 0, 0.501298,0.0006713)    );
  // itree = 347
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.858849,0.012127) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.148202,-0.0175085) , 
6, 0.824752, 1, 0, 0.297819,-0.0123978) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.45355,-0.0433871) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.649426,0.0103136) , 
2, 23523.7, 1, 0, 0.637946,0.00911281) , 
4, 0.0764593, 1, 0, 0.505302,0.00072406)    );
  // itree = 348
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422814,-0.00493931) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.317061,0.0491747) , 
0, 45883.3, 1, 0, 0.362819,0.0290839) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.619322,0.00767093) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424755,-0.0128774) , 
1, 8.04762, 1, 0, 0.560272,0.0010244) , 
8, -0.0276375, 1, 0, 0.512121,0.00786703)    );
  // itree = 349
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499683,0.0123156) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0734072,-0.0644972) , 
8, 0.0934506, 1, 0, 0.452925,0.0104756) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502939,-0.0122955) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544663,0.0175421) , 
0, 96715.2, 1, 0, 0.509481,-0.0101528) , 
7, -0.425678, 1, 0, 0.488694,-0.00257077)    );
  // itree = 350
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.955315,0.0224792) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445212,-0.00647029) , 
6, 0.652083, 1, 0, 0.542568,-0.00466869) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0575005,0.00283722) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57346,0.0216243) , 
4, 0.134827, 1, 0, 0.244445,0.018413) , 
6, 4.24829, 1, 0, 0.496963,-0.00113779)    );
  // itree = 351
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.060291,-0.0519376) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551361,0.0084484) , 
7, -2.53524, 1, 0, 0.527268,0.00888761) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574009,-0.025611) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361386,-0.00257611) , 
7, 0.960032, 1, 0, 0.456527,-0.0182474) , 
7, 0.146683, 1, 0, 0.493906,-0.00390953)    );
  // itree = 352
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69107,-0.0546904) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.1808,-0.00445203) , 
1, 3.09524, 1, 0, 0.26294,-0.0134688) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.619478,0.00609321) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348493,0.027228) , 
6, 3.78186, 1, 0, 0.573722,0.0138228) , 
8, -0.0380049, 1, 0, 0.514663,0.00863645)    );
  // itree = 353
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381657,-0.0171565) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.101824,0.0481983) , 
6, 3.23501, 1, 0, 0.303558,-0.00661796) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.768033,0.017774) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388198,-0.00226818) , 
6, 1.95257, 1, 0, 0.587159,0.0101067) , 
4, 0.0575487, 1, 0, 0.504181,0.00521325)    );
  // itree = 354
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.215915,0.0194543) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572344,-0.010521) , 
7, -1.65022, 1, 0, 0.502698,-0.00834347) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546178,0.0131058) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.156001,-0.0245954) , 
7, 1.9117, 1, 0, 0.47891,0.0112597) , 
7, 0.145073, 1, 0, 0.49195,0.000513576)    );
  // itree = 355
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.18181,-0.00011) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294301,0.0411344) , 
2, 67993.6, 1, 0, 0.226911,0.0203879) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.450652,-0.0345788) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539761,-0.00658883) , 
7, -0.688357, 1, 0, 0.518372,-0.0180347) , 
7, -1.85228, 1, 0, 0.493457,-0.0147503)    );
  // itree = 356
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502181,-0.0072981) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549584,0.0288633) , 
1, 13.381, 1, 0, 0.505781,-0.00406881) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481563,0.0160645) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.660675,-0.0626829) , 
2, 148894, 1, 0, 0.492676,0.016768) , 
7, 0.145338, 1, 0, 0.499575,0.00579844)    );
  // itree = 357
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504409,0.0313215) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521079,0.00362488) , 
4, 0.0380735, 1, 0, 0.518214,0.00996128) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.398307,-0.0312892) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.556296,0.0173573) , 
3, 0.047619, 1, 0, 0.464874,-0.019218) , 
0, 91663.7, 1, 0, 0.507895,0.00431594)    );
  // itree = 358
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543977,0.0203913) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694153,0.00119668) , 
4, 0.0769734, 1, 0, 0.632361,0.0122734) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.201962,-0.0138547) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.926074,0.0163606) , 
4, 0.24803, 1, 0, 0.362571,-0.0116872) , 
1, 6.90476, 1, 0, 0.502287,0.000721275)    );
  // itree = 359
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.214881,-0.015945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.611927,0.0104574) , 
5, 1757.27, 1, 0, 0.29344,-0.0105787) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.716257,0.0127219) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315027,0.0713245) , 
7, 2.10032, 1, 0, 0.697284,0.0211325) , 
4, 0.0965179, 1, 0, 0.512486,0.0066215)    );
  // itree = 360
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.255651,0.0208899) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530578,-0.00189679) , 
7, -1.5581, 1, 0, 0.498402,0.000108184) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484207,0.0310619) , 
1, 14.2857, 1, 0, 0.497731,0.00252423)    );
  // itree = 361
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.245751,-0.000201755) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.631878,0.029335) , 
5, 1738.6, 1, 0, 0.308111,0.00763298) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.799822,-0.00150215) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423388,-0.0191984) , 
6, 1.76275, 1, 0, 0.60228,-0.0180044) , 
4, 0.0762334, 1, 0, 0.489275,-0.00815581)    );
  // itree = 362
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.633045,0.00103265) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.161806,-0.0128271) , 
6, 1.91973, 1, 0, 0.406638,-0.00695611) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.799434,-0.0259737) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.963129,0.0389525) , 
2, 39610.1, 1, 0, 0.935077,0.0159864) , 
4, 0.266292, 1, 0, 0.498903,-0.00295038)    );
  // itree = 363
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.872957,-0.00307688) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.443651,0.0279593) , 
1, 3.14286, 1, 0, 0.643618,0.0214978) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.269973,0.00400534) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893728,-0.0412945) , 
4, 0.304778, 1, 0, 0.370465,-0.00134403) , 
1, 6.52381, 1, 0, 0.506382,0.0100218)    );
  // itree = 364
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.160935,0.037797) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562402,-0.00287697) , 
7, -2.33113, 1, 0, 0.545053,-0.00203921) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565023,0.0501753) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.133255,0.00347308) , 
6, 1.76738, 1, 0, 0.30137,0.0281679) , 
7, 1.57486, 1, 0, 0.514338,0.00176828)    );
  // itree = 365
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.21331,-0.0844047) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.141506,-0.0144421) , 
0, 39257.1, 1, 0, 0.163868,-0.0377009) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597216,-0.00453126) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440391,0.0109805) , 
1, 7.66667, 1, 0, 0.535006,0.00289821) , 
7, -1.84267, 1, 0, 0.502863,-0.000617962)    );
  // itree = 366
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.478735,0.0124751) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590326,0.0447812) , 
7, -0.283336, 1, 0, 0.488082,0.0204223) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.124614,0.11934) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516467,-0.0104999) , 
8, -0.125972, 1, 0, 0.497293,-0.0106486) , 
7, -0.147319, 1, 0, 0.493062,0.0036229)    );
  // itree = 367
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388793,-0.00427535) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.747535,-0.0379305) , 
4, 0.241937, 1, 0, 0.402915,-0.00791117) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.869811,0.0262555) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.970064,0.00672784) , 
5, 4163.9, 1, 0, 0.946133,0.0149668) , 
4, 0.267263, 1, 0, 0.490365,-0.00422816)    );
  // itree = 368
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536998,-0.00878285) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.174164,-0.0412029) , 
6, 5.14444, 1, 0, 0.499208,-0.0151977) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.520922,0.00784134) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.39027,-0.0148633) , 
1, 10.3333, 1, 0, 0.499634,0.00569513) , 
7, 0.145338, 1, 0, 0.499407,-0.00542628)    );
  // itree = 369
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493727,-0.000697891) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542586,-0.0124188) , 
8, -0.00302949, 1, 0, 0.518299,-0.00886888) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0441312,-0.0305547) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.151061,0.106326) , 
7, -0.437019, 1, 0, 0.107606,0.0321684) , 
8, 0.113961, 1, 0, 0.492322,-0.0062732)    );
  // itree = 370
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.67738,-0.0153306) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.365551,0.00474241) , 
6, 1.91844, 1, 0, 0.534066,-0.00821156) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433358,0.0177515) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.068739,-0.0504597) , 
7, 2.42926, 1, 0, 0.374445,0.0129419) , 
7, 1.0012, 1, 0, 0.496245,-0.00319937)    );
  // itree = 371
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292413,-0.0143835) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584076,0.00481081) , 
4, 0.058682, 1, 0, 0.499313,0.000122936) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.199173,0.0533229) , 
7, 2.42808, 1, 0, 0.488504,0.00211337)    );
  // itree = 372
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.201788,-0.00982924) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390233,0.00953158) , 
8, -0.0262084, 1, 0, 0.337822,0.00644696) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.67137,-0.028578) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.921386,0.0107248) , 
4, 0.247075, 1, 0, 0.822633,-0.0135451) , 
4, 0.170596, 1, 0, 0.495689,-6.29789e-05)    );
  // itree = 373
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.896732,0.0353312) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337104,-0.00188326) , 
1, 3.66667, 1, 0, 0.473726,0.00822652) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424551,-0.00840066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954792,0.0171655) , 
4, 0.2859, 1, 0, 0.500932,-0.00880833) , 
8, -0.00649348, 1, 0, 0.489259,-0.00149966)    );
  // itree = 374
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.257782,0.00040374) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.711282,0.0388632) , 
5, 1951.43, 1, 0, 0.32197,0.00813347) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.661152,-0.0136377) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483903,0.00243338) , 
3, 0.047619, 1, 0, 0.608776,-0.0132564) , 
4, 0.0762669, 1, 0, 0.496199,-0.00486045)    );
  // itree = 375
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.438387,0.0169576) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574184,-0.00342424) , 
7, -0.982251, 1, 0, 0.545446,0.000902496) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0776182,-0.00898278) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.639455,-0.0450849) , 
4, 0.190707, 1, 0, 0.233614,-0.0284582) , 
6, 3.76304, 1, 0, 0.485129,-0.00477664)    );
  // itree = 376
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561091,0.00307365) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.297537,-0.0124054) , 
3, 0.047619, 1, 0, 0.487191,-0.000729804) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.585905,-0.0356797) , 
0, 211427, 1, 0, 0.489837,-0.00193406)    );
  // itree = 377
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.773575,0.0330934) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.907948,0.0115742) , 
8, -0.0383984, 1, 0, 0.891672,0.014897) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512173,-0.0167619) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281304,-0.00213328) , 
6, 1.52685, 1, 0, 0.351367,-0.0109028) , 
1, 3.7619, 1, 0, 0.483653,-0.00458607)    );
  // itree = 378
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.145618,0.00989188) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.443663,-0.0190794) , 
7, -2.1252, 1, 0, 0.384563,-0.0188006) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533475,0.00645757) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.777819,-0.0558457) , 
2, 149187, 1, 0, 0.546928,0.00552997) , 
7, -0.711411, 1, 0, 0.501111,-0.00133579)    );
  // itree = 379
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393797,-0.00410533) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2789,0.0285799) , 
1, 7.28571, 1, 0, 0.349496,0.0114918) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586174,-0.000948963) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.418022,-0.0211662) , 
1, 9.28571, 1, 0, 0.547399,-0.00831206) , 
8, -0.0276375, 1, 0, 0.497804,-0.00334922)    );
  // itree = 380
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55404,0.0358954) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.377005,0.000441431) , 
2, 24039.9, 1, 0, 0.392577,0.00658203) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599079,-0.0202893) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496956,0.0119866) , 
1, 14.3333, 1, 0, 0.586502,-0.0169905) , 
2, 64134.4, 1, 0, 0.478544,-0.00386766)    );
  // itree = 381
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419029,0.0413932) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501575,0.00141988) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431058,-0.0141046) , 
1, 11.5714, 1, 0, 0.4912,-0.00186918) , 
4, 0.0192115, 1, 0, 0.48753,0.00123387)    );
  // itree = 382
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289614,-0.0273713) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528421,0.000856633) , 
7, -1.28141, 1, 0, 0.490348,-0.003352) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532454,0.0343052) , 
1, 15.0952, 1, 0, 0.491861,-0.00122599)    );
  // itree = 383
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540182,0.00114903) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385231,-0.0161562) , 
0, 66682.9, 1, 0, 0.4998,-0.0042075) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.747535,0.0626905) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404212,0.00323457) , 
6, 2.61988, 1, 0, 0.505489,0.0307608) , 
1, 12.0476, 1, 0, 0.500448,-0.000221154)    );
  // itree = 384
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.596503,-0.00575835) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305865,0.0129678) , 
6, 2.85053, 1, 0, 0.515536,-0.00105942) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.763965,0.0468964) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384705,0.00395411) , 
6, 4.41341, 1, 0, 0.571561,0.0434519) , 
1, 14.2857, 1, 0, 0.518498,0.00129386)    );
  // itree = 385
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0126341,-0.0177683) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0551788,-0.0763848) , 
5, 902.148, 1, 0, 0.0329724,-0.0331553) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343463,-0.00142766) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.843896,0.0116931) , 
4, 0.153382, 1, 0, 0.526946,0.00428975) , 
8, -0.115341, 1, 0, 0.499186,0.00218544)    );
  // itree = 386
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549125,-0.000455488) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.211108,0.0253767) , 
6, 2.20718, 1, 0, 0.414658,0.0125503) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.804293,-0.0367196) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.958439,0.0119224) , 
2, 57369.5, 1, 0, 0.900004,-0.0144772) , 
4, 0.247498, 1, 0, 0.514745,0.00697676)    );
  // itree = 387
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368523,0.00289359) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357738,-0.0262136) , 
2, 41529.8, 1, 0, 0.364255,-0.0105879) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629365,0.0149779) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308259,-0.023329) , 
7, 1.55489, 1, 0, 0.591912,0.0132143) , 
2, 54347.8, 1, 0, 0.495208,0.00310357)    );
  // itree = 388
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384872,0.00985913) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509188,-0.00233938) , 
7, -0.710708, 1, 0, 0.472545,0.00127885) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954919,0.044431) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 1,0.0512529) , 
5, 10867.1, 1, 0, 0.975388,0.0320722) , 
4, 0.341318, 1, 0, 0.506666,0.00336837)    );
  // itree = 389
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519367,0.0020687) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354086,-0.0186629) , 
1, 9.7619, 1, 0, 0.488801,-0.00320724) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.757646,0.0404924) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.232379,-0.0103719) , 
6, 5.93425, 1, 0, 0.58513,0.0238096) , 
0, 114736, 1, 0, 0.498832,-0.000393733)    );
  // itree = 390
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518378,0.000307238) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0315125,-0.0552215) , 
8, 0.160235, 1, 0, 0.499986,-0.00135555) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359722,-0.0481349) , 
1, 15.2381, 1, 0, 0.494486,-0.00439165)    );
  // itree = 391
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531206,-0.000515612) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285594,-0.0228558) , 
7, 1.28658, 1, 0, 0.486511,-0.00510653) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524786,0.0485935) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569336,0.00240506) , 
1, 10.3333, 1, 0, 0.552161,0.0252967) , 
0, 96706.5, 1, 0, 0.49778,0.000112326)    );
  // itree = 392
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.904327,-0.00838979) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.920142,0.0401096) , 
0, 39554.6, 1, 0, 0.908904,0.0118307) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411928,-0.00432098) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222805,-0.0234474) , 
7, 1.00076, 1, 0, 0.365983,-0.0120912) , 
1, 3.95238, 1, 0, 0.497822,-0.00628217)    );
  // itree = 393
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.297069,-0.00261237) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76287,0.0177498) , 
4, 0.115628, 1, 0, 0.501972,0.00876676) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.272168,0.0711995) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.703979,0.0114295) , 
4, 0.136003, 1, 0, 0.511867,0.0636762) , 
1, 13.3333, 1, 0, 0.502642,0.0124868)    );
  // itree = 394
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298442,-0.00487919) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305908,0.0220391) , 
4, 0.0721352, 1, 0, 0.300808,0.00678468) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.77404,-0.00588813) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49209,-0.0319704) , 
8, 0.0344457, 1, 0, 0.719927,-0.0166701) , 
4, 0.11541, 1, 0, 0.493907,-0.00402152)    );
  // itree = 395
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296441,0.00393382) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445732,-0.00920679) , 
4, 0.0995049, 1, 0, 0.34833,-0.00241733) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.880486,0.019877) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918277,-0.0224621) , 
4, 0.345094, 1, 0, 0.888539,0.015529) , 
4, 0.209292, 1, 0, 0.496505,0.00250521)    );
  // itree = 396
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353495,-0.00850711) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.858232,0.00970254) , 
4, 0.172506, 1, 0, 0.515511,-0.00386642) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311255,-0.0586493) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505756,-0.0191447) , 
0, 107626, 1, 0, 0.428764,-0.05722) , 
1, 13.3333, 1, 0, 0.509155,-0.00777569)    );
  // itree = 397
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524794,0.00243484) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403725,-0.0176946) , 
0, 66683.9, 1, 0, 0.489435,-0.00420336) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546133,0.0232299) , 
1, 15.0952, 1, 0, 0.491597,-0.00240813)    );
  // itree = 398
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514415,-0.0286423) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.811677,0.0162483) , 
7, -1.53804, 1, 0, 0.788257,0.012947) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353645,-0.00891513) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298617,0.00973438) , 
6, 3.64713, 1, 0, 0.335519,-0.00455685) , 
6, 1.29156, 1, 0, 0.504516,0.00197692)    );
  // itree = 399
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608476,0.0140758) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456468,-0.0065235) , 
8, 0.0159502, 1, 0, 0.557045,0.00984392) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.118386,-0.00206072) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.653192,-0.0267712) , 
5, 2366.66, 1, 0, 0.241723,-0.0148673) , 
6, 3.41177, 1, 0, 0.489427,0.00454486)    );
  // itree = 400
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426538,-0.00320776) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.166711,-0.0465918) , 
1, 11.5238, 1, 0, 0.413449,-0.00805818) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401281,-0.00437947) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.920795,0.0343496) , 
4, 0.135214, 1, 0, 0.648061,0.0124629) , 
2, 68566.3, 1, 0, 0.511952,0.000557687)    );
  // itree = 401
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.849952,-0.0159957) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.171752,0.0123266) , 
1, 3.47619, 1, 0, 0.335068,0.00814078) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.649348,-0.0245243) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.906283,-0.000553552) , 
2, 53278.3, 1, 0, 0.818279,-0.0138388) , 
4, 0.17223, 1, 0, 0.484873,0.00132667)    );
  // itree = 402
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491345,0.0169173) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582653,-0.0112653) , 
2, 27262.9, 1, 0, 0.57199,-0.00794111) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.201275,0.0127918) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.856057,-0.0213259) , 
4, 0.229351, 1, 0, 0.372532,0.00668266) , 
1, 7.19048, 1, 0, 0.494603,-0.00226732)    );
  // itree = 403
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.640212,0.04451) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308858,-0.0124106) , 
4, 0.0117897, 1, 0, 0.453861,0.0237723) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502527,-0.0027184) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473314,-0.0173278) , 
1, 12.8095, 1, 0, 0.499603,-0.0060262) , 
4, 0.0208184, 1, 0, 0.496494,-0.00400134)    );
  // itree = 404
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341468,-0.00764071) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.610341,0.00859428) , 
4, 0.07624, 1, 0, 0.501989,0.00366408) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41489,0.0140231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411161,-0.025552) , 
1, 13.7619, 1, 0, 0.412206,-0.0277066) , 
1, 13, 1, 0, 0.492249,0.000261066)    );
  // itree = 405
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357492,0.00537731) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.861436,0.0231087) , 
4, 0.171432, 1, 0, 0.512875,0.012987) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482893,0.0137312) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.417051,-0.0483742) , 
7, -0.434396, 1, 0, 0.444672,-0.0345952) , 
1, 13.4286, 1, 0, 0.507781,0.00943309)    );
  // itree = 406
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558614,-0.00740092) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.153728,-0.0395839) , 
6, 5.63492, 1, 0, 0.529689,-0.0125832) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.284595,0.00424096) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296309,0.0460401) , 
8, 0.00968297, 1, 0, 0.289903,0.0269017) , 
7, 1.57486, 1, 0, 0.500534,-0.00778229)    );
  // itree = 407
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353189,-0.0190566) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362819,0.0370479) , 
0, 58879, 1, 0, 0.354275,-0.0170185) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393575,0.00938403) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.946857,-0.0241433) , 
5, 5626.79, 1, 0, 0.535737,0.00657375) , 
2, 41427.4, 1, 0, 0.488156,0.000387657)    );
  // itree = 408
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.821572,-0.00988157) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445226,0.0164762) , 
1, 5, 1, 0, 0.585261,0.0108692) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0410183,-0.0432066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.747189,0.00835259) , 
5, 2132.55, 1, 0, 0.233231,-0.0261217) , 
6, 3.76942, 1, 0, 0.514824,0.0034678)    );
  // itree = 409
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560412,0.00788035) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442445,-0.0176704) , 
1, 10.6667, 1, 0, 0.538589,0.00368099) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.272789,-0.00121959) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674567,-0.0218228) , 
4, 0.132101, 1, 0, 0.425424,-0.0127867) , 
7, 0.430449, 1, 0, 0.495415,-0.00260162)    );
  // itree = 410
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996621,0.0611367) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445362,-0.0039412) , 
6, 0.481428, 1, 0, 0.5027,-0.00184973) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.265045,0.0467065) , 
6, 8.47824, 1, 0, 0.496072,0.000102014)    );
  // itree = 411
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.723373,0.0117255) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.279861,-0.00559946) , 
6, 1.82071, 1, 0, 0.510824,0.00449037) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382037,-0.0359897) , 
1, 15.6667, 1, 0, 0.50603,0.00203615)    );
  // itree = 412
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527264,0.0396393) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.61465,0.00336953) , 
4, 0.0382385, 1, 0, 0.597841,0.0126266) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.1257,-0.0184606) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.928092,0.0378702) , 
4, 0.248926, 1, 0, 0.282233,-0.0107477) , 
3, 0.047619, 1, 0, 0.507514,0.00593686)    );
  // itree = 413
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440754,0.005653) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48729,-0.00546145) , 
7, -0.42608, 1, 0, 0.470377,-0.002153) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971562,0.045902) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971252,-0.0113367) , 
2, 86813.9, 1, 0, 0.971408,0.0245734) , 
4, 0.343087, 1, 0, 0.504103,-0.000354)    );
  // itree = 414
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 1,0.0529391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563243,-0.0113868) , 
6, 0.407538, 1, 0, 0.61431,-0.0126609) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221139,-0.00871503) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332102,0.0180688) , 
7, -0.428759, 1, 0, 0.285104,0.0100199) , 
6, 2.52625, 1, 0, 0.490722,-0.00414626)    );
  // itree = 415
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551735,-0.0117246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.259483,0.0275815) , 
8, 0.0678292, 1, 0, 0.521455,-0.0107198) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.454464,0.00346893) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385709,0.0463479) , 
1, 9, 1, 0, 0.433122,0.0208884) , 
7, 0.720992, 1, 0, 0.492921,-0.000509223)    );
  // itree = 416
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472692,0.0186457) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.695557,0.00268905) , 
2, 35920.6, 1, 0, 0.627062,0.0122923) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.17742,-0.0182423) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918475,0.02359) , 
4, 0.248454, 1, 0, 0.350946,-0.0120851) , 
1, 6.52381, 1, 0, 0.492208,0.000386475)    );
  // itree = 417
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.268132,0.0257185) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533709,-0.002182) , 
7, -1.55873, 1, 0, 0.501405,0.000493338) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494612,-0.0147758) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329252,-0.051692) , 
7, 0.117146, 1, 0, 0.427515,-0.0478939) , 
1, 13.3333, 1, 0, 0.496344,-0.00282096)    );
  // itree = 418
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526001,0.00709516) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.162592,-0.013714) , 
0, 41430, 1, 0, 0.30964,-0.00653664) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680743,0.0631802) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.840084,0.00621828) , 
4, 0.175909, 1, 0, 0.819074,0.0199428) , 
4, 0.15227, 1, 0, 0.502329,0.003479)    );
  // itree = 419
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.96226,0.0162387) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420249,-0.0116742) , 
1, 2.7619, 1, 0, 0.520665,-0.0120867) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426515,0.0417436) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.158259,-0.0130719) , 
7, 1.98042, 1, 0, 0.266695,0.0147459) , 
7, 1.57268, 1, 0, 0.484843,-0.00830201)    );
  // itree = 420
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389002,0.0474207) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.287243,0.00141115) , 
2, 31294, 1, 0, 0.299608,0.0112867) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.655189,-0.0174149) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.792577,0.0157494) , 
0, 87333.6, 1, 0, 0.690733,-0.0129499) , 
4, 0.114489, 1, 0, 0.476769,0.000308724)    );
  // itree = 421
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498865,-0.00120782) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464029,0.0240805) , 
1, 11.7143, 1, 0, 0.494994,0.00273426) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.398529,-0.0264327) , 
1, 16.8571, 1, 0, 0.492017,0.000710573)    );
  // itree = 422
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308285,-0.00266143) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248939,-0.0358458) , 
4, 0.0991574, 1, 0, 0.301299,-0.00902582) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527798,0.0200385) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.854295,-0.00830783) , 
4, 0.196583, 1, 0, 0.725569,0.00846849) , 
4, 0.115436, 1, 0, 0.508757,-0.000471521)    );
  // itree = 423
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328625,0.0124693) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296017,0.0542015) , 
4, 0.0702033, 1, 0, 0.325941,0.0189171) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.648828,0.00215474) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538261,-0.0182793) , 
7, 0.708198, 1, 0, 0.614498,-0.00517666) , 
4, 0.0777019, 1, 0, 0.502641,0.00416313)    );
  // itree = 424
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534044,0.00122548) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376805,0.0377234) , 
1, 9.09524, 1, 0, 0.512946,0.00869027) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0714498,-0.0575485) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53771,-0.00375395) , 
4, 0.0397897, 1, 0, 0.440847,-0.0152244) , 
0, 78531.8, 1, 0, 0.495029,0.00274718)    );
  // itree = 425
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512416,-0.00474138) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466571,0.0120167) , 
7, 0.428457, 1, 0, 0.495313,0.00187278) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48929,0.044015) , 
1, 15.0952, 1, 0, 0.49507,0.00473686)    );
  // itree = 426
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515639,0.00789503) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244114,-0.0161172) , 
7, 1.57137, 1, 0, 0.481169,0.00722028) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.859172,-0.0858238) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.977701,-0.0510539) , 
2, 79453.6, 1, 0, 0.915389,-0.0458764) , 
4, 0.342849, 1, 0, 0.508705,0.00385309)    );
  // itree = 427
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.786209,0.0072252) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.184938,-0.0268448) , 
6, 1.20615, 1, 0, 0.339911,-0.0205407) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.607325,0.0119326) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.459811,-0.0056532) , 
1, 9.85714, 1, 0, 0.571864,0.00968662) , 
8, -0.0210287, 1, 0, 0.507256,0.00126716)    );
  // itree = 428
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.268059,-0.0345837) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592576,-0.00391366) , 
7, -1.2818, 1, 0, 0.542955,-0.00958619) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.438489,0.0252534) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346112,-0.00610973) , 
7, 0.42281, 1, 0, 0.404554,0.0198103) , 
1, 8.38095, 1, 0, 0.500853,-0.000643831)    );
  // itree = 429
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521035,-0.000100447) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506346,0.0148204) , 
7, 0.144582, 1, 0, 0.514242,0.00892331) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518543,0.0174226) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.249842,-0.0913269) , 
7, 0.42281, 1, 0, 0.425765,-0.0268405) , 
1, 11.5714, 1, 0, 0.502218,0.00406305)    );
  // itree = 430
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.781037,0.00154047) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52572,-0.036862) , 
7, 1.25501, 1, 0, 0.747247,-0.00435813) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.275495,0.0153344) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.924485,-0.0575842) , 
5, 7286.03, 1, 0, 0.333186,0.0164403) , 
6, 1.43967, 1, 0, 0.499069,0.00810794)    );
  // itree = 431
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996147,0.041847) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.446034,-0.0107357) , 
1, 1.80952, 1, 0, 0.504975,-0.0112582) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544321,0.00655869) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426515,0.0457212) , 
7, 0.703557, 1, 0, 0.509291,0.0228688) , 
0, 87332.7, 1, 0, 0.505803,-0.00471379)    );
  // itree = 432
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326011,-0.0099984) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.829216,0.0061755) , 
4, 0.171224, 1, 0, 0.491744,-0.00641019) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563065,0.0427075) , 
1, 16.1905, 1, 0, 0.493774,-0.00461308)    );
  // itree = 433
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.956859,0.0222676) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431565,-0.0135106) , 
6, 0.824752, 1, 0, 0.603232,-0.00998319) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00448112,-0.0542856) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.449429,0.0148094) , 
4, 0.0397897, 1, 0, 0.373958,0.0124712) , 
1, 6.28571, 1, 0, 0.488258,0.00127694)    );
  // itree = 434
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40093,-0.00618351) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.896563,-0.0500415) , 
4, 0.303299, 1, 0, 0.462866,-0.0124009) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.654543,-0.00261397) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350198,0.016638) , 
6, 2.16009, 1, 0, 0.526533,0.00822394) , 
7, -0.134355, 1, 0, 0.497944,-0.00103737)    );
  // itree = 435
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.64225,0.00450577) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26851,-0.0121503) , 
1, 6.14286, 1, 0, 0.486294,-0.00363405) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572335,0.0103652) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400331,0.100269) , 
7, 1.27149, 1, 0, 0.539753,0.0293557) , 
0, 96705.6, 1, 0, 0.495421,0.00199839)    );
  // itree = 436
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.685068,-0.0372407) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.941309,0.000566583) , 
5, 1815.16, 1, 0, 0.836593,-0.0280363) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.43312,0.0140975) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310794,-0.0139709) , 
7, 0.430151, 1, 0, 0.386169,0.00441802) , 
1, 3.7619, 1, 0, 0.491949,-0.00320373)    );
  // itree = 437
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.436289,0.0272038) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558689,-0.00875547) , 
4, 0.0384701, 1, 0, 0.538655,-0.00503866) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46066,0.0294755) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338683,-0.0103386) , 
0, 69434.7, 1, 0, 0.424257,0.022334) , 
8, 0.0240742, 1, 0, 0.506942,0.00254945)    );
  // itree = 438
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.802935,-0.016194) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.425956,0.0144933) , 
1, 4.52381, 1, 0, 0.550717,0.00792787) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.161979,0.0105586) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.659856,-0.0227977) , 
5, 1981.05, 1, 0, 0.386201,-0.0104841) , 
8, 0.020861, 1, 0, 0.499093,0.00215034)    );
  // itree = 439
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877614,0.020073) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338715,0.00181785) , 
6, 1.00731, 1, 0, 0.487102,0.00747217) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558878,-0.0368767) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.946711,0.0323185) , 
4, 0.249278, 1, 0, 0.691116,-0.0241988) , 
2, 129494, 1, 0, 0.50597,0.00454317)    );
  // itree = 440
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.754337,0.0210266) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.255794,0.00465349) , 
6, 1.4442, 1, 0, 0.428438,0.0157953) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534894,-0.0143424) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 1,0.0551415) , 
5, 13251, 1, 0, 0.607013,-0.0135168) , 
2, 59115.4, 1, 0, 0.516666,0.0013131)    );
  // itree = 441
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.369469,0.0231759) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502613,-0.0185306) , 
2, 93367.1, 1, 0, 0.397081,0.0161832) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62047,-0.0144768) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440074,0.00242779) , 
7, 0.523485, 1, 0, 0.543042,-0.00870709) , 
7, -0.998732, 1, 0, 0.510121,-0.00309317)    );
  // itree = 442
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.622241,-0.00164449) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0227135,-0.0876114) , 
6, 2.86917, 1, 0, 0.581015,-0.00902651) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238208,-0.01963) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453753,0.0155596) , 
7, -0.995037, 1, 0, 0.397221,0.0106191) , 
0, 47435.2, 1, 0, 0.488548,0.00085723)    );
  // itree = 443
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.992968,0.0356284) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608933,-0.0144007) , 
1, 1.19048, 1, 0, 0.697148,-0.0123836) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348887,0.0188083) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426848,-0.00238431) , 
0, 78584.8, 1, 0, 0.376043,0.0152103) , 
1, 5.42857, 1, 0, 0.505282,0.0041043)    );
  // itree = 444
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346787,-0.00434708) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532454,-0.0484762) , 
4, 0.189514, 1, 0, 0.35603,-0.00934978) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.87421,0.0290688) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.928519,0.00225933) , 
4, 0.273, 1, 0, 0.906297,0.0181218) , 
4, 0.209421, 1, 0, 0.497424,-0.0022908)    );
  // itree = 445
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448564,-0.004004) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41303,-0.0257035) , 
1, 13.3333, 1, 0, 0.445904,-0.00807817) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.940176,0.00239529) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.990936,0.047334) , 
4, 0.364278, 1, 0, 0.969057,0.0236051) , 
4, 0.342466, 1, 0, 0.479797,-0.00602556)    );
  // itree = 446
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442906,-0.0540429) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363898,0.0161179) , 
2, 20790.7, 1, 0, 0.373685,0.00853311) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252666,-0.0281044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696382,-0.00470819) , 
4, 0.076352, 1, 0, 0.518643,-0.0147711) , 
2, 41135, 1, 0, 0.482958,-0.00903415)    );
  // itree = 447
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403747,0.0261563) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.45355,-0.0239233) , 
2, 99617.1, 1, 0, 0.412643,0.0138103) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53078,-0.0103817) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.277186,0.0225024) , 
7, 1.57124, 1, 0, 0.503255,-0.00948357) , 
4, 0.0384668, 1, 0, 0.485604,-0.00494591)    );
  // itree = 448
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583575,0.00583047) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361225,-0.0124978) , 
1, 7.42857, 1, 0, 0.496263,-0.00200565) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608824,0.0541055) , 
1, 17, 1, 0, 0.499165,0.000462238)    );
  // itree = 449
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.652438,0.0071477) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.11815,-0.0499061) , 
0, 46121.2, 1, 0, 0.363455,-0.0230632) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175804,-0.0283293) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578299,0.00446777) , 
8, -0.0480741, 1, 0, 0.514898,0.00109854) , 
4, 0.0398075, 1, 0, 0.486077,-0.00349961)    );
  // itree = 450
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38653,0.00195804) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0486438,-0.0265287) , 
0, 82589.5, 1, 0, 0.314392,-0.00378812) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327988,0.0369346) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674273,0.00596691) , 
4, 0.09186, 1, 0, 0.639418,0.0130502) , 
4, 0.076352, 1, 0, 0.515838,0.00664805)    );
  // itree = 451
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.116937,0.0586608) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552205,-0.00936693) , 
8, -0.0932298, 1, 0, 0.520931,-0.0092447) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.206625,0.0248124) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.823493,-0.0113748) , 
4, 0.192361, 1, 0, 0.432918,0.0173133) , 
1, 8.38095, 1, 0, 0.492751,-0.000741444)    );
  // itree = 452
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512245,-0.0072383) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349712,0.0442107) , 
1, 10.1429, 1, 0, 0.499487,-0.00377245) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.124614,-0.0152817) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559885,0.023024) , 
4, 0.0398075, 1, 0, 0.464009,0.0230339) , 
0, 69869, 1, 0, 0.489139,0.00404644)    );
  // itree = 453
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447971,0.0264677) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514688,-0.00350829) , 
2, 29177.3, 1, 0, 0.506956,0.00117582) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.145512,-0.0011751) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.761263,-0.0443909) , 
4, 0.190345, 1, 0, 0.409935,-0.0277344) , 
1, 11.5714, 1, 0, 0.49299,-0.00298575)    );
  // itree = 454
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.594912,-0.00137844) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375296,0.0162853) , 
3, 0.047619, 1, 0, 0.538348,0.00344761) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235856,-0.0425943) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0972503,0.0425664) , 
6, 4.56616, 1, 0, 0.204472,-0.0284624) , 
7, 1.5709, 1, 0, 0.499001,-0.00031304)    );
  // itree = 455
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313137,-0.00123501) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316208,0.0425463) , 
4, 0.0578503, 1, 0, 0.313779,0.00982459) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432432,-0.00850462) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.973936,0.0114748) , 
5, 5790.81, 1, 0, 0.611196,-0.00858876) , 
4, 0.0758819, 1, 0, 0.497295,-0.00153705)    );
  // itree = 456
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306634,-0.000684887) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295279,0.038271) , 
4, 0.05062, 1, 0, 0.304665,0.00767018) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579938,-0.00857742) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258501,0.0175785) , 
6, 6.26042, 1, 0, 0.559763,-0.00843705) , 
4, 0.0587458, 1, 0, 0.48535,-0.00373849)    );
  // itree = 457
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445993,0.0408293) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320416,-0.0161078) , 
8, 0.00935797, 1, 0, 0.392771,0.017849) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.386041,-0.0269412) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551115,-0.0010639) , 
2, 33719.4, 1, 0, 0.523313,-0.00872334) , 
4, 0.0385261, 1, 0, 0.499982,-0.00397412)    );
  // itree = 458
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491277,-0.00749715) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.276177,0.0131146) , 
0, 43330, 1, 0, 0.371509,0.00561374) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965146,-0.00561343) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.825939,-0.0589561) , 
1, 12.1429, 1, 0, 0.94295,-0.0150072) , 
5, 5629.2, 1, 0, 0.492219,0.0012578)    );
  // itree = 459
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475471,-0.00664678) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.688765,0.0112295) , 
8, -0.00168997, 1, 0, 0.545236,-0.000848581) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.213147,-0.0105956) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472676,0.0254204) , 
4, 0.0586738, 1, 0, 0.39271,0.0200474) , 
8, 0.0229143, 1, 0, 0.503419,0.00488027)    );
  // itree = 460
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513294,0.00628023) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445913,-0.0213919) , 
0, 108578, 1, 0, 0.507145,0.00488836) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.716455,0.0442872) , 
0, 185592, 1, 0, 0.514816,0.006759)    );
  // itree = 461
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473902,-0.00924312) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.92355,0.0210033) , 
4, 0.17256, 1, 0, 0.629232,-0.00263443) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295643,0.0214968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.920325,-0.0503044) , 
5, 7698.58, 1, 0, 0.345147,0.0227267) , 
6, 2.52714, 1, 0, 0.525622,0.0066151)    );
  // itree = 462
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570036,0.00711829) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.109824,-0.065563) , 
7, 2.12081, 1, 0, 0.541135,0.00586948) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482989,-0.0282736) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.228776,0.00533973) , 
6, 2.28208, 1, 0, 0.364383,-0.016197) , 
8, 0.020861, 1, 0, 0.487777,-0.000791944)    );
  // itree = 463
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325218,0.00197389) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.189368,0.0514024) , 
1, 12.9048, 1, 0, 0.315874,0.00664612) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335459,-0.0284848) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.770201,-0.00326705) , 
4, 0.138774, 1, 0, 0.6582,-0.0145711) , 
4, 0.0952474, 1, 0, 0.500989,-0.00482724)    );
  // itree = 464
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411745,0.0225455) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501734,-0.00179972) , 
4, 0.0381109, 1, 0, 0.485287,0.00238925) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.643673,-0.00640702) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.621199,0.0344684) , 
1, 11.5714, 1, 0, 0.629771,0.0347794) , 
0, 131532, 1, 0, 0.49552,0.00468313)    );
  // itree = 465
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.764662,0.0126337) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.291562,-0.00809663) , 
6, 1.95257, 1, 0, 0.58197,0.00557038) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0585249,-0.00791043) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570984,-0.0277581) , 
4, 0.117364, 1, 0, 0.285553,-0.0193736) , 
3, 0.047619, 1, 0, 0.498147,-0.00148346)    );
  // itree = 466
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312965,0.000337847) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382666,0.0323194) , 
4, 0.095206, 1, 0, 0.328112,0.011365) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.621849,-0.0190503) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.915238,0.00701933) , 
4, 0.247398, 1, 0, 0.768517,-0.0118259) , 
4, 0.13331, 1, 0, 0.512669,0.00164659)    );
  // itree = 467
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.178977,-0.00815295) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512018,0.0269909) , 
4, 0.0763604, 1, 0, 0.377867,0.0217549) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551675,-0.00159441) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221612,0.0656631) , 
7, 2.40681, 1, 0, 0.539714,0.000225957) , 
8, -0.0210287, 1, 0, 0.490986,0.00670771)    );
  // itree = 468
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409258,0.0118608) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540722,-0.0090675) , 
7, -0.982251, 1, 0, 0.515052,-0.0072047) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.112807,-0.0250856) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586033,0.0178954) , 
4, 0.0398269, 1, 0, 0.478019,0.0150585) , 
0, 66682.9, 1, 0, 0.502891,0.000105999)    );
  // itree = 469
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617038,0.0357388) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.701733,0.00217443) , 
2, 39610.1, 1, 0, 0.682125,0.0162161) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396361,-0.0282983) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.284168,-0.00453214) , 
1, 4.52381, 1, 0, 0.298238,-0.0120161) , 
6, 1.91937, 1, 0, 0.493797,0.00236588)    );
  // itree = 470
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.622474,0.0200214) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.642976,0.0030259) , 
7, -0.412742, 1, 0, 0.635034,0.0127782) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.242688,-0.0262913) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.386319,0.00756337) , 
1, 8.19048, 1, 0, 0.331167,-0.00526566) , 
1, 6.90476, 1, 0, 0.487784,0.00403435)    );
  // itree = 471
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.402935,0.000866791) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697021,-0.0195861) , 
4, 0.0965516, 1, 0, 0.560524,-0.0136788) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0303014,-0.0260613) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496266,0.0183612) , 
4, 0.0797695, 1, 0, 0.3083,0.00664892) , 
3, 0.047619, 1, 0, 0.4896,-0.00796273)    );
  // itree = 472
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.51836,-0.00900584) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262473,0.0316233) , 
6, 5.46255, 1, 0, 0.505881,-0.00880616) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.232246,0.0841444) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503054,0.00906397) , 
8, -0.0684185, 1, 0, 0.472354,0.0214931) , 
1, 9.85714, 1, 0, 0.497551,-0.00127775)    );
  // itree = 473
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.90887,0.0204534) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388111,-0.00211858) , 
1, 3.7619, 1, 0, 0.517314,0.00246786) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.100597,-0.0647062) , 
6, 7.19862, 1, 0, 0.500265,-0.0002403)    );
  // itree = 474
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.958305,0.00195439) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505104,0.017752) , 
1, 2.19048, 1, 0, 0.660383,0.0197348) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388042,-0.0110871) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.234443,0.0137606) , 
8, 0.0249105, 1, 0, 0.339894,-0.00600819) , 
1, 6.33333, 1, 0, 0.502908,0.00708577)    );
  // itree = 475
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516712,0.00272445) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.198442,0.0543685) , 
7, 2.13598, 1, 0, 0.496485,0.00651152) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447462,-0.0391117) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433005,-0.000689502) , 
8, 0.000857734, 1, 0, 0.440533,-0.0335534) , 
1, 12.8095, 1, 0, 0.490693,0.00236418)    );
  // itree = 476
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.758765,-0.0621114) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2149,-0.00837922) , 
6, 0.901263, 1, 0, 0.3066,-0.0199914) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579785,0.0407982) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543483,0.000170625) , 
7, -1.07161, 1, 0, 0.545253,0.00263356) , 
7, -1.27748, 1, 0, 0.504907,-0.00119136)    );
  // itree = 477
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244037,0.00697676) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497559,-0.0282517) , 
7, -1.58195, 1, 0, 0.396096,-0.0196719) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.640974,0.0167965) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40184,-0.0108943) , 
7, 0.879218, 1, 0, 0.551278,0.00839) , 
7, -0.710708, 1, 0, 0.508504,0.000655076)    );
  // itree = 478
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481581,0.00366495) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.661508,0.0301712) , 
7, -0.410346, 1, 0, 0.513016,0.0102806) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479234,-0.0155958) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.842228,0.0568791) , 
2, 144893, 1, 0, 0.501249,-0.0151232) , 
7, -0.137685, 1, 0, 0.506547,-0.00368455)    );
  // itree = 479
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.126694,-0.000611158) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0627839,-0.0687802) , 
0, 60338.1, 1, 0, 0.0981483,-0.0270999) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440529,-0.00604379) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583901,0.00961707) , 
7, -0.703497, 1, 0, 0.542924,0.00715766) , 
8, -0.0706489, 1, 0, 0.49508,0.00347263)    );
  // itree = 480
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.719658,0.0018261) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434615,0.0285234) , 
6, 1.56393, 1, 0, 0.668419,0.0103411) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.10295,0.021759) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.408551,-0.0177962) , 
4, 0.0764354, 1, 0, 0.291628,-0.00995041) , 
6, 1.91937, 1, 0, 0.484359,0.000428834)    );
  // itree = 481
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.705501,-0.008949) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.668168,0.0132896) , 
7, 0.413855, 1, 0, 0.690711,0.000188893) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.214692,0.00283514) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481936,0.0257264) , 
0, 78584.2, 1, 0, 0.330777,0.0173677) , 
6, 1.91844, 1, 0, 0.513408,0.00865112)    );
  // itree = 482
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0572596,0.0270336) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303051,0.0576423) , 
4, 0.0812432, 1, 0, 0.179659,0.049252) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561497,-0.00323375) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355615,0.0202242) , 
7, 1.28201, 1, 0, 0.522174,0.000993958) , 
7, -2.13859, 1, 0, 0.504431,0.00349386)    );
  // itree = 483
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.430606,-0.0251765) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509803,0.00243904) , 
2, 26647.3, 1, 0, 0.503415,-0.00108104) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.553582,-0.0518367) , 
0, 184803, 1, 0, 0.505166,-0.0030778)    );
  // itree = 484
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475671,0.0375738) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.278852,-0.015878) , 
4, 0.0154205, 1, 0, 0.294917,-0.0128539) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.713722,0.0111062) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383907,-0.0221982) , 
7, 1.55445, 1, 0, 0.678117,0.0103657) , 
4, 0.0965667, 1, 0, 0.500388,-0.000403574)    );
  // itree = 485
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.624503,-0.0195841) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.972526,0.0237423) , 
5, 2592.4, 1, 0, 0.780453,-0.0140186) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396084,0.0133143) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362819,-0.00126012) , 
7, -0.143832, 1, 0, 0.378261,0.00697887) , 
1, 4.52381, 1, 0, 0.503254,0.000453282)    );
  // itree = 486
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539173,0.00784241) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.245079,-0.0321022) , 
7, 1.5709, 1, 0, 0.501312,0.00563416) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481413,-0.0188113) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221612,0.0230144) , 
7, 1.55692, 1, 0, 0.442219,-0.014903) , 
0, 78531.8, 1, 0, 0.486664,0.000543628)    );
  // itree = 487
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50249,-0.00216618) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.646408,-0.0507082) , 
0, 159603, 1, 0, 0.507828,-0.00457428) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.253536,0.0377749) , 
6, 8.705, 1, 0, 0.501299,-0.00318837)    );
  // itree = 488
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528332,0.00069379) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537137,0.020959) , 
0, 59508.4, 1, 0, 0.531145,0.00932246) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.080546,-0.0256367) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.268332,-0.0321891) , 
2, 95631.1, 1, 0, 0.144665,-0.0345066) , 
6, 5.64613, 1, 0, 0.501545,0.00596563)    );
  // itree = 489
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294508,-0.00565246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31659,-0.0209038) , 
4, 0.0889632, 1, 0, 0.299814,-0.0128422) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.799956,0.00486313) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.662777,-0.0182229) , 
1, 12.8095, 1, 0, 0.78023,0.00083424) , 
4, 0.13349, 1, 0, 0.499557,-0.00715593)    );
  // itree = 490
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.194693,0.0367734) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577115,0.00219006) , 
8, -0.068688, 1, 0, 0.538915,0.00571745) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326928,-0.0162066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.657079,0.0247231) , 
2, 114680, 1, 0, 0.413667,-0.00989614) , 
1, 9.85714, 1, 0, 0.508967,0.0019841)    );
  // itree = 491
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.686568,-0.00138218) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.210679,-0.0337377) , 
6, 2.71076, 1, 0, 0.611174,-0.00889769) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364132,0.00014346) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384868,0.0220138) , 
7, 0.139916, 1, 0, 0.373437,0.0134963) , 
1, 6.90476, 1, 0, 0.493556,0.00218155)    );
  // itree = 492
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167222,-0.0179765) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.662287,0.0132271) , 
8, -0.0543815, 1, 0, 0.553551,0.0114634) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.966328,0.0288339) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.280673,-0.0248322) , 
1, 2.47619, 1, 0, 0.382844,-0.0241824) , 
8, 0.0194201, 1, 0, 0.499837,0.000247227)    );
  // itree = 493
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.195301,0.0411763) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551907,0.000910391) , 
8, -0.0657895, 1, 0, 0.509916,0.00503517) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337135,-0.0249358) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.982217,0.0487597) , 
5, 9036.98, 1, 0, 0.508551,-0.0197112) , 
0, 104908, 1, 0, 0.509723,0.00154199)    );
  // itree = 494
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578122,-0.019336) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.331292,0.00158469) , 
3, 0.047619, 1, 0, 0.511573,-0.0188732) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371469,0.0170112) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.808117,-0.0145794) , 
4, 0.209421, 1, 0, 0.472059,0.0143743) , 
7, 0.415327, 1, 0, 0.496591,-0.00626788)    );
  // itree = 495
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525914,0.00350647) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0905032,-0.0549771) , 
7, 2.42808, 1, 0, 0.509272,0.00257524) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532454,0.0412655) , 
1, 16.8571, 1, 0, 0.509891,0.00459925)    );
  // itree = 496
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996672,0.051336) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.642689,-0.0125622) , 
6, 0.454277, 1, 0, 0.711251,-0.0118181) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.194009,0.0173855) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.826309,-0.0103308) , 
4, 0.229552, 1, 0, 0.334952,0.0145973) , 
6, 1.73277, 1, 0, 0.520126,0.00159851)    );
  // itree = 497
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431565,-0.019033) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102026,0.0172859) , 
6, 2.26527, 1, 0, 0.297739,-0.00906539) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.615097,0.0110352) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.815046,-0.0555506) , 
2, 148320, 1, 0, 0.6283,0.0119774) , 
4, 0.0762669, 1, 0, 0.500838,0.00386345)    );
  // itree = 498
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.291907,-0.0344915) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599167,-0.0025171) , 
7, -1.26616, 1, 0, 0.555491,-0.00862793) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0503041,-0.0150867) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614948,0.0228095) , 
4, 0.0976061, 1, 0, 0.359649,0.013118) , 
3, 0.047619, 1, 0, 0.503138,-0.00281468)    );
  // itree = 499
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806789,-0.00896556) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28058,0.0132527) , 
1, 3.42857, 1, 0, 0.422639,0.0115217) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422141,-0.0167343) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.936728,0.0164468) , 
4, 0.172482, 1, 0, 0.604454,-0.00996403) , 
2, 63794.4, 1, 0, 0.505053,0.00178251)    );
  // itree = 500
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.290399,-0.015403) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285811,0.00751317) , 
7, 0.434977, 1, 0, 0.288565,-0.00848414) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.594545,0.014881) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.953254,0.00875204) , 
5, 4825.33, 1, 0, 0.792261,0.0162983) , 
4, 0.13331, 1, 0, 0.498042,0.0018224)    );
  // itree = 501
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.300521,0.0238821) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.444725,-0.000985829) , 
7, -0.996429, 1, 0, 0.411792,0.0052488) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.859077,-0.0605839) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.934042,0.00757476) , 
4, 0.306729, 1, 0, 0.903385,-0.0182025) , 
4, 0.247389, 1, 0, 0.508063,0.000656205)    );
  // itree = 502
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349523,-0.0106687) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669029,0.0296117) , 
2, 153131, 1, 0, 0.366284,-0.0126612) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.889417,-0.0115578) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.951293,0.0371977) , 
0, 47259.1, 1, 0, 0.925713,0.0156407) , 
4, 0.229351, 1, 0, 0.496648,-0.00606599)    );
  // itree = 503
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.904673,0.00861434) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348186,-0.0164836) , 
6, 1.11807, 1, 0, 0.623996,-0.0104386) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181172,0.0476351) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40311,0.00211402) , 
8, -0.0644722, 1, 0, 0.371707,0.0085844) , 
1, 6.90476, 1, 0, 0.498412,-0.000969336)    );
  // itree = 504
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575001,0.00181111) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.435039,-0.0163994) , 
1, 8.38095, 1, 0, 0.529407,-0.00549555) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46939,0.0142567) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.145423,-0.0376249) , 
6, 5.22775, 1, 0, 0.43453,0.0124006) , 
7, 0.715824, 1, 0, 0.499913,6.77868e-05)    );
  // itree = 505
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.299994,0.00173961) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.284994,0.0739463) , 
4, 0.0703166, 1, 0, 0.298592,0.0109714) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.672764,-0.0201022) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547019,0.00364512) , 
1, 6.71429, 1, 0, 0.610301,-0.00868178) , 
4, 0.0777019, 1, 0, 0.487403,-0.000933082)    );
  // itree = 506
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.661278,0.054094) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.197296,0.00805057) , 
1, 5, 1, 0, 0.298357,0.0215591) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292846,0.0241467) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557488,-0.00854919) , 
7, -1.85548, 1, 0, 0.536522,-0.00822402) , 
8, -0.0343171, 1, 0, 0.484149,-0.0016747)    );
  // itree = 507
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580195,0.000548149) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.193836,-0.0216876) , 
6, 3.21679, 1, 0, 0.491686,-0.00515095) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.609904,0.0255388) , 
0, 158174, 1, 0, 0.497701,-0.00328336)    );
  // itree = 508
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266532,-0.00527806) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.317183,-0.0424381) , 
2, 94567.3, 1, 0, 0.27609,-0.0138482) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399945,0.0118149) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.826335,-0.00818751) , 
4, 0.170315, 1, 0, 0.638142,0.0031428) , 
4, 0.0784229, 1, 0, 0.494488,-0.00359881)    );
  // itree = 509
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348429,-0.0206712) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583035,0.0100594) , 
4, 0.0401731, 1, 0, 0.539936,0.00685288) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27943,0.00337123) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.628235,-0.02898) , 
4, 0.114617, 1, 0, 0.431943,-0.0157508) , 
7, 0.430449, 1, 0, 0.499628,-0.00158371)    );
  // itree = 510
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.713475,0.0013369) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.121192,-0.0445083) , 
6, 1.95033, 1, 0, 0.593037,-0.0100675) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515247,0.0103485) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.201962,-0.0104383) , 
6, 4.39752, 1, 0, 0.433191,0.00688998) , 
0, 45789.4, 1, 0, 0.508873,-0.00113884)    );
  // itree = 511
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273719,0.00530705) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697668,0.0577579) , 
5, 1752.29, 1, 0, 0.333508,0.0129021) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548992,0.00509083) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601881,-0.0155561) , 
7, -0.42536, 1, 0, 0.58162,-0.0097957) , 
4, 0.0586787, 1, 0, 0.507719,-0.0030351)    );
  // itree = 512
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572223,0.0340968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544168,0.00808067) , 
2, 29177.3, 1, 0, 0.546748,0.0154053) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273292,-0.0180844) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.718911,0.00889103) , 
4, 0.116046, 1, 0, 0.479766,-0.00615212) , 
7, 0.14087, 1, 0, 0.515815,0.00545009)    );
  // itree = 513
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.053244,-0.00740077) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.129331,-0.0890473) , 
4, 0.0928403, 1, 0, 0.089832,-0.0475135) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.573163,-0.00411736) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400552,0.0113614) , 
7, 0.805739, 1, 0, 0.52098,0.000522392) , 
7, -2.1263, 1, 0, 0.49726,-0.00212034)    );
  // itree = 514
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.604331,-0.00495378) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.64335,0.0271767) , 
7, -0.114314, 1, 0, 0.625116,0.0164451) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310613,0.0080987) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431758,-0.017334) , 
8, -0.0244109, 1, 0, 0.396205,-0.0137954) , 
0, 45793.9, 1, 0, 0.502651,0.000266728)    );
  // itree = 515
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496422,-0.00543125) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421157,-0.0285334) , 
1, 13.0476, 1, 0, 0.491685,-0.00897145) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.702559,0.0266866) , 
0, 185592, 1, 0, 0.49795,-0.00766351)    );
  // itree = 516
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.901775,0.00973632) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419029,-0.0118253) , 
6, 0.836213, 1, 0, 0.560224,-0.00973629) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394743,0.0239062) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.186095,-0.00785674) , 
6, 4.91933, 1, 0, 0.298971,0.010784) , 
6, 3.39809, 1, 0, 0.498948,-0.00492334)    );
  // itree = 517
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.648129,-0.00507835) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470455,0.0185639) , 
0, 40609.8, 1, 0, 0.563141,0.0078494) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.220679,-0.0162094) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.891711,0.0114843) , 
4, 0.247105, 1, 0, 0.389871,-0.0158336) , 
1, 9, 1, 0, 0.508452,0.000374311)    );
  // itree = 518
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581922,0.0421629) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35177,0.0111298) , 
2, 35647.8, 1, 0, 0.388079,0.0230326) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544503,0.00858631) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.460387,-0.0117337) , 
7, 0.158926, 1, 0, 0.50661,-0.000707571) , 
4, 0.038225, 1, 0, 0.48532,0.0035566)    );
  // itree = 519
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366849,-0.0217013) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303051,-0.0731933) , 
4, 0.0128663, 1, 0, 0.337048,-0.0480043) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292846,0.0068586) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.647789,-0.00689913) , 
4, 0.0920034, 1, 0, 0.499044,-0.00219029) , 
4, 0.0192175, 1, 0, 0.490219,-0.00468596)    );
  // itree = 520
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.566926,0.000997345) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366921,0.0150316) , 
0, 50484.7, 1, 0, 0.505352,0.00740996) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0824908,-0.0623504) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521259,-0.011869) , 
8, -0.071317, 1, 0, 0.469421,-0.0193105) , 
0, 78532.9, 1, 0, 0.496954,0.00116464)    );
  // itree = 521
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531951,-0.00135778) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.450855,0.0190427) , 
0, 72122.9, 1, 0, 0.515274,0.0033178) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374172,-0.0428627) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.638835,0.0201742) , 
0, 131608, 1, 0, 0.481174,-0.0244564) , 
1, 12.0476, 1, 0, 0.5116,0.000325148)    );
  // itree = 522
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.121407,0.00435121) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.386259,-0.0322972) , 
4, 0.0949481, 1, 0, 0.247625,-0.0197942) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55252,0.00639691) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422667,-0.0380967) , 
1, 16.1905, 1, 0, 0.548553,0.0060272) , 
8, -0.038237, 1, 0, 0.494643,0.00140141)    );
  // itree = 523
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483482,-0.0081611) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.771116,0.0252769) , 
2, 108162, 1, 0, 0.529732,-0.00543985) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.490785,0.0172281) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355019,-0.0143437) , 
1, 10.3333, 1, 0, 0.468209,0.0159375) , 
7, 0.429913, 1, 0, 0.507348,0.00233796)    );
  // itree = 524
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455594,-0.0146946) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559516,0.0202609) , 
1, 13, 1, 0, 0.466871,-0.013427) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559306,0.00595801) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.147822,-0.0263616) , 
7, 2.18523, 1, 0, 0.521374,0.00444629) , 
7, -0.418703, 1, 0, 0.501675,-0.00201354)    );
  // itree = 525
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602424,-0.00238029) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.268994,-0.0195628) , 
6, 3.65597, 1, 0, 0.539048,-0.00711681) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0951686,-0.0241905) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522067,-0.0571216) , 
4, 0.172633, 1, 0, 0.192527,-0.038771) , 
8, 0.0543204, 1, 0, 0.487693,-0.0118081)    );
  // itree = 526
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366604,-0.0085819) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.850615,0.0106068) , 
4, 0.153356, 1, 0, 0.557004,-0.00236859) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.402028,0.0228415) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0972503,-0.0268956) , 
6, 6.10541, 1, 0, 0.369833,0.022425) , 
7, 1.00037, 1, 0, 0.508399,0.0040699)    );
  // itree = 527
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554003,-0.00268332) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.178791,0.0425755) , 
8, 0.0886065, 1, 0, 0.520035,1.22512e-06) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.287226,-0.00500646) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.224257,0.0515655) , 
6, 6.76897, 1, 0, 0.246447,0.0333616) , 
6, 5.63492, 1, 0, 0.496457,0.00287622)    );
  // itree = 528
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518244,-0.00610012) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479642,0.00732547) , 
7, 0.141135, 1, 0, 0.4997,0.00057267) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.331972,-0.0542244) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.436244,-0.0156566) , 
0, 107748, 1, 0, 0.397344,-0.05072) , 
1, 13.3333, 1, 0, 0.492252,-0.00315953)    );
  // itree = 529
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.892359,0.000582183) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322987,-0.0301033) , 
3, 0.047619, 1, 0, 0.828417,-0.0040407) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75908,0.0239768) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305206,0.00769857) , 
1, 3.66667, 1, 0, 0.360511,0.0149237) , 
6, 1.14892, 1, 0, 0.511453,0.008806)    );
  // itree = 530
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.451337,0.0133851) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613769,-0.00554174) , 
2, 57987, 1, 0, 0.537166,0.00608312) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31355,-0.00481381) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.731269,-0.0400117) , 
4, 0.172506, 1, 0, 0.44127,-0.0175337) , 
7, 0.432507, 1, 0, 0.501133,-0.00279109)    );
  // itree = 531
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.141937,0.0381763) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404833,-0.00602675) , 
7, -1.82981, 1, 0, 0.379747,-0.00550663) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.917277,0.00956682) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.754062,0.0309444) , 
6, 4.28671, 1, 0, 0.895567,0.01703) , 
4, 0.209729, 1, 0, 0.517271,0.000501946)    );
  // itree = 532
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56947,-0.00744124) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.377593,0.00949031) , 
3, 0.047619, 1, 0, 0.520628,-0.00478586) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0897825,0.0170778) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337518,0.0343988) , 
4, 0.0977918, 1, 0, 0.201564,0.0263971) , 
7, 1.85667, 1, 0, 0.493182,-0.00210352)    );
  // itree = 533
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0414538,-0.0526576) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0769192,-0.0575273) , 
4, 0.0858383, 1, 0, 0.0598509,-0.0315805) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44323,0.0164561) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58107,0.00308712) , 
2, 45371.2, 1, 0, 0.538185,0.0102375) , 
8, -0.123084, 1, 0, 0.512133,0.00795999)    );
  // itree = 534
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483732,-0.00790033) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554306,0.0155643) , 
8, -0.00649348, 1, 0, 0.524607,0.00744966) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.520345,-0.0158905) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.256207,0.00263059) , 
7, 1.45861, 1, 0, 0.395182,-0.0116426) , 
7, 0.702497, 1, 0, 0.485247,0.0016434)    );
  // itree = 535
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525982,-0.076441) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163339,-0.0100449) , 
0, 54796.3, 1, 0, 0.343141,-0.0483274) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.715325,0.0126026) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303634,-0.00545592) , 
6, 1.77546, 1, 0, 0.50612,0.00399997) , 
4, 0.0192455, 1, 0, 0.497215,0.00114089)    );
  // itree = 536
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.100945,-0.0822518) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0588881,-0.0400009) , 
6, 2.36477, 1, 0, 0.0777949,-0.0531299) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510328,-0.00139021) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546033,0.0216009) , 
1, 13.3333, 1, 0, 0.512769,0.000813837) , 
7, -2.13759, 1, 0, 0.487658,-0.00230033)    );
  // itree = 537
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0910054,0.0298305) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.191759,-0.0638838) , 
4, 0.0992685, 1, 0, 0.138446,-0.031231) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448899,0.00875913) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531297,-0.00432136) , 
7, -0.905949, 1, 0, 0.515752,-0.00213513) , 
7, -2.1263, 1, 0, 0.492167,-0.00395393)    );
  // itree = 538
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591995,0.00158983) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532454,0.0219328) , 
1, 13, 1, 0, 0.586785,0.00582382) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0638506,-0.0329699) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.820742,0.0215914) , 
4, 0.172154, 1, 0, 0.303888,-0.0136668) , 
3, 0.047619, 1, 0, 0.506511,0.000293197)    );
  // itree = 539
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555063,0.00291866) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.585431,0.0327915) , 
1, 14.619, 1, 0, 0.556665,0.00718462) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.34727,-0.0222666) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.192997,0.038563) , 
7, 1.55546, 1, 0, 0.321104,-0.0159196) , 
8, 0.0333995, 1, 0, 0.499636,0.00159119)    );
  // itree = 540
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.120229,0.0257203) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348803,-0.0121051) , 
8, -0.0548997, 1, 0, 0.311341,-0.0110361) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.723967,-0.0104684) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.794054,0.0151231) , 
8, -0.00718043, 1, 0, 0.766607,0.00747661) , 
4, 0.133251, 1, 0, 0.499479,-0.00338576)    );
  // itree = 541
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395603,0.020938) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513878,-0.00684641) , 
4, 0.0382385, 1, 0, 0.49187,-0.00310254) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55085,0.0334193) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55404,0.00915772) , 
3, 0.047619, 1, 0, 0.552318,0.0447261) , 
1, 13.3333, 1, 0, 0.496354,0.000445215)    );
  // itree = 542
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527521,-0.00424297) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488766,-0.0266005) , 
1, 13.3333, 1, 0, 0.524441,-0.00852627) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.249957,0.0255256) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.724371,-0.0161458) , 
4, 0.152257, 1, 0, 0.412528,0.0103442) , 
8, 0.0181209, 1, 0, 0.487976,-0.00237768)    );
  // itree = 543
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.81871,-0.0754289) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.987655,0.0103237) , 
5, 1669.06, 1, 0, 0.931815,-0.0276517) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.225459,0.0027778) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.913743,-0.0135513) , 
5, 4512.83, 1, 0, 0.397505,0.000250982) , 
1, 2.7619, 1, 0, 0.485399,-0.00433903)    );
  // itree = 544
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.844033,0.00423811) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41446,-0.0123912) , 
1, 4.71429, 1, 0, 0.59787,-0.00812718) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0814321,-0.0294154) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356121,0.0185448) , 
0, 49532, 1, 0, 0.308488,0.0139733) , 
6, 2.52625, 1, 0, 0.496251,-0.000366394)    );
  // itree = 545
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494929,0.0531569) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.438247,0.00406749) , 
4, 0.0619428, 1, 0, 0.453753,0.0334146) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.271824,-0.0159468) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.756243,0.0028099) , 
4, 0.114489, 1, 0, 0.498549,-0.0086867) , 
2, 29177.3, 1, 0, 0.493823,-0.00424449)    );
  // itree = 546
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501119,0.00562208) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503578,-0.0439916) , 
1, 13, 1, 0, 0.501326,0.00168963) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.15752,0.00136139) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325488,0.0625716) , 
0, 125817, 1, 0, 0.245499,0.0461383) , 
6, 6.76717, 1, 0, 0.487116,0.00415852)    );
  // itree = 547
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524519,0.0141342) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483173,-0.00534594) , 
8, 0.00243028, 1, 0, 0.504284,0.00597226) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532454,0.0417397) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469708,-0.00332833) , 
3, 0.047619, 1, 0, 0.502835,0.0399551) , 
1, 12.8095, 1, 0, 0.504147,0.00917989)    );
  // itree = 548
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.648217,0.0115162) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28793,-0.00393096) , 
6, 2.20718, 1, 0, 0.500402,0.00688357) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468086,-0.0246283) , 
1, 16.8571, 1, 0, 0.499518,0.00525737)    );
  // itree = 549
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306118,-0.0214921) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550773,0.0013006) , 
8, -0.0289475, 1, 0, 0.492238,-0.00396689) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525334,0.0264849) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480855,0.00247192) , 
3, 0.047619, 1, 0, 0.503481,0.0252174) , 
1, 12.8095, 1, 0, 0.493352,-0.00107604)    );
  // itree = 550
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522034,0.00128495) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0449439,-0.0611506) , 
7, 2.42808, 1, 0, 0.50032,-0.000187779) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0252294,-0.0156223) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203971,-0.0521048) , 
4, 0.0759793, 1, 0, 0.119389,-0.0521127) , 
6, 6.22263, 1, 0, 0.475889,-0.00351804)    );
  // itree = 551
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493853,0.00177782) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.641218,0.0163525) , 
7, 0.0504868, 1, 0, 0.543492,0.00974898) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.140542,-0.0265481) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721002,0.0066995) , 
5, 2165.38, 1, 0, 0.36183,-0.014157) , 
7, 1.00259, 1, 0, 0.499093,0.00390627)    );
  // itree = 552
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.297885,0.00128197) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.119927,-0.050289) , 
3, 0.047619, 1, 0, 0.230455,-0.0158582) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52405,0.003785) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.700245,0.0305903) , 
0, 158163, 1, 0, 0.532863,0.00677425) , 
7, -1.56907, 1, 0, 0.496919,0.00408413)    );
  // itree = 553
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516474,0.0116211) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592355,-0.00411504) , 
7, -0.425678, 1, 0, 0.564038,0.00213163) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0503041,-0.00770436) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502304,0.0258677) , 
5, 922.021, 1, 0, 0.30008,0.0239012) , 
6, 3.76942, 1, 0, 0.51093,0.00651164)    );
  // itree = 554
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315948,-0.00466698) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.66022,-0.0216465) , 
4, 0.0965248, 1, 0, 0.496532,-0.0179026) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175056,-0.0409322) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534841,0.0134865) , 
8, -0.0432268, 1, 0, 0.470263,0.00734288) , 
7, 0.439563, 1, 0, 0.487239,-0.00897153)    );
  // itree = 555
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469109,0.00481438) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.898119,-0.0548569) , 
4, 0.323865, 1, 0, 0.507587,0.00233664) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474439,0.0347457) , 
1, 14.2857, 1, 0, 0.505924,0.00485587)    );
  // itree = 556
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.232246,-0.0627825) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0782403,-0.00167788) , 
6, 1.61034, 1, 0, 0.127995,-0.0339151) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579015,-0.00270931) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357532,0.0182238) , 
3, 0.047619, 1, 0, 0.5203,0.00293481) , 
7, -1.85273, 1, 0, 0.487706,-0.000126793)    );
  // itree = 557
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484427,-0.0020192) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590058,0.011236) , 
8, -0.0141347, 1, 0, 0.55404,0.00934236) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.12962,-0.00364962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.254648,-0.0385968) , 
4, 0.0958507, 1, 0, 0.185512,-0.0219057) , 
7, 1.85743, 1, 0, 0.522251,0.00664693)    );
  // itree = 558
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302843,0.0112962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49187,0.065544) , 
7, -1.44492, 1, 0, 0.332836,0.0253808) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530499,-0.0059803) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.116937,-0.0549289) , 
6, 7.50872, 1, 0, 0.514698,-0.00964058) , 
7, -1.28167, 1, 0, 0.485067,-0.00393456)    );
  // itree = 559
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.378454,-0.00441153) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.642539,0.00830765) , 
2, 56557.1, 1, 0, 0.508104,0.00116918) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0276825,-0.0332141) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590076,0.0280965) , 
4, 0.0583406, 1, 0, 0.470574,0.0329761) , 
1, 11.3333, 1, 0, 0.503381,0.00517205)    );
  // itree = 560
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.182385,0.0451227) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550376,-0.010576) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338579,0.00655047) , 
7, 1.19372, 1, 0, 0.50818,-0.00962124) , 
7, -2.42289, 1, 0, 0.495807,-0.00787917)    );
  // itree = 561
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380449,-0.0230286) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526574,0.00610599) , 
4, 0.0192175, 1, 0, 0.518479,0.00595259) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.081184,-0.0539938) , 
7, 2.42865, 1, 0, 0.500659,0.0042994)    );
  // itree = 562
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563671,0.00504771) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390556,-0.00842045) , 
0, 51634.1, 1, 0, 0.483439,-0.00169168) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 1,0.0610311) , 
4, 0.359651, 1, 0, 0.506337,0.000128608)    );
  // itree = 563
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565048,0.0328379) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.150786,-0.0170628) , 
0, 61140.7, 1, 0, 0.393659,0.0173007) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499117,-0.0109316) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.976612,0.043482) , 
4, 0.365112, 1, 0, 0.522354,-0.0123999) , 
4, 0.0382385, 1, 0, 0.500829,-0.00743234)    );
  // itree = 564
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68108,-0.00300056) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.237499,-0.0251746) , 
6, 2.55473, 1, 0, 0.555741,-0.0137748) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281708,0.00347007) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.571222,0.042576) , 
1, 13.5714, 1, 0, 0.322394,0.0114296) , 
3, 0.047619, 1, 0, 0.488486,-0.0065104)    );
  // itree = 565
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338876,0.00362477) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222189,-0.023786) , 
7, 0.71813, 1, 0, 0.302043,-0.00462798) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.630625,0.0104848) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.631737,-0.0166597) , 
1, 12.0476, 1, 0, 0.630756,0.00944826) , 
4, 0.076352, 1, 0, 0.498976,0.00380512)    );
  // itree = 566
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.324411,0.0154207) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.720303,-0.00488686) , 
4, 0.115892, 1, 0, 0.501268,0.00727912) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498466,-0.0499452) , 
1, 15.0952, 1, 0, 0.501163,0.00430549)    );
  // itree = 567
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590036,-0.0112236) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312965,0.0253764) , 
8, 0.0534962, 1, 0, 0.558465,-0.00902742) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283207,-0.00970418) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491044,0.0125326) , 
7, -0.709343, 1, 0, 0.431263,0.00933872) , 
0, 51634.1, 1, 0, 0.498456,-0.000363054)    );
  // itree = 568
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591419,-0.00604273) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423943,0.0107301) , 
7, 1.27257, 1, 0, 0.56184,-0.00403986) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25968,0.0223502) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.712653,-0.0138359) , 
4, 0.152494, 1, 0, 0.405788,0.0104442) , 
8, 0.020861, 1, 0, 0.512235,0.000564278)    );
  // itree = 569
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.709206,0.00445193) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499845,0.0393166) , 
7, 1.83382, 1, 0, 0.69642,0.009213) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0675507,0.0192307) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374862,-0.00797032) , 
4, 0.0587627, 1, 0, 0.28886,-0.00464953) , 
6, 1.91937, 1, 0, 0.499071,0.00250048)    );
  // itree = 570
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367262,0.0396807) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570875,-0.0113185) , 
7, -1.54406, 1, 0, 0.546829,-0.00755808) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372253,0.0470945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432621,0.000738617) , 
8, -0.0244109, 1, 0, 0.414206,0.0198586) , 
1, 8.38095, 1, 0, 0.507243,0.000625322)    );
  // itree = 571
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.87735,0.0116589) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.194388,-0.00380863) , 
1, 3.66667, 1, 0, 0.366678,-0.000909641) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.81426,0.0191563) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9336,-0.00030434) , 
4, 0.30002, 1, 0, 0.866631,0.0160988) , 
4, 0.190352, 1, 0, 0.517347,0.00421613)    );
  // itree = 572
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.653999,-0.0188866) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.140442,6.8229e-05) , 
6, 1.27753, 1, 0, 0.314873,-0.0100952) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.822269,0.0110002) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.901094,-0.0301117) , 
2, 122748, 1, 0, 0.836727,0.00929561) , 
4, 0.171224, 1, 0, 0.485034,-0.00377243)    );
  // itree = 573
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.438627,0.0113584) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514569,-0.00824) , 
2, 30909.7, 1, 0, 0.502834,-0.00500935) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532454,0.0590829) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.450986,-0.00846719) , 
8, 0.00284175, 1, 0, 0.492509,0.0430877) , 
1, 11.5714, 1, 0, 0.501286,0.00219953)    );
  // itree = 574
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524134,-0.0117626) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371855,0.00796972) , 
7, 0.996098, 1, 0, 0.485307,-0.00867998) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472238,0.0274512) , 
1, 14.2857, 1, 0, 0.484723,-0.00610163)    );
  // itree = 575
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475455,0.0020583) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.648494,0.0620325) , 
7, -0.286521, 1, 0, 0.493598,0.00951939) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327176,-0.0113181) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.889746,0.015336) , 
4, 0.190707, 1, 0, 0.497516,-0.00613581) , 
7, -0.147611, 1, 0, 0.495798,0.000728545)    );
  // itree = 576
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.33856,-0.00292498) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524626,-0.0287032) , 
4, 0.170415, 1, 0, 0.356233,-0.00781125) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.933198,0.0318637) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.865963,-0.00839111) , 
1, 7.90476, 1, 0, 0.902036,0.00982495) , 
4, 0.210161, 1, 0, 0.509268,-0.00286633)    );
  // itree = 577
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474689,0.00367787) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57432,-0.0352138) , 
7, -0.30405, 1, 0, 0.497731,-0.00615204) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.774195,-0.00293738) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362819,0.0167438) , 
1, 4.57143, 1, 0, 0.487775,0.0137078) , 
7, 0.144582, 1, 0, 0.493129,0.00302685)    );
  // itree = 578
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.271948,-0.0128459) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524283,0.0288472) , 
2, 122760, 1, 0, 0.29064,-0.0111191) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.707327,0.0172131) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.886774,-0.00765839) , 
2, 77619.3, 1, 0, 0.779107,0.0152024) , 
4, 0.133139, 1, 0, 0.494344,-0.000142352)    );
  // itree = 579
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293976,-0.00558341) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577076,0.0107769) , 
4, 0.0596513, 1, 0, 0.490345,0.00836446) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399798,-0.0374392) , 
1, 16.8571, 1, 0, 0.487721,0.00642604)    );
  // itree = 580
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47489,0.00870793) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491432,-0.0118335) , 
2, 30909.7, 1, 0, 0.489051,-0.00935361) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669807,0.0582393) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371655,-0.00993985) , 
6, 2.9051, 1, 0, 0.467266,0.0189637) , 
1, 12.0476, 1, 0, 0.486857,-0.00650204)    );
  // itree = 581
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.18089,0.0202861) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524522,-0.00292006) , 
8, -0.068688, 1, 0, 0.484219,-0.00119957) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221612,0.0480361) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.682884,-0.000698881) , 
4, 0.133391, 1, 0, 0.491188,0.0276765) , 
1, 12.8095, 1, 0, 0.4849,0.00162459)    );
  // itree = 582
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372744,0.00146099) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.819992,-0.0219413) , 
4, 0.19199, 1, 0, 0.512791,-0.00694716) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526979,0.00836444) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47489,0.04618) , 
1, 13, 1, 0, 0.522139,0.0165599) , 
7, 0.140918, 1, 0, 0.517226,0.00420703)    );
  // itree = 583
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545565,0.00704241) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562331,-0.0435338) , 
0, 191726, 1, 0, 0.546105,0.00696881) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.099558,-0.0236581) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.138041,-0.0573515) , 
8, -0.0101098, 1, 0, 0.121296,-0.0435611) , 
7, 1.82815, 1, 0, 0.509275,0.00258802)    );
  // itree = 584
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341086,0.00714937) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.270795,-0.0349943) , 
8, 0.00185843, 1, 0, 0.304595,-0.0192391) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409823,-0.00877922) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586984,0.0130304) , 
4, 0.0397515, 1, 0, 0.553411,0.0123928) , 
7, -1.2818, 1, 0, 0.513788,0.00735548)    );
  // itree = 585
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552968,0.00864433) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401921,-0.0182158) , 
7, 0.715243, 1, 0, 0.506405,0.000850413) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.193188,-0.0465317) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.868072,0.000316999) , 
4, 0.238219, 1, 0, 0.436701,-0.0521007) , 
1, 11.5714, 1, 0, 0.49795,-0.00557274)    );
  // itree = 586
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393878,0.00914596) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.952862,-0.0126638) , 
5, 5626.79, 1, 0, 0.520222,0.00904465) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102239,-0.043277) , 
6, 8.56644, 1, 0, 0.506721,0.00741349)    );
  // itree = 587
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.782374,0.00866931) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322481,-0.00993754) , 
6, 1.47354, 1, 0, 0.528298,-0.00232098) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.103081,0.00755812) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326625,0.0348645) , 
0, 132773, 1, 0, 0.19195,0.0286509) , 
6, 6.05661, 1, 0, 0.506749,-0.000336655)    );
  // itree = 588
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5959,-0.00087627) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.377072,0.0435299) , 
1, 8.42857, 1, 0, 0.570403,0.00634849) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405829,-0.0172547) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167927,0.0370755) , 
7, 2.12745, 1, 0, 0.390463,-0.0181162) , 
0, 47435.2, 1, 0, 0.482214,-0.00564173)    );
  // itree = 589
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.763363,-0.00779132) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.317055,0.00804246) , 
6, 1.24223, 1, 0, 0.479785,0.00378042) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.887106,-0.0577239) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918204,-0.0341546) , 
4, 0.367669, 1, 0, 0.902387,-0.0346821) , 
4, 0.342849, 1, 0, 0.504784,0.00150523)    );
  // itree = 590
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.324099,0.00845039) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.611447,0.035311) , 
4, 0.145969, 1, 0, 0.362647,0.0182117) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.950994,0.0114487) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.707603,-0.017819) , 
6, 1.96112, 1, 0, 0.842484,-0.00943962) , 
4, 0.191247, 1, 0, 0.508386,0.00981326)    );
  // itree = 591
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31168,0.0171392) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.798221,0.0607488) , 
5, 2008.29, 1, 0, 0.367217,0.0225397) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.655322,-0.0152848) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48871,0.000805351) , 
1, 6.90476, 1, 0, 0.567522,-0.00838009) , 
4, 0.0587627, 1, 0, 0.512372,0.000133074)    );
  // itree = 592
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547593,-0.00155191) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.17154,-0.0302479) , 
6, 4.24946, 1, 0, 0.497001,-0.00561946) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309692,0.0446031) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.762438,-0.01322) , 
4, 0.171267, 1, 0, 0.532454,0.0341229) , 
1, 13.4286, 1, 0, 0.499262,-0.00308521)    );
  // itree = 593
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569025,0.00808915) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327988,-0.0303318) , 
1, 14.2857, 1, 0, 0.559686,0.00783847) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2437,-0.0246634) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.734447,0.0346663) , 
2, 125294, 1, 0, 0.323153,-0.0145339) , 
3, 0.047619, 1, 0, 0.49474,0.00169554)    );
  // itree = 594
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514227,0.0182172) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22498,-0.0168109) , 
3, 0.047619, 1, 0, 0.427381,0.011504) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552112,-0.00321514) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.13337,-0.0501673) , 
6, 7.46943, 1, 0, 0.535434,-0.00629681) , 
7, -0.711053, 1, 0, 0.504074,-0.00113047)    );
  // itree = 595
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52106,-0.0167665) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.397889,0.00738672) , 
8, 0.0181209, 1, 0, 0.479674,-0.0110868) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495241,0.0348864) , 
1, 15.7619, 1, 0, 0.480324,-0.00837522)    );
  // itree = 596
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.30633,0.00804796) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.724772,-0.0100589) , 
4, 0.114255, 1, 0, 0.506509,-0.000463749) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.186962,0.0485103) , 
6, 7.50951, 1, 0, 0.492981,0.0017856)    );
  // itree = 597
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605356,-0.019625) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.219104,0.033325) , 
1, 5, 1, 0, 0.319518,0.0178643) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420696,-0.0509244) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541292,0.000441025) , 
7, -1.07936, 1, 0, 0.535744,-0.00275091) , 
7, -1.2837, 1, 0, 0.50207,0.000459674)    );
  // itree = 598
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532872,0.0182655) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243333,-0.00502511) , 
0, 51648.2, 1, 0, 0.404099,0.00980553) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.891853,-0.0323328) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.883615,0.0478056) , 
7, 1.15492, 1, 0, 0.890815,-0.0177478) , 
4, 0.24803, 1, 0, 0.506817,0.0039906)    );
  // itree = 599
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.587144,0.00977576) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.299259,0.0471709) , 
6, 5.43427, 1, 0, 0.565799,0.0176346) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.209186,0.000935671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590765,-0.029358) , 
4, 0.114245, 1, 0, 0.362399,-0.0167286) , 
8, 0.0257083, 1, 0, 0.507593,0.00780109)    );
  // itree = 600
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0794225,-0.0650186) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569935,0.0102533) , 
8, -0.0981632, 1, 0, 0.534082,0.00962252) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.682161,0.0266066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437612,-0.0115509) , 
7, 0.554258, 1, 0, 0.456115,-0.0104468) , 
7, 0.431095, 1, 0, 0.506381,0.00249193)    );
  // itree = 601
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.397305,0.00562867) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414279,-0.0143518) , 
7, -0.42536, 1, 0, 0.407861,-0.0104929) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.945835,-0.00415675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.939628,0.0328143) , 
1, 6.52381, 1, 0, 0.942274,0.0189971) , 
4, 0.266707, 1, 0, 0.501423,-0.00532996)    );
  // itree = 602
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419609,-0.0135609) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806359,0.018743) , 
2, 74460.7, 1, 0, 0.507029,-0.0104045) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426666,0.0140315) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.647399,-0.0422303) , 
2, 157406, 1, 0, 0.463027,0.00907374) , 
0, 72814.5, 1, 0, 0.495076,-0.00511307)    );
  // itree = 603
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.625941,-0.00325531) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434541,0.0204113) , 
0, 44624.5, 1, 0, 0.544667,0.00879688) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.215082,-0.0169311) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.884634,0.0088339) , 
4, 0.247921, 1, 0, 0.38805,-0.0154025) , 
1, 8.04762, 1, 0, 0.493073,0.000824978)    );
  // itree = 604
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565539,-0.00304254) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.317017,0.034074) , 
7, 1.57864, 1, 0, 0.532454,0.00126751) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361539,0.0311119) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466558,0.00265075) , 
0, 72958.8, 1, 0, 0.426975,0.0198019) , 
1, 9.80952, 1, 0, 0.506635,0.00580434)    );
  // itree = 605
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502428,0.0209228) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562473,-0.00165416) , 
2, 32674.3, 1, 0, 0.553442,0.00389992) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.287639,-0.018498) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.933113,0.0305036) , 
4, 0.265824, 1, 0, 0.37019,-0.0164953) , 
8, 0.0181209, 1, 0, 0.495138,-0.00258902)    );
  // itree = 606
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579068,0.00405627) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.259892,-0.0120024) , 
6, 2.85053, 1, 0, 0.487275,-4.47711e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554357,0.0347795) , 
1, 14.3333, 1, 0, 0.490645,0.00343383)    );
  // itree = 607
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363047,0.000347976) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.830046,0.0175287) , 
4, 0.151524, 1, 0, 0.52879,0.00768463) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102816,0.0238094) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.618643,-0.018412) , 
4, 0.0796267, 1, 0, 0.449889,-0.0109036) , 
1, 10.3333, 1, 0, 0.514599,0.00434147)    );
  // itree = 608
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273675,-0.012614) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.751145,0.00567186) , 
4, 0.114255, 1, 0, 0.498507,-0.00444091) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.282747,0.0409167) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.734098,0.000421942) , 
4, 0.152652, 1, 0, 0.523307,0.0364643) , 
1, 13.4286, 1, 0, 0.500406,-0.00130818)    );
  // itree = 609
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591489,0.00443043) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.213639,-0.014587) , 
6, 2.77435, 1, 0, 0.486749,-0.000514661) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521121,0.0787534) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584262,-0.000139331) , 
0, 140055, 1, 0, 0.565725,0.0264139) , 
0, 120607, 1, 0, 0.494831,0.00224111)    );
  // itree = 610
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0668371,-0.0058234) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48305,-0.037027) , 
5, 1988.28, 1, 0, 0.194568,-0.0224807) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252297,0.0499791) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.594689,0.00424112) , 
7, -2.13793, 1, 0, 0.579773,0.00761049) , 
8, -0.0480741, 1, 0, 0.516186,0.00264319)    );
  // itree = 611
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517995,-0.00303565) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.146616,-0.026842) , 
6, 5.15482, 1, 0, 0.483458,-0.00605576) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592696,0.0305555) , 
1, 17, 1, 0, 0.486663,-0.00416906)    );
  // itree = 612
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.149421,-0.0292977) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327161,0.0156319) , 
7, -1.00428, 1, 0, 0.282641,0.00840013) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.207481,-0.041997) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.618152,-0.00517282) , 
4, 0.0749874, 1, 0, 0.574617,-0.0123319) , 
4, 0.0587172, 1, 0, 0.487384,-0.00613786)    );
  // itree = 613
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.655299,-0.00756186) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392413,0.00915009) , 
0, 34315.5, 1, 0, 0.468064,0.00616566) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.744267,-0.0155863) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.43913,-0.0890074) , 
7, 1.23434, 1, 0, 0.68458,-0.0300886) , 
2, 108162, 1, 0, 0.499982,0.000821234)    );
  // itree = 614
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528159,-0.000950832) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507951,-0.0195941) , 
1, 11.6667, 1, 0, 0.526092,-0.00402933) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0627839,0.0408258) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50438,0.0416479) , 
5, 1084.29, 1, 0, 0.225047,0.0477315) , 
6, 5.6335, 1, 0, 0.500368,0.000393667)    );
  // itree = 615
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.226805,-0.00907439) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374759,-0.0490747) , 
2, 88330.4, 1, 0, 0.265648,-0.0225845) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58437,0.00626619) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.16837,-0.0210749) , 
6, 4.98635, 1, 0, 0.53928,0.0047787) , 
7, -1.28207, 1, 0, 0.496466,0.000497327)    );
  // itree = 616
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521866,0.0103491) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721032,-0.0116321) , 
2, 106873, 1, 0, 0.552556,0.00972648) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375409,-0.0476836) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.159526,-0.00209387) , 
7, 1.84351, 1, 0, 0.220526,-0.0188658) , 
7, 1.57124, 1, 0, 0.508622,0.00594312)    );
  // itree = 617
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506037,-0.00324553) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504912,-0.0418706) , 
1, 14.8095, 1, 0, 0.505984,-0.00750017) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.192758,0.0324368) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309104,0.0360397) , 
7, -0.0988689, 1, 0, 0.252497,0.0465474) , 
6, 6.76686, 1, 0, 0.492884,-0.00470698)    );
  // itree = 618
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.30387,0.00458879) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.805001,0.0573441) , 
5, 1977.3, 1, 0, 0.352874,0.0106764) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529357,-0.0140069) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.94976,0.0533739) , 
4, 0.366914, 1, 0, 0.548703,-0.0164284) , 
4, 0.0572527, 1, 0, 0.493962,-0.00885166)    );
  // itree = 619
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310258,-0.0011008) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616528,0.0184365) , 
4, 0.141194, 1, 0, 0.364594,0.00500605) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597654,-0.0704718) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.904343,-0.0131194) , 
2, 34550.1, 1, 0, 0.858979,-0.0262402) , 
4, 0.211029, 1, 0, 0.491047,-0.00298607)    );
  // itree = 620
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464576,0.028114) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264543,-0.0158552) , 
4, 0.0231076, 1, 0, 0.29812,-0.0100115) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366152,0.0260969) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76577,0.00108439) , 
4, 0.124667, 1, 0, 0.689633,0.00872894) , 
4, 0.0955939, 1, 0, 0.513487,0.000297392)    );
  // itree = 621
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308168,0.00490156) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.769155,-0.00895861) , 
4, 0.155086, 1, 0, 0.453946,0.000396225) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.941763,0.0534557) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983289,0.0134255) , 
5, 6566.49, 1, 0, 0.969854,0.032203) , 
4, 0.323769, 1, 0, 0.499093,0.00317964)    );
  // itree = 622
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473427,-0.0215114) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.568381,-0.00191592) , 
2, 34237.3, 1, 0, 0.553004,-0.00786176) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433569,0.0284524) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314018,-0.0101964) , 
7, 0.706323, 1, 0, 0.391034,0.0174826) , 
8, 0.0257083, 1, 0, 0.508821,-0.000948074)    );
  // itree = 623
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.142425,-0.042035) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56642,0.00685005) , 
7, -2.11571, 1, 0, 0.544015,0.00648134) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400008,-0.00344732) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.100945,-0.0758796) , 
6, 5.72582, 1, 0, 0.373138,-0.0106045) , 
8, 0.0227751, 1, 0, 0.493907,0.00147108)    );
  // itree = 624
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311461,-0.0094619) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.633741,0.00518321) , 
4, 0.0778809, 1, 0, 0.506798,0.000299231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401161,-0.065087) , 
1, 16.8571, 1, 0, 0.50379,-0.00291825)    );
  // itree = 625
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.92474,0.0122936) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0601703,-0.0238418) , 
1, 3.38095, 1, 0, 0.30904,-0.0128881) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401518,0.0135991) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.883202,-0.00483138) , 
4, 0.204771, 1, 0, 0.588444,0.0113561) , 
4, 0.0587172, 1, 0, 0.508968,0.00445984)    );
  // itree = 626
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480321,-0.00513484) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.373641,0.0314659) , 
0, 49246, 1, 0, 0.424581,0.0139597) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.585354,0.000322311) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433312,-0.0156507) , 
0, 51634.1, 1, 0, 0.517248,-0.00941688) , 
7, -0.710708, 1, 0, 0.491823,-0.00300295)    );
  // itree = 627
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669599,-0.000840567) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.727706,0.0215925) , 
7, -0.425634, 1, 0, 0.70686,0.0168822) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.213075,0.00665358) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327235,-0.0183864) , 
7, -0.998732, 1, 0, 0.300043,-0.0170378) , 
6, 1.91973, 1, 0, 0.506304,0.000160106)    );
  // itree = 628
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.609757,0.0052662) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.370913,0.0433184) , 
7, 1.57934, 1, 0, 0.585048,0.0123874) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26576,-0.0412375) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281151,-0.0102215) , 
6, 1.38559, 1, 0, 0.278022,-0.0178633) , 
3, 0.047619, 1, 0, 0.497493,0.00376084)    );
  // itree = 629
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541195,-0.0148838) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.919787,0.0157932) , 
4, 0.209962, 1, 0, 0.63131,-0.0117664) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492765,-0.00205542) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323797,0.0212293) , 
6, 2.06709, 1, 0, 0.386209,0.013597) , 
1, 6.28571, 1, 0, 0.509973,0.000789719)    );
  // itree = 630
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.237595,-0.0239989) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.587276,0.00833183) , 
7, -1.47983, 1, 0, 0.536441,0.00594393) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.267659,-0.0499449) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.125596,0.0383701) , 
6, 3.23324, 1, 0, 0.224774,-0.0250641) , 
7, 1.54938, 1, 0, 0.494042,0.00172559)    );
  // itree = 631
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252874,-0.0121785) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384506,0.00901892) , 
2, 69740.8, 1, 0, 0.298976,-0.00548134) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.786438,-0.000522813) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.801817,0.0242362) , 
0, 51635, 1, 0, 0.793708,0.0167946) , 
4, 0.133458, 1, 0, 0.500694,0.00360125)    );
  // itree = 632
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.04158,-0.0118989) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366468,0.0472904) , 
5, 1726.65, 1, 0, 0.143,0.0230368) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.609953,-0.0137709) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479845,0.00524603) , 
8, 0.00796474, 1, 0, 0.549123,-0.00612947) , 
8, -0.0732779, 1, 0, 0.505087,-0.002967)    );
  // itree = 633
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597805,0.0289227) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37208,-0.00764207) , 
0, 47454.6, 1, 0, 0.479077,0.0113761) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423669,0.0141052) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514536,-0.00846159) , 
4, 0.0381896, 1, 0, 0.499117,-0.0060614) , 
7, -0.42608, 1, 0, 0.491776,0.000326508)    );
  // itree = 634
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372074,-0.0208812) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.977414,0.0508848) , 
5, 9028.87, 1, 0, 0.441867,-0.0200227) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499765,0.00515103) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.912582,-0.0860179) , 
4, 0.323865, 1, 0, 0.529646,0.00280227) , 
7, -0.422219, 1, 0, 0.496474,-0.0058235)    );
  // itree = 635
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696793,-0.00421949) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.700681,-0.0830021) , 
0, 78266.1, 1, 0, 0.697087,-0.0101473) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.119119,0.0224504) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.65494,-0.00329017) , 
5, 1907.3, 1, 0, 0.299665,0.0123724) , 
6, 1.90533, 1, 0, 0.506196,0.000669501)    );
  // itree = 636
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.116339,-0.0763541) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.120836,0.0161767) , 
7, 0.426155, 1, 0, 0.11815,-0.0311043) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37015,0.0100515) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.833596,-0.00718799) , 
4, 0.152494, 1, 0, 0.540805,0.00569542) , 
8, -0.0722079, 1, 0, 0.495679,0.0017664)    );
  // itree = 637
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.12306,-0.0363435) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539363,0.00466564) , 
8, -0.0856626, 1, 0, 0.504351,0.0029116) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601837,0.0108991) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.284531,-0.0513245) , 
7, 0.0820452, 1, 0, 0.478311,-0.0251311) , 
1, 13.4286, 1, 0, 0.502443,0.00085693)    );
  // itree = 638
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.950552,0.0141343) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379156,-0.010222) , 
1, 2.09524, 1, 0, 0.481768,-0.00975573) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574595,-0.00706795) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.641113,0.0371341) , 
7, -0.192901, 1, 0, 0.613465,0.0304116) , 
0, 132063, 1, 0, 0.492239,-0.00656199)    );
  // itree = 639
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44231,0.0776936) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.125421,0.0129405) , 
1, 6.2381, 1, 0, 0.250317,0.0481172) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375869,-0.0150099) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574748,0.0128837) , 
4, 0.0397483, 1, 0, 0.540582,0.0115134) , 
7, -1.84267, 1, 0, 0.515981,0.0146156)    );
  // itree = 640
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.621435,0.029167) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.688866,-0.0135842) , 
4, 0.0400274, 1, 0, 0.6757,-0.00712821) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31937,0.0140407) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358588,-0.0278108) , 
1, 15.0952, 1, 0, 0.321763,0.0137837) , 
6, 1.90533, 1, 0, 0.504611,0.00298033)    );
  // itree = 641
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545887,-0.00608053) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323327,0.0189986) , 
0, 39436.6, 1, 0, 0.424066,0.0100871) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.779105,0.00351387) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482962,-0.0246262) , 
1, 9, 1, 0, 0.623482,-0.015996) , 
2, 77144.3, 1, 0, 0.489457,0.00153415)    );
  // itree = 642
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480641,0.00180425) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524415,-0.0501099) , 
0, 145728, 1, 0, 0.482701,-2.14812e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512486,0.0272656) , 
1, 15.0952, 1, 0, 0.484048,0.00207977)    );
  // itree = 643
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512044,-0.0041914) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.429242,0.0231875) , 
1, 11.4762, 1, 0, 0.509198,-0.00366894) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535364,0.00149181) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368692,-0.0572004) , 
7, 0.107685, 1, 0, 0.468176,-0.0315318) , 
1, 12.8095, 1, 0, 0.505019,-0.00650777)    );
  // itree = 644
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.753607,0.00566211) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0889627,-0.0244497) , 
6, 1.11755, 1, 0, 0.289579,-0.0150038) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368898,0.0392277) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72224,0.000678797) , 
4, 0.109982, 1, 0, 0.68368,0.00726457) , 
4, 0.0954539, 1, 0, 0.501406,-0.00303471)    );
  // itree = 645
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470631,0.00333904) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494012,-0.0115012) , 
7, -0.147611, 1, 0, 0.483662,-0.0061898) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.566405,0.061685) , 
1, 16.1905, 1, 0, 0.485799,-0.0033586)    );
  // itree = 646
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.78995,0.0133548) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361334,-0.0111778) , 
1, 5, 1, 0, 0.487905,-0.00631707) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.287028,-0.00189691) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75377,0.0208799) , 
4, 0.114255, 1, 0, 0.520998,0.0125445) , 
7, -0.147611, 1, 0, 0.506445,0.00424955)    );
  // itree = 647
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629042,0.0108384) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102239,-0.0293084) , 
6, 2.62715, 1, 0, 0.568993,0.00854749) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439979,-0.0101535) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.299978,0.0271262) , 
7, 1.2844, 1, 0, 0.412377,-0.00472709) , 
0, 51634.1, 1, 0, 0.49721,0.00246329)    );
  // itree = 648
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516339,-0.00436278) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455117,0.0107794) , 
8, 0.011091, 1, 0, 0.491556,0.00244026) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44231,-0.0372581) , 
1, 16.8571, 1, 0, 0.489931,-0.000124988)    );
  // itree = 649
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551543,-0.0061188) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360854,0.0102287) , 
0, 50343.8, 1, 0, 0.491063,-0.000705685) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496967,0.0350443) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49552,-0.0143787) , 
1, 14.3333, 1, 0, 0.496676,0.0256956) , 
0, 78276.4, 1, 0, 0.492483,0.00597486)    );
  // itree = 650
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.723087,0.000125173) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348404,0.0133795) , 
6, 1.64076, 1, 0, 0.530643,0.00914847) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.139925,-0.0423526) , 
6, 8.44157, 1, 0, 0.518081,0.00750731)    );
  // itree = 651
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399402,0.0254787) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.673923,-0.0225718) , 
2, 97720.7, 1, 0, 0.452892,0.0195797) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559713,-0.00213127) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541663,0.0262438) , 
1, 14.619, 1, 0, 0.558792,-3.97001e-05) , 
7, -0.703854, 1, 0, 0.529889,0.00531486)    );
  // itree = 652
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.275157,-0.0122748) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303009,0.0178131) , 
4, 0.0597365, 1, 0, 0.287369,0.00462357) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.890056,0.0114028) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.640459,-0.0158748) , 
1, 4.52381, 1, 0, 0.717807,-0.014351) , 
4, 0.113913, 1, 0, 0.485891,-0.00412769)    );
  // itree = 653
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400396,0.0223877) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541926,-0.0114315) , 
4, 0.039765, 1, 0, 0.515171,-0.00856448) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281453,-0.0244747) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495232,0.0141346) , 
4, 0.0395567, 1, 0, 0.45602,0.00971184) , 
7, 0.430449, 1, 0, 0.492674,-0.00161353)    );
  // itree = 654
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431229,-0.0254066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53547,-0.00360015) , 
8, -0.00291834, 1, 0, 0.485838,-0.0183218) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.633378,0.0280928) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.461123,-0.00370815) , 
7, 0.308989, 1, 0, 0.501054,0.00556173) , 
7, -0.140011, 1, 0, 0.49439,-0.00489841)    );
  // itree = 655
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.768458,0.0635803) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.223531,-0.011458) , 
0, 39908.4, 1, 0, 0.389068,0.0154028) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528234,-0.00441599) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549823,-0.0202213) , 
1, 14.2857, 1, 0, 0.529531,-0.00754545) , 
4, 0.038281, 1, 0, 0.506602,-0.00379935)    );
  // itree = 656
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453772,0.0130815) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530272,-0.00993927) , 
2, 30860.6, 1, 0, 0.517836,-0.00626357) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.215006,0.0600823) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477968,0.00668834) , 
8, -0.0684185, 1, 0, 0.443818,0.0169734) , 
1, 9.80952, 1, 0, 0.499369,-0.000466247)    );
  // itree = 657
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471282,0.000218771) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.913926,-0.0338782) , 
4, 0.304701, 1, 0, 0.531356,-0.00330548) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0224892,-0.0722512) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.462495,0.054663) , 
5, 1392.44, 1, 0, 0.221612,0.0317568) , 
7, 2.1427, 1, 0, 0.512845,-0.00121006)    );
  // itree = 658
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.606458,-0.000650275) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315727,0.0163857) , 
6, 2.57685, 1, 0, 0.510808,0.00653857) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.143709,-0.0371708) , 
6, 7.545, 1, 0, 0.497403,0.00453268)    );
  // itree = 659
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312037,-0.000592569) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.197423,0.0330756) , 
1, 12.9048, 1, 0, 0.302346,0.00341695) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.61948,-0.023046) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893519,-0.00693372) , 
2, 54347.8, 1, 0, 0.796438,-0.0187614) , 
4, 0.153552, 1, 0, 0.487649,-0.00490078)    );
  // itree = 660
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.898383,0.0148061) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349048,-0.0091601) , 
6, 0.944988, 1, 0, 0.492924,-0.0068614) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.860767,0.0154457) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.706244,0.053815) , 
1, 9.80952, 1, 0, 0.775887,0.0569431) , 
2, 142623, 1, 0, 0.51343,-0.00223772)    );
  // itree = 661
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286639,6.46701e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.462219,0.0177421) , 
4, 0.113652, 1, 0, 0.336053,0.010006) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.917767,-0.0250265) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.890849,0.0198017) , 
1, 11.6667, 1, 0, 0.912442,-0.00962484) , 
5, 4000.23, 1, 0, 0.499797,0.00442915)    );
  // itree = 662
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785998,-0.0129843) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379622,0.00864001) , 
1, 4.33333, 1, 0, 0.50193,0.00291804) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57828,0.0398078) , 
1, 15.6667, 1, 0, 0.504809,0.00579415)    );
  // itree = 663
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445301,0.0107029) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286825,-0.0254591) , 
4, 0.0140211, 1, 0, 0.306446,-0.0190802) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.867034,-0.016772) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486922,0.00622563) , 
1, 3.95238, 1, 0, 0.567168,0.00487649) , 
4, 0.0574647, 1, 0, 0.492394,-0.00199422)    );
  // itree = 664
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366268,0.0205575) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.615559,-0.00367708) , 
4, 0.0589421, 1, 0, 0.543858,0.002265) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389076,-0.0291104) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.220816,0.0108945) , 
6, 3.26876, 1, 0, 0.335379,-0.0206001) , 
8, 0.0257083, 1, 0, 0.484541,-0.00424063)    );
  // itree = 665
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565564,-0.00530493) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288349,0.015332) , 
6, 3.25998, 1, 0, 0.503871,-0.00123049) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404725,-0.0337583) , 
1, 15.0952, 1, 0, 0.500285,-0.00301634)    );
  // itree = 666
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47673,0.0346234) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.125926,-0.00149733) , 
6, 2.84076, 1, 0, 0.342324,0.0290723) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.662513,0.0046302) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.413923,-0.0108476) , 
1, 6.52381, 1, 0, 0.545262,-0.0045299) , 
7, -1.28207, 1, 0, 0.512966,0.000817561)    );
  // itree = 667
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56385,-0.00900571) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302974,0.035085) , 
6, 2.92694, 1, 0, 0.54276,-0.00726157) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440591,0.0249148) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.201055,-0.00329674) , 
6, 4.9295, 1, 0, 0.328903,0.0148305) , 
6, 3.41054, 1, 0, 0.492365,-0.00205561)    );
  // itree = 668
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42457,0.0391519) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.269881,-0.0109247) , 
4, 0.0154036, 1, 0, 0.283254,-0.0075381) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548145,0.0303909) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.708365,0.00257082) , 
7, -1.27395, 1, 0, 0.688268,0.00888924) , 
4, 0.096658, 1, 0, 0.498766,0.00120306)    );
  // itree = 669
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491466,0.0148316) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669376,-0.0169514) , 
8, -0.0195464, 1, 0, 0.619118,-0.00993979) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423916,0.0172636) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.210527,-0.0118899) , 
6, 3.76944, 1, 0, 0.357409,0.0111565) , 
1, 6.33333, 1, 0, 0.490111,0.00045941)    );
  // itree = 670
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877203,0.00343594) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567576,0.0196085) , 
6, 0.982714, 1, 0, 0.798905,0.0120519) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202861,0.0118225) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368373,-0.0120062) , 
8, -0.0374924, 1, 0, 0.330285,-0.0107935) , 
6, 1.27753, 1, 0, 0.49714,-0.00265924)    );
  // itree = 671
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.640002,0.0182171) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.301661,-0.0338415) , 
1, 9.04762, 1, 0, 0.620279,0.0176459) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.427961,-0.0146016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419586,0.0114193) , 
3, 0.047619, 1, 0, 0.424754,-0.00770817) , 
0, 45360.2, 1, 0, 0.518325,0.00442531)    );
  // itree = 672
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.745051,-0.00389461) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.60758,0.0392617) , 
0, 52506.6, 1, 0, 0.71854,0.00756219) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353517,-0.021276) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339633,-0.000814152) , 
3, 0.047619, 1, 0, 0.348074,-0.0192679) , 
1, 5.14286, 1, 0, 0.494655,-0.00865217)    );
  // itree = 673
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364724,0.042798) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0562,-0.0182459) , 
3, 0.047619, 1, 0, 0.222869,0.0297066) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542413,-0.00232887) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.459787,-0.0239494) , 
1, 11.5714, 1, 0, 0.531449,-0.00797798) , 
8, -0.0657895, 1, 0, 0.495223,-0.00355393)    );
  // itree = 674
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474025,0.00687261) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.39032,0.0383952) , 
8, 0.0195619, 1, 0, 0.443496,0.0215831) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592321,-0.0117374) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419662,0.0081189) , 
7, 0.702227, 1, 0, 0.519283,-0.00441566) , 
7, -0.711411, 1, 0, 0.498086,0.00285602)    );
  // itree = 675
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.964096,0.0230939) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422215,-0.0138048) , 
1, 2.19048, 1, 0, 0.605139,-0.0090905) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.072976,-0.0285187) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401815,0.0099495) , 
8, -0.071317, 1, 0, 0.353194,0.0086876) , 
1, 6.33333, 1, 0, 0.478546,-0.000157661)    );
  // itree = 676
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545245,0.00288964) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389661,0.0392333) , 
1, 9.38095, 1, 0, 0.528473,0.00918831) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322058,-0.0203593) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.985576,0.0368125) , 
5, 9034.26, 1, 0, 0.422821,-0.0210018) , 
0, 66682.9, 1, 0, 0.495429,-0.000254157)    );
  // itree = 677
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.408646,-0.027305) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372714,0.00596288) , 
2, 29893.7, 1, 0, 0.394738,-0.0245242) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.111537,-0.0482544) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564296,0.00756205) , 
7, -2.13611, 1, 0, 0.538241,0.00653572) , 
2, 35628.2, 1, 0, 0.511521,0.000752316)    );
  // itree = 678
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327933,-0.00227057) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473632,-0.0393876) , 
2, 122760, 1, 0, 0.338408,-0.00609212) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.870194,0.00435905) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.819992,0.0323479) , 
1, 12.4286, 1, 0, 0.862062,0.0123663) , 
4, 0.190565, 1, 0, 0.492414,-0.000663505)    );
  // itree = 679
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434596,-0.00364995) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.713873,0.0155039) , 
2, 69765.2, 1, 0, 0.539751,0.00275627) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0565488,0.0236175) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375409,0.0371116) , 
5, 693.644, 1, 0, 0.212226,0.0395301) , 
6, 5.6335, 1, 0, 0.51274,0.00578902)    );
  // itree = 680
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448564,-0.0160809) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.678086,0.0123547) , 
7, -0.996429, 1, 0, 0.637539,0.00916544) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.111064,-0.00325339) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721167,-0.0270757) , 
4, 0.152494, 1, 0, 0.355257,-0.0176467) , 
1, 6.52381, 1, 0, 0.500697,-0.00383234)    );
  // itree = 681
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.645328,0.00768584) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334716,-0.00952721) , 
1, 6.14286, 1, 0, 0.524073,0.000785687) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40159,0.0462813) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471179,0.00723442) , 
0, 80187.3, 1, 0, 0.447589,0.0313381) , 
1, 10.6667, 1, 0, 0.509837,0.00647236)    );
  // itree = 682
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333367,0.0117444) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.195044,0.046147) , 
1, 13, 1, 0, 0.321279,0.0162892) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424257,-0.0250553) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.710466,-0.0009718) , 
8, -0.0291948, 1, 0, 0.643237,-0.00925188) , 
4, 0.0955939, 1, 0, 0.498397,0.00223835)    );
  // itree = 683
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292712,-0.00285866) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501348,-0.01976) , 
4, 0.117938, 1, 0, 0.33977,-0.0101137) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.883332,0.0198659) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.790744,-0.016359) , 
1, 13.381, 1, 0, 0.872334,0.0127221) , 
4, 0.19041, 1, 0, 0.496369,-0.00339886)    );
  // itree = 684
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.205608,0.0636388) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381991,-0.0262354) , 
8, -0.0503836, 1, 0, 0.35372,-0.0179512) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53892,0.00244349) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468817,-0.0347301) , 
1, 16.8571, 1, 0, 0.536777,0.00144171) , 
4, 0.0400827, 1, 0, 0.504952,-0.00192983)    );
  // itree = 685
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.227863,0.0110688) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.637115,0.0473088) , 
5, 1744.47, 1, 0, 0.320228,0.0234926) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697715,-0.00489297) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.713964,0.0247926) , 
1, 11.5714, 1, 0, 0.700283,0.00150993) , 
4, 0.096848, 1, 0, 0.519488,0.0119672)    );
  // itree = 686
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.280655,0.00628247) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785847,0.0513182) , 
5, 2606.77, 1, 0, 0.318066,0.0113137) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.623605,-0.00955475) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22601,0.0520078) , 
7, 2.11955, 1, 0, 0.60212,-0.010506) , 
4, 0.076352, 1, 0, 0.494648,-0.00225051)    );
  // itree = 687
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98636,0.0336481) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.148275,-0.0203162) , 
1, 2.52381, 1, 0, 0.386759,-0.0121834) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.467568,0.00757473) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.757973,0.033449) , 
2, 77007.8, 1, 0, 0.559223,0.0193089) , 
4, 0.0382385, 1, 0, 0.53038,0.0140422)    );
  // itree = 688
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264635,-0.0239826) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407712,-0.00140727) , 
7, -0.707306, 1, 0, 0.364895,-0.00902668) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.924937,0.0183954) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.800519,0.0311019) , 
6, 4.30591, 1, 0, 0.907957,0.0236614) , 
4, 0.210414, 1, 0, 0.502537,-0.000741693)    );
  // itree = 689
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522545,0.0015027) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549584,0.0319234) , 
1, 13.3333, 1, 0, 0.524368,0.00502012) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.301891,-0.00272665) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.767914,-0.0381871) , 
4, 0.171529, 1, 0, 0.430817,-0.0140346) , 
7, 0.430151, 1, 0, 0.488385,-0.00230908)    );
  // itree = 690
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433068,-0.0144791) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.949309,0.0207715) , 
4, 0.323769, 1, 0, 0.48988,-0.0141014) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.639649,0.0234179) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383461,-0.0125388) , 
7, 0.81531, 1, 0, 0.487727,0.00473949) , 
7, 0.137299, 1, 0, 0.48886,-0.00517569)    );
  // itree = 691
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514073,0.00541671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54707,0.0424602) , 
0, 108110, 1, 0, 0.516048,0.00927791) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252764,-0.0574672) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518349,-0.00134854) , 
7, -0.996138, 1, 0, 0.453128,-0.0195114) , 
1, 10.3333, 1, 0, 0.504444,0.00396862)    );
  // itree = 692
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494757,0.0210194) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506072,0.00294377) , 
2, 29177.3, 1, 0, 0.504857,0.00725537) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.136569,-0.0162562) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.708131,-0.0359065) , 
5, 2469.02, 1, 0, 0.41427,-0.0432008) , 
1, 14.7143, 1, 0, 0.50005,0.00457778)    );
  // itree = 693
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273729,0.00703207) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298595,-0.0263766) , 
7, -0.140011, 1, 0, 0.28778,-0.0138629) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.698953,0.00741775) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387511,0.0538653) , 
7, 2.12745, 1, 0, 0.682136,0.0140814) , 
4, 0.0950062, 1, 0, 0.505134,0.00153896)    );
  // itree = 694
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.253928,-0.00411277) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564103,-0.0914937) , 
5, 2927.84, 1, 0, 0.276339,-0.0140697) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9008,-0.0212251) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.641048,0.0105167) , 
1, 3.57143, 1, 0, 0.702894,0.00899315) , 
4, 0.0954241, 1, 0, 0.504644,-0.0017258)    );
  // itree = 695
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294737,0.0118206) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.662777,-0.0175058) , 
5, 3039.73, 1, 0, 0.327252,0.0120933) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.81216,-0.026363) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971562,0.0147873) , 
4, 0.221213, 1, 0, 0.912069,-0.00864752) , 
5, 3994.04, 1, 0, 0.495652,0.00612088)    );
  // itree = 696
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.260355,0.0489514) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.462586,0.00202598) , 
8, -0.039666, 1, 0, 0.417491,0.0139921) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.391713,-0.0159743) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.93099,0.016208) , 
4, 0.191158, 1, 0, 0.566314,-0.00972443) , 
2, 54347.8, 1, 0, 0.501849,0.000548751)    );
  // itree = 697
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388515,0.00129732) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983702,0.0405383) , 
5, 6636.94, 1, 0, 0.458143,0.00446929) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.867,-0.0425261) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.993538,0.0200796) , 
5, 10721.2, 1, 0, 0.919525,-0.0257421) , 
4, 0.304778, 1, 0, 0.515566,0.000709192)    );
  // itree = 698
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0971879,-7.837e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511358,-0.0435575) , 
5, 1738.46, 1, 0, 0.264859,-0.0278896) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.753491,0.010576) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350745,-0.00205028) , 
6, 1.49545, 1, 0, 0.524962,0.00394856) , 
7, -1.5581, 1, 0, 0.49332,7.52949e-05)    );
  // itree = 699
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.632591,-0.0114854) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405271,0.0048474) , 
0, 38246.4, 1, 0, 0.486517,-0.000452413) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588327,0.0270532) , 
0, 164307, 1, 0, 0.490707,0.000861477)    );
  // itree = 700
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353875,0.00446179) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0309018,-0.057182) , 
6, 4.34645, 1, 0, 0.307574,-0.000245894) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535298,-0.0424062) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.795181,-0.0121621) , 
8, -0.0447535, 1, 0, 0.756607,-0.0225214) , 
4, 0.13331, 1, 0, 0.492617,-0.00942549)    );
  // itree = 701
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.641328,0.0322028) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.271752,0.00575387) , 
1, 5.95238, 1, 0, 0.39935,0.0216599) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.571816,-0.00264019) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445359,-0.0166577) , 
1, 9.28571, 1, 0, 0.541557,-0.00794261) , 
8, -0.0214898, 1, 0, 0.50175,0.000343781)    );
  // itree = 702
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555853,-0.00302719) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.589915,0.0189208) , 
1, 14.8095, 1, 0, 0.55776,-0.00175431) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.65494,0.0446374) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.168495,-0.00370568) , 
6, 1.50119, 1, 0, 0.33912,0.0167892) , 
7, 1.26558, 1, 0, 0.519866,0.00145953)    );
  // itree = 703
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.637571,-0.0134872) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401776,0.0068999) , 
1, 6.52381, 1, 0, 0.52205,-0.00385902) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.106164,-0.0179602) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308723,-0.053659) , 
4, 0.0756653, 1, 0, 0.21722,-0.0426494) , 
7, 1.57195, 1, 0, 0.481902,-0.00896798)    );
  // itree = 704
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.593195,-0.000371372) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473934,0.0177828) , 
0, 51633.9, 1, 0, 0.537659,0.00995136) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.873963,0.0216675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.276034,-0.0244703) , 
6, 1.00508, 1, 0, 0.440545,-0.017573) , 
8, 0.00815774, 1, 0, 0.496158,-0.00181091)    );
  // itree = 705
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.520552,-0.0130726) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334264,0.010338) , 
0, 39288.9, 1, 0, 0.418672,-0.000339206) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.713687,0.0213549) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.166711,-0.0273466) , 
6, 7.49758, 1, 0, 0.669029,0.0159936) , 
2, 73373.3, 1, 0, 0.507591,0.00546173)    );
  // itree = 706
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617945,0.00284488) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392221,0.0444847) , 
1, 8.14286, 1, 0, 0.593414,0.00875324) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.418191,-0.00549778) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0270256,-0.0666612) , 
7, 2.11615, 1, 0, 0.387796,-0.0104905) , 
0, 45843.4, 1, 0, 0.481515,-0.00171943)    );
  // itree = 707
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559916,0.00340999) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.223905,0.0774316) , 
6, 7.4697, 1, 0, 0.542648,0.00844669) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527223,0.0361684) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354212,-0.000105945) , 
1, 9, 1, 0, 0.472238,0.0309122) , 
8, 0.011091, 1, 0, 0.515306,0.0171704)    );
  // itree = 708
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525425,-0.00398101) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434734,-0.0529366) , 
1, 13.4286, 1, 0, 0.518272,-0.0107336) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530485,0.0211119) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313811,-0.0103509) , 
1, 8.38095, 1, 0, 0.46261,0.0131445) , 
8, 0.00815774, 1, 0, 0.49566,-0.0010335)    );
  // itree = 709
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167339,0.0864949) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320059,-0.00661288) , 
7, -1.83036, 1, 0, 0.303284,-0.00072798) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285428,0.0515985) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.699241,0.0090348) , 
8, -0.068688, 1, 0, 0.657742,0.017224) , 
4, 0.0764862, 1, 0, 0.525319,0.0105173)    );
  // itree = 710
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363913,-0.00828024) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.821374,-0.0306782) , 
4, 0.266158, 1, 0, 0.415745,-0.0148184) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 1,0.0532939) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971745,-0.0253705) , 
7, 0.233827, 1, 0, 0.988242,0.00834938) , 
5, 8344.62, 1, 0, 0.49572,-0.0115819)    );
  // itree = 711
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586761,0.00240188) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.279989,-0.0676366) , 
1, 9.38095, 1, 0, 0.565374,-0.00404843) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.427341,0.0217905) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422851,-0.0027018) , 
8, -0.00653199, 1, 0, 0.424844,0.010606) , 
0, 51633.9, 1, 0, 0.501009,0.00266351)    );
  // itree = 712
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0950211,-0.017055) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569158,-0.0397202) , 
5, 1957.9, 1, 0, 0.264959,-0.0294323) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617523,0.0270401) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52814,-0.000815042) , 
7, -0.66837, 1, 0, 0.542844,0.00538237) , 
7, -1.28207, 1, 0, 0.497808,-0.000259892)    );
  // itree = 713
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22601,-0.0192512) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.702846,-0.0695794) , 
4, 0.245816, 1, 0, 0.291021,-0.0340335) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53596,-0.0036016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.606225,0.043838) , 
1, 14.8095, 1, 0, 0.53995,0.000526967) , 
7, -0.996742, 1, 0, 0.487687,-0.0067291)    );
  // itree = 714
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455996,0.00149722) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305199,0.0394169) , 
0, 49204.1, 1, 0, 0.423174,0.0118568) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362185,-0.0255955) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.60787,0.00371848) , 
8, -0.0244109, 1, 0, 0.540832,-0.00511867) , 
2, 43488.3, 1, 0, 0.504801,7.98017e-05)    );
  // itree = 715
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.226136,-0.00632077) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543421,-0.022406) , 
5, 1744.05, 1, 0, 0.293648,-0.0124364) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.673788,0.00992953) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.888539,-0.040418) , 
4, 0.342218, 1, 0, 0.698764,0.00863639) , 
4, 0.096658, 1, 0, 0.513215,-0.00101526)    );
  // itree = 716
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.116937,0.0219447) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.45874,-0.0135223) , 
7, -2.13859, 1, 0, 0.439114,-0.0158222) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.796488,0.0376871) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.609271,-0.0179032) , 
7, 0.651359, 1, 0, 0.73604,0.0218416) , 
2, 102183, 1, 0, 0.489118,-0.00947931)    );
  // itree = 717
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.256774,-0.00672634) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.748647,-0.0573906) , 
4, 0.247865, 1, 0, 0.344131,-0.0205846) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.600815,0.00869054) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.195959,-0.0224558) , 
6, 4.24829, 1, 0, 0.539289,0.00550673) , 
7, -0.711066, 1, 0, 0.482015,-0.00215041)    );
  // itree = 718
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.117137,0.0539793) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313249,-0.0104348) , 
7, -2.13274, 1, 0, 0.300329,-0.00936317) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.718979,0.0375548) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.807092,0.0042684) , 
7, -0.982979, 1, 0, 0.78847,0.0167948) , 
4, 0.13349, 1, 0, 0.500329,0.00135422)    );
  // itree = 719
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499459,-0.00173282) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486922,-0.0295417) , 
1, 13.6667, 1, 0, 0.49899,-0.00393188) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522279,0.0255494) , 
1, 15.0952, 1, 0, 0.499825,-0.00206785)    );
  // itree = 720
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.415808,0.0264013) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.461717,-0.0100794) , 
4, 0.0311718, 1, 0, 0.45542,-0.0078861) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.930339,0.0329892) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 1,0.0491658) , 
5, 10551.1, 1, 0, 0.959864,0.0290943) , 
4, 0.322894, 1, 0, 0.501974,-0.00447326)    );
  // itree = 721
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498337,0.00625588) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376289,-0.0195286) , 
1, 12, 1, 0, 0.486716,0.0041228) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455082,0.00750769) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674106,0.0407336) , 
8, -0.0147511, 1, 0, 0.596457,0.035859) , 
0, 132062, 1, 0, 0.495065,0.00653725)    );
  // itree = 722
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400489,0.0165909) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31083,-0.0397399) , 
4, 0.0257028, 1, 0, 0.356074,-0.0127182) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.427028,0.0278585) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581673,0.00584888) , 
7, -0.987699, 1, 0, 0.546164,0.0144761) , 
4, 0.0401388, 1, 0, 0.509613,0.0092471)    );
  // itree = 723
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313581,-0.0047525) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.593247,-0.057222) , 
4, 0.163076, 1, 0, 0.331609,-0.0112764) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.908843,0.0262813) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.815543,-0.0116005) , 
1, 8.42857, 1, 0, 0.87264,0.0109745) , 
4, 0.190565, 1, 0, 0.496149,-0.00450939)    );
  // itree = 724
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414457,0.0129024) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.15198,-0.0151642) , 
6, 3.33781, 1, 0, 0.341534,0.00950483) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.981438,0.0103356) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.870238,-0.0268385) , 
1, 5.14286, 1, 0, 0.923103,-0.0135249) , 
5, 4279.33, 1, 0, 0.499312,0.00325693)    );
  // itree = 725
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.300101,0.00563698) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.630213,-0.0166878) , 
4, 0.12681, 1, 0, 0.400248,-0.00340944) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.97706,-0.00355273) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.914507,0.0226544) , 
6, 1.46663, 1, 0, 0.939502,0.0165273) , 
4, 0.266707, 1, 0, 0.495292,0.000104419)    );
  // itree = 726
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349961,-0.0111205) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.879726,0.00555548) , 
4, 0.190565, 1, 0, 0.499017,-0.00841094) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532454,0.0169041) , 
1, 14.3333, 1, 0, 0.500609,-0.00675813)    );
  // itree = 727
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292001,-0.0272016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.151794,0.0423338) , 
1, 12.9048, 1, 0, 0.282436,-0.0213671) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395644,-0.025479) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.66008,0.00910196) , 
7, -1.28138, 1, 0, 0.622271,0.00630963) , 
4, 0.0775898, 1, 0, 0.491447,-0.00434486)    );
  // itree = 728
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.768449,-0.00387295) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.287297,0.0108754) , 
1, 4.52381, 1, 0, 0.444152,0.00886571) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.73142,-0.0602544) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.957042,-0.0106854) , 
2, 41671.1, 1, 0, 0.914864,-0.0218128) , 
4, 0.285298, 1, 0, 0.514136,0.00430454)    );
  // itree = 729
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528862,-0.00719917) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357932,0.0261431) , 
1, 9.38095, 1, 0, 0.50984,-0.00391979) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.490737,0.0359509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453407,-0.00296359) , 
1, 9, 1, 0, 0.467448,0.0131564) , 
0, 66555.7, 1, 0, 0.496194,0.00157729)    );
  // itree = 730
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542614,-0.0089774) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.234276,0.0371523) , 
6, 6.42876, 1, 0, 0.527765,-0.00899631) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608726,0.0209753) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238846,-0.0110321) , 
7, 1.52567, 1, 0, 0.475517,0.014681) , 
7, 0.425863, 1, 0, 0.507211,0.000318309)    );
  // itree = 731
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.609368,0.0167629) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.191335,-0.00542078) , 
0, 37399.1, 1, 0, 0.321809,0.00202896) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.769752,-0.00632671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480738,-0.022479) , 
6, 3.81429, 1, 0, 0.715049,-0.0138818) , 
4, 0.114617, 1, 0, 0.507871,-0.00549924)    );
  // itree = 732
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507175,-0.00581404) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392642,0.018565) , 
1, 10.4286, 1, 0, 0.489376,-0.0022974) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58581,-0.0416261) , 
0, 158175, 1, 0, 0.49424,-0.00461525)    );
  // itree = 733
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516359,0.00123233) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355807,-0.0135005) , 
1, 9.38095, 1, 0, 0.482025,-0.00294321) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.663539,0.0307361) , 
0, 168417, 1, 0, 0.489336,-0.00136798)    );
  // itree = 734
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345734,-0.0132846) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540588,0.00755118) , 
2, 45808.7, 1, 0, 0.470266,-0.00138377) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442035,-0.0544199) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983702,-0.00135051) , 
5, 9977.96, 1, 0, 0.711826,-0.0307142) , 
2, 136599, 1, 0, 0.490026,-0.00378305)    );
  // itree = 735
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.182633,-0.0060563) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.596328,0.0155241) , 
7, -2.01222, 1, 0, 0.553346,0.0173877) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457881,-0.00179805) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337971,-0.0391966) , 
1, 13.5714, 1, 0, 0.448643,-0.00664155) , 
7, 0.428457, 1, 0, 0.513626,0.00827204)    );
  // itree = 736
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281893,-0.00632899) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.713032,-0.149661) , 
4, 0.298602, 1, 0, 0.322602,-0.0211692) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447065,-0.01985) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.587837,0.0081967) , 
7, -0.718608, 1, 0, 0.548401,0.000926462) , 
8, -0.0247164, 1, 0, 0.486229,-0.00515745)    );
  // itree = 737
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.236301,-0.016074) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464061,0.00529435) , 
8, -0.0262084, 1, 0, 0.40084,0.000265039) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.958257,0.0267938) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.924252,0.0524147) , 
1, 12.0476, 1, 0, 0.952519,0.0251276) , 
4, 0.266965, 1, 0, 0.499959,0.00473205)    );
  // itree = 738
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588268,0.00386651) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181293,-0.0362999) , 
8, 0.0704987, 1, 0, 0.545054,0.00102029) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516729,-0.0348861) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294257,-0.00868385) , 
7, 1.2589, 1, 0, 0.38725,-0.027477) , 
7, 0.715456, 1, 0, 0.497576,-0.00755365)    );
  // itree = 739
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965649,-0.01312) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.713765,0.0244611) , 
6, 1.23946, 1, 0, 0.898113,0.0114317) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400331,-0.00979681) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.160482,0.0188244) , 
8, 0.0729065, 1, 0, 0.365795,-0.00933415) , 
1, 3.95238, 1, 0, 0.496749,-0.0042256)    );
  // itree = 740
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439812,0.0217124) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.708941,0.0026325) , 
4, 0.0952393, 1, 0, 0.587699,0.0153229) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.157606,0.0148951) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380632,-0.0227086) , 
2, 52090.2, 1, 0, 0.294629,-0.00922059) , 
3, 0.047619, 1, 0, 0.505389,0.00842981)    );
  // itree = 741
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559478,0.00937663) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.59217,0.0305984) , 
1, 15.0952, 1, 0, 0.560675,0.0135518) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343772,0.0228545) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0780615,-0.0471067) , 
8, 0.0895378, 1, 0, 0.13308,-0.0172633) , 
8, 0.0694011, 1, 0, 0.509038,0.00983051)    );
  // itree = 742
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309741,-0.0037465) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.60479,-0.0672234) , 
5, 1362.61, 1, 0, 0.351927,-0.0164959) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524795,-0.000155138) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58325,0.0132901) , 
0, 78532.1, 1, 0, 0.538523,0.00413638) , 
4, 0.0384701, 1, 0, 0.50455,0.000379849)    );
  // itree = 743
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.267435,-7.59475e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613165,-0.019038) , 
4, 0.0777883, 1, 0, 0.4749,-0.016711) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505379,0.00178403) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.317818,0.041581) , 
6, 6.48872, 1, 0, 0.492368,0.00595354) , 
7, 0.141135, 1, 0, 0.48279,-0.00647352)    );
  // itree = 744
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0724894,-0.0778829) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447998,-0.0023516) , 
7, -2.4234, 1, 0, 0.432381,-0.00521729) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.926636,0.0541161) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.924252,-0.0118879) , 
2, 70350.6, 1, 0, 0.92532,0.026018) , 
4, 0.304727, 1, 0, 0.487772,-0.00170743)    );
  // itree = 745
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.97034,0.0242407) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4234,-0.00982852) , 
1, 2.47619, 1, 0, 0.523038,-0.00791356) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.206805,-0.00218237) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.844555,0.0410704) , 
5, 2545.96, 1, 0, 0.427455,0.0167934) , 
7, 0.715243, 1, 0, 0.493906,-0.000383238)    );
  // itree = 746
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539794,0.019324) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233742,-0.0260651) , 
8, 0.0422374, 1, 0, 0.482063,0.0157375) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329797,0.00966717) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.618948,-0.00982511) , 
4, 0.0776231, 1, 0, 0.507563,-0.00389805) , 
7, -0.418703, 1, 0, 0.497829,0.00359755)    );
  // itree = 747
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570849,-0.0120426) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292846,0.0475308) , 
8, 0.0813014, 1, 0, 0.552636,-0.0122232) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289428,0.0178773) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359546,-0.0289236) , 
1, 13.7143, 1, 0, 0.298241,0.0101753) , 
3, 0.047619, 1, 0, 0.47831,-0.005679)    );
  // itree = 748
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0285143,-0.00975692) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292846,-0.0369682) , 
5, 2128.97, 1, 0, 0.102608,-0.0198781) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.633094,-0.00247919) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.377241,0.0129528) , 
6, 2.65494, 1, 0, 0.550174,0.00315117) , 
8, -0.0841036, 1, 0, 0.509747,0.00107103)    );
  // itree = 749
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.176526,0.0692762) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262473,-0.0289546) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546676,0.00250918) , 
7, -1.38348, 1, 0, 0.516063,-0.000480441) , 
7, -2.41783, 1, 0, 0.504845,0.00137088)    );
  // itree = 750
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48544,-0.00391722) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.682161,0.0305855) , 
0, 182044, 1, 0, 0.490737,-0.00357752) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.412691,-0.0229593) , 
1, 16.8571, 1, 0, 0.488734,-0.00445539)    );
  // itree = 751
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505379,-0.0177322) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.790141,0.00496603) , 
4, 0.115794, 1, 0, 0.632771,-0.00986107) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203992,0.00967147) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.834678,-0.0254023) , 
4, 0.2283, 1, 0, 0.361076,0.00241167) , 
1, 6.33333, 1, 0, 0.501806,-0.00394524)    );
  // itree = 752
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.192029,0.00907288) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.834004,0.0449367) , 
4, 0.21142, 1, 0, 0.316217,0.0239745) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.18037,0.0217918) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563198,-0.00619684) , 
8, -0.0724959, 1, 0, 0.524851,-0.00496502) , 
7, -1.27212, 1, 0, 0.488646,5.70069e-05)    );
  // itree = 753
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315426,0.000303945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.77892,-0.0294249) , 
4, 0.191862, 1, 0, 0.435625,-0.00955081) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.678708,0.0232553) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48222,-0.00279715) , 
7, 0.227309, 1, 0, 0.542847,0.00727909) , 
7, -0.42536, 1, 0, 0.503772,0.00114582)    );
  // itree = 754
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579153,-0.00503443) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.416802,0.00930942) , 
0, 45778.7, 1, 0, 0.495429,0.0029573) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466957,-0.0226704) , 
1, 15.0952, 1, 0, 0.49407,0.00113258)    );
  // itree = 755
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.770977,-0.00508472) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32515,-0.0454639) , 
8, 0.0600358, 1, 0, 0.728291,-0.0113352) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302571,0.011666) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383365,-0.0143638) , 
1, 11.6667, 1, 0, 0.316892,0.00744778) , 
6, 1.43967, 1, 0, 0.482411,-0.000109204)    );
  // itree = 756
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315027,0.0404503) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.141506,0.0245412) , 
6, 2.36477, 1, 0, 0.221612,0.0348276) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328983,-0.00538908) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.832052,0.00785698) , 
4, 0.153302, 1, 0, 0.517497,-0.000935459) , 
7, -2.13389, 1, 0, 0.501153,0.0010401)    );
  // itree = 757
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437486,-0.0225283) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536459,0.0115891) , 
4, 0.0208184, 1, 0, 0.530111,0.0112567) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502125,-0.0242572) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238727,0.00795629) , 
6, 4.10613, 1, 0, 0.406109,-0.0177015) , 
1, 9.85714, 1, 0, 0.499471,0.0041013)    );
  // itree = 758
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40902,-0.00889404) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.631223,0.00485513) , 
2, 63877.3, 1, 0, 0.513256,-0.00363472) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.251523,0.0691289) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.144776,0.00893015) , 
7, 2.55691, 1, 0, 0.196553,0.0448743) , 
7, 2.14278, 1, 0, 0.495823,-0.000964519)    );
  // itree = 759
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474025,0.0132482) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.671774,-0.000228494) , 
2, 59407.8, 1, 0, 0.574031,0.0094035) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289985,-0.0145737) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.982909,0.0369026) , 
5, 7298.87, 1, 0, 0.384354,-0.0120776) , 
8, 0.0224951, 1, 0, 0.519666,0.00324659)    );
  // itree = 760
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522129,-0.000201505) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359803,-0.0328338) , 
1, 10.7143, 1, 0, 0.505902,-0.00473969) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522416,0.0249343) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.618272,-0.0190185) , 
0, 173383, 1, 0, 0.541398,0.0204286) , 
0, 86083.7, 1, 0, 0.512942,0.000251617)    );
  // itree = 761
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.299259,-0.0483634) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.657363,-0.00190019) , 
7, -1.54639, 1, 0, 0.621924,-0.00752017) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.204769,0.0193687) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.896615,-0.00718676) , 
5, 4515.25, 1, 0, 0.383998,0.0162081) , 
1, 6.90476, 1, 0, 0.504713,0.0041692)    );
  // itree = 762
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.141081,0.0538657) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515029,-0.000329222) , 
7, -2.41328, 1, 0, 0.499903,0.00126263) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399152,-0.0398645) , 
1, 14.2857, 1, 0, 0.495407,-0.00164188)    );
  // itree = 763
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.250908,0.0523654) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0910054,0.00746254) , 
1, 7.28571, 1, 0, 0.167047,0.0369926) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348762,-0.00755211) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.847585,0.0095719) , 
4, 0.171224, 1, 0, 0.522888,-0.00286744) , 
7, -2.13274, 1, 0, 0.500873,-0.000401371)    );
  // itree = 764
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541342,0.00289822) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419429,0.0169961) , 
1, 9.57143, 1, 0, 0.518543,0.00677249) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590326,0.00554914) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298214,-0.0421569) , 
7, 0.0933072, 1, 0, 0.46066,-0.0287316) , 
1, 13.3333, 1, 0, 0.514606,0.00435781)    );
  // itree = 765
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502463,0.0237402) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525948,-0.00194186) , 
2, 26142, 1, 0, 0.523734,0.00200834) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381519,0.0329295) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46922,-0.00713732) , 
0, 78623.2, 1, 0, 0.431565,0.0166221) , 
1, 9.80952, 1, 0, 0.501388,0.00555138)    );
  // itree = 766
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470717,0.011161) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57278,-0.0100964) , 
8, -0.0141347, 1, 0, 0.538905,-0.00370417) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382585,0.0558954) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.140887,0.00206721) , 
7, 2.18536, 1, 0, 0.245019,0.0275401) , 
7, 1.85733, 1, 0, 0.514369,-0.00109569)    );
  // itree = 767
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614096,0.00490101) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28317,-0.0167523) , 
6, 2.59248, 1, 0, 0.509926,-0.00237707) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0572596,0.0308874) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539268,0.0520862) , 
4, 0.0969162, 1, 0, 0.296096,0.0666652) , 
6, 6.75493, 1, 0, 0.498664,0.00125934)    );
  // itree = 768
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.631558,0.00393387) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.324526,-0.0115771) , 
1, 6.2381, 1, 0, 0.502799,-0.00318824) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498094,-0.00202224) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372714,0.0434468) , 
7, 0.705902, 1, 0, 0.462635,0.0191486) , 
1, 11.5714, 1, 0, 0.49776,-0.000385902)    );
  // itree = 769
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.625862,0.00341798) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.398633,-0.0138673) , 
0, 40708.8, 1, 0, 0.502504,-0.00677004) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.282436,-0.0391183) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.89009,0.0268672) , 
4, 0.303426, 1, 0, 0.411913,-0.0374723) , 
1, 11.5714, 1, 0, 0.490959,-0.0106828)    );
  // itree = 770
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517089,-0.0031617) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.219609,-0.0281059) , 
7, 1.57208, 1, 0, 0.480366,-0.00647382) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563008,0.00769396) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420931,0.0540755) , 
7, 0.712333, 1, 0, 0.525532,0.0251616) , 
1, 13, 1, 0, 0.485004,-0.00322476)    );
  // itree = 771
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.838041,-0.00550266) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578563,0.0257607) , 
6, 1.1144, 1, 0, 0.796927,0.00325547) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337059,-0.0147999) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.282578,-0.00521741) , 
3, 0.047619, 1, 0, 0.316809,-0.0165748) , 
6, 1.29156, 1, 0, 0.486764,-0.0095551)    );
  // itree = 772
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346043,0.0337627) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546015,0.00742562) , 
7, -1.27748, 1, 0, 0.514995,0.0144548) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0982308,-0.0506269) , 
6, 7.49758, 1, 0, 0.4976,0.0118959)    );
  // itree = 773
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.267464,0.0283282) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591242,-0.00834576) , 
8, -0.0654124, 1, 0, 0.565121,-0.00820269) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.373837,0.015813) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.139925,-0.0216157) , 
7, 1.29198, 1, 0, 0.31903,0.0103055) , 
3, 0.047619, 1, 0, 0.493883,-0.00284497)    );
  // itree = 774
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.615323,0.00191998) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426451,0.0327803) , 
8, 0.0353107, 1, 0, 0.579649,0.0101188) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.1162,-0.0245836) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.93099,0.030114) , 
5, 4429.5, 1, 0, 0.295758,-0.0141625) , 
3, 0.047619, 1, 0, 0.501079,0.0033987)    );
  // itree = 775
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.848372,0.0497113) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312965,0.00366464) , 
6, 1.37854, 1, 0, 0.446065,0.0232822) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509881,-0.00544962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983549,0.0621372) , 
4, 0.36148, 1, 0, 0.533548,-0.00463734) , 
2, 36367.4, 1, 0, 0.516008,0.000960246)    );
  // itree = 776
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281685,-0.00968687) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57484,-0.0223706) , 
4, 0.130371, 1, 0, 0.354067,-0.0178113) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.928839,0.00190312) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.872334,0.0278723) , 
1, 12.8095, 1, 0, 0.918864,0.0088255) , 
4, 0.228416, 1, 0, 0.483502,-0.0117069)    );
  // itree = 777
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68779,-0.0376071) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.159041,-0.0014596) , 
1, 3.14286, 1, 0, 0.355905,-0.0254845) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262902,-0.00587875) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.763713,0.00785541) , 
4, 0.114489, 1, 0, 0.496376,0.0009764) , 
2, 34417, 1, 0, 0.472195,-0.0035786)    );
  // itree = 778
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522679,-0.00513575) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.417961,0.0112925) , 
7, 0.715824, 1, 0, 0.491803,-0.000526278) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545199,0.0281841) , 
1, 16.8571, 1, 0, 0.493244,0.000810001)    );
  // itree = 779
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.131826,-0.0628132) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0551788,0.0205251) , 
3, 0.047619, 1, 0, 0.0978472,-0.0375919) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414727,0.0465818) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532454,0.00210033) , 
7, -1.61461, 1, 0, 0.526275,0.0056312) , 
7, -2.13274, 1, 0, 0.500673,0.00304823)    );
  // itree = 780
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532661,-0.00697406) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.621924,0.0209067) , 
1, 14.2857, 1, 0, 0.537353,-0.00615882) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350633,0.0509944) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0660617,-0.0368129) , 
3, 0.047619, 1, 0, 0.210879,0.0229401) , 
8, 0.0702666, 1, 0, 0.5,-0.00282948)    );
  // itree = 781
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.207677,0.0323353) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545455,-0.00441837) , 
7, -2.13759, 1, 0, 0.526414,-0.00330337) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0117237,-0.0291769) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471251,0.0445909) , 
4, 0.0948358, 1, 0, 0.228833,0.0407329) , 
6, 6.75493, 1, 0, 0.50818,-0.000605127)    );
  // itree = 782
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545014,0.000166007) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40821,-0.0190939) , 
1, 9.80952, 1, 0, 0.511637,-0.00576372) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.160711,0.0830148) , 
7, 2.4209, 1, 0, 0.496148,-0.00331587)    );
  // itree = 783
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.413402,0.0117439) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.131176,-0.0123206) , 
8, 0.0651893, 1, 0, 0.374504,0.013397) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.715148,-0.0255719) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.901622,-0.00501659) , 
4, 0.236831, 1, 0, 0.865384,-0.0121898) , 
4, 0.2096, 1, 0, 0.504584,0.00661666)    );
  // itree = 784
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.169445,-0.0309981) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.628972,0.00123741) , 
8, -0.0519114, 1, 0, 0.530425,-0.00425564) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26418,0.0296245) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.740062,-0.00244863) , 
4, 0.190269, 1, 0, 0.385205,0.0238122) , 
8, 0.0227751, 1, 0, 0.486598,0.00421514)    );
  // itree = 785
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.610118,0.00334536) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357683,-0.0175015) , 
0, 45467.4, 1, 0, 0.499393,-0.00778869) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.127144,-0.00454622) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.853243,0.0298456) , 
4, 0.134332, 1, 0, 0.53946,0.0164131) , 
0, 96705.6, 1, 0, 0.505417,-0.00414998)    );
  // itree = 786
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.234184,-0.00790773) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351267,0.0259373) , 
7, -0.711411, 1, 0, 0.316581,0.0196165) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506614,-0.00928801) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918022,0.011948) , 
4, 0.240113, 1, 0, 0.671077,-0.00499562) , 
4, 0.0952474, 1, 0, 0.506488,0.00643152)    );
  // itree = 787
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468535,0.0217536) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349712,-0.0117267) , 
0, 87553.1, 1, 0, 0.444159,0.018604) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602928,-0.0247643) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502778,-0.00136084) , 
7, -0.0987526, 1, 0, 0.51804,-0.00568918) , 
7, -0.42536, 1, 0, 0.491128,0.00315976)    );
  // itree = 788
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577768,-0.00660975) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357772,0.00891349) , 
3, 0.047619, 1, 0, 0.514286,-0.00367111) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.152409,0.0687877) , 
7, 2.4301, 1, 0, 0.501209,-0.00192264)    );
  // itree = 789
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.698547,0.00300711) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346765,0.0176235) , 
6, 1.91844, 1, 0, 0.534502,0.0126893) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.189211,-0.0120967) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.158141,-0.0667146) , 
8, 0.0130141, 1, 0, 0.175737,-0.0345032) , 
7, 1.85667, 1, 0, 0.503999,0.00867694)    );
  // itree = 790
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235832,0.052231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356106,-0.00247532) , 
8, -0.0141978, 1, 0, 0.309422,0.0143308) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549215,0.00749432) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577657,-0.0116905) , 
7, -0.426426, 1, 0, 0.567371,-0.00594833) , 
4, 0.0572325, 1, 0, 0.493374,-0.000130922)    );
  // itree = 791
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468782,0.00981596) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.922826,-0.0148076) , 
4, 0.285715, 1, 0, 0.542455,0.00893377) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295077,-0.00978177) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.992151,0.037033) , 
5, 6486.57, 1, 0, 0.392171,-0.00874589) , 
7, 0.715824, 1, 0, 0.496494,0.0035269)    );
  // itree = 792
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583329,0.0118425) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.250588,-0.026688) , 
7, 1.57208, 1, 0, 0.544979,0.011134) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0354346,0.0260859) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328917,-0.0464817) , 
4, 0.109586, 1, 0, 0.159526,-0.0259716) , 
6, 5.24505, 1, 0, 0.509197,0.00768943)    );
  // itree = 793
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329252,-0.0499613) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.127402,-0.0102658) , 
6, 2.20753, 1, 0, 0.226653,-0.0390467) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53806,-0.00402863) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526038,0.0212135) , 
1, 10.6667, 1, 0, 0.535905,0.00139357) , 
7, -1.56257, 1, 0, 0.501145,-0.00315192)    );
  // itree = 794
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524405,-0.00563716) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512802,-0.0293116) , 
1, 13.381, 1, 0, 0.523853,-0.00909818) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163774,0.000592284) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333104,0.051083) , 
1, 13.3333, 1, 0, 0.216745,0.0260556) , 
6, 5.6335, 1, 0, 0.496969,-0.00602083)    );
  // itree = 795
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.34431,0.0133728) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.80108,-0.00300785) , 
4, 0.152324, 1, 0, 0.508058,0.00941386) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55404,-0.0635979) , 
0, 184796, 1, 0, 0.509569,0.00684469)    );
  // itree = 796
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.39753,-0.00547321) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.915048,0.0172057) , 
4, 0.21003, 1, 0, 0.535983,-0.000936219) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.51234,0.0163582) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.232945,-0.00397276) , 
3, 0.047619, 1, 0, 0.414693,0.0140584) , 
7, 0.715824, 1, 0, 0.499875,0.00352767)    );
  // itree = 797
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360026,0.00578181) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0211656,-0.0594104) , 
8, 0.113961, 1, 0, 0.332405,0.00469503) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.748241,0.0326146) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.840732,0.0113318) , 
7, -1.21006, 1, 0, 0.82776,0.0186158) , 
4, 0.15239, 1, 0, 0.515504,0.00984062)    );
  // itree = 798
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319552,-0.00785727) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480996,-0.0385287) , 
7, -1.14864, 1, 0, 0.372641,-0.0238228) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601531,0.00398605) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262473,-0.0260522) , 
8, 0.044633, 1, 0, 0.542026,-0.000373713) , 
7, -0.714861, 1, 0, 0.495221,-0.00685329)    );
  // itree = 799
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.290892,-0.0169045) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.799434,0.00344896) , 
4, 0.134421, 1, 0, 0.512095,-0.00935093) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583433,0.002931) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360254,0.0280531) , 
1, 6.90476, 1, 0, 0.474678,0.021375) , 
7, 0.430449, 1, 0, 0.497699,0.00247062)    );
  // itree = 800
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411645,0.00960517) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243117,-0.0310092) , 
1, 14.3333, 1, 0, 0.404029,0.00926786) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.922242,-0.000392986) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.724371,-0.0439688) , 
6, 3.48926, 1, 0, 0.880378,-0.0150315) , 
4, 0.228381, 1, 0, 0.512052,0.00375742)    );
  // itree = 801
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.291359,-0.0132044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.737423,0.00518477) , 
4, 0.114448, 1, 0, 0.494357,-0.00468224) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294423,0.0297886) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.797507,-0.00807233) , 
4, 0.222286, 1, 0, 0.490444,0.0287467) , 
1, 12.0476, 1, 0, 0.493962,-0.00131022)    );
  // itree = 802
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203971,0.0539272) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.178913,0.0174144) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552929,-0.00485479) , 
8, -0.068688, 1, 0, 0.509597,-0.00387721) , 
7, -2.40631, 1, 0, 0.499401,-0.00194022)    );
  // itree = 803
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368633,0.0166362) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536182,-0.0080736) , 
7, -0.988291, 1, 0, 0.500244,-0.00389587) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584508,0.0456636) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504693,0.0141528) , 
1, 16.3333, 1, 0, 0.545887,0.0516958) , 
1, 14.3333, 1, 0, 0.502603,-0.00102293)    );
  // itree = 804
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.759978,-0.0126322) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351679,0.00893733) , 
6, 1.32862, 1, 0, 0.51244,0.00188695) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0786908,-0.057785) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.201962,-0.00980034) , 
7, 0.369167, 1, 0, 0.137393,-0.037859) , 
6, 6.76606, 1, 0, 0.49143,-0.000339584)    );
  // itree = 805
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68249,0.0137068) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.141666,-0.0422438) , 
8, 0.102421, 1, 0, 0.654688,0.0134245) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273006,-0.0222774) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.412936,-0.000751312) , 
1, 9.09524, 1, 0, 0.342297,-0.0149699) , 
1, 6.33333, 1, 0, 0.500689,-0.000573111)    );
  // itree = 806
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.377459,0.0115071) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.628617,-0.00150546) , 
7, -0.902079, 1, 0, 0.551718,0.00274243) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.249815,-0.0264904) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.866258,0.0401777) , 
4, 0.229032, 1, 0, 0.352696,-0.0187753) , 
7, 1.00057, 1, 0, 0.503897,-0.00242788)    );
  // itree = 807
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537053,0.00792489) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.246459,-0.0178682) , 
7, 1.56597, 1, 0, 0.499019,0.00675044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.716045,0.0581918) , 
0, 182036, 1, 0, 0.506085,0.00839029)    );
  // itree = 808
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547913,-0.0174065) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28578,0.00775016) , 
3, 0.047619, 1, 0, 0.469124,-0.0133713) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350293,0.0236282) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.635546,0.00246518) , 
4, 0.0783354, 1, 0, 0.528045,0.0124529) , 
7, -0.137132, 1, 0, 0.501579,0.000853132)    );
  // itree = 809
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.847624,-0.0149311) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.170515,0.0206161) , 
1, 3.57143, 1, 0, 0.34969,0.0158034) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584508,-0.0355706) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827855,-0.00383849) , 
4, 0.164445, 1, 0, 0.81055,-0.0088612) , 
4, 0.152494, 1, 0, 0.521581,0.00660406)    );
  // itree = 810
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0424848,0.00043801) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.144776,-0.0661008) , 
4, 0.0746447, 1, 0, 0.0955027,-0.0469087) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511559,-0.00255099) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537862,0.016594) , 
1, 13.3333, 1, 0, 0.513394,-0.000734623) , 
7, -2.13807, 1, 0, 0.49005,-0.00331397)    );
  // itree = 811
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374897,-0.00565564) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.650825,0.0178439) , 
7, -0.903636, 1, 0, 0.514258,0.00827746) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49572,-0.0118186) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387511,-0.0362169) , 
1, 11.3333, 1, 0, 0.483039,-0.0193584) , 
7, 0.145073, 1, 0, 0.499991,-0.00435225)    );
  // itree = 812
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613174,0.0059493) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.241494,0.0418617) , 
6, 5.6335, 1, 0, 0.592149,0.0104956) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0358638,-0.0341532) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.490631,0.00394606) , 
4, 0.0981989, 1, 0, 0.265246,-0.00888309) , 
3, 0.047619, 1, 0, 0.501398,0.00511593)    );
  // itree = 813
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.417316,-0.00536071) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.883226,-0.0508322) , 
4, 0.247208, 1, 0, 0.498514,-0.0124715) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489323,0.00481579) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375075,0.0411643) , 
7, 0.658282, 1, 0, 0.455699,0.0261632) , 
1, 11.5714, 1, 0, 0.492785,-0.00730135)    );
  // itree = 814
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.648771,0.00990284) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244485,-0.0168378) , 
1, 6.14286, 1, 0, 0.593481,0.00758233) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32876,-0.0139994) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522958,0.0158198) , 
1, 13.4286, 1, 0, 0.364611,-0.00945565) , 
1, 7.19048, 1, 0, 0.500358,0.000649905)    );
  // itree = 815
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.585244,-0.00173908) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432303,-0.0278173) , 
0, 92302.5, 1, 0, 0.564028,-0.00743991) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.183751,-0.0208877) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.386392,0.0299342) , 
1, 8, 1, 0, 0.312785,0.0158567) , 
3, 0.047619, 1, 0, 0.490617,-0.000632842)    );
  // itree = 816
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.467601,-0.0047105) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.821456,0.0589199) , 
2, 147920, 1, 0, 0.485612,-0.00368959) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.755955,0.0443525) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323551,0.0152176) , 
6, 4.26483, 1, 0, 0.574723,0.0508188) , 
1, 14.8095, 1, 0, 0.490981,-0.000405616)    );
  // itree = 817
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319724,-0.0194534) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339318,-0.0617404) , 
7, -0.0462708, 1, 0, 0.328632,-0.0435787) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50761,-0.00424715) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.553361,0.0185574) , 
1, 13.4286, 1, 0, 0.510892,-0.00222484) , 
4, 0.0192455, 1, 0, 0.500609,-0.00455799)    );
  // itree = 818
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.571262,0.0216685) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549169,-0.000467016) , 
7, -0.154408, 1, 0, 0.55908,0.0121124) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534368,-0.0242022) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.29666,0.0111773) , 
6, 3.94447, 1, 0, 0.426685,-0.0101376) , 
0, 65731, 1, 0, 0.515603,0.00480576)    );
  // itree = 819
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570104,-0.00631566) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424773,0.00922292) , 
0, 51649.1, 1, 0, 0.505728,0.0011179) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591739,0.0569324) , 
1, 16.1905, 1, 0, 0.508085,0.00396634)    );
  // itree = 820
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0752255,-0.0570875) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526455,0.000471865) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.145901,-0.0436133) , 
6, 7.49758, 1, 0, 0.514306,-0.000896936) , 
7, -2.39863, 1, 0, 0.498999,-0.00237704)    );
  // itree = 821
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.12521,-0.00892559) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.615603,-0.0348473) , 
4, 0.167306, 1, 0, 0.264807,-0.0173392) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547348,0.00348524) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48794,-0.0335913) , 
1, 15.0952, 1, 0, 0.545033,0.00242758) , 
8, -0.0380049, 1, 0, 0.491119,-0.00137545)    );
  // itree = 822
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563959,0.00968792) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521303,-0.00856802) , 
1, 11.3333, 1, 0, 0.558327,0.00859883) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25616,-0.025543) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.342368,0.0207384) , 
1, 10.3333, 1, 0, 0.27268,-0.0131636) , 
7, 1.28591, 1, 0, 0.506924,0.00468265)    );
  // itree = 823
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629862,0.00922908) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.218547,-0.019316) , 
3, 0.047619, 1, 0, 0.533103,0.00549347) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.226572,-0.0330046) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.880986,-0.0112628) , 
4, 0.248307, 1, 0, 0.445147,-0.0340742) , 
1, 10.6667, 1, 0, 0.515763,-0.00230705)    );
  // itree = 824
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.781139,-0.0183573) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355174,-0.0012725) , 
1, 4.33333, 1, 0, 0.503399,-0.00792684) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.467998,-0.0443531) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292846,0.0146699) , 
6, 5.95859, 1, 0, 0.422889,-0.0401338) , 
1, 11.3333, 1, 0, 0.491939,-0.0125115)    );
  // itree = 825
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496072,-0.0357914) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572612,-0.00116203) , 
4, 0.0194822, 1, 0, 0.567813,-0.00382218) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35403,0.0406138) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400906,0.00179793) , 
0, 47526.6, 1, 0, 0.391155,0.0138354) , 
1, 7.66667, 1, 0, 0.499023,0.00305358)    );
  // itree = 826
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49757,0.00653372) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.959864,-0.0687971) , 
5, 8830.21, 1, 0, 0.560989,0.005) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340669,0.0893188) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0450455,-0.0224934) , 
3, 0.047619, 1, 0, 0.187145,0.0404293) , 
8, 0.0702666, 1, 0, 0.519425,0.00893902)    );
  // itree = 827
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540876,0.000726367) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.211331,0.0215642) , 
8, 0.0732838, 1, 0, 0.502176,0.00338709) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.589675,0.0245479) , 
1, 15.7619, 1, 0, 0.505123,0.0047949)    );
  // itree = 828
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599616,-0.0020479) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492359,0.0145182) , 
1, 7.57143, 1, 0, 0.55829,0.00645111) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46906,-0.0276594) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.170886,-0.000413916) , 
8, 0.0630023, 1, 0, 0.353523,-0.0247278) , 
8, 0.0181209, 1, 0, 0.489346,-0.00404672)    );
  // itree = 829
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442751,0.0307278) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.342706,-0.00356781) , 
4, 0.0312764, 1, 0, 0.418082,0.0217734) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529969,-0.000735006) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.187307,-0.0370615) , 
6, 6.79155, 1, 0, 0.515576,-0.00282461) , 
4, 0.0385261, 1, 0, 0.498781,0.00141275)    );
  // itree = 830
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503757,0.00621227) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.249575,0.0412291) , 
6, 4.30711, 1, 0, 0.470004,0.0129688) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319598,-0.0157033) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.960681,0.0171136) , 
5, 4172.28, 1, 0, 0.505663,-0.0133142) , 
7, -0.425618, 1, 0, 0.492456,-0.00358006)    );
  // itree = 831
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203844,-0.0139498) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.39486,0.0147921) , 
7, -0.99003, 1, 0, 0.348786,0.0147285) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.849477,-0.0334207) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.948783,-0.00583945) , 
4, 0.217886, 1, 0, 0.915226,-0.0141077) , 
5, 4174.7, 1, 0, 0.510013,0.00652077)    );
  // itree = 832
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550626,0.0201668) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.780997,-0.000547138) , 
2, 36298.2, 1, 0, 0.710605,0.0105963) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326032,-0.0130639) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.478735,0.0152695) , 
1, 12.1905, 1, 0, 0.351169,-0.00874721) , 
1, 5.42857, 1, 0, 0.491039,-0.00121995)    );
  // itree = 833
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500124,-0.0080833) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.839595,0.0230104) , 
2, 115107, 1, 0, 0.545066,-0.00617015) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.205833,0.0295344) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.632401,-0.0134102) , 
4, 0.168344, 1, 0, 0.316457,0.0166181) , 
7, 1.28606, 1, 0, 0.506752,-0.00235094)    );
  // itree = 834
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965324,0.002494) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484702,-0.0157664) , 
1, 2.14286, 1, 0, 0.696675,-0.0131346) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381266,0.0121716) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247928,-0.00697372) , 
7, 0.72653, 1, 0, 0.340863,0.00822347) , 
1, 5.14286, 1, 0, 0.479936,-0.000124619)    );
  // itree = 835
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247252,0.0196271) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586991,-0.00280834) , 
5, 1775.92, 1, 0, 0.349794,0.0144438) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76752,-0.0321748) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.853528,0.00728912) , 
7, -0.136418, 1, 0, 0.815037,-0.0144972) , 
4, 0.171529, 1, 0, 0.499502,0.00513096)    );
  // itree = 836
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.386662,0.022447) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664381,0.000776625) , 
4, 0.0779317, 1, 0, 0.551428,0.0105802) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.158861,-0.0292848) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.904516,0.0148504) , 
5, 4468.99, 1, 0, 0.400596,-0.0229611) , 
1, 9.85714, 1, 0, 0.515159,0.00251481)    );
  // itree = 837
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546877,0.00249031) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694904,0.0364336) , 
1, 15.6667, 1, 0, 0.55188,0.00528605) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.171063,-0.0484391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.237552,-0.00368214) , 
7, -0.428796, 1, 0, 0.211446,-0.0191592) , 
8, 0.0543204, 1, 0, 0.499571,0.00152996)    );
  // itree = 838
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592511,-0.00640763) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346795,0.0134315) , 
1, 7.66667, 1, 0, 0.513302,9.90873e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.101631,-0.0419886) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.839525,-0.000548681) , 
4, 0.134374, 1, 0, 0.502027,-0.0247992) , 
0, 104912, 1, 0, 0.511938,-0.00291421)    );
  // itree = 839
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493455,0.00120062) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523909,0.0316227) , 
1, 13.0476, 1, 0, 0.495388,0.00496656) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.646408,-0.0489549) , 
0, 185592, 1, 0, 0.500705,0.00310671)    );
  // itree = 840
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50849,-0.00529557) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432867,0.0135277) , 
0, 75434.1, 1, 0, 0.491243,-0.00116171) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.30694,0.00711768) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.817795,-0.087801) , 
4, 0.230457, 1, 0, 0.585321,-0.0418216) , 
0, 158163, 1, 0, 0.496476,-0.00342323)    );
  // itree = 841
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298868,-0.00626821) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75792,0.00787701) , 
4, 0.116791, 1, 0, 0.509712,0.000762627) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414128,-0.0404538) , 
1, 14.3333, 1, 0, 0.504952,-0.00264436)    );
  // itree = 842
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.391528,0.0177087) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557446,-0.000587568) , 
8, -0.0247164, 1, 0, 0.514333,0.00501703) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394218,-0.0496109) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538172,-0.0199344) , 
3, 0.047619, 1, 0, 0.466453,-0.0655655) , 
1, 13.3333, 1, 0, 0.511378,0.000660794)    );
  // itree = 843
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.123265,0.13332) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539475,-0.00741394) , 
8, -0.126644, 1, 0, 0.520845,-0.00640554) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455082,0.00632716) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364123,0.0311292) , 
7, 0.728103, 1, 0, 0.428886,0.0195953) , 
1, 8.04762, 1, 0, 0.491517,0.00188681)    );
  // itree = 844
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.981466,0.0283957) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25656,-0.0173361) , 
1, 1.71429, 1, 0, 0.342816,-0.0204663) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.287585,-0.009879) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.796023,0.0173174) , 
4, 0.0948686, 1, 0, 0.565207,0.00665628) , 
2, 45371.2, 1, 0, 0.49914,-0.00140119)    );
  // itree = 845
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515926,-0.000774687) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411238,-0.0206419) , 
1, 11.3333, 1, 0, 0.502259,-0.00480744) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.116142,0.0160937) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0996825,0.160863) , 
6, 3.28542, 1, 0, 0.108317,0.0408614) , 
8, 0.121493, 1, 0, 0.48085,-0.00232557)    );
  // itree = 846
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.241391,-0.0596954) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.152409,0.00298873) , 
0, 39263.5, 1, 0, 0.182063,-0.0273622) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554006,0.00504207) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.128276,-0.0391685) , 
7, 2.07709, 1, 0, 0.523741,0.00384456) , 
7, -1.85256, 1, 0, 0.494486,0.00117257)    );
  // itree = 847
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.804339,0.00343598) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.3869,-0.00920521) , 
1, 4.52381, 1, 0, 0.520649,-0.0077846) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532454,0.0604563) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.146469,0.00604809) , 
6, 1.77162, 1, 0, 0.273719,0.0256517) , 
7, 1.57195, 1, 0, 0.48913,-0.00351674)    );
  // itree = 848
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326241,-0.0073367) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.940981,0.0129678) , 
5, 4005.46, 1, 0, 0.51917,-0.00443635) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513256,0.0500073) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.194074,0.00238623) , 
7, 1.84782, 1, 0, 0.284268,0.0218415) , 
7, 1.57447, 1, 0, 0.488813,-0.00104046)    );
  // itree = 849
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.30137,-0.0129772) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.784996,0.0128189) , 
4, 0.133458, 1, 0, 0.489615,-0.00252476) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473814,-0.018898) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362819,-0.0574161) , 
0, 137770, 1, 0, 0.420574,-0.0545341) , 
1, 14.3333, 1, 0, 0.485929,-0.00530189)    );
  // itree = 850
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519016,0.00695912) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.427824,-0.0260176) , 
1, 12.3333, 1, 0, 0.513514,0.0051488) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.556862,0.0376783) , 
1, 15.6667, 1, 0, 0.515406,0.00747337)    );
  // itree = 851
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.101538,0.0560326) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.36753,-0.00518735) , 
7, -2.13274, 1, 0, 0.350685,-0.00421103) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.892685,0.031344) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.926356,0.00928018) , 
7, -0.758618, 1, 0, 0.917467,0.017076) , 
4, 0.209367, 1, 0, 0.49843,0.00133792)    );
  // itree = 852
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.113568,0.0149775) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.138169,-0.0328789) , 
7, -0.998701, 1, 0, 0.131426,-0.021405) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.60479,0.00161835) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507889,0.0210788) , 
8, 0.00627584, 1, 0, 0.556533,0.0154334) , 
8, -0.0748369, 1, 0, 0.510957,0.0114839)    );
  // itree = 853
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368408,-0.0105107) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364823,0.0341053) , 
2, 39864.4, 1, 0, 0.365583,0.0220357) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.587436,-0.00852586) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.370875,0.0284293) , 
6, 5.69894, 1, 0, 0.574123,-0.00720158) , 
4, 0.0590127, 1, 0, 0.512637,0.00141877)    );
  // itree = 854
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289031,-0.026662) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542268,0.0139833) , 
2, 73480.1, 1, 0, 0.378586,-0.0162549) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.635861,0.0125164) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.276269,-0.0152595) , 
7, 1.40506, 1, 0, 0.555908,0.0090465) , 
7, -0.710328, 1, 0, 0.504013,0.00164185)    );
  // itree = 855
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343724,0.012762) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.794254,0.000642377) , 
4, 0.13331, 1, 0, 0.541544,0.00971396) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0742447,0.00961374) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.446495,-0.0657943) , 
4, 0.172482, 1, 0, 0.176143,-0.0255878) , 
6, 5.08947, 1, 0, 0.504541,0.00613908)    );
  // itree = 856
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.443272,0.00586631) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.905528,-0.0287821) , 
4, 0.247499, 1, 0, 0.520542,0.00312716) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333367,-0.02634) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502057,0.000842594) , 
1, 12.6667, 1, 0, 0.407052,-0.01944) , 
1, 9.80952, 1, 0, 0.493249,-0.00229995)    );
  // itree = 857
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521854,-0.00863117) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.142693,0.035908) , 
8, 0.123902, 1, 0, 0.501422,-0.00879524) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47673,-0.0364128) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362819,-0.0461137) , 
7, 0.128138, 1, 0, 0.420192,-0.0718047) , 
1, 14.619, 1, 0, 0.497265,-0.0120198)    );
  // itree = 858
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292921,-0.0102577) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.207142,-0.0363664) , 
4, 0.0619953, 1, 0, 0.277469,-0.0176471) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605985,-0.00827966) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614829,0.00939298) , 
7, 0.136321, 1, 0, 0.610187,0.00052706) , 
4, 0.0764862, 1, 0, 0.484982,-0.00631201)    );
  // itree = 859
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44414,0.0158976) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248306,-0.0292224) , 
4, 0.0242919, 1, 0, 0.29801,-0.0157571) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379563,0.00937608) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.932686,-0.0135881) , 
5, 4622.35, 1, 0, 0.58429,0.0069316) , 
4, 0.0594028, 1, 0, 0.501691,0.000385378)    );
  // itree = 860
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.66136,0.0172647) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616677,-0.00407131) , 
7, -0.154131, 1, 0, 0.63622,0.00668849) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.397995,-0.0227353) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.291998,-0.00377231) , 
8, 0.011091, 1, 0, 0.355035,-0.0191812) , 
1, 6.90476, 1, 0, 0.497846,-0.00604221)    );
  // itree = 861
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54968,-0.00132742) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554589,-0.0348477) , 
1, 12.0476, 1, 0, 0.550017,-0.00484011) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203806,-0.00169324) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337336,0.0328498) , 
8, -0.00370481, 1, 0, 0.27653,0.0210433) , 
6, 3.78275, 1, 0, 0.496224,0.000250927)    );
  // itree = 862
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.780851,0.0197404) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.36833,-0.000376527) , 
6, 1.71967, 1, 0, 0.569293,0.0114383) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.206827,-0.00585243) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.626793,-0.032757) , 
4, 0.153315, 1, 0, 0.345239,-0.0190123) , 
8, 0.0257083, 1, 0, 0.508927,0.00323405)    );
  // itree = 863
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.377269,0.00820986) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.671671,-0.0120151) , 
4, 0.0952177, 1, 0, 0.528469,-0.00305509) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0181808,-0.028943) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484313,0.0158689) , 
4, 0.0401388, 1, 0, 0.403493,0.0171589) , 
1, 9.80952, 1, 0, 0.498307,0.00182336)    );
  // itree = 864
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37781,0.0124522) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542801,-0.00454457) , 
4, 0.0592006, 1, 0, 0.492054,-0.00028357) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0922962,-0.00910562) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.741773,0.0207649) , 
4, 0.0777019, 1, 0, 0.532454,0.0183547) , 
0, 104899, 1, 0, 0.497112,0.00204961)    );
  // itree = 865
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374623,0.0155156) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31192,-0.0348059) , 
4, 0.023706, 1, 0, 0.342033,-0.0102104) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.863353,-0.00988651) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448335,0.0110364) , 
1, 3.95238, 1, 0, 0.537372,0.00980321) , 
4, 0.038225, 1, 0, 0.500675,0.00604338)    );
  // itree = 866
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515359,0.0074953) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0684439,-0.0470752) , 
7, 2.42095, 1, 0, 0.498933,0.00795078) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482001,0.00418909) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466512,-0.0402308) , 
8, -0.00752849, 1, 0, 0.47317,-0.0224275) , 
0, 108110, 1, 0, 0.495857,0.00432403)    );
  // itree = 867
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175426,0.049882) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560751,-0.0042738) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31943,0.0141676) , 
7, 1.45469, 1, 0, 0.523048,-0.00198731) , 
7, -2.41103, 1, 0, 0.510487,-0.000386617)    );
  // itree = 868
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.51739,-0.0127491) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374872,0.0115922) , 
0, 56737.9, 1, 0, 0.495274,-0.0110774) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.136623,-0.00586013) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.860395,0.0271022) , 
4, 0.134374, 1, 0, 0.439221,0.00951811) , 
0, 69444.7, 1, 0, 0.478989,-0.00509389)    );
  // itree = 869
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313513,-0.00711742) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.39312,-0.0330671) , 
4, 0.124525, 1, 0, 0.321061,-0.0123473) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.667072,0.0151106) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.896302,-0.00303863) , 
4, 0.224144, 1, 0, 0.816788,0.00778452) , 
4, 0.153526, 1, 0, 0.508504,-0.00473512)    );
  // itree = 870
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680616,0.00850167) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.278212,0.0514781) , 
7, 2.12874, 1, 0, 0.657223,0.0134387) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0893555,0.0012018) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.684631,-0.0166557) , 
4, 0.134421, 1, 0, 0.339298,-0.0103312) , 
1, 6.28571, 1, 0, 0.503515,0.00194662)    );
  // itree = 871
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217516,-0.0160765) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329283,0.0223275) , 
7, -0.952981, 1, 0, 0.298234,0.0135054) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616973,-0.00278057) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0915221,-0.036055) , 
8, 0.0829163, 1, 0, 0.554879,-0.00620465) , 
8, -0.0380049, 1, 0, 0.504999,-0.0023739)    );
  // itree = 872
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541405,-0.0165264) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559932,0.00162046) , 
8, 0.000875456, 1, 0, 0.550647,-0.0103488) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217925,-0.0248757) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349976,0.0148015) , 
7, -0.992706, 1, 0, 0.313147,0.00640399) , 
3, 0.047619, 1, 0, 0.482375,-0.00553298)    );
  // itree = 873
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544718,-0.00779355) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414471,0.00817719) , 
8, 0.020861, 1, 0, 0.505753,-0.00418494) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.113254,-0.0419347) , 
6, 7.49758, 1, 0, 0.490134,-0.00575624)    );
  // itree = 874
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.649196,-0.000983741) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407092,0.0120034) , 
1, 6.33333, 1, 0, 0.537083,0.00701726) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102239,-0.0511049) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.166711,-0.00757165) , 
1, 12.6667, 1, 0, 0.126748,-0.0327486) , 
6, 5.64646, 1, 0, 0.50507,0.00391487)    );
  // itree = 875
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.206115,-0.00518457) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294365,-0.03372) , 
7, -0.698246, 1, 0, 0.266615,-0.0317933) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354746,-0.0569314) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574271,0.00581264) , 
4, 0.0208336, 1, 0, 0.560957,0.00340615) , 
8, -0.0257209, 1, 0, 0.485004,-0.00567676)    );
  // itree = 876
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456071,0.0428976) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.740568,0.0107979) , 
8, -0.0468922, 1, 0, 0.711335,0.0182532) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394218,-0.0230731) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.282196,0.00474632) , 
1, 4.52381, 1, 0, 0.296262,-0.000575735) , 
6, 1.90533, 1, 0, 0.507938,0.00902651)    );
  // itree = 877
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588087,0.0217864) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.839178,0.00359162) , 
2, 40366.3, 1, 0, 0.739708,0.0157958) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.317818,-0.0100442) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510586,0.00927852) , 
1, 12.8571, 1, 0, 0.348426,-0.00755418) , 
1, 5.14286, 1, 0, 0.507176,0.00191932)    );
  // itree = 878
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.944803,-0.00119334) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55742,0.0196563) , 
1, 3.19048, 1, 0, 0.714727,0.0199839) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.13218,-0.00431472) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.742143,-0.025568) , 
5, 2432.59, 1, 0, 0.300419,-0.0144819) , 
6, 1.73371, 1, 0, 0.50247,0.00232653)    );
  // itree = 879
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.834748,0.0117555) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.713722,0.0408016) , 
1, 8.14286, 1, 0, 0.820727,0.0172014) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.242053,-0.0079143) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.925477,0.0235826) , 
4, 0.304839, 1, 0, 0.337048,-0.00627614) , 
6, 1.25663, 1, 0, 0.508736,0.00205751)    );
  // itree = 880
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538067,0.00133871) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238825,0.0363072) , 
7, 1.85965, 1, 0, 0.510729,0.00476236) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.269726,0.0604798) , 
6, 8.20987, 1, 0, 0.502365,0.00749103)    );
  // itree = 881
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.236984,-0.0145612) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511228,0.0252688) , 
4, 0.0605753, 1, 0, 0.419845,0.0205558) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353359,-0.0274149) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544959,-0.00421072) , 
4, 0.0401388, 1, 0, 0.509744,-0.00995782) , 
7, -0.710708, 1, 0, 0.483392,-0.00101357)    );
  // itree = 882
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.855164,-0.0073365) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448037,-0.040329) , 
6, 1.11377, 1, 0, 0.790237,-0.017052) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38257,0.0126809) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.224836,-0.00473927) , 
7, 1.00464, 1, 0, 0.34214,0.0113241) , 
6, 1.29193, 1, 0, 0.504612,0.00103539)    );
  // itree = 883
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347377,0.0481399) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360022,0.00231124) , 
2, 40284.9, 1, 0, 0.356659,0.0197837) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535113,-0.00767662) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550408,0.0199938) , 
1, 13.4286, 1, 0, 0.536168,-0.00604352) , 
7, -1.27212, 1, 0, 0.505581,-0.00164274)    );
  // itree = 884
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.3642,0.00224744) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390621,0.0414942) , 
1, 9, 1, 0, 0.373258,0.0204528) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579042,-0.00392343) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233865,0.0341318) , 
7, 2.12955, 1, 0, 0.55903,-0.00273734) , 
8, -0.0247164, 1, 0, 0.509251,0.00347665)    );
  // itree = 885
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617712,-0.0101961) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669093,0.0201746) , 
1, 10.6667, 1, 0, 0.621846,-0.00994885) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325417,0.018823) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322243,-0.0043112) , 
7, -0.422621, 1, 0, 0.323598,0.00629095) , 
6, 2.19385, 1, 0, 0.498662,-0.00324139)    );
  // itree = 886
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565714,-0.0221382) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0909207,0.00159569) , 
1, 5.7619, 1, 0, 0.288985,-0.0120344) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.744049,0.00888564) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.651681,-0.0148523) , 
1, 11.5714, 1, 0, 0.72846,0.00477401) , 
4, 0.114245, 1, 0, 0.495505,-0.00413571)    );
  // itree = 887
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495273,8.32777e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404449,-0.0341179) , 
1, 12.3333, 1, 0, 0.489632,-0.00336448) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544015,0.0353753) , 
1, 15.7619, 1, 0, 0.492067,-0.000345625)    );
  // itree = 888
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528347,-0.00105861) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471951,-0.044519) , 
7, 0.266487, 1, 0, 0.52375,-0.00705955) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.635546,0.0203365) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306372,-0.00010363) , 
7, 1.16656, 1, 0, 0.457976,0.0141698) , 
7, 0.429913, 1, 0, 0.498494,0.00109189)    );
  // itree = 889
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.115962,-0.0193222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40086,-0.0308534) , 
4, 0.116838, 1, 0, 0.224782,-0.0305414) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.595894,0.00499703) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293111,-0.0190091) , 
7, 1.25908, 1, 0, 0.530794,0.00111055) , 
7, -1.56698, 1, 0, 0.494103,-0.00268448)    );
  // itree = 890
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.700889,0.0054226) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321583,-0.00848965) , 
1, 5.7619, 1, 0, 0.48392,-0.00321721) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72738,-0.0213454) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393187,0.0455038) , 
6, 5.59126, 1, 0, 0.584757,0.0235187) , 
0, 136084, 1, 0, 0.49096,-0.00135066)    );
  // itree = 891
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567838,0.00519217) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376134,-0.0251252) , 
6, 3.83448, 1, 0, 0.559383,0.00398889) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238104,-0.00266385) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.1034,-0.0434468) , 
7, 0.42691, 1, 0, 0.186321,-0.0208692) , 
6, 4.2365, 1, 0, 0.501015,9.96628e-05)    );
  // itree = 892
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422775,-0.0192127) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.953155,0.0121093) , 
5, 4518.57, 1, 0, 0.597726,-0.0169914) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475573,0.0353616) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.30095,0.00518043) , 
1, 5, 1, 0, 0.317211,0.0119979) , 
6, 2.5138, 1, 0, 0.495934,-0.00647191)    );
  // itree = 893
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421364,0.0209264) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0627839,-0.00850906) , 
1, 9, 1, 0, 0.317071,0.0152942) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.418056,-0.0160584) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.861841,0.0100147) , 
4, 0.182006, 1, 0, 0.675378,-0.00387771) , 
4, 0.0951591, 1, 0, 0.513917,0.00476157)    );
  // itree = 894
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558058,0.00204353) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350748,-0.0183889) , 
0, 55325.2, 1, 0, 0.480137,-0.00711847) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519881,0.00291064) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.782547,0.0539352) , 
3, 0.047619, 1, 0, 0.644656,0.02948) , 
0, 131531, 1, 0, 0.493231,-0.00420561)    );
  // itree = 895
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564292,0.00282023) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305958,0.0254976) , 
6, 3.56254, 1, 0, 0.515024,0.0085293) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.113254,-0.0586811) , 
6, 7.49758, 1, 0, 0.498484,0.00541942)    );
  // itree = 896
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.967731,0.0122557) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603329,0.0210501) , 
6, 1.10246, 1, 0, 0.82109,0.0216224) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.254813,0.0106955) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.3712,-0.0189139) , 
7, -0.977036, 1, 0, 0.342337,-0.016654) , 
1, 4.52381, 1, 0, 0.491004,-0.00476797)    );
  // itree = 897
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.643067,-0.00202658) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.178253,-0.0571252) , 
6, 2.22574, 1, 0, 0.617773,-0.00577817) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.246992,0.00408403) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.944259,0.046909) , 
4, 0.305379, 1, 0, 0.335533,0.0116262) , 
6, 2.45565, 1, 0, 0.511748,0.000759861)    );
  // itree = 898
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.649595,-0.00418494) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434177,-0.0312116) , 
8, 0.0319041, 1, 0, 0.604549,-0.011815) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0343044,-0.0157476) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570649,0.0129648) , 
4, 0.07624, 1, 0, 0.370496,0.00866582) , 
1, 6.28571, 1, 0, 0.490102,-0.00180029)    );
  // itree = 899
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555398,-0.00676962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422228,0.00736919) , 
8, 0.0227751, 1, 0, 0.515129,-0.00340072) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.269574,0.0196471) , 
6, 7.04381, 1, 0, 0.502927,-0.00182675)    );
  // itree = 900
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499935,-0.00167839) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.589915,0.0394476) , 
1, 14.1429, 1, 0, 0.502919,0.000161537) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.331428,0.0350828) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.931815,-0.00536062) , 
5, 4527.11, 1, 0, 0.637247,0.0224026) , 
0, 132062, 1, 0, 0.514319,0.00204902)    );
  // itree = 901
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464938,-0.000693056) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393493,0.0241312) , 
1, 11.9524, 1, 0, 0.457678,0.00285924) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519533,-0.0418685) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.992912,0.0435192) , 
5, 9968.74, 1, 0, 0.71192,-0.0236232) , 
2, 116161, 1, 0, 0.486858,-0.000180176)    );
  // itree = 902
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.194766,-0.0240301) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539196,0.00692704) , 
7, -1.8521, 1, 0, 0.505711,0.00501336) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445993,-0.0247148) , 
1, 15.0952, 1, 0, 0.503621,0.00326035)    );
  // itree = 903
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315083,0.00487487) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344525,0.0275369) , 
4, 0.0889593, 1, 0, 0.321037,0.013421) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965198,0.0232691) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601952,-0.010487) , 
6, 1.13753, 1, 0, 0.727305,-0.00661587) , 
4, 0.116173, 1, 0, 0.507582,0.00422069)    );
  // itree = 904
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305701,0.0179193) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360711,-0.0172803) , 
2, 80754.4, 1, 0, 0.319881,0.0100693) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477415,-0.0110413) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986063,0.0235991) , 
5, 5878.84, 1, 0, 0.657772,-0.0101725) , 
4, 0.0952811, 1, 0, 0.505055,-0.00102381)    );
  // itree = 905
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603083,0.0101847) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.254122,-0.0163565) , 
6, 2.61687, 1, 0, 0.487123,0.00203217) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.758638,0.0650777) , 
0, 191218, 1, 0, 0.496446,0.00430764)    );
  // itree = 906
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0549128,-0.0769861) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421362,-0.00387979) , 
7, -2.41792, 1, 0, 0.40625,-0.00739744) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.935043,-0.00178903) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.945723,0.0344971) , 
1, 9.28571, 1, 0, 0.9385,0.0100464) , 
4, 0.266707, 1, 0, 0.504481,-0.00417804)    );
  // itree = 907
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.718415,-0.020056) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.778391,0.00570977) , 
8, -0.00881671, 1, 0, 0.756607,-0.00525454) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0886512,-0.012646) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.452704,0.0178282) , 
4, 0.0575487, 1, 0, 0.343874,0.0151172) , 
6, 1.43967, 1, 0, 0.516074,0.00661772)    );
  // itree = 908
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.61137,0.00664956) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388958,-0.0270347) , 
1, 9.7619, 1, 0, 0.572465,-2.77672e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.125785,-0.00865717) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498511,0.041434) , 
2, 60260.4, 1, 0, 0.321522,0.020439) , 
3, 0.047619, 1, 0, 0.49846,0.00600809)    );
  // itree = 909
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388695,0.0325012) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.103671,-0.000647548) , 
3, 0.047619, 1, 0, 0.268665,0.0285437) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337971,-0.0467998) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544748,-0.00331144) , 
7, -1.34914, 1, 0, 0.538004,-0.005916) , 
7, -1.5674, 1, 0, 0.507814,-0.00205337)    );
  // itree = 910
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 1,0.0539146) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.462224,-0.00867058) , 
6, 0.375373, 1, 0, 0.506634,-0.00903027) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0737919,-0.0233905) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669376,0.0119612) , 
4, 0.0586087, 1, 0, 0.48794,0.0058534) , 
0, 69869.8, 1, 0, 0.501456,-0.0049074)    );
  // itree = 911
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527591,-0.00532875) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464399,-0.0540554) , 
1, 13.3333, 1, 0, 0.522728,-0.0116113) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4761,8.90908e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375296,0.0427491) , 
1, 7.57143, 1, 0, 0.437691,0.0226356) , 
7, 0.716036, 1, 0, 0.4972,-0.0013306)    );
  // itree = 912
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506529,0.0018356) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.140203,-0.0211461) , 
0, 42940.4, 1, 0, 0.297734,-0.0123335) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.777381,-0.0072192) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.799176,0.0199303) , 
1, 8.38095, 1, 0, 0.78507,0.00450092) , 
4, 0.134421, 1, 0, 0.500225,-0.00533873)    );
  // itree = 913
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489538,-0.000680792) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.642731,0.0320502) , 
0, 128482, 1, 0, 0.499705,0.00164044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.436849,-0.0300837) , 
1, 15.7619, 1, 0, 0.497165,-0.000189696)    );
  // itree = 914
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341781,0.0103028) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0899359,-0.0123485) , 
1, 10.5238, 1, 0, 0.305292,0.00921917) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.823741,-0.0042945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694904,-0.021558) , 
1, 6.28571, 1, 0, 0.755598,-0.0191282) , 
4, 0.133458, 1, 0, 0.49002,-0.00240974)    );
  // itree = 915
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0705644,-0.028417) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480599,0.0179486) , 
8, -0.113527, 1, 0, 0.380183,0.0126748) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351208,0.00227498) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69804,-0.0156463) , 
4, 0.0968119, 1, 0, 0.53908,-0.00935363) , 
8, -0.0232873, 1, 0, 0.495261,-0.00327879)    );
  // itree = 916
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495002,0.00185438) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529976,-0.0297996) , 
7, -0.423178, 1, 0, 0.500679,-0.00431649) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564766,0.0165735) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.184261,-0.0306468) , 
6, 5.64529, 1, 0, 0.531187,0.0159738) , 
7, -0.149746, 1, 0, 0.517745,0.00703422)    );
  // itree = 917
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327988,-0.0156627) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.166176,0.021524) , 
8, 0.0399396, 1, 0, 0.28864,-0.009651) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.661638,0.00882361) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.214868,-0.0315944) , 
8, 0.0851762, 1, 0, 0.621872,0.0085611) , 
4, 0.0764862, 1, 0, 0.491679,0.0014457)    );
  // itree = 918
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.964466,0.00710372) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.782433,0.0275078) , 
1, 2.04762, 1, 0, 0.917794,0.0153739) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.34932,-0.00811887) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.726571,0.0303891) , 
0, 184806, 1, 0, 0.36721,-0.00855636) , 
1, 3.7619, 1, 0, 0.49245,-0.00311299)    );
  // itree = 919
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468226,-0.0150429) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309065,0.00451569) , 
0, 48369, 1, 0, 0.407708,-0.00918717) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32896,-0.0150459) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.727673,0.0163792) , 
4, 0.0396, 1, 0, 0.644078,0.0108658) , 
2, 74057.1, 1, 0, 0.493048,-0.00194714)    );
  // itree = 920
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470904,-0.00393228) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.95265,0.0421276) , 
4, 0.304502, 1, 0, 0.513418,-0.0011732) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534508,0.0259622) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0760629,-0.0720011) , 
8, 0.0764633, 1, 0, 0.487034,0.0228199) , 
0, 69879, 1, 0, 0.505843,0.00571592)    );
  // itree = 921
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564481,0.0193198) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.43231,-0.00622903) , 
1, 8.04762, 1, 0, 0.524015,0.0146904) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.792758,0.0106451) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288099,-0.0259742) , 
1, 5, 1, 0, 0.451418,-0.0161955) , 
7, 0.430449, 1, 0, 0.496387,0.00293604)    );
  // itree = 922
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565742,-0.000884227) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546323,0.0296562) , 
1, 9.66667, 1, 0, 0.56222,0.00613747) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0743712,-0.0260073) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.699086,-0.070255) , 
4, 0.228752, 1, 0, 0.19361,-0.0348693) , 
6, 4.27527, 1, 0, 0.508295,0.000138481)    );
  // itree = 923
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.149084,0.00127469) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221612,0.0871921) , 
7, -2.5187, 1, 0, 0.188807,0.0407045) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440847,0.0290611) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539854,0.0014643) , 
4, 0.0208336, 1, 0, 0.533389,0.00385333) , 
7, -2.11134, 1, 0, 0.5141,0.00591615)    );
  // itree = 924
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.263303,-0.0143254) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337294,0.0162312) , 
7, -0.435767, 1, 0, 0.309408,0.00759248) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.787587,-0.00199989) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.61882,-0.0406966) , 
7, 0.945957, 1, 0, 0.754524,-0.0125411) , 
4, 0.133639, 1, 0, 0.489775,-0.000565892)    );
  // itree = 925
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.679495,0.0179004) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69969,0.00085631) , 
8, -0.0130331, 1, 0, 0.693369,0.00831781) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0993408,-0.00108747) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.624819,-0.0221983) , 
5, 1881.91, 1, 0, 0.283726,-0.0125902) , 
6, 1.90533, 1, 0, 0.500306,-0.00153604)    );
  // itree = 926
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510289,-0.0108275) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.609609,0.00414384) , 
7, 0.239107, 1, 0, 0.535442,-0.0081046) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273868,0.0259749) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.917595,-0.0689088) , 
5, 6267.68, 1, 0, 0.367659,0.0205915) , 
7, 1.00076, 1, 0, 0.494419,-0.00108827)    );
  // itree = 927
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492794,-0.00731306) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432689,-0.0323644) , 
1, 12.1429, 1, 0, 0.485585,-0.0132546) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.274599,-0.00287854) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.642231,0.0123481) , 
4, 0.0762669, 1, 0, 0.50458,0.00958649) , 
8, 0.00633047, 1, 0, 0.49416,-0.00294387)    );
  // itree = 928
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426182,0.00385231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308259,-0.0646144) , 
4, 0.0119542, 1, 0, 0.360803,-0.0365418) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423883,0.0414879) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514647,-0.00159146) , 
4, 0.0374914, 1, 0, 0.504264,0.00302081) , 
4, 0.0192455, 1, 0, 0.495305,0.000550156)    );
  // itree = 929
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.164963,-0.00337216) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539176,-0.0305154) , 
4, 0.116537, 1, 0, 0.315752,-0.0180061) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680542,0.0141812) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384157,-0.00518246) , 
8, 0.0219872, 1, 0, 0.565838,0.0091383) , 
8, -0.0276375, 1, 0, 0.502711,0.00228647)    );
  // itree = 930
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.809693,-0.00698573) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426647,0.0151341) , 
1, 4.52381, 1, 0, 0.548731,0.0116121) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385988,-0.0225395) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361643,-0.000689624) , 
0, 64816.7, 1, 0, 0.377816,-0.0188763) , 
7, 0.727167, 1, 0, 0.496006,0.00220692)    );
  // itree = 931
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567174,0.000983358) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539621,0.0161346) , 
1, 11.5714, 1, 0, 0.563322,0.00430148) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511358,0.0150117) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.072243,-0.0455277) , 
6, 1.31852, 1, 0, 0.173633,-0.0196325) , 
8, 0.0651893, 1, 0, 0.5205,0.00167145)    );
  // itree = 932
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305533,0.0030822) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407065,-0.0157721) , 
4, 0.106238, 1, 0, 0.329278,-0.00298746) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.801019,0.0349378) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.840677,0.00792709) , 
8, -0.022557, 1, 0, 0.831836,0.0174693) , 
4, 0.171529, 1, 0, 0.491495,0.00361563)    );
  // itree = 933
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559404,0.00181935) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355434,-0.017064) , 
1, 8.33333, 1, 0, 0.505939,-0.00419234) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.803396,-0.0325989) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551803,0.041079) , 
6, 3.25821, 1, 0, 0.638278,0.0331407) , 
0, 131531, 1, 0, 0.516809,-0.00112602)    );
  // itree = 934
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531194,-0.00126286) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.1968,0.0297603) , 
8, 0.0591341, 1, 0, 0.484576,0.00211914) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.886319,-0.0755077) , 
4, 0.362043, 1, 0, 0.499582,0.000146726)    );
  // itree = 935
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605832,-0.012122) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419156,0.00691013) , 
0, 49088.9, 1, 0, 0.542347,-0.00611106) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32375,0.0471806) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494331,0.000398362) , 
7, -1.01235, 1, 0, 0.450453,0.0145023) , 
1, 8.38095, 1, 0, 0.51421,0.00020042)    );
  // itree = 936
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.553617,-0.00271914) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.227653,0.0244402) , 
6, 2.31244, 1, 0, 0.422495,0.00910144) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329333,0.0489957) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.638377,-0.0215191) , 
8, -0.0646565, 1, 0, 0.602606,-0.014481) , 
2, 63377.3, 1, 0, 0.505531,-0.00177074)    );
  // itree = 937
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389439,0.00685341) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.889134,-0.014455) , 
4, 0.229359, 1, 0, 0.497149,0.00420065) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458728,-0.0409415) , 
1, 16.8571, 1, 0, 0.496148,0.00219322)    );
  // itree = 938
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.678164,-0.0216537) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.892038,0.0164059) , 
4, 0.113994, 1, 0, 0.775737,-0.00994022) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.226553,-0.00567231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422482,0.0110844) , 
8, -0.0276375, 1, 0, 0.368166,0.00926488) , 
1, 5, 1, 0, 0.495362,0.00327129)    );
  // itree = 939
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539268,-0.0073479) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393211,0.0147466) , 
7, 1.01202, 1, 0, 0.506898,-0.00377875) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262473,-0.0228007) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555435,0.0227254) , 
7, -1.27884, 1, 0, 0.509226,0.0199209) , 
0, 72805.3, 1, 0, 0.507531,0.00266804)    );
  // itree = 940
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.991409,0.0347964) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.735986,-0.0334301) , 
6, 0.510839, 1, 0, 0.828263,-0.0232728) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337566,-0.00793537) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339538,0.00688819) , 
1, 6.33333, 1, 0, 0.338759,-0.000470215) , 
6, 1.11894, 1, 0, 0.492491,-0.00763151)    );
  // itree = 941
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497007,0.00206044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.251199,0.0343879) , 
6, 6.75493, 1, 0, 0.482283,0.00467532) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.837733,-0.0734336) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.949179,0.0181019) , 
0, 60355.8, 1, 0, 0.895191,-0.028747) , 
4, 0.342315, 1, 0, 0.507975,0.00259577)    );
  // itree = 942
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.207049,-0.00780529) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358588,-0.05967) , 
2, 79118.5, 1, 0, 0.248431,-0.0258974) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.648209,0.017351) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532183,-0.00287913) , 
8, -0.0124277, 1, 0, 0.555967,0.00267825) , 
8, -0.0365758, 1, 0, 0.49359,-0.00311771)    );
  // itree = 943
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.461728,-0.0153855) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.170826,0.0108995) , 
3, 0.047619, 1, 0, 0.383057,-0.0138218) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664796,0.0193068) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.596552,-0.0151826) , 
0, 114789, 1, 0, 0.647088,0.0117897) , 
2, 68299.9, 1, 0, 0.488732,-0.00357112)    );
  // itree = 944
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0582853,-0.0709775) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439078,0.0119762) , 
7, -2.13759, 1, 0, 0.416514,0.0132178) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392193,-0.0226767) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.904327,-0.00429601) , 
4, 0.172494, 1, 0, 0.590424,-0.0194496) , 
2, 63377.3, 1, 0, 0.494813,-0.00148991)    );
  // itree = 945
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586698,0.0100859) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244822,-0.0166462) , 
7, 1.57195, 1, 0, 0.542039,0.00917728) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0357124,0.0136292) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244937,-0.0306593) , 
4, 0.0596513, 1, 0, 0.167823,-0.0280286) , 
6, 4.84516, 1, 0, 0.500578,0.00505505)    );
  // itree = 946
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.63155,0.0188045) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.759139,-0.00368859) , 
2, 62576, 1, 0, 0.694237,0.0135003) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243372,-0.00325466) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307278,-0.0321946) , 
8, -0.0188329, 1, 0, 0.284024,-0.0275584) , 
6, 1.96112, 1, 0, 0.498449,-0.00609634)    );
  // itree = 947
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541856,-0.00933526) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.36072,0.00887415) , 
7, 1.00057, 1, 0, 0.496916,-0.00601168) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489845,0.0420514) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519213,-0.0119545) , 
0, 121923, 1, 0, 0.505904,0.0214418) , 
1, 13.3333, 1, 0, 0.497576,-0.00399787)    );
  // itree = 948
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.585272,0.00509607) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400473,-0.0113645) , 
1, 7.66667, 1, 0, 0.51224,-0.0017603) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.218949,0.0464968) , 
6, 8.45791, 1, 0, 0.504194,-0.000180245)    );
  // itree = 949
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542612,0.000818045) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582634,0.0224231) , 
1, 12.8095, 1, 0, 0.546639,0.00480718) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.476432,-0.0260653) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.231707,-0.00265845) , 
7, 1.66295, 1, 0, 0.365807,-0.0214039) , 
7, 0.995912, 1, 0, 0.501879,-0.00168078)    );
  // itree = 950
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312965,0.00835143) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.268106,-0.0142256) , 
7, 0.158926, 1, 0, 0.292471,-0.00216743) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.646186,0.00220954) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697294,0.018296) , 
8, -0.00291834, 1, 0, 0.673443,0.0151937) , 
4, 0.0953875, 1, 0, 0.499995,0.00728956)    );
  // itree = 951
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389999,-0.027539) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.318007,-0.00508827) , 
2, 31227.4, 1, 0, 0.366059,-0.0291558) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549981,0.0059078) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338132,0.0480715) , 
7, 1.56191, 1, 0, 0.523024,0.0121205) , 
2, 36367.4, 1, 0, 0.494679,0.0046667)    );
  // itree = 952
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434826,-0.0102062) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.773575,0.0396266) , 
2, 131755, 1, 0, 0.468735,-0.00802598) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574154,0.0187384) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442325,-0.00123692) , 
8, 0.011091, 1, 0, 0.523615,0.0141642) , 
7, -0.425678, 1, 0, 0.50403,0.00624538)    );
  // itree = 953
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409057,-0.00382183) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.228562,-0.0268134) , 
1, 13.8571, 1, 0, 0.397714,-0.00776899) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.880174,0.042862) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.988273,0.0281907) , 
5, 5073.13, 1, 0, 0.952756,0.0336968) , 
4, 0.266409, 1, 0, 0.490312,-0.0008512)    );
  // itree = 954
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479099,0.00408231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57495,-0.0189883) , 
7, -0.32762, 1, 0, 0.524298,-0.0101399) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252853,0.0184331) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.814933,-0.0322532) , 
4, 0.205022, 1, 0, 0.377738,0.0115227) , 
7, 1.00259, 1, 0, 0.488828,-0.00489719)    );
  // itree = 955
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0119702,-0.0460302) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0565488,-0.0459745) , 
5, 1168.13, 1, 0, 0.0324093,-0.0283278) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.19885,-0.0453027) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551046,0.00945201) , 
8, -0.0860004, 1, 0, 0.539238,0.0101557) , 
8, -0.115886, 1, 0, 0.510323,0.00796015)    );
  // itree = 956
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.566623,0.00685962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.604881,-0.0231245) , 
1, 12.1429, 1, 0, 0.568881,0.00624811) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.146616,-0.0402522) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339104,0.0126609) , 
1, 12.1429, 1, 0, 0.211331,-0.0162667) , 
6, 4.34645, 1, 0, 0.520489,0.00320086)    );
  // itree = 957
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524182,0.00247923) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423859,-0.0172851) , 
7, 0.430449, 1, 0, 0.486088,-0.00566901) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.635267,0.0469514) , 
0, 184795, 1, 0, 0.490891,-0.00363589)    );
  // itree = 958
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.86288,0.000220201) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.791776,0.0336705) , 
8, 0.015458, 1, 0, 0.842545,0.0114295) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.124994,0.00493075) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505486,-0.0100409) , 
4, 0.0966893, 1, 0, 0.324607,-0.00564741) , 
6, 1.11755, 1, 0, 0.492268,-0.000119495)    );
  // itree = 959
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.61352,-0.0288967) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.878235,0.00125818) , 
4, 0.0787655, 1, 0, 0.772368,-0.0145992) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328462,0.00660687) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38794,-0.0196159) , 
1, 11.6667, 1, 0, 0.339326,0.00188407) , 
6, 1.29156, 1, 0, 0.491177,-0.00389598)    );
  // itree = 960
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4541,-0.0153537) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548709,0.00168343) , 
7, -0.438055, 1, 0, 0.514777,-0.00484002) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.690515,0.0374313) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362819,0.00262121) , 
6, 2.32431, 1, 0, 0.455452,0.0161501) , 
1, 10.6667, 1, 0, 0.503356,-0.00079933)    );
  // itree = 961
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.436205,-0.00865859) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.950672,0.0263031) , 
4, 0.304947, 1, 0, 0.489526,-0.00818997) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403405,0.0228838) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.935567,-0.0223352) , 
4, 0.305175, 1, 0, 0.535651,0.0209874) , 
0, 96706.5, 1, 0, 0.497101,-0.00339839)    );
  // itree = 962
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.589915,0.0219628) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.239274,-0.0164318) , 
6, 2.61308, 1, 0, 0.458999,0.00997134) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785104,-0.0203319) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333162,0.00165105) , 
6, 1.25533, 1, 0, 0.502037,-0.00682457) , 
7, -0.425678, 1, 0, 0.485937,-0.000541258)    );
  // itree = 963
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.797942,0.00306542) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38999,0.017) , 
6, 1.45407, 1, 0, 0.561209,0.0152528) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400585,-0.0116816) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.260127,0.0275966) , 
8, 0.0337521, 1, 0, 0.363297,-0.00199098) , 
7, 1.00139, 1, 0, 0.513223,0.0110718)    );
  // itree = 964
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.712763,-0.00348022) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.11889,-0.0567296) , 
3, 0.047619, 1, 0, 0.62174,-0.0104829) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385035,-0.00135753) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.30694,0.0286063) , 
7, 0.999919, 1, 0, 0.364972,0.00708739) , 
1, 6.33333, 1, 0, 0.495272,-0.00182889)    );
  // itree = 965
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.610536,-0.00713743) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0514402,-0.0649077) , 
6, 2.87108, 1, 0, 0.564089,-0.0137029) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375861,0.0141769) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515075,-0.00687112) , 
0, 102379, 1, 0, 0.420192,0.0109565) , 
0, 51634.1, 1, 0, 0.498294,-0.00242769)    );
  // itree = 966
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46115,0.0249147) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511956,0.00403312) , 
2, 29177.3, 1, 0, 0.505947,0.00889387) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.135948,0.00816527) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68922,-0.0275317) , 
4, 0.135251, 1, 0, 0.457739,-0.018152) , 
1, 11.5714, 1, 0, 0.499349,0.00519213)    );
  // itree = 967
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.74311,0.00401149) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357889,0.0225163) , 
1, 5.28571, 1, 0, 0.593054,0.0148738) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521945,-0.0262859) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335442,0.00128793) , 
6, 2.0896, 1, 0, 0.390101,-0.00949335) , 
0, 48903, 1, 0, 0.490097,0.00251251)    );
  // itree = 968
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.874563,-0.0134799) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.443196,0.0134793) , 
1, 3.7619, 1, 0, 0.563498,0.0104768) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0938168,-0.00639373) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549584,-0.036196) , 
4, 0.225087, 1, 0, 0.186729,-0.0197598) , 
6, 4.31152, 1, 0, 0.506623,0.00591245)    );
  // itree = 969
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58649,0.0111358) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529535,-0.00728805) , 
8, 0.00633047, 1, 0, 0.560674,0.00361619) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102915,-0.0136029) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.606878,-0.0551768) , 
4, 0.228752, 1, 0, 0.20445,-0.0299455) , 
6, 3.81994, 1, 0, 0.492831,-0.00277569)    );
  // itree = 970
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392634,-0.00440237) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.921768,0.0199574) , 
4, 0.228961, 1, 0, 0.516347,-0.00030914) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0118456,-0.0473218) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.249749,-0.0413738) , 
4, 0.0796267, 1, 0, 0.124614,-0.0478042) , 
6, 6.76686, 1, 0, 0.492683,-0.0031782)    );
  // itree = 971
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384506,-0.00243951) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.131446,-0.0315348) , 
1, 10.9048, 1, 0, 0.344708,-0.00911312) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.897236,0.0075086) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.764582,0.0374426) , 
7, 1.27014, 1, 0, 0.881409,0.0141052) , 
4, 0.190565, 1, 0, 0.507723,-0.00206091)    );
  // itree = 972
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.449697,0.00374534) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437949,0.0328198) , 
1, 13.3333, 1, 0, 0.448962,0.00756793) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.889811,-0.0704045) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.943163,-0.00434287) , 
4, 0.323103, 1, 0, 0.927777,-0.0172859) , 
4, 0.304842, 1, 0, 0.503301,0.00474736)    );
  // itree = 973
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569806,0.0154017) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322268,-0.0113388) , 
3, 0.047619, 1, 0, 0.49491,0.0118068) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32391,0.00797538) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.589818,-0.0159449) , 
4, 0.0765713, 1, 0, 0.486451,-0.00931479) , 
7, -0.140909, 1, 0, 0.490312,0.000325902)    );
  // itree = 974
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516301,-0.000680998) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.462262,0.0154588) , 
7, 0.430687, 1, 0, 0.496199,0.0071662) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.644882,0.0452731) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389403,-0.00775604) , 
7, 0.168741, 1, 0, 0.532454,0.0385224) , 
1, 14.3333, 1, 0, 0.498432,0.00909788)    );
  // itree = 975
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547414,-0.0059456) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.212533,0.0246945) , 
8, 0.0897397, 1, 0, 0.521631,-0.00500912) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46066,0.0102729) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614548,0.0477315) , 
0, 137405, 1, 0, 0.532454,0.0413561) , 
1, 13.3333, 1, 0, 0.522414,-0.00165614)    );
  // itree = 976
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313497,-0.0176482) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248827,0.00576646) , 
8, 0.0195619, 1, 0, 0.29102,-0.0129642) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569263,0.0125364) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.932125,-0.012152) , 
5, 4499.73, 1, 0, 0.776515,0.00674422) , 
4, 0.13349, 1, 0, 0.495757,-0.00465303)    );
  // itree = 977
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.120836,-0.011179) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.194568,0.093041) , 
7, 0.391294, 1, 0, 0.156396,0.0391473) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366849,-0.0262671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557392,0.00310543) , 
8, -0.0375373, 1, 0, 0.533912,-0.000800987) , 
8, -0.0937521, 1, 0, 0.503628,0.00240361)    );
  // itree = 978
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.801108,0.00626208) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334719,-0.0101524) , 
1, 4.33333, 1, 0, 0.484758,-0.00628709) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555542,0.0431256) , 
1, 15.7619, 1, 0, 0.48689,-0.00376364)    );
  // itree = 979
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.905146,0.0186497) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286702,-0.016753) , 
6, 0.941606, 1, 0, 0.405418,-0.0167714) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.705309,0.0143311) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468478,-0.0112364) , 
1, 9.80952, 1, 0, 0.617594,0.00273572) , 
2, 63794.4, 1, 0, 0.501804,-0.00790978)    );
  // itree = 980
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343883,-0.0146762) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584094,0.00522589) , 
4, 0.0586791, 1, 0, 0.506317,0.000385043) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.451487,-0.00733619) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325754,-0.0388154) , 
7, 0.403668, 1, 0, 0.407846,-0.0228851) , 
1, 10.3333, 1, 0, 0.488104,-0.00391914)    );
  // itree = 981
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314976,-0.00344749) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.728231,0.0153467) , 
4, 0.136006, 1, 0, 0.437087,0.00368164) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.87035,-0.0906454) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.93485,-0.0115486) , 
8, -0.00949414, 1, 0, 0.914008,-0.0260246) , 
4, 0.285423, 1, 0, 0.509334,-0.00081844)    );
  // itree = 982
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.213568,-0.0503926) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0658072,0.00170461) , 
6, 2.95947, 1, 0, 0.156562,-0.0329116) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357384,0.018602) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.693749,-0.0028883) , 
4, 0.096673, 1, 0, 0.539941,0.00781805) , 
7, -1.84917, 1, 0, 0.50603,0.00421538)    );
  // itree = 983
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507902,0.00405478) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.418354,-0.0203774) , 
1, 13.0476, 1, 0, 0.503784,0.00303764) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.653975,0.0292586) , 
0, 158163, 1, 0, 0.510636,0.00438168)    );
  // itree = 984
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547947,-0.00662742) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343219,0.0178777) , 
8, 0.0238357, 1, 0, 0.493148,-0.000919747) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.192222,0.0806973) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547111,0.0139301) , 
8, -0.126517, 1, 0, 0.528813,0.0217831) , 
7, -0.144079, 1, 0, 0.512779,0.0115763)    );
  // itree = 985
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360491,-0.0378666) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542359,-0.0107786) , 
4, 0.0397355, 1, 0, 0.506159,-0.0184698) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508495,0.0137897) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.152682,-0.0207072) , 
6, 5.22209, 1, 0, 0.421684,0.00840918) , 
1, 9.80952, 1, 0, 0.485421,-0.0118711)    );
  // itree = 986
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.600298,-0.00682396) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.276168,0.00588962) , 
6, 2.61593, 1, 0, 0.502566,-0.00355026) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494243,0.032339) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47673,-0.016765) , 
1, 15.2381, 1, 0, 0.489313,0.0262338) , 
1, 11.6667, 1, 0, 0.500833,0.000343851)    );
  // itree = 987
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545266,0.00626493) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367468,-0.0119708) , 
1, 9, 1, 0, 0.49254,0.000628592) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.991547,0.0714366) , 
4, 0.360429, 1, 0, 0.512132,0.00268838)    );
  // itree = 988
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0,-0.0594164) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0565488,-0.0505928) , 
5, 812.916, 1, 0, 0.0318652,-0.0279205) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58574,-0.000636013) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.370433,0.0174221) , 
8, 0.0276451, 1, 0, 0.527956,0.00462109) , 
8, -0.119699, 1, 0, 0.498597,0.00269529)    );
  // itree = 989
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.914705,0.023271) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.205237,-0.0357516) , 
6, 0.86637, 1, 0, 0.348736,-0.0231062) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629893,0.00535109) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294135,-0.0212443) , 
7, 1.0963, 1, 0, 0.534016,-0.00113239) , 
7, -0.996742, 1, 0, 0.492199,-0.00609174)    );
  // itree = 990
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506813,-6.18579e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.30618,-0.0463444) , 
1, 13, 1, 0, 0.497648,-0.00358966) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41005,0.0302568) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.930465,-0.0371731) , 
4, 0.305175, 1, 0, 0.535809,0.0257604) , 
0, 96705.6, 1, 0, 0.503703,0.00106783)    );
  // itree = 991
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313165,-0.00429932) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.189368,-0.0397512) , 
4, 0.0547483, 1, 0, 0.275895,-0.018175) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348681,0.0296297) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.645369,0.000464428) , 
4, 0.0918454, 1, 0, 0.616763,0.00485721) , 
4, 0.0764593, 1, 0, 0.488882,-0.0037836)    );
  // itree = 992
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311968,-0.0288766) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.23841,0.00593037) , 
1, 7.66667, 1, 0, 0.277485,-0.0141784) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.573014,0.00214401) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528727,0.0180974) , 
7, 0.44238, 1, 0, 0.556885,0.0100077) , 
8, -0.038237, 1, 0, 0.500812,0.00515375)    );
  // itree = 993
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581006,0.00615846) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.291837,-0.0260515) , 
8, 0.0422374, 1, 0, 0.530929,0.00188655) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.624439,-0.0155275) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390685,0.0218099) , 
6, 1.38141, 1, 0, 0.424722,0.0207271) , 
1, 8.71429, 1, 0, 0.498667,0.00760976)    );
  // itree = 994
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508876,0.00545381) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.736482,-0.022933) , 
2, 47169.8, 1, 0, 0.625674,-0.00628554) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404407,0.014369) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.122999,-0.0265737) , 
7, 1.56728, 1, 0, 0.362819,0.0122271) , 
1, 6.90476, 1, 0, 0.492739,0.00307693)    );
  // itree = 995
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53892,0.00706968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.192152,-0.0180382) , 
6, 4.35838, 1, 0, 0.492844,0.00537558) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560015,0.0401287) , 
1, 17, 1, 0, 0.494562,0.00689063)    );
  // itree = 996
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.236122,0.0516029) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586881,0.00323962) , 
7, -1.8521, 1, 0, 0.555846,0.00823378) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248895,-0.0177657) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.964704,0.0446263) , 
4, 0.286487, 1, 0, 0.385167,-0.0132724) , 
1, 8.38095, 1, 0, 0.504433,0.00175551)    );
  // itree = 997
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.023334,-0.00958678) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312965,0.0442828) , 
5, 1138.29, 1, 0, 0.167721,0.0299154) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504013,-0.00542795) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.97472,0.0311591) , 
4, 0.323337, 1, 0, 0.553462,-0.00444024) , 
8, -0.0748369, 1, 0, 0.514995,-0.0010142)    );
  // itree = 998
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529953,-0.00473404) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47673,0.025784) , 
7, 1.38846, 1, 0, 0.526078,-0.00289426) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0450031,-0.0343971) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28058,-0.0534456) , 
5, 1408.55, 1, 0, 0.139373,-0.0362718) , 
7, 1.85206, 1, 0, 0.493524,-0.00570403)    );
  // itree = 999
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303637,0.0056041) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.658382,-0.00761988) , 
4, 0.103292, 1, 0, 0.473847,-0.00171651) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.960228,0.044527) , 
4, 0.36148, 1, 0, 0.493828,-0.000336662)    );
   return;
}
 
// Clean up
void ReadBDTG::Clear() 
{
   for (unsigned int itree=0; itree<fForest.size(); itree++) { 
      delete fForest[itree]; 
   }
}
double ReadBDTG::GetMvaValue( const std::vector<double>& inputValues ) const
{
  // classifier response value
  double retval = 0;

  // classifier response, sanity check first
  if (!IsStatusClean()) {
     std::cout << "Problem in class \"" << fClassName << "\": cannot return classifier response"
               << " because status is dirty" << std::endl;
     retval = 0;
  }
  else {
     if (IsNormalised()) {
        // normalise variables
        std::vector<double> iV;
        iV.reserve(inputValues.size());
        int ivar = 0;
        for (std::vector<double>::const_iterator varIt = inputValues.begin();
             varIt != inputValues.end(); varIt++, ivar++) {
           iV.push_back(NormVariable( *varIt, fVmin[ivar], fVmax[ivar] ));
        }
        retval = GetMvaValue__( iV );
     }
     else {
        retval = GetMvaValue__( inputValues );
     }
  }

  return retval;
}
