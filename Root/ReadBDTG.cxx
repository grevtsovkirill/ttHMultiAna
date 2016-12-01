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
-1, 0, 1, -99, 0.787623,0.0575246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0847727,-0.0830455) , 
3, -0.614686, 1, 0, 0.269534,-0.230466) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.746532,0.0493065) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.953051,0.0906101) , 
4, 0.276452, 1, 0, 0.900887,0.400887) , 
4, 0.200318, 1, 0, 0.501114,0.00111444)    );
  // itree = 1
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.7894,0.0523066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0843407,-0.0753679) , 
3, -0.61587, 1, 0, 0.2676,-0.209224) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608264,0.0143134) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.923784,0.0772388) , 
8, -0.0641057, 1, 0, 0.902326,0.362326) , 
4, 0.200113, 1, 0, 0.502131,0.00196423)    );
  // itree = 2
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.824266,0.0604932) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102158,-0.0685538) , 
1, 3.33333, 1, 0, 0.246084,-0.208682) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.646755,0.024688) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.942249,0.0744295) , 
4, 0.253254, 1, 0, 0.863449,0.298253) , 
4, 0.171676, 1, 0, 0.500728,0.000412961)    );
  // itree = 3
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.812392,0.0508214) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.094692,-0.0637439) , 
3, -0.710922, 1, 0, 0.265155,-0.172992) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69086,0.0186853) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.92753,0.0671249) , 
7, -1.42953, 1, 0, 0.901071,0.293765) , 
4, 0.200246, 1, 0, 0.498541,-0.00168891)    );
  // itree = 4
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.829184,0.0546068) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.101523,-0.0597996) , 
1, 3.2381, 1, 0, 0.247888,-0.169136) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.646761,0.020009) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.940829,0.0647191) , 
4, 0.253244, 1, 0, 0.861916,0.242704) , 
4, 0.171652, 1, 0, 0.501056,0.000668584)    );
  // itree = 5
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806901,0.0446016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0788175,-0.0589351) , 
3, -0.710922, 1, 0, 0.247682,-0.15334) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.644966,0.0180245) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.94575,0.0619298) , 
4, 0.253147, 1, 0, 0.864833,0.222171) , 
4, 0.17154, 1, 0, 0.500644,0.000577063)    );
  // itree = 6
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.931246,0.0671579) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.132712,-0.0487979) , 
1, 2.57143, 1, 0, 0.250218,-0.136098) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.8898,0.0511069) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47963,-0.0312949) , 
8, 0.0777198, 1, 0, 0.86294,0.19815) , 
4, 0.171675, 1, 0, 0.50324,0.00192956)    );
  // itree = 7
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.820821,0.04537) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.085015,-0.0535549) , 
1, 3.2381, 1, 0, 0.230094,-0.139468) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.854005,0.0462618) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.251412,-0.0634057) , 
7, 2.38255, 1, 0, 0.810548,0.160768) , 
4, 0.143177, 1, 0, 0.50013,0.000206027)    );
  // itree = 8
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.95194,0.0641345) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.673692,0.0163584) , 
1, 4.85714, 1, 0, 0.843131,0.191907) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.126031,-0.0485979) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.953092,0.0557678) , 
4, 0.285906, 1, 0, 0.310714,-0.104788) , 
3, -0.427918, 1, 0, 0.501517,0.0015387)    );
  // itree = 9
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.768551,0.0330416) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0955242,-0.0480862) , 
3, -0.520177, 1, 0, 0.288799,-0.0919) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877197,0.0364199) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996946,0.0658209) , 
5, 11.051, 1, 0, 0.926165,0.182609) , 
4, 0.228795, 1, 0, 0.498377,-0.00163605)    );
  // itree = 10
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.881924,0.048808) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519831,-0.0227683) , 
6, 3.04045, 1, 0, 0.827147,0.149578) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.105107,-0.0454346) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.927711,0.044614) , 
4, 0.257307, 1, 0, 0.305225,-0.0906317) , 
3, -0.332724, 1, 0, 0.501071,-0.000495475)    );
  // itree = 11
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.820098,0.0373843) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0853673,-0.0459139) , 
1, 3.33333, 1, 0, 0.229058,-0.102274) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243783,-0.0647645) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.85237,0.0397315) , 
7, -2.38034, 1, 0, 0.809725,0.116406) , 
4, 0.14314, 1, 0, 0.50003,-0.000225455)    );
  // itree = 12
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.886866,0.046044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533458,-0.0189462) , 
6, 2.82712, 1, 0, 0.82546,0.127324) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.121422,-0.0407584) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.953919,0.0478243) , 
4, 0.285888, 1, 0, 0.304001,-0.0774955) , 
3, -0.332603, 1, 0, 0.496927,-0.00171783)    );
  // itree = 13
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.825162,0.0347775) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0857597,-0.0419945) , 
1, 3.33333, 1, 0, 0.231259,-0.0845134) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.853092,0.0367721) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235367,-0.0607634) , 
7, 2.38028, 1, 0, 0.809893,0.10038) , 
4, 0.143135, 1, 0, 0.500662,0.00156999)    );
  // itree = 14
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.914334,0.0462047) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597449,-0.0121853) , 
6, 2.59357, 1, 0, 0.856592,0.120143) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.149261,-0.0351716) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965206,0.0484738) , 
4, 0.314459, 1, 0, 0.315632,-0.0629247) , 
3, -0.523113, 1, 0, 0.500095,-0.000499974)    );
  // itree = 15
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.933944,0.0496981) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.113989,-0.0369644) , 
1, 2.61905, 1, 0, 0.230413,-0.0746088) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235775,-0.0610428) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.856194,0.0349773) , 
7, -2.37905, 1, 0, 0.812112,0.0868052) , 
4, 0.143177, 1, 0, 0.502003,0.000753999)    );
  // itree = 16
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.951375,0.0506913) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.703685,0.00326916) , 
6, 2.61332, 1, 0, 0.911952,0.133157) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.165236,-0.0292815) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.933543,0.0362346) , 
4, 0.257323, 1, 0, 0.373813,-0.0402702) , 
3, -0.808727, 1, 0, 0.503493,0.00152195)    );
  // itree = 17
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.137847,-0.0469654) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.705645,0.0259421) , 
7, -1.74574, 1, 0, 0.578473,0.0294486) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0214973,-0.0553747) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252269,-0.0565534) , 
4, 0.143118, 1, 0, 0.0711867,-0.161369) , 
7, 2.38072, 1, 0, 0.5006,0.000156299)    );
  // itree = 18
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217759,-0.0329705) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.838256,0.0412134) , 
5, 2.97551, 1, 0, 0.405032,-0.0302321) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986454,0.0759765) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.997518,0.0569777) , 
4, 0.277454, 1, 0, 0.995549,0.154356) , 
5, 10.4061, 1, 0, 0.50048,-0.000396353)    );
  // itree = 19
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.936358,0.0471553) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.623361,-0.00169715) , 
1, 4.85714, 1, 0, 0.801668,0.0742079) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.131153,-0.0320565) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.969856,0.0439827) , 
4, 0.314463, 1, 0, 0.3,-0.0507952) , 
3, -0.142354, 1, 0, 0.49846,-0.00134392)    );
  // itree = 20
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827022,0.0286234) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0658244,-0.0397622) , 
1, 3.14286, 1, 0, 0.214136,-0.0637261) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.17338,-0.0501782) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.794829,0.0264907) , 
7, -2.37991, 1, 0, 0.739345,0.0515887) , 
4, 0.114545, 1, 0, 0.49814,-0.00137015)    );
  // itree = 21
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0740042,-0.0495623) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.689178,0.0207462) , 
7, -2.33523, 1, 0, 0.577657,0.0237126) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0221662,-0.051211) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.253889,-0.0530571) , 
4, 0.143321, 1, 0, 0.0714097,-0.128065) , 
7, 2.38119, 1, 0, 0.500996,0.000728955)    );
  // itree = 22
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0215649,-0.0644274) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.196875,-0.0369551) , 
8, -0.166294, 1, 0, 0.112283,-0.124023) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.630616,0.0159143) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0538824,-0.0574282) , 
8, 0.120899, 1, 0, 0.564808,0.0210567) , 
8, -0.0765395, 1, 0, 0.500301,0.000375693)    );
  // itree = 23
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.678017,0.0195357) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0539622,-0.040371) , 
1, 4.71429, 1, 0, 0.216103,-0.0534926) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785886,0.0233016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.106069,-0.059929) , 
7, 3.33173, 1, 0, 0.741472,0.0450152) , 
4, 0.114544, 1, 0, 0.499401,-0.000373724)    );
  // itree = 24
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.949298,0.0427394) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.702753,-0.00426284) , 
6, 2.61317, 1, 0, 0.910253,0.0839032) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283362,-0.019334) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.995987,0.0599791) , 
5, 11.7705, 1, 0, 0.369378,-0.0280742) , 
3, -0.808696, 1, 0, 0.498109,-0.00142295)    );
  // itree = 25
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233167,-0.0271178) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.862396,0.040497) , 
5, 3.3207, 1, 0, 0.401717,-0.0214949) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984229,0.0696579) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.997408,0.0541581) , 
4, 0.273423, 1, 0, 0.994998,0.110647) , 
5, 9.95625, 1, 0, 0.502391,0.000928238)    );
  // itree = 26
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986019,0.0565431) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.913049,0.0362686) , 
1, 1.04762, 1, 0, 0.952055,0.103818) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243881,-0.0177007) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.96288,0.0363796) , 
4, 0.314432, 1, 0, 0.413778,-0.0189136) , 
1, 2.14286, 1, 0, 0.499316,0.000589797)    );
  // itree = 27
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0195109,-0.0488713) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.24385,-0.044134) , 
4, 0.143076, 1, 0, 0.0681833,-0.0982317) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.705197,0.0195834) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.147644,-0.0394348) , 
7, 1.7457, 1, 0, 0.578318,0.016946) , 
7, -2.38102, 1, 0, 0.501826,-0.000324403)    );
  // itree = 28
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.992606,0.0567029) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.898454,0.031051) , 
6, 1.01555, 1, 0, 0.955404,0.0918315) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.269694,-0.0150418) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.96895,0.0378773) , 
4, 0.34301, 1, 0, 0.418613,-0.0157732) , 
1, 2.14286, 1, 0, 0.503486,0.0012404)    );
  // itree = 29
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0297588,-0.0598007) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.242587,-0.0270027) , 
8, -0.152164, 1, 0, 0.143372,-0.0862004) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694326,0.0216534) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.284674,-0.0259068) , 
8, 0.0342112, 1, 0, 0.568246,0.0166446) , 
8, -0.0634136, 1, 0, 0.498867,-0.000149179)    );
  // itree = 30
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989705,0.0550745) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.892642,0.0278747) , 
6, 1.14861, 1, 0, 0.956207,0.082995) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0990149,-0.0275084) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.691432,0.00868004) , 
4, 0.114412, 1, 0, 0.41409,-0.0150976) , 
1, 2.14286, 1, 0, 0.500306,0.000502611)    );
  // itree = 31
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.196921,-0.0283402) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.802148,0.0307736) , 
5, 2.53408, 1, 0, 0.409655,-0.0147228) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986085,0.0676163) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.997258,0.052147) , 
4, 0.273421, 1, 0, 0.995376,0.0830246) , 
5, 10.6291, 1, 0, 0.502089,0.000703013)    );
  // itree = 32
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.137394,-0.0375348) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.70442,0.0179269) , 
7, -1.74363, 1, 0, 0.578503,0.0146303) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0191396,-0.0471129) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.253317,-0.0423142) , 
4, 0.14333, 1, 0, 0.0695727,-0.0820065) , 
7, 2.38255, 1, 0, 0.501513,1.12312e-05)    );
  // itree = 33
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347421,-0.0123985) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.117351,-0.0469527) , 
6, 2.10321, 1, 0, 0.202798,-0.0647555) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.699606,0.0208176) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.206556,-0.0329264) , 
8, 0.0502107, 1, 0, 0.57691,0.0171467) , 
8, -0.0470486, 1, 0, 0.502392,0.000833035)    );
  // itree = 34
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0194248,-0.0449797) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.231166,-0.0399354) , 
4, 0.143223, 1, 0, 0.0653319,-0.0727597) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.704967,0.0157968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.145486,-0.0351689) , 
7, 1.74726, 1, 0, 0.578072,0.0117333) , 
7, -2.37924, 1, 0, 0.500225,-0.00109497)    );
  // itree = 35
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.990618,0.0558106) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.913572,0.0286089) , 
1, 1.04762, 1, 0, 0.955703,0.0702634) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.095694,-0.02549) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69303,0.00710093) , 
4, 0.114425, 1, 0, 0.414077,-0.0133449) , 
1, 2.14286, 1, 0, 0.50058,8.06761e-06)    );
  // itree = 36
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0178183,-0.0446092) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.232132,-0.0359084) , 
4, 0.143223, 1, 0, 0.0651239,-0.0650987) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.70585,0.0148435) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.147193,-0.0317968) , 
7, 1.74794, 1, 0, 0.580024,0.0117463) , 
7, -2.37827, 1, 0, 0.50107,-3.70492e-05)    );
  // itree = 37
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0294669,-0.0573888) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.267371,-0.021905) , 
8, -0.147705, 1, 0, 0.157728,-0.0621809) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696156,0.017323) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258548,-0.0245659) , 
8, 0.0391471, 1, 0, 0.570533,0.0118877) , 
8, -0.0587237, 1, 0, 0.499235,-0.000905159)    );
  // itree = 38
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.850619,0.048933) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4467,-0.0118105) , 
6, 1.0357, 1, 0, 0.593915,0.0168449) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.11467,-0.0375897) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.892867,0.0289116) , 
5, 3.25318, 1, 0, 0.295782,-0.0400553) , 
6, 3.02657, 1, 0, 0.502208,-0.000657816)    );
  // itree = 39
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25423,-0.0211148) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.912498,0.0422793) , 
5, 3.92702, 1, 0, 0.416262,-0.0116021) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989684,0.0615774) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.99821,0.0516601) , 
4, 0.300615, 1, 0, 0.99645,0.0632667) , 
5, 11.7714, 1, 0, 0.497844,-0.00107463)    );
  // itree = 40
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.988093,0.0539269) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.914827,0.0276465) , 
1, 1.04762, 1, 0, 0.954526,0.0591122) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281346,-0.011919) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.97438,0.034811) , 
4, 0.371542, 1, 0, 0.41417,-0.0115616) , 
1, 2.14286, 1, 0, 0.50072,-0.000241567)    );
  // itree = 41
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0820392,-0.0426981) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.628757,0.0102016) , 
8, -0.0953421, 1, 0, 0.555974,0.00852255) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0238388,-0.0430013) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.250096,-0.0489114) , 
4, 0.143118, 1, 0, 0.0747615,-0.0681061) , 
8, 0.102917, 1, 0, 0.500781,-0.000266416)    );
  // itree = 42
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877333,0.0501602) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471515,-0.00743064) , 
6, 0.933455, 1, 0, 0.609782,0.0181903) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.139001,-0.0311268) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.921611,0.0302941) , 
5, 3.92523, 1, 0, 0.301395,-0.0325009) , 
6, 2.71882, 1, 0, 0.498426,-0.000113859)    );
  // itree = 43
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.214827,-0.0200171) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.841451,0.0268753) , 
5, 2.97525, 1, 0, 0.405335,-0.0100273) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984527,0.0629677) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.997218,0.0500778) , 
4, 0.273421, 1, 0, 0.995025,0.0548228) , 
5, 10.4061, 1, 0, 0.500135,0.000398175)    );
  // itree = 44
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.959794,0.0372956) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333071,-0.018341) , 
3, 0.0480937, 1, 0, 0.887815,0.0410863) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475251,0.000548307) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.137952,-0.0330221) , 
7, 1.42927, 1, 0, 0.389111,-0.0113152) , 
1, 3.61905, 1, 0, 0.499252,0.000257949)    );
  // itree = 45
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0702145,-0.0434781) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.626508,0.00903456) , 
8, -0.100164, 1, 0, 0.555685,0.00708206) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0273781,-0.0401173) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.279971,-0.045572) , 
4, 0.143195, 1, 0, 0.0851346,-0.0586211) , 
8, 0.0976232, 1, 0, 0.499058,-0.000824797)    );
  // itree = 46
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806578,0.0369187) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4439,-0.0121963) , 
6, 1.20228, 1, 0, 0.610626,0.0140907) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.177089,-0.0404868) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401622,0.00456794) , 
0, 76379.2, 1, 0, 0.300853,-0.0278775) , 
6, 2.73222, 1, 0, 0.498441,-0.0011082)    );
  // itree = 47
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.653477,0.00615376) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.135423,-0.0305727) , 
1, 3.2381, 1, 0, 0.196264,-0.0358218) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.744455,0.0173571) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230873,-0.0214488) , 
7, 1.29285, 1, 0, 0.584506,0.0115713) , 
7, -1.42816, 1, 0, 0.498865,0.00111708)    );
  // itree = 48
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27271,-0.0154382) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.92377,0.0383814) , 
5, 4.46248, 1, 0, 0.40025,-0.00990866) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983877,0.0605891) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.997753,0.0500242) , 
4, 0.273421, 1, 0, 0.995399,0.0465995) , 
5, 10.4071, 1, 0, 0.496037,-0.00081392)    );
  // itree = 49
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.90343,0.030791) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.185996,-0.0349799) , 
3, 0.619201, 1, 0, 0.791838,0.0299006) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0402266,-0.0334577) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578713,0.00284676) , 
4, 0.0858621, 1, 0, 0.378948,-0.0129546) , 
1, 5, 1, 0, 0.49936,-0.000456667)    );
  // itree = 50
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.34928,-0.00694758) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.111508,-0.03517) , 
6, 1.83803, 1, 0, 0.189859,-0.0344741) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.730553,0.0140374) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.130372,-0.0268639) , 
7, 1.83781, 1, 0, 0.587725,0.0101163) , 
7, -1.42702, 1, 0, 0.501341,0.000434889)    );
  // itree = 51
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986364,0.0511234) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.914697,0.0216529) , 
1, 1.04762, 1, 0, 0.953719,0.0395504) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0857891,-0.0224644) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599089,0.00429923) , 
4, 0.0858621, 1, 0, 0.41227,-0.0065396) , 
1, 2.14286, 1, 0, 0.499715,0.000904035)    );
  // itree = 52
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0970627,-0.0345816) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629848,0.00840507) , 
8, -0.0855172, 1, 0, 0.552499,0.00597092) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.02018,-0.040493) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.161194,-0.0438456) , 
4, 0.11457, 1, 0, 0.0643954,-0.0479131) , 
8, 0.111923, 1, 0, 0.500365,0.000215616)    );
  // itree = 53
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.988149,0.051809) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.919545,0.0218666) , 
1, 1.04762, 1, 0, 0.956638,0.0370741) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387817,-0.00812173) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617908,0.0327035) , 
0, 126175, 1, 0, 0.415396,-0.00611693) , 
1, 2.14286, 1, 0, 0.502617,0.000843276)    );
  // itree = 54
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.923839,0.055269) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470574,-0.00402994) , 
6, 0.76972, 1, 0, 0.568219,0.00944193) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332894,-0.0325209) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.210886,-0.0110248) , 
3, 0.714839, 1, 0, 0.253677,-0.0324915) , 
6, 3.80824, 1, 0, 0.500468,0.000409647)    );
  // itree = 55
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983017,0.0435553) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.808901,0.00567054) , 
1, 4.85714, 1, 0, 0.942108,0.0373812) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.413699,-0.00792748) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62013,0.0324455) , 
0, 135690, 1, 0, 0.432911,-0.00683436) , 
3, -0.903924, 1, 0, 0.498855,-0.00110821)    );
  // itree = 56
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.639495,0.00290399) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.131119,-0.0284346) , 
1, 3.14286, 1, 0, 0.192006,-0.0297691) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.740022,0.0125667) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238346,-0.0188059) , 
7, 1.29284, 1, 0, 0.58527,0.0065791) , 
7, -1.42816, 1, 0, 0.499035,-0.00139132)    );
  // itree = 57
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0078474,-0.0438471) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.101865,-0.0390507) , 
4, 0.114475, 1, 0, 0.0362917,-0.0407211) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.649168,0.00725975) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0389099,-0.0385714) , 
7, 3.01669, 1, 0, 0.559679,0.0046433) , 
7, -3.33219, 1, 0, 0.49765,-0.000733048)    );
  // itree = 58
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.927027,0.0539824) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.452414,-0.00422948) , 
6, 0.765813, 1, 0, 0.54267,0.00651345) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273377,-0.0385119) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.162289,-0.0145252) , 
3, 0.809643, 1, 0, 0.20637,-0.0398573) , 
6, 5.11911, 1, 0, 0.502359,0.00095509)    );
  // itree = 59
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.833239,0.0352461) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334836,-0.0162827) , 
6, 1.11304, 1, 0, 0.487042,-0.00430417) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.748978,0.0468269) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.256337,-0.0137003) , 
6, 6.15857, 1, 0, 0.590328,0.0370658) , 
0, 113587, 1, 0, 0.500429,0.00105794)    );
  // itree = 60
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.699132,0.0111554) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0437536,-0.027053) , 
1, 4.04762, 1, 0, 0.218094,-0.0178094) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.623265,-0.00317503) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.732538,0.0263868) , 
0, 69293.6, 1, 0, 0.658524,0.0100923) , 
4, 0.0860699, 1, 0, 0.50006,5.34435e-05)    );
  // itree = 61
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.183504,-0.0198069) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.772595,0.0173472) , 
5, 2.2445, 1, 0, 0.419226,-0.00529717) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.990249,0.0540102) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.999268,0.0510806) , 
4, 0.307999, 1, 0, 0.997236,0.0332128) , 
5, 11.7701, 1, 0, 0.500599,0.000124323)    );
  // itree = 62
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.05867,-0.0245854) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528824,-0.0285196) , 
4, 0.171597, 1, 0, 0.153741,-0.0298253) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694244,0.0115886) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27402,-0.0166784) , 
8, 0.0375925, 1, 0, 0.57116,0.00614642) , 
8, -0.0602018, 1, 0, 0.500548,6.13218e-05)    );
  // itree = 63
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965513,0.0379322) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.913406,0.0163931) , 
3, -0.93531, 1, 0, 0.943928,0.0333837) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31281,-0.00789074) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.973278,0.0269015) , 
4, 0.371563, 1, 0, 0.430957,-0.00594036) , 
3, -0.903576, 1, 0, 0.497851,-0.000812299)    );
  // itree = 64
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0710952,-0.0350151) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62842,0.00637923) , 
8, -0.100711, 1, 0, 0.557909,0.00424352) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0237817,-0.0345229) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.279455,-0.0314927) , 
4, 0.142419, 1, 0, 0.0810054,-0.0327054) , 
8, 0.096994, 1, 0, 0.500145,-0.000231862)    );
  // itree = 65
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.783537,0.027666) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393137,-0.00721263) , 
6, 1.31589, 1, 0, 0.53706,0.00569135) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333774,-0.0372593) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.156006,-0.0167523) , 
3, 0.42919, 1, 0, 0.2069,-0.0352332) , 
6, 5.39687, 1, 0, 0.502078,0.00135516)    );
  // itree = 66
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.803289,0.0260105) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329039,-0.0144435) , 
6, 1.19467, 1, 0, 0.481557,-0.00440431) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.772472,0.0458966) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.272879,-0.00922528) , 
6, 6.15857, 1, 0, 0.607425,0.0343339) , 
0, 122740, 1, 0, 0.495236,-0.000194292)    );
  // itree = 67
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0644925,-0.0241796) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493749,-0.0220672) , 
4, 0.14325, 1, 0, 0.185343,-0.0258878) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69434,0.00928747) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221272,-0.0178161) , 
8, 0.0473382, 1, 0, 0.572597,0.00479961) , 
8, -0.0500629, 1, 0, 0.499123,-0.00102276)    );
  // itree = 68
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0179039,-0.0347286) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.228308,-0.0209539) , 
4, 0.1432, 1, 0, 0.0632165,-0.0258354) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.707901,0.00862304) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.143028,-0.0192617) , 
7, 1.74669, 1, 0, 0.579182,0.00538649) , 
7, -2.3805, 1, 0, 0.500949,0.000652497)    );
  // itree = 69
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.747756,0.0186259) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295353,-0.0178023) , 
6, 1.48398, 1, 0, 0.489749,-0.00503232) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0588957,-0.0236256) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.729489,0.0307551) , 
4, 0.0578427, 1, 0, 0.558387,0.025295) , 
0, 103560, 1, 0, 0.500715,-0.000187038)    );
  // itree = 70
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.707823,0.0137968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244763,-0.0260798) , 
6, 1.71163, 1, 0, 0.508278,-0.00707647) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0667154,-0.019389) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.736946,0.0246752) , 
4, 0.0858621, 1, 0, 0.479112,0.0154697) , 
0, 71380.5, 1, 0, 0.498952,0.000133239)    );
  // itree = 71
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.068303,-0.0216092) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580489,-0.018416) , 
4, 0.171611, 1, 0, 0.183453,-0.0222846) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697113,0.00760202) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.045058,-0.0308773) , 
7, 2.92489, 1, 0, 0.587487,0.0049615) , 
7, -1.42819, 1, 0, 0.498895,-0.00101271)    );
  // itree = 72
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.924759,0.0266605) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.995936,0.0447486) , 
5, 4.90706, 1, 0, 0.954712,0.0247363) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298238,-0.00679015) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.975282,0.0288149) , 
4, 0.400022, 1, 0, 0.412473,-0.0047335) , 
1, 2.14286, 1, 0, 0.49833,-6.73155e-05)    );
  // itree = 73
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.170952,-0.0191009) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.715419,0.0127805) , 
5, 1.96155, 1, 0, 0.403951,-0.00476264) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986778,0.053506) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996925,0.0456718) , 
4, 0.273423, 1, 0, 0.995126,0.0255966) , 
5, 10.2801, 1, 0, 0.499935,0.000166529)    );
  // itree = 74
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.845063,0.0250429) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338859,-0.0122513) , 
6, 1.04729, 1, 0, 0.483622,-0.00497102) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.679176,0.0356776) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.21866,-0.0181529) , 
6, 7.6785, 1, 0, 0.574011,0.0253966) , 
0, 105860, 1, 0, 0.497363,-0.000354635)    );
  // itree = 75
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.978313,0.0606964) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481476,-0.000598751) , 
6, 0.550823, 1, 0, 0.536813,0.00449542) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332898,-0.0303059) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.154296,-0.0165319) , 
3, 0.524108, 1, 0, 0.20601,-0.0276316) , 
6, 5.39687, 1, 0, 0.50181,0.00109593)    );
  // itree = 76
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.708505,0.0108653) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238144,-0.0243292) , 
6, 1.71201, 1, 0, 0.504542,-0.0079239) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0630377,-0.020618) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.745563,0.0259664) , 
4, 0.0858625, 1, 0, 0.487093,0.0155946) , 
0, 71380.8, 1, 0, 0.498969,-0.000412875)    );
  // itree = 77
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.998165,0.0510909) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.974947,0.0518949) , 
6, 0.851448, 1, 0, 0.988041,0.031442) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.140756,-0.0154049) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.625292,0.00354689) , 
4, 0.0858621, 1, 0, 0.450099,-0.00293569) , 
1, 1.80952, 1, 0, 0.496922,5.65754e-05)    );
  // itree = 78
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543972,-0.000812896) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697913,0.0360289) , 
0, 80345.4, 1, 0, 0.568618,0.00527419) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.370566,-0.0315085) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.20904,-0.00226077) , 
3, 0.428833, 1, 0, 0.253695,-0.0191378) , 
6, 3.80876, 1, 0, 0.499816,-5.91693e-05)    );
  // itree = 79
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354171,-0.00899079) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.752435,0.0123298) , 
7, -0.748908, 1, 0, 0.588488,0.00585494) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499294,0.00220371) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.130715,-0.0243386) , 
1, 4.28571, 1, 0, 0.200535,-0.0180955) , 
7, 1.42779, 1, 0, 0.501244,0.000468858)    );
  // itree = 80
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.967285,0.0340614) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.906059,0.00935556) , 
3, -0.935626, 1, 0, 0.941763,0.0227625) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.418114,-0.0082412) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471302,0.011756) , 
0, 80345, 1, 0, 0.432843,-0.00439551) , 
3, -0.903891, 1, 0, 0.498471,-0.00089334)    );
  // itree = 81
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.961823,0.0253584) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328859,-0.00836667) , 
3, 0.0480258, 1, 0, 0.889787,0.0166577) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463361,-0.0122261) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310916,0.0120956) , 
3, 0.904866, 1, 0, 0.389463,-0.00525523) , 
1, 3.61905, 1, 0, 0.501007,-0.000369899)    );
  // itree = 82
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.951892,0.0479559) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403015,-0.00779506) , 
6, 0.669953, 1, 0, 0.484729,-0.00345627) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.872285,0.0511338) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445471,0.00872067) , 
6, 4.03071, 1, 0, 0.652718,0.0285699) , 
0, 135690, 1, 0, 0.499373,-0.000664449)    );
  // itree = 83
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00987654,-0.0337368) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.101939,-0.0299217) , 
4, 0.114414, 1, 0, 0.0382579,-0.0238741) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26243,-0.00835745) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.715701,0.0077567) , 
4, 0.0860283, 1, 0, 0.562739,0.00360373) , 
7, -3.33345, 1, 0, 0.501197,0.000379529)    );
  // itree = 84
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.253623,-0.00941148) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.704177,0.00863868) , 
4, 0.0861194, 1, 0, 0.550522,0.00400502) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0149025,-0.0371522) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.168935,-0.0300406) , 
4, 0.114796, 1, 0, 0.0642045,-0.0263581) , 
8, 0.111296, 1, 0, 0.499053,0.000791572)    );
  // itree = 85
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986835,0.0512181) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332051,-0.00533072) , 
1, 1.80952, 1, 0, 0.389601,-0.00440423) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.962358,0.0109514) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989814,0.0416303) , 
3, 0.52407, 1, 0, 0.974977,0.016298) , 
4, 0.371481, 1, 0, 0.498577,-0.00055019)    );
  // itree = 86
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.931108,0.0315452) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.949747,0.0196165) , 
4, 0.0575692, 1, 0, 0.94501,0.0229122) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53551,-0.00787281) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309685,0.00831637) , 
3, 0.909347, 1, 0, 0.435593,-0.00330631) , 
3, -0.903718, 1, 0, 0.501666,9.43024e-05)    );
  // itree = 87
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264287,-0.0110298) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.684981,0.00739585) , 
7, -1.11098, 1, 0, 0.561422,0.00362872) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0968343,-0.00429962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0218433,-0.0430714) , 
1, 5.90476, 1, 0, 0.0391148,-0.0220852) , 
7, 3.3335, 1, 0, 0.500356,0.00062236)    );
  // itree = 88
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.36009,-0.0107436) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.686437,0.00924398) , 
8, -0.0199718, 1, 0, 0.563137,0.00289932) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0409054,-0.0232907) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355646,-0.0233877) , 
4, 0.143355, 1, 0, 0.119719,-0.0210712) , 
8, 0.0779687, 1, 0, 0.49826,-0.000607831)    );
  // itree = 89
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0217269,-0.0256745) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252002,-0.0283904) , 
4, 0.143377, 1, 0, 0.0742221,-0.0207635) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552516,-0.00145213) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565893,0.0160921) , 
0, 80345, 1, 0, 0.555951,0.00340108) , 
8, -0.0973851, 1, 0, 0.500216,0.000605293)    );
  // itree = 90
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.132243,-0.0170881) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68117,0.00646123) , 
7, -1.74626, 1, 0, 0.563084,0.0035291) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00860318,-0.0354202) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0993453,-0.0252658) , 
4, 0.114795, 1, 0, 0.0354317,-0.0198676) , 
7, 3.33262, 1, 0, 0.500568,0.000757093)    );
  // itree = 91
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.963548,0.0490451) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463645,-0.0020202) , 
6, 0.609036, 1, 0, 0.527687,0.00208158) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258554,-0.0315014) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.153415,-0.00998159) , 
3, 0.80961, 1, 0, 0.195715,-0.0258364) , 
6, 6.01287, 1, 0, 0.500015,-0.000245549)    );
  // itree = 92
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.903077,0.0185972) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.19821,-0.0165307) , 
3, 0.619211, 1, 0, 0.791425,0.0128225) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.444252,-0.0133345) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320891,0.0134589) , 
3, 0.904867, 1, 0, 0.382068,-0.00467769) , 
1, 4.28571, 1, 0, 0.50048,0.000384488)    );
  // itree = 93
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.895511,0.018512) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.198079,-0.0253843) , 
3, 0.714452, 1, 0, 0.79528,0.0116474) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442568,-0.011582) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319806,0.0113402) , 
3, 0.904867, 1, 0, 0.380874,-0.00425204) , 
1, 4.28571, 1, 0, 0.501056,0.000358956)    );
  // itree = 94
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.869325,0.0126629) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26564,-0.00588502) , 
1, 3.61905, 1, 0, 0.401505,-0.00352188) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.966183,0.0127797) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98929,0.0400578) , 
3, 0.143391, 1, 0, 0.977908,0.015753) , 
4, 0.400052, 1, 0, 0.498592,-0.0002753)    );
  // itree = 95
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.24857,-0.010021) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893053,0.0211087) , 
5, 3.75945, 1, 0, 0.397095,-0.00384419) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.977336,0.0432223) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996881,0.0441233) , 
4, 0.250596, 1, 0, 0.994033,0.0180385) , 
5, 9.86162, 1, 0, 0.499975,-7.27883e-05)    );
  // itree = 96
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.99094,0.030716) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.852357,0.0243136) , 
3, -0.80876, 1, 0, 0.955925,0.0173577) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499956,-0.00774468) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305612,0.0084241) , 
3, 0.904805, 1, 0, 0.411256,-0.00342658) , 
1, 2.14286, 1, 0, 0.498573,-9.46195e-05)    );
  // itree = 97
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221863,-0.0109353) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.747155,0.00878899) , 
7, -1.29253, 1, 0, 0.588385,0.0048019) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.663483,0.00731833) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.138433,-0.0195177) , 
1, 3.33333, 1, 0, 0.202094,-0.0138908) , 
7, 1.42809, 1, 0, 0.501787,0.000611413)    );
  // itree = 98
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.910687,0.0213312) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.118656,-0.0145458) , 
3, -0.898634, 1, 0, 0.218794,-0.0085024) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.624502,-0.0039269) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721384,0.0204044) , 
0, 63194.5, 1, 0, 0.659821,0.00639705) , 
4, 0.0860338, 1, 0, 0.501514,0.00104888)    );
  // itree = 99
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893174,0.030041) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420559,-0.00320245) , 
6, 0.893973, 1, 0, 0.526281,0.00235215) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.190998,-0.00851496) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.188541,-0.0331766) , 
1, 10.8571, 1, 0, 0.189799,-0.023416) , 
6, 6.01332, 1, 0, 0.497997,0.000186151)    );
  // itree = 100
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.74004,0.0117007) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.290546,-0.0126619) , 
6, 1.48863, 1, 0, 0.485131,-0.00379289) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.730841,0.0324509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.261987,-0.0095681) , 
6, 5.56949, 1, 0, 0.566845,0.0167124) , 
0, 102164, 1, 0, 0.498616,-0.000408986)    );
  // itree = 101
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0107315,-0.0290383) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0990721,-0.0264464) , 
4, 0.114234, 1, 0, 0.0382295,-0.0184432) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.685672,0.00632794) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.278049,-0.00907636) , 
7, 1.11302, 1, 0, 0.562681,0.00289222) , 
7, -3.33043, 1, 0, 0.50097,0.000381738)    );
  // itree = 102
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0626531,-0.0157326) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559352,-0.0227607) , 
4, 0.171792, 1, 0, 0.170268,-0.0170404) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697953,0.00664159) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235772,-0.0145714) , 
8, 0.043222, 1, 0, 0.572284,0.00204345) , 
8, -0.0543912, 1, 0, 0.499147,-0.00142838)    );
  // itree = 103
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.73337,0.0102043) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266265,-0.0151335) , 
6, 1.5554, 1, 0, 0.497516,-0.00445652) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0640828,-0.0189536) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.668421,0.0202989) , 
4, 0.0574812, 1, 0, 0.504423,0.0128825) , 
0, 80345, 1, 0, 0.499335,0.000109911)    );
  // itree = 104
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549715,0.00558062) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.034834,-0.0210338) , 
1, 5.57143, 1, 0, 0.215314,-0.00841908) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696719,0.00711692) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0588401,-0.036623) , 
8, 0.157971, 1, 0, 0.661379,0.00631145) , 
4, 0.0860341, 1, 0, 0.501034,0.00101633)    );
  // itree = 105
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98752,0.0518994) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314515,-0.00469468) , 
1, 1.80952, 1, 0, 0.373602,-0.00368125) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.963428,0.0119358) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98658,0.0350929) , 
3, 0.809628, 1, 0, 0.972663,0.0119375) , 
4, 0.343011, 1, 0, 0.498545,-0.000423733)    );
  // itree = 106
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0391139,-0.0166835) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431081,-0.0249945) , 
4, 0.172001, 1, 0, 0.111534,-0.0159561) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.660582,-0.00289431) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384755,0.0155234) , 
3, 0.904814, 1, 0, 0.564868,0.00235743) , 
8, -0.0765395, 1, 0, 0.500605,-0.000238649)    );
  // itree = 107
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.692632,0.00736928) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238212,-0.0165598) , 
6, 1.78755, 1, 0, 0.500546,-0.00434296) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602748,0.0190921) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.218791,-0.0144533) , 
6, 5.67777, 1, 0, 0.495574,0.00929821) , 
0, 73869.8, 1, 0, 0.499034,-0.000194325)    );
  // itree = 108
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.698528,0.00669862) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0427331,-0.0163158) , 
1, 4.71429, 1, 0, 0.215972,-0.00773774) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.701251,0.00598875) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0785613,-0.0287305) , 
8, 0.135883, 1, 0, 0.659986,0.00493949) , 
4, 0.0858607, 1, 0, 0.499774,0.000365212)    );
  // itree = 109
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.910726,0.0160333) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.117071,-0.0122916) , 
3, -0.900221, 1, 0, 0.216466,-0.00711576) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.625736,-0.000109652) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.74932,0.0173555) , 
0, 73870, 1, 0, 0.662084,0.0059026) , 
4, 0.0859873, 1, 0, 0.500175,0.00117256)    );
  // itree = 110
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316526,-0.0051919) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.981299,0.0370116) , 
5, 7.92222, 1, 0, 0.39018,-0.00339064) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.966895,0.0101107) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984986,0.0339944) , 
0, 58040.6, 1, 0, 0.976726,0.0120506) , 
4, 0.371545, 1, 0, 0.497476,-0.000565996)    );
  // itree = 111
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550476,-0.00218585) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.611471,0.0219483) , 
0, 63194.4, 1, 0, 0.566692,0.00377083) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.378427,-0.0250613) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208401,-0.00284642) , 
3, 0.333638, 1, 0, 0.252256,-0.0137093) , 
6, 3.81492, 1, 0, 0.498702,-8.87002e-06)    );
  // itree = 112
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599842,0.00443995) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.256632,-0.0157472) , 
6, 5.13229, 1, 0, 0.562901,0.00264031) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0102017,-0.0286593) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0996622,-0.0229718) , 
4, 0.114894, 1, 0, 0.0367218,-0.0150646) , 
7, 3.33418, 1, 0, 0.49978,0.000516405)    );
  // itree = 113
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.998523,0.0522646) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.966821,0.0468536) , 
6, 1.16244, 1, 0, 0.98906,0.0182732) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440816,-0.00560829) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470729,0.00678721) , 
0, 71380.8, 1, 0, 0.451109,-0.00227472) , 
1, 1.80952, 1, 0, 0.498046,-0.000481897)    );
  // itree = 114
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.972104,0.0480564) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504684,-0.00102798) , 
6, 0.577068, 1, 0, 0.568303,0.00255849) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361893,-0.0230181) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.218351,0.000754043) , 
3, 0.524027, 1, 0, 0.261054,-0.0113925) , 
6, 3.79489, 1, 0, 0.501319,-0.000482974)    );
  // itree = 115
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.284115,-0.00553256) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.962718,0.0298633) , 
5, 6.11476, 1, 0, 0.374106,-0.00291413) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.961542,0.0105176) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984546,0.0311625) , 
3, 0.238444, 1, 0, 0.972762,0.01086) , 
4, 0.34299, 1, 0, 0.50005,-1.63368e-05)    );
  // itree = 116
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.115664,0.0066278) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0157732,-0.0413644) , 
3, 0.809995, 1, 0, 0.0375188,-0.0141281) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.657412,-0.00218141) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387628,0.0139812) , 
3, 0.904804, 1, 0, 0.564453,0.00236619) , 
7, -3.33284, 1, 0, 0.501407,0.000392674)    );
  // itree = 117
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0426006,-0.0273962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.600978,0.00308468) , 
7, -3.33219, 1, 0, 0.5458,0.00143518) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0147148,-0.0351535) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.121511,-0.0297925) , 
4, 0.114796, 1, 0, 0.047639,-0.0196506) , 
8, 0.12556, 1, 0, 0.498454,-0.00056884)    );
  // itree = 118
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.907377,0.0127457) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.11852,-0.0120952) , 
3, -0.903413, 1, 0, 0.211857,-0.00736212) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0280728,-0.0476126) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.685596,0.00498518) , 
8, -0.203816, 1, 0, 0.658344,0.00405117) , 
4, 0.0860219, 1, 0, 0.496057,-9.72812e-05)    );
  // itree = 119
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.949495,0.0220058) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298288,-0.00407364) , 
1, 2.14286, 1, 0, 0.404987,-0.0022253) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.979038,0.0140534) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.980018,0.0271844) , 
1, 4.85714, 1, 0, 0.97976,0.0120055) , 
4, 0.400092, 1, 0, 0.501478,0.000163711)    );
  // itree = 120
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.907236,0.0257205) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389255,-0.00486092) , 
6, 0.839717, 1, 0, 0.490942,-0.000985485) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.708514,0.0312348) , 
0, 171609, 1, 0, 0.50101,0.000362305)    );
  // itree = 121
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.979797,0.05306) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482896,-0.000607086) , 
6, 0.541869, 1, 0, 0.536207,0.00223514) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28583,-0.0211431) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.169867,-0.0057648) , 
3, 0.80961, 1, 0, 0.217388,-0.0148655) , 
6, 5.15952, 1, 0, 0.497745,0.000172135)    );
  // itree = 122
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954272,0.0378589) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.406385,-0.00916045) , 
6, 0.65821, 1, 0, 0.516643,-0.00480571) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577251,0.0183283) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217734,-0.0137414) , 
6, 5.22189, 1, 0, 0.472034,0.00805632) , 
0, 65843.1, 1, 0, 0.500385,-0.00011803)    );
  // itree = 123
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.648898,0.00908916) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.131943,-0.0150921) , 
1, 3.42857, 1, 0, 0.191174,-0.00886563) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.679844,-0.00187941) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.410229,0.0148263) , 
3, 0.904814, 1, 0, 0.58801,0.00271744) , 
7, -1.4276, 1, 0, 0.501359,0.000188205)    );
  // itree = 124
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.478228,-0.00482087) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.6378,0.00786414) , 
8, -0.0149044, 1, 0, 0.58367,0.00391151) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.658175,0.00616337) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0981411,-0.0194777) , 
3, -0.140724, 1, 0, 0.205104,-0.00901222) , 
7, 1.42779, 1, 0, 0.498075,0.000989394)    );
  // itree = 125
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.6526,-0.00266376) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371515,0.0125792) , 
3, 0.904814, 1, 0, 0.553981,0.00152639) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0239123,-0.0217204) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.265377,-0.0236408) , 
4, 0.143195, 1, 0, 0.0776381,-0.014874) , 
8, 0.102917, 1, 0, 0.498778,-0.000374237)    );
  // itree = 126
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0607118,-0.012355) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.462577,-0.0172012) , 
4, 0.143083, 1, 0, 0.174174,-0.0123325) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697698,0.00569691) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238295,-0.0110536) , 
8, 0.0437847, 1, 0, 0.574641,0.00211049) , 
8, -0.0538533, 1, 0, 0.501409,-0.000530642)    );
  // itree = 127
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575498,-0.00246857) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535816,0.0104455) , 
0, 64440.7, 1, 0, 0.560859,0.00211662) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0113817,-0.0212521) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0981919,-0.0252173) , 
4, 0.114891, 1, 0, 0.0379058,-0.0139679) , 
7, 3.33474, 1, 0, 0.499153,0.000218708)    );
  // itree = 128
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.734751,0.00759056) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0336179,-0.0236548) , 
1, 4.71429, 1, 0, 0.225373,-0.0104806) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309065,-0.0113104) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.654451,0.00642858) , 
8, -0.0375101, 1, 0, 0.580155,0.00296812) , 
4, 0.0572956, 1, 0, 0.497842,-0.000152129)    );
  // itree = 129
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.99803,0.0444186) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965253,0.0453376) , 
6, 1.01508, 1, 0, 0.986242,0.0156759) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437783,-0.00534084) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482877,0.00634458) , 
0, 75588.3, 1, 0, 0.451896,-0.00243366) , 
1, 1.80952, 1, 0, 0.498602,-0.000850738)    );
  // itree = 130
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516712,-0.00118105) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.647574,0.0177455) , 
0, 80345.6, 1, 0, 0.542033,0.00202861) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343857,-0.0201336) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.165836,-0.00803384) , 
3, 0.42919, 1, 0, 0.214008,-0.0133138) , 
6, 5.15862, 1, 0, 0.503139,0.000209485)    );
  // itree = 131
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27822,-0.00953488) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605148,0.00463343) , 
8, -0.0317183, 1, 0, 0.519242,0.00142222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00882613,-0.0520196) , 
8, 0.292843, 1, 0, 0.501809,0.000580714)    );
  // itree = 132
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.655375,-0.00242314) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387886,0.0123048) , 
3, 0.904821, 1, 0, 0.562717,0.00161607) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00821058,-0.030264) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0915614,-0.0230625) , 
4, 0.114586, 1, 0, 0.0328914,-0.0137071) , 
7, 3.3335, 1, 0, 0.500191,-0.000192279)    );
  // itree = 133
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76778,0.00686216) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288299,-0.00511509) , 
1, 5, 1, 0, 0.428135,-0.00223923) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.978999,0.0112783) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984992,0.0306887) , 
1, 4.42857, 1, 0, 0.983348,0.011482) , 
4, 0.457148, 1, 0, 0.498667,-0.000496143)    );
  // itree = 134
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.997004,0.0461823) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.964259,0.0414971) , 
6, 1.14861, 1, 0, 0.987034,0.0143188) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.909973,0.010937) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407442,-0.00265858) , 
3, -0.903891, 1, 0, 0.453816,-0.00144367) , 
1, 1.80952, 1, 0, 0.499766,-8.53516e-05)    );
  // itree = 135
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525734,-0.00292509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.573195,0.0144542) , 
0, 64440.7, 1, 0, 0.539871,0.00167093) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364601,-0.0195829) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.16,-0.00811599) , 
3, 0.23892, 1, 0, 0.211762,-0.0132747) , 
6, 5.15858, 1, 0, 0.502014,-5.35051e-05)    );
  // itree = 136
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0105691,-0.0515294) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.228478,-0.00660817) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.675349,0.00368008) , 
4, 0.0858621, 1, 0, 0.516805,0.000706361) , 
8, -0.275569, 1, 0, 0.498097,-0.000114344)    );
  // itree = 137
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.873578,0.0175401) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379663,-0.00323992) , 
6, 0.957226, 1, 0, 0.494228,0.000135063) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.707182,0.0306329) , 
0, 191035, 1, 0, 0.501147,0.000984338)    );
  // itree = 138
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.943526,0.0278586) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400841,-0.00443842) , 
6, 0.69401, 1, 0, 0.485375,-0.00189076) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.623692,-0.00402519) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.655243,0.0337344) , 
3, 0.619466, 1, 0, 0.645324,0.0137382) , 
0, 135690, 1, 0, 0.499018,-0.000557677)    );
  // itree = 139
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550757,0.0054083) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0855461,-0.0233164) , 
3, 0.240422, 1, 0, 0.189475,-0.00934723) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.676666,-0.00166989) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40408,0.0145736) , 
3, 0.904814, 1, 0, 0.583842,0.00269149) , 
7, -1.42758, 1, 0, 0.497867,6.69553e-05)    );
  // itree = 140
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.942798,0.0286724) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.467855,-0.0001327) , 
6, 0.706399, 1, 0, 0.549976,0.00262998) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316272,-0.0165195) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.179471,-0.00450145) , 
3, 0.714709, 1, 0, 0.227732,-0.0105777) , 
6, 4.60983, 1, 0, 0.501647,0.000649133)    );
  // itree = 141
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0177267,-0.0227808) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.160377,-0.0255634) , 
4, 0.114855, 1, 0, 0.0644897,-0.0143515) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.651007,-0.00255686) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379484,0.0112721) , 
3, 0.904803, 1, 0, 0.555535,0.00120753) , 
8, -0.102568, 1, 0, 0.50135,-0.000509367)    );
  // itree = 142
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.991274,0.0256508) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.770043,0.0186683) , 
3, -0.713395, 1, 0, 0.956095,0.0110992) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.873555,0.0113527) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383074,-0.00262262) , 
3, -0.903891, 1, 0, 0.415333,-0.00148772) , 
1, 2.14286, 1, 0, 0.50207,0.000531188)    );
  // itree = 143
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.679292,-0.00115789) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40594,0.0122163) , 
3, 0.904805, 1, 0, 0.586512,0.00245497) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.105894,-0.0152019) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.908866,0.0158425) , 
5, 5.35349, 1, 0, 0.206877,-0.00835534) , 
7, 1.42948, 1, 0, 0.500787,1.39159e-05)    );
  // itree = 144
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528895,-7.65781e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.622574,0.0165435) , 
0, 71380.3, 1, 0, 0.550229,0.0032509) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431195,-0.0191132) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.17748,-0.00833763) , 
3, -0.0469609, 1, 0, 0.229669,-0.011873) , 
6, 4.42601, 1, 0, 0.498284,0.000800123)    );
  // itree = 145
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0428078,-0.0208976) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.607888,0.00347825) , 
7, -3.33284, 1, 0, 0.552673,0.00221106) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.088659,-0.0224157) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0203145,0.00034723) , 
7, 3.33565, 1, 0, 0.069143,-0.0113727) , 
8, 0.111923, 1, 0, 0.500798,0.000753736)    );
  // itree = 146
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233301,-0.0075937) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0695167,0.0204757) , 
1, 11.6667, 1, 0, 0.2146,-0.00414119) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.743474,0.00596151) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.746522,-0.0194003) , 
1, 14.5714, 1, 0, 0.743677,0.00454022) , 
4, 0.114425, 1, 0, 0.501914,0.000573232)    );
  // itree = 147
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.868676,0.014384) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.201888,-0.0156427) , 
3, 0.524069, 1, 0, 0.699428,0.00667057) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.651331,-0.0140686) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.318908,0.00223026) , 
3, -0.421643, 1, 0, 0.381149,-0.00329067) , 
1, 5.14286, 1, 0, 0.500544,0.000446076)    );
  // itree = 148
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.71397,0.00650233) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.318507,-0.00608585) , 
6, 1.66523, 1, 0, 0.488315,-0.00107326) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696619,0.0225961) , 
0, 176763, 1, 0, 0.497279,-0.000197207)    );
  // itree = 149
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.992446,0.0246204) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.848589,0.0161582) , 
3, -0.808276, 1, 0, 0.956082,0.00930057) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499538,-0.004752) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305667,0.00430571) , 
3, 0.904837, 1, 0, 0.410541,-0.00219687) , 
1, 2.14286, 1, 0, 0.498416,-0.000344867)    );
  // itree = 150
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68077,0.00423329) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22386,-0.0162153) , 
6, 1.89882, 1, 0, 0.517495,-0.00412248) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0695044,-0.0202553) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.623213,0.0126139) , 
4, 0.0574323, 1, 0, 0.47403,0.00579924) , 
0, 65842.9, 1, 0, 0.501818,-0.000544058)    );
  // itree = 151
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.116858,-0.0127781) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.729956,0.00450299) , 
7, -1.83689, 1, 0, 0.586796,0.00185434) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.476562,0.00229572) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.088077,-0.0217828) , 
3, 0.619758, 1, 0, 0.20481,-0.00787093) , 
7, 1.42807, 1, 0, 0.500694,-0.000337807)    );
  // itree = 152
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597971,0.00309649) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0887336,-0.0167775) , 
8, 0.106972, 1, 0, 0.550555,0.00194848) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00514684,-0.0350901) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0785153,-0.0256001) , 
4, 0.114521, 1, 0, 0.0269983,-0.0138563) , 
7, 4.28611, 1, 0, 0.501329,0.000462488)    );
  // itree = 153
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.23902,-0.00570548) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0703021,0.0163976) , 
1, 11.6667, 1, 0, 0.219667,-0.00285785) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515908,-0.00965616) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.796734,0.00837059) , 
8, -0.0321786, 1, 0, 0.740561,0.00452457) , 
4, 0.114545, 1, 0, 0.501032,0.00112982)    );
  // itree = 154
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.992117,0.0229844) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.846883,0.0159445) , 
3, -0.808744, 1, 0, 0.95614,0.00883898) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.33026,-0.00294428) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98193,0.0268549) , 
4, 0.457224, 1, 0, 0.415138,-0.00142287) , 
1, 2.14286, 1, 0, 0.50207,0.000226068)    );
  // itree = 155
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.988533,0.0455964) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362843,-0.00349772) , 
1, 1.71429, 1, 0, 0.418014,-0.00259923) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.982172,0.00335902) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.980064,0.0222453) , 
1, 3.33333, 1, 0, 0.980495,0.00795641) , 
4, 0.428669, 1, 0, 0.501462,-0.00103323)    );
  // itree = 156
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0233338,-0.0344142) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590208,0.00225572) , 
8, -0.160908, 1, 0, 0.545606,0.00104378) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0504244,-0.0309569) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0196786,-0.000875606) , 
7, 2.38034, 1, 0, 0.0400751,-0.0129379) , 
8, 0.13192, 1, 0, 0.499825,-0.000222412)    );
  // itree = 157
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323839,-0.00346409) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.979793,0.0245833) , 
5, 7.27879, 1, 0, 0.418024,-0.00180385) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983498,0.00566832) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983188,0.025656) , 
1, 3.33333, 1, 0, 0.983251,0.00892332) , 
4, 0.428612, 1, 0, 0.501481,-0.000219957)    );
  // itree = 158
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0259386,-0.0339501) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591238,0.00255651) , 
8, -0.159424, 1, 0, 0.545828,0.00134967) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0501706,-0.0282332) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0202871,0.000536954) , 
7, 2.38207, 1, 0, 0.0396072,-0.0109313) , 
8, 0.133373, 1, 0, 0.50006,0.000239324)    );
  // itree = 159
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542661,0.00429446) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0369331,-0.0144283) , 
1, 5.57143, 1, 0, 0.213834,-0.00485797) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.628497,-0.00209432) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.71589,0.0105161) , 
0, 63194.4, 1, 0, 0.660357,0.00267285) , 
4, 0.0858607, 1, 0, 0.499452,-4.08786e-05)    );
  // itree = 160
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0215467,-0.00770549) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0290232,-0.0311569) , 
8, -0.066228, 1, 0, 0.0263304,-0.0110856) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.642535,-0.00168846) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351583,0.00883694) , 
3, 0.904814, 1, 0, 0.537151,0.00114854) , 
7, -5.23596, 1, 0, 0.500384,0.000267972)    );
  // itree = 161
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.670933,-0.000375078) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404591,0.0113602) , 
3, 0.904821, 1, 0, 0.580526,0.00273779) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.226306,0.0153178) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0294023,-0.0290771) , 
3, 0.619955, 1, 0, 0.0652959,-0.00753167) , 
7, 2.38119, 1, 0, 0.501836,0.00116936)    );
  // itree = 162
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.997449,0.0431647) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.961157,0.043757) , 
6, 1.18029, 1, 0, 0.987037,0.0117971) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.36411,-0.00270014) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.980354,0.0195165) , 
4, 0.42863, 1, 0, 0.454797,-0.00144718) , 
1, 1.80952, 1, 0, 0.501714,-0.000279696)    );
  // itree = 163
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.969543,0.035045) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504775,0.000916245) , 
6, 0.577068, 1, 0, 0.568099,0.00281721) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.391366,-0.0154886) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208128,0.000455047) , 
3, 0.333638, 1, 0, 0.255865,-0.0064641) , 
6, 3.79489, 1, 0, 0.500205,0.000799046)    );
  // itree = 164
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579295,-0.00693839) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419459,0.00390528) , 
0, 44877.3, 1, 0, 0.490492,-0.0011453) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.391997,0.0171865) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986461,0.0214536) , 
4, 0.286249, 1, 0, 0.694057,0.0138541) , 
0, 164141, 1, 0, 0.501089,-0.00036447)    );
  // itree = 165
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.991027,0.0445023) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.930392,0.00840659) , 
3, -0.967177, 1, 0, 0.943401,0.00940196) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.802303,-0.00775268) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.317315,-6.46389e-05) , 
3, -0.541105, 1, 0, 0.433974,-0.00244458) , 
3, -0.903718, 1, 0, 0.50014,-0.000905916)    );
  // itree = 166
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989992,0.0543631) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474527,-0.0013833) , 
6, 0.438818, 1, 0, 0.509195,1.69118e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181151,-0.0219711) , 
6, 8.40124, 1, 0, 0.49802,-0.000683583)    );
  // itree = 167
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.673655,-0.00289768) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407725,0.0104644) , 
3, 0.904814, 1, 0, 0.583147,0.000601582) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522414,0.00203122) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0892298,-0.0201484) , 
3, 0.429638, 1, 0, 0.200331,-0.00757691) , 
7, 1.42753, 1, 0, 0.497467,-0.0012289)    );
  // itree = 168
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.643921,0.001324) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.201691,-0.0168563) , 
6, 2.20273, 1, 0, 0.517082,-0.00438878) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.619953,-0.00791481) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409365,0.0148649) , 
3, 0.333638, 1, 0, 0.472496,0.00374048) , 
0, 65842.7, 1, 0, 0.501083,-0.00147177)    );
  // itree = 169
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.80408,0.0118816) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175809,-0.0238564) , 
3, 0.904801, 1, 0, 0.697378,0.00632873) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.649102,-0.0129154) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314969,0.00118707) , 
3, -0.421643, 1, 0, 0.378439,-0.00364949) , 
1, 5.42857, 1, 0, 0.497037,6.09248e-05)    );
  // itree = 170
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.84326,0.00832222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.196424,-0.0128837) , 
3, 0.714415, 1, 0, 0.69839,0.00363933) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434967,-0.0100587) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328114,0.00956537) , 
3, 0.905045, 1, 0, 0.37947,-0.0029456) , 
1, 5.42857, 1, 0, 0.499085,-0.000475842)    );
  // itree = 171
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965165,0.0331733) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464993,0.000253894) , 
6, 0.609442, 1, 0, 0.528261,0.00202254) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.209772,0.0119976) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.180021,-0.0262196) , 
1, 9.04762, 1, 0, 0.192312,-0.0106514) , 
6, 6.01332, 1, 0, 0.500583,0.000978335)    );
  // itree = 172
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247461,-0.00738257) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0576998,0.00870562) , 
1, 10.7143, 1, 0, 0.215711,-0.00409659) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827662,-0.00186478) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.604798,0.0108156) , 
3, 0.809611, 1, 0, 0.740875,0.00264629) , 
4, 0.114418, 1, 0, 0.499455,-0.000453436)    );
  // itree = 173
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0141929,-0.0458234) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.598617,0.00257123) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.137537,-0.0164916) , 
8, 0.0715111, 1, 0, 0.524864,0.000445534) , 
8, -0.249149, 1, 0, 0.503601,-0.000271743)    );
  // itree = 174
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527278,-0.000798223) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578781,0.0126275) , 
0, 63194.1, 1, 0, 0.542859,0.0027517) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0392665,-0.000378036) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.662537,-0.0164908) , 
4, 0.172099, 1, 0, 0.223042,-0.008708) , 
6, 4.8377, 1, 0, 0.499228,0.0011883)    );
  // itree = 175
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.761822,0.00142358) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22248,-0.0103493) , 
3, -0.0469609, 1, 0, 0.411653,-0.00444751) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.772532,0.00982449) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411285,-0.00211479) , 
7, 0.521939, 1, 0, 0.551848,0.00296058) , 
7, -0.475825, 1, 0, 0.498461,0.000139534)    );
  // itree = 176
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572517,0.00372239) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0188328,-0.0188635) , 
3, 0.239911, 1, 0, 0.220688,-0.00385897) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.436828,-0.00799483) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.726196,0.0058092) , 
8, -0.0307005, 1, 0, 0.660482,0.0026606) , 
4, 0.0860283, 1, 0, 0.501047,0.000297115)    );
  // itree = 177
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552619,-0.00595221) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405209,0.00627635) , 
0, 51353.5, 1, 0, 0.485711,-0.000661839) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.180705,0.0268441) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.941718,0.00308631) , 
4, 0.171947, 1, 0, 0.644208,0.0131141) , 
0, 135690, 1, 0, 0.499261,0.00051588)    );
  // itree = 178
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.851066,0.0102326) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.184385,-0.0178288) , 
3, 0.714415, 1, 0, 0.700174,0.00395778) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431993,-0.00823804) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329097,0.00798688) , 
3, 0.905224, 1, 0, 0.379034,-0.00249145) , 
1, 5.42857, 1, 0, 0.499429,-7.36504e-05)    );
  // itree = 179
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996083,0.0179667) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.915548,0.0116038) , 
1, 1.61905, 1, 0, 0.943983,0.00855515) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.980933,0.0445385) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405949,-0.00262934) , 
1, 1.61905, 1, 0, 0.432357,-0.00177707) , 
3, -0.903576, 1, 0, 0.499073,-0.000429752)    );
  // itree = 180
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.739114,0.00663079) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294138,-0.00616101) , 
6, 1.52887, 1, 0, 0.486896,-0.00119078) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0549695,-0.0100223) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.746541,0.0153755) , 
4, 0.0574745, 1, 0, 0.579905,0.00898339) , 
0, 106685, 1, 0, 0.500795,0.000329594)    );
  // itree = 181
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.231139,-0.00473471) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.741107,0.00651636) , 
4, 0.114425, 1, 0, 0.501881,0.00168285) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.108919,0.00514627) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.825084,-0.0269855) , 
4, 0.171947, 1, 0, 0.49702,-0.0122058) , 
1, 12.6667, 1, 0, 0.501375,0.000238174)    );
  // itree = 182
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592502,-0.00842029) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403393,0.00248008) , 
0, 42668.4, 1, 0, 0.487537,-0.00240305) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.159432,0.0190324) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.930125,-0.000660448) , 
4, 0.171978, 1, 0, 0.60488,0.00822407) , 
0, 117761, 1, 0, 0.501653,-0.00112464)    );
  // itree = 183
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484099,0.00367995) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0242864,-0.0230539) , 
1, 6.28571, 1, 0, 0.235279,-0.00589203) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.641296,0.00410245) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.159892,-0.010162) , 
8, 0.0779687, 1, 0, 0.578461,0.00256245) , 
4, 0.0574748, 1, 0, 0.497999,0.000580228)    );
  // itree = 184
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98612,0.0494383) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507347,0.000118368) , 
6, 0.474623, 1, 0, 0.550258,0.00155892) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.039303,-0.00724622) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.677332,-0.0123561) , 
4, 0.171763, 1, 0, 0.230101,-0.00914514) , 
6, 4.5962, 1, 0, 0.502668,-3.22074e-05)    );
  // itree = 185
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.982792,0.0295408) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918223,0.00332584) , 
3, -0.953425, 1, 0, 0.941598,0.00623413) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420676,-0.00340178) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.70005,0.0180999) , 
0, 176762, 1, 0, 0.433434,-0.00254592) , 
3, -0.903568, 1, 0, 0.498778,-0.0014169)    );
  // itree = 186
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.874569,0.0130067) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347345,-0.00994428) , 
3, 0.333767, 1, 0, 0.668643,0.00365265) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497114,-0.0146606) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.263939,0.00678657) , 
3, 0.238628, 1, 0, 0.327584,-0.0036226) , 
6, 2.03431, 1, 0, 0.499685,4.85483e-05)    );
  // itree = 187
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.805274,0.00792745) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.179709,-0.0185624) , 
3, 0.90481, 1, 0, 0.697482,0.00371347) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457175,-0.00887148) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32554,0.00586719) , 
3, 0.81009, 1, 0, 0.37966,-0.00270212) , 
1, 5.42857, 1, 0, 0.499024,-0.000292623)    );
  // itree = 188
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557936,0.00866826) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0909359,-0.0190205) , 
3, 0.238444, 1, 0, 0.198097,-0.00547264) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877866,-0.00370519) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.412119,0.00744855) , 
3, -0.618335, 1, 0, 0.586489,0.00316205) , 
7, -1.4261, 1, 0, 0.501401,0.00127039)    );
  // itree = 189
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.963605,0.0306937) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409889,-0.00301178) , 
6, 0.621261, 1, 0, 0.485583,-0.000954552) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.152184,0.0170322) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.933554,0.00265614) , 
4, 0.171635, 1, 0, 0.611971,0.00856463) , 
0, 122740, 1, 0, 0.499192,7.0435e-05)    );
  // itree = 190
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517301,-0.00306516) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46284,0.00698673) , 
0, 65430.1, 1, 0, 0.498614,5.50539e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540953,-0.0178063) , 
1, 15.4286, 1, 0, 0.50022,-0.000684034)    );
  // itree = 191
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616258,-0.00611844) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420885,0.00340422) , 
0, 39453.2, 1, 0, 0.490555,-0.000125797) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.716429,0.0234111) , 
0, 176762, 1, 0, 0.500035,0.000637706)    );
  // itree = 192
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437446,-0.00278364) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.571307,0.00420155) , 
8, -0.00886619, 1, 0, 0.515669,0.00131856) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0100291,-0.0460505) , 
8, 0.311975, 1, 0, 0.49999,0.000787923)    );
  // itree = 193
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559827,-0.00151234) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592463,0.00962618) , 
0, 57626, 1, 0, 0.569969,0.00148333) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298407,-0.0113704) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.224581,0.00415411) , 
3, 0.904821, 1, 0, 0.259244,-0.00534648) , 
6, 3.79441, 1, 0, 0.50198,-1.10816e-05)    );
  // itree = 194
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.927561,0.0078152) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298451,-0.00311156) , 
3, -0.903413, 1, 0, 0.374275,-0.00218148) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.976744,0.00186983) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.969621,0.0148226) , 
1, 5, 1, 0, 0.971602,0.00546574) , 
4, 0.342919, 1, 0, 0.497473,-0.000604259)    );
  // itree = 195
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599138,0.00388911) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0264067,-0.0216263) , 
1, 5.71429, 1, 0, 0.233374,-0.00699716) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0162665,-0.040506) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602137,0.00299128) , 
8, -0.275467, 1, 0, 0.582466,0.00239157) , 
4, 0.0574335, 1, 0, 0.501759,0.000220983)    );
  // itree = 196
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9824,0.028959) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.917665,0.00307935) , 
3, -0.953435, 1, 0, 0.940709,0.00585108) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489673,-0.00023036) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.211744,-0.011992) , 
6, 4.07049, 1, 0, 0.432078,-0.00222411) , 
3, -0.903576, 1, 0, 0.498733,-0.00116587)    );
  // itree = 197
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581691,-0.00135275) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529924,0.00912268) , 
1, 8.33333, 1, 0, 0.56799,0.0014488) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489586,-0.0113502) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.200773,-0.00232062) , 
3, -0.332496, 1, 0, 0.252426,-0.00518581) , 
6, 3.81472, 1, 0, 0.499606,1.10667e-05)    );
  // itree = 198
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.223145,-0.00414815) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.739497,0.00317141) , 
4, 0.114544, 1, 0, 0.497379,0.000193143) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519522,-0.0149198) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530085,-0.00974185) , 
3, 0.905113, 1, 0, 0.525005,-0.0136261) , 
1, 14.4762, 1, 0, 0.498818,-0.00052638)    );
  // itree = 199
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893344,0.0106775) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381537,-0.00365238) , 
6, 0.881773, 1, 0, 0.488845,-0.00162992) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.704398,0.0161442) , 
0, 176762, 1, 0, 0.498139,-0.00100695)    );
  // itree = 200
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.998014,0.0305256) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.973607,0.0486125) , 
6, 1.01508, 1, 0, 0.989312,0.00992397) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.166405,-0.0100698) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540498,0.000145302) , 
7, -1.42787, 1, 0, 0.453748,-0.0015773) , 
1, 1.80952, 1, 0, 0.500207,-0.000579595)    );
  // itree = 201
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350836,-0.00477013) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.755328,0.00518589) , 
7, -0.747147, 1, 0, 0.58739,0.00151238) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.652781,0.00419369) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0990576,-0.0149678) , 
3, -0.140724, 1, 0, 0.203141,-0.00588479) , 
7, 1.4295, 1, 0, 0.501217,-0.000146533)    );
  // itree = 202
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.276416,-0.00827919) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599236,0.00154313) , 
8, -0.0322887, 1, 0, 0.514832,-0.000639097) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0102506,-0.0452756) , 
8, 0.29216, 1, 0, 0.497152,-0.00114451)    );
  // itree = 203
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414824,-0.000185978) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399583,-0.0163749) , 
1, 11.3333, 1, 0, 0.412705,-0.00230358) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.729313,0.00656117) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102945,-0.00775549) , 
7, 2.01846, 1, 0, 0.555738,0.00373882) , 
7, -0.475825, 1, 0, 0.501592,0.00145145)    );
  // itree = 204
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.770419,0.00133295) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364676,-0.0110827) , 
6, 2.59357, 1, 0, 0.656415,-0.00342114) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.267415,-0.00741391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337297,0.0201953) , 
3, 0.990935, 1, 0, 0.302242,0.0024107) , 
3, 0.809648, 1, 0, 0.498837,-0.000826447)    );
  // itree = 205
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294462,-0.00356355) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971419,0.0189867) , 
5, 6.85325, 1, 0, 0.373671,-0.00227275) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.961114,0.00316356) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984299,0.0235691) , 
3, 0.428823, 1, 0, 0.971952,0.00459807) , 
4, 0.343009, 1, 0, 0.497722,-0.000848115)    );
  // itree = 206
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563331,-0.00392009) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383067,0.00768911) , 
0, 48718.6, 1, 0, 0.497661,0.000132462) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0631787,-0.00789656) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.666892,0.0125788) , 
4, 0.0575242, 1, 0, 0.504014,0.00734071) , 
0, 80345.2, 1, 0, 0.499323,0.00201826)    );
  // itree = 207
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374707,-0.000747328) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336252,-0.0125261) , 
1, 14.4762, 1, 0, 0.372935,-0.00148681) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.963073,0.00336066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.978983,0.0219272) , 
0, 52761.4, 1, 0, 0.972522,0.00596645) , 
4, 0.342926, 1, 0, 0.496924,5.44533e-05)    );
  // itree = 208
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.771142,-0.00765082) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.957539,0.00825565) , 
4, 0.228755, 1, 0, 0.851667,-0.00360573) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0291877,-0.0194391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383276,0.00589231) , 
7, -3.33182, 1, 0, 0.320653,0.00303412) , 
3, -0.523113, 1, 0, 0.501154,0.000777114)    );
  // itree = 209
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.915195,0.00705364) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.119002,-0.00754771) , 
3, -0.903413, 1, 0, 0.214523,-0.00398649) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.654304,0.00270117) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.687075,-0.0104928) , 
1, 15, 1, 0, 0.656345,0.00176105) , 
4, 0.0858625, 1, 0, 0.49724,-0.000308702)    );
  // itree = 210
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405361,0.000473461) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.779895,0.00907148) , 
7, -0.521233, 1, 0, 0.552906,0.00392959) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42178,-0.000984187) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.435253,-0.0141049) , 
1, 12.6667, 1, 0, 0.42315,-0.00212787) , 
7, 0.476513, 1, 0, 0.50214,0.00155967)    );
  // itree = 211
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.899378,0.0129446) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387011,-0.00303071) , 
6, 0.859811, 1, 0, 0.491737,-0.000931105) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.702833,0.0170667) , 
0, 171609, 1, 0, 0.501292,-0.000305755)    );
  // itree = 212
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0328178,-0.0147903) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0125538,-0.0489154) , 
1, 7.38095, 1, 0, 0.0224306,-0.0114485) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.618817,0.00419688) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364617,-0.00366858) , 
7, 0.750657, 1, 0, 0.529918,0.00162054) , 
7, -6.18671, 1, 0, 0.502269,0.000908498)    );
  // itree = 213
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217799,-0.00251476) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.741713,0.00476992) , 
4, 0.114582, 1, 0, 0.499907,0.00166571) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569536,-0.0154716) , 
1, 16.6667, 1, 0, 0.5018,0.0011506)    );
  // itree = 214
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.887563,0.0111877) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383675,-0.00263038) , 
6, 0.907702, 1, 0, 0.493464,-0.000622235) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.729689,0.0240771) , 
0, 191035, 1, 0, 0.501382,1.45595e-05)    );
  // itree = 215
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550047,0.00364371) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0116443,-0.0291305) , 
3, 0.429693, 1, 0, 0.23639,-0.00509303) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0136719,-0.0439237) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601335,0.00219463) , 
8, -0.240218, 1, 0, 0.577682,0.00138697) , 
4, 0.0574746, 1, 0, 0.498271,-0.000120779)    );
  // itree = 216
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491132,-0.000991608) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.655875,0.0131615) , 
0, 99873.8, 1, 0, 0.514463,0.000556136) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181857,-0.0144768) , 
6, 7.549, 1, 0, 0.49895,-3.94687e-05)    );
  // itree = 217
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.871115,-0.00274424) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374754,0.00372055) , 
3, -0.61804, 1, 0, 0.549164,0.00124728) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0713746,0.0125625) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00905638,-0.0444344) , 
3, 0.905255, 1, 0, 0.0264378,-0.00746121) , 
7, 4.28686, 1, 0, 0.499746,0.000423992)    );
  // itree = 218
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.994991,0.00525902) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98324,0.0481843) , 
3, -0.903591, 1, 0, 0.989436,0.00743319) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.430661,-0.00310158) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.587907,0.00615294) , 
0, 113587, 1, 0, 0.452913,-0.00196802) , 
1, 1.66667, 1, 0, 0.4997,-0.0011482)    );
  // itree = 219
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521663,-0.00307526) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538708,0.00690589) , 
0, 63194.1, 1, 0, 0.527306,-6.79047e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0291689,-0.00219487) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549981,-0.0145262) , 
4, 0.14342, 1, 0, 0.194678,-0.00898633) , 
6, 6.01287, 1, 0, 0.499524,-0.000812781)    );
  // itree = 220
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.928719,0.0161016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.946296,0.00535814) , 
4, 0.0575804, 1, 0, 0.941708,0.00571478) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356382,-0.00235205) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.982191,0.0184573) , 
4, 0.457221, 1, 0, 0.433427,-0.00129861) , 
3, -0.903718, 1, 0, 0.499216,-0.000390842)    );
  // itree = 221
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.025748,-0.0263102) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.587649,0.00187461) , 
8, -0.165492, 1, 0, 0.544659,0.000975637) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.127861,0.0169459) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0167155,-0.0396817) , 
3, 0.90517, 1, 0, 0.0486786,-0.00557301) , 
8, 0.128119, 1, 0, 0.497386,0.000351475)    );
  // itree = 222
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.885827,0.00959413) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.207529,-0.0113036) , 
3, 0.333637, 1, 0, 0.698971,0.00334485) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432431,-0.00696897) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327347,0.00705879) , 
3, 0.905176, 1, 0, 0.378087,-0.00196597) , 
1, 5.42857, 1, 0, 0.498179,2.16311e-05)    );
  // itree = 223
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.948217,0.00963116) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347111,-0.00223631) , 
1, 2.14286, 1, 0, 0.444587,-0.00129561) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.979942,0.0224769) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.985829,0.0149392) , 
7, -0.399669, 1, 0, 0.983833,0.00567648) , 
4, 0.485694, 1, 0, 0.499064,-0.000591265)    );
  // itree = 224
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.916792,0.00314719) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.744846,-0.0103464) , 
3, -0.840283, 1, 0, 0.852046,-0.00377412) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0789577,0.00489242) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.857022,-0.00517104) , 
4, 0.200112, 1, 0, 0.315542,0.00123636) , 
3, -0.522974, 1, 0, 0.498333,-0.000470755)    );
  // itree = 225
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.833187,-0.00571321) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.176164,5.59811e-05) , 
3, -0.617264, 1, 0, 0.374536,-0.00196424) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.973159,0.0124139) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.969347,-0.0018606) , 
1, 10.7143, 1, 0, 0.97221,0.00382505) , 
4, 0.34299, 1, 0, 0.500931,-0.000739923)    );
  // itree = 226
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.236309,-0.00627004) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0662549,0.0109439) , 
1, 11.6667, 1, 0, 0.216419,-0.00333651) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.741855,0.00437775) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.747705,-0.013564) , 
1, 15, 1, 0, 0.742243,0.00302833) , 
4, 0.114425, 1, 0, 0.501856,0.000118576)    );
  // itree = 227
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5659,-0.0035367) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42937,0.00422097) , 
0, 48715.4, 1, 0, 0.495123,0.000249171) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.724339,0.0193891) , 
0, 191035, 1, 0, 0.502594,0.000716497)    );
  // itree = 228
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.643417,0.00272334) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.250901,-0.00456653) , 
1, 5.42857, 1, 0, 0.400233,-0.00199498) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.977076,-0.0164962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.979431,0.0187517) , 
1, 5, 1, 0, 0.978782,0.00380425) , 
4, 0.400101, 1, 0, 0.496408,-0.00103094)    );
  // itree = 229
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288445,-0.00365592) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.766476,0.00589962) , 
7, -1.0179, 1, 0, 0.553481,0.00207601) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986209,0.0419129) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372962,-0.00426649) , 
1, 1.80952, 1, 0, 0.417626,-0.00280488) , 
7, 0.478366, 1, 0, 0.500611,0.000176554)    );
  // itree = 230
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.828231,0.00412757) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.45481,-0.00827427) , 
1, 5.42857, 1, 0, 0.655392,-0.00315992) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262866,-0.0111681) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340171,0.0207969) , 
3, 0.990934, 1, 0, 0.301373,0.0011256) , 
3, 0.809608, 1, 0, 0.498878,-0.00126527)    );
  // itree = 231
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0372089,-0.00739507) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.416377,-0.0166283) , 
4, 0.17179, 1, 0, 0.107273,-0.00661611) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680861,0.00455852) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376279,-0.00580829) , 
8, 0.0206243, 1, 0, 0.562705,0.000876125) , 
8, -0.0780176, 1, 0, 0.498986,-0.000172093)    );
  // itree = 232
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583969,0.00197843) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.241789,-0.00685885) , 
6, 5.39641, 1, 0, 0.550162,0.00104074) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0208963,-0.00200568) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0311203,-0.0289713) , 
8, -0.0470486, 1, 0, 0.0271733,-0.00822836) , 
7, 4.28422, 1, 0, 0.501202,0.000173016)    );
  // itree = 233
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.867195,-0.00358513) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.373757,0.00281088) , 
3, -0.61803, 1, 0, 0.54781,0.000409083) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0301699,-0.0271995) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0219694,0.0159941) , 
8, 0.101917, 1, 0, 0.0279407,-0.00745898) , 
7, 4.2863, 1, 0, 0.499349,-0.000324356)    );
  // itree = 234
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572196,0.00254724) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456992,-0.00651019) , 
8, 0.0292964, 1, 0, 0.548317,0.000490793) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0146718,-0.0131483) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.113444,-0.0178874) , 
4, 0.114517, 1, 0, 0.0456088,-0.00712615) , 
8, 0.126655, 1, 0, 0.501164,-0.000223661)    );
  // itree = 235
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543449,0.00930335) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.071768,-0.0204664) , 
3, 0.0495624, 1, 0, 0.153282,-0.00565773) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697815,0.00333958) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258446,-0.0052052) , 
8, 0.038851, 1, 0, 0.571351,0.00122047) , 
8, -0.0585432, 1, 0, 0.49996,4.59218e-05)    );
  // itree = 236
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.913405,0.013825) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.391098,-0.00176346) , 
6, 0.815775, 1, 0, 0.49027,-2.78037e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399375,0.0145482) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9836,0.0223059) , 
4, 0.286115, 1, 0, 0.698398,0.0120543) , 
0, 164141, 1, 0, 0.501141,0.000603251)    );
  // itree = 237
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.725045,0.00156914) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221815,-0.00801989) , 
3, 0.238573, 1, 0, 0.414247,-0.00248964) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.688463,-0.000763867) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359363,0.0102246) , 
3, 0.809642, 1, 0, 0.552291,0.00235602) , 
7, -0.475962, 1, 0, 0.499905,0.000517154)    );
  // itree = 238
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.703598,-0.00142261) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401483,0.0089441) , 
3, 0.809643, 1, 0, 0.586144,0.00151148) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349747,0.00379428) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0897875,-0.0218066) , 
3, 0.904871, 1, 0, 0.204293,-0.00378437) , 
7, 1.42796, 1, 0, 0.500539,0.000324229)    );
  // itree = 239
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555999,0.00784833) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0837681,-0.017561) , 
3, 0.238443, 1, 0, 0.190035,-0.00447345) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.645901,0.00308121) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22546,-0.0117849) , 
8, 0.0611327, 1, 0, 0.584541,0.00124087) , 
7, -1.42731, 1, 0, 0.496808,-2.9923e-05)    );
  // itree = 240
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28191,-0.00621087) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602936,0.00243913) , 
8, -0.0317126, 1, 0, 0.519005,0.000433159) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0120551,-0.0393583) , 
8, 0.292843, 1, 0, 0.501317,8.02436e-06)    );
  // itree = 241
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.998358,0.043489) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971451,0.0440691) , 
6, 1.14909, 1, 0, 0.9904,0.00820934) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494365,0.000377337) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203831,-0.00843326) , 
6, 4.83789, 1, 0, 0.451481,-0.000687953) , 
1, 1.71429, 1, 0, 0.49796,7.93957e-05)    );
  // itree = 242
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986469,0.040112) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468683,-0.00123332) , 
6, 0.481819, 1, 0, 0.510205,-0.000160491) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.182064,-0.0148682) , 
6, 9.01208, 1, 0, 0.501661,-0.000509315)    );
  // itree = 243
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614031,0.00697367) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0262075,-0.0186611) , 
1, 5.28571, 1, 0, 0.234894,-0.00447409) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0275255,-0.0262654) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.60588,0.00182734) , 
7, -6.18582, 1, 0, 0.578398,0.00107449) , 
4, 0.0574323, 1, 0, 0.497986,-0.000224384)    );
  // itree = 244
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.277768,-0.00407244) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.928745,0.00906493) , 
5, 4.55664, 1, 0, 0.405667,-0.00201486) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.997115,0.0368398) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.992344,-0.000791914) , 
0, 117761, 1, 0, 0.995921,0.00408155) , 
5, 10.6281, 1, 0, 0.501195,-0.0010282)    );
  // itree = 245
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0165916,-0.0306363) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.595682,0.00229458) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.131796,-0.00678335) , 
8, 0.0742564, 1, 0, 0.522951,0.00121019) , 
8, -0.246079, 1, 0, 0.501627,0.000806191)    );
  // itree = 246
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.92827,0.00358636) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62332,-0.0101727) , 
6, 2.08669, 1, 0, 0.851868,-0.00299297) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.024607,-0.023876) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349384,0.00499381) , 
4, 0.0290851, 1, 0, 0.32054,0.00273517) , 
3, -0.523139, 1, 0, 0.500877,0.000790986)    );
  // itree = 247
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785138,-0.00731517) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.955573,0.0058477) , 
4, 0.200222, 1, 0, 0.868764,-0.00304442) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0868769,0.0059281) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.857628,-0.00511961) , 
4, 0.200098, 1, 0, 0.324356,0.00183746) , 
3, -0.61803, 1, 0, 0.497434,0.000285415)    );
  // itree = 248
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.939098,0.00353854) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.653601,-0.0112937) , 
6, 1.99864, 1, 0, 0.86769,-0.00353667) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506163,0.00696549) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.29752,0.000372683) , 
3, -0.00158314, 1, 0, 0.325853,0.00161969) , 
3, -0.61796, 1, 0, 0.499824,-3.58961e-05)    );
  // itree = 249
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486042,0.00284167) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0199841,-0.0246154) , 
1, 6.28571, 1, 0, 0.234038,-0.00566114) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547991,-0.00127086) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.668587,0.00683478) , 
0, 80345.5, 1, 0, 0.578269,0.000608757) , 
4, 0.0574335, 1, 0, 0.498046,-0.000852439)    );
  // itree = 250
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0920562,0.0147179) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0129917,-0.0420732) , 
3, 0.905233, 1, 0, 0.0362044,-0.00626911) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244016,-0.00822084) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.627169,0.00180774) , 
8, -0.047957, 1, 0, 0.560561,0.000306479) , 
7, -3.33285, 1, 0, 0.498177,-0.000475834)    );
  // itree = 251
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5892,-0.00632246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404178,0.00350433) , 
0, 43616.5, 1, 0, 0.487578,-0.000982241) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.624228,-0.00574116) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614856,0.020154) , 
3, 0.619612, 1, 0, 0.617802,0.00569421) , 
0, 122740, 1, 0, 0.501659,-0.00026032)    );
  // itree = 252
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.251795,-0.00552256) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0421997,0.011746) , 
1, 11, 1, 0, 0.216709,-0.00219092) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.795547,-0.00108453) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.487391,0.00774543) , 
3, 0.714411, 1, 0, 0.658981,0.0021429) , 
4, 0.0859891, 1, 0, 0.499705,0.000582154)    );
  // itree = 253
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954727,0.00355631) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.907185,0.0118218) , 
0, 62561.3, 1, 0, 0.941742,0.00455384) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.979244,0.0312847) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.406633,-0.00185525) , 
1, 1.71429, 1, 0, 0.433235,-0.00120582) , 
3, -0.903924, 1, 0, 0.499696,-0.000453054)    );
  // itree = 254
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.97423,0.0294805) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.997805,0.0197259) , 
2, 34365.9, 1, 0, 0.989133,0.0048306) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26812,-0.00245885) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.953674,0.00404587) , 
4, 0.285877, 1, 0, 0.450513,-0.00131063) , 
1, 1.80952, 1, 0, 0.497213,-0.000778157)    );
  // itree = 255
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328938,-0.00461269) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.598529,0.00109609) , 
8, -0.0242403, 1, 0, 0.517028,-0.000400503) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00955509,-0.0427227) , 
8, 0.298611, 1, 0, 0.500065,-0.000750862)    );
  // itree = 256
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584543,-0.00682865) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403059,0.00541868) , 
0, 44271.9, 1, 0, 0.48604,-0.000356953) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.408195,0.0113721) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98977,-0.00455171) , 
5, 9.95852, 1, 0, 0.627837,0.00744441) , 
0, 126175, 1, 0, 0.500741,0.000451854)    );
  // itree = 257
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.990735,0.00730521) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.759684,0.0138962) , 
3, -0.71358, 1, 0, 0.954,0.00420341) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.130945,0.00163388) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.834803,-0.00435645) , 
4, 0.171694, 1, 0, 0.411389,-0.000765763) , 
1, 2.14286, 1, 0, 0.498338,3.05077e-05)    );
  // itree = 258
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.596463,0.00485454) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0145037,-0.0214) , 
3, 0.145166, 1, 0, 0.231519,-0.0030778) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.642045,0.00404437) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0509941,-0.0119186) , 
7, 3.33385, 1, 0, 0.582528,0.0028281) , 
4, 0.0572999, 1, 0, 0.501199,0.00145969)    );
  // itree = 259
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248787,0.00069854) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.782553,-0.00547995) , 
4, 0.17155, 1, 0, 0.406352,-0.00150861) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9673,-0.00710246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986445,0.0263837) , 
0, 54321.9, 1, 0, 0.978329,0.00319863) , 
4, 0.400052, 1, 0, 0.500179,-0.000736442)    );
  // itree = 260
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.182239,0.0179458) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.695354,-0.00430395) , 
7, -2.3805, 1, 0, 0.659337,-0.00312665) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.270496,-0.00548567) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335435,0.0177796) , 
3, 0.990936, 1, 0, 0.302614,0.00224213) , 
3, 0.809608, 1, 0, 0.500205,-0.000731672)    );
  // itree = 261
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00847734,-0.008675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0345924,-0.0311126) , 
4, 0.086202, 1, 0, 0.0202436,-0.00818003) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613324,0.00182905) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359497,-0.0035121) , 
7, 0.748389, 1, 0, 0.524485,0.000154458) , 
7, -6.18936, 1, 0, 0.496483,-0.00030838)    );
  // itree = 262
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.981533,0.00211303) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.802531,0.00658944) , 
1, 3.2381, 1, 0, 0.913639,0.00443276) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.671954,-0.00840829) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307565,0.00179367) , 
3, -0.378047, 1, 0, 0.367074,-0.000873415) , 
3, -0.808696, 1, 0, 0.498365,0.000401189)    );
  // itree = 263
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.240764,-0.00198356) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581646,0.00372821) , 
4, 0.0574748, 1, 0, 0.500584,0.00228184) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.556303,-0.0100213) , 
1, 15.4286, 1, 0, 0.50274,0.00178877)    );
  // itree = 264
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.109237,0.0102342) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0157797,-0.0310847) , 
3, 0.810555, 1, 0, 0.0364469,-0.00539208) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577491,0.00218925) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230813,-0.0103671) , 
6, 7.65853, 1, 0, 0.563797,0.00153514) , 
7, -3.33219, 1, 0, 0.501502,0.000716836)    );
  // itree = 265
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00557743,-0.0207902) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0363777,-0.0247175) , 
4, 0.0838565, 1, 0, 0.0197088,-0.00716241) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0142473,-0.0326348) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552743,0.0013125) , 
8, -0.239774, 1, 0, 0.531494,0.000806499) , 
7, -6.18906, 1, 0, 0.502643,0.000357259)    );
  // itree = 266
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986259,0.038574) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46747,-0.00168571) , 
6, 0.466827, 1, 0, 0.507423,-0.00063444) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.184903,-0.0115444) , 
6, 8.99917, 1, 0, 0.498129,-0.000902598)    );
  // itree = 267
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564714,-0.00443863) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4258,0.00297852) , 
0, 48716.4, 1, 0, 0.492736,-0.000680249) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.735782,0.0144877) , 
0, 191035, 1, 0, 0.500968,-0.000312746)    );
  // itree = 268
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983798,0.0319982) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368063,-0.0030497) , 
1, 1.71429, 1, 0, 0.411183,-0.00190612) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.690147,0.00413379) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0396678,-0.00666326) , 
7, 3.0161, 1, 0, 0.555643,0.00273771) , 
7, -0.475825, 1, 0, 0.501003,0.000981252)    );
  // itree = 269
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.793562,0.00915037) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41625,-0.00187788) , 
6, 1.29165, 1, 0, 0.571354,0.0015029) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.377259,-0.0126601) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.204855,0.00092077) , 
3, 0.428833, 1, 0, 0.253301,-0.00494773) , 
6, 3.79441, 1, 0, 0.50233,0.00010298)    );
  // itree = 270
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337682,-0.00748022) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0486418,0.00492476) , 
6, 2.58017, 1, 0, 0.212643,-0.00291435) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827877,-0.000835246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603974,0.00880681) , 
3, 0.809648, 1, 0, 0.740065,0.00228311) , 
4, 0.114626, 1, 0, 0.498865,-9.37874e-05)    );
  // itree = 271
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.880455,0.00947804) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523783,-0.00547829) , 
6, 2.08669, 1, 0, 0.775345,0.00284764) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266442,-0.00913605) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310938,0.00752974) , 
3, 0.959203, 1, 0, 0.291881,-0.00107316) , 
3, 0.143234, 1, 0, 0.498974,0.000606331)    );
  // itree = 272
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.902491,0.00120077) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562997,-0.00763979) , 
6, 2.60768, 1, 0, 0.837815,-0.00196767) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.478907,0.00968945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.300098,0.00161479) , 
3, -0.0198387, 1, 0, 0.315068,0.00221329) , 
3, -0.427918, 1, 0, 0.501611,0.000721308)    );
  // itree = 273
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.952164,0.0104842) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344505,-0.00271976) , 
1, 2.14286, 1, 0, 0.443313,-0.00166429) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989817,0.0130579) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.968902,0.019764) , 
6, 2.62841, 1, 0, 0.983581,0.00479575) , 
4, 0.485777, 1, 0, 0.498917,-0.000999437)    );
  // itree = 274
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697486,0.0268027) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696833,-0.000138933) , 
4, 0.0290286, 1, 0, 0.696893,0.00191205) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497054,-0.00504516) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316683,0.00136032) , 
3, 0.620181, 1, 0, 0.37909,-0.00183608) , 
1, 5.42857, 1, 0, 0.498052,-0.000433056)    );
  // itree = 275
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.756315,0.00503061) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367494,-0.00153494) , 
6, 1.47024, 1, 0, 0.517278,0.000551169) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.180264,-0.0118737) , 
6, 7.54854, 1, 0, 0.501687,8.40579e-05)    );
  // itree = 276
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.573259,-0.00641242) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382817,0.00341269) , 
0, 46083.4, 1, 0, 0.49557,-0.00221744) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0739881,-0.0246013) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559761,0.00700525) , 
4, 0.0288778, 1, 0, 0.503963,0.00349289) , 
0, 80345.2, 1, 0, 0.497774,-0.000718106)    );
  // itree = 277
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514359,-0.00135026) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4669,0.00471241) , 
0, 66685.5, 1, 0, 0.498102,0.000425891) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.587579,-0.0116361) , 
1, 16.2857, 1, 0, 0.500517,9.53425e-05)    );
  // itree = 278
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.60537,-0.00511061) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426935,0.00272936) , 
0, 40809.2, 1, 0, 0.493669,-0.000274637) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.724117,0.013871) , 
0, 191035, 1, 0, 0.501437,5.59331e-05)    );
  // itree = 279
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235259,-0.00542756) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0670627,0.0123401) , 
1, 11.6667, 1, 0, 0.21613,-0.00250435) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.740057,0.00392454) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.73826,-0.010653) , 
1, 12.6667, 1, 0, 0.739836,0.00175676) , 
4, 0.114542, 1, 0, 0.499219,-0.00020101)    );
  // itree = 280
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.51034,0.000817462) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.734253,0.0136759) , 
0, 191035, 1, 0, 0.518114,0.00101654) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.011396,-0.0289199) , 
8, 0.286385, 1, 0, 0.500246,0.000734261)    );
  // itree = 281
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.753096,0.00489724) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399407,-0.00385556) , 
6, 1.47089, 1, 0, 0.566085,-0.00026475) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.290291,-0.00956801) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.225925,0.00217519) , 
3, 0.904821, 1, 0, 0.256013,-0.00444936) , 
6, 3.79489, 1, 0, 0.498104,-0.00118219)    );
  // itree = 282
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345725,-0.00733753) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0411722,0.00577444) , 
6, 2.59353, 1, 0, 0.215592,-0.00257846) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.701944,0.0035347) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581837,-0.00209107) , 
7, 0.474107, 1, 0, 0.65766,0.00135781) , 
4, 0.0858625, 1, 0, 0.49971,-4.86132e-05)    );
  // itree = 283
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.973599,0.0304222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503626,0.000692597) , 
6, 0.577047, 1, 0, 0.568602,0.00188499) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0594863,0.000323891) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.767422,-0.0106717) , 
4, 0.20048, 1, 0, 0.249447,-0.00383592) , 
6, 3.79489, 1, 0, 0.499163,0.000640288)    );
  // itree = 284
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.864606,0.00465166) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163594,-0.0200477) , 
3, 0.904784, 1, 0, 0.791446,0.00184937) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238129,-0.0030655) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.975317,0.0107682) , 
4, 0.37153, 1, 0, 0.379082,-0.00175702) , 
1, 4.28571, 1, 0, 0.499011,-0.000708165)    );
  // itree = 285
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.226995,-0.00409723) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0688965,0.0132191) , 
1, 12.9524, 1, 0, 0.214944,-0.00198171) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.741281,0.00513126) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.736363,-0.00487852) , 
1, 10.8571, 1, 0, 0.740226,0.00255053) , 
4, 0.114425, 1, 0, 0.499511,0.000473589)    );
  // itree = 286
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986999,0.00827475) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.844324,0.0104688) , 
1, 3.14286, 1, 0, 0.944116,0.00626754) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167609,0.00159387) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.840918,-0.00349311) , 
4, 0.171791, 1, 0, 0.436006,-0.000424017) , 
3, -0.903924, 1, 0, 0.501436,0.000437669)    );
  // itree = 287
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58638,-0.00517475) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401527,0.00212279) , 
0, 43617, 1, 0, 0.485024,-0.00109362) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.187901,0.0111747) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.947017,0.0015653) , 
4, 0.200174, 1, 0, 0.612718,0.00537439) , 
0, 122739, 1, 0, 0.499015,-0.000384922)    );
  // itree = 288
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.716073,0.0263405) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697607,0.000115019) , 
4, 0.0289186, 1, 0, 0.699382,0.00207397) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499233,-0.00483053) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31429,0.00229785) , 
3, 0.620454, 1, 0, 0.37778,-0.00133246) , 
1, 5.14286, 1, 0, 0.497957,-5.95382e-05)    );
  // itree = 289
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.962167,0.0236619) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409879,-0.00336176) , 
6, 0.638392, 1, 0, 0.486411,-0.00162217) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.157475,0.015676) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.937469,0.000548393) , 
4, 0.171674, 1, 0, 0.621683,0.00636884) , 
0, 126175, 1, 0, 0.50019,-0.000808197)    );
  // itree = 290
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453988,0.0104088) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0839152,-0.017422) , 
3, 0.619773, 1, 0, 0.191707,-0.00204856) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.625837,0.00312072) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0611818,-0.0166987) , 
8, 0.132575, 1, 0, 0.587871,0.00217787) , 
7, -1.42818, 1, 0, 0.501494,0.00125636)    );
  // itree = 291
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.280511,-0.00415451) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601645,0.00242609) , 
8, -0.0317126, 1, 0, 0.517179,0.000797408) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00843023,-0.0407713) , 
8, 0.292843, 1, 0, 0.499751,0.000444609)    );
  // itree = 292
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.985874,0.0395051) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50143,0.000811707) , 
6, 0.495788, 1, 0, 0.546852,0.00156373) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0489832,0.000627163) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.725,-0.0108908) , 
4, 0.200235, 1, 0, 0.219125,-0.00391077) , 
6, 4.81886, 1, 0, 0.502279,0.000819151)    );
  // itree = 293
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503639,0.00116607) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.010662,-0.0259039) , 
3, 0.620504, 1, 0, 0.233065,-0.00424047) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558059,-0.0020698) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.624804,0.00846309) , 
0, 65430.3, 1, 0, 0.581353,0.00137524) , 
4, 0.0574746, 1, 0, 0.49904,4.80431e-05)    );
  // itree = 294
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9892,-0.00257467) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.767268,0.0194369) , 
3, -0.713231, 1, 0, 0.954002,0.00377405) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50207,-0.00264077) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304297,0.00273285) , 
3, 0.904805, 1, 0, 0.411505,-0.0010589) , 
1, 2.14286, 1, 0, 0.498424,-0.00028456)    );
  // itree = 295
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424595,-0.000866335) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577557,0.00314646) , 
8, -0.0109269, 1, 0, 0.516195,0.0013882) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00870687,-0.0367964) , 
8, 0.308503, 1, 0, 0.500431,0.00111041)    );
  // itree = 296
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.867893,0.00670603) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.166284,-0.0162587) , 
3, 0.904799, 1, 0, 0.794333,0.00343838) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0310643,-0.0199742) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.412046,-0.000168098) , 
4, 0.0289274, 1, 0, 0.38029,-0.00107713) , 
1, 4.28571, 1, 0, 0.500992,0.000239235)    );
  // itree = 297
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.631781,-0.00306578) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.748355,0.0103517) , 
2, 34759.1, 1, 0, 0.702733,0.00304207) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0190854,-0.0243752) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414009,-0.000449091) , 
4, 0.0289274, 1, 0, 0.380493,-0.00133944) , 
1, 5.42857, 1, 0, 0.500919,0.000297997)    );
  // itree = 298
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.692308,-0.00370541) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.177507,0.0180031) , 
7, 2.38267, 1, 0, 0.655029,-0.00244732) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.265159,-0.00670138) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341909,0.0177036) , 
3, 0.990935, 1, 0, 0.303312,0.00182434) , 
3, 0.809611, 1, 0, 0.498578,-0.000547193)    );
  // itree = 299
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341162,-0.00579611) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0456461,0.00231811) , 
6, 2.58017, 1, 0, 0.214966,-0.00251117) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.784323,0.00365602) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545898,-0.00388908) , 
6, 3.79441, 1, 0, 0.741846,0.00160853) , 
4, 0.114423, 1, 0, 0.501028,-0.000274438)    );
  // itree = 300
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.908159,-0.00325) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.452868,0.0030533) , 
1, 3.61905, 1, 0, 0.564055,0.00188991) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0850699,0.0118642) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0143859,-0.0368066) , 
3, 0.905301, 1, 0, 0.0351687,-0.00486918) , 
7, 3.33353, 1, 0, 0.500942,0.00108332)    );
  // itree = 301
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674374,0.00296697) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288709,-0.00429665) , 
6, 1.95118, 1, 0, 0.487905,-0.000676399) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.182067,0.0127765) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.936745,0.00171902) , 
4, 0.171636, 1, 0, 0.647566,0.00585106) , 
0, 135690, 1, 0, 0.501632,-0.000115166)    );
  // itree = 302
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546146,0.00131256) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41608,-0.00346496) , 
7, 0.47746, 1, 0, 0.495427,-0.000394717) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.104595,0.0127354) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.7869,-0.0211789) , 
4, 0.143428, 1, 0, 0.519301,-0.00817304) , 
1, 13.7143, 1, 0, 0.497203,-0.000973411)    );
  // itree = 303
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.150437,-0.00020922) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37754,-0.0126523) , 
5, 0.777335, 1, 0, 0.232114,-0.00350536) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.633391,0.00126654) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0854187,-0.010519) , 
8, 0.111923, 1, 0, 0.582596,0.000551371) , 
4, 0.0575244, 1, 0, 0.501049,-0.000392509)    );
  // itree = 304
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.278645,0.012943) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0382159,-0.0281911) , 
3, 0.715175, 1, 0, 0.0944393,-0.00404916) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.690838,-0.00139564) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375618,0.00658708) , 
3, 0.809607, 1, 0, 0.564156,0.000951578) , 
8, -0.0857566, 1, 0, 0.50368,0.000307734)    );
  // itree = 305
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532139,-0.00222708) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439264,0.0081533) , 
0, 59044.4, 1, 0, 0.498479,0.000885254) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546395,-0.016685) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477887,0.000366875) , 
3, 0.525568, 1, 0, 0.498448,-0.00705334) , 
1, 12.6667, 1, 0, 0.498476,6.77155e-05)    );
  // itree = 306
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.824334,-0.00262378) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351083,0.00569371) , 
3, -0.237264, 1, 0, 0.54979,0.00139492) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983827,0.0300361) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375055,-0.00510351) , 
1, 1.66667, 1, 0, 0.420424,-0.00350852) , 
7, 0.476513, 1, 0, 0.49932,-0.000518086)    );
  // itree = 307
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.416856,-0.00106034) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.39622,-0.0140602) , 
1, 12, 1, 0, 0.413852,-0.00262089) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.748281,0.00396303) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.182547,-0.00275461) , 
7, 1.5202, 1, 0, 0.55341,0.00194176) , 
7, -0.475025, 1, 0, 0.500175,0.000201319)    );
  // itree = 308
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.987235,0.0072801) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.846693,0.00991395) , 
1, 3.2381, 1, 0, 0.944081,0.00574806) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357053,-0.00261844) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983969,0.0151578) , 
4, 0.457196, 1, 0, 0.432634,-0.0016553) , 
3, -0.903718, 1, 0, 0.499174,-0.000692109)    );
  // itree = 309
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581088,-0.00545917) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403043,0.00249081) , 
0, 44271.6, 1, 0, 0.484831,-0.00109016) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.881952,-0.0205341) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522337,0.012101) , 
6, 2.87172, 1, 0, 0.625612,0.00481624) , 
0, 126175, 1, 0, 0.49919,-0.000487711)    );
  // itree = 310
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.406891,-0.00944862) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0479409,0.00769777) , 
6, 2.24698, 1, 0, 0.233157,-0.00250031) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.658853,-0.00191436) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506134,0.00363015) , 
1, 6.42857, 1, 0, 0.579143,0.00113371) , 
4, 0.0572999, 1, 0, 0.498826,0.000290108)    );
  // itree = 311
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.921531,-0.00377863) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.951208,0.0113698) , 
8, -0.0212626, 1, 0, 0.945103,0.00477194) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.821066,-0.00262172) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328728,0.000951286) , 
3, -0.631934, 1, 0, 0.435931,-7.73352e-05) , 
3, -0.903924, 1, 0, 0.501353,0.000545733)    );
  // itree = 312
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549493,0.00207195) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.272859,-0.0120765) , 
6, 4.63132, 1, 0, 0.536626,0.00118882) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.042654,0.0013996) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.692192,-0.0110222) , 
4, 0.2003, 1, 0, 0.200919,-0.0038698) , 
6, 5.39687, 1, 0, 0.5001,0.000638423)    );
  // itree = 313
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586026,0.00377609) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0194705,-0.0118259) , 
3, 0.144539, 1, 0, 0.216237,-0.00146113) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.887261,-0.00278061) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504519,0.00468323) , 
3, -0.427674, 1, 0, 0.659838,0.00160383) , 
4, 0.0859873, 1, 0, 0.501532,0.000510051)    );
  // itree = 314
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57695,0.000791243) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0650136,-0.0102685) , 
7, 2.38, 1, 0, 0.498923,-9.45451e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56243,-0.0121807) , 
1, 16.2857, 1, 0, 0.50063,-0.000434883)    );
  // itree = 315
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0938912,-0.00691452) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.724232,0.00227062) , 
7, -2.01783, 1, 0, 0.547409,0.000617592) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.787788,0.00187192) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.236375,-0.0063381) , 
3, -0.237288, 1, 0, 0.419455,-0.00213971) , 
7, 0.476491, 1, 0, 0.497291,-0.000462405)    );
  // itree = 316
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.970083,0.0256934) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498615,-0.000444526) , 
6, 0.590982, 1, 0, 0.565005,0.000738404) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.149617,-0.0137585) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.342276,0.00297343) , 
0, 88433.5, 1, 0, 0.254087,-0.00357279) , 
6, 3.80824, 1, 0, 0.49783,-0.000193046)    );
  // itree = 317
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325099,0.0157666) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.690807,-0.00344924) , 
8, -0.0645724, 1, 0, 0.657516,-0.00175153) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.263722,-0.00761303) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339584,0.0148422) , 
3, 0.990936, 1, 0, 0.301201,0.000843335) , 
3, 0.809608, 1, 0, 0.499145,-0.000598202)    );
  // itree = 318
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98669,0.0385975) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469232,1.79275e-05) , 
6, 0.467291, 1, 0, 0.508642,0.000672445) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.174075,-0.0109807) , 
6, 8.9996, 1, 0, 0.499716,0.00040802)    );
  // itree = 319
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.804522,0.00568366) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330793,-0.00406128) , 
6, 1.20884, 1, 0, 0.485116,-0.0013767) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527006,-0.000483048) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.67565,0.013466) , 
7, -0.476416, 1, 0, 0.61964,0.00583279) , 
0, 126175, 1, 0, 0.498676,-0.00064999)    );
  // itree = 320
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580466,-0.0053377) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44859,0.00339375) , 
0, 52981.6, 1, 0, 0.537903,-0.00227751) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0793497,-0.0190885) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489493,0.00341118) , 
8, -0.0783492, 1, 0, 0.426288,0.00123763) , 
1, 8.57143, 1, 0, 0.500436,-0.00109754)    );
  // itree = 321
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.789046,-0.00687316) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954967,0.0073224) , 
4, 0.20039, 1, 0, 0.870094,-0.00209916) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603792,0.00959551) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316021,0.00164168) , 
3, -0.463833, 1, 0, 0.329206,0.00181594) , 
3, -0.61796, 1, 0, 0.503275,0.000555976)    );
  // itree = 322
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.689236,0.00473133) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387992,-0.00155443) , 
6, 1.82789, 1, 0, 0.564468,0.00150802) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.402629,0.0107768) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230584,-0.00600319) , 
1, 5.42857, 1, 0, 0.253246,-0.00268129) , 
6, 3.79441, 1, 0, 0.496165,0.000588599)    );
  // itree = 323
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98935,0.0318129) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.408469,-0.00181135) , 
1, 1.80952, 1, 0, 0.460477,-0.00109476) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.980409,0.00435771) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989385,0.0289937) , 
1, 6.66667, 1, 0, 0.985487,0.00457558) , 
4, 0.51433, 1, 0, 0.502323,-0.000642802)    );
  // itree = 324
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499362,0.000753972) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523675,0.00865238) , 
0, 92747.1, 1, 0, 0.502576,0.00129239) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.170092,0.00301371) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.894567,-0.0178529) , 
4, 0.229042, 1, 0, 0.491385,-0.00381614) , 
1, 11.6667, 1, 0, 0.501007,0.00057626)    );
  // itree = 325
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0107577,-0.0311855) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311388,-0.00512301) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574745,0.00131058) , 
8, -0.036232, 1, 0, 0.521802,7.12067e-05) , 
8, -0.249967, 1, 0, 0.499935,-0.000231154)    );
  // itree = 326
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.940644,0.00321435) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371284,-0.00175249) , 
3, -0.903718, 1, 0, 0.443025,-0.00116761) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.990008,0.0109618) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.973607,0.0258582) , 
6, 2.65461, 1, 0, 0.985157,0.00520551) , 
4, 0.485737, 1, 0, 0.499369,-0.000505244)    );
  // itree = 327
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202996,-0.00227617) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.709596,-0.00700515) , 
7, -1.38227, 1, 0, 0.410692,-0.00380083) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.618585,0.0026244) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296373,-0.00341039) , 
6, 3.80923, 1, 0, 0.553944,0.00114676) , 
7, -0.475313, 1, 0, 0.499816,-0.000722716)    );
  // itree = 328
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222588,-0.000418168) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.738769,0.00382256) , 
4, 0.114626, 1, 0, 0.495923,0.00171334) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.171371,0.0100243) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.859931,-0.0261318) , 
4, 0.200475, 1, 0, 0.530772,-0.00581921) , 
1, 13.7143, 1, 0, 0.498464,0.00116413)    );
  // itree = 329
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316247,-0.003131) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.931987,0.00417993) , 
4, 0.228652, 1, 0, 0.506781,-0.00113495) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.11295,0.0126873) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.844562,-0.00505304) , 
4, 0.172574, 1, 0, 0.476148,0.00366285) , 
1, 10.7143, 1, 0, 0.500948,-0.000221402)    );
  // itree = 330
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983165,0.00366212) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.800087,0.00585708) , 
1, 3.2381, 1, 0, 0.912577,0.00418632) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335415,-0.00372927) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602031,0.0049102) , 
0, 126175, 1, 0, 0.367076,-0.00248925) , 
3, -0.808696, 1, 0, 0.496693,-0.000903064)    );
  // itree = 331
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48535,-0.00179684) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565251,0.00478213) , 
0, 105860, 1, 0, 0.496147,-0.000885983) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.566845,-0.00943957) , 
1, 16.2857, 1, 0, 0.498001,-0.00112745)    );
  // itree = 332
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567856,0.00279807) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475736,-0.00644826) , 
8, 0.0260077, 1, 0, 0.546895,0.000446481) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.122662,0.00965219) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0190891,-0.0358061) , 
3, 0.904997, 1, 0, 0.0496131,-0.00490014) , 
8, 0.123934, 1, 0, 0.50007,-5.69695e-05)    );
  // itree = 333
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563529,-0.00414364) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423534,0.00213176) , 
0, 48715.8, 1, 0, 0.491006,-0.000833445) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.718845,0.0123414) , 
0, 191035, 1, 0, 0.498509,-0.000530636)    );
  // itree = 334
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.871095,0.00898463) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491475,-0.00639963) , 
6, 2.08717, 1, 0, 0.753119,0.00181257) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335215,-0.010593) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.263532,0.00564068) , 
6, 2.30031, 1, 0, 0.293646,-0.0014054) , 
3, 0.333627, 1, 0, 0.50008,4.03897e-05)    );
  // itree = 335
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523242,0.000438879) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445683,0.00534851) , 
0, 65430.1, 1, 0, 0.499468,0.00139642) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.153638,0.00296736) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.858713,-0.0122549) , 
4, 0.200489, 1, 0, 0.50326,-0.0034842) , 
1, 12.8571, 1, 0, 0.499856,0.000896972)    );
  // itree = 336
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390625,0.0121698) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.704935,-0.00451685) , 
7, -1.42407, 1, 0, 0.660414,-0.00219999) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.265715,-0.00600915) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.342795,0.0156846) , 
3, 0.990936, 1, 0, 0.303874,0.00168637) , 
3, 0.809628, 1, 0, 0.50162,-0.0004691)    );
  // itree = 337
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.902218,0.00480557) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293694,-0.00448975) , 
3, -0.808696, 1, 0, 0.413093,-0.00205441) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58808,0.00229128) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.23017,-0.00896128) , 
6, 5.61396, 1, 0, 0.556074,0.00110512) , 
7, -0.476411, 1, 0, 0.501886,-9.23083e-05)    );
  // itree = 338
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543285,0.00225321) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.686653,-0.00599202) , 
0, 80345.4, 1, 0, 0.566612,0.000969766) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.142437,-0.0117817) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329125,0.00241647) , 
0, 81774.1, 1, 0, 0.255845,-0.00229302) , 
6, 3.79441, 1, 0, 0.499395,0.000264051)    );
  // itree = 339
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.030273,-0.0150662) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563836,0.00065507) , 
8, -0.14518, 1, 0, 0.519179,0.000160649) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0112005,-0.0377252) , 
8, 0.286385, 1, 0, 0.501453,-0.000144914)    );
  // itree = 340
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.750605,0.0123351) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.860888,-0.00445415) , 
7, -1.43044, 1, 0, 0.851588,-0.00242053) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475797,0.00682526) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306894,0.00137245) , 
1, 3.42857, 1, 0, 0.317418,0.00150835) , 
3, -0.522786, 1, 0, 0.500075,0.000164889)    );
  // itree = 341
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0925022,0.011093) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0144822,-0.0304503) , 
3, 0.905233, 1, 0, 0.0376988,-0.00353399) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.683056,0.00187292) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.138679,-0.00374467) , 
7, 1.74641, 1, 0, 0.563646,0.000952536) , 
7, -3.33284, 1, 0, 0.50226,0.000428892)    );
  // itree = 342
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.29677,-0.0020674) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.988336,0.0201002) , 
5, 8.11937, 1, 0, 0.416432,-0.000696143) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.775643,0.00736255) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501194,0.00141946) , 
7, 0.0240815, 1, 0, 0.554371,0.00229473) , 
7, -0.474779, 1, 0, 0.502137,0.00116217)    );
  // itree = 343
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.716278,0.00386008) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322622,0.000148588) , 
6, 1.6774, 1, 0, 0.500678,0.00138171) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.151768,0.00323997) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.863182,-0.0124107) , 
4, 0.2009, 1, 0, 0.509469,-0.00355065) , 
1, 12.6667, 1, 0, 0.501591,0.000869215)    );
  // itree = 344
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.606638,-0.00483506) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426738,0.00274991) , 
0, 40809.2, 1, 0, 0.494533,-0.000206495) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.734785,0.017538) , 
0, 191035, 1, 0, 0.502585,0.000207528)    );
  // itree = 345
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304168,-0.00205986) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.171365,0.00514808) , 
1, 11.5714, 1, 0, 0.288264,-0.000931195) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.967985,0.0141537) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.905527,-0.00132364) , 
3, -0.713346, 1, 0, 0.929355,0.00216292) , 
4, 0.228661, 1, 0, 0.499292,8.72947e-05)    );
  // itree = 346
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266358,-0.000395338) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.648717,-0.00671936) , 
4, 0.196152, 1, 0, 0.291152,-0.000987711) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.933047,0.00574586) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.892143,-0.0136084) , 
1, 13.7143, 1, 0, 0.92875,0.00207918) , 
4, 0.228782, 1, 0, 0.501396,2.35785e-05)    );
  // itree = 347
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.876018,-0.00236787) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371022,0.00326291) , 
3, -0.618307, 1, 0, 0.547823,0.000973697) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.940138,0.00855828) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336171,-0.00468989) , 
1, 2.14286, 1, 0, 0.419032,-0.00292851) , 
7, 0.47724, 1, 0, 0.497272,-0.000557942)    );
  // itree = 348
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480506,0.0121622) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.127268,-0.00734292) , 
1, 4.85714, 1, 0, 0.190604,-0.00151965) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.751762,0.00350418) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364875,-0.00126457) , 
7, 0.749607, 1, 0, 0.587434,0.00154311) , 
7, -1.427, 1, 0, 0.499975,0.000868094)    );
  // itree = 349
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0968364,-0.00758777) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.727962,0.00286445) , 
7, -2.01772, 1, 0, 0.551558,0.000862322) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404079,-0.00338718) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49114,0.00368893) , 
0, 105860, 1, 0, 0.417042,-0.00195264) , 
7, 0.476513, 1, 0, 0.499474,-0.000227619)    );
  // itree = 350
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343956,-0.00653041) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0428415,0.00249536) , 
6, 2.59353, 1, 0, 0.21383,-0.0025657) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.653526,0.00109514) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696992,-0.00828103) , 
1, 15, 1, 0, 0.656252,0.000364012) , 
4, 0.0858561, 1, 0, 0.496769,-0.000692084)    );
  // itree = 351
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504231,3.54439e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437473,-0.00556813) , 
1, 10.6667, 1, 0, 0.494456,-0.000701596) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.225141,0.0112675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.902789,0.000324398) , 
4, 0.229019, 1, 0, 0.553816,0.00722269) , 
1, 15, 1, 0, 0.497532,-0.000290968)    );
  // itree = 352
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558874,6.04828e-07) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.250311,-0.00584442) , 
6, 2.25361, 1, 0, 0.409496,-0.00221015) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.851243,-0.00208515) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361778,0.00347746) , 
3, -0.427943, 1, 0, 0.553682,0.000860951) , 
7, -0.476568, 1, 0, 0.498897,-0.000305953)    );
  // itree = 353
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.229296,-0.000647583) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.743631,0.00438372) , 
4, 0.114575, 1, 0, 0.501447,0.0018501) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.152083,0.00200569) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.856921,-0.0155334) , 
4, 0.20053, 1, 0, 0.501685,-0.00540521) , 
1, 12.8571, 1, 0, 0.501472,0.00109826)    );
  // itree = 354
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0112333,-0.0330775) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316671,-0.0040819) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575148,0.00247409) , 
8, -0.0347869, 1, 0, 0.522123,0.0010112) , 
8, -0.248636, 1, 0, 0.500364,0.000680899)    );
  // itree = 355
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.992949,0.000794879) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.879362,0.00785454) , 
1, 2.14286, 1, 0, 0.945824,0.00418638) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433254,-0.00275592) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.438306,0.00277505) , 
1, 9.04762, 1, 0, 0.434688,-0.000975817) , 
3, -0.903924, 1, 0, 0.50033,-0.000312867)    );
  // itree = 356
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694697,0.00343726) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31649,-0.00137715) , 
6, 1.80158, 1, 0, 0.490905,0.00054819) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.724353,0.0121017) , 
0, 191035, 1, 0, 0.498725,0.000808748)    );
  // itree = 357
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.324917,-0.00241364) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.959751,0.0104347) , 
5, 6.16496, 1, 0, 0.397822,-0.00146375) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.997482,0.00058896) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.994014,0.024035) , 
1, 4.28571, 1, 0, 0.995132,0.0026514) , 
5, 9.9566, 1, 0, 0.500991,-0.000752971)    );
  // itree = 358
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.218535,-0.000970488) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372282,0.00556683) , 
4, 0.122586, 1, 0, 0.245863,0.000686839) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.956103,0.0160981) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.825303,-0.00595024) , 
1, 3.61905, 1, 0, 0.858226,-0.0026137) , 
4, 0.17155, 1, 0, 0.49856,-0.000675157)    );
  // itree = 359
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.815196,0.000325859) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629061,0.0112819) , 
7, 1.43517, 1, 0, 0.794784,0.00184769) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208689,-0.00668042) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411467,0.00798918) , 
0, 66685.9, 1, 0, 0.300626,-0.000591569) , 
3, -0.0471582, 1, 0, 0.500255,0.000393837)    );
  // itree = 360
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.793386,-0.00669997) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.100971,9.22306e-05) , 
3, -0.61587, 1, 0, 0.288542,-0.00215356) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.935922,0.00773012) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.904012,-0.00900303) , 
1, 10.2857, 1, 0, 0.928127,0.00187223) , 
4, 0.228676, 1, 0, 0.498352,-0.000832931)    );
  // itree = 361
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.985135,0.0314852) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54217,-0.00123099) , 
6, 0.481359, 1, 0, 0.590808,-0.000245736) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535173,0.0165143) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.271327,0.000924873) , 
1, 4.28571, 1, 0, 0.296396,0.00235174) , 
6, 3.04045, 1, 0, 0.499209,0.000562403)    );
  // itree = 362
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.781832,0.0126067) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.87578,-0.00430886) , 
7, -1.43044, 1, 0, 0.868113,-0.00217848) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.412714,0.00346379) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.113136,-0.00364806) , 
7, 1.42925, 1, 0, 0.326245,0.00157846) , 
3, -0.618307, 1, 0, 0.497957,0.000387928)    );
  // itree = 363
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.948381,0.00751493) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.750843,-0.00329832) , 
1, 6.47619, 1, 0, 0.909303,0.00246644) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0885718,0.00143757) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.746912,-0.00362132) , 
4, 0.14314, 1, 0, 0.371815,-0.000971278) , 
3, -0.808339, 1, 0, 0.501205,-0.000143718)    );
  // itree = 364
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.731886,0.0110172) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0959413,-0.0104304) , 
3, -0.427918, 1, 0, 0.186683,-0.00257768) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.677949,-9.26689e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41044,0.00835699) , 
3, 0.904814, 1, 0, 0.587398,0.0016762) , 
7, -1.4276, 1, 0, 0.499516,0.000743268)    );
  // itree = 365
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.994541,0.0467268) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.487217,0.000713237) , 
6, 0.412184, 1, 0, 0.517576,0.00106304) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.180613,-0.00881951) , 
6, 7.56169, 1, 0, 0.501995,0.000685708)    );
  // itree = 366
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.410643,0.00577745) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0807999,-0.0175366) , 
0, 55200.7, 1, 0, 0.235037,-0.00266434) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.878623,-0.00222644) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.418106,0.00350403) , 
3, -0.523139, 1, 0, 0.582671,0.00119989) , 
4, 0.0572999, 1, 0, 0.502155,0.000304887)    );
  // itree = 367
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526274,-0.00169259) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445894,0.0033373) , 
0, 65430.1, 1, 0, 0.504963,-0.000440443) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363015,0.0117569) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511709,0.000679685) , 
0, 69310.3, 1, 0, 0.476543,0.0034878) , 
1, 10.7143, 1, 0, 0.499504,0.000314095)    );
  // itree = 368
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00934323,-0.0295747) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605047,0.00344305) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.209636,-0.00488575) , 
8, 0.0495512, 1, 0, 0.522545,0.00176927) , 
8, -0.275057, 1, 0, 0.503857,0.00149539)    );
  // itree = 369
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.670295,0.000846174) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283555,-0.00511384) , 
6, 1.97089, 1, 0, 0.485617,-0.00179536) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.888321,-0.0106963) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511575,0.00749061) , 
6, 3.12114, 1, 0, 0.640298,0.00293254) , 
0, 135690, 1, 0, 0.49891,-0.00138906)    );
  // itree = 370
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.810034,-0.00799407) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0950883,-0.00101677) , 
3, -0.708402, 1, 0, 0.266202,-0.00282183) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.955709,0.0112073) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.815889,-0.00378846) , 
6, 2.23134, 1, 0, 0.900345,0.0014188) , 
4, 0.200101, 1, 0, 0.497792,-0.00127314)    );
  // itree = 371
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.951065,0.00871202) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.750157,-0.00471186) , 
1, 6.47619, 1, 0, 0.910976,0.00245846) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366132,-0.00459999) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374519,0.00308724) , 
1, 7.2381, 1, 0, 0.370473,-0.000699362) , 
3, -0.808727, 1, 0, 0.499915,5.68834e-05)    );
  // itree = 372
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.218675,0.000910222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.3055,0.00932743) , 
4, 0.10897, 1, 0, 0.233506,0.00231962) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.888374,0.00394729) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.67799,-0.00593019) , 
6, 2.42934, 1, 0, 0.809668,-0.00117921) , 
4, 0.142979, 1, 0, 0.502764,0.000684512)    );
  // itree = 373
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581182,-0.000704081) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203634,0.00439835) , 
7, 1.43037, 1, 0, 0.495737,0.000154267) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433571,-0.0160603) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575988,-0.000551687) , 
7, -0.475376, 1, 0, 0.522144,-0.00610796) , 
1, 13.7143, 1, 0, 0.497691,-0.000309235)    );
  // itree = 374
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.798951,-0.00527952) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.962167,0.00785844) , 
4, 0.228878, 1, 0, 0.869441,-0.00186556) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528189,0.00708032) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302876,0.000800033) , 
3, -0.155907, 1, 0, 0.327419,0.00161035) , 
3, -0.618307, 1, 0, 0.501181,0.000496037)    );
  // itree = 375
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532637,-0.00232744) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448523,0.00247643) , 
0, 58873.6, 1, 0, 0.498926,-0.000464088) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562585,-0.00742249) , 
1, 15.4286, 1, 0, 0.501259,-0.000721616)    );
  // itree = 376
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310576,0.0233157) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0413086,-0.00876019) , 
3, 0.715175, 1, 0, 0.106649,0.00351498) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.672042,0.00145504) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40728,-0.00440876) , 
8, 0.0165164, 1, 0, 0.561029,-0.000642878) , 
8, -0.0819215, 1, 0, 0.4996,-8.07615e-05)    );
  // itree = 377
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.707632,0.0243639) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694969,-4.21872e-05) , 
4, 0.0290286, 1, 0, 0.696169,0.001725) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0199506,-0.0227976) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.410884,-0.000590968) , 
4, 0.0287373, 1, 0, 0.37785,-0.00137593) , 
1, 5.14286, 1, 0, 0.497703,-0.000208376)    );
  // itree = 378
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334241,-0.00273792) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.15215,0.00263045) , 
1, 10, 1, 0, 0.292135,-0.0012255) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.963655,0.0107396) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.905297,-0.00177564) , 
3, -0.61804, 1, 0, 0.929827,0.00172729) , 
4, 0.228774, 1, 0, 0.502784,-0.000250108)    );
  // itree = 379
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.227508,0.0274449) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.682218,-0.00357411) , 
8, -0.0982037, 1, 0, 0.65866,-0.00223285) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.261101,-0.00633403) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335762,0.0133273) , 
3, 0.990936, 1, 0, 0.298248,0.000965031) , 
3, 0.809643, 1, 0, 0.499233,-0.000818278)    );
  // itree = 380
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554867,-0.00226177) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428884,0.00500746) , 
0, 52981.6, 1, 0, 0.506442,0.000193954) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.171151,0.00666556) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.908069,-0.00277846) , 
4, 0.228862, 1, 0, 0.474239,0.00347347) , 
1, 10.8571, 1, 0, 0.500254,0.000824062)    );
  // itree = 381
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.576378,-0.00179061) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387193,0.00556931) , 
0, 46679.8, 1, 0, 0.505701,0.000775215) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.576598,-0.0107624) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.451266,0.0040018) , 
3, 0.619222, 1, 0, 0.494834,-0.00264464) , 
0, 75587.4, 1, 0, 0.502547,-0.000217287)    );
  // itree = 382
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514398,-0.000249676) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00714054,-0.0420824) , 
8, 0.311975, 1, 0, 0.498386,-0.000430021) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572845,-0.0136078) , 
1, 16.2857, 1, 0, 0.500334,-0.000783285)    );
  // itree = 383
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.809467,0.0041404) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.630732,-0.00666788) , 
0, 71380.3, 1, 0, 0.773383,0.00162047) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334455,-0.00728658) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.255809,0.00586427) , 
6, 2.48692, 1, 0, 0.292677,-0.000658023) , 
3, 0.143249, 1, 0, 0.498688,0.000318442)    );
  // itree = 384
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.869228,0.00542571) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167729,-0.0191011) , 
3, 0.904799, 1, 0, 0.796821,0.0023901) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0148444,-0.0344088) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4143,-0.00100575) , 
7, -5.23751, 1, 0, 0.379241,-0.00161497) , 
1, 4.28571, 1, 0, 0.499526,-0.000461301)    );
  // itree = 385
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582506,-4.54868e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527434,0.00568683) , 
1, 8.33333, 1, 0, 0.567987,0.00125351) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363109,-0.00890943) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.211101,0.000124453) , 
3, 0.428976, 1, 0, 0.253177,-0.00354966) , 
6, 3.80923, 1, 0, 0.499586,0.000209902)    );
  // itree = 386
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608651,0.00367402) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.684222,-0.0157979) , 
0, 71380.3, 1, 0, 0.620247,0.0011548) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371883,-0.00571771) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26416,0.00653569) , 
3, 0.809643, 1, 0, 0.308138,-0.000989055) , 
6, 2.59404, 1, 0, 0.49941,0.000324775)    );
  // itree = 387
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311111,-0.000944756) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.841621,-0.0114859) , 
4, 0.258637, 1, 0, 0.332365,-0.00133597) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.95059,-0.000373833) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.968353,0.0165974) , 
3, 0.428833, 1, 0, 0.958479,0.00246272) , 
4, 0.285857, 1, 0, 0.498159,-0.000330079)    );
  // itree = 388
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.991573,0.041008) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481166,-0.000294494) , 
6, 0.438296, 1, 0, 0.515037,0.000248592) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.168831,-0.0112772) , 
6, 8.08783, 1, 0, 0.502018,-0.000107754)    );
  // itree = 389
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.900996,-0.000174233) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.643146,-0.00679165) , 
3, -0.776975, 1, 0, 0.823936,-0.00304056) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0218955,-0.0116935) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403315,0.00253539) , 
4, 0.0574807, 1, 0, 0.306519,0.000461514) , 
3, -0.332723, 1, 0, 0.498718,-0.000839361)    );
  // itree = 390
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.686874,0.00444589) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.218125,-0.00708575) , 
3, 0.904824, 1, 0, 0.541187,0.00168418) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527938,-0.00892555) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385833,0.00398274) , 
3, 0.525879, 1, 0, 0.428653,-0.00190443) , 
1, 8.57143, 1, 0, 0.503538,0.0004836)    );
  // itree = 391
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.624338,0.00271222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360576,-0.00149661) , 
1, 6.28571, 1, 0, 0.49924,0.000519679) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.571611,0.0104447) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422989,-0.00454426) , 
7, 0.476404, 1, 0, 0.514482,0.00487161) , 
1, 12.6667, 1, 0, 0.500798,0.000964583)    );
  // itree = 392
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586035,0.00273475) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0268043,-0.00901339) , 
3, 0.143464, 1, 0, 0.217286,-0.00148802) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567016,-0.00278712) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.793685,0.00293963) , 
8, -0.0256694, 1, 0, 0.73981,0.0012599) , 
4, 0.114417, 1, 0, 0.499458,-4.09837e-06)    );
  // itree = 393
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577161,0.000720128) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.673347,-0.0089326) , 
0, 71380.7, 1, 0, 0.594176,-0.000472699) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.178216,-0.00276223) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403024,0.00895383) , 
0, 80663.5, 1, 0, 0.301944,0.00307776) , 
6, 3.02705, 1, 0, 0.502194,0.000644831)    );
  // itree = 394
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0169571,-0.0210084) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523311,0.000976939) , 
8, -0.246079, 1, 0, 0.501257,0.000581927) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560461,0.00865412) , 
1, 16.2857, 1, 0, 0.502745,0.000795329)    );
  // itree = 395
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.885825,-0.00653436) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382022,5.51137e-05) , 
1, 3.57143, 1, 0, 0.498384,-0.000772813) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563209,0.00763252) , 
1, 15.4286, 1, 0, 0.50084,-0.000433893)    );
  // itree = 396
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222251,0.000447566) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345622,0.0179031) , 
4, 0.129492, 1, 0, 0.229722,0.00162176) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.944901,0.0134447) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.765169,-0.00337155) , 
1, 3.61905, 1, 0, 0.809282,-0.00124531) , 
4, 0.14309, 1, 0, 0.498809,0.000290594)    );
  // itree = 397
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.776113,0.00167559) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328226,-0.00353081) , 
6, 1.38879, 1, 0, 0.517825,-0.00129197) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.125087,0.0068887) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877632,-0.0050234) , 
4, 0.200278, 1, 0, 0.453336,0.00193237) , 
1, 9.04762, 1, 0, 0.501349,-0.000468177)    );
  // itree = 398
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570237,-0.000335369) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372284,0.00329012) , 
1, 7.42857, 1, 0, 0.497703,0.000804602) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0926806,0.00179377) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.79465,-0.00912157) , 
4, 0.143868, 1, 0, 0.508947,-0.00468695) , 
1, 12.8571, 1, 0, 0.498865,0.00023696)    );
  // itree = 399
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542918,0.00687437) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.892557,-0.00291598) , 
4, 0.143078, 1, 0, 0.737468,0.00221743) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328036,-0.00654492) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.259248,0.00452413) , 
6, 2.4804, 1, 0, 0.291249,-0.00067545) , 
3, 0.428823, 1, 0, 0.498602,0.000668841)    );
  // itree = 400
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.878906,-0.000861776) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617443,-0.0132428) , 
3, -0.659123, 1, 0, 0.854502,-0.00251022) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483459,0.00821141) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.29495,-0.00211901) , 
3, -0.015306, 1, 0, 0.315103,4.06676e-07) , 
3, -0.523113, 1, 0, 0.498819,-0.000854695)    );
  // itree = 401
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.709579,-0.00110016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401683,0.00450291) , 
3, 0.809611, 1, 0, 0.590005,0.000434859) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.67218,0.00439459) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102098,-0.0109576) , 
3, -0.236664, 1, 0, 0.20432,-0.00331391) , 
7, 1.42972, 1, 0, 0.50288,-0.000411979)    );
  // itree = 402
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5586,0.000201672) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.234904,-0.00528067) , 
6, 4.05662, 1, 0, 0.501109,-0.000548347) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546444,0.0109367) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550606,-0.00592763) , 
3, 0.905851, 1, 0, 0.548519,0.00530271) , 
1, 15, 1, 0, 0.503556,-0.000246261)    );
  // itree = 403
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.663448,-0.00355343) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.149853,0.0179005) , 
7, 2.37988, 1, 0, 0.620627,-0.00215203) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.271378,-0.00783135) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351719,0.0184859) , 
3, 0.995468, 1, 0, 0.308276,0.00100724) , 
3, 0.904814, 1, 0, 0.499311,-0.000924977)    );
  // itree = 404
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.626546,0.00330575) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0134326,-0.0218147) , 
3, 0.0494877, 1, 0, 0.233302,-0.00329981) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.718345,-0.00300401) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491215,0.00184626) , 
1, 5.42857, 1, 0, 0.577544,0.000283172) , 
4, 0.0574706, 1, 0, 0.496845,-0.000556767)    );
  // itree = 405
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.82487,0.00111838) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.660369,0.0102411) , 
7, 1.41127, 1, 0, 0.80697,0.00237303) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.282206,-0.00494441) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309268,0.000663307) , 
3, 0.945608, 1, 0, 0.29773,-0.00164789) , 
3, -0.142334, 1, 0, 0.500534,-4.6562e-05)    );
  // itree = 406
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293527,-0.00146503) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.907653,0.00388314) , 
4, 0.200188, 1, 0, 0.505102,9.76539e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0879133,0.0111545) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.803892,-0.000805687) , 
4, 0.143154, 1, 0, 0.477771,0.00379674) , 
1, 10.7143, 1, 0, 0.49983,0.000811203)    );
  // itree = 407
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.899403,-0.00336726) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.919501,0.00925945) , 
2, 43785.9, 1, 0, 0.911468,0.00270611) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367709,-0.00198635) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.373362,0.00161724) , 
1, 7.2381, 1, 0, 0.370641,-0.000157262) , 
3, -0.808397, 1, 0, 0.49978,0.000526457)    );
  // itree = 408
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549953,0.000725194) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266178,-0.0135853) , 
6, 4.37635, 1, 0, 0.531341,-0.000166372) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0512258,0.0278099) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.254566,-0.00984236) , 
7, -2.38297, 1, 0, 0.202493,-0.00428466) , 
6, 5.39687, 1, 0, 0.496317,-0.000604989)    );
  // itree = 409
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.8147,0.0126426) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.857811,-0.00213576) , 
4, 0.0290308, 1, 0, 0.854127,-0.000942247) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354162,0.0035088) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175427,-0.00667673) , 
6, 4.47434, 1, 0, 0.317874,0.00138673) , 
3, -0.522812, 1, 0, 0.4998,0.000596614)    );
  // itree = 410
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.992639,0.0426741) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.811101,-0.00290703) , 
3, -0.967388, 1, 0, 0.824424,-0.00203012) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.416973,0.0119) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.29837,-3.41475e-05) , 
3, 0.175022, 1, 0, 0.309674,0.00140503) , 
3, -0.332747, 1, 0, 0.500566,0.000131129)    );
  // itree = 411
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.861209,-0.000406051) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.703925,-0.00787655) , 
0, 62560, 1, 0, 0.823915,-0.00263999) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.223997,-0.00215484) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422687,0.00553138) , 
0, 71382.2, 1, 0, 0.303986,0.000373464) , 
3, -0.332603, 1, 0, 0.498311,-0.000752825)    );
  // itree = 412
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311615,-3.5688e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.745156,0.0065986) , 
7, -0.928828, 1, 0, 0.415506,0.00153776) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.778887,-0.00398233) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345461,0.000388523) , 
3, 0.238569, 1, 0, 0.550271,-0.0017565) , 
7, -0.475333, 1, 0, 0.499088,-0.000505359)    );
  // itree = 413
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181371,-9.88281e-06) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.685687,-0.0184341) , 
5, 3.17597, 1, 0, 0.216377,-0.00135039) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0803929,-0.0113889) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.775886,0.00203571) , 
7, -4.28685, 1, 0, 0.740463,0.00137094) , 
4, 0.114425, 1, 0, 0.500176,0.000123242)    );
  // itree = 414
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31745,-0.00681125) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0426092,0.0111041) , 
7, 2.38255, 1, 0, 0.248851,-0.00328347) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617638,0.00172933) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0294013,-0.0185336) , 
7, 4.28538, 1, 0, 0.574825,0.000911231) , 
8, -0.0370857, 1, 0, 0.50031,-4.76384e-05)    );
  // itree = 415
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.153627,0.000841123) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.391834,-0.00890921) , 
5, 1.30594, 1, 0, 0.215096,-0.0015844) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.416527,0.0028487) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.943808,-0.00170313) , 
4, 0.257323, 1, 0, 0.659484,0.00148551) , 
4, 0.0859887, 1, 0, 0.499955,0.000383461)    );
  // itree = 416
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.754775,0.0141065) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.86864,0.000590736) , 
7, -1.41304, 1, 0, 0.858787,0.00193341) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347185,-0.00105314) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.15633,-0.00941159) , 
6, 4.86673, 1, 0, 0.314296,-0.00160278) , 
3, -0.523113, 1, 0, 0.499769,-0.000398228)    );
  // itree = 417
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537196,0.00166925) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358119,-0.0035217) , 
1, 8.85714, 1, 0, 0.486295,2.40603e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599182,0.0200772) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.663462,-0.000720308) , 
2, 122953, 1, 0, 0.631985,0.00568352) , 
0, 126175, 1, 0, 0.500909,0.000591763)    );
  // itree = 418
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.722559,0.00213703) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221522,-0.00517814) , 
3, 0.238444, 1, 0, 0.410824,-0.00100116) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555737,0.00351719) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56555,-0.00373575) , 
1, 12.8571, 1, 0, 0.55671,0.0021633) , 
7, -0.475045, 1, 0, 0.501255,0.000960406)    );
  // itree = 419
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.738826,0.0161656) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.813683,0.00128278) , 
4, 0.0287367, 1, 0, 0.807222,0.00249099) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354815,-0.00419998) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262382,0.00246868) , 
6, 2.30377, 1, 0, 0.302307,-0.000530191) , 
3, -0.142335, 1, 0, 0.502449,0.000667369)    );
  // itree = 420
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.892878,-0.000818594) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.682432,-0.010193) , 
3, -0.744941, 1, 0, 0.865767,-0.00248472) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.441988,0.00359749) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293515,-0.000735843) , 
3, 0.460692, 1, 0, 0.325981,0.000648019) , 
3, -0.618033, 1, 0, 0.499955,-0.000361668)    );
  // itree = 421
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.857027,-0.000733236) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.969006,0.0137922) , 
4, 0.200284, 1, 0, 0.911016,0.00288875) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.105051,0.00158612) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.814287,-0.00234441) , 
4, 0.17155, 1, 0, 0.369814,-4.54102e-05) , 
3, -0.808727, 1, 0, 0.498494,0.000652237)    );
  // itree = 422
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309218,0.00474285) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.913294,-0.000919083) , 
4, 0.200227, 1, 0, 0.548468,0.00244258) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477023,-0.00417153) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0693847,0.00892684) , 
8, 0.101917, 1, 0, 0.42143,-0.00256089) , 
7, 0.477516, 1, 0, 0.498737,0.000483905)    );
  // itree = 423
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5403,-0.00291994) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.435292,0.00364986) , 
0, 58873.4, 1, 0, 0.506418,-0.000828742) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.109797,0.00863628) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.849143,-0.000269937) , 
4, 0.171724, 1, 0, 0.468878,0.00394058) , 
1, 10.2857, 1, 0, 0.499189,8.9695e-05)    );
  // itree = 424
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.269403,-0.00571811) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.604146,0.000508679) , 
4, 0.0572996, 1, 0, 0.53037,-0.00045587) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303975,0.0137147) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.155281,-0.0032412) , 
3, 0.714416, 1, 0, 0.208227,0.00534414) , 
6, 5.62715, 1, 0, 0.498704,0.000114268)    );
  // itree = 425
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590233,0.00587083) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0211223,-0.00736004) , 
3, 0.143464, 1, 0, 0.220466,0.000519921) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.774565,-0.00497845) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491859,0.00110967) , 
3, 0.809608, 1, 0, 0.65709,-0.00269581) , 
4, 0.0858545, 1, 0, 0.499945,-0.00153844)    );
  // itree = 426
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.82458,0.00470206) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428684,-0.0014559) , 
6, 1.12821, 1, 0, 0.567142,0.000102883) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.160587,-0.00690591) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954154,0.0112595) , 
4, 0.400187, 1, 0, 0.254207,-0.00405347) , 
6, 3.80923, 1, 0, 0.499283,-0.000798409)    );
  // itree = 427
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.859601,-0.00238966) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.301914,0.000744221) , 
3, -0.522861, 1, 0, 0.496466,-0.00040116) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537249,0.0134391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562429,0.000687372) , 
1, 16.4286, 1, 0, 0.550077,0.00683466) , 
1, 15, 1, 0, 0.499236,-2.73384e-05)    );
  // itree = 428
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27226,-0.000476401) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674889,-0.00766702) , 
4, 0.206902, 1, 0, 0.289702,-0.000890995) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.945319,0.00546738) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.760655,-0.00672582) , 
8, 0.0567469, 1, 0, 0.930557,0.00210045) , 
4, 0.228676, 1, 0, 0.499845,8.99329e-05)    );
  // itree = 429
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.931234,0.00272752) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.65591,-0.00409214) , 
3, -0.88126, 1, 0, 0.758074,-0.00252369) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0854492,-0.0097772) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383532,0.00348277) , 
7, -1.4276, 1, 0, 0.293603,0.00047281) , 
3, 0.23843, 1, 0, 0.499135,-0.000853164)    );
  // itree = 430
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298072,-0.000643096) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.239393,-0.0106202) , 
0, 126175, 1, 0, 0.293873,-0.00133317) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.938786,0.00788602) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.911856,-0.000695485) , 
1, 8.57143, 1, 0, 0.928419,0.00252859) , 
4, 0.228773, 1, 0, 0.502015,-6.64465e-05)    );
  // itree = 431
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.220632,-5.75852e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.429991,0.00595011) , 
4, 0.124051, 1, 0, 0.268079,0.00180046) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.904949,0.000295053) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.852941,-0.0157393) , 
1, 15, 1, 0, 0.900979,-0.00087313) , 
4, 0.200211, 1, 0, 0.500975,0.000816623)    );
  // itree = 432
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56994,-0.00328046) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.410258,0.00439923) , 
0, 44842.2, 1, 0, 0.481479,0.00063641) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560465,-0.0098702) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984486,0.0141309) , 
4, 0.285905, 1, 0, 0.698986,-0.004721) , 
2, 122953, 1, 0, 0.501162,0.000151602)    );
  // itree = 433
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295767,-0.0013089) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.985445,0.0180716) , 
5, 9.1436, 1, 0, 0.333143,-0.000928027) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98694,0.0175663) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.919133,-0.00147252) , 
6, 2.11547, 1, 0, 0.958107,0.00195325) , 
4, 0.285878, 1, 0, 0.498138,-0.000167348)    );
  // itree = 434
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.675993,-0.000844685) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405179,0.00653462) , 
3, 0.904804, 1, 0, 0.584329,0.000815617) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347002,0.00347175) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0886641,-0.0184403) , 
3, 0.904871, 1, 0, 0.203669,-0.00255527) , 
7, 1.42809, 1, 0, 0.498383,5.45366e-05)    );
  // itree = 435
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540717,0.00563721) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0371651,-0.00213969) , 
3, 0.428976, 1, 0, 0.231987,0.00199293) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442144,-0.00510816) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.883972,4.54339e-05) , 
4, 0.186512, 1, 0, 0.80874,-0.00122127) , 
4, 0.142988, 1, 0, 0.501563,0.000490607)    );
  // itree = 436
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281638,0.00422252) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.881273,-0.00330497) , 
4, 0.171547, 1, 0, 0.549121,0.0010233) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.172238,-0.00749154) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76145,0.00140166) , 
4, 0.143194, 1, 0, 0.416997,-0.00223875) , 
7, 0.477218, 1, 0, 0.497616,-0.000248307)    );
  // itree = 437
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472943,0.0102876) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.12625,-0.0078011) , 
1, 4.85714, 1, 0, 0.190201,-0.00170884) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601077,0.00252553) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.231995,-0.00640814) , 
6, 7.56169, 1, 0, 0.586831,0.0018063) , 
7, -1.42827, 1, 0, 0.49981,0.00103508)    );
  // itree = 438
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.876918,-0.00110919) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383395,0.00240694) , 
3, -0.618335, 1, 0, 0.558294,0.000936792) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.267511,0.0217932) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.03506,-0.0291553) , 
3, 0.715512, 1, 0, 0.0839085,-0.00278856) , 
8, 0.0983845, 1, 0, 0.501113,0.00048775)    );
  // itree = 439
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.678183,0.00112215) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.318315,-0.00265354) , 
6, 1.93603, 1, 0, 0.498114,-0.000695567) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235739,0.0122981) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.8749,-0.00352586) , 
4, 0.229262, 1, 0, 0.54683,0.00645262) , 
1, 15, 1, 0, 0.500631,-0.000326256)    );
  // itree = 440
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.665029,-0.00363239) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.155488,0.0168827) , 
7, 2.37942, 1, 0, 0.621016,-0.00226946) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.271323,-0.00557952) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348284,0.0203259) , 
3, 0.995468, 1, 0, 0.306684,0.00217342) , 
3, 0.904804, 1, 0, 0.49939,-0.000550354)    );
  // itree = 441
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517253,-0.00253298) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.461097,0.00207589) , 
0, 65430.1, 1, 0, 0.497602,-0.000856733) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.595247,0.00795378) , 
1, 16.2857, 1, 0, 0.500224,-0.000609012)    );
  // itree = 442
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588459,-0.00530084) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387235,0.00240214) , 
0, 43447.3, 1, 0, 0.496887,-0.00150584) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.062861,-0.0303958) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.553948,0.00492342) , 
4, 0.0287373, 1, 0, 0.498992,0.00184635) , 
0, 80345, 1, 0, 0.497438,-0.000628593)    );
  // itree = 443
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567188,-0.00181276) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.377687,0.00593453) , 
0, 48271.3, 1, 0, 0.503776,0.000595072) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5347,-0.00785768) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44925,0.00382203) , 
3, 0.809607, 1, 0, 0.484879,-0.00225177) , 
0, 73870.2, 1, 0, 0.497993,-0.000276142)    );
  // itree = 444
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546239,-0.00019156) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423234,0.00481005) , 
7, 0.476513, 1, 0, 0.498054,0.00128966) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0515614,0.00702508) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.67932,-0.0086162) , 
4, 0.0864597, 1, 0, 0.511275,-0.00579663) , 
1, 12.8571, 1, 0, 0.499411,0.000562125)    );
  // itree = 445
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.690906,0.00340737) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315556,-0.00113849) , 
6, 1.83401, 1, 0, 0.492531,0.000640681) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.725321,0.0172955) , 
0, 191035, 1, 0, 0.500356,0.000994915)    );
  // itree = 446
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.658339,-0.00150232) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289918,0.00259024) , 
3, 0.80961, 1, 0, 0.495908,-0.000208346) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535762,-0.00803402) , 
1, 15.4286, 1, 0, 0.497406,-0.000499527)    );
  // itree = 447
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534195,0.000664455) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456695,0.00648778) , 
0, 63251, 1, 0, 0.512338,0.00157462) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470337,-0.0061756) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464005,0.00573887) , 
3, 0.905494, 1, 0, 0.466873,-0.00160575) , 
1, 10.8571, 1, 0, 0.503624,0.000965076)    );
  // itree = 448
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50678,-0.00102624) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0205628,-0.0216597) , 
7, 4.28705, 1, 0, 0.457781,-0.00148366) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98231,-0.0043669) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989074,0.027774) , 
1, 5.90476, 1, 0, 0.986673,0.0040991) , 
4, 0.51433, 1, 0, 0.499266,-0.00104575)    );
  // itree = 449
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551734,0.00794016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0760817,-0.0150525) , 
3, 0.143851, 1, 0, 0.17108,-0.00271454) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.913389,-0.00332759) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44576,0.00212117) , 
3, -0.808727, 1, 0, 0.575447,0.000709495) , 
8, -0.0543912, 1, 0, 0.502537,9.21235e-05)    );
  // itree = 450
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.833739,-0.00524485) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347486,0.00209223) , 
3, -0.332747, 1, 0, 0.544148,-0.00110357) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.793927,0.00618239) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.237149,-0.00180172) , 
3, -0.236928, 1, 0, 0.423433,0.00138849) , 
7, 0.477482, 1, 0, 0.496914,-0.000128454)    );
  // itree = 451
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550933,0.000885741) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.204025,-0.00635881) , 
6, 4.18945, 1, 0, 0.493427,-0.000177329) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.712021,0.00658671) , 
0, 176762, 1, 0, 0.50239,1.48595e-05)    );
  // itree = 452
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996584,-0.0172834) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.985038,0.0415232) , 
3, -0.903602, 1, 0, 0.991211,0.00412245) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534448,-0.00226888) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393766,0.0013403) , 
1, 6.71429, 1, 0, 0.452886,-0.000205574) , 
1, 1.66667, 1, 0, 0.500256,0.000175268)    );
  // itree = 453
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.901093,0.00518033) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.975582,-0.0198811) , 
4, 0.457178, 1, 0, 0.911976,0.00292084) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.65311,-0.0045883) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.29784,-0.000319535) , 
3, -0.205817, 1, 0, 0.366772,-0.00140688) , 
3, -0.808727, 1, 0, 0.497856,-0.000366362)    );
  // itree = 454
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.223901,-0.00565745) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.199232,0.00208168) , 
4, 0.0710704, 1, 0, 0.215188,-0.0015395) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.850163,0.00527089) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592981,-0.00199003) , 
6, 2.22751, 1, 0, 0.740884,0.00103973) , 
4, 0.114581, 1, 0, 0.500744,-0.000138469)    );
  // itree = 455
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00721539,-0.041811) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601239,0.00236255) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208001,-0.00631505) , 
8, 0.0494823, 1, 0, 0.517909,0.000779724) , 
8, -0.275057, 1, 0, 0.498843,0.000475638)    );
  // itree = 456
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519548,-0.000719858) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.45993,0.00348321) , 
0, 65430.1, 1, 0, 0.500199,0.000383355) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575126,0.0105962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516437,-0.0015912) , 
3, 0.71534, 1, 0, 0.53724,0.00448925) , 
1, 13.3333, 1, 0, 0.502896,0.000682326)    );
  // itree = 457
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.87636,0.0191622) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.888608,-0.00411792) , 
4, 0.0290532, 1, 0, 0.887453,-0.00163117) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.596076,0.00797166) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323138,0.000999524) , 
1, 3.61905, 1, 0, 0.34313,0.00144749) , 
3, -0.713531, 1, 0, 0.50198,0.000549038)    );
  // itree = 458
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.911402,-0.00634486) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466356,0.000879863) , 
1, 3.61905, 1, 0, 0.57719,-0.000146245) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230035,0.00934358) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.029283,-0.0222502) , 
3, 0.620735, 1, 0, 0.0661817,-0.00382419) , 
7, 2.38119, 1, 0, 0.498805,-0.000710417)    );
  // itree = 459
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75658,0.00317836) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37516,-0.00332056) , 
6, 1.47701, 1, 0, 0.528539,-0.000867502) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326633,0.0168904) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.138296,-0.00928552) , 
3, 0.619222, 1, 0, 0.201053,0.00473845) , 
6, 6.0265, 1, 0, 0.501107,-0.000397919)    );
  // itree = 460
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321147,0.0166318) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.754904,0.00099453) , 
8, -0.0553314, 1, 0, 0.698139,0.00219534) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.255373,-0.002692) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.97897,0.0109524) , 
4, 0.40011, 1, 0, 0.379176,-0.00153957) , 
1, 5.42857, 1, 0, 0.499407,-0.00013172)    );
  // itree = 461
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489445,-0.00111633) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554102,0.0102699) , 
0, 105860, 1, 0, 0.49666,-7.38009e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293417,-0.00920515) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.948547,0.00342112) , 
4, 0.315195, 1, 0, 0.520938,-0.00707095) , 
1, 13.3333, 1, 0, 0.498443,-0.000587589)    );
  // itree = 462
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785526,0.00408712) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329415,-0.0016036) , 
3, 0.714442, 1, 0, 0.607639,0.00185893) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35847,-0.00635246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.265414,0.00723454) , 
3, 0.809643, 1, 0, 0.303031,-0.00103528) , 
6, 2.82712, 1, 0, 0.502465,0.000859628)    );
  // itree = 463
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989274,-0.00766363) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.77368,0.0166281) , 
3, -0.713563, 1, 0, 0.954766,0.00225064) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597377,-0.00447615) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380024,-0.000490717) , 
1, 5, 1, 0, 0.414105,-0.0011127) , 
1, 2.14286, 1, 0, 0.500928,-0.00057259)    );
  // itree = 464
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.253838,-0.00133456) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578179,0.00707832) , 
4, 0.181055, 1, 0, 0.268533,-0.000581736) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.957154,0.0103368) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.860716,-0.00226073) , 
3, -0.618335, 1, 0, 0.902077,0.00151698) , 
4, 0.200112, 1, 0, 0.499345,0.000182867)    );
  // itree = 465
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.589647,-0.000296903) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361259,0.00667997) , 
6, 3.07723, 1, 0, 0.547465,0.000849991) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456684,0.00846673) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.173008,-0.0125582) , 
3, -0.236828, 1, 0, 0.225869,-0.00273972) , 
6, 4.59575, 1, 0, 0.498917,0.000308093)    );
  // itree = 466
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579271,-0.00197598) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388842,0.00644878) , 
0, 46083.4, 1, 0, 0.501681,0.00114982) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.596816,-0.0104303) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.462561,0.00165017) , 
3, 0.428833, 1, 0, 0.501976,-0.00287864) , 
0, 80345.2, 1, 0, 0.501759,8.74085e-05)    );
  // itree = 467
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.234517,-0.00323567) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.450183,0.0104237) , 
4, 0.155327, 1, 0, 0.245529,-0.00161912) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.61816,0.00832274) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.899542,-0.000197629) , 
7, -1.43351, 1, 0, 0.865464,0.00113141) , 
4, 0.171655, 1, 0, 0.499332,-0.000493051)    );
  // itree = 468
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.149098,0.0160963) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.668153,0.000210234) , 
7, -2.36056, 1, 0, 0.623753,0.00121329) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.265069,-0.0111691) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348062,0.0126325) , 
3, 0.995467, 1, 0, 0.303219,-0.00128956) , 
3, 0.904805, 1, 0, 0.498963,0.000238883)    );
  // itree = 469
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335328,-0.000334487) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353633,-0.0121686) , 
0, 150057, 1, 0, 0.336172,-0.000898556) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.968602,0.00208517) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.871854,0.0129645) , 
7, 1.42935, 1, 0, 0.959045,0.00213441) , 
4, 0.285877, 1, 0, 0.501027,-9.58252e-05)    );
  // itree = 470
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.937739,-0.00688007) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965414,0.0153619) , 
4, 0.114648, 1, 0, 0.95406,0.00153044) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346509,-0.0017145) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984209,0.0113178) , 
4, 0.485739, 1, 0, 0.413051,-0.00118133) , 
1, 2.14286, 1, 0, 0.499528,-0.000747868)    );
  // itree = 471
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.82651,-0.00636179) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.122969,0.00310648) , 
1, 3.2381, 1, 0, 0.267004,0.00130381) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.96311,0.0055904) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.820172,-0.00622627) , 
6, 2.00978, 1, 0, 0.899494,-0.00174177) , 
4, 0.200245, 1, 0, 0.499415,0.000184699)    );
  // itree = 472
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.754501,-0.00100745) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.974229,-0.0456254) , 
4, 0.400143, 1, 0, 0.788531,-0.00220746) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0230814,-0.0158869) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.441368,0.00235383) , 
7, -3.32997, 1, 0, 0.38021,0.00122794) , 
1, 4.28571, 1, 0, 0.500457,0.000216243)    );
  // itree = 473
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.110816,0.0105845) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0144817,-0.0264661) , 
3, 0.809995, 1, 0, 0.0359591,-0.0031131) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.686095,-0.00111948) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375502,0.00331848) , 
3, 0.809607, 1, 0, 0.56221,0.000150473) , 
7, -3.33264, 1, 0, 0.499895,-0.000235979)    );
  // itree = 474
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.211809,-0.00324141) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.898548,0.00759197) , 
5, 4.76594, 1, 0, 0.262957,-0.00205956) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.964095,0.0100314) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.86153,-0.00190401) , 
3, -0.713163, 1, 0, 0.901449,0.00113292) , 
4, 0.200112, 1, 0, 0.497331,-0.000887681)    );
  // itree = 475
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.231626,0.00015779) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.809743,-0.00305501) , 
4, 0.143134, 1, 0, 0.497915,-0.00108918) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539992,0.00646568) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552321,0.00426321) , 
3, 0.905113, 1, 0, 0.546333,0.00572791) , 
1, 15, 1, 0, 0.50047,-0.00072952)    );
  // itree = 476
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500595,0.000904821) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501355,-0.00700997) , 
1, 13.7143, 1, 0, 0.500632,0.000344944) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582836,0.0106473) , 
1, 16.2857, 1, 0, 0.502819,0.000626373)    );
  // itree = 477
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.747239,0.000618635) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0803765,0.0300123) , 
7, 3.33353, 1, 0, 0.698286,0.00154703) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.462863,-0.00396392) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325104,0.00222331) , 
3, 0.810352, 1, 0, 0.381958,-0.00128613) , 
1, 5.42857, 1, 0, 0.501172,-0.000218402)    );
  // itree = 478
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586285,0.00566758) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0219627,-0.00213415) , 
3, 0.144539, 1, 0, 0.216419,0.00168449) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.82067,-0.00228915) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481606,0.00209775) , 
3, 0.524027, 1, 0, 0.658833,-0.000457783) , 
4, 0.0860264, 1, 0, 0.49934,0.000314519)    );
  // itree = 479
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.446601,-0.00523574) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167371,0.00609813) , 
6, 5.40956, 1, 0, 0.413164,-0.00309667) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72841,0.00240445) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.101541,-0.00447912) , 
7, 2.0188, 1, 0, 0.555073,0.00105375) , 
7, -0.475313, 1, 0, 0.50176,-0.000505506)    );
  // itree = 480
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570383,0.00163532) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372312,-0.00236516) , 
1, 7.42857, 1, 0, 0.498333,0.00010708) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539406,0.0105469) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495475,0.00193816) , 
3, 0.810227, 1, 0, 0.512295,0.00637997) , 
1, 12.6667, 1, 0, 0.499756,0.000746069)    );
  // itree = 481
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674445,-0.00426298) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0636042,0.0233406) , 
7, 3.33175, 1, 0, 0.619543,-0.002164) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434647,0.00250049) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.021422,-0.0319886) , 
8, 0.140855, 1, 0, 0.392228,0.00103722) , 
1, 6.85714, 1, 0, 0.49961,-0.000475017)    );
  // itree = 482
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.128225,0.0280307) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.689821,0.00156302) , 
7, -3.31136, 1, 0, 0.663747,0.00242175) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.260127,-0.0090952) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326034,0.00713258) , 
3, 0.981871, 1, 0, 0.300084,-0.00043302) , 
3, 0.809611, 1, 0, 0.503343,0.00116257)    );
  // itree = 483
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567904,0.00105485) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50769,0.00578662) , 
1, 9.04762, 1, 0, 0.552574,0.00202901) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0886027,0.0140484) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0104048,-0.0323935) , 
3, 0.905301, 1, 0, 0.0313218,-0.00256881) , 
7, 4.28463, 1, 0, 0.502764,0.00158965)    );
  // itree = 484
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428181,-0.00323865) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577388,0.00323598) , 
8, -0.0101692, 1, 0, 0.517052,0.000592257) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00788643,-0.0391719) , 
8, 0.309333, 1, 0, 0.500905,0.000349335)    );
  // itree = 485
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603703,0.00128447) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222066,0.00775569) , 
7, 1.42537, 1, 0, 0.519818,0.00179184) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295997,-0.00445501) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.981307,0.0217907) , 
4, 0.371538, 1, 0, 0.450332,-0.00213525) , 
1, 9.04762, 1, 0, 0.501907,0.000779541)    );
  // itree = 486
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.744881,-0.00199799) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345327,0.00246391) , 
3, 0.524019, 1, 0, 0.550175,-0.000270375) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.87648,0.00246898) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.276274,-0.00527386) , 
3, -0.713088, 1, 0, 0.423084,-0.00228779) , 
7, 0.476513, 1, 0, 0.500718,-0.00105545)    );
  // itree = 487
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.85293,-0.000278595) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597302,-0.00663308) , 
1, 7.2381, 1, 0, 0.792398,-0.00258625) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0218247,-0.0066555) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493837,0.00254726) , 
4, 0.0861199, 1, 0, 0.29942,0.00026108) , 
3, -0.0469332, 1, 0, 0.499377,-0.000893825)    );
  // itree = 488
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316869,-0.00128454) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.833171,-0.00961294) , 
4, 0.258647, 1, 0, 0.338465,-0.00157191) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.969273,0.0101751) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.949492,-0.00220367) , 
3, -0.618033, 1, 0, 0.957531,0.001255) , 
4, 0.285857, 1, 0, 0.500816,-0.000830546)    );
  // itree = 489
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230036,-0.00474068) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362004,0.0022378) , 
4, 0.0615122, 1, 0, 0.315056,0.000622725) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.976885,0.00192516) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.889249,-0.00772286) , 
6, 2.24126, 1, 0, 0.941966,-0.00229117) , 
4, 0.257323, 1, 0, 0.49967,-0.000235365)    );
  // itree = 490
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.947387,0.00186467) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68143,-0.00740507) , 
6, 2.10152, 1, 0, 0.885459,-0.00221482) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.114891,-0.00355643) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.427218,0.00294587) , 
7, -1.42818, 1, 0, 0.340575,0.00133039) , 
3, -0.713502, 1, 0, 0.500005,0.000293083)    );
  // itree = 491
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.778279,0.00878878) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.844746,0.000113746) , 
4, 0.0290202, 1, 0, 0.838973,0.00077645) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.416082,-0.00677486) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.297008,-0.00100201) , 
3, 0.252129, 1, 0, 0.312492,-0.00168558) , 
3, -0.427943, 1, 0, 0.499885,-0.000809254)    );
  // itree = 492
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283731,0.00118632) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.756492,0.00895833) , 
4, 0.220627, 1, 0, 0.31311,0.00172079) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.925983,-0.00781862) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.987818,0.0147831) , 
4, 0.518409, 1, 0, 0.942012,-0.00276312) , 
4, 0.257347, 1, 0, 0.499542,0.000391577)    );
  // itree = 493
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.117385,0.00582057) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560531,-0.00150942) , 
8, -0.0771092, 1, 0, 0.497826,-0.000698766) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439789,0.00938748) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.631455,-0.00219632) , 
0, 137265, 1, 0, 0.53391,0.00408039) , 
1, 14.4762, 1, 0, 0.499701,-0.000450533)    );
  // itree = 494
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.880662,0.00673731) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.589315,-0.00216352) , 
1, 6.42857, 1, 0, 0.79439,0.00281343) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.274107,-0.00633113) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314903,0.00281666) , 
3, 0.950141, 1, 0, 0.29743,-0.00150042) , 
3, -0.0470449, 1, 0, 0.501354,0.00026974)    );
  // itree = 495
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340924,-0.0037578) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597149,0.00179339) , 
8, -0.0227596, 1, 0, 0.517196,0.00021571) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00953553,-0.0342524) , 
8, 0.300385, 1, 0, 0.50068,2.34362e-05)    );
  // itree = 496
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.995331,0.0469417) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.487924,0.00116308) , 
6, 0.397811, 1, 0, 0.51628,0.00130855) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.183401,-0.00575852) , 
6, 7.54854, 1, 0, 0.500681,0.00103078)    );
  // itree = 497
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508917,0.00959827) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.766106,-0.000841012) , 
7, -1.42796, 1, 0, 0.735576,0.000551418) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258059,-0.00714449) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319208,0.00154269) , 
3, 0.972803, 1, 0, 0.292133,-0.00196182) , 
3, 0.428823, 1, 0, 0.49977,-0.000785024)    );
  // itree = 498
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547508,-0.0101415) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496876,0.000633199) , 
2, 34365.9, 1, 0, 0.513842,-0.0025444) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0819464,-0.00620597) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806832,0.00758507) , 
4, 0.114669, 1, 0, 0.470678,0.00175016) , 
0, 64441.1, 1, 0, 0.497645,-0.000932908)    );
  // itree = 499
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.831841,0.00560567) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.6645,-0.00359041) , 
0, 64280.1, 1, 0, 0.793043,0.00301357) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339125,-0.0122655) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294115,-0.00134263) , 
3, 0.252112, 1, 0, 0.296642,-0.00158197) , 
3, -0.0471582, 1, 0, 0.499677,0.000297672)    );
  // itree = 500
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432396,0.00269347) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339922,-0.00148593) , 
0, 73869.8, 1, 0, 0.406268,0.00135613) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.964107,-0.0184273) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.987257,0.0144314) , 
3, -0.0470449, 1, 0, 0.976229,-0.00170464) , 
4, 0.400022, 1, 0, 0.502058,0.000841726)    );
  // itree = 501
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5709,-0.000327905) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235728,0.00953312) , 
6, 6.61931, 1, 0, 0.55078,0.000222478) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.840894,-0.0103641) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316612,-0.00136461) , 
1, 3.2381, 1, 0, 0.417152,-0.00207265) , 
7, 0.476399, 1, 0, 0.498684,-0.000672295)    );
  // itree = 502
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827746,-0.00376733) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.675099,0.00699546) , 
7, 1.397, 1, 0, 0.810778,-0.00228994) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421696,0.00890525) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298177,0.00121268) , 
3, 0.116211, 1, 0, 0.306225,0.0014571) , 
3, -0.237325, 1, 0, 0.501211,9.03822e-06)    );
  // itree = 503
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52944,-0.00216413) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440789,0.00272082) , 
0, 59044.6, 1, 0, 0.495653,-0.000385442) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579029,0.0105189) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510473,-0.00246929) , 
3, 0.715341, 1, 0, 0.534971,0.0044571) , 
1, 13.7143, 1, 0, 0.498492,-3.57852e-05)    );
  // itree = 504
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.923018,0.00555716) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.849817,-0.00350397) , 
3, -0.844661, 1, 0, 0.913029,0.00290361) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0659765,-0.0103061) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.398247,-3.99822e-05) , 
4, 0.0289804, 1, 0, 0.370058,-0.000447557) , 
3, -0.80839, 1, 0, 0.50003,0.000354617)    );
  // itree = 505
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.685503,0.0157498) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.910535,-0.00756342) , 
8, -0.0434559, 1, 0, 0.884464,-0.00161451) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0853965,0.00498313) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.762055,-0.000754225) , 
4, 0.142987, 1, 0, 0.388855,0.00173086) , 
1, 3.42857, 1, 0, 0.498551,0.000990416)    );
  // itree = 506
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.920907,0.00839121) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496232,-0.00352023) , 
6, 0.783909, 1, 0, 0.614313,-0.00141706) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.134582,0.00593009) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.913458,-0.006013) , 
5, 3.62695, 1, 0, 0.311338,0.00280009) , 
6, 2.60669, 1, 0, 0.498043,0.000201312)    );
  // itree = 507
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.45573,0.00662413) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0258942,-0.00203265) , 
3, 0.714846, 1, 0, 0.220199,0.00267518) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.846967,-0.00362716) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597859,0.00198276) , 
3, 0.619256, 1, 0, 0.738159,-0.00128699) , 
4, 0.114425, 1, 0, 0.500105,0.000534018)    );
  // itree = 508
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.780346,-0.00807163) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.955014,0.00608821) , 
4, 0.200332, 1, 0, 0.865557,-0.00331375) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311834,0.00171219) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492933,-0.00940502) , 
1, 13.3333, 1, 0, 0.328454,0.000396378) , 
3, -0.61816, 1, 0, 0.500055,-0.000788983)    );
  // itree = 509
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.703073,-0.00180827) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399797,0.00273766) , 
3, 0.809628, 1, 0, 0.584144,-0.000420953) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0398141,0.00785908) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.245354,-0.00760323) , 
8, -0.0857566, 1, 0, 0.200027,-0.00359682) , 
7, 1.42838, 1, 0, 0.498292,-0.00113077)    );
  // itree = 510
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0128102,-0.0367536) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.607902,0.00180917) , 
8, -0.244439, 1, 0, 0.588687,0.00123281) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501819,0.00521739) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.085981,-0.0178279) , 
3, 0.524713, 1, 0, 0.202809,-0.00354068) , 
7, 1.42885, 1, 0, 0.501747,0.000157329)    );
  // itree = 511
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.190716,-0.00564968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.594337,0.000883449) , 
7, -1.427, 1, 0, 0.507718,-0.000101478) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.189831,-0.0105092) , 
6, 9.01162, 1, 0, 0.499264,-0.000338707)    );
  // itree = 512
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.850084,0.00225782) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453009,-0.00657154) , 
6, 2.04238, 1, 0, 0.718045,-0.0020451) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333002,-0.0035647) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.261625,0.00599645) , 
6, 2.4804, 1, 0, 0.294733,0.000700647) , 
3, 0.524027, 1, 0, 0.498015,-0.000617909)    );
  // itree = 513
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.77878,-0.00641602) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0849704,0.000316606) , 
3, -0.61587, 1, 0, 0.26475,-0.0018677) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.916469,-0.000220741) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.731364,0.00984769) , 
6, 5.17626, 1, 0, 0.901795,0.00108423) , 
4, 0.200211, 1, 0, 0.497547,-0.000788969)    );
  // itree = 514
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00983338,-0.0276117) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530916,0.00162926) , 
8, -0.265002, 1, 0, 0.511189,0.00109661) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.205334,0.0126351) , 
6, 8.99917, 1, 0, 0.50277,0.00135977)    );
  // itree = 515
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285338,-0.000499168) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76277,0.00805678) , 
4, 0.220629, 1, 0, 0.314779,0.000253238) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971661,0.00132788) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.883723,-0.00807086) , 
6, 2.45812, 1, 0, 0.940579,-0.002297) , 
4, 0.257353, 1, 0, 0.50003,-0.000501689)    );
  // itree = 516
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529053,0.000788979) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0709928,-0.00524156) , 
3, 0.714487, 1, 0, 0.289323,-0.0011557) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.752375,0.0122856) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.945139,0.00142575) , 
7, -1.44313, 1, 0, 0.924853,0.00233001) , 
4, 0.228671, 1, 0, 0.498346,-9.26556e-06)    );
  // itree = 517
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.934817,0.000554143) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.712909,-0.00783961) , 
1, 6.42857, 1, 0, 0.885334,-0.00253802) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.137105,0.0033287) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.927075,-0.00407035) , 
4, 0.257323, 1, 0, 0.341265,0.00147331) , 
3, -0.713168, 1, 0, 0.50071,0.000297751)    );
  // itree = 518
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.993125,0.039728) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480849,0.00105311) , 
6, 0.423273, 1, 0, 0.513333,0.00115745) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181936,-0.00915425) , 
6, 8.07491, 1, 0, 0.500589,0.000826261)    );
  // itree = 519
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597526,0.00633253) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.802874,-0.00354515) , 
4, 0.0575781, 1, 0, 0.760678,-0.00162257) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354699,-0.0034617) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266116,0.00828784) , 
6, 2.08537, 1, 0, 0.298712,0.00205297) , 
3, 0.23843, 1, 0, 0.501519,0.000439374)    );
  // itree = 520
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468509,-0.00012098) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.979477,-0.0267472) , 
4, 0.542862, 1, 0, 0.495641,-0.000401004) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580288,0.00801269) , 
1, 16.2857, 1, 0, 0.497935,-0.000157854)    );
  // itree = 521
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.188987,-0.00177533) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527022,-0.0169207) , 
5, 1.60575, 1, 0, 0.232317,-0.00238845) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.659459,-0.000662525) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507399,0.00351797) , 
1, 6.85714, 1, 0, 0.579825,0.00152476) , 
4, 0.0574332, 1, 0, 0.500728,0.000634072)    );
  // itree = 522
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534329,0.000346295) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356207,-0.00490726) , 
1, 8.85714, 1, 0, 0.484313,-0.00103776) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.84943,-0.0100467) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492713,0.00940996) , 
6, 3.17995, 1, 0, 0.614991,0.00358286) , 
0, 122740, 1, 0, 0.498451,-0.000537872)    );
  // itree = 523
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.206708,-0.00772869) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0918823,0.0152388) , 
6, 5.43405, 1, 0, 0.188863,-0.00275535) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238367,-0.00428725) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.653952,0.00256609) , 
8, -0.0529439, 1, 0, 0.58984,0.0014268) , 
7, -1.42816, 1, 0, 0.503128,0.000522394)    );
  // itree = 524
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669324,0.000981334) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.157096,0.0234598) , 
7, 2.37988, 1, 0, 0.62633,0.00224749) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.263453,-0.0106543) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347936,0.0106778) , 
3, 0.995468, 1, 0, 0.302015,-0.00129447) , 
3, 0.904821, 1, 0, 0.500085,0.000868726)    );
  // itree = 525
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.726198,-0.00333613) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0885913,0.00091104) , 
3, -0.332389, 1, 0, 0.290673,-0.000941579) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.940812,0.00130392) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.778364,0.00754298) , 
6, 5.17278, 1, 0, 0.927797,0.00152972) , 
4, 0.228675, 1, 0, 0.501393,-0.000124229)    );
  // itree = 526
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0946429,0.0332414) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.746643,-0.00013241) , 
7, -3.32394, 1, 0, 0.697471,0.0012042) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463468,-0.00318922) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322929,-0.000819441) , 
3, 0.810468, 1, 0, 0.381157,-0.00185821) , 
1, 5.14286, 1, 0, 0.498877,-0.000718494)    );
  // itree = 527
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542265,0.00486255) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.89197,-0.00142634) , 
4, 0.142985, 1, 0, 0.736392,0.00190393) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.18136,-0.00819706) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384001,0.00104687) , 
0, 59046.1, 1, 0, 0.289014,-0.00215676) , 
3, 0.428946, 1, 0, 0.495422,-0.000283272)    );
  // itree = 528
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.692872,0.00595072) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0988356,-0.00855669) , 
3, -0.332724, 1, 0, 0.191414,-0.00223017) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.839267,-0.00106806) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.39657,0.00378409) , 
3, -0.332503, 1, 0, 0.587007,0.00120693) , 
7, -1.42818, 1, 0, 0.500614,0.000456303)    );
  // itree = 529
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.867246,0.00052689) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.7578,0.0107985) , 
7, 1.44679, 1, 0, 0.857297,0.00164407) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326082,-0.00406449) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304499,0.0015929) , 
3, 0.927483, 1, 0, 0.314053,-0.00131357) , 
3, -0.522861, 1, 0, 0.499985,-0.000301282)    );
  // itree = 530
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.855247,0.00506137) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.689689,-0.00498113) , 
0, 62559.6, 1, 0, 0.815829,0.00202598) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293252,-0.00323803) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310835,0.00252865) , 
3, 0.941071, 1, 0, 0.303312,-0.000519823) , 
3, -0.23755, 1, 0, 0.500622,0.000460268)    );
  // itree = 531
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570423,0.00143733) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353243,-0.00349715) , 
1, 7.14286, 1, 0, 0.506993,-2.3203e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557682,0.00651473) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0589719,-0.0203301) , 
7, 2.37669, 1, 0, 0.476048,0.0036813) , 
1, 10.7143, 1, 0, 0.501,0.000694247)    );
  // itree = 532
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590998,-0.000197016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0979301,0.0182329) , 
8, 0.101917, 1, 0, 0.539133,0.000681791) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0686831,0.00139362) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.783897,-0.00734524) , 
4, 0.143206, 1, 0, 0.420442,-0.00297594) , 
1, 8.57143, 1, 0, 0.499302,-0.000545699)    );
  // itree = 533
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.724333,-0.00359491) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0880045,0.000409051) , 
3, -0.332389, 1, 0, 0.287797,-0.00128431) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76695,0.00862063) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.946861,0.00171651) , 
7, -1.43086, 1, 0, 0.928334,0.00190355) , 
4, 0.228762, 1, 0, 0.49978,-0.000229301)    );
  // itree = 534
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.219164,2.31398e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.74303,0.0031317) , 
4, 0.114626, 1, 0, 0.498996,0.00142826) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548405,-0.00760782) , 
1, 15.4286, 1, 0, 0.500761,0.00109898)    );
  // itree = 535
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570724,0.000238163) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244132,0.00595552) , 
6, 3.7004, 1, 0, 0.51912,0.000807647) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0414394,0.00521773) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.652488,-0.00382934) , 
4, 0.0862669, 1, 0, 0.447328,-0.00172035) , 
1, 9.04762, 1, 0, 0.500762,0.000161218)    );
  // itree = 536
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570773,0.00392968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0150709,-0.0269568) , 
1, 6.52381, 1, 0, 0.280975,-0.00413746) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25751,-0.000822089) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.891899,0.00315231) , 
4, 0.191952, 1, 0, 0.520311,0.000500938) , 
4, 0.0287371, 1, 0, 0.4996,9.95601e-05)    );
  // itree = 537
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238603,-0.00711193) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608938,0.0015448) , 
8, -0.0380738, 1, 0, 0.521637,-9.01035e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00759707,-0.0393289) , 
8, 0.285699, 1, 0, 0.503395,-0.0003082)    );
  // itree = 538
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.809828,0.0145691) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.860604,0.000649103) , 
4, 0.0290308, 1, 0, 0.855997,0.00172206) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.30223,-0.000120579) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496582,-0.00978962) , 
1, 15, 1, 0, 0.315143,-0.00061697) , 
3, -0.523139, 1, 0, 0.5009,0.00018637)    );
  // itree = 539
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893769,-0.00420793) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409903,0.000900168) , 
1, 3.61905, 1, 0, 0.520474,0.000109811) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0184843,-0.0237144) , 
7, 7.14193, 1, 0, 0.501451,-0.000135283)    );
  // itree = 540
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.980384,0.00858253) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.917316,-0.00840101) , 
3, -0.953791, 1, 0, 0.939528,-0.00313021) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75803,0.00225282) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305567,-0.000914684) , 
3, -0.269272, 1, 0, 0.437282,0.000344382) , 
3, -0.903924, 1, 0, 0.502161,-0.000104459)    );
  // itree = 541
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.969445,0.0205354) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500659,0.000684046) , 
6, 0.597752, 1, 0, 0.568497,0.00123762) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.611894,0.00631343) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.206897,-0.00559694) , 
3, -0.712234, 1, 0, 0.254866,-0.00175026) , 
6, 3.81472, 1, 0, 0.500547,0.000590282)    );
  // itree = 542
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.398365,0.00994854) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0804618,-0.00858631) , 
0, 58185.4, 1, 0, 0.240093,0.00145354) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.719257,-0.00303239) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394817,0.00187906) , 
3, 0.809657, 1, 0, 0.579467,-0.00127838) , 
4, 0.0572999, 1, 0, 0.50092,-0.000646081)    );
  // itree = 543
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235355,-0.00104174) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442487,0.00605102) , 
4, 0.155228, 1, 0, 0.245924,-0.000343521) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540406,-0.00443983) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.895712,0.00478339) , 
4, 0.191951, 1, 0, 0.868134,0.00253766) , 
4, 0.17155, 1, 0, 0.50223,0.000843317)    );
  // itree = 544
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.71597,0.0165721) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.015616,-0.00865466) , 
3, 0.0494875, 1, 0, 0.3008,0.00404543) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.761061,-0.00176939) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31973,0.00137056) , 
3, 0.333638, 1, 0, 0.518986,-0.000341553) , 
4, 0.0289262, 1, 0, 0.499829,4.36258e-05)    );
  // itree = 545
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605006,-0.00361661) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42393,0.000763377) , 
0, 40811.2, 1, 0, 0.492241,-0.000745377) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.725713,0.0126554) , 
0, 191035, 1, 0, 0.49988,-0.000446926)    );
  // itree = 546
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.730421,0.00331806) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334859,-0.00424025) , 
3, 0.904803, 1, 0, 0.604644,0.00129007) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0654562,0.00223836) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.73528,-0.00563682) , 
4, 0.171738, 1, 0, 0.29906,-0.00154883) , 
6, 2.82712, 1, 0, 0.498644,0.000305328)    );
  // itree = 547
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510495,-0.000676726) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163882,-0.010131) , 
6, 7.549, 1, 0, 0.497788,-0.000758139) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529115,0.0118471) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550542,-0.00655691) , 
3, 0.905113, 1, 0, 0.540217,0.00546783) , 
1, 15, 1, 0, 0.500055,-0.000425475)    );
  // itree = 548
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.606036,-0.00181737) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426439,0.00191183) , 
0, 40811.2, 1, 0, 0.493732,0.000365943) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.726682,0.0106808) , 
0, 191035, 1, 0, 0.501606,0.000598366)    );
  // itree = 549
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.962276,0.00976086) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458298,-0.00227309) , 
6, 0.623481, 1, 0, 0.526447,-0.00137318) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.029788,-0.00128758) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584235,0.0106395) , 
4, 0.143503, 1, 0, 0.202773,0.00509417) , 
6, 6.02605, 1, 0, 0.499503,-0.000834828)    );
  // itree = 550
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.161538,-0.000443093) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.520492,-0.00908886) , 
5, 2.15342, 1, 0, 0.215538,-0.00166814) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.7337,0.00228242) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.898206,-0.0114616) , 
0, 188371, 1, 0, 0.741528,0.00162523) , 
4, 0.114417, 1, 0, 0.499574,0.000110289)    );
  // itree = 551
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.81462,-0.00523114) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.960522,0.0053016) , 
4, 0.200185, 1, 0, 0.885734,-0.00169511) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.672541,0.00627031) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319755,0.000536314) , 
3, -0.550014, 1, 0, 0.341981,0.000941323) , 
3, -0.713219, 1, 0, 0.498011,0.000184798)    );
  // itree = 552
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.213302,-0.00067253) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.271388,0.00481863) , 
4, 0.0955449, 1, 0, 0.228195,0.00102168) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617505,-0.00779751) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.849644,-0.000449785) , 
8, -0.0307005, 1, 0, 0.805445,-0.00182574) , 
4, 0.143141, 1, 0, 0.497998,-0.000309184)    );
  // itree = 553
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.615845,-0.00442424) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42289,0.00231655) , 
0, 38962.9, 1, 0, 0.490508,-7.97211e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.685905,-0.0150325) , 
0, 171609, 1, 0, 0.499315,-0.000542256)    );
  // itree = 554
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491712,-0.00193171) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544222,0.00366634) , 
0, 101502, 1, 0, 0.49886,-0.00102644) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538132,0.010969) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560543,-0.00536801) , 
3, 0.905113, 1, 0, 0.549512,0.00538602) , 
1, 14.4762, 1, 0, 0.501518,-0.00068995)    );
  // itree = 555
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414958,-0.00611167) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.631017,0.00104972) , 
8, -0.0217767, 1, 0, 0.568571,-0.000743808) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489269,0.00781581) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208636,-0.00121114) , 
3, -0.237529, 1, 0, 0.262092,0.0019859) , 
6, 3.80828, 1, 0, 0.501879,-0.000149808)    );
  // itree = 556
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4,-0.00980267) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.587334,0.00121805) , 
4, 0.0288779, 1, 0, 0.57248,0.000371641) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0594683,-0.000956635) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.767438,-0.00830349) , 
4, 0.20042, 1, 0, 0.256838,-0.00327406) , 
6, 3.80824, 1, 0, 0.503367,-0.000426618)    );
  // itree = 557
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504047,-0.000593943) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.6179,0.00760482) , 
1, 14.1429, 1, 0, 0.508985,-0.000110223) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.185833,-0.00740874) , 
6, 8.40124, 1, 0, 0.49808,-0.000306509)    );
  // itree = 558
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437465,-0.0108141) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0508433,0.00070903) , 
6, 1.96045, 1, 0, 0.230756,-0.0035045) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599335,0.000110694) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.291915,-0.00500348) , 
6, 6.03231, 1, 0, 0.577812,-0.000295034) , 
4, 0.0572943, 1, 0, 0.497847,-0.00103452)    );
  // itree = 559
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.225123,0.00221455) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.352923,0.0151899) , 
4, 0.129575, 1, 0, 0.232925,0.00261199) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.864106,-0.00340893) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.712317,0.00395578) , 
3, 0.809607, 1, 0, 0.807168,-0.000926757) , 
4, 0.143174, 1, 0, 0.501026,0.00095983)    );
  // itree = 560
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.607756,-0.00285692) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.410006,0.00266948) , 
0, 40811, 1, 0, 0.488425,0.000332765) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368793,-0.0118222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.987828,0.0280965) , 
4, 0.314375, 1, 0, 0.634314,-0.00398373) , 
0, 135690, 1, 0, 0.500699,-3.03908e-05)    );
  // itree = 561
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484757,0.00842962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0134101,-0.0108421) , 
3, 0.714966, 1, 0, 0.24067,0.00214789) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.812895,-0.00320651) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392566,0.00132839) , 
3, 0.143416, 1, 0, 0.580235,-0.000921984) , 
4, 0.0572999, 1, 0, 0.501166,-0.000207149)    );
  // itree = 562
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69652,0.00665906) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.219151,-0.00227715) , 
3, 0.428976, 1, 0, 0.413955,0.00220756) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.742983,-0.00300661) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351063,0.00123274) , 
3, 0.52412, 1, 0, 0.553158,-0.00117522) , 
7, -0.476056, 1, 0, 0.500215,0.000111346)    );
  // itree = 563
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.520405,-0.00266674) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.452631,0.00158021) , 
0, 63250.6, 1, 0, 0.495989,-0.00100781) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549622,-0.00680624) , 
1, 15.4286, 1, 0, 0.498049,-0.00123397)    );
  // itree = 564
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334357,0.0215448) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0469344,-0.00899632) , 
3, 0.714868, 1, 0, 0.11863,0.00341264) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680933,0.00221539) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.370212,-0.00462127) , 
8, 0.0221806, 1, 0, 0.563418,-4.75326e-05) , 
8, -0.0765395, 1, 0, 0.49998,0.000445973)    );
  // itree = 565
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.761678,0.00437483) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.975537,-0.0433242) , 
4, 0.428584, 1, 0, 0.791057,0.00150524) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0286396,-0.0181736) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.413241,-2.26248e-05) , 
4, 0.0287367, 1, 0, 0.381458,-0.000683656) , 
1, 4.28571, 1, 0, 0.500729,-4.62688e-05)    );
  // itree = 566
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366747,0.0168376) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696329,-0.00250851) , 
8, -0.0568786, 1, 0, 0.661984,-0.000501943) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363083,0.00517056) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.030022,-0.0234881) , 
8, 0.103543, 1, 0, 0.298422,0.00129833) , 
3, 0.809648, 1, 0, 0.500365,0.000298359)    );
  // itree = 567
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.14156,0.00795086) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0257309,-0.0243377) , 
3, 0.905147, 1, 0, 0.0652776,-0.00229376) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.837918,-0.00258251) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.461352,0.00234003) , 
1, 4.28571, 1, 0, 0.58164,0.000967454) , 
7, -2.37828, 1, 0, 0.503821,0.00047597)    );
  // itree = 568
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.842962,-0.000664178) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333235,0.003803) , 
3, -0.332503, 1, 0, 0.534724,0.00132366) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37126,0.00497551) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.149488,-0.0103844) , 
3, 0.23892, 1, 0, 0.204489,-0.00198349) , 
6, 5.39687, 1, 0, 0.498784,0.000963732)    );
  // itree = 569
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555689,-0.00236065) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407698,0.00226338) , 
0, 51353.5, 1, 0, 0.488453,-0.000267768) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.637948,0.00210548) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.656914,0.0128681) , 
1, 13.7143, 1, 0, 0.645218,0.00485769) , 
0, 135690, 1, 0, 0.501713,0.000165774)    );
  // itree = 570
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590447,-0.00206909) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382015,0.004731) , 
6, 3.07977, 1, 0, 0.56732,-0.000976572) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304496,0.00784332) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.24159,-0.0101909) , 
1, 6.42857, 1, 0, 0.254407,-0.00503801) , 
6, 3.79489, 1, 0, 0.499675,-0.00185457)    );
  // itree = 571
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525147,0.00540876) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0192043,-0.00332754) , 
3, 0.430351, 1, 0, 0.218977,0.00158707) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.634893,-0.00205342) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.864488,0.00578375) , 
0, 135690, 1, 0, 0.657189,-0.00133198) , 
4, 0.0859891, 1, 0, 0.499736,-0.000283142)    );
  // itree = 572
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.609,0.00402302) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.196613,-0.00327768) , 
6, 2.5367, 1, 0, 0.503845,0.00163681) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616854,-0.0086796) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442998,0.00308755) , 
3, 0.333627, 1, 0, 0.492302,-0.00171404) , 
0, 75587.8, 1, 0, 0.50048,0.000659866)    );
  // itree = 573
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519783,-0.00161927) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456612,0.0031493) , 
0, 64441.1, 1, 0, 0.498879,-0.000171461) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.132637,0.00141243) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.825311,-0.01222) , 
4, 0.172251, 1, 0, 0.518367,-0.00535171) , 
1, 13.7143, 1, 0, 0.50031,-0.000551738)    );
  // itree = 574
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357076,-0.00167203) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0669178,0.00446747) , 
6, 2.82712, 1, 0, 0.246786,6.92263e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.681539,0.00536978) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.952851,0.00344351) , 
4, 0.27367, 1, 0, 0.863791,0.00349376) , 
4, 0.171688, 1, 0, 0.501252,0.00148158)    );
  // itree = 575
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.138665,0.0094882) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0216867,-0.0286087) , 
3, 0.905147, 1, 0, 0.0611824,-0.00258997) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564192,-0.00022358) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.663016,0.00571027) , 
0, 108371, 1, 0, 0.57867,0.000437839) , 
7, -2.3811, 1, 0, 0.500706,-1.83239e-05)    );
  // itree = 576
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.793173,-0.00444501) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343236,0.00252658) , 
3, 0.0480381, 1, 0, 0.546666,-0.00109868) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445086,0.00580399) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389471,-0.0016947) , 
0, 65430.5, 1, 0, 0.424537,0.00240885) , 
7, 0.476513, 1, 0, 0.49882,0.000275432)    );
  // itree = 577
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0691301,0.00836045) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577497,-0.00113227) , 
7, -2.37888, 1, 0, 0.501081,-0.000296513) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582731,0.00984534) , 
1, 16.2857, 1, 0, 0.503223,-2.79709e-05)    );
  // itree = 578
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.650185,-0.00228661) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.177916,0.0189105) , 
8, 0.0997588, 1, 0, 0.620511,-0.00123003) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264541,-0.00820361) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32669,0.00952364) , 
3, 0.981869, 1, 0, 0.307385,0.0012412) , 
3, 0.904805, 1, 0, 0.499865,-0.000277874)    );
  // itree = 579
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.775847,0.00632129) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334957,-0.00380059) , 
3, 0.809607, 1, 0, 0.620804,0.00279457) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0484805,0.00398889) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577729,-0.00535311) , 
4, 0.114668, 1, 0, 0.306404,-0.00215352) , 
6, 2.59357, 1, 0, 0.500444,0.000900314)    );
  // itree = 580
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.406182,0.0178947) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0690839,-0.00407628) , 
3, 0.619489, 1, 0, 0.152863,0.00374954) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0800579,-0.00797756) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.637784,0.000236092) , 
7, -2.3805, 1, 0, 0.568516,-0.000314211) , 
8, -0.0621079, 1, 0, 0.499285,0.000362642)    );
  // itree = 581
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.88232,0.00385193) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.924859,-0.0117383) , 
2, 107259, 1, 0, 0.887751,0.00220583) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0947208,0.000800367) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.858808,-0.00529175) , 
4, 0.200245, 1, 0, 0.337934,-0.000902832) , 
3, -0.713531, 1, 0, 0.498753,6.44001e-06)    );
  // itree = 582
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.784561,0.00335504) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338355,-0.00170345) , 
6, 1.31633, 1, 0, 0.509029,-9.9027e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38383,-0.00679873) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.632211,0.00283971) , 
0, 126181, 1, 0, 0.46706,-0.00369261) , 
1, 10.7143, 1, 0, 0.50095,-0.000790755)    );
  // itree = 583
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235245,-0.00103698) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503611,0.00603247) , 
4, 0.152604, 1, 0, 0.269234,0.00034742) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.921176,-0.00179088) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.731735,-0.00746419) , 
6, 4.39527, 1, 0, 0.898523,-0.0021602) , 
4, 0.200207, 1, 0, 0.499665,-0.00057081)    );
  // itree = 584
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.794913,-0.00442472) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0682462,0.000549054) , 
3, -0.709668, 1, 0, 0.22983,-0.000877323) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.251125,0.00938967) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.852741,0.00228994) , 
7, -2.37991, 1, 0, 0.809828,0.00252921) , 
4, 0.142988, 1, 0, 0.50004,0.000709716)    );
  // itree = 585
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.635129,-0.00160326) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.446887,0.00382437) , 
1, 6.66667, 1, 0, 0.544986,0.000891715) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0239658,0.00211491) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399227,-0.00649059) , 
4, 0.0864552, 1, 0, 0.217626,-0.00386256) , 
6, 4.83203, 1, 0, 0.500626,0.000247465)    );
  // itree = 586
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.925015,0.00513021) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.846973,-0.0051922) , 
3, -0.854067, 1, 0, 0.911308,0.00203855) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.467953,-0.00279572) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.299717,-0.000295011) , 
3, 0.827741, 1, 0, 0.371699,-0.00148973) , 
3, -0.808727, 1, 0, 0.501413,-0.000641582)    );
  // itree = 587
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.299424,-0.00516266) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602952,0.00120988) , 
8, -0.0323959, 1, 0, 0.530139,-0.00011771) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0340514,-0.00243758) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.662992,0.0124087) , 
4, 0.171912, 1, 0, 0.206636,0.00469842) , 
6, 5.61442, 1, 0, 0.498187,0.000357973)    );
  // itree = 588
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.70365,0.00793657) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.846059,0.0011069) , 
4, 0.0572943, 1, 0, 0.817778,0.00248876) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288956,0.000584156) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501236,-0.0111206) , 
1, 14.4762, 1, 0, 0.302883,-0.000225663) , 
3, -0.237529, 1, 0, 0.500794,0.000817683)    );
  // itree = 589
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.250024,-0.00102101) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.703692,0.00313349) , 
4, 0.0858621, 1, 0, 0.551191,0.00160884) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.79334,0.00216763) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233103,-0.00725647) , 
3, -0.237417, 1, 0, 0.418447,-0.00215135) , 
7, 0.475852, 1, 0, 0.499574,0.000146693)    );
  // itree = 590
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.887585,0.00776337) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382601,-0.00134769) , 
6, 0.92093, 1, 0, 0.494333,-0.000144971) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.726407,0.011319) , 
0, 191035, 1, 0, 0.502096,0.000110216)    );
  // itree = 591
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.173555,0.000949904) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511553,-0.0135537) , 
5, 2.02307, 1, 0, 0.217311,-0.0011379) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420179,0.00266961) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.943702,-0.000734738) , 
4, 0.257238, 1, 0, 0.660689,0.00156634) , 
4, 0.0858625, 1, 0, 0.50125,0.000593895)    );
  // itree = 592
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.695573,-0.00294674) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.189889,0.0205465) , 
7, 2.38022, 1, 0, 0.659224,-0.00150274) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363596,0.00423662) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0243418,-0.0225738) , 
8, 0.111296, 1, 0, 0.301781,0.00105769) , 
3, 0.809607, 1, 0, 0.500482,-0.00036564)    );
  // itree = 593
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62077,0.00201835) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.193408,-0.00266781) , 
1, 5.42857, 1, 0, 0.357208,-0.000917903) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.976156,0.0112405) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.938235,-0.00300013) , 
8, 0.0270315, 1, 0, 0.968422,0.00270378) , 
4, 0.314362, 1, 0, 0.500015,-7.17167e-05)    );
  // itree = 594
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.649298,-0.00109967) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367055,0.00348709) , 
3, 0.904821, 1, 0, 0.549793,7.37511e-06) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0294297,-0.0200096) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0199288,0.0174999) , 
8, 0.090752, 1, 0, 0.0265798,-0.00371231) , 
7, 4.28614, 1, 0, 0.5008,-0.000340932)    );
  // itree = 595
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292502,0.000779516) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.234614,-0.00857223) , 
0, 135691, 1, 0, 0.289285,0.000153821) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.879307,0.00806751) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.978938,-0.00182518) , 
4, 0.405493, 1, 0, 0.928776,0.00343418) , 
4, 0.228676, 1, 0, 0.499574,0.00123253)    );
  // itree = 596
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68195,0.00213076) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316959,-0.00214257) , 
6, 1.93603, 1, 0, 0.499401,-0.000106529) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500988,-0.00785643) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.566256,-0.00749598) , 
1, 16.0952, 1, 0, 0.534036,-0.00740768) , 
1, 14.4762, 1, 0, 0.501172,-0.000479937)    );
  // itree = 597
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.853755,0.00474841) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971943,-0.0141194) , 
4, 0.428657, 1, 0, 0.874645,0.00314187) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.08702,0.00094399) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.856634,-0.00529334) , 
4, 0.200112, 1, 0, 0.329106,-0.000796766) , 
3, -0.618335, 1, 0, 0.504082,0.000466507)    );
  // itree = 598
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.685698,-0.00344953) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357933,0.00288796) , 
3, 0.809607, 1, 0, 0.550728,-0.00132348) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.644044,0.00577979) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.225957,-0.00287609) , 
3, 0.714442, 1, 0, 0.424936,0.00204296) , 
7, 0.476513, 1, 0, 0.50173,-1.21958e-05)    );
  // itree = 599
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588182,-0.00350473) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582748,0.00192404) , 
0, 75587.9, 1, 0, 0.586613,-0.00170399) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528963,0.00946784) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0940335,-0.00374802) , 
3, 0.429287, 1, 0, 0.205944,0.00167077) , 
7, 1.42885, 1, 0, 0.501137,-0.000946214)    );
  // itree = 600
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.870158,0.000620768) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524772,-0.00831851) , 
6, 1.98988, 1, 0, 0.791266,-0.0018897) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439675,0.00256361) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0212578,-0.0135022) , 
7, 3.3342, 1, 0, 0.379006,0.0015461) , 
1, 4.28571, 1, 0, 0.499105,0.000545188)    );
  // itree = 601
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893764,-0.000431468) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523833,-0.00820136) , 
6, 2.20537, 1, 0, 0.798679,-0.00388816) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286873,0.00785066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.300587,-0.00131653) , 
1, 5, 1, 0, 0.299106,8.9739e-05) , 
3, -0.142231, 1, 0, 0.496911,-0.0014853)    );
  // itree = 602
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.21644,-0.00869358) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0343298,0.0136556) , 
7, 2.38278, 1, 0, 0.163933,-0.00311998) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616225,0.00186334) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49667,-0.00227019) , 
7, 0.47543, 1, 0, 0.570692,0.000292019) , 
8, -0.0552996, 1, 0, 0.497813,-0.000319305)    );
  // itree = 603
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.168443,-0.000333185) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.644229,-0.00587555) , 
5, 2.60054, 1, 0, 0.245297,-0.00133051) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.59279,0.00698391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9007,0.00229278) , 
7, -1.42922, 1, 0, 0.864184,0.00246338) , 
4, 0.17155, 1, 0, 0.498836,0.000223728)    );
  // itree = 604
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.938341,-0.00221531) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.632448,0.0053254) , 
1, 4.28571, 1, 0, 0.806402,0.00279192) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390473,0.00117694) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.10089,-0.00814435) , 
7, 1.43049, 1, 0, 0.303217,-0.000440958) , 
3, -0.142354, 1, 0, 0.503251,0.00084423)    );
  // itree = 605
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.78292,-0.00371494) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533369,0.00503859) , 
8, 0.0567469, 1, 0, 0.761315,-0.00289443) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28091,0.000847236) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513301,-0.0154587) , 
1, 15.4286, 1, 0, 0.291954,-7.01378e-05) , 
3, 0.238444, 1, 0, 0.497584,-0.00130748)    );
  // itree = 606
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.824208,0.00359486) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543672,0.0118816) , 
6, 3.05487, 1, 0, 0.797122,0.00323913) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.81242,-0.00729145) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358794,-3.19823e-05) , 
3, -0.902664, 1, 0, 0.378803,-0.000481699) , 
1, 4.28571, 1, 0, 0.500486,0.000600628)    );
  // itree = 607
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.237214,-0.00103968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.441891,0.00900192) , 
4, 0.155226, 1, 0, 0.247635,-0.000148488) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.731344,0.00574141) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.966238,0.00123296) , 
4, 0.314364, 1, 0, 0.864767,0.00336545) , 
4, 0.17155, 1, 0, 0.501978,0.00129974)    );
  // itree = 608
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.981242,0.0234388) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75316,-0.00283026) , 
3, -0.948906, 1, 0, 0.781325,-0.00179991) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230114,0.00992596) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316791,0.000696053) , 
1, 5.42857, 1, 0, 0.300138,0.00163715) , 
3, 0.0482119, 1, 0, 0.501807,0.000196655)    );
  // itree = 609
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0636933,-0.013026) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605257,0.00105905) , 
7, -2.37956, 1, 0, 0.529832,-2.68656e-06) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343313,0.0145816) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.141258,-0.00106798) , 
3, 0.524027, 1, 0, 0.202166,0.00616175) , 
6, 6.01287, 1, 0, 0.502623,0.000509204)    );
  // itree = 610
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.727768,0.00288406) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217535,-0.00509707) , 
3, 0.238573, 1, 0, 0.412942,-0.000539934) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.783166,-0.00120988) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350896,0.00569998) , 
3, 0.238569, 1, 0, 0.55654,0.001352) , 
7, -0.475313, 1, 0, 0.502169,0.000635651)    );
  // itree = 611
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582443,-0.00208133) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.417769,0.0015591) , 
0, 44877.3, 1, 0, 0.490551,-9.35367e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.907245,-0.00172743) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496359,0.0159872) , 
6, 4.04886, 1, 0, 0.697911,0.00693993) , 
0, 164141, 1, 0, 0.501176,0.00026686)    );
  // itree = 612
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22529,0.00115902) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337038,-0.0036964) , 
7, -0.473913, 1, 0, 0.291362,-0.0017256) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.938075,-0.00205313) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.917703,0.00937103) , 
3, 0.428884, 1, 0, 0.929499,0.00125675) , 
4, 0.228794, 1, 0, 0.502564,-0.00073854)    );
  // itree = 613
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.734874,0.000595637) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407284,-0.00656226) , 
6, 1.57107, 1, 0, 0.609529,-0.00206823) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325695,0.00230499) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.17565,-0.00874168) , 
6, 7.81993, 1, 0, 0.308085,0.000903842) , 
6, 2.71882, 1, 0, 0.500236,-0.00099067)    );
  // itree = 614
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.254509,-0.00317404) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.650266,0.00278382) , 
4, 0.185349, 1, 0, 0.289984,-0.0020275) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.765087,0.0112673) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.945339,-0.000411779) , 
7, -1.426, 1, 0, 0.92669,0.00131021) , 
4, 0.228861, 1, 0, 0.499145,-0.00093105)    );
  // itree = 615
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401774,0.00135214) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0770606,-0.0148165) , 
0, 58185.8, 1, 0, 0.239306,-0.00288306) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.188593,-0.00206063) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.725507,0.00138185) , 
4, 0.109151, 1, 0, 0.578197,0.000439435) , 
4, 0.0574807, 1, 0, 0.498625,-0.000340694)    );
  // itree = 616
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.846999,0.000270479) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.832474,0.00707333) , 
7, 0.488214, 1, 0, 0.842273,0.00238883) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0734282,0.000833892) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.853918,-0.00464528) , 
4, 0.200197, 1, 0, 0.311467,-0.000674524) , 
3, -0.427674, 1, 0, 0.501366,0.000421407)    );
  // itree = 617
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.871328,0.00275679) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305948,-0.000736112) , 
3, -0.617987, 1, 0, 0.489832,0.000441921) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694325,-0.00842058) , 
0, 176762, 1, 0, 0.498456,0.000193453)    );
  // itree = 618
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.790256,-0.0014512) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0866259,0.00503358) , 
3, -0.615188, 1, 0, 0.270334,0.00215784) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.657295,-0.00983065) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918928,-0.000847956) , 
4, 0.21929, 1, 0, 0.900247,-0.00148799) , 
4, 0.200246, 1, 0, 0.502,0.000816992)    );
  // itree = 619
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.218343,0.00148632) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591081,-0.0021377) , 
4, 0.114415, 1, 0, 0.374804,-0.000516704) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.96911,0.00269594) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.990217,0.0371665) , 
0, 126620, 1, 0, 0.972952,0.00219549) , 
4, 0.342901, 1, 0, 0.499884,5.04493e-05)    );
  // itree = 620
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.704551,0.00277354) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.125955,-0.0019607) , 
3, 0.143801, 1, 0, 0.358874,0.000560691) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.953532,-0.0131994) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.97489,0.00892111) , 
3, 0.23843, 1, 0, 0.963674,-0.00214271) , 
4, 0.314414, 1, 0, 0.50095,-7.43764e-05)    );
  // itree = 621
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546446,0.0188577) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0722909,-0.00286044) , 
3, 0.144606, 1, 0, 0.154329,0.00333414) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.691455,0.000780748) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281061,-0.00414471) , 
8, 0.0358714, 1, 0, 0.569201,-0.00034494) , 
8, -0.0621079, 1, 0, 0.501124,0.000258763)    );
  // itree = 622
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.757324,0.00325777) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.18737,-0.00987471) , 
3, 0.904813, 1, 0, 0.624535,0.00105572) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432049,-0.0044221) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350648,0.00387774) , 
3, 0.905113, 1, 0, 0.388918,-0.00135537) , 
1, 6.42857, 1, 0, 0.50039,-0.000214668)    );
  // itree = 623
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498664,0.000436216) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.446833,-0.00357546) , 
1, 12, 1, 0, 0.492273,-0.0001287) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.725395,0.010647) , 
0, 191742, 1, 0, 0.49993,0.000100354)    );
  // itree = 624
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47435,0.000887825) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.977924,-0.022416) , 
4, 0.542884, 1, 0, 0.500011,0.000394734) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316282,-0.00548643) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.96651,0.0109044) , 
4, 0.343176, 1, 0, 0.503766,-0.00340477) , 
1, 12.8571, 1, 0, 0.500399,1.79146e-06)    );
  // itree = 625
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75503,7.37835e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580138,-0.00718529) , 
0, 75587.9, 1, 0, 0.720582,-0.00158434) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0746508,-0.001463) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.921358,0.0127202) , 
4, 0.228782, 1, 0, 0.294785,0.000969185) , 
3, 0.52407, 1, 0, 0.499514,-0.000258586)    );
  // itree = 626
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233304,0.00144148) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.188465,0.0124565) , 
4, 0.0655873, 1, 0, 0.222287,0.00276863) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0238841,-0.0313242) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.685696,-0.000650783) , 
8, -0.209744, 1, 0, 0.659359,-0.00100711) , 
4, 0.0859891, 1, 0, 0.501934,0.000352839)    );
  // itree = 627
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.796628,0.0036614) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351149,-0.000860079) , 
1, 4.19048, 1, 0, 0.500192,0.000334724) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.615361,0.00850573) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.45636,0.00141851) , 
3, 0.146583, 1, 0, 0.494226,0.0039979) , 
1, 11.6667, 1, 0, 0.499361,0.000844928)    );
  // itree = 628
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.299184,-0.00844422) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475164,0.000414526) , 
8, -0.0161685, 1, 0, 0.410689,-0.00196896) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.731059,0.00325781) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.103565,-0.00452065) , 
7, 2.01907, 1, 0, 0.555947,0.00158554) , 
7, -0.474585, 1, 0, 0.501065,0.000242574)    );
  // itree = 629
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28629,0.00547677) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0670313,-0.00805261) , 
7, 1.42779, 1, 0, 0.220798,0.0021407) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.773224,-0.00417516) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493274,0.000487555) , 
3, 0.809608, 1, 0, 0.658214,-0.00240517) , 
4, 0.0859891, 1, 0, 0.500812,-0.000769363)    );
  // itree = 630
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569896,-0.00140375) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.682113,-0.00619918) , 
7, 0.886091, 1, 0, 0.581705,-0.00168461) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35304,0.00738889) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0893814,-0.0104558) , 
3, 0.904881, 1, 0, 0.207104,0.000969612) , 
7, 1.43037, 1, 0, 0.497383,-0.00108715)    );
  // itree = 631
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.154696,0.0224345) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0252009,-0.0191821) , 
3, 0.904829, 1, 0, 0.0685284,0.00235269) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.834252,-0.0044042) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455714,0.00141246) , 
1, 5, 1, 0, 0.576188,-1.68163e-05) , 
7, -2.38102, 1, 0, 0.499335,0.000341896)    );
  // itree = 632
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.863335,0.00169911) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57268,0.00856653) , 
3, -0.563933, 1, 0, 0.842711,0.00233564) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455833,0.00751356) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.300439,-0.00204666) , 
1, 3.61905, 1, 0, 0.309121,-0.000676947) , 
3, -0.427918, 1, 0, 0.498287,0.000391061)    );
  // itree = 633
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827296,-0.00190992) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.637355,0.00648877) , 
8, 0.0567469, 1, 0, 0.812796,-0.00109523) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.408944,0.00709329) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294105,0.000532795) , 
3, 0.11607, 1, 0, 0.301642,0.000894971) , 
3, -0.23755, 1, 0, 0.498562,0.000128255)    );
  // itree = 634
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433313,-0.00592482) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.891947,0.00336331) , 
4, 0.171663, 1, 0, 0.621781,-0.00203527) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442644,0.00206754) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0318744,-0.0168277) , 
8, 0.119784, 1, 0, 0.39367,0.000990971) , 
1, 6.42857, 1, 0, 0.501677,-0.000441913)    );
  // itree = 635
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.695467,0.000729846) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389829,-0.00261181) , 
6, 1.82842, 1, 0, 0.56857,-0.000664028) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0334988,-0.00455634) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551671,0.00726875) , 
4, 0.114894, 1, 0, 0.263731,0.00316318) , 
6, 3.79489, 1, 0, 0.501963,0.000172212)    );
  // itree = 636
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488437,-0.00190599) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558184,0.00430744) , 
0, 105860, 1, 0, 0.49633,-0.00105374) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.135678,0.00561284) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.831753,-0.000930478) , 
4, 0.172243, 1, 0, 0.528025,0.00213648) , 
1, 13.7143, 1, 0, 0.498644,-0.000820812)    );
  // itree = 637
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.652525,0.000211615) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167406,0.0238243) , 
8, 0.107798, 1, 0, 0.625496,0.00112142) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.245127,-0.0232481) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309919,-0.000373016) , 
3, 0.941073, 1, 0, 0.303689,-0.00169883) , 
3, 0.904805, 1, 0, 0.499689,1.88713e-05)    );
  // itree = 638
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0950161,0.0290127) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.744735,-0.00364396) , 
7, -3.32888, 1, 0, 0.696289,-0.00142075) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456119,0.00319644) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.043024,-0.0145485) , 
7, 2.38197, 1, 0, 0.380379,0.00155724) , 
1, 5.42857, 1, 0, 0.499111,0.000437996)    );
  // itree = 639
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252203,0.000115669) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.865932,-0.00287616) , 
4, 0.17154, 1, 0, 0.498419,-0.000795248) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181818,0.00995385) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.855527,-0.000954601) , 
4, 0.200731, 1, 0, 0.533625,0.00493615) , 
1, 14.4762, 1, 0, 0.50027,-0.000493835)    );
  // itree = 640
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501927,0.00745126) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.103218,-0.0246018) , 
0, 57280.2, 1, 0, 0.288431,-0.00366673) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501328,0.000193983) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.686725,0.00719525) , 
0, 126175, 1, 0, 0.519648,0.00063314) , 
4, 0.0289284, 1, 0, 0.498895,0.000247212)    );
  // itree = 641
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.987697,0.00136493) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.824366,-0.00956907) , 
1, 3.2381, 1, 0, 0.938393,-0.00375504) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41271,0.00032061) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.600858,0.00733206) , 
0, 122739, 1, 0, 0.434892,0.00076097) , 
3, -0.903891, 1, 0, 0.499499,0.000181491)    );
  // itree = 642
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.810664,-0.00118851) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330656,0.00254526) , 
3, 0.238627, 1, 0, 0.566654,0.00025151) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0748552,-0.00149603) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.799103,-0.00862559) , 
5, 2.45189, 1, 0, 0.252988,-0.00319858) , 
6, 3.79441, 1, 0, 0.498328,-0.000500024)    );
  // itree = 643
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.822504,-0.00925166) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.942835,0.00938028) , 
4, 0.143363, 1, 0, 0.885885,-0.00112148) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0153687,-0.0224742) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424979,0.00235156) , 
7, -5.23597, 1, 0, 0.389183,0.00152344) , 
1, 3.61905, 1, 0, 0.498378,0.000941979)    );
  // itree = 644
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.122958,0.00594861) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48165,-0.00555701) , 
8, -0.0584639, 1, 0, 0.409832,-0.00305124) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580723,0.00165231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.225404,-0.00660812) , 
6, 6.01332, 1, 0, 0.554072,0.000806443) , 
7, -0.475045, 1, 0, 0.499568,-0.000651254)    );
  // itree = 645
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.819577,-0.00298573) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.947391,0.0181728) , 
4, 0.143077, 1, 0, 0.887889,0.00271373) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.101722,0.00229799) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.829974,-0.00244872) , 
4, 0.17155, 1, 0, 0.389742,0.000276048) , 
1, 3.61905, 1, 0, 0.500331,0.000817213)    );
  // itree = 646
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.693946,-0.0026269) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.192269,0.0145583) , 
7, 2.37899, 1, 0, 0.658728,-0.0015996) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341327,-0.00415811) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.279374,0.00660115) , 
6, 2.10147, 1, 0, 0.30251,0.0010717) , 
3, 0.809607, 1, 0, 0.500695,-0.000414504)    );
  // itree = 647
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.490411,-0.000934427) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.641694,0.00555232) , 
0, 103881, 1, 0, 0.51114,-0.000145956) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.18915,-0.0112743) , 
6, 9.01208, 1, 0, 0.502351,-0.000408421)    );
  // itree = 648
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827929,0.000566253) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46442,0.00738184) , 
3, -0.364277, 1, 0, 0.792282,0.0014647) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.331887,-0.0141599) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294865,-0.00182941) , 
3, 0.20232, 1, 0, 0.296594,-0.00181255) , 
3, -0.0469624, 1, 0, 0.498076,-0.000480451)    );
  // itree = 649
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.568961,0.00254326) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497266,-0.00235604) , 
1, 9.04762, 1, 0, 0.550997,0.000963164) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423181,-0.00576577) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396939,0.00464874) , 
1, 10.7143, 1, 0, 0.418083,-0.00254949) , 
7, 0.476767, 1, 0, 0.498931,-0.000412852)    );
  // itree = 650
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.958727,-0.00186858) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.717839,0.00331688) , 
1, 4.71429, 1, 0, 0.871591,0.00135009) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458609,-0.00351806) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.297222,-0.000393755) , 
3, 0.306601, 1, 0, 0.326802,-0.00105977) , 
3, -0.618033, 1, 0, 0.503061,-0.000280095)    );
  // itree = 651
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.670495,0.00332729) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.958667,-0.00828882) , 
4, 0.343025, 1, 0, 0.739491,0.00209067) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329218,-0.00563129) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.259399,0.00330845) , 
6, 2.36907, 1, 0, 0.290161,-0.000562478) , 
3, 0.42893, 1, 0, 0.498672,0.000668716)    );
  // itree = 652
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.220183,0.00303614) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.200861,0.0213899) , 
4, 0.0776978, 1, 0, 0.218319,0.00307879) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.936379,0.00427543) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554631,-0.00142716) , 
3, -0.808389, 1, 0, 0.656083,-0.000227816) , 
4, 0.0858625, 1, 0, 0.498127,0.000965283)    );
  // itree = 653
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316615,-0.00282599) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877546,0.00163455) , 
4, 0.171534, 1, 0, 0.535567,-0.000936266) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.415833,0.00234869) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551742,-0.0055171) , 
1, 15.8571, 1, 0, 0.43119,0.00104893) , 
1, 8.57143, 1, 0, 0.500249,-0.000264521)    );
  // itree = 654
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.822048,0.00595777) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.239169,-0.000368793) , 
3, -0.427676, 1, 0, 0.414353,0.00166391) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616851,-0.000522521) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295237,-0.00524919) , 
6, 3.80923, 1, 0, 0.553458,-0.00119) , 
7, -0.47632, 1, 0, 0.500661,-0.0001068)    );
  // itree = 655
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230168,-0.00265502) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669664,0.00120669) , 
4, 0.0860338, 1, 0, 0.514831,8.57075e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181878,-0.0102438) , 
6, 7.56169, 1, 0, 0.499498,-0.000264278)    );
  // itree = 656
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.910928,-0.00364771) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469033,0.00277905) , 
1, 3.61905, 1, 0, 0.578302,0.00153708) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0197099,0.0404857) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0770941,-0.0102782) , 
8, -0.151718, 1, 0, 0.0669982,-0.0027389) , 
7, 2.38063, 1, 0, 0.500265,0.000884461)    );
  // itree = 657
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603458,0.000554989) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.689975,-0.0146165) , 
0, 71380.8, 1, 0, 0.616806,-0.000818476) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.129396,0.00476257) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.900854,-0.0067927) , 
5, 3.397, 1, 0, 0.316113,0.00163228) , 
6, 2.59286, 1, 0, 0.500703,0.000127802)    );
  // itree = 658
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414826,-0.000752115) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400898,-0.00673476) , 
1, 11.6667, 1, 0, 0.412807,-0.0013173) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.765073,0.00257717) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.297152,-0.00129806) , 
7, 1.02072, 1, 0, 0.553062,0.000909556) , 
7, -0.475845, 1, 0, 0.499472,5.87018e-05)    );
  // itree = 659
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.811621,-0.00140966) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.121645,0.00182442) , 
3, -0.61587, 1, 0, 0.315727,0.00056029) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984242,0.0067181) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.898854,-0.00676314) , 
6, 1.876, 1, 0, 0.943268,-0.00184802) , 
4, 0.257238, 1, 0, 0.501987,-0.000154519)    );
  // itree = 660
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495877,-0.000299472) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385888,-0.00618698) , 
1, 11.8095, 1, 0, 0.485453,-0.000785393) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.676287,-0.00773839) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.59809,0.0149691) , 
3, 0.143785, 1, 0, 0.616241,0.00321223) , 
0, 122740, 1, 0, 0.49994,-0.000342585)    );
  // itree = 661
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617015,-0.00455516) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424656,0.00292471) , 
0, 39453.4, 1, 0, 0.493252,0.000128474) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.703032,-0.0111466) , 
0, 176762, 1, 0, 0.502008,-0.000169894)    );
  // itree = 662
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.849868,0.000676113) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524837,0.00892778) , 
6, 2.27643, 1, 0, 0.789503,0.00218928) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.766671,0.00277347) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.331744,-0.00332052) , 
3, -0.80414, 1, 0, 0.377717,-0.00170226) , 
1, 4.28571, 1, 0, 0.496871,-0.000576213)    );
  // itree = 663
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578695,0.0027449) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.706581,-0.0108831) , 
0, 80345, 1, 0, 0.595665,0.00111203) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.676856,-0.00944819) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25332,-0.00113998) , 
3, -0.808696, 1, 0, 0.294013,-0.00234874) , 
6, 3.04041, 1, 0, 0.502337,4.12951e-05)    );
  // itree = 664
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.990342,0.041638) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474172,-0.000767823) , 
6, 0.438847, 1, 0, 0.510013,-0.000142141) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202026,0.00929257) , 
6, 8.40124, 1, 0, 0.499706,0.000110586)    );
  // itree = 665
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.751912,0.00247117) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.189856,-0.0096648) , 
3, 0.904803, 1, 0, 0.6226,0.000655613) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511768,-0.00463464) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336167,0.000783321) , 
3, 0.526966, 1, 0, 0.38994,-0.00165662) , 
1, 6.66667, 1, 0, 0.50007,-0.000562124)    );
  // itree = 666
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538218,0.000810478) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565365,-0.00466374) , 
8, 0.0126022, 1, 0, 0.547089,-0.000939264) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.155974,0.0216571) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0278157,-0.00865623) , 
3, 0.904997, 1, 0, 0.0674951,0.00307956) , 
8, 0.111296, 1, 0, 0.496118,-0.000512148)    );
  // itree = 667
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603136,-0.00436693) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424642,0.00109793) , 
0, 40811.2, 1, 0, 0.491754,-0.000782598) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.726691,0.0138279) , 
0, 191035, 1, 0, 0.499493,-0.000460283)    );
  // itree = 668
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.887456,0.00613636) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.751438,-0.00304128) , 
0, 62560.2, 1, 0, 0.856259,0.00310456) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243101,-0.00484671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364167,0.0024901) , 
7, -0.476832, 1, 0, 0.314421,-0.0002345) , 
3, -0.522861, 1, 0, 0.498472,0.000899709)    );
  // itree = 669
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41407,-0.00172341) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582639,0.00339943) , 
8, -0.0125309, 1, 0, 0.517284,0.00123524) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00701006,-0.0366713) , 
8, 0.305018, 1, 0, 0.500467,0.00101064)    );
  // itree = 670
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507616,0.00637877) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.770446,0.000118825) , 
7, -1.42796, 1, 0, 0.739424,0.000950874) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.34361,-0.00709217) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.268247,0.00164231) , 
6, 2.09985, 1, 0, 0.296189,-0.00110697) , 
3, 0.428823, 1, 0, 0.501238,-0.000154972)    );
  // itree = 671
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534975,0.00154677) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222353,0.0102509) , 
6, 5.57291, 1, 0, 0.516866,0.00148616) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0535944,0.00348595) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.733775,-0.00437874) , 
4, 0.114626, 1, 0, 0.445371,-0.00158332) , 
1, 9.04762, 1, 0, 0.498372,0.000692153)    );
  // itree = 672
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.901803,0.000513874) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.736699,-0.0149531) , 
3, -0.767988, 1, 0, 0.887271,-0.00139112) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546683,0.0054912) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296752,0.000364398) , 
3, 0.102512, 1, 0, 0.343324,0.00161147) , 
3, -0.713531, 1, 0, 0.501893,0.000736166)    );
  // itree = 673
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.807285,-0.00184556) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411653,0.00477685) , 
6, 5.14544, 1, 0, 0.782148,-0.0011933) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32093,0.0113778) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295602,0.00098397) , 
1, 3.61905, 1, 0, 0.296725,0.00114658) , 
3, 0.048038, 1, 0, 0.499073,0.000171202)    );
  // itree = 674
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.949986,-0.000114396) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696554,-0.0065955) , 
6, 1.98429, 1, 0, 0.886726,-0.00292265) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.7149,0.0107652) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326078,-0.000664938) , 
3, -0.631618, 1, 0, 0.340142,8.67074e-05) , 
3, -0.713208, 1, 0, 0.49983,-0.000792494)    );
  // itree = 675
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.815948,-0.00210575) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.425926,-0.0126933) , 
3, -0.273859, 1, 0, 0.790541,-0.00303431) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347486,0.00376424) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0318159,-0.00858302) , 
8, 0.111923, 1, 0, 0.295332,0.00175349) , 
3, -0.0471399, 1, 0, 0.496918,-0.0001955)    );
  // itree = 676
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48071,0.00546059) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0180964,-0.00367747) , 
3, 0.619317, 1, 0, 0.219571,0.0017314) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.656546,-0.0013246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664553,-0.00503884) , 
1, 10.7143, 1, 0, 0.658174,-0.00194657) , 
4, 0.0858625, 1, 0, 0.500096,-0.000620978)    );
  // itree = 677
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.490717,0.000435938) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.707769,-0.0115342) , 
0, 182762, 1, 0, 0.49695,0.000118591) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602251,0.0112459) , 
1, 16.2857, 1, 0, 0.499656,0.000399493)    );
  // itree = 678
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.841752,-0.00108962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442853,-0.0051055) , 
6, 2.23314, 1, 0, 0.722659,-0.00288225) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0463436,-0.0148754) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364497,0.00202719) , 
8, -0.0780176, 1, 0, 0.295517,8.18558e-05) , 
3, 0.524027, 1, 0, 0.500229,-0.00133872)    );
  // itree = 679
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.729207,0.00268485) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322759,-0.00118105) , 
6, 1.60754, 1, 0, 0.500421,0.000240096) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.160054,0.0104186) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.874643,0.00169378) , 
4, 0.200561, 1, 0, 0.519571,0.00612517) , 
1, 12.6667, 1, 0, 0.502409,0.000850941)    );
  // itree = 680
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.829698,-0.0112234) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0678945,0.000489397) , 
1, 3.14286, 1, 0, 0.218323,-0.00126824) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175005,0.0120811) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.796629,0.00110741) , 
7, -2.37957, 1, 0, 0.741296,0.00182348) , 
4, 0.114425, 1, 0, 0.501758,0.000407373)    );
  // itree = 681
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.556354,0.00363238) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221486,-0.00215006) , 
3, 0.90485, 1, 0, 0.411724,0.00152434) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385307,-0.00225509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.968382,0.00307471) , 
4, 0.285914, 1, 0, 0.554529,-0.00121329) , 
7, -0.475825, 1, 0, 0.500222,-0.000172202)    );
  // itree = 682
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.818484,-0.00465615) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523877,0.00818877) , 
6, 3.11623, 1, 0, 0.78998,-0.0017551) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424005,0.00277767) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.193465,-0.00555108) , 
6, 4.84132, 1, 0, 0.382576,0.00119259) , 
1, 4.28571, 1, 0, 0.50071,0.000337856)    );
  // itree = 683
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.752094,0.004687) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.805281,-0.00624933) , 
4, 0.0574658, 1, 0, 0.793388,-0.00228546) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0353556,-0.00475181) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491225,0.0023921) , 
4, 0.0572999, 1, 0, 0.383025,0.00116576) , 
1, 4.28571, 1, 0, 0.501639,0.000168195)    );
  // itree = 684
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163966,0.00266087) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384465,-0.0169499) , 
5, 0.858891, 1, 0, 0.237309,-0.00299441) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.626333,-0.000824144) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50675,0.00263727) , 
7, 0.475896, 1, 0, 0.581119,0.000386131) , 
4, 0.0575283, 1, 0, 0.501646,-0.000395296)    );
  // itree = 685
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583676,0.0104836) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.797995,0.0011668) , 
7, -1.43365, 1, 0, 0.774877,0.00240975) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.173412,-0.00340424) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989469,0.0239608) , 
4, 0.400116, 1, 0, 0.292867,-0.00123711) , 
3, 0.143327, 1, 0, 0.499464,0.000325997)    );
  // itree = 686
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.63638,-0.000544597) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.291864,-0.00802894) , 
6, 4.37047, 1, 0, 0.586468,-0.00142937) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353992,0.00565982) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0936886,-0.00474563) , 
3, 0.90488, 1, 0, 0.209092,0.00134864) , 
7, 1.42883, 1, 0, 0.500195,-0.000794281)    );
  // itree = 687
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.815775,-0.00632217) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0950899,0.000364957) , 
3, -0.713072, 1, 0, 0.266325,-0.0014822) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.958978,0.00835368) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.859658,-0.00183591) , 
3, -0.61804, 1, 0, 0.901438,0.00116113) , 
4, 0.200113, 1, 0, 0.500035,-0.000509499)    );
  // itree = 688
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.656029,-0.00317979) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.228782,0.0107461) , 
8, 0.0832778, 1, 0, 0.622004,-0.00219272) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.176807,-0.00685689) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404127,0.0103215) , 
0, 57864.9, 1, 0, 0.304112,0.00109628) , 
3, 0.904804, 1, 0, 0.499134,-0.000921465)    );
  // itree = 689
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457717,-0.00449924) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0488987,0.0164676) , 
8, 0.11964, 1, 0, 0.408789,-0.00262429) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558785,-0.000466008) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53335,0.0049314) , 
1, 10.8571, 1, 0, 0.553923,0.000560977) , 
7, -0.474436, 1, 0, 0.499028,-0.000643817)    );
  // itree = 690
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.187073,0.00449181) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.624909,-0.0150858) , 
5, 2.60698, 1, 0, 0.220519,0.00129016) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617143,-0.00265868) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.766784,0.00365711) , 
0, 80345.4, 1, 0, 0.655593,-0.0010265) , 
4, 0.0858625, 1, 0, 0.49911,-0.000193263)    );
  // itree = 691
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.70443,-0.00054584) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401483,0.00478164) , 
3, 0.809642, 1, 0, 0.585925,0.000743138) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0442011,0.0192898) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247243,-0.00621376) , 
8, -0.0863263, 1, 0, 0.202603,-0.00203479) , 
7, 1.42885, 1, 0, 0.500219,0.000122027)    );
  // itree = 692
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.924271,0.00536871) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.849097,-0.00575085) , 
3, -0.85406, 1, 0, 0.911156,0.00204372) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0344799,0.00603889) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.429797,-0.002125) , 
7, -3.3315, 1, 0, 0.368031,-0.0012813) , 
3, -0.808727, 1, 0, 0.498743,-0.00048108)    );
  // itree = 693
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485965,0.00472306) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.751926,-0.00174505) , 
7, -1.42883, 1, 0, 0.719742,-0.00090326) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354348,0.00538247) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0261206,-0.012845) , 
8, 0.111923, 1, 0, 0.297255,0.00220182) , 
3, 0.524108, 1, 0, 0.50014,0.000710709)    );
  // itree = 694
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0529687,0.00721268) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.24133,-0.00577028) , 
8, -0.0669201, 1, 0, 0.191435,-0.00216869) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.728088,0.00453367) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53812,-0.000659016) , 
7, -0.338868, 1, 0, 0.5845,0.000677733) , 
7, -1.42729, 1, 0, 0.498689,5.63236e-05)    );
  // itree = 695
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.906121,0.00147973) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.623127,-0.00691031) , 
3, -0.795101, 1, 0, 0.801011,-0.00291866) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258285,0.00235632) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.430655,-0.00467051) , 
1, 10.8571, 1, 0, 0.301882,0.000258708) , 
3, -0.142335, 1, 0, 0.498652,-0.000993896)    );
  // itree = 696
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75934,-0.000512098) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.149799,0.0199694) , 
7, 2.38119, 1, 0, 0.69923,0.000830101) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.790698,-0.0104619) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361298,-0.00122396) , 
3, -0.896482, 1, 0, 0.380771,-0.00161453) , 
1, 5.42857, 1, 0, 0.500638,-0.000694379)    );
  // itree = 697
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.754179,0.00744966) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455815,-0.00195973) , 
0, 27635.6, 1, 0, 0.496737,-0.00067663) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491637,0.00871296) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514956,-0.00251347) , 
1, 10, 1, 0, 0.505262,0.00104263) , 
0, 80345.2, 1, 0, 0.49898,-0.000224248)    );
  // itree = 698
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.661355,0.00773044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.126783,-0.00670841) , 
1, 3.14286, 1, 0, 0.188369,-0.0022903) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.751139,0.00271743) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360675,-0.000865241) , 
7, 0.749078, 1, 0, 0.585845,0.00121566) , 
7, -1.4276, 1, 0, 0.499401,0.000453177)    );
  // itree = 699
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.553078,0.000468498) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25124,-0.00646688) , 
6, 4.3432, 1, 0, 0.514621,-0.000286912) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.18981,0.00855715) , 
6, 7.56173, 1, 0, 0.499699,1.70768e-05)    );
  // itree = 700
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.642506,0.0132521) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.830025,0.00172319) , 
8, -0.0524751, 1, 0, 0.815144,0.00284563) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405397,0.00647075) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.297043,-0.000888049) , 
1, 3.61905, 1, 0, 0.302432,-0.000105314) , 
3, -0.237529, 1, 0, 0.500367,0.00103391)    );
  // itree = 701
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.681549,-0.00388286) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258787,0.0079256) , 
8, 0.0899451, 1, 0, 0.654364,-0.00313989) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22212,-0.00611289) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362993,0.00626761) , 
7, -0.473933, 1, 0, 0.304001,0.000761514) , 
3, 0.809628, 1, 0, 0.497962,-0.0013983)    );
  // itree = 702
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.985851,0.0207262) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.889392,-0.00403304) , 
3, -0.953796, 1, 0, 0.907666,-0.00171342) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0675388,-0.00821391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400205,0.00351522) , 
4, 0.0288758, 1, 0, 0.371354,0.00230668) , 
3, -0.808727, 1, 0, 0.501339,0.00133233)    );
  // itree = 703
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488211,0.000952574) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569091,-0.00414219) , 
0, 108371, 1, 0, 0.498543,0.000345437) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552632,-0.00916078) , 
1, 16.2857, 1, 0, 0.500005,8.40395e-05)    );
  // itree = 704
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597463,0.00209149) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0578238,-0.0134085) , 
8, 0.120401, 1, 0, 0.549563,0.00115521) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.418112,-0.00151861) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428714,-0.00932837) , 
1, 12.9524, 1, 0, 0.419203,-0.00183511) , 
7, 0.476491, 1, 0, 0.49871,-1.13067e-05)    );
  // itree = 705
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22416,-0.00498944) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.626564,-0.000325482) , 
4, 0.134915, 1, 0, 0.354299,-0.00257248) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.975605,0.00815275) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.888183,-0.0105791) , 
6, 4.41801, 1, 0, 0.965569,0.00116331) , 
4, 0.314414, 1, 0, 0.496812,-0.00170151)    );
  // itree = 706
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.770191,6.87109e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542179,0.00835985) , 
7, 1.42617, 1, 0, 0.740887,0.00128018) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.260634,-0.00517137) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314858,0.00168277) , 
3, 0.972814, 1, 0, 0.290606,-0.00126667) , 
3, 0.428833, 1, 0, 0.500707,-7.83085e-05)    );
  // itree = 707
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175186,0.00369775) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.631917,-0.0155574) , 
5, 2.83678, 1, 0, 0.215371,0.000663221) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.89419,-0.000323835) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.596277,-0.00517969) , 
3, -0.142146, 1, 0, 0.737324,-0.00248039) , 
4, 0.114575, 1, 0, 0.497861,-0.00103815)    );
  // itree = 708
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303108,0.00592241) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68965,-0.00264352) , 
8, -0.0464789, 1, 0, 0.625728,-0.00102244) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469175,0.00309851) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0436023,-0.0108319) , 
7, 2.38059, 1, 0, 0.390035,0.00165911) , 
1, 6.66667, 1, 0, 0.500903,0.00039773)    );
  // itree = 709
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.932713,0.0065996) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.980095,-0.0115644) , 
4, 0.343016, 1, 0, 0.945041,0.00264124) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.737495,-0.00229658) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303848,0.00058814) , 
3, -0.178397, 1, 0, 0.435452,-0.000580301) , 
3, -0.903568, 1, 0, 0.501187,-0.000164736)    );
  // itree = 710
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.947886,0.000193737) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.745326,-0.00852309) , 
1, 6.47619, 1, 0, 0.907486,-0.00253638) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508918,0.00303834) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295869,-0.000291594) , 
3, 0.655487, 1, 0, 0.371437,0.00125463) , 
3, -0.808696, 1, 0, 0.500204,0.000343975)    );
  // itree = 711
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208628,0.00446796) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0357143,-0.0261967) , 
3, 0.905125, 1, 0, 0.0949847,-0.0032374) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562766,-0.000155092) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531145,0.00500406) , 
1, 10.8571, 1, 0, 0.556737,0.000811674) , 
8, -0.0857566, 1, 0, 0.497631,0.000293379)    );
  // itree = 712
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.872685,-0.00292208) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.30533,0.00162824) , 
3, -0.618307, 1, 0, 0.497551,-9.65919e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.611002,0.00919242) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.478722,0.00180144) , 
3, 0.146022, 1, 0, 0.511483,0.00467483) , 
1, 12.6667, 1, 0, 0.498987,0.000395224)    );
  // itree = 713
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.683966,0.000693234) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298597,-0.00330275) , 
6, 1.88399, 1, 0, 0.503755,-0.000973259) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0556807,-0.013644) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.556691,0.00563285) , 
7, -2.3747, 1, 0, 0.475405,0.00348532) , 
1, 10.8571, 1, 0, 0.498353,-0.000123798)    );
  // itree = 714
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.982083,-0.00444639) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674441,0.00311789) , 
1, 2.14286, 1, 0, 0.785697,0.00249231) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.174899,-0.00324767) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98862,0.0185646) , 
4, 0.400107, 1, 0, 0.29448,-0.00134982) , 
3, 0.048038, 1, 0, 0.50072,0.000263321)    );
  // itree = 715
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.917702,0.00531986) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508965,-0.00393768) , 
6, 1.06559, 1, 0, 0.697884,-0.0011868) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0470535,-0.010545) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.435535,0.00321628) , 
8, -0.0973851, 1, 0, 0.380354,0.00195777) , 
1, 5.42857, 1, 0, 0.499609,0.000776766)    );
  // itree = 716
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522931,0.000991575) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.166976,-0.00665597) , 
6, 5.49312, 1, 0, 0.490715,0.000298845) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.707371,0.00787774) , 
0, 171609, 1, 0, 0.500507,0.000523942)    );
  // itree = 717
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.212775,0.0120254) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.657005,-0.00339618) , 
8, -0.0842629, 1, 0, 0.624247,-0.00243027) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362392,-0.0116264) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285275,0.0060401) , 
6, 1.73499, 1, 0, 0.306406,0.000146831) , 
3, 0.904821, 1, 0, 0.501119,-0.00143194)    );
  // itree = 718
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.224529,0.000766525) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.73845,-0.00187732) , 
4, 0.114417, 1, 0, 0.497575,-0.000609881) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526005,0.0098341) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544469,-0.0033733) , 
3, 0.905431, 1, 0, 0.535481,0.00521736) , 
1, 15, 1, 0, 0.499563,-0.000304366)    );
  // itree = 719
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501727,0.00138116) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68609,-0.00330413) , 
7, 0.0240365, 1, 0, 0.576974,-0.000623942) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.020905,-0.00541488) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2556,0.0156993) , 
4, 0.143354, 1, 0, 0.071325,0.00302311) , 
7, 2.38172, 1, 0, 0.499733,-6.68343e-05)    );
  // itree = 720
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.995735,-0.0240738) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.979552,0.0260189) , 
3, -0.904052, 1, 0, 0.988226,0.00218861) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.906923,-0.00542717) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.406889,-0.00133661) , 
3, -0.903891, 1, 0, 0.452129,-0.00144018) , 
1, 1.80952, 1, 0, 0.498996,-0.00112294)    );
  // itree = 721
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511501,-0.000284793) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.182736,-0.0100416) , 
6, 7.54854, 1, 0, 0.50099,-0.000413159) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.595412,0.0103194) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485943,-0.00155335) , 
3, 0.430681, 1, 0, 0.516699,0.00376061) , 
1, 12.8571, 1, 0, 0.502597,1.37992e-05)    );
  // itree = 722
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222469,-0.000183344) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.451402,0.0033719) , 
4, 0.133618, 1, 0, 0.266156,0.000755955) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.94196,-0.000730138) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.804025,-0.0057151) , 
6, 2.61897, 1, 0, 0.897789,-0.00227375) , 
4, 0.200246, 1, 0, 0.498157,-0.000356866)    );
  // itree = 723
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.92688,0.00336008) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.274035,-0.00218409) , 
3, -0.901024, 1, 0, 0.355883,-0.00143363) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.955941,-0.00205954) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.979048,0.0162967) , 
3, 0.428823, 1, 0, 0.966487,0.00130983) , 
4, 0.314344, 1, 0, 0.499064,-0.00079031)    );
  // itree = 724
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.644659,-0.00120461) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.139388,0.0176377) , 
8, 0.120582, 1, 0, 0.619561,-0.000572012) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266023,-0.00292192) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.36294,0.0168705) , 
3, 0.995469, 1, 0, 0.310497,0.00215194) , 
3, 0.904804, 1, 0, 0.499072,0.000489924)    );
  // itree = 725
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893524,0.000457912) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564303,-0.00558174) , 
3, -0.749519, 1, 0, 0.781968,-0.00244828) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00857533,-0.0250129) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321791,0.000638899) , 
4, 0.0289284, 1, 0, 0.294032,-0.000198376) , 
3, 0.0482158, 1, 0, 0.499033,-0.00114365)    );
  // itree = 726
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.845034,0.00204816) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.237375,-0.00214225) , 
3, -0.142231, 1, 0, 0.535953,0.000213616) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.171421,-0.00710499) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509074,0.00517987) , 
8, -0.043464, 1, 0, 0.430144,0.00257297) , 
1, 8.57143, 1, 0, 0.50056,0.00100281)    );
  // itree = 727
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308662,-0.00322228) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.743929,0.00368656) , 
7, -0.929621, 1, 0, 0.414693,-0.000765174) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546545,0.0031183) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.690932,-0.0057681) , 
0, 143322, 1, 0, 0.557492,0.00208311) , 
7, -0.475825, 1, 0, 0.503628,0.00100874)    );
  // itree = 728
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.868628,0.00024106) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494752,0.00820298) , 
3, -0.618354, 1, 0, 0.774384,0.00307812) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.282958,-0.000673277) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499633,-0.0168364) , 
1, 15.4286, 1, 0, 0.293216,-0.000950179) , 
3, 0.143234, 1, 0, 0.499087,0.00077335)    );
  // itree = 729
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2512,-0.00215886) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.660674,0.0021715) , 
4, 0.0858561, 1, 0, 0.509699,0.000656355) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2832,-0.00412519) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.970859,0.0125543) , 
4, 0.343033, 1, 0, 0.465736,-0.00206226) , 
1, 10.7143, 1, 0, 0.501191,0.000130207)    );
  // itree = 730
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.905966,0.00100167) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544828,0.00564268) , 
3, -0.794818, 1, 0, 0.738494,0.00387011) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27947,0.00254831) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502447,-0.0137257) , 
1, 14.4762, 1, 0, 0.294745,0.00063594) , 
3, 0.42893, 1, 0, 0.500285,0.00213397)    );
  // itree = 731
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.220986,0.00112837) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349241,0.0168679) , 
4, 0.129492, 1, 0, 0.22878,0.00196651) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.947134,0.0107736) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.757931,-0.00317169) , 
1, 3.42857, 1, 0, 0.805284,-0.0012846) , 
4, 0.143091, 1, 0, 0.498577,0.00044503)    );
  // itree = 732
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.568758,0.00147208) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37444,-0.00240916) , 
1, 7.42857, 1, 0, 0.497688,5.51238e-06) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582974,0.0105931) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486905,0.00084589) , 
3, 0.43247, 1, 0, 0.513247,0.00498163) , 
1, 12.8571, 1, 0, 0.499269,0.000511233)    );
  // itree = 733
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.430366,0.0106785) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0831387,-0.00189911) , 
3, 0.714488, 1, 0, 0.195459,0.00312202) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918402,0.00271783) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455156,-0.0014475) , 
3, -0.808387, 1, 0, 0.586734,-0.000351972) , 
7, -1.42816, 1, 0, 0.500567,0.000413077)    );
  // itree = 734
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579668,-0.000922755) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530708,0.004512) , 
1, 8.33333, 1, 0, 0.566846,0.000483794) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0903323,0.00943445) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329848,-0.00636118) , 
7, -1.42658, 1, 0, 0.257516,-0.00269165) , 
6, 3.79441, 1, 0, 0.498959,-0.000213103)    );
  // itree = 735
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.720206,0.0024945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321959,-0.00133621) , 
6, 1.62805, 1, 0, 0.498373,0.000145061) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0627465,0.0218596) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.686371,0.00211658) , 
4, 0.0863622, 1, 0, 0.517786,0.00549361) , 
1, 12.8571, 1, 0, 0.500387,0.000699984)    );
  // itree = 736
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.215214,-0.000135675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.834155,-0.00477101) , 
5, 2.97512, 1, 0, 0.401573,-0.00145904) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996702,0.01379) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.996608,0.0362624) , 
1, 11.3333, 1, 0, 0.996683,0.00195085) , 
5, 10.4061, 1, 0, 0.497111,-0.000911615)    );
  // itree = 737
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.908277,0.00113785) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537317,-0.00443745) , 
3, -0.795106, 1, 0, 0.736855,-0.00221196) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349848,-0.00435769) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.267047,0.00414677) , 
6, 1.9315, 1, 0, 0.294418,0.000514843) , 
3, 0.428833, 1, 0, 0.499885,-0.000751483)    );
  // itree = 738
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592501,-0.00224698) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414374,0.00462683) , 
0, 42865.2, 1, 0, 0.489552,0.00127145) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302781,-0.0123958) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.975631,0.00822081) , 
4, 0.257304, 1, 0, 0.653608,-0.00518755) , 
0, 150056, 1, 0, 0.500328,0.000847177)    );
  // itree = 739
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588642,0.000736724) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0271686,-0.0212359) , 
7, 5.23765, 1, 0, 0.555861,0.000198083) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0333185,0.0150043) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102691,-0.0156743) , 
7, -1.42428, 1, 0, 0.0752395,-0.00316485) , 
8, 0.102917, 1, 0, 0.500984,-0.000185901)    );
  // itree = 740
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.441955,0.00783858) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.110972,-0.00717231) , 
1, 4.71429, 1, 0, 0.168834,-0.00172584) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0290813,-0.0178919) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605853,0.00246011) , 
7, -5.23801, 1, 0, 0.574019,0.0016802) , 
8, -0.0538215, 1, 0, 0.500005,0.00105803)    );
  // itree = 741
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529155,-0.00125862) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.128048,-0.0113949) , 
6, 4.15688, 1, 0, 0.495369,-0.00161033) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.576605,0.00640748) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0735664,-0.0111502) , 
8, 0.0983845, 1, 0, 0.508619,0.00352478) , 
0, 80345.2, 1, 0, 0.498875,-0.00025165)    );
  // itree = 742
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00845608,-0.0329822) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0324409,-0.0290959) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533468,0.00118983) , 
8, -0.167351, 1, 0, 0.517007,0.000630287) , 
8, -0.275569, 1, 0, 0.49842,0.000427462)    );
  // itree = 743
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496931,-8.33489e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44985,-0.00511953) , 
1, 12, 1, 0, 0.491236,-0.0006504) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.728075,0.00899954) , 
0, 186720, 1, 0, 0.49984,-0.000416749)    );
  // itree = 744
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55099,0.000382892) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.255098,-0.00540591) , 
6, 4.3307, 1, 0, 0.512613,-0.000259025) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.200849,0.00645002) , 
6, 7.54854, 1, 0, 0.497872,-1.6466e-05)    );
  // itree = 745
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.280378,0.00202854) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.841825,-0.00225141) , 
4, 0.142988, 1, 0, 0.562413,-2.04287e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.121212,0.0339937) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0189002,0.000718469) , 
3, 0.810869, 1, 0, 0.0411794,0.00526869) , 
7, 3.33471, 1, 0, 0.500398,0.000608858)    );
  // itree = 746
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.573628,-0.000616347) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37326,0.00326039) , 
1, 7.42857, 1, 0, 0.500417,0.000620109) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.284493,-0.00789331) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.959917,0.0138519) , 
4, 0.314647, 1, 0, 0.507141,-0.00423009) , 
1, 12.8571, 1, 0, 0.501108,0.000121556)    );
  // itree = 747
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313326,0.00120246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0658778,-0.0110935) , 
0, 64810.3, 1, 0, 0.213608,-0.00175918) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.840232,-0.00106856) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484278,0.00295852) , 
3, 0.238444, 1, 0, 0.656575,0.00065761) , 
4, 0.086032, 1, 0, 0.497476,-0.000210422)    );
  // itree = 748
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524973,-0.00147771) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208504,0.0091771) , 
6, 6.13174, 1, 0, 0.513657,-0.000861296) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.18746,-0.0100333) , 
6, 7.56169, 1, 0, 0.498371,-0.00117499)    );
  // itree = 749
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388453,0.00236577) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.969915,-0.00433105) , 
4, 0.342901, 1, 0, 0.501542,0.00134909) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.097605,0.00412866) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.794901,-0.00743509) , 
4, 0.143528, 1, 0, 0.492531,-0.00219865) , 
1, 12, 1, 0, 0.500271,0.000848759)    );
  // itree = 750
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.789372,-0.00193976) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.279563,0.00226704) , 
3, 0.0482119, 1, 0, 0.497277,-6.51083e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540735,0.0102101) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559546,0.00718338) , 
3, 0.905431, 1, 0, 0.550545,0.0090016) , 
1, 15, 1, 0, 0.50007,0.000410313)    );
  // itree = 751
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.823912,-0.0110764) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0988745,-0.000452472) , 
1, 3.33333, 1, 0, 0.244497,-0.00181271) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.682493,0.00331163) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.952279,0.000191244) , 
4, 0.273673, 1, 0, 0.864463,0.00148177) , 
4, 0.171693, 1, 0, 0.500379,-0.000452962)    );
  // itree = 752
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.991362,0.0340401) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477544,-0.00157293) , 
6, 0.438338, 1, 0, 0.511414,-0.000863157) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.195895,0.00778096) , 
6, 8.40081, 1, 0, 0.500951,-0.000626332)    );
  // itree = 753
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419002,-0.00222922) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395519,0.00237961) , 
0, 71380.9, 1, 0, 0.411329,-0.000625269) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.782783,0.00494972) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498857,0.00131611) , 
7, 0.022425, 1, 0, 0.553704,0.00169442) , 
7, -0.476386, 1, 0, 0.499405,0.000809725)    );
  // itree = 754
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527039,-0.000826338) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.212608,0.00743409) , 
6, 6.0117, 1, 0, 0.510398,-0.000326261) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.177338,-0.00957218) , 
6, 8.40081, 1, 0, 0.499099,-0.000569013)    );
  // itree = 755
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785492,0.00078443) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333333,-0.00450561) , 
6, 1.38926, 1, 0, 0.536307,-0.00189435) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475581,0.00177281) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0346772,-0.0147876) , 
8, 0.127416, 1, 0, 0.429411,0.000921221) , 
1, 8.57143, 1, 0, 0.50004,-0.000939113)    );
  // itree = 756
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55391,-0.00112783) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380551,0.00653879) , 
0, 51497.7, 1, 0, 0.503458,0.000816449) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806524,-0.011618) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.444955,5.12707e-05) , 
3, -0.808727, 1, 0, 0.489271,-0.00162283) , 
0, 75587.8, 1, 0, 0.499299,0.000101353)    );
  // itree = 757
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629955,0.000924228) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0733839,-0.0106274) , 
8, 0.120401, 1, 0, 0.586721,0.000376783) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572558,0.00329021) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.121911,-0.00971624) , 
7, 1.8367, 1, 0, 0.201021,-0.00335789) , 
7, 1.42861, 1, 0, 0.500916,-0.000454054)    );
  // itree = 758
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502553,0.00193296) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.127224,-0.0130246) , 
6, 6.4383, 1, 0, 0.486737,0.00111388) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295889,-0.00972473) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.980893,0.0087322) , 
4, 0.285832, 1, 0, 0.606047,-0.00436187) , 
0, 122740, 1, 0, 0.499796,0.000514539)    );
  // itree = 759
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424693,-0.00315246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.568616,-0.000165657) , 
7, -0.476568, 1, 0, 0.51451,-0.000961621) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.193102,0.00813712) , 
6, 7.54854, 1, 0, 0.499035,-0.000636369)    );
  // itree = 760
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.656466,0.00397997) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.902086,0.00120783) , 
4, 0.114414, 1, 0, 0.816613,0.00244812) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0422924,0.000557062) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.699967,-0.00352543) , 
4, 0.143183, 1, 0, 0.300902,-0.000984257) , 
3, -0.237529, 1, 0, 0.49985,0.000339868)    );
  // itree = 761
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570654,-0.00149491) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.291875,0.00365049) , 
6, 3.61552, 1, 0, 0.515149,-0.000361267) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.185714,-0.0096948) , 
6, 7.54854, 1, 0, 0.50015,-0.000683915)    );
  // itree = 762
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.650414,-0.00291267) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376743,0.0026125) , 
3, 0.904805, 1, 0, 0.554321,-0.00135819) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.229314,0.0288806) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0261207,-0.0205459) , 
3, 0.810341, 1, 0, 0.0786213,0.00288895) , 
8, 0.103543, 1, 0, 0.49975,-0.00087097)    );
  // itree = 763
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.164123,-0.00211536) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577723,0.00496892) , 
4, 0.0859838, 1, 0, 0.413685,0.00223831) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379837,-0.00228876) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965214,0.00430499) , 
4, 0.28593, 1, 0, 0.549556,-0.00107358) , 
7, -0.475845, 1, 0, 0.497994,0.000183243)    );
  // itree = 764
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9851,0.0176117) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222152,-0.00189721) , 
1, 1.66667, 1, 0, 0.288393,-0.00135218) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.939268,0.000885734) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.763445,0.00591931) , 
6, 5.17011, 1, 0, 0.925068,0.0011239) , 
4, 0.228661, 1, 0, 0.497639,-0.000538406)    );
  // itree = 765
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578494,0.00189275) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.793865,0.0179395) , 
0, 191035, 1, 0, 0.585969,0.00192187) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0472858,0.0195968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.249091,-0.00535853) , 
8, -0.0771092, 1, 0, 0.201902,-0.00153901) , 
7, 1.42883, 1, 0, 0.498806,0.00113643)    );
  // itree = 766
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.254162,-0.0014643) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.866303,0.00189652) , 
4, 0.17155, 1, 0, 0.496406,-0.000128827) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533732,-0.00637686) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494677,-0.00136364) , 
3, 0.716234, 1, 0, 0.508152,-0.00372434) , 
1, 12.6667, 1, 0, 0.497606,-0.000496249)    );
  // itree = 767
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76285,-0.00883375) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.113658,-0.00113417) , 
3, -0.617901, 1, 0, 0.190251,-0.0016981) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.677287,-0.00405702) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.576746,0.00166941) , 
7, -0.884558, 1, 0, 0.586741,0.000821687) , 
7, -1.42883, 1, 0, 0.5005,0.000273603)    );
  // itree = 768
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.742749,0.00312393) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.145089,-0.00045354) , 
3, -0.0464651, 1, 0, 0.377315,0.001257) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.95738,-0.0114384) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98132,0.00449458) , 
3, 0.238513, 1, 0, 0.969234,-0.0021768) , 
4, 0.342925, 1, 0, 0.500805,0.000540619)    );
  // itree = 769
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.196647,0.00714546) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592674,-0.000130752) , 
7, -1.42731, 1, 0, 0.507433,0.000738367) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426201,-0.00518401) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721147,0.0109499) , 
0, 182127, 1, 0, 0.468971,-0.00297562) , 
1, 10.7143, 1, 0, 0.500045,2.49297e-05)    );
  // itree = 770
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.866519,0.017785) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.894675,0.000869594) , 
4, 0.0290658, 1, 0, 0.892042,0.00197674) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574525,-0.00816192) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321073,0.000126745) , 
1, 3.61905, 1, 0, 0.339809,-0.000670327) , 
3, -0.713502, 1, 0, 0.500744,0.000101093)    );
  // itree = 771
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.654411,-0.00271811) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.290314,0.00113) , 
3, 0.809611, 1, 0, 0.493061,-0.00123109) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569444,0.0102524) , 
1, 16.2857, 1, 0, 0.495036,-0.000938598)    );
  // itree = 772
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505848,-0.00109099) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440768,0.00435077) , 
1, 10.5238, 1, 0, 0.497347,-0.000237995) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.219819,-0.00848697) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.924968,0.000698671) , 
4, 0.258068, 1, 0, 0.517023,-0.00571636) , 
1, 13.7143, 1, 0, 0.49881,-0.000645182)    );
  // itree = 773
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.978503,-0.00135433) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.761765,0.00390466) , 
1, 3.14286, 1, 0, 0.887856,0.00231966) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0809442,0.00117768) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.801161,-0.00510769) , 
4, 0.17153, 1, 0, 0.340651,-0.00105353) , 
3, -0.713346, 1, 0, 0.500855,-6.59667e-05)    );
  // itree = 774
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.626821,0.00183984) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.369492,-0.0017724) , 
1, 6.66667, 1, 0, 0.498189,-1.65067e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532515,-0.00960845) , 
1, 14.4762, 1, 0, 0.499904,-0.000473994)    );
  // itree = 775
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222975,-0.00119998) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.739594,0.00171916) , 
4, 0.114538, 1, 0, 0.499458,0.000422536) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.224207,0.00744182) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.892435,0.00146061) , 
4, 0.229019, 1, 0, 0.545351,0.00503774) , 
1, 15, 1, 0, 0.501875,0.000665609)    );
  // itree = 776
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53615,0.00172893) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.211709,0.0194453) , 
6, 5.44612, 1, 0, 0.516765,0.00195362) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463018,-0.00442531) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.430724,0.00366745) , 
3, 0.905176, 1, 0, 0.44527,-0.00127455) , 
1, 9.04762, 1, 0, 0.49815,0.00111312)    );
  // itree = 777
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.813617,-0.0050516) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.962669,0.00777511) , 
4, 0.200298, 1, 0, 0.885601,-0.00103156) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.331755,0.00124019) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53815,0.0107976) , 
1, 15.4286, 1, 0, 0.34109,0.00129684) , 
3, -0.713531, 1, 0, 0.499905,0.000617725)    );
  // itree = 778
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.873638,0.00686915) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.981475,-0.0431549) , 
4, 0.428799, 1, 0, 0.888256,0.00242922) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283795,-0.00166185) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.982161,0.00737776) , 
4, 0.428656, 1, 0, 0.389347,-0.00102954) , 
1, 3.61905, 1, 0, 0.500811,-0.000256793)    );
  // itree = 779
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.879184,-0.000787047) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586665,-0.00550279) , 
3, -0.681803, 1, 0, 0.824253,-0.0020639) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315417,0.00629424) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304903,0.000549043) , 
1, 4.52381, 1, 0, 0.306086,0.000974463) , 
3, -0.332747, 1, 0, 0.499171,-0.000157722)    );
  // itree = 780
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.801324,0.00414533) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.210916,6.63014e-05) , 
3, 0.524026, 1, 0, 0.572537,0.00224163) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0133261,-0.0273642) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.443144,0.000587244) , 
4, 0.0288746, 1, 0, 0.406446,-0.000383644) , 
1, 7.2381, 1, 0, 0.501207,0.00111416)    );
  // itree = 781
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563718,-0.00125375) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0671931,0.00714141) , 
7, 2.38119, 1, 0, 0.485548,-0.000489355) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390506,0.00854997) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989661,-0.0181939) , 
5, 9.68697, 1, 0, 0.60116,0.00454549) , 
0, 113586, 1, 0, 0.500526,0.000162923)    );
  // itree = 782
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503806,0.000302725) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.465163,-0.00543049) , 
1, 11.3333, 1, 0, 0.50019,-0.000242066) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539154,0.00694563) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558978,0.00171792) , 
3, 0.905411, 1, 0, 0.549271,0.00497795) , 
1, 14.4762, 1, 0, 0.50275,3.02099e-05)    );
  // itree = 783
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.888138,-0.00125849) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333092,0.00218466) , 
3, -0.713531, 1, 0, 0.497352,0.000834591) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555585,-0.00753657) , 
1, 15.4286, 1, 0, 0.499579,0.000523862)    );
  // itree = 784
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.710178,0.00580107) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.435887,-0.00144989) , 
0, 30271.2, 1, 0, 0.487628,-0.000107064) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325536,-0.0092333) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.980943,0.0113128) , 
4, 0.285845, 1, 0, 0.630811,-0.00365612) , 
0, 135690, 1, 0, 0.499865,-0.000410379)    );
  // itree = 785
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.23359,-1.46246e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55599,0.00286951) , 
4, 0.152651, 1, 0, 0.290159,0.000680902) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.93693,-0.00682202) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.786697,0.00845972) , 
6, 5.17011, 1, 0, 0.925053,-0.00228477) , 
4, 0.228795, 1, 0, 0.500105,-0.000299781)    );
  // itree = 786
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.822542,-0.00853649) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954646,0.00833756) , 
4, 0.171653, 1, 0, 0.884381,-0.00183062) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.671266,0.00238016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.300651,0.000357961) , 
3, -0.236015, 1, 0, 0.394136,0.00107936) , 
1, 3.61905, 1, 0, 0.502838,0.000434126)    );
  // itree = 787
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381973,0.000561474) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.96862,-0.00727874) , 
4, 0.342988, 1, 0, 0.498014,-0.000113925) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584713,-0.00315166) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244367,-0.0166934) , 
8, 0.039735, 1, 0, 0.501192,-0.00550395) , 
1, 12.6667, 1, 0, 0.498346,-0.00067711)    );
  // itree = 788
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.182981,0.0132881) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.650274,-0.00226419) , 
8, -0.0982037, 1, 0, 0.622719,-0.00150849) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.269801,-0.00428073) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353282,0.0138387) , 
3, 0.995468, 1, 0, 0.308084,0.00116813) , 
3, 0.904814, 1, 0, 0.500501,-0.000468783)    );
  // itree = 789
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.930367,0.00738688) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.857473,-0.00262709) , 
3, -0.871841, 1, 0, 0.910858,0.00293774) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457007,-0.00380973) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303221,0.00175788) , 
3, 0.827774, 1, 0, 0.369358,-0.00140618) , 
3, -0.808387, 1, 0, 0.500324,-0.000355572)    );
  // itree = 790
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.761942,-0.00478232) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0368069,-0.00110589) , 
3, -0.614686, 1, 0, 0.216365,-0.00165423) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243856,-0.00196075) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.792194,0.00176459) , 
4, 0.134825, 1, 0, 0.660592,0.000641136) , 
4, 0.0858607, 1, 0, 0.501015,-0.000183417)    );
  // itree = 791
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.957634,0.0054861) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877204,-0.00571916) , 
3, -0.92659, 1, 0, 0.907991,-0.00215274) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.767228,0.00753686) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330302,-0.00106152) , 
3, -0.636455, 1, 0, 0.374078,0.000294837) , 
3, -0.808727, 1, 0, 0.501545,-0.000289501)    );
  // itree = 792
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696514,0.00223093) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363036,0.0113079) , 
8, 0.0612035, 1, 0, 0.661971,0.00311525) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248519,-0.00873275) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31658,0.00279075) , 
3, 0.945617, 1, 0, 0.301483,-0.000349376) , 
3, 0.809642, 1, 0, 0.502371,0.00158135)    );
  // itree = 793
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563793,0.000898619) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.207418,-0.00432116) , 
6, 3.48677, 1, 0, 0.488311,-0.00013837) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629743,-0.0167137) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603173,0.000280034) , 
3, 0.334055, 1, 0, 0.609944,-0.00492385) , 
0, 126175, 1, 0, 0.500702,-0.000625876)    );
  // itree = 794
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989875,-0.0017832) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.803276,0.0047724) , 
1, 2.14286, 1, 0, 0.890195,0.00347872) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492813,-0.00343418) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293287,0.000378825) , 
3, 0.347274, 1, 0, 0.338739,-0.00089536) , 
3, -0.713531, 1, 0, 0.49992,0.000383108)    );
  // itree = 795
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.585882,-0.000218535) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603812,0.0081773) , 
1, 12.6667, 1, 0, 0.587707,0.000664481) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.242782,-0.00774815) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.031158,0.0109201) , 
8, 0.111923, 1, 0, 0.204268,-0.00377196) , 
7, 1.4295, 1, 0, 0.501589,-0.000331908)    );
  // itree = 796
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.413502,0.00291828) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551981,-2.38197e-05) , 
7, -0.475313, 1, 0, 0.500147,0.000774645) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541009,-0.00524264) , 
1, 14.4762, 1, 0, 0.502266,0.000471795)    );
  // itree = 797
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548652,-0.000776881) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421742,0.00281008) , 
7, 0.477218, 1, 0, 0.498907,0.000412874) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562617,0.00832338) , 
1, 15.4286, 1, 0, 0.501309,0.000718402)    );
  // itree = 798
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.246073,0.00419034) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577736,-0.000435824) , 
4, 0.0572999, 1, 0, 0.499154,0.000264619) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518135,0.009987) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580083,0.00230882) , 
1, 16.4286, 1, 0, 0.549903,0.00559376) , 
1, 15, 1, 0, 0.50176,0.000538366)    );
  // itree = 799
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983592,0.00253728) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.684424,-0.0106382) , 
3, -0.808737, 1, 0, 0.885301,-0.00327496) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0619246,-0.00756331) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.449074,0.00124825) , 
8, -0.0872347, 1, 0, 0.391659,0.000577403) , 
1, 3.2381, 1, 0, 0.502616,-0.000288503)    );
  // itree = 800
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561747,0.00321356) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971988,-0.025389) , 
4, 0.400109, 1, 0, 0.623946,0.00117152) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.70908,-0.00635983) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343212,-1.64407e-05) , 
3, -0.706834, 1, 0, 0.388081,-0.00124718) , 
1, 6.42857, 1, 0, 0.498972,-0.000110045)    );
  // itree = 801
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.896593,-0.0010445) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.699637,-0.00574388) , 
3, -0.763401, 1, 0, 0.86413,-0.00206082) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.600853,0.00542526) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314197,0.00032751) , 
3, -0.464191, 1, 0, 0.327066,0.000592871) , 
3, -0.618335, 1, 0, 0.49824,-0.000252915)    );
  // itree = 802
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479873,-0.00104375) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38882,-0.00398423) , 
1, 9.04762, 1, 0, 0.456795,-0.00151677) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.981468,-0.0128475) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.99071,0.0289222) , 
1, 5.90476, 1, 0, 0.98754,0.00289333) , 
4, 0.514323, 1, 0, 0.49855,-0.00116981)    );
  // itree = 803
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.952148,0.0001413) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.905583,-0.0166935) , 
3, -0.926593, 1, 0, 0.938687,-0.00366942) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.820699,-0.00321449) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.365601,0.00282658) , 
1, 3.61905, 1, 0, 0.432998,0.00160367) , 
3, -0.903924, 1, 0, 0.496958,0.000936726)    );
  // itree = 804
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247696,-0.00395309) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.576847,0.00107249) , 
4, 0.0574746, 1, 0, 0.499151,0.000186827) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5,-0.0122708) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.566009,-0.00380503) , 
1, 16.4286, 1, 0, 0.533945,-0.00772599) , 
1, 15, 1, 0, 0.500946,-0.000221446)    );
  // itree = 805
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.478286,0.00332759) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.937043,-0.00480891) , 
4, 0.257347, 1, 0, 0.626042,0.00160668) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26159,-0.012851) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350803,0.00801565) , 
3, 0.995469, 1, 0, 0.30251,-0.00241122) , 
3, 0.904824, 1, 0, 0.500922,5.28299e-05)    );
  // itree = 806
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.257995,0.0125136) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.663215,0.0017675) , 
8, -0.0703523, 1, 0, 0.62635,0.00248924) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344622,-0.0110105) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.282262,0.00409063) , 
6, 1.94918, 1, 0, 0.302904,-0.00073158) , 
3, 0.904804, 1, 0, 0.501354,0.00124455)    );
  // itree = 807
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518668,-0.00121739) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491119,0.00213749) , 
0, 63194.5, 1, 0, 0.508667,-8.43816e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.190544,0.00947236) , 
6, 8.40124, 1, 0, 0.497546,0.00016036)    );
  // itree = 808
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.946928,0.00487951) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.692871,-0.00299238) , 
6, 2.8276, 1, 0, 0.909525,0.00158005) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.679353,-0.00505457) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306461,-0.00129522) , 
3, -0.377922, 1, 0, 0.367746,-0.00187009) , 
3, -0.808532, 1, 0, 0.498286,-0.00103879)    );
  // itree = 809
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.738578,-0.00275614) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355313,0.000556587) , 
3, 0.52407, 1, 0, 0.555636,-0.00128238) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233665,0.0261415) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.033235,-0.0112528) , 
3, 0.809995, 1, 0, 0.0817572,0.00345186) , 
8, 0.102917, 1, 0, 0.500717,-0.000733721)    );
  // itree = 810
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307535,-0.00435779) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694342,0.00225533) , 
8, -0.0271893, 1, 0, 0.567347,0.000366862) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181429,-0.0103076) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0295359,0.0280514) , 
7, 3.33219, 1, 0, 0.143063,-0.00335211) , 
8, 0.0695119, 1, 0, 0.499276,-0.0002298)    );
  // itree = 811
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489831,-3.74703e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697364,-0.013062) , 
0, 178002, 1, 0, 0.496331,-0.000276908) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580949,0.00639028) , 
1, 16.2857, 1, 0, 0.498561,-0.000102131)    );
  // itree = 812
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.896742,-0.00125116) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.728589,-0.0105684) , 
3, -0.76799, 1, 0, 0.882173,-0.00220861) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.568981,0.0040294) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298318,0.000647346) , 
3, -0.0607247, 1, 0, 0.341882,0.00127692) , 
3, -0.713502, 1, 0, 0.498455,0.000266832)    );
  // itree = 813
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37515,-0.0063037) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0438517,0.00267899) , 
6, 2.24797, 1, 0, 0.212542,-0.00193951) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.722626,-0.00208388) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602613,0.00122015) , 
1, 6.42857, 1, 0, 0.66053,-0.00011975) , 
4, 0.0860338, 1, 0, 0.49846,-0.00077809)    );
  // itree = 814
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502229,0.000372831) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458967,0.00396227) , 
1, 11.3333, 1, 0, 0.498169,0.000580423) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525765,0.00123184) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528058,-0.0169792) , 
3, 0.905411, 1, 0, 0.526954,-0.00488309) , 
1, 14.4762, 1, 0, 0.499702,0.000289427)    );
  // itree = 815
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505134,-0.000275123) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.624689,0.00670266) , 
1, 15, 1, 0, 0.510579,8.54242e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.186625,-0.00825426) , 
6, 8.08697, 1, 0, 0.49818,-0.000167775)    );
  // itree = 816
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506894,-0.001797) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448112,0.0053673) , 
1, 10.6667, 1, 0, 0.498036,-0.000459493) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483724,-0.00931617) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572885,-0.00429763) , 
1, 16.4286, 1, 0, 0.528355,-0.00648043) , 
1, 15, 1, 0, 0.49964,-0.000778007)    );
  // itree = 817
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.870725,0.00066858) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69416,0.00832637) , 
1, 10.7143, 1, 0, 0.855118,0.00175952) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532239,-0.00665004) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306896,-0.000542647) , 
3, -0.37804, 1, 0, 0.315668,-0.000728603) , 
3, -0.523113, 1, 0, 0.50059,0.000124319)    );
  // itree = 818
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.819176,-0.000566126) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.418191,-0.00384783) , 
6, 2.58017, 1, 0, 0.720359,-0.00176096) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325838,0.00307202) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.166278,-0.00515818) , 
6, 4.65955, 1, 0, 0.294306,0.000922502) , 
3, 0.524106, 1, 0, 0.498539,-0.000363843)    );
  // itree = 819
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457982,-0.00140675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984967,0.0101634) , 
4, 0.400092, 1, 0, 0.555118,-0.000615838) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296037,0.0273391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0356729,-0.00895411) , 
3, 0.714992, 1, 0, 0.091165,0.00376578) , 
8, 0.0976232, 1, 0, 0.498958,-8.54502e-05)    );
  // itree = 820
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893832,0.000525889) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530874,-0.00581219) , 
6, 2.59333, 1, 0, 0.822784,-0.00179966) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379519,0.00366824) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295299,0.000120224) , 
3, 0.428904, 1, 0, 0.30729,0.00068051) , 
3, -0.332747, 1, 0, 0.49977,-0.000245561)    );
  // itree = 821
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494109,-0.000282671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494826,-0.00936452) , 
1, 15.4286, 1, 0, 0.494128,-0.000490012) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.727082,0.0089472) , 
0, 191035, 1, 0, 0.501872,-0.00028168)    );
  // itree = 822
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.792685,-0.00377037) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345921,-0.00147222) , 
3, 0.0480381, 1, 0, 0.548562,-0.00222265) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.169498,-0.00368562) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680012,0.00400008) , 
4, 0.114608, 1, 0, 0.422404,0.000785679) , 
7, 0.476978, 1, 0, 0.499214,-0.00104591)    );
  // itree = 823
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.164536,0.00376249) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519197,-0.00859367) , 
5, 2.15408, 1, 0, 0.217827,0.000591831) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.856692,-0.00464218) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599477,0.000414809) , 
3, 0.524121, 1, 0, 0.739981,-0.00227664) , 
4, 0.114542, 1, 0, 0.500336,-0.000960144)    );
  // itree = 824
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.928424,-0.000386231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.743029,-0.00583565) , 
1, 8.09524, 1, 0, 0.906615,-0.00128306) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.687049,0.00469495) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310758,0.00153924) , 
3, -0.377756, 1, 0, 0.372961,0.00192823) , 
3, -0.808344, 1, 0, 0.501021,0.00115762)    );
  // itree = 825
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.461699,0.0169273) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519927,0.00216302) , 
4, 0.0290175, 1, 0, 0.515566,0.00239487) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508855,0.00566149) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453519,-0.00362455) , 
1, 7.2381, 1, 0, 0.468623,-0.00099384) , 
0, 66685.9, 1, 0, 0.498817,0.0011858)    );
  // itree = 826
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.990776,0.0273036) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483531,-0.000558333) , 
6, 0.420377, 1, 0, 0.515255,-0.00018821) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.188006,0.00762242) , 
6, 7.71137, 1, 0, 0.501442,5.51189e-05)    );
  // itree = 827
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524957,-0.00130575) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4455,0.00218152) , 
0, 65430.5, 1, 0, 0.504084,-0.000399088) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680239,0.0105021) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.438015,-0.000254743) , 
3, -0.422362, 1, 0, 0.480102,0.00281648) , 
1, 10.8571, 1, 0, 0.499481,0.000218163)    );
  // itree = 828
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549432,0.00050565) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.195226,-0.00366025) , 
6, 3.86292, 1, 0, 0.485994,-0.000154497) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.886478,-0.00949544) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50893,0.00837388) , 
6, 3.26348, 1, 0, 0.648357,0.00278745) , 
0, 135690, 1, 0, 0.499965,9.86446e-05)    );
  // itree = 829
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984958,-0.00687154) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721791,0.00349273) , 
1, 2.14286, 1, 0, 0.825245,0.00255999) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.253382,-0.00247751) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579626,0.00885992) , 
0, 117763, 1, 0, 0.304426,-0.000698336) , 
3, -0.332747, 1, 0, 0.4999,0.000524579)    );
  // itree = 830
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0721035,0.00591145) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0548971,-0.0210532) , 
0, 64281.1, 1, 0, 0.0648935,-0.00189307) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.413527,0.00137123) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965064,-0.00325728) , 
4, 0.285901, 1, 0, 0.580081,0.00058514) , 
7, -2.37811, 1, 0, 0.501353,0.000206436)    );
  // itree = 831
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545228,-0.00107852) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5441,0.00527213) , 
1, 10, 1, 0, 0.544989,0.000326579) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203441,0.000604489) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235651,-0.0133903) , 
1, 10.2857, 1, 0, 0.21762,-0.0051176) , 
6, 4.83203, 1, 0, 0.500518,-0.000412967)    );
  // itree = 832
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570428,0.00372256) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474831,-0.00363666) , 
8, 0.0269583, 1, 0, 0.549324,0.00160717) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0197723,0.0157717) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0668269,-0.015062) , 
7, -2.38077, 1, 0, 0.0504281,-0.00328822) , 
8, 0.124933, 1, 0, 0.501243,0.00113537)    );
  // itree = 833
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.269309,-0.00245539) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603499,0.00171253) , 
4, 0.0574807, 1, 0, 0.528849,0.000764173) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0883245,0.0111814) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243501,-0.0089333) , 
7, -1.43106, 1, 0, 0.19414,-0.00374064) , 
6, 6.01332, 1, 0, 0.501152,0.000391406)    );
  // itree = 834
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.623337,0.00279158) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.935515,-0.00260148) , 
4, 0.228653, 1, 0, 0.750331,0.00142188) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0446641,-0.00501727) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.796179,0.0053) , 
4, 0.171682, 1, 0, 0.295219,-0.000442587) , 
3, 0.333627, 1, 0, 0.501032,0.000400569)    );
  // itree = 835
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538341,-0.00102878) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.370291,0.00300545) , 
1, 8.09524, 1, 0, 0.508431,-0.000223412) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27665,-0.00627012) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971183,0.00825724) , 
4, 0.34297, 1, 0, 0.464468,-0.00408813) , 
1, 10.8571, 1, 0, 0.49993,-0.000970739)    );
  // itree = 836
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481801,0.00396576) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.754082,-0.00200771) , 
7, -1.43953, 1, 0, 0.721029,-0.00122441) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0386209,-0.011187) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358416,0.00311631) , 
8, -0.0857566, 1, 0, 0.293311,0.000901903) , 
3, 0.524019, 1, 0, 0.497768,-0.000114515)    );
  // itree = 837
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.979845,-0.000979969) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.802226,-0.00839809) , 
1, 4.28571, 1, 0, 0.937098,-0.00318165) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.130878,-0.000291791) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.70524,0.00215713) , 
4, 0.114588, 1, 0, 0.436729,0.00097371) , 
3, -0.903924, 1, 0, 0.502063,0.000431138)    );
  // itree = 838
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.936388,-0.00144883) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669592,0.00669327) , 
6, 2.60673, 1, 0, 0.891502,0.00133541) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0966985,-0.000512119) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.860406,-0.00444146) , 
4, 0.200098, 1, 0, 0.342463,-0.0013576) , 
3, -0.713531, 1, 0, 0.502152,-0.000574337)    );
  // itree = 839
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163675,0.00371291) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52466,-0.00437787) , 
5, 2.15377, 1, 0, 0.217827,0.00122583) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.948631,0.00367275) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.654703,-0.00258567) , 
3, -0.808532, 1, 0, 0.738904,-0.00115902) , 
4, 0.114417, 1, 0, 0.50151,-7.25287e-05)    );
  // itree = 840
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.936679,0.00093618) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.808692,-0.00633169) , 
3, -0.890134, 1, 0, 0.868818,-0.00352572) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.119998,0.00293209) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.930044,-0.00278997) , 
4, 0.257222, 1, 0, 0.326557,0.00127703) , 
3, -0.61816, 1, 0, 0.500535,-0.000263871)    );
  // itree = 841
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.690007,-0.00133403) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285261,0.00622459) , 
6, 5.39641, 1, 0, 0.657895,-0.000616707) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264681,-0.0031644) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328895,0.00742886) , 
3, 0.981871, 1, 0, 0.303481,0.00109039) , 
3, 0.809607, 1, 0, 0.500219,0.000142766)    );
  // itree = 842
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562396,0.00179519) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.74096,-0.00518826) , 
2, 92583.9, 1, 0, 0.592686,0.000725744) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.119961,0.000954571) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.897147,-0.0118752) , 
5, 3.39697, 1, 0, 0.293782,-0.0015544) , 
6, 3.04092, 1, 0, 0.499131,1.20777e-05)    );
  // itree = 843
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496947,-0.000774317) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.476341,-0.00617748) , 
1, 12.6667, 1, 0, 0.495851,-0.000849015) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534984,0.0108785) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558491,-0.000706018) , 
3, 0.905411, 1, 0, 0.546977,0.00645319) , 
1, 14.4762, 1, 0, 0.498502,-0.000470314)    );
  // itree = 844
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32415,-0.000847296) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.166467,-0.00677958) , 
0, 80345, 1, 0, 0.288936,-0.00186234) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.936148,0.0072488) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.901088,-0.00328777) , 
1, 10.7143, 1, 0, 0.92763,0.00251246) , 
4, 0.228798, 1, 0, 0.498421,-0.000427456)    );
  // itree = 845
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599848,0.00454262) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0393802,0.00152268) , 
3, 0.144539, 1, 0, 0.232388,0.00245517) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.851676,-0.00199894) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258025,0.00999749) , 
7, 2.37899, 1, 0, 0.810417,-0.000695734) , 
4, 0.142988, 1, 0, 0.501152,0.000990103)    );
  // itree = 846
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827428,-0.00581671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.083701,0.00169339) , 
1, 3.2381, 1, 0, 0.229771,0.000217247) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.854465,0.00215596) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.255646,0.0107436) , 
7, 2.38025, 1, 0, 0.812024,0.00240143) , 
4, 0.1431, 1, 0, 0.502131,0.00123894)    );
  // itree = 847
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0512595,0.00450783) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238278,-0.00833413) , 
8, -0.066228, 1, 0, 0.189672,-0.00365691) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.648754,-0.000655533) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339973,0.00481565) , 
6, 3.79441, 1, 0, 0.587908,0.000407761) , 
7, -1.42818, 1, 0, 0.500974,-0.000479545)    );
  // itree = 848
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543795,-0.00124594) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244453,-0.0103656) , 
6, 4.87474, 1, 0, 0.527561,-0.00132433) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294709,0.00864249) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.149215,-0.00399442) , 
3, 0.714594, 1, 0, 0.201344,0.0027826) , 
6, 6.01287, 1, 0, 0.500306,-0.000981208)    );
  // itree = 849
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.12092,-0.00094128) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.689256,0.00694179) , 
7, -1.83544, 1, 0, 0.417493,0.00327586) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480044,-0.00196694) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.987966,0.0137438) , 
4, 0.457222, 1, 0, 0.55036,-0.00108639) , 
7, -0.475025, 1, 0, 0.499685,0.00057736)    );
  // itree = 850
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330552,0.00832458) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0729199,-0.00558079) , 
0, 60699.7, 1, 0, 0.216673,0.00198051) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.127463,0.00771027) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72344,-0.000824627) , 
7, -2.38003, 1, 0, 0.656898,-7.12486e-05) , 
4, 0.0859887, 1, 0, 0.498318,0.000667848)    );
  // itree = 851
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.686926,0.00475816) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0348837,-0.00040977) , 
3, -0.330717, 1, 0, 0.221568,0.0015224) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366393,-0.00426084) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.882229,-0.00021685) , 
4, 0.183895, 1, 0, 0.740494,-0.00157132) , 
4, 0.114545, 1, 0, 0.502002,-0.000149482)    );
  // itree = 852
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827601,-0.00452222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.114846,-0.000452879) , 
3, -0.713072, 1, 0, 0.287269,-0.00147731) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.955535,0.00837553) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.898085,-0.00406092) , 
3, -0.332724, 1, 0, 0.925911,0.00110864) , 
4, 0.228675, 1, 0, 0.49754,-0.000625898)    );
  // itree = 853
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498975,0.000559769) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504377,0.00638381) , 
1, 13.5714, 1, 0, 0.499174,0.000629652) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540301,-0.0053852) , 
1, 15.4286, 1, 0, 0.500705,0.000407773)    );
  // itree = 854
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0705488,0.00687708) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583862,-0.00152223) , 
7, -2.38052, 1, 0, 0.507848,-0.000674552) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.700992,-0.00508044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433623,0.0051913) , 
3, -0.608002, 1, 0, 0.470205,0.00207956) , 
1, 10.7143, 1, 0, 0.500616,-0.000145479)    );
  // itree = 855
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893415,-0.00211578) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.691934,0.00655161) , 
3, -0.749665, 1, 0, 0.854606,0.000498695) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499888,-0.00628165) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302365,-0.00243834) , 
3, -0.232868, 1, 0, 0.315774,-0.00206429) , 
3, -0.522974, 1, 0, 0.50008,-0.00118763)    );
  // itree = 856
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.632245,0.00233646) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.214459,-0.00475839) , 
6, 2.29092, 1, 0, 0.49763,-0.000177403) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562943,0.00511453) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0419677,-0.0205076) , 
8, 0.123468, 1, 0, 0.505413,0.00264391) , 
0, 80345.2, 1, 0, 0.499671,0.000562525)    );
  // itree = 857
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.89068,0.00266671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357931,-0.00217053) , 
1, 3.33333, 1, 0, 0.504926,-0.000907494) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.134963,0.00598178) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.882167,-0.000964031) , 
4, 0.200234, 1, 0, 0.477025,0.00278178) , 
1, 10.7143, 1, 0, 0.499509,-0.000191291)    );
  // itree = 858
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.994327,0.0385085) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483697,-0.000315174) , 
6, 0.412309, 1, 0, 0.514792,4.91888e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.183998,-0.0116636) , 
6, 7.56173, 1, 0, 0.499635,-0.000356786)    );
  // itree = 859
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.83345,0.0145176) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.79029,0.00140412) , 
4, 0.0289186, 1, 0, 0.794582,0.00174182) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.692266,-0.00304814) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308553,-7.54716e-05) , 
3, -0.522131, 1, 0, 0.378507,-0.000916954) , 
1, 4.28571, 1, 0, 0.498483,-0.000150295)    );
  // itree = 860
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.430287,0.00329272) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0871189,-0.0151344) , 
0, 52128.4, 1, 0, 0.236194,-0.00275796) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.944996,-0.00528926) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527688,0.00216421) , 
3, -0.90352, 1, 0, 0.580159,0.00129764) , 
4, 0.0574794, 1, 0, 0.500464,0.00035798)    );
  // itree = 861
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542773,0.000326185) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68585,-0.00872549) , 
0, 80345, 1, 0, 0.566073,-0.000580221) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.410711,0.00817704) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.21308,-9.79969e-05) , 
3, 0.333638, 1, 0, 0.264072,0.0030802) , 
6, 3.79441, 1, 0, 0.500277,0.000217268)    );
  // itree = 862
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.840164,-0.00153315) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.299791,0.0019472) , 
3, -0.427943, 1, 0, 0.497139,0.000287287) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.568078,0.010422) , 
1, 15.4286, 1, 0, 0.499779,0.000665921)    );
  // itree = 863
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.438384,0.00944625) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0912144,-0.00387268) , 
0, 51967.1, 1, 0, 0.239367,0.00173692) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554652,-0.00317773) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.636615,0.00125906) , 
0, 71380.7, 1, 0, 0.579805,-0.00156143) , 
4, 0.0574332, 1, 0, 0.50024,-0.000790556)    );
  // itree = 864
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.942942,-0.00145295) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.611435,-0.00702734) , 
6, 1.11232, 1, 0, 0.791433,-0.00369507) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0331712,-0.0124194) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.410947,3.24318e-05) , 
4, 0.0287343, 1, 0, 0.380293,-0.000412448) , 
1, 4.28571, 1, 0, 0.500374,-0.0013712)    );
  // itree = 865
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.490577,-0.00134962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535438,0.00640873) , 
0, 95285.6, 1, 0, 0.497649,-0.000280119) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.185331,-0.00112905) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.851839,-0.0121876) , 
4, 0.201297, 1, 0, 0.535132,-0.00568224) , 
1, 15, 1, 0, 0.499641,-0.000567304)    );
  // itree = 866
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.649328,0.00809968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.821436,0.000323442) , 
7, -1.42593, 1, 0, 0.804304,0.0012559) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353719,-0.00938899) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294241,-0.00029182) , 
3, 0.238509, 1, 0, 0.298392,-0.000933991) , 
3, -0.142334, 1, 0, 0.498145,-6.93404e-05)    );
  // itree = 867
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330822,-0.0031385) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.148562,0.00172782) , 
1, 9.09524, 1, 0, 0.288941,-0.00162891) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.93048,-0.000238794) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.92376,0.0113739) , 
3, 0.809611, 1, 0, 0.928032,0.00157727) , 
4, 0.228794, 1, 0, 0.50015,-0.000569324)    );
  // itree = 868
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.885729,0.00126863) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541743,0.00426085) , 
6, 2.841, 1, 0, 0.82567,0.00215095) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247326,-0.00233091) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550386,0.00609226) , 
0, 108371, 1, 0, 0.304134,-0.000680937) , 
3, -0.332724, 1, 0, 0.498255,0.000373121)    );
  // itree = 869
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405356,-0.00530087) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0653063,0.00275993) , 
6, 2.06925, 1, 0, 0.226158,-0.00143877) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.853876,0.00102718) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531283,0.00702294) , 
7, 1.43039, 1, 0, 0.807775,0.00180002) , 
4, 0.142979, 1, 0, 0.496114,6.45092e-05)    );
  // itree = 870
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167691,0.0159232) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674453,-0.0023051) , 
8, -0.0819735, 1, 0, 0.620202,-0.000721623) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329453,0.00568203) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470698,-0.00139364) , 
0, 73872.5, 1, 0, 0.396406,0.00219032) , 
1, 6.85714, 1, 0, 0.501824,0.000818658)    );
  // itree = 871
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.757786,-0.00177118) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.149026,0.018646) , 
7, 2.38258, 1, 0, 0.700144,-9.64875e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233139,-0.00505417) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.976729,0.00905597) , 
4, 0.371461, 1, 0, 0.377414,-0.00316044) , 
1, 5.14286, 1, 0, 0.498595,-0.00200996)    );
  // itree = 872
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.751116,0.00354392) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.188828,-0.00711752) , 
3, 0.904813, 1, 0, 0.622605,0.00169212) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.626588,-0.00479777) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335399,0.000296526) , 
3, -0.327537, 1, 0, 0.391792,-0.00130625) , 
1, 6.66667, 1, 0, 0.500171,0.000101647)    );
  // itree = 873
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.977794,0.00452222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524243,0.00746786) , 
3, -0.618012, 1, 0, 0.887967,0.00323068) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0603134,-0.0110383) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447413,0.000691261) , 
8, -0.0872347, 1, 0, 0.388848,-4.33359e-05) , 
1, 3.42857, 1, 0, 0.499326,0.000681359)    );
  // itree = 874
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0710144,-0.0126726) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0430354,0.0127294) , 
6, 4.50426, 1, 0, 0.0637553,-0.00299131) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.839787,-0.00143944) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456794,0.00174337) , 
1, 5, 1, 0, 0.579028,0.000782303) , 
7, -2.37824, 1, 0, 0.500986,0.000210757)    );
  // itree = 875
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550811,-0.00174121) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470642,0.00684366) , 
0, 64440.7, 1, 0, 0.533639,-0.000122629) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466846,-0.00458835) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396535,-0.000207431) , 
3, 0.810864, 1, 0, 0.424269,-0.00230515) , 
1, 8.57143, 1, 0, 0.496892,-0.000855938)    );
  // itree = 876
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721479,0.00277618) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41571,0.0147048) , 
6, 3.87945, 1, 0, 0.699654,0.00276936) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.652321,-0.00243245) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315691,0.000704148) , 
3, -0.423295, 1, 0, 0.379218,-0.000386662) , 
1, 5.42857, 1, 0, 0.499801,0.000800975)    );
  // itree = 877
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455018,0.00336611) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0424781,-0.00298047) , 
7, 2.38034, 1, 0, 0.378283,0.00254095) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.933281,-0.0047216) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.99824,0.0302527) , 
5, 9.576, 1, 0, 0.970401,-0.000172583) , 
4, 0.342988, 1, 0, 0.501778,0.001975)    );
  // itree = 878
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420262,0.000312587) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372765,-0.00590556) , 
1, 11, 1, 0, 0.411137,-0.000717606) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72884,0.00380016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.10226,-0.00557457) , 
7, 2.01983, 1, 0, 0.555011,0.00184277) , 
7, -0.473935, 1, 0, 0.5006,0.000874472)    );
  // itree = 879
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323057,0.00640597) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.073107,-0.00376183) , 
0, 64280.4, 1, 0, 0.221349,0.00180476) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.256054,-0.0081577) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.719067,-0.0013781) , 
8, -0.0602018, 1, 0, 0.65815,-0.00190032) , 
4, 0.0858625, 1, 0, 0.501598,-0.0005724)    );
  // itree = 880
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.576331,-0.00010036) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536098,0.00327593) , 
0, 65842.7, 1, 0, 0.561829,0.000847737) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0551387,0.00362921) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0211899,-0.0242365) , 
1, 7.47619, 1, 0, 0.0375864,-0.00257542) , 
7, 3.33313, 1, 0, 0.49973,0.000442251)    );
  // itree = 881
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244826,0.0112126) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0429929,-0.00319863) , 
3, 0.905058, 1, 0, 0.115949,0.00271691) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.683076,0.0013703) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.365404,-0.00477244) , 
8, 0.0221806, 1, 0, 0.562744,-0.000550067) , 
8, -0.0765395, 1, 0, 0.499521,-8.77744e-05)    );
  // itree = 882
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264639,-0.000320667) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.817199,0.00288937) , 
4, 0.19479, 1, 0, 0.393647,0.00050101) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.959516,-0.0163846) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.985236,0.00425813) , 
3, 0.143394, 1, 0, 0.97255,-0.00307834) , 
4, 0.371565, 1, 0, 0.501453,-0.000165558)    );
  // itree = 883
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.869893,-0.00558537) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.373582,0.000717132) , 
3, -0.618307, 1, 0, 0.547439,-0.00135705) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.185289,0.00603586) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.757363,-0.00275997) , 
4, 0.143228, 1, 0, 0.422769,0.00118128) , 
7, 0.477652, 1, 0, 0.49871,-0.000364919)    );
  // itree = 884
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.598269,0.003729) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0467856,-0.0018334) , 
3, 0.238635, 1, 0, 0.247343,0.00114172) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521131,-0.0113044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.88732,-0.000349242) , 
4, 0.192048, 1, 0, 0.859869,-0.00145711) , 
4, 0.171638, 1, 0, 0.498387,7.65905e-05)    );
  // itree = 885
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498011,0.000950555) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495725,-0.00470799) , 
1, 13.7143, 1, 0, 0.497899,0.000456917) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58566,0.00853458) , 
1, 16.2857, 1, 0, 0.500225,0.000663189)    );
  // itree = 886
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.851756,0.00435909) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305175,-0.0042136) , 
1, 3.2381, 1, 0, 0.410527,-0.00207469) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.688425,0.00247998) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0408556,-0.0060948) , 
7, 3.01614, 1, 0, 0.552822,0.00137812) , 
7, -0.475825, 1, 0, 0.498687,6.45356e-05)    );
  // itree = 887
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313917,0.00720759) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69031,-0.00255542) , 
8, -0.0645724, 1, 0, 0.655748,-0.00167835) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0334152,-0.0210811) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371419,0.00513756) , 
8, -0.0857566, 1, 0, 0.300016,0.00124494) , 
3, 0.809611, 1, 0, 0.498101,-0.000382857)    );
  // itree = 888
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512668,-0.000724605) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550188,0.00442654) , 
1, 11.6667, 1, 0, 0.517372,1.87937e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.179978,-0.00751934) , 
6, 7.54854, 1, 0, 0.501874,-0.000235233)    );
  // itree = 889
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557781,-0.000623499) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.15693,-0.00963307) , 
6, 3.40404, 1, 0, 0.497857,-0.0015249) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572661,0.00384224) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0400712,-0.0229206) , 
7, 3.32539, 1, 0, 0.504501,0.00158737) , 
0, 80345.2, 1, 0, 0.499605,-0.000706158)    );
  // itree = 890
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381527,-0.00646417) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0451136,0.00124325) , 
6, 2.23362, 1, 0, 0.216287,-0.00230971) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.450049,0.00317052) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.955279,0.000543708) , 
4, 0.281715, 1, 0, 0.660559,0.00226026) , 
4, 0.0858607, 1, 0, 0.501736,0.000626537)    );
  // itree = 891
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.887638,0.000883325) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.666019,0.00878664) , 
3, -0.704496, 1, 0, 0.857996,0.00238327) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381384,-0.0036234) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2966,0.000595103) , 
3, 0.564829, 1, 0, 0.315426,-0.000711362) , 
3, -0.523139, 1, 0, 0.502145,0.000353618)    );
  // itree = 892
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.291825,-0.00432729) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.865272,0.0007171) , 
4, 0.171532, 1, 0, 0.51612,-0.00184265) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356616,0.00832493) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491606,-0.00170307) , 
0, 66708.4, 1, 0, 0.454049,0.00133289) , 
1, 9.04762, 1, 0, 0.500045,-0.00102025)    );
  // itree = 893
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.861516,0.000537307) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437479,0.00357467) , 
3, -0.55485, 1, 0, 0.752127,0.00158778) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.33063,0.000516263) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.207009,-0.00543861) , 
6, 3.84547, 1, 0, 0.29518,-0.000553202) , 
3, 0.333638, 1, 0, 0.502222,0.000416878)    );
  // itree = 894
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.162992,0.00641366) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.43201,-0.00321122) , 
5, 1.47556, 1, 0, 0.222343,0.00208294) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.210902,-0.00611628) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.728568,0.000200979) , 
4, 0.110465, 1, 0, 0.657752,-0.000616501) , 
4, 0.0859887, 1, 0, 0.500417,0.000358942)    );
  // itree = 895
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.249515,-0.00113629) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.704691,0.00267294) , 
4, 0.0860279, 1, 0, 0.550524,0.00127614) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721443,-0.00393126) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230278,-7.59904e-05) , 
3, 0.238513, 1, 0, 0.419487,-0.00158696) , 
7, 0.476767, 1, 0, 0.499573,0.000162887)    );
  // itree = 896
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.835637,0.000877312) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432649,0.0057178) , 
3, -0.400783, 1, 0, 0.772864,0.00191931) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347351,-0.00469815) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258785,0.00311877) , 
6, 2.0927, 1, 0, 0.29172,-0.000108511) , 
3, 0.143249, 1, 0, 0.497182,0.000757426)    );
  // itree = 897
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577315,0.000594999) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.156937,-0.00806616) , 
8, 0.0670817, 1, 0, 0.509804,-0.000267973) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.190338,0.0133775) , 
6, 8.4133, 1, 0, 0.498858,8.24776e-05)    );
  // itree = 898
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.215297,0.00233555) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235272,0.0121105) , 
4, 0.0982264, 1, 0, 0.2176,0.0026218) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.97065,0.0184529) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.690979,-0.0019314) , 
1, 2.14286, 1, 0, 0.740084,-0.000646722) , 
4, 0.114544, 1, 0, 0.501535,0.000845575)    );
  // itree = 899
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512275,0.000993035) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41201,-0.00291598) , 
1, 9.14286, 1, 0, 0.488992,-2.28837e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.711138,-0.014541) , 
0, 176762, 1, 0, 0.498245,-0.000400072)    );
  // itree = 900
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.23529,0.000402279) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499682,0.00527811) , 
4, 0.152639, 1, 0, 0.267981,0.00114735) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.687314,-0.00668209) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.930994,0.00019816) , 
4, 0.238305, 1, 0, 0.897928,-0.00112664) , 
4, 0.200227, 1, 0, 0.500353,0.000308529)    );
  // itree = 901
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.625371,0.00260002) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.192832,-0.00421211) , 
6, 2.37387, 1, 0, 0.506915,0.000409142) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527588,-0.00701912) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447072,0.00264452) , 
3, 0.809642, 1, 0, 0.480594,-0.00232376) , 
0, 71380.3, 1, 0, 0.498402,-0.000474725)    );
  // itree = 902
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.81624,-0.00879995) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0843674,-0.000253367) , 
1, 3.33333, 1, 0, 0.228448,-0.00139952) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515259,0.0114868) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.856938,0.000416072) , 
7, -1.42922, 1, 0, 0.809795,0.00199495) , 
4, 0.142987, 1, 0, 0.499084,0.000180716)    );
  // itree = 903
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.909897,-0.000632665) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.688828,0.00488636) , 
3, -0.808705, 1, 0, 0.830915,0.00218094) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.444373,-0.00974765) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296776,-0.000197029) , 
3, -0.0788179, 1, 0, 0.304129,-0.000783779) , 
3, -0.332723, 1, 0, 0.499829,0.000317611)    );
  // itree = 904
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332549,0.0119565) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.240607,-0.00241847) , 
4, 0.0164961, 1, 0, 0.245907,-0.00148341) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.730226,0.00509835) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965701,-0.000309648) , 
4, 0.314367, 1, 0, 0.864877,0.00254006) , 
4, 0.17155, 1, 0, 0.49984,0.000167221)    );
  // itree = 905
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.133003,0.00917685) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603194,0.000545054) , 
8, -0.0812294, 1, 0, 0.548597,0.000954016) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0829116,0.0102486) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.00888048,-0.02907) , 
3, 0.905255, 1, 0, 0.0290316,-0.00184821) , 
7, 4.28454, 1, 0, 0.499413,0.000688749)    );
  // itree = 906
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918399,0.0110393) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.968214,-0.00441157) , 
4, 0.143218, 1, 0, 0.945999,0.00282062) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.765076,-0.00282558) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307995,0.000147331) , 
3, -0.359686, 1, 0, 0.434583,-0.00085508) , 
3, -0.903565, 1, 0, 0.500165,-0.000383721)    );
  // itree = 907
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.662385,-0.00697775) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0863101,0.000758863) , 
1, 4.85714, 1, 0, 0.241033,-0.00118117) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.732727,0.00354264) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.964975,-0.000700755) , 
4, 0.314456, 1, 0, 0.864092,0.00171175) , 
4, 0.171689, 1, 0, 0.495356,-3.22984e-07)    );
  // itree = 908
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0376664,0.0016191) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0789191,-0.0119254) , 
8, -0.0383498, 1, 0, 0.0632566,-0.00330508) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579609,-0.000424476) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575648,0.00350665) , 
0, 73870.2, 1, 0, 0.57842,0.000514926) , 
7, -2.37838, 1, 0, 0.500493,-6.29104e-05)    );
  // itree = 909
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403852,-0.00121428) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0198577,-0.0154785) , 
1, 7.14286, 1, 0, 0.235228,-0.00308196) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.189117,-0.00152562) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.728037,0.00217587) , 
4, 0.10926, 1, 0, 0.581255,0.00102872) , 
4, 0.0576017, 1, 0, 0.501145,7.70375e-05)    );
  // itree = 910
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.745635,0.00247108) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405596,-0.00539207) , 
6, 1.51412, 1, 0, 0.602243,-0.00115277) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.10704,0.00589592) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.864972,-0.00736156) , 
5, 2.89511, 1, 0, 0.301759,0.00142682) , 
6, 2.84095, 1, 0, 0.498339,-0.000260775)    );
  // itree = 911
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.275846,0.0012054) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.903895,-0.00363607) , 
4, 0.200246, 1, 0, 0.508316,-0.000225829) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.188474,-0.0152307) , 
6, 9.01162, 1, 0, 0.499516,-0.000536556)    );
  // itree = 912
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.995537,-0.0294417) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.876232,0.00283922) , 
1, 1.52381, 1, 0, 0.911553,0.00155608) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0640263,-0.0116413) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399633,-0.000127548) , 
4, 0.0287355, 1, 0, 0.371269,-0.00050508) , 
3, -0.808397, 1, 0, 0.502375,-4.91755e-06)    );
  // itree = 913
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.60415,0.00152468) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.135655,-0.00256917) , 
3, 0.714846, 1, 0, 0.37457,0.000177437) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.959114,-0.0149086) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986594,0.0181599) , 
0, 92750.6, 1, 0, 0.967712,-0.00301782) , 
4, 0.343012, 1, 0, 0.496672,-0.000480324)    );
  // itree = 914
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357934,-0.000849904) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305059,0.00461368) , 
1, 14.5714, 1, 0, 0.355681,-0.000456183) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.934918,0.014158) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.972291,0.00518394) , 
4, 0.341567, 1, 0, 0.968171,0.00271383) , 
4, 0.314362, 1, 0, 0.499185,0.000286537)    );
  // itree = 915
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0922179,0.023989) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0140574,-0.00918827) , 
3, 0.904997, 1, 0, 0.0355918,0.00276181) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.077203,-0.01488) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570831,-0.000274096) , 
7, -2.92433, 1, 0, 0.549985,-0.000553301) , 
7, -4.28518, 1, 0, 0.502206,-0.000245376)    );
  // itree = 916
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499972,0.00125281) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481834,0.011592) , 
1, 12.381, 1, 0, 0.499399,0.00121062) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.195619,-0.0089377) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.903481,0.000217996) , 
4, 0.229262, 1, 0, 0.527196,-0.00543953) , 
1, 13.7143, 1, 0, 0.501419,0.000727229)    );
  // itree = 917
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.654353,0.00113136) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.19846,-0.00902966) , 
6, 2.14007, 1, 0, 0.520842,-0.00189343) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.078926,-0.00444144) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.800841,0.00598283) , 
4, 0.114425, 1, 0, 0.46592,0.00142277) , 
0, 64440.9, 1, 0, 0.500429,-0.000660874)    );
  // itree = 918
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.225717,-0.00145463) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.191292,0.0111758) , 
4, 0.0695349, 1, 0, 0.219001,0.000994204) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.712115,-0.00220725) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0756506,0.00781778) , 
7, 3.32866, 1, 0, 0.658853,-0.00143853) , 
4, 0.0858625, 1, 0, 0.501233,-0.000566767)    );
  // itree = 919
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548339,-0.000682185) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380513,0.00719276) , 
0, 52922.9, 1, 0, 0.50466,0.00103665) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527787,-0.0069693) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447979,0.0036148) , 
3, 0.809611, 1, 0, 0.480926,-0.00200844) , 
0, 73870.2, 1, 0, 0.497464,0.000113405)    );
  // itree = 920
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.610154,-0.00110026) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426532,0.00142677) , 
0, 40810.6, 1, 0, 0.495723,0.000346885) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.723824,0.01088) , 
0, 191035, 1, 0, 0.503259,0.000565228)    );
  // itree = 921
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989206,-0.00662616) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.802435,0.0044415) , 
1, 2.14286, 1, 0, 0.888517,0.0028069) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510141,-0.00411748) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293821,-0.000413225) , 
3, 0.265683, 1, 0, 0.340266,-0.00140563) , 
3, -0.713531, 1, 0, 0.499478,-0.000182306)    );
  // itree = 922
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49971,0.000820148) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482938,-0.00437527) , 
1, 12.1905, 1, 0, 0.498415,0.000256443) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584827,0.0060791) , 
1, 16.2857, 1, 0, 0.500686,0.000402517)    );
  // itree = 923
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52636,0.00116816) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.199227,-0.00965115) , 
6, 6.11827, 1, 0, 0.514851,0.000624677) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181564,-0.00996175) , 
6, 7.54854, 1, 0, 0.499411,0.000256809)    );
  // itree = 924
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.731179,-0.00188526) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305795,0.00231961) , 
3, 0.524019, 1, 0, 0.513143,-0.000291689) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.176628,-0.0116942) , 
6, 8.08697, 1, 0, 0.500656,-0.000611475)    );
  // itree = 925
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203623,-0.00171029) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513982,-0.0217027) , 
5, 0.566747, 1, 0, 0.293969,-0.00384682) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569739,-0.00079644) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440761,0.00169225) , 
7, 0.47601, 1, 0, 0.519461,9.92831e-05) , 
4, 0.0288758, 1, 0, 0.499663,-0.000247193)    );
  // itree = 926
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.454192,-0.00057968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.378434,-0.00472359) , 
0, 71380.7, 1, 0, 0.431201,-0.00147767) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.985742,-0.00840746) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983553,0.0132538) , 
1, 3.04762, 1, 0, 0.984001,0.00240723) , 
4, 0.45719, 1, 0, 0.500919,-0.000987706)    );
  // itree = 927
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222809,0.00220391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349149,0.0104407) , 
4, 0.129494, 1, 0, 0.230769,0.00220088) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.865287,-0.00365828) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.708379,0.00387773) , 
3, 0.809651, 1, 0, 0.806652,-0.00114853) , 
4, 0.143091, 1, 0, 0.498516,0.000643629)    );
  // itree = 928
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586229,-0.00180215) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.078378,0.0142198) , 
8, 0.111923, 1, 0, 0.535881,-0.000762106) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.467649,0.00362667) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0159667,-0.0272797) , 
7, 5.22815, 1, 0, 0.429033,0.00230065) , 
1, 8.57143, 1, 0, 0.500005,0.000266279)    );
  // itree = 929
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.885689,-0.000525888) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374559,0.00333671) , 
1, 3.42857, 1, 0, 0.500746,0.00198588) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4976,-0.00546895) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509525,0.000172466) , 
3, 0.905113, 1, 0, 0.503922,-0.0031788) , 
1, 12.8571, 1, 0, 0.501069,0.00145951)    );
  // itree = 930
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877899,-0.0013936) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629007,-0.00785594) , 
3, -0.681529, 1, 0, 0.850273,-0.0023659) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303108,-0.0027069) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322366,0.00140381) , 
1, 5.42857, 1, 0, 0.318244,0.000168317) , 
3, -0.522852, 1, 0, 0.500414,-0.000699417)    );
  // itree = 931
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.979509,-9.22577e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.796017,-0.0109087) , 
1, 4.57143, 1, 0, 0.934627,-0.00387807) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.589768,0.00182265) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363126,-0.000841037) , 
1, 5.42857, 1, 0, 0.433758,3.67624e-05) , 
3, -0.903924, 1, 0, 0.497882,-0.000464441)    );
  // itree = 932
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541018,-0.000476545) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243195,-0.0107056) , 
6, 4.88848, 1, 0, 0.524646,-0.000761461) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.114844,-0.00592959) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25427,0.0147991) , 
0, 109719, 1, 0, 0.192951,0.00502347) , 
6, 6.02601, 1, 0, 0.49721,-0.000282962)    );
  // itree = 933
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62721,0.00253465) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.21818,-0.00177583) , 
1, 5.42857, 1, 0, 0.37553,-0.000202857) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984401,0.00109476) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.953443,0.0143236) , 
6, 2.62529, 1, 0, 0.974401,0.00300734) , 
4, 0.34299, 1, 0, 0.498828,0.000458069)    );
  // itree = 934
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.604531,-0.00212942) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.408661,0.00296903) , 
0, 40812, 1, 0, 0.486195,0.000688599) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.615934,-0.0126128) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.639072,0.000196114) , 
3, 0.619466, 1, 0, 0.631772,-0.00420315) , 
0, 135690, 1, 0, 0.498435,0.000277296)    );
  // itree = 935
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.911891,0.00246164) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.73086,0.00727387) , 
1, 8.09524, 1, 0, 0.88815,0.00303715) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371585,0.000399058) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.170195,-0.00964981) , 
6, 4.8492, 1, 0, 0.338068,-0.000619839) , 
3, -0.713502, 1, 0, 0.499272,0.000451856)    );
  // itree = 936
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235813,0.00034675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507274,0.00726372) , 
4, 0.152504, 1, 0, 0.270121,0.00149885) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.955377,0.00349957) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.852524,-0.0057831) , 
3, -0.618307, 1, 0, 0.896503,-0.00162397) , 
4, 0.200112, 1, 0, 0.500426,0.000350667)    );
  // itree = 937
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.553642,-0.00125969) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409471,0.00319667) , 
0, 51351.9, 1, 0, 0.488378,0.000513304) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.626888,-0.011919) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.640265,0.0008575) , 
3, 0.619915, 1, 0, 0.635965,-0.00403989) , 
0, 135690, 1, 0, 0.500802,0.000130011)    );
  // itree = 938
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.251378,-0.00100285) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.658016,0.00213889) , 
4, 0.0860219, 1, 0, 0.508003,0.000884092) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357603,0.00398283) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524654,-0.0063093) , 
0, 80354.6, 1, 0, 0.466908,-0.00185688) , 
1, 10.8571, 1, 0, 0.500065,0.000354645)    );
  // itree = 939
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307514,-0.00103697) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.745967,0.00723139) , 
7, -0.928794, 1, 0, 0.410315,0.00108702) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.848224,-0.00371739) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360156,-0.000504218) , 
3, -0.427943, 1, 0, 0.551959,-0.00155762) , 
7, -0.475313, 1, 0, 0.49812,-0.000552395)    );
  // itree = 940
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0539738,0.0148279) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.231805,-0.0051927) , 
8, -0.0669201, 1, 0, 0.185514,-0.00134175) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.645,0.00281216) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.185071,-0.00723876) , 
8, 0.0695119, 1, 0, 0.585873,0.00153828) , 
7, -1.42895, 1, 0, 0.498045,0.000906478)    );
  // itree = 941
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.487704,-0.00127209) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532416,0.00481385) , 
0, 97553.4, 1, 0, 0.494392,-0.000420816) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527767,0.00820317) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540892,-0.000137422) , 
3, 0.905112, 1, 0, 0.534427,0.0049773) , 
1, 15, 1, 0, 0.496513,-0.000134868)    );
  // itree = 942
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0581484,-0.00367972) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.64402,0.0020149) , 
7, -2.51689, 1, 0, 0.550906,0.00129526) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0222222,-0.000742504) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0266714,-0.0193358) , 
8, -0.0380798, 1, 0, 0.024883,-0.00331384) , 
7, 4.28586, 1, 0, 0.501372,0.000861232)    );
  // itree = 943
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508304,0.00672985) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0133123,-0.00357041) , 
3, 0.619795, 1, 0, 0.237819,0.00215584) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.659263,-0.00148003) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264424,0.00347559) , 
7, 1.42854, 1, 0, 0.579055,-0.00054598) , 
4, 0.0574812, 1, 0, 0.49925,8.58951e-05)    );
  // itree = 944
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.934824,0.0019225) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.659631,0.00467973) , 
6, 2.59333, 1, 0, 0.888855,0.00250768) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.587527,-0.00554277) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320449,-0.000301229) , 
1, 3.61905, 1, 0, 0.339991,-0.000720245) , 
3, -0.713346, 1, 0, 0.501055,0.000226985)    );
  // itree = 945
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.910013,0.00361559) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.936582,-0.0109443) , 
2, 116356, 1, 0, 0.912868,0.00193887) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581632,-0.00365196) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296472,0.000658833) , 
3, 0.224832, 1, 0, 0.370853,-0.00102056) , 
3, -0.808727, 1, 0, 0.501904,-0.000305014)    );
  // itree = 946
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41318,-0.00434709) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664389,0.00239238) , 
8, -0.0265474, 1, 0, 0.602539,0.000596913) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.101082,-0.00014921) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.856223,-0.0148753) , 
5, 2.89511, 1, 0, 0.298292,-0.00372288) , 
6, 2.84147, 1, 0, 0.499299,-0.000868915)    );
  // itree = 947
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.866534,-0.00106388) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530813,-0.00674031) , 
3, -0.600222, 1, 0, 0.813284,-0.00243974) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419243,0.00835033) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.297497,0.000127372) , 
3, 0.11607, 1, 0, 0.305517,0.00076979) , 
3, -0.237529, 1, 0, 0.500817,-0.000464681)    );
  // itree = 948
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.239432,-0.00429355) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57836,0.00119064) , 
4, 0.0572996, 1, 0, 0.498093,0.000217095) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561828,-0.00920606) , 
1, 16.2857, 1, 0, 0.499755,-2.44969e-05)    );
  // itree = 949
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336732,-0.00299932) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0653304,0.00711081) , 
6, 6.02601, 1, 0, 0.31094,-0.00206572) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.903022,0.00617164) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.97637,-0.000772515) , 
4, 0.38789, 1, 0, 0.946691,0.00187167) , 
4, 0.257353, 1, 0, 0.497156,-0.000912429)    );
  // itree = 950
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965334,0.00426327) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.911079,-0.0136919) , 
3, -0.939994, 1, 0, 0.939871,-0.0038324) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599975,0.00155667) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292581,-0.000916617) , 
3, 0.728041, 1, 0, 0.432642,0.000548203) , 
3, -0.903718, 1, 0, 0.499025,-2.51073e-05)    );
  // itree = 951
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.799003,0.000631989) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616605,0.0108052) , 
7, 1.39024, 1, 0, 0.777136,0.00206659) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248027,0.00601221) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298277,-0.00317526) , 
1, 4.85714, 1, 0, 0.293053,-0.0010617) , 
3, 0.143327, 1, 0, 0.500912,0.000281547)    );
  // itree = 952
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.665009,-0.00155328) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0877557,0.022415) , 
8, 0.126493, 1, 0, 0.623588,-0.000486778) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629025,0.00474589) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335572,0.00137421) , 
3, -0.233523, 1, 0, 0.396839,0.00219106) , 
1, 6.42857, 1, 0, 0.503944,0.000926181)    );
  // itree = 953
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.97048,-0.00310061) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.752546,-0.00797627) , 
1, 4.85714, 1, 0, 0.903323,-0.00466522) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629807,0.00262068) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.297028,-0.000601564) , 
3, -0.033447, 1, 0, 0.371703,0.000551482) , 
3, -0.808532, 1, 0, 0.4987,-0.000694724)    );
  // itree = 954
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305668,0.00806721) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.686168,-0.00280625) , 
8, -0.0703523, 1, 0, 0.655931,-0.00195651) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393907,0.00340108) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0276583,-0.0131375) , 
7, 2.38112, 1, 0, 0.299986,0.000667096) , 
3, 0.809607, 1, 0, 0.498416,-0.000795496)    );
  // itree = 955
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.182856,-0.00241504) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57885,0.00183389) , 
7, -1.42818, 1, 0, 0.492493,0.000915783) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.722596,0.0114793) , 
0, 191035, 1, 0, 0.500005,0.00112123)    );
  // itree = 956
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.275653,0.000309469) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806968,0.00644202) , 
4, 0.209611, 1, 0, 0.358936,0.00133946) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.973654,-0.00364762) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.888563,-0.0114319) , 
6, 4.39781, 1, 0, 0.96374,-0.00222741) , 
4, 0.31434, 1, 0, 0.500605,0.000503955)    );
  // itree = 957
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309432,0.000899701) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.212385,-0.00332424) , 
7, 0.476513, 1, 0, 0.268697,-0.000528326) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.698366,0.00685077) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.928943,0.0023318) , 
7, -1.42953, 1, 0, 0.903565,0.00217038) , 
4, 0.200109, 1, 0, 0.502302,0.000464686)    );
  // itree = 958
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.731546,-0.00408436) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0738365,0.000310688) , 
3, -0.42756, 1, 0, 0.265699,-0.00137931) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.923048,0.000942645) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76161,0.00746031) , 
6, 4.16045, 1, 0, 0.901831,0.00172788) , 
4, 0.200211, 1, 0, 0.500155,-0.00023411)    );
  // itree = 959
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.781216,0.00655725) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22822,-0.00129561) , 
3, -0.142334, 1, 0, 0.4143,0.00184327) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.767623,-0.00503382) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497519,0.00106103) , 
7, 0.0231272, 1, 0, 0.549838,-0.000264876) , 
7, -0.475825, 1, 0, 0.498412,0.000535001)    );
  // itree = 960
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.886827,0.00402597) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293292,0.000722345) , 
3, -0.618307, 1, 0, 0.510473,0.00153643) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167965,0.00141618) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.897623,-0.0119658) , 
4, 0.2288, 1, 0, 0.474204,-0.00240246) , 
1, 10.7143, 1, 0, 0.503511,0.000780307)    );
  // itree = 961
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307107,0.00467785) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0773364,-0.00665556) , 
0, 64811.2, 1, 0, 0.220944,0.000629464) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.317114,-0.00768355) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.787083,-0.0011026) , 
8, -0.0641057, 1, 0, 0.735608,-0.00161107) , 
4, 0.114696, 1, 0, 0.499925,-0.000585048)    );
  // itree = 962
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.625326,-0.0028238) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283133,0.0014899) , 
3, 0.904824, 1, 0, 0.495707,-0.00138402) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2478,0.0105566) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.911009,-0.00874596) , 
4, 0.257767, 1, 0, 0.537926,0.00488567) , 
1, 13.3333, 1, 0, 0.498846,-0.000917878)    );
  // itree = 963
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565065,-0.00306584) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549034,0.00142432) , 
0, 71380.3, 1, 0, 0.560023,-0.00148161) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.091372,0.0222617) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.016518,-0.0055508) , 
3, 0.905319, 1, 0, 0.0388875,0.0031108) , 
7, 3.33353, 1, 0, 0.498329,-0.000937941)    );
  // itree = 964
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.451172,0.00232215) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0689704,-0.00436935) , 
3, 0.904829, 1, 0, 0.289727,0.00059308) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.926533,-0.00689843) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918004,0.00337974) , 
3, 0.714465, 1, 0, 0.923252,-0.00233877) , 
4, 0.228659, 1, 0, 0.498627,-0.000373676)    );
  // itree = 965
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306479,-0.00717332) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47584,0.000768092) , 
8, -0.0167926, 1, 0, 0.41427,-0.00138159) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76412,0.0021982) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.301798,-0.00159575) , 
7, 1.02051, 1, 0, 0.553609,0.000623605) , 
7, -0.475743, 1, 0, 0.500632,-0.000138775)    );
  // itree = 966
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521904,0.0128609) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0881808,0.00209107) , 
3, 0.42966, 1, 0, 0.198499,0.00422815) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.60122,0.000628269) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.216573,-0.0124362) , 
6, 7.549, 1, 0, 0.586308,6.58877e-05) , 
7, -1.42623, 1, 0, 0.501958,0.000971198)    );
  // itree = 967
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.624123,-0.000550473) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0635116,-0.0155753) , 
8, 0.126626, 1, 0, 0.582856,-0.00093698) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.684562,0.00747152) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.103873,-9.35256e-05) , 
3, -0.236664, 1, 0, 0.207231,0.00157622) , 
7, 1.42925, 1, 0, 0.497493,-0.000365839)    );
  // itree = 968
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4935,0.00157132) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484361,0.00783578) , 
0, 91254.3, 1, 0, 0.492005,0.001904) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38349,-0.0147653) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.982643,0.0165638) , 
4, 0.286326, 1, 0, 0.675577,-0.00619786) , 
0, 164141, 1, 0, 0.501574,0.00148168)    );
  // itree = 969
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.988911,0.020688) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313554,-0.00218196) , 
1, 1.80952, 1, 0, 0.374094,-0.00158492) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.985526,-0.0306903) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.970475,0.00996569) , 
1, 2.14286, 1, 0, 0.972665,0.00258358) , 
4, 0.342905, 1, 0, 0.49868,-0.000717296)    );
  // itree = 970
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.932958,0.00280213) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35327,-0.00202724) , 
3, -0.808727, 1, 0, 0.537057,-0.000541662) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0345194,-0.0198263) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481744,0.00384433) , 
8, -0.122083, 1, 0, 0.431604,0.00232852) , 
1, 8.57143, 1, 0, 0.501525,0.000425439)    );
  // itree = 971
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281816,-0.000937428) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.783209,-0.00714981) , 
4, 0.217859, 1, 0, 0.334577,-0.00158194) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965882,0.0108364) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.952936,-0.00171061) , 
3, -0.427943, 1, 0, 0.958781,0.00204229) , 
4, 0.285843, 1, 0, 0.500204,-0.000620284)    );
  // itree = 972
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.744159,-0.00494634) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.946427,0.00229337) , 
4, 0.171753, 1, 0, 0.853386,-0.00208836) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540719,0.00806597) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305462,0.000410776) , 
3, -0.305501, 1, 0, 0.317878,0.00087743) , 
3, -0.523139, 1, 0, 0.500765,-0.000135448)    );
  // itree = 973
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.820298,0.00119321) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2607,-0.0018657) , 
3, -0.237417, 1, 0, 0.486313,-0.000241209) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.406648,0.00714378) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.991711,-0.0125189) , 
5, 9.95852, 1, 0, 0.641871,0.00366194) , 
0, 135690, 1, 0, 0.499352,8.59355e-05)    );
  // itree = 974
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480136,-0.00475655) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62378,0.000671056) , 
7, -0.475845, 1, 0, 0.570431,-0.000964632) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488406,0.00244743) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0468223,-0.00635058) , 
7, 2.38219, 1, 0, 0.408965,0.00141405) , 
1, 7.2381, 1, 0, 0.501038,5.76536e-05)    );
  // itree = 975
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.926003,0.00255283) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584587,-0.00296576) , 
3, -0.854061, 1, 0, 0.723498,-0.00143709) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.211065,0.0107836) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.300975,-0.000462228) , 
1, 5, 1, 0, 0.292719,0.000450888) , 
3, 0.524019, 1, 0, 0.499586,-0.000455751)    );
  // itree = 976
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501727,-0.000590741) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437297,-0.00986541) , 
1, 11.4286, 1, 0, 0.498866,-0.000774614) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.59719,0.00965787) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481517,-0.000246983) , 
3, 0.43247, 1, 0, 0.515019,0.00403854) , 
1, 12.6667, 1, 0, 0.500528,-0.000279392)    );
  // itree = 977
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334972,0.00850673) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.677917,0.000776161) , 
7, -1.42851, 1, 0, 0.62452,0.0017643) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2649,-0.00783554) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355408,0.00943087) , 
3, 0.995467, 1, 0, 0.306581,-0.000625002) , 
3, 0.904803, 1, 0, 0.500551,0.000832682)    );
  // itree = 978
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.933438,0.0034634) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.755372,-0.00385648) , 
1, 8.09524, 1, 0, 0.912479,0.00122898) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.43127,-0.0030429) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305789,0.000902206) , 
3, 0.913873, 1, 0, 0.36786,-0.00143854) , 
3, -0.808696, 1, 0, 0.497021,-0.000805919)    );
  // itree = 979
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54369,0.00436234) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.970067,-0.00737423) , 
4, 0.343021, 1, 0, 0.624638,0.00239955) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.446416,0.000339475) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0518149,-0.0153084) , 
8, 0.0983845, 1, 0, 0.391242,-0.00048018) , 
1, 6.85714, 1, 0, 0.500915,0.000873009)    );
  // itree = 980
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.84292,-0.00174876) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316184,0.000837507) , 
3, -0.427788, 1, 0, 0.507502,-0.000240138) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.190545,-0.0139065) , 
6, 9.01251, 1, 0, 0.498726,-0.000524356)    );
  // itree = 981
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.948412,0.004858) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.425133,-0.00156454) , 
3, -0.903924, 1, 0, 0.497915,-0.000679608) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440115,0.00699598) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.642499,-0.00163834) , 
0, 135706, 1, 0, 0.518833,0.00362497) , 
1, 12.8571, 1, 0, 0.50007,-0.000236009)    );
  // itree = 982
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.317819,0.00671304) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0693171,-0.00316073) , 
0, 64810.3, 1, 0, 0.217101,0.00208054) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344747,-0.00303795) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.909898,0.00239298) , 
4, 0.208374, 1, 0, 0.658314,-0.000692802) , 
4, 0.0859891, 1, 0, 0.49863,0.000310927)    );
  // itree = 983
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.699611,0.0124338) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69341,-0.00476203) , 
4, 0.0290202, 1, 0, 0.693964,-0.00234863) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62899,0.00390305) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312588,-0.00319396) , 
3, -0.233523, 1, 0, 0.380838,-0.00016942) , 
1, 5.42857, 1, 0, 0.498158,-0.000985912)    );
  // itree = 984
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.220281,-0.000691078) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.741858,0.00337499) , 
4, 0.114425, 1, 0, 0.498204,0.00130413) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565033,-0.00739258) , 
1, 16.2857, 1, 0, 0.49994,0.00107544)    );
  // itree = 985
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.960094,-0.00130343) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.735032,-0.00669797) , 
6, 1.99769, 1, 0, 0.907092,-0.00304457) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.106337,0.00289974) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.820335,-0.00117064) , 
4, 0.17155, 1, 0, 0.373685,0.000937137) , 
3, -0.808696, 1, 0, 0.501427,-1.64154e-05)    );
  // itree = 986
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.791091,0.000679212) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363769,-0.00234596) , 
1, 4.66667, 1, 0, 0.494501,-0.00114546) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222181,0.00698774) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893986,-6.07087e-05) , 
4, 0.229842, 1, 0, 0.55049,0.00430844) , 
1, 14.4762, 1, 0, 0.497474,-0.000855877)    );
  // itree = 987
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.866512,-0.00198046) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488184,-0.00509233) , 
6, 2.71834, 1, 0, 0.791807,-0.00302342) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353082,-0.00254007) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.263674,0.00395305) , 
6, 2.10484, 1, 0, 0.297559,0.000681431) , 
3, -0.0471582, 1, 0, 0.498547,-0.000825162)    );
  // itree = 988
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.791479,-0.00310252) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367182,0.000203027) , 
1, 4.66667, 1, 0, 0.497673,-0.000518848) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540898,0.0113598) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562152,0.00166831) , 
3, 0.905662, 1, 0, 0.551937,0.00763509) , 
1, 15, 1, 0, 0.500496,-9.46667e-05)    );
  // itree = 989
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9443,-0.00227003) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.646986,-0.0044104) , 
1, 4.28571, 1, 0, 0.822431,-0.00357378) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0484533,-0.00670308) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.370154,0.00323492) , 
8, -0.0857566, 1, 0, 0.310206,0.00148889) , 
3, -0.332747, 1, 0, 0.500984,-0.000396704)    );
  // itree = 990
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577004,0.00202873) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0364936,-0.00430373) , 
3, 0.239911, 1, 0, 0.227827,-0.000320384) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.974129,0.0133953) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.769213,-0.00473293) , 
1, 2.14286, 1, 0, 0.805779,-0.00299388) , 
4, 0.143097, 1, 0, 0.497492,-0.0015678)    );
  // itree = 991
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.818678,-0.00804225) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.942872,0.00508648) , 
4, 0.143194, 1, 0, 0.883476,-0.00169128) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363511,0.00249681) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.427039,-0.00097719) , 
1, 8.85714, 1, 0, 0.390716,0.000869173) , 
1, 3.61905, 1, 0, 0.500704,0.000297663)    );
  // itree = 992
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.770935,-0.00362103) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.955298,0.00318617) , 
4, 0.228837, 1, 0, 0.851382,-0.00175484) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.11533,0.00262203) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.930919,-0.00294976) , 
4, 0.257353, 1, 0, 0.319109,0.0010894) , 
3, -0.523113, 1, 0, 0.501206,0.000116357)    );
  // itree = 993
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355551,-0.00843312) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669422,0.000690368) , 
4, 0.0575242, 1, 0, 0.601411,-0.000796068) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.119329,0.00440166) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.892797,-0.00401408) , 
5, 3.25318, 1, 0, 0.305277,0.00178946) , 
6, 2.841, 1, 0, 0.499775,9.13093e-05)    );
  // itree = 994
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.746395,0.000717079) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602076,0.00776303) , 
1, 12.6667, 1, 0, 0.737399,0.00140711) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.278895,-0.0139155) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294867,-0.000330668) , 
3, 0.592182, 1, 0, 0.293999,-0.000850804) , 
3, 0.428927, 1, 0, 0.498928,0.000192755)    );
  // itree = 995
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954834,4.18679e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.89607,-0.0207176) , 
3, -0.926593, 1, 0, 0.937582,-0.00479765) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.168426,0.00197749) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.840939,-0.00241716) , 
4, 0.171639, 1, 0, 0.436004,0.000169413) , 
3, -0.903924, 1, 0, 0.501034,-0.000474573)    );
  // itree = 996
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.633486,0.0010297) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.219933,-0.00357891) , 
6, 2.28278, 1, 0, 0.499344,-0.000514514) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.720855,-0.00682484) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.406755,0.00656081) , 
6, 2.9076, 1, 0, 0.509537,0.00228039) , 
0, 80345.4, 1, 0, 0.50204,0.00022463)    );
  // itree = 997
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.738093,-0.00158144) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.275489,0.000899887) , 
3, 0.42893, 1, 0, 0.495139,-0.000509089) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511207,-0.00387876) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546829,-0.0175465) , 
3, 0.905662, 1, 0, 0.529591,-0.00786638) , 
1, 15, 1, 0, 0.496963,-0.00089857)    );
  // itree = 998
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.87379,0.00135383) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.641056,0.0114329) , 
3, -0.636498, 1, 0, 0.856332,0.00241219) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489454,-0.00591082) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302247,0.000692432) , 
3, -0.232983, 1, 0, 0.315344,-0.000227411) , 
3, -0.523113, 1, 0, 0.499166,0.000669502)    );
  // itree = 999
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512507,0.00321325) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0578242,0.000105382) , 
3, 0.715055, 1, 0, 0.270626,0.00179405) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.887829,-0.00348625) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.953332,0.0100099) , 
0, 122740, 1, 0, 0.898348,-0.00142257) , 
4, 0.200113, 1, 0, 0.502585,0.000605429)    );
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
