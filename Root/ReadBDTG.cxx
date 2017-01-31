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
-1, 0, 1, -99, 0.44047,-0.011906) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.192607,-0.0614786) , 
1, 2.57143, 1, 0, 0.328551,-0.171449) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.771429,0.0542857) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918878,0.0837756) , 
4, 0.161205, 1, 0, 0.893058,0.393058) , 
5, 4801.39, 1, 0, 0.508576,0.00857599)    );
  // itree = 1
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309539,-0.0351243) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.698529,0.0423555) , 
2, 87360, 1, 0, 0.353429,-0.131671) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.959635,0.0848468) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.870555,0.0664255) , 
1, 5.28571, 1, 0, 0.917063,0.377847) , 
5, 5395.91, 1, 0, 0.516414,0.0156655)    );
  // itree = 2
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551622,0.0140965) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.249805,-0.0436973) , 
1, 1.38095, 1, 0, 0.335664,-0.135369) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.837017,0.0536097) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.947721,0.0759393) , 
5, 10360, 1, 0, 0.893197,0.317077) , 
5, 5300.02, 1, 0, 0.498117,-0.00353649)    );
  // itree = 3
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581677,0.0201161) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.174841,-0.0565942) , 
6, 0.811629, 1, 0, 0.337716,-0.128057) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.849145,0.0575856) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.553908,0.00661208) , 
6, 1.68125, 1, 0, 0.741124,0.187307) , 
4, 0.133738, 1, 0, 0.504067,0.00198732)    );
  // itree = 4
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503155,0.00762533) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.198251,-0.0483963) , 
6, 0.926254, 1, 0, 0.314492,-0.132384) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.79694,0.0418224) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954128,0.0691881) , 
5, 9121.79, 1, 0, 0.883092,0.266153) , 
5, 4678.79, 1, 0, 0.498475,-0.00342913)    );
  // itree = 5
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536181,0.0088569) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.160214,-0.0513564) , 
6, 0.839761, 1, 0, 0.31281,-0.129141) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.837129,0.0503903) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544595,0.0038426) , 
6, 1.65807, 1, 0, 0.738237,0.160227) , 
4, 0.114918, 1, 0, 0.498504,-0.00283501)    );
  // itree = 6
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545541,0.0169405) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.24703,-0.0358442) , 
1, 1.38095, 1, 0, 0.337053,-0.0952905) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.95572,0.0639707) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.848629,0.0410621) , 
1, 3.57143, 1, 0, 0.890659,0.220057) , 
5, 5387.48, 1, 0, 0.493847,-0.00597642)    );
  // itree = 7
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.753623,0.0457535) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.212274,-0.0403791) , 
6, 0.562447, 1, 0, 0.333985,-0.0987577) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.912968,0.0583419) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.639386,0.0187258) , 
6, 1.41975, 1, 0, 0.802175,0.184976) , 
4, 0.152602, 1, 0, 0.5148,0.0108204)    );
  // itree = 8
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217412,-0.0360446) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806962,0.0395734) , 
5, 4002.1, 1, 0, 0.293019,-0.124744) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.857924,0.0604348) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.606755,0.00683859) , 
1, 2.42857, 1, 0, 0.696075,0.117811) , 
2, 49322.4, 1, 0, 0.498908,-0.000841997)    );
  // itree = 9
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.789474,0.042987) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230469,-0.033858) , 
6, 0.517723, 1, 0, 0.343107,-0.0842753) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.909506,0.0522435) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58815,0.00963484) , 
6, 1.67271, 1, 0, 0.784994,0.146594) , 
4, 0.171951, 1, 0, 0.501202,-0.00167683)    );
  // itree = 10
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538312,0.0191004) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22163,-0.0332888) , 
1, 1.38095, 1, 0, 0.315668,-0.0796216) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.808642,0.0245274) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.935378,0.0533645) , 
4, 0.240424, 1, 0, 0.882767,0.163357) , 
5, 4815.47, 1, 0, 0.491556,-0.00426098)    );
  // itree = 11
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664228,0.0219463) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.213873,-0.0329149) , 
6, 0.730171, 1, 0, 0.373096,-0.0587844) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696126,0.0226025) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.969005,0.0578732) , 
5, 10740.3, 1, 0, 0.81237,0.145758) , 
4, 0.209808, 1, 0, 0.501627,0.00106432)    );
  // itree = 12
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.607143,0.022667) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343186,-0.0199909) , 
1, 1.38095, 1, 0, 0.416726,-0.033922) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.958333,0.0514013) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.988439,0.0641445) , 
3, 0.047619, 1, 0, 0.965287,0.186708) , 
5, 10254.9, 1, 0, 0.499396,-0.000672151)    );
  // itree = 13
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.412066,0.00270715) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163969,-0.0394611) , 
1, 2.7619, 1, 0, 0.301133,-0.0697335) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.915601,0.0515032) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.809981,0.0239646) , 
1, 3.57143, 1, 0, 0.855263,0.134378) , 
5, 3931.91, 1, 0, 0.503199,0.00469656)    );
  // itree = 14
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447115,0.00486871) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.190419,-0.0358569) , 
1, 2.38095, 1, 0, 0.326087,-0.0613356) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.853865,0.0236054) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.961039,0.0527858) , 
4, 0.293647, 1, 0, 0.899584,0.121431) , 
5, 5382.4, 1, 0, 0.492178,-0.00840431)    );
  // itree = 15
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.234283,-0.0242022) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.819599,0.0286616) , 
5, 3994.91, 1, 0, 0.326984,-0.0713559) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.878378,0.0517882) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.654935,0.00634655) , 
1, 2.33333, 1, 0, 0.73036,0.085338) , 
2, 58265.6, 1, 0, 0.492512,-0.00705537)    );
  // itree = 16
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542105,0.00951907) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.159843,-0.0345259) , 
6, 0.919277, 1, 0, 0.335755,-0.0564055) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.913284,0.0445519) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.593796,0.00572475) , 
6, 1.65807, 1, 0, 0.79046,0.0981643) , 
4, 0.171779, 1, 0, 0.493878,-0.00265403)    );
  // itree = 17
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.734223,0.0284813) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.192292,-0.0297612) , 
6, 0.596242, 1, 0, 0.328063,-0.0608831) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.830671,0.0325732) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46,-0.0195591) , 
6, 3.89583, 1, 0, 0.798251,0.0955078) , 
4, 0.171362, 1, 0, 0.489209,-0.00728391)    );
  // itree = 18
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.734496,0.0357631) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483981,-0.00660309) , 
1, 2.09524, 1, 0, 0.612604,0.059774) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.165257,-0.0356168) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.645991,0.0112101) , 
4, 0.228729, 1, 0, 0.327217,-0.0779278) , 
6, 1.27533, 1, 0, 0.5001,0.00549014)    );
  // itree = 19
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.213747,-0.0286683) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376755,-0.00188006) , 
2, 28183.4, 1, 0, 0.298182,-0.0587358) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.852839,0.0462454) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613993,0.00235364) , 
1, 2.28571, 1, 0, 0.695756,0.0658854) , 
2, 49322.4, 1, 0, 0.498799,0.00414847)    );
  // itree = 20
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.859287,0.0433832) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247285,-0.0210937) , 
6, 0.466386, 1, 0, 0.346282,-0.043695) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.80356,0.0251195) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524476,-0.028885) , 
8, 0.0576723, 1, 0, 0.781038,0.0695236) , 
4, 0.171653, 1, 0, 0.498322,-0.00410089)    );
  // itree = 21
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320346,-0.0119939) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.802895,0.0434203) , 
2, 27291.6, 1, 0, 0.638971,0.0908009) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.33102,-0.0184386) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806522,0.025411) , 
4, 0.266351, 1, 0, 0.446081,-0.0326884) , 
1, 1.47619, 1, 0, 0.4969,-0.000153451)    );
  // itree = 22
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388983,-0.00287898) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.171657,-0.0337688) , 
6, 1.63065, 1, 0, 0.31068,-0.0535283) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.868074,0.042428) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.640187,0.00486879) , 
1, 2.2381, 1, 0, 0.716755,0.0626851) , 
2, 55524, 1, 0, 0.492555,-0.00147801)    );
  // itree = 23
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.378713,-0.0246127) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558736,0.0116835) , 
8, -0.0360207, 1, 0, 0.528807,0.0210924) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.108108,-0.0608916) , 
8, 0.109215, 1, 0, 0.51338,0.0118896)    );
  // itree = 24
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.134921,-0.0657135) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258621,-0.0456712) , 
8, -0.111464, 1, 0, 0.206667,-0.198812) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337019,-0.0100733) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.755717,0.0170344) , 
4, 0.133385, 1, 0, 0.507403,-9.72742e-06) , 
8, -0.0705262, 1, 0, 0.489459,-0.0118714)    );
  // itree = 25
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.821844,0.0351598) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581081,-0.000597277) , 
1, 2.19048, 1, 0, 0.701841,0.0605083) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.237494,-0.0202326) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.786859,0.0251549) , 
4, 0.285608, 1, 0, 0.358072,-0.0386236) , 
6, 0.882351, 1, 0, 0.509073,0.00492012)    );
  // itree = 26
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.108974,-0.062532) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296552,-0.0340309) , 
8, -0.115297, 1, 0, 0.230942,-0.154902) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.648515,0.0236111) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473375,-0.00466582) , 
1, 1.47619, 1, 0, 0.51941,0.0111481) , 
8, -0.0555145, 1, 0, 0.493969,-0.00349664)    );
  // itree = 27
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411307,0.00342362) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.178645,-0.0258575) , 
1, 2.57143, 1, 0, 0.311006,-0.0335551) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.8965,0.0295847) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.74375,-0.0172348) , 
7, 1.315, 1, 0, 0.88024,0.0692617) , 
5, 4665.28, 1, 0, 0.485895,-0.00196601)    );
  // itree = 28
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442635,0.00438932) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.177431,-0.0291464) , 
6, 1.30227, 1, 0, 0.31023,-0.0440854) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.487342,-0.0369899) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.739026,0.0189151) , 
7, -1.57742, 1, 0, 0.721201,0.0496914) , 
2, 55524, 1, 0, 0.496247,-0.00163942)    );
  // itree = 29
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.624309,0.0191098) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384468,-0.0117313) , 
1, 1.28571, 1, 0, 0.453391,-0.0089332) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 1,0.0652487) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.84879,0.0288633) , 
1, 2.33333, 1, 0, 0.889543,0.114681) , 
2, 116531, 1, 0, 0.511596,0.00756333)    );
  // itree = 30
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471311,0.00382196) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.216921,-0.0300134) , 
1, 2.28571, 1, 0, 0.357832,-0.0377957) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.935882,0.0393916) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.631083,0.00406668) , 
6, 1.63404, 1, 0, 0.801796,0.0609081) , 
4, 0.209406, 1, 0, 0.487128,-0.00905012)    );
  // itree = 31
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367615,-0.0207388) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560698,0.0107266) , 
8, -0.0302865, 1, 0, 0.52311,0.0160868) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351759,-0.0360717) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.100671,-0.0610803) , 
8, 0.113271, 1, 0, 0.244253,-0.162031) , 
8, 0.0736867, 1, 0, 0.503867,0.00379549)    );
  // itree = 32
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.398682,-0.00387346) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.950474,0.0372064) , 
5, 7986.81, 1, 0, 0.512742,0.00564273) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.116564,-0.0473669) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572519,-0.0213388) , 
4, 0.151852, 1, 0, 0.247265,-0.136613) , 
8, 0.0598768, 1, 0, 0.488708,-0.00723577)    );
  // itree = 33
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.284615,-0.0344724) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.173913,-0.0637745) , 
0, 40277.2, 1, 0, 0.227612,-0.168975) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53718,0.0071811) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.276347,-0.0341755) , 
7, 1.6075, 1, 0, 0.513433,0.0115414) , 
7, -1.85255, 1, 0, 0.497983,0.00178374)    );
  // itree = 34
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521372,0.00922597) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312185,-0.0221912) , 
1, 2.7619, 1, 0, 0.420413,-0.0189575) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.825436,0.0171152) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.895918,0.0433092) , 
0, 45315.4, 1, 0, 0.864198,0.09053) , 
4, 0.285868, 1, 0, 0.499401,0.000529784)    );
  // itree = 35
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.147887,-0.0546699) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283582,-0.0230586) , 
7, -2.23867, 1, 0, 0.213768,-0.130785) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102941,-0.0605261) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535157,0.00738996) , 
8, -0.105781, 1, 0, 0.522949,0.0186413) , 
7, -1.85788, 1, 0, 0.506187,0.0105404)    );
  // itree = 36
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31087,-0.0298088) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536615,0.0049584) , 
8, -0.0521974, 1, 0, 0.513962,0.00541597) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.139535,-0.0323955) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.218579,-0.0580522) , 
4, 0.0608633, 1, 0, 0.185897,-0.157917) , 
8, 0.0791083, 1, 0, 0.493056,-0.00499251)    );
  // itree = 37
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.845219,0.0317733) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509606,-0.00134332) , 
6, 0.595503, 1, 0, 0.695906,0.0518234) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.279726,-0.0129957) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.807786,0.0277889) , 
4, 0.323957, 1, 0, 0.358676,-0.0244778) , 
6, 0.91049, 1, 0, 0.509453,0.00963677)    );
  // itree = 38
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371635,0.00127945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.12013,-0.0442592) , 
1, 3.2381, 1, 0, 0.314169,-0.0304685) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.749641,0.0148494) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.465517,-0.029793) , 
8, 0.0633427, 1, 0, 0.727795,0.0336273) , 
4, 0.114918, 1, 0, 0.502924,-0.00121891)    );
  // itree = 39
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.200355,-0.0228143) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414621,0.00259475) , 
2, 27731, 1, 0, 0.331849,-0.0247737) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.912568,0.0410571) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.659514,0.00266139) , 
1, 2.33333, 1, 0, 0.746479,0.0442163) , 
2, 58265.6, 1, 0, 0.506733,0.00432505)    );
  // itree = 40
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554315,0.0140983) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243521,-0.0194786) , 
1, 1.33333, 1, 0, 0.338504,-0.0294079) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554192,-0.00669133) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.903073,0.0330181) , 
2, 44596.2, 1, 0, 0.80603,0.0517545) , 
4, 0.171779, 1, 0, 0.503513,-0.000762344)    );
  // itree = 41
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.152216,-0.0371336) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806818,-0.00505276) , 
5, 5309.61, 1, 0, 0.317986,-0.0927201) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537198,0.00361188) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.125,-0.0497297) , 
8, 0.104011, 1, 0, 0.518929,0.00476584) , 
8, -0.0399654, 1, 0, 0.491148,-0.00871192)    );
  // itree = 42
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0993657,-0.041673) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349358,-0.00267453) , 
2, 18674.8, 1, 0, 0.31567,-0.0275101) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965895,0.0409702) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.850746,0.0056118) , 
6, 0.829075, 1, 0, 0.914152,0.0488834) , 
5, 5396.48, 1, 0, 0.494101,-0.00473409)    );
  // itree = 43
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.444169,-0.000509166) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.868545,0.0283189) , 
2, 98644.8, 1, 0, 0.524894,0.0129559) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321534,-0.0180064) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.18797,-0.0546472) , 
8, 0.0175345, 1, 0, 0.283898,-0.0933297) , 
7, 1.57226, 1, 0, 0.501919,0.00282322)    );
  // itree = 44
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423502,0.000238239) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.154465,-0.0273003) , 
1, 3, 1, 0, 0.310601,-0.0346908) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.844816,0.0242397) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549433,-0.00897671) , 
6, 2.00425, 1, 0, 0.756086,0.0340207) , 
4, 0.133574, 1, 0, 0.493022,-0.00655412)    );
  // itree = 45
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27191,-0.0120715) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.798694,0.0343253) , 
2, 24397.8, 1, 0, 0.626833,0.0583525) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488083,0.000114748) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.297017,-0.032763) , 
8, 0.0295046, 1, 0, 0.4479,-0.0207226) , 
1, 1.28571, 1, 0, 0.496421,0.00072046)    );
  // itree = 46
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38588,-0.0108891) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.589678,0.0141625) , 
8, -0.0287123, 1, 0, 0.533723,0.0236543) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311362,-0.0179438) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.957346,0.0339506) , 
5, 10254.9, 1, 0, 0.41129,-0.0412837) , 
8, 0.0207628, 1, 0, 0.50117,0.00638813)    );
  // itree = 47
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.171084,-0.0264389) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345364,-0.00261931) , 
2, 23460.5, 1, 0, 0.286007,-0.0349487) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.759653,0.0200847) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.642374,-0.00428363) , 
1, 3.85714, 1, 0, 0.699615,0.0222822) , 
2, 49322.4, 1, 0, 0.499504,-0.00540727)    );
  // itree = 48
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.576271,0.00827245) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345716,-0.0142092) , 
1, 1.38095, 1, 0, 0.413295,-0.0227026) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.930612,0.0386902) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680556,0.00405315) , 
6, 2.59481, 1, 0, 0.854108,0.0601191) , 
4, 0.304408, 1, 0, 0.476384,-0.0108493)    );
  // itree = 49
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181034,-0.0410712) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538442,0.00593561) , 
8, -0.0841616, 1, 0, 0.518321,0.0112108) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428969,-0.00058912) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26477,-0.0428435) , 
1, 2.19048, 1, 0, 0.33701,-0.067387) , 
8, 0.0369837, 1, 0, 0.488353,-0.00178005)    );
  // itree = 50
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431715,0.00195327) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359869,-0.0302643) , 
1, 4.42857, 1, 0, 0.416155,-0.0157808) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.683908,0.00431357) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.961089,0.0477553) , 
2, 62631.3, 1, 0, 0.849188,0.0633705) , 
4, 0.285349, 1, 0, 0.489403,-0.00239215)    );
  // itree = 51
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.168126,-0.0297334) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.772861,-0.00216113) , 
5, 3525.28, 1, 0, 0.393407,-0.0634184) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53871,0.00682163) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.197183,-0.035938) , 
7, 2.23062, 1, 0, 0.52705,0.0164039) , 
7, -1.00225, 1, 0, 0.503058,0.002074)    );
  // itree = 52
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.589438,0.00996871) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320678,-0.0122295) , 
1, 1.38095, 1, 0, 0.397187,-0.0186508) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.943149,0.022713) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.968586,0.0429144) , 
3, 0.047619, 1, 0, 0.948689,0.0463761) , 
5, 9599.79, 1, 0, 0.493901,-0.0072474)    );
  // itree = 53
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469673,-0.00421118) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.23127,-0.0388698) , 
6, 1.61158, 1, 0, 0.392632,-0.0463013) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546499,0.00855367) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283582,-0.0217695) , 
8, 0.0611929, 1, 0, 0.52443,0.0183874) , 
7, -0.987144, 1, 0, 0.499089,0.00594981)    );
  // itree = 54
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283747,-0.029806) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550987,0.00553393) , 
7, -1.5714, 1, 0, 0.529985,0.00819782) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.284091,-0.0269319) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0408163,-0.0657868) , 
8, 0.124929, 1, 0, 0.19708,-0.107929) , 
8, 0.0671656, 1, 0, 0.502783,-0.00129084)    );
  // itree = 55
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.194062,-0.0236308) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217391,0.0086684) , 
0, 48190.8, 1, 0, 0.198261,-0.057165) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.714377,0.0212875) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511023,-0.00422348) , 
1, 2.2381, 1, 0, 0.593832,0.0195253) , 
2, 27969.4, 1, 0, 0.502412,0.00180149)    );
  // itree = 56
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483892,0.00345513) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.461698,-0.0137665) , 
1, 3.71429, 1, 0, 0.476731,-0.00524733) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477707,0.00474657) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.971014,0.0546481) , 
2, 98644.8, 1, 0, 0.758242,0.0811496) , 
3, 0.047619, 1, 0, 0.497837,0.00123022)    );
  // itree = 57
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.823966,0.0250542) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.270341,-0.0112592) , 
6, 0.559593, 1, 0, 0.401153,-0.010674) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468085,-0.00522413) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.885548,0.0270289) , 
2, 27600, 1, 0, 0.835324,0.051472) , 
4, 0.247403, 1, 0, 0.499709,0.00343309)    );
  // itree = 58
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26972,-0.0271657) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52321,0.00422314) , 
7, -1.60988, 1, 0, 0.501923,0.00449865) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339744,-0.0291274) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.10687,-0.0484934) , 
6, 1.1835, 1, 0, 0.233449,-0.109478) , 
7, 1.85568, 1, 0, 0.48641,-0.00208705)    );
  // itree = 59
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0979381,-0.0555659) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344828,-0.0175942) , 
8, -0.0981371, 1, 0, 0.232394,-0.0910271) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.454545,-0.0025179) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.885075,0.0291764) , 
2, 116531, 1, 0, 0.51498,0.00295804) , 
8, -0.0586522, 1, 0, 0.491825,-0.00474299)    );
  // itree = 60
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25747,-0.00731389) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.81415,0.0153672) , 
5, 3809.57, 1, 0, 0.395294,-0.00824863) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.90932,0.0382016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.781293,0.0102968) , 
1, 3.57143, 1, 0, 0.826512,0.048814) , 
2, 87360, 1, 0, 0.493231,0.00471125)    );
  // itree = 61
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.743166,0.0191098) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248447,-0.00555932) , 
6, 0.92585, 1, 0, 0.492931,0.0185136) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.220044,-0.0296397) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.789581,0.0104813) , 
4, 0.209269, 1, 0, 0.513969,-0.0288254) , 
1, 4, 1, 0, 0.500787,0.000836015)    );
  // itree = 62
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579404,0.0119821) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.182362,-0.017383) , 
6, 1.73445, 1, 0, 0.493359,0.0177969) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.171038,-0.0293062) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.767241,0.00486926) , 
4, 0.190656, 1, 0, 0.495055,-0.0312221) , 
1, 4, 1, 0, 0.49401,-0.00100612)    );
  // itree = 63
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.941567,0.0461183) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484169,-2.79817e-05) , 
6, 0.444522, 1, 0, 0.580808,0.0205529) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.236364,-0.0231539) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.626263,0.013339) , 
3, 0.047619, 1, 0, 0.316116,-0.0464229) , 
6, 1.61158, 1, 0, 0.504187,0.00116516)    );
  // itree = 64
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.683453,0.0587817) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.615929,0.00689384) , 
4, 0.0192334, 1, 0, 0.623325,0.0401998) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403594,-0.00821993) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.716418,0.0186985) , 
3, 0.047619, 1, 0, 0.43772,-0.0156775) , 
1, 1.33333, 1, 0, 0.485264,-0.00136419)    );
  // itree = 65
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.147059,-0.0181388) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346154,-0.0484878) , 
4, 0.0814415, 1, 0, 0.242331,-0.0936667) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.704259,0.0119038) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371429,-0.00423874) , 
6, 0.890231, 1, 0, 0.516928,0.00720728) , 
8, -0.0705262, 1, 0, 0.499208,0.00069799)    );
  // itree = 66
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0855856,-0.0439607) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403974,-0.0115508) , 
4, 0.0956044, 1, 0, 0.214477,-0.0741) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497175,0.0297286) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527205,0.000348789) , 
4, 0.0194238, 1, 0, 0.524903,0.00819666) , 
8, -0.0645875, 1, 0, 0.501703,0.00204627)    );
  // itree = 67
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327869,0.00170026) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.830281,0.0237401) , 
2, 29027.9, 1, 0, 0.642693,0.0421342) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.215299,-0.0119225) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.710938,0.0103029) , 
4, 0.115351, 1, 0, 0.442001,-0.00611429) , 
1, 1.33333, 1, 0, 0.495046,0.00663815)    );
  // itree = 68
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.627119,0.00627515) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.191646,-0.0369776) , 
6, 0.836448, 1, 0, 0.351477,-0.0547192) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315892,-0.000570384) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.737321,0.0150019) , 
2, 49322.4, 1, 0, 0.539292,0.0196346) , 
7, -1.28741, 1, 0, 0.515115,0.0100632)    );
  // itree = 69
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433642,-0.000716992) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44,-0.0215579) , 
1, 4.14286, 1, 0, 0.435102,-0.0156931) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.767857,-0.00619941) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.888372,0.0355685) , 
1, 4.57143, 1, 0, 0.854515,0.0535049) , 
4, 0.323848, 1, 0, 0.48576,-0.00733509)    );
  // itree = 70
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359699,-0.0204794) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.836364,0.0114301) , 
2, 110989, 1, 0, 0.423798,-0.046436) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550816,0.00643026) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350719,-0.0149821) , 
7, 1.40227, 1, 0, 0.519539,0.00844268) , 
7, -0.716935, 1, 0, 0.494983,-0.00563261)    );
  // itree = 71
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0810811,-0.0552145) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351752,-0.00342158) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.80216,0.0128297) , 
4, 0.171629, 1, 0, 0.512586,0.00395835) , 
8, -0.101764, 1, 0, 0.5,9.85869e-05)    );
  // itree = 72
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.781179,0.0187748) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.378914,-0.00299342) , 
6, 0.735517, 1, 0, 0.523907,0.0116383) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.186567,-0.0513428) , 
6, 4.67225, 1, 0, 0.514916,0.00689093)    );
  // itree = 73
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.598109,-0.00153246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233232,-0.0311461) , 
6, 0.900304, 1, 0, 0.376274,-0.0500905) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.282738,-0.0255047) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54319,0.0021532) , 
7, -1.55853, 1, 0, 0.521898,-0.000330047) , 
8, -0.0264, 1, 0, 0.491617,-0.0106772)    );
  // itree = 74
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.164815,-0.0171097) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572622,0.00937239) , 
2, 20686.3, 1, 0, 0.500491,0.0136585) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305495,-0.0228801) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.93692,0.0219501) , 
5, 9619.99, 1, 0, 0.484244,-0.0388523) , 
1, 3.71429, 1, 0, 0.494251,-0.00651106)    );
  // itree = 75
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.398356,-0.00160785) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.412752,-0.0324664) , 
1, 7.14286, 1, 0, 0.399477,-0.0121107) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.872165,0.0241174) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.573248,-0.00579543) , 
6, 3.27493, 1, 0, 0.830523,0.0400845) , 
4, 0.247838, 1, 0, 0.497577,-0.000231836)    );
  // itree = 76
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0703125,-0.0562236) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292208,-0.0228074) , 
8, -0.111464, 1, 0, 0.191489,-0.0818326) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486593,-0.000118352) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.829971,0.0384132) , 
3, 0.047619, 1, 0, 0.512091,0.00642742) , 
8, -0.0705262, 1, 0, 0.493845,0.00140435)    );
  // itree = 77
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.661395,0.00806134) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.576355,0.0379695) , 
0, 49142.1, 1, 0, 0.647887,0.0394596) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485913,0.00197439) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.194521,-0.0341188) , 
8, 0.0593689, 1, 0, 0.457983,-0.00263137) , 
1, 1.38095, 1, 0, 0.505702,0.00794516)    );
  // itree = 78
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.654867,0.00776368) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580645,0.0408411) , 
0, 55791.4, 1, 0, 0.645914,0.0366202) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345352,-0.00568675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.952593,0.0265867) , 
5, 10245.9, 1, 0, 0.456193,-0.00676365) , 
1, 1.38095, 1, 0, 0.505117,0.00442405)    );
  // itree = 79
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545008,0.0058207) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381166,-0.0100462) , 
8, 0.0332725, 1, 0, 0.514292,0.00775718) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.164634,-0.0372599) , 
7, 2.1399, 1, 0, 0.502641,0.00450894)    );
  // itree = 80
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286214,-0.00297161) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.786088,0.0196191) , 
5, 2474.05, 1, 0, 0.470734,0.0114229) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496804,-0.0185121) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.763636,0.0191602) , 
3, 0.047619, 1, 0, 0.566216,-0.0248705) , 
1, 4.42857, 1, 0, 0.498432,0.000894831)    );
  // itree = 81
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.165468,-0.040736) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393103,-0.014619) , 
7, -2.17896, 1, 0, 0.319347,-0.058257) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423174,0.0192403) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534064,0.00143868) , 
4, 0.0199047, 1, 0, 0.524483,0.00853272) , 
7, -1.56758, 1, 0, 0.506967,0.00282954)    );
  // itree = 82
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.370607,0.0239305) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420901,-0.00569475) , 
4, 0.01941, 1, 0, 0.41709,-0.00956153) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.887943,0.0315026) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.818182,0.00112342) , 
1, 12.9048, 1, 0, 0.873318,0.0534627) , 
2, 98644.8, 1, 0, 0.498109,0.00163051)    );
  // itree = 83
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545455,0.00230281) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.200736,-0.0181791) , 
1, 1.80952, 1, 0, 0.311586,-0.0317117) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424242,-0.0287825) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.755707,0.0100832) , 
8, -0.0627184, 1, 0, 0.731115,0.0167996) , 
4, 0.114384, 1, 0, 0.497117,-0.0102583)    );
  // itree = 84
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.93931,0.0417702) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445514,-0.00263293) , 
6, 0.439934, 1, 0, 0.536239,0.00821911) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.130354,-0.0292432) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517921,-0.00660584) , 
0, 60828, 1, 0, 0.327854,-0.0488837) , 
6, 1.98589, 1, 0, 0.490974,-0.00418469)    );
  // itree = 85
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262755,-0.0211751) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.921053,0.0181688) , 
5, 9040.14, 1, 0, 0.369658,-0.042295) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580061,0.00809306) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.317808,-0.0149402) , 
8, 0.0425102, 1, 0, 0.53208,0.0114828) , 
8, -0.030918, 1, 0, 0.501218,0.00126439)    );
  // itree = 86
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989583,0.0629639) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479218,-0.00014993) , 
6, 0.291473, 1, 0, 0.509923,0.00506512) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25974,-0.0377652) , 
6, 4.52007, 1, 0, 0.502125,0.00130485)    );
  // itree = 87
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.681844,0.00510673) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.287448,-0.00930705) , 
6, 0.850214, 1, 0, 0.443962,-0.0101748) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.777778,0.0367617) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.924644,0.0159054) , 
5, 5602.38, 1, 0, 0.888208,0.0457365) , 
2, 116531, 1, 0, 0.501692,-0.00290909)    );
  // itree = 88
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407028,0.0104833) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.282429,-0.0127217) , 
4, 0.0275979, 1, 0, 0.312216,-0.0191905) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.840404,0.0177878) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546651,-0.00333751) , 
6, 1.61087, 1, 0, 0.734597,0.0190413) , 
4, 0.114577, 1, 0, 0.501545,-0.0020534)    );
  // itree = 89
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.284615,0.0504903) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484211,0.0119616) , 
2, 32749.2, 1, 0, 0.421687,0.0645297) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0869565,-0.0443724) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513016,-0.00119251) , 
8, -0.101873, 1, 0, 0.498159,-0.00607942) , 
4, 0.01941, 1, 0, 0.491852,-0.000256136)    );
  // itree = 90
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.937413,0.0364979) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.43897,-0.000353686) , 
6, 0.440037, 1, 0, 0.514292,0.00841995) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.197183,-0.0101415) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330709,-0.0473767) , 
1, 8.28571, 1, 0, 0.260223,-0.08226) , 
6, 3.89583, 1, 0, 0.500696,0.00356757)    );
  // itree = 91
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359865,-0.00164269) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.172316,-0.0276387) , 
7, 1.56893, 1, 0, 0.339861,-0.0117982) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827957,0.019571) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433121,-0.0158327) , 
6, 3.92106, 1, 0, 0.79229,0.0333824) , 
4, 0.171661, 1, 0, 0.495353,0.00372958)    );
  // itree = 92
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53451,0.0101812) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346218,-0.00957876) , 
8, 0.0314091, 1, 0, 0.498218,0.0181773) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357921,-0.0138982) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.839763,0.0136283) , 
4, 0.285793, 1, 0, 0.531869,-0.0123669) , 
1, 4, 1, 0, 0.5109,0.00666617)    );
  // itree = 93
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484944,-0.00160581) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.427273,0.0294036) , 
0, 60329.8, 1, 0, 0.47897,0.00500732) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423774,-0.0169968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.743961,0.0160241) , 
3, 0.047619, 1, 0, 0.493431,-0.0249896) , 
1, 3.85714, 1, 0, 0.484378,-0.00620985)    );
  // itree = 94
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414345,-0.00977676) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577379,0.0066107) , 
8, -0.0175793, 1, 0, 0.526004,0.00454076) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.159794,-0.00837038) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312775,-0.0378656) , 
4, 0.0598923, 1, 0, 0.24228,-0.0534272) , 
8, 0.0625038, 1, 0, 0.502009,-0.00036171)    );
  // itree = 95
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533239,0.0201817) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570696,0.00478962) , 
4, 0.0382939, 1, 0, 0.559935,0.0278404) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.120167,-0.0222163) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.625908,0.00225564) , 
4, 0.0780704, 1, 0, 0.440399,-0.0157505) , 
1, 2.66667, 1, 0, 0.498422,0.00540874)    );
  // itree = 96
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.164557,-0.0433218) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485291,0.0018117) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.884337,0.0336052) , 
4, 0.342458, 1, 0, 0.519792,0.0103024) , 
7, -2.13742, 1, 0, 0.508471,0.00683514)    );
  // itree = 97
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367829,0.000665101) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.156044,-0.0245311) , 
1, 4.7619, 1, 0, 0.336963,-0.00732997) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.879848,0.0192141) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572165,-0.00370825) , 
6, 1.98961, 1, 0, 0.785451,0.0213125) , 
4, 0.152818, 1, 0, 0.506475,0.00349585)    );
  // itree = 98
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.619772,0.0307934) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.195767,-0.00256308) , 
1, 2.04762, 1, 0, 0.442478,0.0530522) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428161,-0.00496037) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.851598,0.0178069) , 
4, 0.291088, 1, 0, 0.507015,-0.00440588) , 
4, 0.0194817, 1, 0, 0.501358,0.000631175)    );
  // itree = 99
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.15748,-0.0186839) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.635438,0.0124811) , 
2, 18674.8, 1, 0, 0.557783,0.0198582) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361272,-0.0100977) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.846774,0.0165753) , 
4, 0.323898, 1, 0, 0.454899,-0.0137226) , 
1, 2.95238, 1, 0, 0.503966,0.00229264)    );
  // itree = 100
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325709,-0.00179942) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.720339,0.0117951) , 
4, 0.0959152, 1, 0, 0.528416,0.0116025) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.199488,-0.0247907) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586466,0.0012447) , 
2, 53018.9, 1, 0, 0.356164,-0.0351177) , 
7, 1.28331, 1, 0, 0.5048,0.00519696)    );
  // itree = 101
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323646,-0.017846) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550288,4.78023e-05) , 
8, -0.037565, 1, 0, 0.512787,-0.00658113) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.232558,-0.0391779) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.179012,-0.0131674) , 
6, 1.72011, 1, 0, 0.211905,-0.0689726) , 
8, 0.0646443, 1, 0, 0.487487,-0.0118273)    );
  // itree = 102
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.260814,-0.0156519) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.810606,0.0220644) , 
4, 0.303732, 1, 0, 0.339869,-0.0246712) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495601,0.021362) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532385,0.0038054) , 
4, 0.01941, 1, 0, 0.529355,0.0144146) , 
8, -0.0331072, 1, 0, 0.494957,0.00731933)    );
  // itree = 103
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367292,0.00580207) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426671,-0.00671796) , 
4, 0.038518, 1, 0, 0.410855,-0.00947288) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.94859,0.0108095) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.995169,0.052144) , 
3, 0.047619, 1, 0, 0.960494,0.0219496) , 
5, 10254.3, 1, 0, 0.499701,-0.00439361)    );
  // itree = 104
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513661,0.0379981) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40796,0.0130985) , 
8, 0.00111601, 1, 0, 0.458333,0.075979) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547858,4.13618e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351425,-0.0178038) , 
8, 0.0369837, 1, 0, 0.515822,-0.00657083) , 
4, 0.01941, 1, 0, 0.51132,-0.000105578)    );
  // itree = 105
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.417202,-0.00411808) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532895,-0.0303907) , 
1, 7.71429, 1, 0, 0.43609,-0.0211511) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.620065,0.0111689) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372988,-0.00129866) , 
6, 1.38182, 1, 0, 0.5358,0.0175255) , 
7, -0.985406, 1, 0, 0.517672,0.0104941)    );
  // itree = 106
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.34517,-0.0085047) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363697,0.00392229) , 
7, 0.141508, 1, 0, 0.35332,-0.00845476) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.825494,0.0129104) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.655738,-0.00909673) , 
7, 1.28232, 1, 0, 0.806667,0.0200072) , 
4, 0.190385, 1, 0, 0.500888,0.000809843)    );
  // itree = 107
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.73852,0.0163183) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591276,-0.0153332) , 
0, 37194.3, 1, 0, 0.696845,0.0163986) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286066,-0.0115163) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.7,0.0167413) , 
3, 0.047619, 1, 0, 0.341844,-0.0222213) , 
6, 0.907177, 1, 0, 0.496904,-0.00535256)    );
  // itree = 108
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.408955,0.00692527) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.279279,-0.0111885) , 
4, 0.0257174, 1, 0, 0.316488,-0.0152932) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.318841,-0.0226436) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.686765,0.00930978) , 
8, -0.0795992, 1, 0, 0.668468,0.0172891) , 
4, 0.0764078, 1, 0, 0.507632,0.00240074)    );
  // itree = 109
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.121442,-0.0167788) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403868,-0.000953697) , 
2, 32749.2, 1, 0, 0.298009,-0.0168949) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.741359,0.0112397) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.724138,-0.0146286) , 
1, 9.33333, 1, 0, 0.737448,0.0125346) , 
4, 0.114369, 1, 0, 0.489464,-0.00407301)    );
  // itree = 110
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.692477,0.0139552) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230882,-0.00536796) , 
6, 1.12002, 1, 0, 0.495127,0.0143485) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293103,-0.0441523) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527586,-0.00265426) , 
7, -1.54852, 1, 0, 0.50627,-0.01469) , 
1, 4, 1, 0, 0.499313,0.00343984)    );
  // itree = 111
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367477,-0.00935776) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346939,0.0245147) , 
0, 73766.8, 1, 0, 0.366322,-0.0203956) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.699659,-0.0120228) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.838498,0.0125227) , 
8, -0.0211811, 1, 0, 0.808542,0.012568) , 
2, 76994.6, 1, 0, 0.490297,-0.0111544)    );
  // itree = 112
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.623978,0.0213338) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.633909,0.00236618) , 
4, 0.0387655, 1, 0, 0.63109,0.0239045) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.429521,-0.0060402) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.908397,0.0315621) , 
2, 171980, 1, 0, 0.463212,-0.00966178) , 
1, 1.33333, 1, 0, 0.506478,-0.00101096)    );
  // itree = 113
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.416965,-0.00786985) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305136,-0.0328518) , 
7, 0.720468, 1, 0, 0.385274,-0.0353722) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344944,-0.00648273) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588629,0.00764169) , 
4, 0.0388478, 1, 0, 0.532732,0.00954302) , 
8, -0.0230261, 1, 0, 0.498613,-0.000849416)    );
  // itree = 114
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.416176,0.00335505) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.925743,0.0279769) , 
2, 40127, 1, 0, 0.656299,0.0288044) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468596,-0.00110553) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.16129,-0.0320633) , 
7, 2.1399, 1, 0, 0.455402,-0.00550844) , 
1, 1.47619, 1, 0, 0.50817,0.00350428)    );
  // itree = 115
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.478013,0.00285099) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584,0.0403442) , 
0, 99961.5, 1, 0, 0.481071,0.00978153) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591429,-0.0320495) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.787302,0.00819598) , 
3, 0.047619, 1, 0, 0.684211,-0.0341368) , 
1, 8.85714, 1, 0, 0.508105,0.00393689)    );
  // itree = 116
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.427492,-0.00780945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564458,0.00708626) , 
7, -0.677043, 1, 0, 0.525409,0.00699077) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.105691,-0.020974) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339869,-0.0323498) , 
2, 40867.5, 1, 0, 0.235507,-0.0675773) , 
7, 1.85871, 1, 0, 0.509146,0.00280769)    );
  // itree = 117
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.476471,0.0253382) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400327,-0.00390552) , 
4, 0.0121503, 1, 0, 0.403696,-0.00626619) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.847695,0.015631) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.716763,-0.00965021) , 
7, 0.984268, 1, 0, 0.828352,0.021894) , 
4, 0.247738, 1, 0, 0.502892,0.000311816)    );
  // itree = 118
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400971,0.00740861) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54615,-0.00534455) , 
4, 0.0384374, 1, 0, 0.51428,-0.00532482) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0985916,-0.0177432) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305164,-0.0314478) , 
2, 38497.3, 1, 0, 0.222535,-0.0579225) , 
8, 0.071974, 1, 0, 0.493759,-0.00902448)    );
  // itree = 119
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.595474,-0.00317653) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.650083,0.0137692) , 
7, 0.166593, 1, 0, 0.620611,0.0128594) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401678,-0.00854062) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.761039,0.0167624) , 
3, 0.047619, 1, 0, 0.440067,-0.0153664) , 
1, 1.38095, 1, 0, 0.488197,-0.00784179)    );
  // itree = 120
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.672304,0.0149948) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529197,-0.0113534) , 
0, 37195, 1, 0, 0.628961,0.0168176) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.181416,-0.0291636) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356781,-0.00265232) , 
7, -1.56758, 1, 0, 0.338783,-0.0128135) , 
6, 1.12917, 1, 0, 0.498983,0.00354505)    );
  // itree = 121
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.43355,0.00042394) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.220321,-0.0163337) , 
1, 4, 1, 0, 0.377327,-0.00902057) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.726519,-0.00939303) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.855212,0.0169776) , 
8, -0.0169638, 1, 0, 0.821888,0.018173) , 
4, 0.209684, 1, 0, 0.503034,-0.00133112)    );
  // itree = 122
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319213,-0.00508706) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.134146,-0.031364) , 
7, 1.57137, 1, 0, 0.298789,-0.0195007) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.556188,-0.00820724) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.692495,0.00812052) , 
8, -0.0194393, 1, 0, 0.657713,0.00911459) , 
4, 0.0763838, 1, 0, 0.497191,-0.00368306)    );
  // itree = 123
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.377745,-0.00358164) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.417085,-0.0363332) , 
7, -1.20048, 1, 0, 0.386621,-0.0266531) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507788,0.000990112) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.83871,0.0298397) , 
0, 132186, 1, 0, 0.527805,0.0060821) , 
7, -1.00885, 1, 0, 0.50281,0.000286746)    );
  // itree = 124
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.244978,-0.0101691) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.30303,0.0444678) , 
0, 69159.8, 1, 0, 0.24896,-0.0177654) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.683908,0.00941222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572268,-0.0085034) , 
0, 60732.1, 1, 0, 0.653389,0.0100091) , 
2, 38497.3, 1, 0, 0.498908,-0.000600019)    );
  // itree = 125
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.970297,0.0518128) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508845,0.0018137) , 
6, 0.36781, 1, 0, 0.573326,0.0141825) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354942,-0.00408381) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243354,-0.0322369) , 
7, 0.447886, 1, 0, 0.316783,-0.0347471) , 
6, 1.60715, 1, 0, 0.500595,0.000310743)    );
  // itree = 126
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534024,0.0151722) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577658,0.00243327) , 
4, 0.0393013, 1, 0, 0.565106,0.0173862) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.239726,-0.0153914) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.779129,0.000708987) , 
4, 0.228711, 1, 0, 0.445044,-0.0221137) , 
1, 2.7619, 1, 0, 0.502124,-0.00333465)    );
  // itree = 127
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348958,-0.00470236) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.797992,0.00736892) , 
4, 0.152521, 1, 0, 0.530437,-0.00150131) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248915,-0.0226175) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.766667,0.0100875) , 
4, 0.285581, 1, 0, 0.34126,-0.0374709) , 
8, 0.0371595, 1, 0, 0.498807,-0.00751531)    );
  // itree = 128
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471895,0.00330642) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526961,-0.0151718) , 
1, 5.33333, 1, 0, 0.481577,0.000894608) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.786957,0.0380914) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.670157,0.00641548) , 
7, 0.17957, 1, 0, 0.733967,0.0432631) , 
3, 0.047619, 1, 0, 0.502568,0.00441834)    );
  // itree = 129
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.45,0.00145349) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363083,-0.0219517) , 
1, 2.57143, 1, 0, 0.405961,-0.0223075) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502399,0.000505784) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.754808,0.0222498) , 
0, 91297.9, 1, 0, 0.527591,0.00554392) , 
7, -0.996004, 1, 0, 0.504571,0.000272689)    );
  // itree = 130
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.278297,-0.0160613) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346122,0.00536559) , 
7, -0.148698, 1, 0, 0.316271,-0.0108079) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.665,0.0148307) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.687861,-0.00493458) , 
1, 5.90476, 1, 0, 0.673362,0.0173027) , 
4, 0.0764559, 1, 0, 0.517907,0.0050651)    );
  // itree = 131
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.203222,-0.00817475) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588692,0.00598894) , 
2, 25442.1, 1, 0, 0.489117,0.0055724) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518987,-0.00444865) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42471,-0.0260784) , 
6, 3.23243, 1, 0, 0.506257,-0.0176201) , 
1, 3.85714, 1, 0, 0.495637,-0.00325014)    );
  // itree = 132
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.938218,0.0376268) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432365,-0.00199871) , 
6, 0.439347, 1, 0, 0.507466,0.00386997) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283186,-0.0274152) , 
6, 3.89551, 1, 0, 0.497151,0.000358316)    );
  // itree = 133
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.179756,-0.01182) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.594257,0.00641648) , 
2, 27456.5, 1, 0, 0.507321,0.00586163) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516332,-0.004814) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32438,-0.0202945) , 
6, 1.98622, 1, 0, 0.474652,-0.0195583) , 
7, 0.153378, 1, 0, 0.492643,-0.00555966)    );
  // itree = 134
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167488,-0.020419) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557758,0.00432499) , 
8, -0.0909414, 1, 0, 0.537883,0.00811408) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.425121,-0.0207657) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286325,0.00395925) , 
6, 1.38153, 1, 0, 0.365473,-0.0254263) , 
8, 0.0282183, 1, 0, 0.500887,0.000916944)    );
  // itree = 135
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504084,-0.00122372) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303502,-0.0177413) , 
8, 0.0368993, 1, 0, 0.471103,-0.00899564) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.764706,0.0469415) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.812183,0.00853365) , 
1, 11.1429, 1, 0, 0.791429,0.0551601) , 
0, 124449, 1, 0, 0.493352,-0.00453949)    );
  // itree = 136
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488098,0.00189675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.822857,0.0370752) , 
3, 0.047619, 1, 0, 0.511869,0.0092197) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238806,-0.0240281) , 
6, 4.85481, 1, 0, 0.504642,0.00731014)    );
  // itree = 137
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389764,-0.00585581) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55102,-0.0325393) , 
1, 8, 1, 0, 0.415842,-0.0235898) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509209,0.000652413) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.798535,0.0179475) , 
0, 132192, 1, 0, 0.528343,0.00407986) , 
7, -0.996004, 1, 0, 0.50804,-0.000913537)    );
  // itree = 138
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511442,0.00233121) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76,-0.0264953) , 
4, 0.380399, 1, 0, 0.519031,0.00374749) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.048951,-0.0581675) , 
8, 0.125237, 1, 0, 0.505736,0.00118479)    );
  // itree = 139
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.146341,-0.0337617) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.571429,0.002615) , 
4, 0.11432, 1, 0, 0.314496,-0.0449065) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528293,-0.000909965) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27551,-0.0223767) , 
7, 1.69304, 1, 0, 0.506988,-0.00615044) , 
7, -1.56634, 1, 0, 0.491499,-0.009269)    );
  // itree = 140
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.668806,0.0142668) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482653,-0.0133487) , 
0, 37755.7, 1, 0, 0.608117,0.0115059) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.277419,0.0427663) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.331371,-0.011018) , 
4, 0.0194378, 1, 0, 0.326861,-0.0152292) , 
6, 1.27533, 1, 0, 0.500823,0.00130694)    );
  // itree = 141
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489244,-0.00187328) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.773333,0.015663) , 
3, 0.047619, 1, 0, 0.51192,-0.00191576) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41958,0.0521037) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.136364,-0.012925) , 
8, 0.122958, 1, 0, 0.283636,0.0483136) , 
8, 0.0831569, 1, 0, 0.499296,0.000861855)    );
  // itree = 142
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312878,-0.00396281) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.668956,0.0121757) , 
4, 0.0764921, 1, 0, 0.51129,0.010308) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508232,-0.00294591) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.443407,-0.0146138) , 
8, 0.00971271, 1, 0, 0.483585,-0.0174421) , 
7, 0.139479, 1, 0, 0.498459,-0.0025436)    );
  // itree = 143
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.183784,-0.0357889) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53945,0.0050731) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440945,-0.00678663) , 
7, 0.550016, 1, 0, 0.508135,0.00307079) , 
7, -2.14237, 1, 0, 0.496084,0.00034362)    );
  // itree = 144
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545392,0.00225209) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309392,-0.012477) , 
7, 1.57015, 1, 0, 0.52735,0.00279788) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286885,0.0330527) , 
8, 0.0833911, 1, 0, 0.515565,0.00525889)    );
  // itree = 145
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541711,-0.000335584) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392358,-0.0112548) , 
8, 0.0258102, 1, 0, 0.50858,-0.00639047) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.205405,-0.0284038) , 
7, 2.14312, 1, 0, 0.497411,-0.00843714)    );
  // itree = 146
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.331002,-0.00159389) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694344,0.00984119) , 
4, 0.0763737, 1, 0, 0.526304,0.00944918) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.267782,-0.0217676) , 
6, 3.89904, 1, 0, 0.513635,0.00650751)    );
  // itree = 147
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0974026,-0.0249193) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.263566,-0.0302312) , 
2, 43449.9, 1, 0, 0.173145,-0.05144) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496468,0.00286737) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545143,-0.00560035) , 
1, 3.85714, 1, 0, 0.514503,0.000214074) , 
8, -0.0735627, 1, 0, 0.495206,-0.00270604)    );
  // itree = 148
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.652765,0.00229585) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574879,0.0264955) , 
0, 48818, 1, 0, 0.640458,0.0174401) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.192053,-0.0105802) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.627695,0.00289023) , 
4, 0.0765117, 1, 0, 0.444815,-0.00656983) , 
1, 1.47619, 1, 0, 0.497045,-0.000160018)    );
  // itree = 149
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.716043,0.0118242) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293339,0.000556465) , 
6, 0.836448, 1, 0, 0.477723,0.0121839) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575563,-0.0297202) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785965,0.0157309) , 
3, 0.047619, 1, 0, 0.676175,-0.0248737) , 
1, 8.28571, 1, 0, 0.501945,0.00766077)    );
  // itree = 150
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362054,0.00803387) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507454,-0.00634658) , 
4, 0.03845, 1, 0, 0.471426,-0.00558927) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.585492,0.00701665) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.901288,0.0386019) , 
0, 91861.8, 1, 0, 0.758216,0.0423717) , 
3, 0.047619, 1, 0, 0.495556,-0.00155384)    );
  // itree = 151
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.124088,-0.0265302) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409369,0.0129344) , 
8, -0.0405236, 1, 0, 0.374441,0.025045) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575809,0.00154173) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385057,-0.0138568) , 
6, 1.98589, 1, 0, 0.532569,-0.00496669) , 
4, 0.0384762, 1, 0, 0.496873,0.00180818)    );
  // itree = 152
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.942997,0.0314016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401511,-0.00447962) , 
6, 0.411604, 1, 0, 0.47619,-0.0041843) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.604061,-0.0188671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.675127,0.0229143) , 
6, 1.92282, 1, 0, 0.651438,0.0262888) , 
0, 83188.2, 1, 0, 0.496728,-0.000613093)    );
  // itree = 153
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493026,-0.00149504) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.869732,0.0300329) , 
1, 11.1429, 1, 0, 0.513604,-0.000470222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.29386,-0.0265129) , 
6, 3.89583, 1, 0, 0.503596,-0.00323838)    );
  // itree = 154
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.3,0.0305218) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547619,0.00914953) , 
2, 34043.7, 1, 0, 0.471698,0.0442164) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292755,-0.00704908) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.718166,0.00478602) , 
4, 0.109973, 1, 0, 0.504651,-0.00370229) , 
4, 0.0196169, 1, 0, 0.50194,0.000239803)    );
  // itree = 155
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248609,-0.00313186) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597826,-0.0251828) , 
2, 55494.7, 1, 0, 0.390298,-0.0267434) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401747,-0.00853192) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.556363,0.00526138) , 
8, -0.0248877, 1, 0, 0.521675,0.00535242) , 
7, -0.997742, 1, 0, 0.497796,-0.000481435)    );
  // itree = 156
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.415868,-0.00602227) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510791,0.0118044) , 
0, 86730.2, 1, 0, 0.42241,-0.0116446) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.901685,0.0235719) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669355,-0.000166961) , 
6, 2.5431, 1, 0, 0.841667,0.0271268) , 
4, 0.285671, 1, 0, 0.503004,-0.00419154)    );
  // itree = 157
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.435484,0.000989433) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371711,-0.00992336) , 
1, 4.14286, 1, 0, 0.421629,-0.00348629) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.981788,0.0352951) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.906593,0.0030802) , 
1, 11.2857, 1, 0, 0.964377,0.0213626) , 
5, 10245.9, 1, 0, 0.507223,0.000432502)    );
  // itree = 158
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.195745,-0.0142637) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.757018,0.0171478) , 
2, 18808.6, 1, 0, 0.652997,0.0250766) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320829,-0.00379703) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.945869,0.0160666) , 
5, 9340.41, 1, 0, 0.438118,-0.00438519) , 
1, 1.47619, 1, 0, 0.492513,0.00307289)    );
  // itree = 159
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.703209,0.0234645) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629283,0.00392883) , 
4, 0.0387655, 1, 0, 0.649963,0.025046) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457627,0.0078219) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458386,-0.00386742) , 
7, -0.436069, 1, 0, 0.458119,0.000418454) , 
1, 1.47619, 1, 0, 0.509152,0.0069698)    );
  // itree = 160
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.566997,0.00376974) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468787,-0.00871715) , 
1, 2.7619, 1, 0, 0.515095,-0.00517733) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504499,0.0103032) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.196532,-0.00874535) , 
8, 0.0636438, 1, 0, 0.473684,0.0200413) , 
7, 0.424176, 1, 0, 0.500607,0.00364563)    );
  // itree = 161
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202864,-0.00278089) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.611063,0.0108521) , 
2, 25442.1, 1, 0, 0.501915,0.0175422) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516957,-0.0136308) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525907,0.00680578) , 
8, 0.00835403, 1, 0, 0.520666,-0.0103795) , 
1, 4, 1, 0, 0.508905,0.00713236)    );
  // itree = 162
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541998,-0.000442086) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.465091,0.0137495) , 
7, 1.00471, 1, 0, 0.527548,0.00508376) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0859375,-0.0518763) , 
8, 0.119474, 1, 0, 0.516427,0.00284237)    );
  // itree = 163
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381551,-2.54503e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328264,0.0132682) , 
4, 0.0331697, 1, 0, 0.35743,0.0143578) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.597652,-0.00489353) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.272727,-0.0328161) , 
6, 4.0051, 1, 0, 0.57898,-0.0146185) , 
4, 0.0576895, 1, 0, 0.501701,-0.00451127)    );
  // itree = 164
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.300493,-0.0133763) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507994,0.000138888) , 
7, -1.57282, 1, 0, 0.490613,-0.00204826) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.873134,0.0302666) , 
4, 0.38093, 1, 0, 0.500903,-0.000393948)    );
  // itree = 165
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389489,-0.00065977) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238924,-0.0143874) , 
0, 37196.4, 1, 0, 0.317753,-0.0170985) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696552,0.00961943) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.678243,-0.00829565) , 
1, 5.28571, 1, 0, 0.689173,0.0049842) , 
4, 0.0955839, 1, 0, 0.495277,-0.00654384)    );
  // itree = 166
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.257282,-0.0103615) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.487032,0.0120785) , 
4, 0.0383935, 1, 0, 0.434444,0.0140254) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.462462,0.0100874) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511426,-0.00501542) , 
4, 0.019383, 1, 0, 0.507488,-0.00803965) , 
7, -1.01755, 1, 0, 0.494444,-0.00409946)    );
  // itree = 167
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.386697,-0.0029476) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.810519,0.00616069) , 
2, 76994.6, 1, 0, 0.507714,-0.00231265) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0482759,-0.04848) , 
8, 0.109105, 1, 0, 0.494407,-0.00429238)    );
  // itree = 168
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680105,0.0159352) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514484,-0.0161326) , 
0, 37193.5, 1, 0, 0.628561,0.0135107) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264822,-0.0133469) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374577,0.00126215) , 
8, -0.0126392, 1, 0, 0.337355,-0.00769337) , 
6, 1.12917, 1, 0, 0.498503,0.00404058)    );
  // itree = 169
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.34956,-0.00649018) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877637,0.0334682) , 
2, 130647, 1, 0, 0.383877,-0.0111967) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.735714,0.0322631) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.845156,0.0112759) , 
8, -0.0460769, 1, 0, 0.833333,0.0243696) , 
4, 0.228354, 1, 0, 0.50172,-0.00187159)    );
  // itree = 170
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.59001,0.000886977) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.467043,0.0216711) , 
0, 45529.5, 1, 0, 0.563392,0.0142363) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353436,-0.00797132) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.853119,0.0159482) , 
4, 0.323387, 1, 0, 0.447648,-0.00852642) , 
1, 2.66667, 1, 0, 0.503439,0.00244569)    );
  // itree = 171
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357855,-0.000454761) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222222,-0.0182875) , 
0, 66977, 1, 0, 0.343587,-0.00557502) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.667832,-0.00659299) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.816005,0.0105628) , 
8, -0.0297718, 1, 0, 0.791762,0.0138616) , 
4, 0.171653, 1, 0, 0.5003,0.00122139)    );
  // itree = 172
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664794,0.00722929) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38316,-0.00168339) , 
6, 1.1295, 1, 0, 0.542517,0.0074214) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.397849,-0.0135572) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.282209,0.00962072) , 
6, 2.68288, 1, 0, 0.380604,-0.0230896) , 
8, 0.0282183, 1, 0, 0.506163,0.00057084)    );
  // itree = 173
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424354,-0.0150564) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577926,0.00298109) , 
8, -0.0224613, 1, 0, 0.542431,-0.00247188) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388706,0.00411893) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.874016,0.0217959) , 
4, 0.323848, 1, 0, 0.48234,0.0139041) , 
1, 2.47619, 1, 0, 0.510647,0.00618983)    );
  // itree = 174
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464706,-0.0010183) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.673684,-0.0235135) , 
1, 12, 1, 0, 0.476923,-0.0048627) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.70922,0.0261102) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.986014,0.0320642) , 
5, 8786.53, 1, 0, 0.848592,0.049571) , 
4, 0.361392, 1, 0, 0.497383,-0.00186615)    );
  // itree = 175
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.251888,-0.00268083) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480744,-0.0180167) , 
5, 2252.43, 1, 0, 0.309254,-0.0160419) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.742134,-0.000586106) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.759587,0.016812) , 
7, 0.415412, 1, 0, 0.748107,0.0108) , 
4, 0.13331, 1, 0, 0.483651,-0.00537514)    );
  // itree = 176
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485607,0.00165052) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590551,-0.0225735) , 
1, 12.4286, 1, 0, 0.488477,0.00207856) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.824268,0.040009) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72327,-0.00132116) , 
7, 0.21044, 1, 0, 0.78392,0.0362594) , 
3, 0.047619, 1, 0, 0.511803,0.00477723)    );
  // itree = 177
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537112,0.00252204) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.188841,-0.0261488) , 
8, 0.0832328, 1, 0, 0.519769,0.00341007) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.257576,-0.0247502) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.15625,-0.0411124) , 
7, 2.34635, 1, 0, 0.207692,-0.0687914) , 
7, 1.85442, 1, 0, 0.503341,-0.00039078)    );
  // itree = 178
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508766,-0.00104709) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664884,0.0190881) , 
0, 73364.4, 1, 0, 0.53245,0.00391082) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293959,-0.0161715) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.957806,0.0173734) , 
5, 9351.89, 1, 0, 0.410847,-0.028381) , 
8, 0.0221711, 1, 0, 0.5,-0.00470631)    );
  // itree = 179
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376569,0.0285124) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578378,-0.00256704) , 
2, 54583.2, 1, 0, 0.464623,0.0478557) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341872,-0.00245209) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.807714,0.00734036) , 
4, 0.182413, 1, 0, 0.515327,0.00124939) , 
4, 0.0194378, 1, 0, 0.511102,0.00513248)    );
  // itree = 180
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380952,-0.0153372) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332028,0.00750155) , 
4, 0.011493, 1, 0, 0.334691,0.014528) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.695957,-0.00760622) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.782927,0.0149799) , 
3, 0.047619, 1, 0, 0.7117,-0.00888932) , 
4, 0.114557, 1, 0, 0.506645,0.00384733)    );
  // itree = 181
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362199,0.00737284) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.738562,-0.0153941) , 
4, 0.20977, 1, 0, 0.45887,0.00596912) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560878,-0.0119632) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464938,6.034e-05) , 
8, 0.0148942, 1, 0, 0.51,-0.0133529) , 
8, -0.00935821, 1, 0, 0.491678,-0.00642919)    );
  // itree = 182
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313869,-0.00370185) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.125,-0.0400129) , 
6, 1.30145, 1, 0, 0.222642,-0.0377444) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49685,0.00642241) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584311,-0.00414452) , 
1, 4.42857, 1, 0, 0.522248,0.00855548) , 
7, -1.83864, 1, 0, 0.506247,0.00608279)    );
  // itree = 183
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360791,0.0036948) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355789,0.0276264) , 
7, 0.71396, 1, 0, 0.359384,0.0260847) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613901,0.00247894) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319588,-0.0255323) , 
6, 3.89904, 1, 0, 0.596064,0.000914689) , 
4, 0.0573533, 1, 0, 0.514315,0.00960837)    );
  // itree = 184
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521835,0.00668033) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52439,-0.00289563) , 
7, -0.173989, 1, 0, 0.523121,0.0041346) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102041,-0.0323516) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.641509,0.00142739) , 
5, 2512.37, 1, 0, 0.291391,-0.0354919) , 
7, 1.56893, 1, 0, 0.502193,0.000555894)    );
  // itree = 185
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505435,-0.0395191) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.318408,0.0101864) , 
6, 0.906867, 1, 0, 0.407792,-0.0328249) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505157,0.000712082) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.73913,-0.0204383) , 
1, 14.7619, 1, 0, 0.513141,0.000111772) , 
4, 0.01941, 1, 0, 0.505193,-0.00237316)    );
  // itree = 186
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493625,-0.0179173) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.223229,-0.00236099) , 
1, 1.04762, 1, 0, 0.307431,-0.0205868) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588063,0.000798387) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.898438,0.0372043) , 
0, 203647, 1, 0, 0.600501,0.0042344) , 
4, 0.05791, 1, 0, 0.496268,-0.00459349)    );
  // itree = 187
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.478965,-0.00374708) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348348,0.0138995) , 
6, 3.23664, 1, 0, 0.469862,-0.00573578) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.8,0.0361432) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.984848,0.0250675) , 
5, 10464.3, 1, 0, 0.888087,0.054883) , 
4, 0.361902, 1, 0, 0.492779,-0.00241403)    );
  // itree = 188
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.140244,-0.0280111) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495929,0.000171358) , 
2, 16508.4, 1, 0, 0.471368,-0.00403314) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.915663,0.0229146) , 
2, 174797, 1, 0, 0.493499,-0.00219398)    );
  // itree = 189
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485731,0.000225853) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285714,0.0415604) , 
6, 3.10864, 1, 0, 0.476402,0.00511348) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.594355,-0.00690977) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400881,-0.0273945) , 
6, 3.25798, 1, 0, 0.564417,-0.0202349) , 
1, 4.42857, 1, 0, 0.501874,-0.0022225)    );
  // itree = 190
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.186667,-0.0221386) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877863,0.0129647) , 
5, 7824.48, 1, 0, 0.310534,-0.0330484) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332502,-0.00120286) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.904331,0.0152908) , 
5, 4353.25, 1, 0, 0.535722,0.00557595) , 
8, -0.0386484, 1, 0, 0.503344,2.2374e-05)    );
  // itree = 191
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334979,0.00173342) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.212121,0.0503163) , 
6, 3.02062, 1, 0, 0.328649,0.00887616) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411905,-0.0122862) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.814083,-2.6046e-05) , 
2, 43680, 1, 0, 0.676698,-0.0119882) , 
4, 0.0953715, 1, 0, 0.499104,-0.00134203)    );
  // itree = 192
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.59284,-0.000105066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474359,0.0221637) , 
0, 39358.3, 1, 0, 0.557447,0.0182729) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0873016,-0.0465528) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472945,-0.00440922) , 
4, 0.0194678, 1, 0, 0.453867,-0.0134649) , 
1, 2.7619, 1, 0, 0.503574,0.00176559)    );
  // itree = 193
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.225352,0.00733129) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552102,-0.00905746) , 
2, 24099.4, 1, 0, 0.493707,-0.0131099) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565705,0.0120026) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362105,-0.0113173) , 
6, 1.98589, 1, 0, 0.524499,0.0162666) , 
7, 0.138653, 1, 0, 0.5078,0.0003352)    );
  // itree = 194
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437109,0.00361826) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437701,-0.00454035) , 
7, -0.414497, 1, 0, 0.4375,-0.00418797) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484979,-0.0324281) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.959847,0.00778536) , 
5, 6207.77, 1, 0, 0.813492,-0.0282224) , 
4, 0.30461, 1, 0, 0.494396,-0.00782489)    );
  // itree = 195
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341772,-0.00308574) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.682429,0.00908471) , 
4, 0.0763034, 1, 0, 0.534329,0.00709545) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424269,-0.00533051) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507772,-0.0260847) , 
0, 74995, 1, 0, 0.436162,-0.0186965) , 
7, 0.721065, 1, 0, 0.508606,0.000336961)    );
  // itree = 196
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.598832,0.0167942) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439712,-0.00275113) , 
0, 28400.7, 1, 0, 0.4818,0.00622559) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442953,0.0403292) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.874194,0.00850258) , 
5, 5330.72, 1, 0, 0.734205,0.0449467) , 
0, 96457.2, 1, 0, 0.505008,0.00978589)    );
  // itree = 197
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385377,0.00180537) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.223193,-0.0122535) , 
0, 37202.7, 1, 0, 0.305988,-0.0115902) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456311,0.0238305) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.761013,0.000133644) , 
4, 0.138837, 1, 0, 0.708421,0.0102412) , 
4, 0.0953638, 1, 0, 0.499698,-0.00108172)    );
  // itree = 198
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309823,-0.0120096) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294492,0.0088379) , 
0, 65132.4, 1, 0, 0.3078,-0.0247855) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.910037,0.00707785) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.923567,-0.0549396) , 
5, 25879.2, 1, 0, 0.911451,0.00435975) , 
5, 5382.4, 1, 0, 0.486316,-0.0161664)    );
  // itree = 199
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.701784,0.00304231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339869,0.0371355) , 
6, 2.35525, 1, 0, 0.66015,0.0188816) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448235,-0.00243379) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330275,-0.0191114) , 
6, 3.90214, 1, 0, 0.441128,-0.00741341) , 
1, 1.33333, 1, 0, 0.5,-0.00034544)    );
  // itree = 200
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405405,-0.0132391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529984,0.00440542) , 
4, 0.0194007, 1, 0, 0.519952,0.00602562) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22695,-0.0161488) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.630332,0.0124341) , 
3, 0.047619, 1, 0, 0.336774,-0.0213589) , 
6, 2.30377, 1, 0, 0.491039,0.00170321)    );
  // itree = 201
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.553918,0.00307618) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376705,-0.00648295) , 
6, 1.9899, 1, 0, 0.517331,0.00232466) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273684,-0.0354666) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.236735,-0.00516284) , 
7, 1.97649, 1, 0, 0.252874,-0.0376887) , 
7, 1.56654, 1, 0, 0.494556,-0.00112135)    );
  // itree = 202
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2,-0.00920319) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.39185,0.00924415) , 
5, 784.884, 1, 0, 0.338422,0.0120351) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.962687,0.0130759) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.844636,-0.0214904) , 
6, 0.609366, 1, 0, 0.898042,-0.0139413) , 
5, 5395.91, 1, 0, 0.503587,0.00436848)    );
  // itree = 203
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495498,0.00232877) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.798526,-0.018126) , 
4, 0.342881, 1, 0, 0.523496,0.00201451) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222552,0.00209753) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.593846,0.0240194) , 
4, 0.0760383, 1, 0, 0.404834,0.0290229) , 
7, 1.28345, 1, 0, 0.507993,0.00554314)    );
  // itree = 204
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493562,0.0177189) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296825,-2.46546e-05) , 
0, 37225.7, 1, 0, 0.380474,0.0190561) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483542,-0.00527725) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.832103,0.0144017) , 
4, 0.331097, 1, 0, 0.531069,-0.00676676) , 
4, 0.0384374, 1, 0, 0.498521,-0.00118563)    );
  // itree = 205
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497833,0.00614768) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.643861,-0.00354227) , 
1, 5.14286, 1, 0, 0.532244,0.00942944) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.209091,-0.0324257) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37931,0.00957192) , 
1, 4.7619, 1, 0, 0.261053,-0.0357814) , 
8, 0.0598768, 1, 0, 0.506496,0.00513698)    );
  // itree = 206
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42069,0.0136025) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53566,0.00124915) , 
7, -1.0455, 1, 0, 0.514804,0.00747072) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.21466,-0.0312891) , 
7, 2.1399, 1, 0, 0.503309,0.00495775)    );
  // itree = 207
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163793,-0.0275663) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.556818,-0.00154744) , 
4, 0.0931266, 1, 0, 0.333333,-0.0334521) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55576,0.00799962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499027,-0.00391903) , 
7, -0.264802, 1, 0, 0.51866,0.000351403) , 
7, -1.56764, 1, 0, 0.503903,-0.00234021)    );
  // itree = 208
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546518,-0.00742044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455422,0.0123894) , 
0, 50405.3, 1, 0, 0.530647,-0.00872348) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474486,0.0095659) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.342246,-0.0134966) , 
6, 3.89583, 1, 0, 0.465036,0.0153169) , 
1, 2.95238, 1, 0, 0.496299,0.00386177)    );
  // itree = 209
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262626,0.0258664) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511094,-0.0113662) , 
7, -2.08346, 1, 0, 0.493875,-0.0212379) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536478,0.00776981) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335088,-0.0115466) , 
7, 1.36723, 1, 0, 0.483333,0.00632532) , 
7, 0.149387, 1, 0, 0.489336,-0.00937095)    );
  // itree = 210
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202312,0.00603621) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335938,-0.0285238) , 
4, 0.0573774, 1, 0, 0.282051,-0.0348366) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.214689,-0.00634168) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.615429,0.00688943) , 
2, 28488.3, 1, 0, 0.521335,0.00788717) , 
7, -1.56897, 1, 0, 0.500606,0.00418594)    );
  // itree = 211
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.34965,0.0404563) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486275,-0.00450567) , 
2, 33834, 1, 0, 0.437186,0.0362042) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326326,-0.00634791) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.793889,0.00585909) , 
4, 0.182547, 1, 0, 0.493571,-0.00580662) , 
4, 0.0196467, 1, 0, 0.489139,-0.00250482)    );
  // itree = 212
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.189474,-0.026996) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532165,0.00465604) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0458015,-0.0459568) , 
8, 0.125096, 1, 0, 0.518919,0.00884154) , 
7, -2.13668, 1, 0, 0.5064,0.00657636)    );
  // itree = 213
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439592,-0.000192984) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.622727,-0.0225669) , 
1, 8.85714, 1, 0, 0.457256,-0.00488581) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.811765,-0.0215991) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.895765,0.0375504) , 
0, 41944.6, 1, 0, 0.865828,0.0271532) , 
4, 0.342639, 1, 0, 0.495932,-0.00185294)    );
  // itree = 214
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57147,0.00148672) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235294,-0.0100491) , 
6, 1.46984, 1, 0, 0.476839,-0.00388966) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.777202,0.035793) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.774648,-0.00390534) , 
1, 13.2857, 1, 0, 0.776119,0.0361516) , 
0, 124449, 1, 0, 0.496475,-0.00126259)    );
  // itree = 215
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390435,-0.00794174) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53903,0.00549008) , 
8, -0.0227476, 1, 0, 0.503437,0.0056992) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.642857,-0.0384266) , 
1, 14.6667, 1, 0, 0.508151,0.00297588)    );
  // itree = 216
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463104,0.0253611) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363971,-0.000967009) , 
8, 0.0074665, 1, 0, 0.422556,0.0299832) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524344,-0.0029722) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392857,0.0157382) , 
6, 3.89551, 1, 0, 0.518468,-0.00460924) , 
7, -1.27163, 1, 0, 0.50584,-5.49008e-05)    );
  // itree = 217
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477679,-0.0210099) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22069,0.0108901) , 
1, 2.28571, 1, 0, 0.376694,-0.0293544) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.599451,0.00586706) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.352144,-0.00510146) , 
6, 1.30044, 1, 0, 0.505973,0.00375389) , 
4, 0.0194212, 1, 0, 0.496539,0.00133805)    );
  // itree = 218
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350467,0.019359) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.596154,0.00120749) , 
2, 54583.2, 1, 0, 0.454054,0.0373569) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.3422,-0.00610361) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.817491,0.00816396) , 
4, 0.200518, 1, 0, 0.504434,-0.0047369) , 
4, 0.0194378, 1, 0, 0.500701,-0.00161759)    );
  // itree = 219
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.301294,-0.00832515) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.173611,0.0537119) , 
8, 0.0830525, 1, 0, 0.293328,-0.0152043) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.636082,0.00737193) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669154,-0.00400939) , 
1, 4.42857, 1, 0, 0.650231,0.00562366) , 
4, 0.0765117, 1, 0, 0.489565,-0.00375239)    );
  // itree = 220
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514006,-0.00310722) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422785,0.00767385) , 
0, 41457.6, 1, 0, 0.483011,0.000974403) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572917,-0.0290292) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.743169,-0.00249981) , 
3, 0.047619, 1, 0, 0.656,-0.03783) , 
1, 10.6667, 1, 0, 0.49592,-0.00192145)    );
  // itree = 221
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.253731,-0.0273575) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.451879,-0.00633608) , 
4, 0.0228525, 1, 0, 0.430204,-0.0200995) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504202,0.00156103) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.787302,0.0217333) , 
1, 10.3333, 1, 0, 0.527881,0.00656573) , 
7, -0.714948, 1, 0, 0.503907,2.09711e-05)    );
  // itree = 222
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475825,0.00061356) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333333,0.0401313) , 
6, 3.46085, 1, 0, 0.470255,0.0056351) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448082,-0.0196231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.8509,0.00602625) , 
2, 123112, 1, 0, 0.555556,-0.0262898) , 
1, 4.14286, 1, 0, 0.495188,-0.0036966)    );
  // itree = 223
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.922343,0.0274717) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38749,-0.00452956) , 
6, 0.452312, 1, 0, 0.473076,-0.00325854) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.73639,0.00262595) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.632258,0.0391055) , 
6, 3.64463, 1, 0, 0.704365,0.032145) , 
0, 91298, 1, 0, 0.495973,0.000246344)    );
  // itree = 224
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501824,-0.00221666) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426282,0.0101973) , 
7, 1.00018, 1, 0, 0.487013,0.00031663) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.676923,-0.0404883) , 
4, 0.380934, 1, 0, 0.492047,-0.00177252)    );
  // itree = 225
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.20076,-0.00100836) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519802,-0.0106913) , 
2, 49322.4, 1, 0, 0.339269,-0.0124889) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.775556,0.00691988) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.802439,-0.0066311) , 
4, 0.345111, 1, 0, 0.781818,0.00758787) , 
4, 0.17141, 1, 0, 0.494519,-0.00544584)    );
  // itree = 226
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344,0.0385096) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49275,0.00072379) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.728929,0.0151558) , 
0, 96458, 1, 0, 0.51474,0.00461045) , 
7, -1.85793, 1, 0, 0.506143,0.00805536)    );
  // itree = 227
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.965306,0.041416) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539969,0.000801568) , 
6, 0.375833, 1, 0, 0.607374,0.00894083) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.146482,0.00686546) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458959,-0.0159375) , 
4, 0.0781931, 1, 0, 0.3235,-0.0157148) , 
6, 1.28568, 1, 0, 0.495876,-0.000743249)    );
  // itree = 228
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.650231,0.0212953) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470197,0.000634524) , 
0, 26699, 1, 0, 0.499747,0.00928589) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26,0.00640981) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.64548,-0.019231) , 
2, 58265.6, 1, 0, 0.530754,-0.0215625) , 
0, 60728.7, 1, 0, 0.506046,0.00301923)    );
  // itree = 229
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.478711,-0.0138167) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167617,0.0015739) , 
6, 0.938491, 1, 0, 0.322451,-0.0168505) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258065,-0.00625009) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.694218,0.00741199) , 
2, 28488.3, 1, 0, 0.606258,0.00835865) , 
4, 0.0575411, 1, 0, 0.506634,-0.000490386)    );
  // itree = 230
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578548,0.00565074) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473404,-0.0112404) , 
0, 52417.9, 1, 0, 0.562048,0.00724001) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.172297,0.00858817) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375217,-0.0130441) , 
4, 0.0413691, 1, 0, 0.333793,-0.0194097) , 
6, 1.61116, 1, 0, 0.496431,-0.000420977)    );
  // itree = 231
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437026,0.000860876) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555154,-0.0169587) , 
1, 7.38095, 1, 0, 0.45152,-0.00260856) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.891803,0.0346511) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.823077,-0.0116647) , 
4, 0.381156, 1, 0, 0.871264,0.03296) , 
4, 0.342881, 1, 0, 0.488466,0.000522226)    );
  // itree = 232
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.449534,0.0062667) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497115,-0.00280157) , 
7, -0.703266, 1, 0, 0.484676,-0.00118222) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69697,0.0255731) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.842105,0.0201087) , 
0, 163379, 1, 0, 0.769811,0.0458902) , 
1, 12.8571, 1, 0, 0.49923,0.00122036)    );
  // itree = 233
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525263,0.00306543) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496988,-0.0127163) , 
7, 0.912488, 1, 0, 0.521148,0.00151546) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.369565,0.00250484) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330709,0.0674318) , 
6, 1.78226, 1, 0, 0.358575,0.0317406) , 
7, 1.56439, 1, 0, 0.506584,0.00422319)    );
  // itree = 234
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463728,0.00587405) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336347,-0.00852227) , 
8, 0.0197938, 1, 0, 0.428392,0.00514285) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.758958,-0.0249623) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.832579,0.00473426) , 
0, 53779.4, 1, 0, 0.789773,-0.0213502) , 
4, 0.266766, 1, 0, 0.504065,-0.00040478)    );
  // itree = 235
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283019,-0.00517538) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.257143,-0.0430967) , 
0, 52441.5, 1, 0, 0.275109,-0.029425) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48992,-0.00258673) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.700416,0.00975297) , 
1, 7.38095, 1, 0, 0.523714,-0.00207163) , 
8, -0.0553035, 1, 0, 0.500707,-0.00460302)    );
  // itree = 236
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453937,-0.00693354) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.888889,0.0246996) , 
2, 170526, 1, 0, 0.469918,-0.0137501) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505376,-0.00228068) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.915556,0.0350512) , 
4, 0.286796, 1, 0, 0.729927,0.0268821) , 
3, 0.047619, 1, 0, 0.491017,-0.010453)    );
  // itree = 237
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.695425,-0.000909843) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492126,-0.0135245) , 
0, 35269.8, 1, 0, 0.614297,-0.015994) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421053,0.00160157) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.833333,0.021458) , 
4, 0.361661, 1, 0, 0.449494,0.00573851) , 
1, 1.38095, 1, 0, 0.492083,0.000122303)    );
  // itree = 238
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.556518,0.00283842) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.413989,0.0143541) , 
0, 37709.7, 1, 0, 0.508448,0.016678) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.299387,-0.013124) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.925806,0.00285528) , 
5, 9035.86, 1, 0, 0.501038,-0.018619) , 
1, 4, 1, 0, 0.505629,0.00325082)    );
  // itree = 239
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.245648,0.0207353) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488308,0.000269565) , 
2, 50884.3, 1, 0, 0.345826,0.0298572) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457948,-0.00391757) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.96748,0.0204796) , 
5, 9457.46, 1, 0, 0.589062,-0.00343129) , 
4, 0.0580879, 1, 0, 0.505189,0.00804726)    );
  // itree = 240
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.176856,-0.0240813) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603563,0.00153732) , 
4, 0.095373, 1, 0, 0.388093,-0.025306) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.576,0.0176673) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.51448,0.000227295) , 
7, -0.809792, 1, 0, 0.518246,0.00305211) , 
7, -1.00043, 1, 0, 0.494589,-0.00210236)    );
  // itree = 241
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208689,-0.0112857) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613389,0.00426787) , 
2, 30967.9, 1, 0, 0.50636,-0.000857465) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208861,-0.0314318) , 
6, 4.67225, 1, 0, 0.497019,-0.00302099)    );
  // itree = 242
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510766,0.000738866) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.741497,-0.030328) , 
1, 14.7619, 1, 0, 0.518361,-7.67359e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442623,0.0497632) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385246,0.0027284) , 
8, -0.00622706, 1, 0, 0.409836,0.047951) , 
7, 1.56496, 1, 0, 0.50889,0.00411453)    );
  // itree = 243
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302234,-0.00892727) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341385,0.0060377) , 
7, 0.144086, 1, 0, 0.319826,-0.00547066) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.766865,0.0129826) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.735714,-0.0161139) , 
1, 15.6667, 1, 0, 0.764842,0.0206853) , 
4, 0.114499, 1, 0, 0.514837,0.00599119)    );
  // itree = 244
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538387,0.0134972) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.406593,-0.00880289) , 
8, 0.0157929, 1, 0, 0.492698,0.0126164) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523565,-0.00595442) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.24812,0.0362432) , 
8, 0.0892923, 1, 0, 0.5123,-0.0108605) , 
7, -0.415574, 1, 0, 0.505904,-0.00320025)    );
  // itree = 245
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479693,-0.00176251) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314961,0.0254245) , 
6, 4.12602, 1, 0, 0.475104,-0.00194887) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57,0.0292004) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.910569,0.00833506) , 
5, 9215.09, 1, 0, 0.757848,0.039772) , 
1, 10.2857, 1, 0, 0.5003,0.00176891)    );
  // itree = 246
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333004,-0.00865865) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.940092,0.0160062) , 
5, 8748.44, 1, 0, 0.440195,-0.0140612) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.598416,0.0117597) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486824,-0.00230777) , 
7, -0.186602, 1, 0, 0.512487,0.0022593) , 
7, -0.716935, 1, 0, 0.494973,-0.00169456)    );
  // itree = 247
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.291667,-0.0236881) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505576,0.0325661) , 
4, 0.0112313, 1, 0, 0.430993,0.0364801) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313248,-0.00424354) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.739043,0.0055094) , 
2, 56976.7, 1, 0, 0.498032,-0.00148121) , 
4, 0.01941, 1, 0, 0.49248,0.00166257)    );
  // itree = 248
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.950092,0.0316805) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531563,0.000514905) , 
6, 0.393187, 1, 0, 0.611346,0.00772952) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.223059,-0.00832763) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.929204,0.0179886) , 
5, 7841.65, 1, 0, 0.338983,-0.0120996) , 
6, 1.18637, 1, 0, 0.496635,-0.000621933)    );
  // itree = 249
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340426,0.0134943) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374644,-0.00832841) , 
7, -0.985406, 1, 0, 0.367777,-0.0104756) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.587209,0.0138559) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.949893,0.00322624) , 
5, 5850.69, 1, 0, 0.821183,0.0174945) , 
4, 0.209406, 1, 0, 0.500503,-0.00228789)    );
  // itree = 250
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309103,-0.00830792) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.753948,0.00510382) , 
2, 58265.6, 1, 0, 0.505128,-0.00781223) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516252,0.0086046) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.216783,-0.0163153) , 
7, 2.31734, 1, 0, 0.497092,0.0156896) , 
7, 0.141508, 1, 0, 0.501511,0.00276712)    );
  // itree = 251
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44697,-0.00755883) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527676,0.00428015) , 
7, -0.716935, 1, 0, 0.507478,0.00284804) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.280374,-0.0222771) , 
6, 3.98119, 1, 0, 0.497682,0.000494961)    );
  // itree = 252
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409639,-0.00604159) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338912,-0.0294488) , 
4, 0.012109, 1, 0, 0.367901,-0.0558764) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339844,0.0306109) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507985,-0.00162565) , 
7, -1.83256, 1, 0, 0.498449,-0.000267214) , 
4, 0.0193969, 1, 0, 0.487701,-0.00484573)    );
  // itree = 253
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.178808,-0.0303221) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350687,0.00768226) , 
2, 13865.7, 1, 0, 0.34179,0.0140301) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.713568,-0.0112651) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.688468,0.00815231) , 
8, 0.0210666, 1, 0, 0.706857,-0.0113157) , 
2, 58265.6, 1, 0, 0.497642,0.00320957)    );
  // itree = 254
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526597,0.000650162) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422185,0.0187383) , 
8, 0.0430507, 1, 0, 0.51375,0.00606231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0296296,-0.048789) , 
8, 0.129414, 1, 0, 0.500793,0.00431312)    );
  // itree = 255
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262745,-0.0318004) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389222,-0.00572856) , 
1, 3.47619, 1, 0, 0.312796,-0.0425266) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533976,0.00171062) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.278215,-0.0117141) , 
7, 1.68736, 1, 0, 0.511969,0.00155659) , 
7, -1.57265, 1, 0, 0.494639,-0.0022791)    );
  // itree = 256
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518021,-0.00285929) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542373,0.0131451) , 
7, 0.619297, 1, 0, 0.520917,-0.00199714) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341346,-0.0263516) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463235,-0.00219243) , 
8, -0.00617553, 1, 0, 0.410417,-0.027195) , 
7, 1.00018, 1, 0, 0.499391,-0.00690581)    );
  // itree = 257
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359561,0.00527776) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.909812,-0.00903768) , 
5, 5382.4, 1, 0, 0.519983,0.0067033) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22963,-0.0386978) , 
6, 4.8145, 1, 0, 0.511966,0.00393456)    );
  // itree = 258
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37037,0.0026384) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371134,-0.0203345) , 
7, -0.508801, 1, 0, 0.370892,-0.0360488) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.520877,-0.00402772) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47967,0.00472227) , 
7, 0.426726, 1, 0, 0.505579,-0.00188883) , 
4, 0.0199047, 1, 0, 0.494096,-0.00480101)    );
  // itree = 259
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.093985,0.00987625) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550898,0.0245253) , 
5, 2593.27, 1, 0, 0.270208,0.0283317) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.224558,-0.00499763) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.622157,0.00149016) , 
2, 30967.9, 1, 0, 0.519809,-0.000966586) , 
8, -0.0586522, 1, 0, 0.498416,0.00154453)    );
  // itree = 260
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62,0.0362127) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341346,-0.0050861) , 
0, 38233.4, 1, 0, 0.458101,0.0343679) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518132,-0.00532567) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.451689,0.005003) , 
8, 0.0207628, 1, 0, 0.499448,-0.00540861) , 
4, 0.0199047, 1, 0, 0.496418,-0.00249356)    );
  // itree = 261
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.443328,-0.00211308) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.871508,0.0127377) , 
4, 0.304345, 1, 0, 0.514658,-0.000884461) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217877,-0.0419065) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383505,-0.00703459) , 
8, -0.022183, 1, 0, 0.338855,-0.0310953) , 
7, 1.28345, 1, 0, 0.491133,-0.00492719)    );
  // itree = 262
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308364,-0.00678514) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.714803,0.00247579) , 
4, 0.0953707, 1, 0, 0.513113,-0.00550383) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.638418,-0.00739725) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266802,0.0172934) , 
6, 0.6905, 1, 0, 0.365269,0.0199219) , 
7, 1.27972, 1, 0, 0.493568,-0.00214259)    );
  // itree = 263
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350105,-0.00874536) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368664,0.0169621) , 
4, 0.0330363, 1, 0, 0.353544,-0.0101895) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407878,0.00932132) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.800676,-0.00165923) , 
4, 0.210367, 1, 0, 0.559229,0.0119452) , 
4, 0.0384638, 1, 0, 0.511173,0.00677369)    );
  // itree = 264
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506079,0.00262707) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552781,-0.00794328) , 
0, 58147.5, 1, 0, 0.515943,0.0011041) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347561,-0.0216732) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303191,0.0128594) , 
7, 0.897193, 1, 0, 0.337678,-0.028923) , 
8, 0.0369837, 1, 0, 0.485942,-0.00394932)    );
  // itree = 265
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.373615,0.00734515) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.520228,-0.00179783) , 
4, 0.0384374, 1, 0, 0.485206,0.00158328) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364341,-0.0228742) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.848649,0.00160229) , 
4, 0.266596, 1, 0, 0.601057,-0.0291187) , 
0, 73362.1, 1, 0, 0.503053,-0.00314634)    );
  // itree = 266
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424581,0.0353946) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313305,-0.0046699) , 
1, 2.57143, 1, 0, 0.36165,0.0303476) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541204,0.0027977) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422034,-0.00884583) , 
8, 0.0222554, 1, 0, 0.510648,-0.000105699) , 
7, -1.5727, 1, 0, 0.498404,0.00239665)    );
  // itree = 267
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472404,-0.00264879) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614094,0.00752925) , 
8, -0.00402874, 1, 0, 0.530595,0.00394429) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26151,0.000447629) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511136,-0.0137822) , 
4, 0.0580562, 1, 0, 0.417071,-0.0164477) , 
8, 0.0207628, 1, 0, 0.498323,-0.00185267)    );
  // itree = 268
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.660971,0.00556103) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.618705,0.0417422) , 
0, 55793.8, 1, 0, 0.656275,0.0243401) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.461115,-0.00413089) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387947,-0.0134371) , 
7, 0.708787, 1, 0, 0.440602,-0.0139381) , 
1, 1.47619, 1, 0, 0.494146,-0.00443503)    );
  // itree = 269
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421394,0.0146106) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321792,-0.00567669) , 
4, 0.0257386, 1, 0, 0.377256,0.015139) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554308,-0.00760782) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475651,0.0052261) , 
8, 0.0258945, 1, 0, 0.536554,-0.0101854) , 
4, 0.0384374, 1, 0, 0.501394,-0.00459589)    );
  // itree = 270
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217857,0.0108711) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488156,-0.00574109) , 
2, 50884.3, 1, 0, 0.32949,0.0095543) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.743921,-0.0060548) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380623,-0.0200938) , 
6, 3.23275, 1, 0, 0.69667,-0.0161603) , 
4, 0.114384, 1, 0, 0.489969,-0.00168446)    );
  // itree = 271
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.756214,0.00254055) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298343,0.0201299) , 
6, 1.64016, 1, 0, 0.638494,0.0192921) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.193634,-0.00838963) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.633715,0.00372307) , 
4, 0.0765854, 1, 0, 0.449473,-0.00327618) , 
1, 1.28571, 1, 0, 0.502595,0.00306636)    );
  // itree = 272
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328729,-0.00059764) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.693989,-0.0239435) , 
2, 83242, 1, 0, 0.402426,-0.0100401) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574261,0.00615586) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433383,-0.000940992) , 
7, 0.705997, 1, 0, 0.528467,0.00844841) , 
7, -1.00119, 1, 0, 0.505681,0.00510595)    );
  // itree = 273
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473684,0.0124664) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.45279,-0.00302306) , 
4, 0.0157719, 1, 0, 0.454119,-0.00415385) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.935323,0.0414218) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.819753,-0.00258603) , 
4, 0.348996, 1, 0, 0.858086,0.0175221) , 
4, 0.323625, 1, 0, 0.502262,-0.00157063)    );
  // itree = 274
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407583,-0.00119245) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563358,0.0191983) , 
8, -0.0199524, 1, 0, 0.523781,0.0311588) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544776,-0.00674579) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480903,0.00956294) , 
1, 2.95238, 1, 0, 0.511691,0.0021509) , 
7, -0.429463, 1, 0, 0.515709,0.0117931)    );
  // itree = 275
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.51242,-0.00130162) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488235,-0.0106365) , 
7, 0.608746, 1, 0, 0.509406,-0.00544394) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.637681,0.0284209) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381795,0.000380625) , 
7, 1.1807, 1, 0, 0.43487,0.0155963) , 
7, 0.990617, 1, 0, 0.494795,-0.00131937)    );
  // itree = 276
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367223,-0.00873615) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534309,0.00540915) , 
8, -0.0323121, 1, 0, 0.504821,0.00704806) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247492,0.0124405) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.600629,-0.0167417) , 
2, 49322.4, 1, 0, 0.516361,-0.0178437) , 
0, 55865, 1, 0, 0.50772,0.000793938)    );
  // itree = 277
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428762,0.00656121) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.816667,-0.0132488) , 
4, 0.266795, 1, 0, 0.510541,0.00778203) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.66877,0.0010352) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.352748,-0.0100303) , 
6, 0.911473, 1, 0, 0.491244,-0.0127085) , 
8, 0.00631093, 1, 0, 0.502193,-0.00108251)    );
  // itree = 278
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.117647,-0.0325778) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447514,0.0134899) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518757,0.00264666) , 
4, 0.0193969, 1, 0, 0.513458,0.00800868) , 
8, -0.101535, 1, 0, 0.501394,0.00614258)    );
  // itree = 279
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453608,0.0426329) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.145833,-0.00707403) , 
6, 1.20409, 1, 0, 0.300518,0.0324658) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546636,-0.00291356) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371585,0.0111526) , 
8, 0.0413569, 1, 0, 0.518664,-0.00199159) , 
8, -0.0626172, 1, 0, 0.501711,0.000686198)    );
  // itree = 280
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368906,-0.00799704) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.804598,0.00684628) , 
2, 72298.3, 1, 0, 0.505872,-0.00980112) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.410596,0.0136099) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541884,0.000712365) , 
4, 0.0385993, 1, 0, 0.512698,0.00866528) , 
7, -0.134654, 1, 0, 0.509633,0.000373936)    );
  // itree = 281
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.162963,-0.0392327) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347826,-0.00827538) , 
4, 0.0383905, 1, 0, 0.293217,-0.0376885) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414,-0.00114772) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.855046,0.0122373) , 
4, 0.247738, 1, 0, 0.518736,0.00249877) , 
7, -1.56758, 1, 0, 0.498316,-0.00114015)    );
  // itree = 282
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.960227,0.0285057) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482391,-0.0066521) , 
6, 0.376206, 1, 0, 0.552029,-0.00967027) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.152361,-0.00240734) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.796681,0.0169484) , 
5, 3732.36, 1, 0, 0.371994,0.0104783) , 
6, 1.65435, 1, 0, 0.501489,-0.00401409)    );
  // itree = 283
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419331,0.00276788) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.861171,0.0245557) , 
4, 0.261768, 1, 0, 0.46495,0.00984704) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.795455,-0.0172727) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.942308,0.0216007) , 
0, 96471.2, 1, 0, 0.83125,-0.0150329) , 
4, 0.323387, 1, 0, 0.510872,0.00672791)    );
  // itree = 284
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348694,0.000513303) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.764927,0.00683885) , 
4, 0.114415, 1, 0, 0.535828,0.00653168) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208333,-0.039708) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.145038,0.0112213) , 
6, 1.85631, 1, 0, 0.184438,-0.033002) , 
8, 0.071974, 1, 0, 0.511816,0.00383019)    );
  // itree = 285
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0773481,-0.0357797) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590635,0.00565919) , 
2, 15209.1, 1, 0, 0.550898,0.00658532) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421437,-0.00726705) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.833333,0.0131707) , 
4, 0.361653, 1, 0, 0.458841,-0.0107303) , 
1, 2.95238, 1, 0, 0.501486,-0.00270892)    );
  // itree = 286
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.63118,0.00116515) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321449,-0.00599944) , 
6, 1.12662, 1, 0, 0.511752,-0.00355832) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.145349,0.000165127) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47619,-0.0282355) , 
4, 0.191884, 1, 0, 0.334988,-0.0428476) , 
6, 3.23243, 1, 0, 0.497252,-0.00678112)    );
  // itree = 287
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72043,0.00554613) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542484,0.0144616) , 
0, 35267.6, 1, 0, 0.657407,0.0226195) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.490594,0.0063668) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376238,-0.00717762) , 
8, 0.0207628, 1, 0, 0.459106,0.00577319) , 
1, 1.47619, 1, 0, 0.510878,0.0101714)    );
  // itree = 288
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.769408,0.00972923) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.365783,-0.00103675) , 
6, 0.750482, 1, 0, 0.511074,0.00515373) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235714,-0.023999) , 
6, 4.81051, 1, 0, 0.503319,0.00334539)    );
  // itree = 289
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.454976,0.0198175) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321429,0.00128779) , 
4, 0.0139693, 1, 0, 0.337521,0.00957784) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47172,-0.00592399) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.958051,0.0148298) , 
5, 10391, 1, 0, 0.581126,-0.00842401) , 
4, 0.0574105, 1, 0, 0.496426,-0.00216483)    );
  // itree = 290
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513332,0.00044603) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.8,0.0250269) , 
1, 11.8095, 1, 0, 0.532428,0.00381014) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35369,-0.0164721) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534884,0.0128562) , 
0, 76149.4, 1, 0, 0.379235,-0.0256454) , 
7, 0.996203, 1, 0, 0.503781,-0.00169809)    );
  // itree = 291
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285714,-0.0290752) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392092,-0.00158983) , 
7, -0.141111, 1, 0, 0.343834,-0.0353307) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500606,-0.00397308) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.723724,0.0105159) , 
1, 8.85714, 1, 0, 0.538074,-0.00375929) , 
4, 0.0383832, 1, 0, 0.495568,-0.0106681)    );
  // itree = 292
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329354,-0.00553315) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.705442,0.00525058) , 
4, 0.0765269, 1, 0, 0.542353,-0.000286538) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.462766,0.0319482) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355353,-0.00345135) , 
1, 2.7619, 1, 0, 0.404908,0.0302495) , 
8, 0.0368993, 1, 0, 0.520237,0.00462696)    );
  // itree = 293
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458772,0.00630119) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364,0.0359231) , 
6, 2.34564, 1, 0, 0.441727,0.0224371) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323892,-0.00736537) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.698909,0.00848447) , 
4, 0.0771763, 1, 0, 0.531593,0.00114319) , 
8, -0.0194393, 1, 0, 0.506759,0.00702759)    );
  // itree = 294
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.275025,0.0125881) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.427828,0.000719967) , 
5, 937.186, 1, 0, 0.341866,0.0178093) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.365973,-0.013285) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.780952,-0.000237757) , 
4, 0.18781, 1, 0, 0.569648,-0.0158263) , 
4, 0.0574254, 1, 0, 0.489028,-0.00392144)    );
  // itree = 295
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0944882,-0.0170779) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.241135,-0.0375372) , 
8, -0.117676, 1, 0, 0.171642,-0.048652) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548744,0.00152493) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374322,-0.00962032) , 
8, 0.0291781, 1, 0, 0.50863,-0.00206486) , 
8, -0.0776289, 1, 0, 0.490841,-0.00452406)    );
  // itree = 296
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.793683,0.0101895) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311384,-0.00479081) , 
6, 0.683452, 1, 0, 0.483238,-0.000704995) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41688,-0.0295346) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.786982,0.00752058) , 
0, 119439, 1, 0, 0.588477,-0.0285128) , 
0, 73365.4, 1, 0, 0.498879,-0.00483789)    );
  // itree = 297
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.377163,-0.000859944) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.80898,0.0115262) , 
2, 75074.7, 1, 0, 0.495818,0.00358905) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.810056,-0.0392095) , 
2, 197290, 1, 0, 0.507156,0.00143713)    );
  // itree = 298
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385827,-0.0226633) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.3125,0.00694391) , 
0, 51285.9, 1, 0, 0.361257,-0.0363356) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.3196,0.00392633) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.720771,-0.00187515) , 
4, 0.10999, 1, 0, 0.517307,0.00291592) , 
4, 0.0194378, 1, 0, 0.505664,-1.26063e-05)    );
  // itree = 299
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613215,-0.00943392) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.461336,-0.00448501) , 
1, 1.47619, 1, 0, 0.501714,-0.0128135) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422078,0.0300854) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.234375,-0.00900902) , 
7, 2.28499, 1, 0, 0.336879,0.0241807) , 
7, 1.8502, 1, 0, 0.492323,-0.010706)    );
  // itree = 300
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.645015,0.0145178) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.454269,-0.00527013) , 
0, 26583, 1, 0, 0.486213,-0.0045162) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38292,0.0237646) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.632138,0.00350604) , 
1, 3.85714, 1, 0, 0.551075,0.0234807) , 
0, 58156.4, 1, 0, 0.500493,0.00164765)    );
  // itree = 301
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.391608,-0.0120961) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.160622,-0.0378946) , 
6, 1.67844, 1, 0, 0.319936,-0.0376685) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400209,0.0074431) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542402,-0.00262508) , 
4, 0.0384111, 1, 0, 0.511559,-0.000174752) , 
7, -1.28117, 1, 0, 0.487882,-0.00480748)    );
  // itree = 302
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497182,0.0174699) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495082,-0.00975587) , 
1, 4.71429, 1, 0, 0.496644,0.0234888) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541643,-0.0070109) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486205,0.00493926) , 
1, 2.7619, 1, 0, 0.512751,-0.00297506) , 
7, -0.714948, 1, 0, 0.508815,0.00349172)    );
  // itree = 303
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327518,-0.0132825) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.823529,0.0172508) , 
4, 0.304221, 1, 0, 0.396587,-0.0199779) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.553151,0.00392611) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356979,-0.013011) , 
7, 1.27637, 1, 0, 0.529198,0.00411137) , 
8, -0.01725, 1, 0, 0.490682,-0.00288522)    );
  // itree = 304
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506651,-0.0123787) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46241,-0.00080879) , 
7, 0.42984, 1, 0, 0.490741,-0.01764) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346397,0.0156577) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590401,-0.00242264) , 
4, 0.0573885, 1, 0, 0.50692,0.00941633) , 
8, 0.0040048, 1, 0, 0.498204,-0.00515912)    );
  // itree = 305
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.300372,0.000563394) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475845,0.0147236) , 
4, 0.114369, 1, 0, 0.341671,0.0115196) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.942478,0.00220127) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.802326,-0.028868) , 
0, 55865, 1, 0, 0.891549,-0.0155065) , 
5, 5382.4, 1, 0, 0.499797,0.0037478)    );
  // itree = 306
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583862,0.00908084) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315315,-0.0229061) , 
7, 1.51024, 1, 0, 0.559308,0.014838) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42621,-0.00560419) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.886525,0.0306917) , 
0, 190736, 1, 0, 0.450973,-0.00748082) , 
1, 2.57143, 1, 0, 0.50307,0.00325202)    );
  // itree = 307
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348877,-0.0186296) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546871,-0.000829222) , 
7, -1.36755, 1, 0, 0.520614,-0.00641808) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512605,0.0257376) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235099,-0.0022109) , 
6, 1.21073, 1, 0, 0.385432,0.0304371) , 
7, 1.28345, 1, 0, 0.502886,-0.00158474)    );
  // itree = 308
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.693571,0.00531253) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313369,-0.0057914) , 
6, 0.903789, 1, 0, 0.48506,-0.00227545) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.791878,0.0302214) , 
1, 13.0952, 1, 0, 0.497356,-2.6763e-05)    );
  // itree = 309
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.173494,-0.00439994) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486068,-0.0281296) , 
2, 49322.4, 1, 0, 0.310298,-0.0269626) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523667,-0.00352915) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532997,0.00927545) , 
7, 0.15103, 1, 0, 0.527945,0.00525316) , 
8, -0.0386484, 1, 0, 0.496251,0.000561918)    );
  // itree = 310
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509069,0.00391904) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.676375,-0.0254066) , 
1, 10.3333, 1, 0, 0.523582,0.00395979) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306288,-6.89772e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524089,-0.0170512) , 
4, 0.0574999, 1, 0, 0.444196,-0.0217918) , 
7, 0.717692, 1, 0, 0.501835,-0.00309487)    );
  // itree = 311
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.461429,0.00312533) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.894539,0.0282281) , 
2, 116531, 1, 0, 0.518482,0.0110507) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288591,0.00107309) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.819444,-0.050867) , 
5, 5343.3, 1, 0, 0.407908,-0.0128431) , 
7, 0.992832, 1, 0, 0.497196,0.00645096)    );
  // itree = 312
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338164,-0.0194401) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552088,-0.00251812) , 
7, -1.53386, 1, 0, 0.533529,-0.0095498) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494105,0.00965671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.378492,-0.00675195) , 
8, 0.0207628, 1, 0, 0.462045,0.0100164) , 
1, 2.95238, 1, 0, 0.496377,0.000619253)    );
  // itree = 313
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.51135,0.00429601) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.606272,0.0353606) , 
7, 0.507126, 1, 0, 0.518668,0.014697) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46234,0.00137982) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.255952,-0.0351635) , 
6, 2.58204, 1, 0, 0.437853,-0.00662518) , 
7, 0.683732, 1, 0, 0.4964,0.00882191)    );
  // itree = 314
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542395,0.00288804) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332936,-0.00972255) , 
1, 2.28571, 1, 0, 0.455133,-0.00388852) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.663664,0.0253263) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.682043,0.00283927) , 
0, 55208.6, 1, 0, 0.675532,0.0198988) , 
1, 6.90476, 1, 0, 0.496877,0.000616841)    );
  // itree = 315
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230023,-0.00166643) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581395,-0.0225612) , 
2, 76326.4, 1, 0, 0.29765,-0.0126056) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.43956,-0.0183673) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.711925,0.00323313) , 
7, -1.52896, 1, 0, 0.69145,0.00265422) , 
4, 0.0953678, 1, 0, 0.484516,-0.00536452)    );
  // itree = 316
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439696,0.00712229) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530926,-0.00372278) , 
7, -0.900958, 1, 0, 0.51016,-0.00281157) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298507,0.052166) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330986,-0.00836458) , 
4, 0.0566045, 1, 0, 0.315217,0.0386759) , 
7, 1.86026, 1, 0, 0.499184,-0.000475678)    );
  // itree = 317
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.369697,-0.0319497) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305625,-0.0029719) , 
4, 0.0117576, 1, 0, 0.310488,-0.0138274) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.650068,0.00911528) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.692308,-0.0121494) , 
1, 9.33333, 1, 0, 0.657621,0.0112503) , 
4, 0.0769126, 1, 0, 0.502467,4.16198e-05)    );
  // itree = 318
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.813368,-0.0039698) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322531,0.00888692) , 
6, 0.926967, 1, 0, 0.553513,0.00958534) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393064,-0.0167558) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463613,-0.0035721) , 
7, -0.716935, 1, 0, 0.445239,-0.0129627) , 
1, 2.57143, 1, 0, 0.49716,-0.00215023)    );
  // itree = 319
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524314,-0.00224225) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399689,0.0108054) , 
7, 1.28535, 1, 0, 0.507609,-0.0012019) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359712,0.0345623) , 
6, 4.81051, 1, 0, 0.503444,0.0009669)    );
  // itree = 320
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455718,0.00633066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546788,-0.00624282) , 
8, -0.0169638, 1, 0, 0.520487,-0.00599013) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.651639,0.0259669) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375,0.00321378) , 
1, 1.09524, 1, 0, 0.445607,0.0217463) , 
7, 0.997963, 1, 0, 0.506121,-0.000668823)    );
  // itree = 321
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533841,-0.00278341) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.460356,0.00805141) , 
1, 2.14286, 1, 0, 0.496278,0.0044348) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.650794,-0.0295197) , 
1, 15.1905, 1, 0, 0.500202,0.00270386)    );
  // itree = 322
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497585,0.0127397) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481767,0.00191063) , 
7, -0.425365, 1, 0, 0.487266,0.0124819) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346154,-0.039038) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.596358,-0.000445164) , 
8, -0.0503714, 1, 0, 0.573895,-0.00689748) , 
1, 4.42857, 1, 0, 0.512249,0.00689308)    );
  // itree = 323
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.228856,-0.0179496) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548982,0.0162728) , 
7, -1.99447, 1, 0, 0.51269,0.0264501) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.378723,0.00617663) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548069,-0.00427813) , 
4, 0.0388886, 1, 0, 0.511255,-0.00326898) , 
7, -0.411941, 1, 0, 0.511762,0.00723579)    );
  // itree = 324
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348178,0.0200468) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494236,-0.000621139) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.566591,-0.0153085) , 
1, 4.14286, 1, 0, 0.514274,-0.0085444) , 
7, -1.85788, 1, 0, 0.506143,-0.00634312)    );
  // itree = 325
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404954,-0.00399281) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.834068,0.0100776) , 
4, 0.285596, 1, 0, 0.467975,-0.00500996) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539773,0.0067384) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.949495,0.0491948) , 
2, 98644.8, 1, 0, 0.756684,0.0397439) , 
3, 0.047619, 1, 0, 0.489523,-0.00166972)    );
  // itree = 326
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.220588,0.0381244) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470889,-0.00476016) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.644007,0.00457312) , 
1, 5.90476, 1, 0, 0.510978,-0.00638807) , 
8, -0.109829, 1, 0, 0.503022,-0.00491817)    );
  // itree = 327
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447214,0.0152634) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.888559,0.00512294) , 
2, 37617.2, 1, 0, 0.666421,0.0286311) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477217,-0.0025529) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347015,0.0128408) , 
7, 1.28989, 1, 0, 0.458774,-0.000895922) , 
1, 1.47619, 1, 0, 0.513524,0.00688947)    );
  // itree = 328
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296478,-0.00803945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.641495,0.0017112) , 
4, 0.0763708, 1, 0, 0.482425,-0.00679114) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.661538,-0.0382674) , 
1, 15.1905, 1, 0, 0.487087,-0.00837189)    );
  // itree = 329
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464063,0.0113965) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.140257,-0.00167748) , 
1, 2.85714, 1, 0, 0.327462,0.0166749) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.611523,-0.00525958) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.930796,0.0362994) , 
2, 148446, 1, 0, 0.645458,-0.00517304) , 
4, 0.0765269, 1, 0, 0.502737,0.00463261)    );
  // itree = 330
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341704,0.00657218) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.656006,-0.00361013) , 
4, 0.0768043, 1, 0, 0.517084,0.00292913) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389189,-0.0278629) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273109,-0.0014183) , 
7, 1.90503, 1, 0, 0.323877,-0.0300257) , 
7, 1.56496, 1, 0, 0.500797,0.000151151)    );
  // itree = 331
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49445,-0.0100129) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.981982,0.0194572) , 
5, 4612.88, 1, 0, 0.617069,-0.0205553) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502435,0.00578371) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.369501,-0.00807003) , 
7, 0.711781, 1, 0, 0.465601,0.0039072) , 
1, 1.33333, 1, 0, 0.505582,-0.0025498)    );
  // itree = 332
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.745168,0.00914701) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349306,-0.00476181) , 
6, 0.80244, 1, 0, 0.509905,0.000846385) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.290909,-0.0167112) , 
6, 3.89583, 1, 0, 0.500395,-0.000915635)    );
  // itree = 333
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348823,-0.000998682) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.809524,0.0102868) , 
4, 0.171362, 1, 0, 0.491437,0.00390739) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560886,-0.0298572) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.919463,0.0286144) , 
4, 0.328059, 1, 0, 0.688095,-0.0263909) , 
1, 10.3333, 1, 0, 0.507848,0.00137903)    );
  // itree = 334
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335435,-0.00321824) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319287,0.0115744) , 
7, 1.00607, 1, 0, 0.332109,-0.000755939) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.775194,0.0145892) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.745335,-0.00142598) , 
7, 0.141817, 1, 0, 0.762066,0.0136758) , 
4, 0.133367, 1, 0, 0.507893,0.00514435)    );
  // itree = 335
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508696,0.00541941) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.36512,-0.00569128) , 
8, 0.0244739, 1, 0, 0.472475,0.00600601) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.626263,-0.0275458) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.95045,0.0156049) , 
2, 62576, 1, 0, 0.797619,-0.0250296) , 
4, 0.342388, 1, 0, 0.499603,0.00341663)    );
  // itree = 336
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.257288,-0.00047516) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542543,0.0133348) , 
5, 2307.66, 1, 0, 0.347399,0.0111362) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.962868,0.0177537) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.801681,-0.022852) , 
6, 0.829075, 1, 0, 0.893169,-0.0102196) , 
5, 5387.48, 1, 0, 0.502688,0.00505975)    );
  // itree = 337
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513678,0.0141182) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366397,-0.0135191) , 
7, 0.711781, 1, 0, 0.473481,0.0141438) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519048,-0.0112726) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544066,0.00582166) , 
7, -0.133842, 1, 0, 0.532472,-0.00430105) , 
8, -0.00926542, 1, 0, 0.51104,0.00240012)    );
  // itree = 338
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514917,-0.00748507) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531096,0.00188279) , 
7, -0.145218, 1, 0, 0.523857,-0.00502514) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298487,0.00679506) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75,0.0429757) , 
1, 12, 1, 0, 0.379932,0.0277136) , 
6, 2.18628, 1, 0, 0.497972,0.000862794)    );
  // itree = 339
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362205,-0.0125925) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.139303,0.0081245) , 
6, 1.49329, 1, 0, 0.302573,-0.0198044) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.67598,0.00346069) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310345,-0.0219625) , 
6, 3.89583, 1, 0, 0.649281,0.00220558) , 
4, 0.0764396, 1, 0, 0.494041,-0.0076495)    );
  // itree = 340
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395833,0.020444) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502473,0.00100335) , 
4, 0.0383935, 1, 0, 0.47883,0.0127487) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530884,-0.00703113) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.370107,0.0116914) , 
7, 1.41247, 1, 0, 0.506588,-0.00963124) , 
7, -0.699902, 1, 0, 0.499402,-0.00383777)    );
  // itree = 341
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525367,0.000655881) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.408072,0.0203038) , 
6, 3.98119, 1, 0, 0.519822,0.00368383) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.261194,-0.0329082) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.21875,-0.00617543) , 
1, 2.04762, 1, 0, 0.238095,-0.0359533) , 
7, 1.8502, 1, 0, 0.503293,0.00135828)    );
  // itree = 342
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27451,-0.0109833) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414072,0.0134072) , 
7, -0.733973, 1, 0, 0.382353,0.0197106) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457843,-0.0041167) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.866584,0.0102587) , 
4, 0.296517, 1, 0, 0.542724,-0.00400268) , 
4, 0.03845, 1, 0, 0.506621,0.00133566)    );
  // itree = 343
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399494,-0.00569365) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.239067,0.0265547) , 
6, 1.49062, 1, 0, 0.35097,0.00785739) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439567,-0.00900146) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.880319,0.00680101) , 
2, 98644.8, 1, 0, 0.524641,-0.0139501) , 
4, 0.0388532, 1, 0, 0.485487,-0.00903369)    );
  // itree = 344
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.197105,-0.00111631) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517964,-0.0193449) , 
4, 0.209338, 1, 0, 0.257143,-0.0125311) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785775,-0.00352836) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562407,0.0112188) , 
1, 2.28571, 1, 0, 0.64402,0.011208) , 
2, 38497.3, 1, 0, 0.505322,0.00269744)    );
  // itree = 345
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.102881,-0.0114271) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.520778,0.0150983) , 
2, 23205.4, 1, 0, 0.44687,0.0226131) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506634,0.00786821) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532279,-0.00723815) , 
7, -0.414862, 1, 0, 0.523554,-0.00469302) , 
8, -0.01725, 1, 0, 0.502135,0.00293427)    );
  // itree = 346
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.966667,0.0302163) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448395,-0.00342986) , 
6, 0.376688, 1, 0, 0.503311,-0.00424311) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.272374,0.00148435) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52027,-0.0316354) , 
4, 0.28618, 1, 0, 0.362963,-0.0276792) , 
6, 3.23243, 1, 0, 0.491793,-0.00616644)    );
  // itree = 347
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294118,-0.028025) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304983,-0.00458042) , 
4, 0.0112599, 1, 0, 0.304394,-0.0140108) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.725891,-0.000494528) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.670732,0.0297927) , 
7, 1.05743, 1, 0, 0.7178,0.00898076) , 
4, 0.114577, 1, 0, 0.487149,-0.00384689)    );
  // itree = 348
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.615385,-0.012834) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664062,0.0148609) , 
4, 0.0191128, 1, 0, 0.659126,0.0276332) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.369587,-0.0014963) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.853949,0.019684) , 
4, 0.304407, 1, 0, 0.45863,0.00344193) , 
1, 1.38095, 1, 0, 0.510746,0.0097301)    );
  // itree = 349
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557458,-0.00427902) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35468,-0.0291362) , 
7, 1.54249, 1, 0, 0.540462,-0.0148704) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421723,-0.000154029) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.897959,0.0415484) , 
4, 0.361911, 1, 0, 0.466564,0.00561406) , 
1, 2.7619, 1, 0, 0.50219,-0.00426123)    );
  // itree = 350
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.633914,-0.00906028) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.236615,0.00498691) , 
6, 1.59299, 1, 0, 0.536441,-0.0126628) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439394,0.00321376) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.711538,-0.0219849) , 
1, 14.9048, 1, 0, 0.45533,0.00341215) , 
1, 2.66667, 1, 0, 0.493432,-0.00413897)    );
  // itree = 351
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491318,0.000114549) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.170584,0.0149706) , 
6, 1.03548, 1, 0, 0.34412,0.0136188) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.743045,-0.00681719) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.758725,0.0105828) , 
7, 0.423543, 1, 0, 0.748148,-0.00203478) , 
4, 0.133749, 1, 0, 0.511125,0.00714837)    );
  // itree = 352
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481946,-0.00228586) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.625269,0.0120043) , 
1, 4.14286, 1, 0, 0.52478,0.00276619) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0846154,-0.0170196) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293706,-0.029854) , 
2, 44938.7, 1, 0, 0.194139,-0.0465145) , 
7, 1.85823, 1, 0, 0.506486,3.94671e-05)    );
  // itree = 353
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285425,-0.00847915) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.658366,0.00447312) , 
4, 0.0764921, 1, 0, 0.49626,-0.00406627) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508671,0.0109474) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.66967,-0.0138937) , 
0, 83185.1, 1, 0, 0.528131,0.018084) , 
7, -0.140498, 1, 0, 0.513723,0.00807056)    );
  // itree = 354
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42509,-0.00147807) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.241935,0.0264582) , 
6, 4.29129, 1, 0, 0.419443,-0.00169708) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.773547,0.0146918) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.97343,-0.00431023) , 
5, 10852.3, 1, 0, 0.864184,0.017825) , 
4, 0.285941, 1, 0, 0.501722,0.0019146)    );
  // itree = 355
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344037,-0.0151468) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.897152,0.00379265) , 
2, 37617.2, 1, 0, 0.615863,-0.022661) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403977,0.00799216) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500798,-0.00356732) , 
1, 3.2381, 1, 0, 0.453971,0.00527098) , 
1, 1.33333, 1, 0, 0.496244,-0.00202253)    );
  // itree = 356
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561702,0.00313581) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.370256,-0.00661146) , 
6, 1.98589, 1, 0, 0.520222,0.00205507) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534014,0.00185818) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.200535,-0.030637) , 
6, 0.947789, 1, 0, 0.347305,-0.0322691) , 
7, 1.29221, 1, 0, 0.497872,-0.00238157)    );
  // itree = 357
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4156,0.00928227) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493521,-0.00133606) , 
7, -0.999308, 1, 0, 0.478852,0.00119285) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506667,0.0499061) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.874172,0.0101189) , 
4, 0.229425, 1, 0, 0.752212,0.0520243) , 
0, 96458, 1, 0, 0.50349,0.00577427)    );
  // itree = 358
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495398,0.00238076) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481094,-0.0100622) , 
1, 3.33333, 1, 0, 0.490349,-0.00283246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.80137,0.0356438) , 
1, 14.7619, 1, 0, 0.499402,-0.0007053)    );
  // itree = 359
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.106383,-0.0326606) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541703,-0.00284147) , 
8, -0.0953694, 1, 0, 0.519151,-0.00848676) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333333,0.0459623) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455972,0.0075672) , 
7, -1.56218, 1, 0, 0.443058,0.0216977) , 
8, 0.0222554, 1, 0, 0.499287,-0.000607207)    );
  // itree = 360
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329173,0.0022532) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.886508,-0.0146714) , 
5, 4806.47, 1, 0, 0.478427,-0.00032872) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.783626,0.0289585) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.917647,0.0092021) , 
5, 12768.3, 1, 0, 0.85044,0.0394802) , 
0, 132186, 1, 0, 0.503567,0.0023615)    );
  // itree = 361
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.239437,0.0147006) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602263,0.000741385) , 
2, 25442.1, 1, 0, 0.504127,0.0105897) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519017,-0.00122887) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49256,-0.0170154) , 
6, 1.65435, 1, 0, 0.509824,-0.012806) , 
1, 4, 1, 0, 0.506294,0.0016898)    );
  // itree = 362
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38983,-0.00813861) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557065,0.00748594) , 
7, -1.21734, 1, 0, 0.502752,0.00556678) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521875,-0.00380491) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.142857,-0.0341216) , 
8, 0.0791842, 1, 0, 0.498534,-0.0116694) , 
7, -0.135967, 1, 0, 0.500408,-0.00401354)    );
  // itree = 363
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.934477,0.0220955) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432241,-0.00435637) , 
6, 0.41653, 1, 0, 0.500317,-0.00532453) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.406015,0.0287287) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384,0.0121627) , 
7, 0.171227, 1, 0, 0.395349,0.0452164) , 
6, 3.66018, 1, 0, 0.494887,-0.00270982)    );
  // itree = 364
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52,-0.0027488) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414495,0.00600367) , 
8, 0.0244739, 1, 0, 0.493303,-0.00133111) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.773684,-0.0413376) , 
0, 170088, 1, 0, 0.503867,-0.00371253)    );
  // itree = 365
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469327,-0.00170544) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.487748,0.0113275) , 
0, 58150.9, 1, 0, 0.472803,0.00162888) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.707143,-0.0597674) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.826531,-0.0116627) , 
1, 4.85714, 1, 0, 0.788018,-0.0446318) , 
4, 0.342956, 1, 0, 0.500301,-0.00240673)    );
  // itree = 366
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399189,-0.00777794) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489933,-0.0263324) , 
1, 5.33333, 1, 0, 0.420233,-0.0239671) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514226,0.00501188) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545129,-0.00396568) , 
1, 4, 1, 0, 0.525621,0.00484315) , 
7, -0.714948, 1, 0, 0.498915,-0.00245742)    );
  // itree = 367
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.107914,-0.00703112) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.45,0.0406684) , 
4, 0.0800209, 1, 0, 0.27957,0.0325492) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525088,-0.00230972) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.130435,-0.033385) , 
8, 0.0996418, 1, 0, 0.511583,-0.00661357) , 
7, -1.85788, 1, 0, 0.498596,-0.00442127)    );
  // itree = 368
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488543,0.000609365) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.30597,0.0207257) , 
6, 4.67251, 1, 0, 0.483258,0.00268119) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.84106,0.000530249) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.892405,0.0458987) , 
7, 0.0293814, 1, 0, 0.867314,0.0368785) , 
4, 0.361902, 1, 0, 0.50729,0.00482111)    );
  // itree = 369
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542533,-0.00637477) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466912,0.0142027) , 
0, 55796.2, 1, 0, 0.53392,-0.0080369) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474197,0.00745586) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335165,-0.0170249) , 
6, 3.89551, 1, 0, 0.464624,0.0103141) , 
1, 2.95238, 1, 0, 0.497515,0.00160365)    );
  // itree = 370
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472479,-0.00659566) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.798319,0.0271553) , 
3, 0.047619, 1, 0, 0.496224,-0.0106429) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221374,-0.0340464) , 
6, 4.85509, 1, 0, 0.489066,-0.0124445)    );
  // itree = 371
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482197,-0.000340244) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503618,0.00960501) , 
7, -0.431799, 1, 0, 0.496061,0.0133683) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513514,-0.0380109) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.891566,0.00740328) , 
4, 0.266478, 1, 0, 0.713376,-0.0395476) , 
0, 132186, 1, 0, 0.509679,0.0100525)    );
  // itree = 372
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555714,-0.00506258) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.209323,0.0142657) , 
6, 0.836738, 1, 0, 0.341317,0.0148808) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.620499,-0.0196211) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550696,0.00189555) , 
1, 1.38095, 1, 0, 0.566265,-0.00636162) , 
4, 0.0575411, 1, 0, 0.484825,0.00132904)    );
  // itree = 373
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552214,0.000805881) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262997,-0.023142) , 
6, 1.62869, 1, 0, 0.528076,-0.00263307) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379261,0.00110033) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323718,0.0286134) , 
8, 0.0207628, 1, 0, 0.362205,0.0195225) , 
6, 1.99247, 1, 0, 0.49392,0.00192916)    );
  // itree = 374
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577617,0.000116737) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349135,-0.00857511) , 
6, 1.60715, 1, 0, 0.512358,-0.00541671) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512438,0.0225836) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247273,0.00546739) , 
6, 0.951582, 1, 0, 0.359244,0.0259714) , 
7, 1.5737, 1, 0, 0.498148,-0.00250372)    );
  // itree = 375
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394628,-0.00989273) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.150407,0.0172624) , 
1, 3.33333, 1, 0, 0.34514,-0.0158196) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.476636,0.0112171) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562422,-0.00123859) , 
7, -0.987144, 1, 0, 0.546101,0.00233226) , 
4, 0.0384167, 1, 0, 0.498738,-0.00194581)    );
  // itree = 376
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.240119,0.00146909) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396487,0.0137157) , 
2, 31147.1, 1, 0, 0.29841,0.015241) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.598793,-0.00916556) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696272,0.00330074) , 
7, -0.719146, 1, 0, 0.673484,0.000353864) , 
2, 43680, 1, 0, 0.512264,0.00675289)    );
  // itree = 377
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334802,0.00980024) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38587,0.0463482) , 
0, 41612.9, 1, 0, 0.357664,0.04502) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.670578,0.00539796) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464212,-0.00398849) , 
1, 1.33333, 1, 0, 0.517873,-0.00289253) , 
8, -0.0555145, 1, 0, 0.504701,0.00104667)    );
  // itree = 378
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264887,0.00546704) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72,0.0346712) , 
2, 67719.9, 1, 0, 0.408708,0.0261272) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528694,-0.00443094) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281879,0.0235089) , 
7, 2.18399, 1, 0, 0.520203,-0.00782768) , 
7, -1.26982, 1, 0, 0.504462,-0.00303374)    );
  // itree = 379
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.449057,0.0134688) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314709,-0.013932) , 
4, 0.0148498, 1, 0, 0.345884,-0.0174139) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570572,0.00660115) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.416116,-0.00959233) , 
7, 1.00018, 1, 0, 0.540775,0.0070519) , 
4, 0.0383621, 1, 0, 0.496842,0.00153671)    );
  // itree = 380
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.36699,-0.00560459) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442308,0.00573154) , 
7, -0.714948, 1, 0, 0.422884,0.00664865) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518519,-0.020308) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.938172,-0.00723121) , 
5, 5811.28, 1, 0, 0.810861,-0.0234751) , 
4, 0.266795, 1, 0, 0.504741,0.000293032)    );
  // itree = 381
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.645629,-0.000929445) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.402778,0.0185527) , 
6, 1.02794, 1, 0, 0.615596,0.00387846) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.246637,-0.0178314) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341275,-0.00326736) , 
1, 1.47619, 1, 0, 0.321412,-0.0166403) , 
6, 1.1867, 1, 0, 0.491461,-0.00477968)    );
  // itree = 382
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.446154,0.0186755) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385797,-0.00400318) , 
4, 0.0112543, 1, 0, 0.387874,-0.00692841) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.932449,0.019045) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616495,-0.00551657) , 
6, 1.98961, 1, 0, 0.81583,0.00903354) , 
4, 0.228711, 1, 0, 0.49833,-0.00280859)    );
  // itree = 383
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399103,0.0242029) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564632,0.0038298) , 
7, -1.53377, 1, 0, 0.548611,0.0139541) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457378,-0.0111348) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325871,0.0126331) , 
7, 1.28848, 1, 0, 0.437892,-0.0147775) , 
1, 2.7619, 1, 0, 0.488738,-0.00158288)    );
  // itree = 384
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517292,0.00515295) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421159,-0.00128156) , 
0, 45724.4, 1, 0, 0.488154,0.0068877) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.853081,0.0270418) , 
0, 170086, 1, 0, 0.503231,0.00863109)    );
  // itree = 385
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549451,0.00508724) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.365411,-0.00416518) , 
1, 2.66667, 1, 0, 0.460009,0.0022886) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.794562,0.0234617) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.983673,0.0211957) , 
5, 11012, 1, 0, 0.875,0.0353544) , 
4, 0.323856, 1, 0, 0.507797,0.00609626)    );
  // itree = 386
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.369553,0.001132) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.902597,0.043004) , 
2, 147967, 1, 0, 0.391811,0.00501231) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.765182,-0.0245034) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.837209,0.00129485) , 
4, 0.326075, 1, 0, 0.796154,-0.0219034) , 
4, 0.228394, 1, 0, 0.497193,-0.0020026)    );
  // itree = 387
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.251435,-0.0129645) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432386,-0.00214412) , 
4, 0.0384762, 1, 0, 0.390823,-0.011303) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.673575,-0.0321744) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.856195,0.0165991) , 
7, -0.916726, 1, 0, 0.824066,0.00972316) , 
2, 87360, 1, 0, 0.488034,-0.00658512)    );
  // itree = 388
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432836,-0.02692) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376761,-0.00596452) , 
0, 33769, 1, 0, 0.394737,-0.0376252) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515364,2.63646e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.257485,-0.0183506) , 
6, 4.67251, 1, 0, 0.505987,-0.00159388) , 
4, 0.0199047, 1, 0, 0.496707,-0.00459949)    );
  // itree = 389
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.34199,0.00613879) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.620155,-0.0332147) , 
5, 4860.18, 1, 0, 0.352081,0.0120095) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.769231,-0.033434) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.923841,0.000272944) , 
4, 0.147385, 1, 0, 0.904866,-0.00693368) , 
5, 5387.48, 1, 0, 0.506386,0.00672171)    );
  // itree = 390
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.246269,-0.0190966) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392743,-0.00188032) , 
7, -0.987102, 1, 0, 0.36455,-0.0117041) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.879032,0.0274135) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.784437,-0.000925235) , 
1, 3.66667, 1, 0, 0.816862,0.0127656) , 
4, 0.209254, 1, 0, 0.497362,-0.00451914)    );
  // itree = 391
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.179389,-0.0232279) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47077,0.00371563) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.833046,-0.0101055) , 
4, 0.323848, 1, 0, 0.514721,0.00555998) , 
8, -0.0795992, 1, 0, 0.497327,0.00348172)    );
  // itree = 392
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.279352,0.0378083) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474771,-0.00515596) , 
7, -1.85788, 1, 0, 0.464293,-0.00754218) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669643,0.0313835) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.912698,-0.0127456) , 
5, 14100.5, 1, 0, 0.757143,0.042934) , 
0, 121727, 1, 0, 0.484971,-0.0039782)    );
  // itree = 393
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535435,0.000639825) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.43662,0.0266851) , 
6, 2.24698, 1, 0, 0.530546,0.0041668) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353933,-0.0171261) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319728,0.0141909) , 
7, 1.00455, 1, 0, 0.346549,-0.0243503) , 
6, 2.60863, 1, 0, 0.505415,0.000271864)    );
  // itree = 394
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52986,0.00114445) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456,-0.00902643) , 
7, 0.919863, 1, 0, 0.516424,-0.00164609) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.255952,0.0321079) , 
7, 2.13891, 1, 0, 0.507634,0.00029271)    );
  // itree = 395
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328831,0.0028254) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266667,-0.0235352) , 
3, 0.047619, 1, 0, 0.326461,0.00480034) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.728682,-0.0493336) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.877956,-0.0159481) , 
8, -0.0299147, 1, 0, 0.85341,-0.0298777) , 
5, 4806.47, 1, 0, 0.488258,-0.00584737)    );
  // itree = 396
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383493,-0.00871346) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396328,0.0023489) , 
7, 0.106013, 1, 0, 0.389685,-0.00795619) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.850207,0.0080735) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.795556,0.0338348) , 
8, 0.0284785, 1, 0, 0.839899,0.022352) , 
4, 0.247772, 1, 0, 0.496423,-0.000770633)    );
  // itree = 397
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.324468,-0.00276182) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68589,0.00914482) , 
4, 0.0763838, 1, 0, 0.528786,0.00731617) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.218487,0.00276904) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495575,-0.0192068) , 
4, 0.0784723, 1, 0, 0.353448,-0.015858) , 
7, 1.28989, 1, 0, 0.504481,0.00410381)    );
  // itree = 398
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480274,-0.00141005) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.809877,-0.0273847) , 
4, 0.342346, 1, 0, 0.510031,-0.00633591) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.16,0.000917139) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.663102,0.0330608) , 
5, 2338.4, 1, 0, 0.363636,0.0302814) , 
7, 1.57018, 1, 0, 0.496362,-0.00291691)    );
  // itree = 399
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296754,0.0178965) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376274,0.00108682) , 
5, 578.913, 1, 0, 0.346466,0.0184538) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.60592,0.000657003) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330396,-0.0336611) , 
7, 1.57075, 1, 0, 0.58658,-0.00362904) , 
4, 0.0574622, 1, 0, 0.503024,0.00405543)    );
  // itree = 400
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348,0.024221) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528874,-0.00139387) , 
7, -1.83821, 1, 0, 0.519324,-0.000800939) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.162791,0.0438298) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351145,0.017909) , 
4, 0.0617701, 1, 0, 0.257692,0.043437) , 
8, 0.0831569, 1, 0, 0.505706,0.00150173)    );
  // itree = 401
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.156627,-0.0301568) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381356,-0.00439734) , 
4, 0.0572603, 1, 0, 0.288557,-0.0288026) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546523,-0.000118901) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358462,-0.00995829) , 
7, 1.2556, 1, 0, 0.520224,-0.00322723) , 
7, -1.55853, 1, 0, 0.501782,-0.00526313)    );
  // itree = 402
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546229,-0.00172761) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495596,0.0113605) , 
1, 2.95238, 1, 0, 0.519517,0.00890022) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.449132,-0.0138024) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338235,0.0109913) , 
6, 3.2413, 1, 0, 0.440503,-0.0242179) , 
7, 0.436653, 1, 0, 0.49176,-0.00273372)    );
  // itree = 403
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354054,-0.019143) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305316,-0.00518306) , 
4, 0.0194078, 1, 0, 0.315551,-0.0202946) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57641,0.00682094) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.790164,-0.00653782) , 
0, 124442, 1, 0, 0.596594,0.0112233) , 
4, 0.0574647, 1, 0, 0.497396,9.86071e-05)    );
  // itree = 404
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421112,0.000372105) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525088,-0.0154999) , 
7, -1.02843, 1, 0, 0.472382,-0.0163956) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292326,-0.00345875) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.714465,0.00988717) , 
2, 49322.4, 1, 0, 0.500463,0.00455852) , 
7, -0.418817, 1, 0, 0.490657,-0.0027588)    );
  // itree = 405
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.134752,-0.0414081) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48358,-0.00163756) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.773481,0.0225108) , 
1, 13.2857, 1, 0, 0.494421,-0.00169219) , 
7, -2.12598, 1, 0, 0.48424,-0.00373489)    );
  // itree = 406
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500834,7.27972e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.232184,-0.0210228) , 
6, 2.68288, 1, 0, 0.475594,-0.00442017) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.596491,0.0300333) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.900524,0.00417637) , 
4, 0.306127, 1, 0, 0.756906,0.0299432) , 
3, 0.047619, 1, 0, 0.495994,-0.00192827)    );
  // itree = 407
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532418,0.00498082) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535433,-0.0182709) , 
7, 0.5321, 1, 0, 0.532626,0.00676358) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28786,0.00346949) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.70364,0.0270659) , 
2, 55524, 1, 0, 0.462209,0.0263229) , 
7, 0.710555, 1, 0, 0.513455,0.0120888)    );
  // itree = 408
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471523,-0.000568144) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.115044,-0.0189053) , 
1, 2.66667, 1, 0, 0.338028,-0.0146123) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533908,0.00304005) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.95,0.0401407) , 
2, 174720, 1, 0, 0.557884,0.00858019) , 
4, 0.039181, 1, 0, 0.505075,0.00300937)    );
  // itree = 409
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494685,0.00030074) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537856,-0.0100752) , 
0, 60729.6, 1, 0, 0.503693,-0.00349211) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293785,0.029101) , 
7, 2.13523, 1, 0, 0.496337,-0.00143493)    );
  // itree = 410
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.342932,0.00664432) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.17474,-0.00956892) , 
8, 0.0294309, 1, 0, 0.303859,0.00781384) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.720165,-0.00803071) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312821,-0.0274526) , 
6, 3.89904, 1, 0, 0.686818,-0.0181016) , 
4, 0.0959493, 1, 0, 0.49117,-0.00486184)    );
  // itree = 411
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515056,-0.00231821) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486895,0.0122254) , 
7, 0.706342, 1, 0, 0.507796,0.00326135) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230016,-0.0181512) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806738,-0.00184094) , 
4, 0.209582, 1, 0, 0.506372,-0.0220619) , 
0, 55866.5, 1, 0, 0.507463,-0.00267008)    );
  // itree = 412
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.444089,-0.00163507) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.869455,0.0140837) , 
4, 0.285347, 1, 0, 0.523393,0.00109179) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.194444,0.00444577) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.662379,0.0206653) , 
5, 2082.95, 1, 0, 0.400283,0.0259439) , 
7, 1.28345, 1, 0, 0.50577,0.00464928)    );
  // itree = 413
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423349,0.017503) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542857,-0.0223322) , 
1, 8.42857, 1, 0, 0.440283,0.0233014) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477064,0.0116894) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527181,-0.00294632) , 
4, 0.0193969, 1, 0, 0.523182,-0.00291828) , 
7, -0.979707, 1, 0, 0.507078,0.00217513)    );
  // itree = 414
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.159398,-0.0151007) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54472,0.00299794) , 
2, 21881.2, 1, 0, 0.484485,0.000382869) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.378947,0.0328633) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.886414,0.0116562) , 
5, 5466.19, 1, 0, 0.735524,0.0361418) , 
1, 9, 1, 0, 0.51727,0.00505279)    );
  // itree = 415
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.36056,0.00735131) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.712623,-0.00388784) , 
4, 0.0957635, 1, 0, 0.532277,0.00541201) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582697,0.00461983) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38107,-0.013566) , 
1, 1.09524, 1, 0, 0.430348,-0.0170734) , 
8, 0.0157929, 1, 0, 0.499193,-0.00188643)    );
  // itree = 416
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555305,0.00471795) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4756,-0.00367294) , 
1, 2.66667, 1, 0, 0.513043,0.00171579) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419753,0.0269239) , 
6, 3.89551, 1, 0, 0.508471,0.0046231)    );
  // itree = 417
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235687,-0.0129585) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.637838,0.000406026) , 
2, 38497.3, 1, 0, 0.482492,-0.0118932) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.425197,0.0155066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541458,0.00116065) , 
4, 0.0388948, 1, 0, 0.515835,0.0107625) , 
7, 0.14951, 1, 0, 0.497808,-0.00148637)    );
  // itree = 418
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.987302,0.0501279) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507333,-0.00313276) , 
6, 0.305236, 1, 0, 0.548687,-0.00322089) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.259358,-0.00503759) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394737,0.0105174) , 
8, -0.0224613, 1, 0, 0.357562,0.0145942) , 
6, 1.65807, 1, 0, 0.496811,0.00161453)    );
  // itree = 419
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545611,0.00845784) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.318072,-0.0121557) , 
8, 0.0394486, 1, 0, 0.511135,0.0117647) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354839,-0.0305405) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48535,-0.00395542) , 
4, 0.020225, 1, 0, 0.474805,-0.01405) , 
7, 0.141817, 1, 0, 0.494545,-2.37369e-05)    );
  // itree = 420
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308625,-0.0033339) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.276206,-0.0219909) , 
4, 0.0761997, 1, 0, 0.301733,-0.0170532) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.773101,0.0101527) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697731,-0.00784789) , 
1, 3.66667, 1, 0, 0.730978,-0.000496694) , 
4, 0.114384, 1, 0, 0.48997,-0.00979266)    );
  // itree = 421
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555556,-0.00149101) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489755,0.00781215) , 
1, 2.95238, 1, 0, 0.521703,0.00586234) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.118644,-0.0349099) , 
8, 0.102068, 1, 0, 0.507478,0.00421075)    );
  // itree = 422
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472701,-0.00300368) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.430199,-0.0283549) , 
0, 75464.5, 1, 0, 0.469446,-0.0104635) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.675824,0.00638725) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.938356,0.0413585) , 
4, 0.305884, 1, 0, 0.792683,0.0322225) , 
0, 121725, 1, 0, 0.491039,-0.00761194)    );
  // itree = 423
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387209,-0.0127154) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.138889,0.0174914) , 
1, 3.33333, 1, 0, 0.337361,-0.0217434) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567854,0.00789513) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.195122,-0.0337807) , 
6, 4.81051, 1, 0, 0.555789,0.0122449) , 
4, 0.0384374, 1, 0, 0.507588,0.00474461)    );
  // itree = 424
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0949721,-0.0314851) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555187,0.0024629) , 
8, -0.0999533, 1, 0, 0.533474,0.0033533) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337976,0.0157105) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.906977,-0.0249037) , 
5, 9340.95, 1, 0, 0.432663,0.0249592) , 
8, 0.0244739, 1, 0, 0.507865,0.00884185)    );
  // itree = 425
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382786,-0.0141023) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515672,-0.000259019) , 
7, -1.00217, 1, 0, 0.491424,-0.00548761) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.704225,-0.0400388) , 
4, 0.380932, 1, 0, 0.49749,-0.00745536)    );
  // itree = 426
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.630722,-0.0039792) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.425414,0.00509362) , 
1, 1.42857, 1, 0, 0.483616,0.0045815) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475309,-0.0351869) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.823529,-0.00487016) , 
4, 0.273988, 1, 0, 0.6825,-0.0363899) , 
1, 10.6667, 1, 0, 0.499697,0.00126868)    );
  // itree = 427
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.446335,0.0172126) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289855,-0.00478637) , 
0, 48814.3, 1, 0, 0.391341,0.0253064) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.502252,-0.00811034) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696063,0.0143721) , 
0, 73362.9, 1, 0, 0.533283,-0.00970558) , 
4, 0.0384374, 1, 0, 0.500778,-0.00168768)    );
  // itree = 428
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394978,-0.0048134) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.904211,0.00825625) , 
4, 0.209808, 1, 0, 0.519117,-0.00609076) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.270335,0.0236403) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.481073,-0.0031787) , 
1, 2.7619, 1, 0, 0.397338,0.0190842) , 
6, 1.98961, 1, 0, 0.493231,-0.000739369)    );
  // itree = 429
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513769,4.02052e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580298,0.0120522) , 
7, 0.0175992, 1, 0, 0.535842,0.00838653) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.402778,-0.017437) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483926,0.00576083) , 
8, 0.00361878, 1, 0, 0.439359,-0.0152737) , 
7, 0.721737, 1, 0, 0.510299,0.00212267)    );
  // itree = 430
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.138122,-0.00856702) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.465257,0.0324378) , 
8, -0.0908741, 1, 0, 0.349609,0.0346785) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55516,0.00543748) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500201,-0.00482847) , 
8, 0.000296459, 1, 0, 0.524439,-0.000381269) , 
8, -0.0517775, 1, 0, 0.506436,0.00322907)    );
  // itree = 431
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523345,-0.000943841) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423377,0.0180235) , 
6, 2.47217, 1, 0, 0.509303,0.00360881) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511777,-0.0221224) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482163,-0.00474629) , 
7, 0.414959, 1, 0, 0.48828,-0.0177909) , 
7, 0.14194, 1, 0, 0.4998,-0.00606425)    );
  // itree = 432
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366667,-0.00938431) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50939,0.0110878) , 
8, -0.0199524, 1, 0, 0.46868,0.0128873) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315789,0.0233043) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500162,-0.00813952) , 
8, -0.0661916, 1, 0, 0.489446,-0.0142497) , 
7, -0.429463, 1, 0, 0.482104,-0.00465488)    );
  // itree = 433
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411857,0.00602417) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.784223,-0.00434345) , 
2, 76994.6, 1, 0, 0.527818,0.0080382) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28,0.00204652) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.647963,-0.0102704) , 
2, 43680, 1, 0, 0.490334,-0.00890015) , 
7, 0.144671, 1, 0, 0.510904,0.000395122)    );
  // itree = 434
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.732839,0.0023581) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358268,0.0389602) , 
6, 1.81266, 1, 0, 0.661411,0.0259232) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.213287,-0.0165987) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458175,0.000393995) , 
4, 0.0199542, 1, 0, 0.439333,-0.00272153) , 
1, 1.28571, 1, 0, 0.49792,0.00483538)    );
  // itree = 435
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360096,-0.00736859) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.771474,0.00905246) , 
2, 72816.9, 1, 0, 0.47341,-0.00859739) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.919118,0.0527851) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954887,-0.0169406) , 
4, 0.247642, 1, 0, 0.936803,0.0415726) , 
2, 170526, 1, 0, 0.498975,-0.0058296)    );
  // itree = 436
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.152727,-0.0194263) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341317,0.0067982) , 
2, 15857.7, 1, 0, 0.322662,0.0102875) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536977,-0.0163047) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.727564,-0.00617273) , 
8, -0.0357549, 1, 0, 0.700412,-0.0142337) , 
2, 55524, 1, 0, 0.488817,-0.000498287)    );
  // itree = 437
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340619,0.0237808) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.412354,-0.00484676) , 
5, 559.93, 1, 0, 0.378049,0.0233807) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561952,-0.00170302) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292373,0.0243405) , 
8, 0.0762156, 1, 0, 0.545572,-0.000945356) , 
4, 0.0384111, 1, 0, 0.507353,0.00460438)    );
  // itree = 438
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512387,0.00443334) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420382,-0.00394171) , 
7, 0.718509, 1, 0, 0.487732,0.00490816) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.476852,-0.0331084) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.976331,0.0180248) , 
5, 10770.9, 1, 0, 0.696104,-0.0335588) , 
3, 0.047619, 1, 0, 0.503549,0.00198825)    );
  // itree = 439
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351619,-0.00389792) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528139,0.00540799) , 
4, 0.0384762, 1, 0, 0.485252,0.00576175) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463158,-0.0233998) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.841584,-0.0034335) , 
2, 120037, 1, 0, 0.658163,-0.0278495) , 
1, 10.6667, 1, 0, 0.498893,0.00311019)    );
  // itree = 440
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286426,-0.0102137) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.387755,0.0124459) , 
7, -0.148698, 1, 0, 0.34212,0.00579692) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58562,-0.00650706) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.209302,-0.0365386) , 
6, 4.81643, 1, 0, 0.570909,-0.0154082) , 
4, 0.0575015, 1, 0, 0.490655,-0.00796992)    );
  // itree = 441
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319749,0.00829966) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510309,-0.032852) , 
5, 2338.48, 1, 0, 0.340414,0.0115241) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379597,-0.00858738) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.81067,0.00512412) , 
4, 0.204146, 1, 0, 0.585169,-0.00629162) , 
4, 0.0574254, 1, 0, 0.497805,6.75974e-05)    );
  // itree = 442
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514986,-0.0228612) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393841,-0.000511062) , 
1, 1.33333, 1, 0, 0.421611,-0.0134188) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591753,-0.00325972) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489861,0.00746227) , 
8, 0.011338, 1, 0, 0.534395,0.00552545) , 
8, -0.012732, 1, 0, 0.497769,-0.000626609)    );
  // itree = 443
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52137,-0.00239253) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534103,0.00777555) , 
7, 0.695192, 1, 0, 0.524006,-0.000385354) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.232082,-0.023646) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340909,0.00209197) , 
1, 4.71429, 1, 0, 0.265882,-0.0308262) , 
7, 1.56478, 1, 0, 0.502188,-0.00295841)    );
  // itree = 444
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544667,-0.00677028) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283582,0.016284) , 
6, 3.20832, 1, 0, 0.529639,-0.0124394) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47541,0.00227801) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.443548,0.0154966) , 
7, 0.426993, 1, 0, 0.46315,0.0138449) , 
1, 2.7619, 1, 0, 0.4947,0.00137241)    );
  // itree = 445
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360294,-0.0187833) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506173,0.0275132) , 
4, 0.0104037, 1, 0, 0.453826,0.0305936) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5,-0.00354363) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.277372,0.0210088) , 
7, 2.13543, 1, 0, 0.493487,-0.00584753) , 
4, 0.0194678, 1, 0, 0.490518,-0.00311913)    );
  // itree = 446
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38083,0.000295627) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.782383,-0.012395) , 
4, 0.209654, 1, 0, 0.480317,-0.00450617) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581006,0.0306404) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.808824,-0.00776553) , 
4, 0.272281, 1, 0, 0.70235,0.0304006) , 
1, 10.6667, 1, 0, 0.497133,-0.00186245)    );
  // itree = 447
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514469,-0.00360476) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40779,0.012021) , 
0, 41113.1, 1, 0, 0.483745,0.00189225) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431624,-0.0234222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.832117,0.0257904) , 
3, 0.047619, 1, 0, 0.579515,-0.0206512) , 
0, 73362.9, 1, 0, 0.497652,-0.00138118)    );
  // itree = 448
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.307517,-0.021608) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528667,-0.000989138) , 
8, -0.0388151, 1, 0, 0.4976,-0.00742958) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355422,-0.0165064) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491557,0.00922771) , 
4, 0.0199271, 1, 0, 0.478754,0.0128893) , 
7, 0.42686, 1, 0, 0.490798,-9.56546e-05)    );
  // itree = 449
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375822,0.00184051) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.818102,0.0166273) , 
4, 0.196011, 1, 0, 0.484365,0.00991065) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.740385,-0.0397615) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.86758,0.00730326) , 
1, 7.42857, 1, 0, 0.805621,-0.0269214) , 
4, 0.342881, 1, 0, 0.511453,0.00680495)    );
  // itree = 450
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328751,-0.00526758) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605138,0.00176212) , 
4, 0.0574647, 1, 0, 0.509324,-0.00233577) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286713,-0.0410811) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.188406,0.00243921) , 
6, 1.1835, 1, 0, 0.238434,-0.0422289) , 
7, 1.8502, 1, 0, 0.494419,-0.00453079)    );
  // itree = 451
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496444,0.00118019) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.101293,-0.0292456) , 
1, 2.66667, 1, 0, 0.339332,-0.0204532) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559837,0.0130439) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54073,-0.00165252) , 
7, -0.140498, 1, 0, 0.549234,0.00965687) , 
4, 0.0384374, 1, 0, 0.500399,0.00265159)    );
  // itree = 452
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41561,-0.00730412) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.566341,0.0068781) , 
7, -0.88011, 1, 0, 0.523184,0.00595548) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.663569,0.00831169) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266667,-0.0195416) , 
6, 0.885663, 1, 0, 0.430545,-0.0164007) , 
7, 0.70925, 1, 0, 0.498464,-1.01465e-05)    );
  // itree = 453
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.369099,0.0162569) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.756494,-0.00718851) , 
4, 0.228549, 1, 0, 0.465323,0.0233133) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544471,-0.00704942) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516204,0.00523944) , 
7, -0.18257, 1, 0, 0.522303,0.00576966) , 
7, -0.714948, 1, 0, 0.508438,0.0100385)    );
  // itree = 454
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.127886,-0.0236006) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551968,-0.00376414) , 
2, 21296, 1, 0, 0.489384,-0.0144296) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.417367,0.0259509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613267,-0.00329619) , 
1, 3.85714, 1, 0, 0.552768,0.0156021) , 
0, 58150.9, 1, 0, 0.504124,-0.00744577)    );
  // itree = 455
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292308,-0.0136116) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.786036,0.00375344) , 
4, 0.15311, 1, 0, 0.486906,-0.0167546) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363412,0.00993599) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.906456,-0.00425696) , 
5, 5413.1, 1, 0, 0.511302,0.0170881) , 
7, -0.140498, 1, 0, 0.500397,0.00195961)    );
  // itree = 456
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484758,0.00363814) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.603175,-0.0202084) , 
1, 12.8571, 1, 0, 0.487856,0.00654435) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.759162,-0.0325297) , 
0, 170086, 1, 0, 0.498203,0.0043077)    );
  // itree = 457
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489204,0.00685112) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48669,-0.00336636) , 
7, -0.428222, 1, 0, 0.487536,-9.05496e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.804734,-0.0466231) , 
0, 190739, 1, 0, 0.498294,-0.00229144)    );
  // itree = 458
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321758,-0.00851383) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.741399,-0.00382029) , 
2, 58265.6, 1, 0, 0.503857,-0.0149649) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32549,0.0133886) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439353,0.00101077) , 
4, 0.0388952, 1, 0, 0.410231,0.0100004) , 
7, 0.993988, 1, 0, 0.485247,-0.0100027)    );
  // itree = 459
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27907,-0.021042) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546705,0.00075332) , 
4, 0.03845, 1, 0, 0.481771,-0.0109804) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340081,0.00707696) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579539,-0.00129369) , 
4, 0.0578733, 1, 0, 0.494037,0.00443246) , 
7, -0.138223, 1, 0, 0.488464,-0.00257034)    );
  // itree = 460
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527001,0.00864185) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.261111,-0.0154211) , 
8, 0.0625038, 1, 0, 0.499126,0.0142472) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411685,0.00529588) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529412,-0.00847292) , 
4, 0.0386747, 1, 0, 0.503578,-0.0101613) , 
7, -0.427901, 1, 0, 0.502071,-0.0018968)    );
  // itree = 461
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669173,0.00624259) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.228916,-0.0242466) , 
1, 1.52381, 1, 0, 0.382199,-0.0358291) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492137,0.00214344) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.736695,-0.0140848) , 
0, 117592, 1, 0, 0.510788,0.00233831) , 
4, 0.0199411, 1, 0, 0.501086,-0.000541396)    );
  // itree = 462
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492169,0.00976227) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.929648,-0.0485685) , 
5, 16153.9, 1, 0, 0.523792,0.0177273) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468326,-0.0018817) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.784314,0.0313427) , 
1, 11.1429, 1, 0, 0.488785,-0.000111812) , 
7, 0.149958, 1, 0, 0.507623,0.0094877)    );
  // itree = 463
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.402878,0.00403765) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.378007,-0.0253584) , 
7, -0.517287, 1, 0, 0.386046,-0.0419289) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477364,-0.00808099) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518017,0.00509863) , 
7, -0.429463, 1, 0, 0.504528,0.00197649) , 
4, 0.0198776, 1, 0, 0.494251,-0.00183213)    );
  // itree = 464
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411552,-0.00227612) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.715116,-0.0474776) , 
4, 0.30404, 1, 0, 0.452344,-0.0136317) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.627451,0.0245905) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506882,0.000778432) , 
7, -0.527985, 1, 0, 0.516996,0.00586866) , 
7, -0.704555, 1, 0, 0.500203,0.000803647)    );
  // itree = 465
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350402,0.00120091) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.687604,-0.00752579) , 
4, 0.0955195, 1, 0, 0.510419,-0.00528754) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.278467,0.00407002) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.763848,0.0217169) , 
4, 0.190789, 1, 0, 0.413821,0.0176223) , 
8, 0.0258945, 1, 0, 0.486756,0.00032471)    );
  // itree = 466
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380421,0.0126768) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0828729,-0.0198378) , 
1, 4.04762, 1, 0, 0.348796,0.0240999) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258603,-0.013634) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.720595,0.00382036) , 
4, 0.106477, 1, 0, 0.584104,-0.00381838) , 
4, 0.0575411, 1, 0, 0.503132,0.00578859)    );
  // itree = 467
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498753,0.00193575) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.627418,0.0142847) , 
8, -0.000994795, 1, 0, 0.541307,0.0130068) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534308,0.00123295) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281967,-0.0149399) , 
6, 1.38153, 1, 0, 0.431621,-0.0110594) , 
8, 0.0197938, 1, 0, 0.50903,0.00592488)    );
  // itree = 468
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411883,-0.00504013) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.806324,-0.0392953) , 
4, 0.30404, 1, 0, 0.468875,-0.0170868) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538585,0.00234057) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.176,-0.0362559) , 
7, 2.33875, 1, 0, 0.524575,0.00180912) , 
7, -0.432019, 1, 0, 0.505014,-0.00482682)    );
  // itree = 469
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608966,0.00867995) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47006,-0.00362953) , 
0, 37193.5, 1, 0, 0.557258,0.00934081) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208969,-0.00939503) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.795322,0.0146334) , 
2, 72298.3, 1, 0, 0.353237,-0.00933095) , 
6, 1.65878, 1, 0, 0.500301,0.00412817)    );
  // itree = 470
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518443,-0.00236054) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439189,0.015681) , 
6, 2.60889, 1, 0, 0.508007,-6.42506e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53479,-0.00357828) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319218,-0.0205791) , 
6, 1.98589, 1, 0, 0.488445,-0.0160451) , 
7, -0.140498, 1, 0, 0.497061,-0.00900653)    );
  // itree = 471
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62923,0.00394741) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325039,-0.00820402) , 
6, 1.16663, 1, 0, 0.504568,-0.00235866) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327935,0.0177849) , 
6, 3.89551, 1, 0, 0.495761,-0.000374115)    );
  // itree = 472
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432032,-0.00798867) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.854701,0.00823015) , 
4, 0.285805, 1, 0, 0.512015,-0.0124176) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175978,0.00150052) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.636986,0.0251425) , 
5, 2074.13, 1, 0, 0.383077,0.025176) , 
7, 1.28544, 1, 0, 0.495179,-0.00750883)    );
  // itree = 473
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366941,-0.00912689) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.934932,0.0149203) , 
5, 9035.86, 1, 0, 0.461714,-0.0150003) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501452,0.00533833) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.746114,-0.0292606) , 
4, 0.361442, 1, 0, 0.515796,0.00778678) , 
7, -0.428002, 1, 0, 0.497025,-0.000122256)    );
  // itree = 474
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409201,0.0083875) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470506,-0.0027136) , 
7, -0.997742, 1, 0, 0.459005,-0.00179172) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.637394,0.0188996) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.89313,0.00929786) , 
4, 0.311137, 1, 0, 0.746341,0.0286201) , 
1, 8.85714, 1, 0, 0.494221,0.00193551)    );
  // itree = 475
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565789,-0.0299564) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289575,-0.00181611) , 
1, 1.42857, 1, 0, 0.391728,-0.0355454) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515042,0.000461793) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344828,0.0246008) , 
7, 2.1399, 1, 0, 0.508596,0.00282144) , 
4, 0.0194212, 1, 0, 0.499001,-0.000328533)    );
  // itree = 476
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.685789,0.00189863) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357027,0.0114032) , 
6, 0.951033, 1, 0, 0.570783,0.0118161) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.140504,-0.00845318) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.825175,0.0143861) , 
5, 3922.32, 1, 0, 0.341547,-0.00328293) , 
6, 1.60748, 1, 0, 0.5038,0.00740417)    );
  // itree = 477
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394231,0.00623304) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358209,-0.0392764) , 
7, 0.00167902, 1, 0, 0.376528,-0.0393077) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506628,0.00360371) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.691943,-0.0226712) , 
1, 13.2857, 1, 0, 0.515015,0.00498424) , 
4, 0.0194817, 1, 0, 0.503845,0.00141188)    );
  // itree = 478
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.65928,0.0139833) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439403,-0.00761383) , 
0, 26701.2, 1, 0, 0.479695,-0.00790828) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379213,0.0180407) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.654434,-0.00220227) , 
1, 4.14286, 1, 0, 0.557426,0.0142432) , 
0, 60728.7, 1, 0, 0.495556,-0.00338848)    );
  // itree = 479
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.275552,0.00251458) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.728031,-0.00856715) , 
5, 2850.23, 1, 0, 0.442317,-0.00222444) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.854167,0.0246628) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.846906,-0.00888501) , 
1, 8.71429, 1, 0, 0.85115,0.0196272) , 
4, 0.30428, 1, 0, 0.503119,0.00102539)    );
  // itree = 480
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501595,0.00384113) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544415,-0.00595812) , 
0, 55864.2, 1, 0, 0.511533,0.00356292) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.212121,-0.0415755) , 
7, 2.14312, 1, 0, 0.501777,0.00116888)    );
  // itree = 481
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504746,0.00437048) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.127119,-0.0212162) , 
6, 2.83263, 1, 0, 0.484235,0.0061535) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549419,-0.0433435) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.623737,0.00578485) , 
6, 2.25436, 1, 0, 0.589189,-0.0289973) , 
0, 73362.9, 1, 0, 0.499508,0.00103814)    );
  // itree = 482
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.675862,-0.00304816) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.324528,0.0254105) , 
1, 1.42857, 1, 0, 0.44878,0.0360518) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.293521,-0.00525203) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.646015,0.00590115) , 
4, 0.0738907, 1, 0, 0.511403,0.0024814) , 
4, 0.0194949, 1, 0, 0.506327,0.00520261)    );
  // itree = 483
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423913,-1.592e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283019,-0.0263487) , 
0, 88461.3, 1, 0, 0.418345,-0.00231859) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.915584,-0.00192583) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.841441,0.0204614) , 
1, 3.57143, 1, 0, 0.867903,0.0194988) , 
2, 98644.8, 1, 0, 0.497749,0.00153495)    );
  // itree = 484
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.623431,-0.000446006) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.709122,0.0212343) , 
7, 0.143072, 1, 0, 0.661787,0.0220817) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4632,0.0124655) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.450622,-0.00461149) , 
7, -0.431698, 1, 0, 0.454918,0.00130636) , 
1, 1.47619, 1, 0, 0.509076,0.00674532)    );
  // itree = 485
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511275,0.00139747) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.8,0.028191) , 
1, 14.6667, 1, 0, 0.519486,0.00438738) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.260563,0.0501291) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42236,0.0132005) , 
4, 0.0595731, 1, 0, 0.346535,0.0521557) , 
7, 1.84321, 1, 0, 0.509109,0.00725348)    );
  // itree = 486
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559004,0.00438137) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382456,-0.00918361) , 
6, 3.23275, 1, 0, 0.545973,0.0068468) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380174,-0.0153801) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341615,0.0185416) , 
6, 2.72725, 1, 0, 0.374421,-0.0212347) , 
8, 0.0278999, 1, 0, 0.508502,0.00071322)    );
  // itree = 487
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.135714,-0.000635344) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332362,-0.0239569) , 
4, 0.133225, 1, 0, 0.19273,-0.0221289) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.610561,0.00530274) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540299,-0.00537541) , 
7, 0.426993, 1, 0, 0.585547,0.00269414) , 
2, 28488.3, 1, 0, 0.491611,-0.00324191)    );
  // itree = 488
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530159,0.00386098) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523756,-0.0123864) , 
7, -0.708655, 1, 0, 0.525438,-0.0182758) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475975,0.000466476) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320346,0.0239274) , 
7, 1.56893, 1, 0, 0.462491,0.00494847) , 
1, 2.66667, 1, 0, 0.492299,-0.00604912)    );
  // itree = 489
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421233,0.02027) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492857,-0.0072266) , 
5, 519.771, 1, 0, 0.444444,0.035537) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509387,0.00554366) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496288,-0.00369027) , 
7, -0.142981, 1, 0, 0.502073,0.000472679) , 
4, 0.01941, 1, 0, 0.497109,0.00349317)    );
  // itree = 490
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315756,-0.000618597) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340102,0.0278453) , 
0, 85387.4, 1, 0, 0.317182,0.00222806) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.773973,-0.0232542) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.948441,1.68684e-05) , 
5, 9391.72, 1, 0, 0.867008,-0.0203243) , 
5, 4814.9, 1, 0, 0.49168,-0.0049294)    );
  // itree = 491
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.272431,-0.0182032) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.573617,-0.004663) , 
4, 0.0573406, 1, 0, 0.470358,-0.0205092) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55249,0.00428391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319018,-0.0143139) , 
7, 1.52132, 1, 0, 0.517683,0.0032505) , 
7, -0.424709, 1, 0, 0.500987,-0.00513197)    );
  // itree = 492
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517861,-6.15169e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323729,-0.0110459) , 
6, 2.56182, 1, 0, 0.494624,-0.00287155) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.669856,-0.0284602) , 
1, 13.8095, 1, 0, 0.501752,-0.00484172)    );
  // itree = 493
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54854,-0.000703423) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.18264,0.0109376) , 
6, 0.919277, 1, 0, 0.354725,0.0112603) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.460545,-0.0109017) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.929947,0.00415668) , 
5, 5647.57, 1, 0, 0.752039,-0.00967284) , 
4, 0.152385, 1, 0, 0.50171,0.00351616)    );
  // itree = 494
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531291,0.000558309) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286738,-0.0258341) , 
6, 3.31635, 1, 0, 0.514641,-0.00271965) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381356,0.018184) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.758621,-0.0084229) , 
2, 101363, 1, 0, 0.437693,0.0318615) , 
7, 1.0056, 1, 0, 0.499901,0.0039046)    );
  // itree = 495
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371871,-0.00353155) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.570003,0.00619162) , 
4, 0.038518, 1, 0, 0.526781,0.00771521) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.245614,-0.0112515) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.728395,0.00853605) , 
4, 0.191543, 1, 0, 0.400794,-0.0114997) , 
8, 0.0244739, 1, 0, 0.495691,0.00297358)    );
  // itree = 496
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.330878,-0.00385005) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.821219,0.00816748) , 
4, 0.171629, 1, 0, 0.499396,-0.00124888) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243056,-0.0348339) , 
6, 4.6689, 1, 0, 0.492169,-0.00335268)    );
  // itree = 497
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.265258,-0.00711747) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.849776,0.0165383) , 
2, 27291.6, 1, 0, 0.66085,0.0138293) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.416457,-0.00542864) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534623,0.00608301) , 
0, 58150.9, 1, 0, 0.447278,-0.0051704) , 
1, 1.47619, 1, 0, 0.502656,-0.000243864)    );
  // itree = 498
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.450589,-0.00375912) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616601,-0.0250047) , 
1, 12, 1, 0, 0.459593,-0.0101617) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.887097,0.0318349) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785185,0.00258467) , 
7, -0.0169482, 1, 0, 0.833977,0.024061) , 
4, 0.361927, 1, 0, 0.479285,-0.00836162)    );
  // itree = 499
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448913,0.0111921) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550291,-0.000797245) , 
7, -1.01971, 1, 0, 0.529697,0.00312616) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.365314,0.00861279) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405063,0.0469118) , 
1, 3.80952, 1, 0, 0.379953,0.0419939) , 
7, 1.57699, 1, 0, 0.516741,0.00648927)    );
  // itree = 500
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431095,-0.00868407) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545166,0.00374097) , 
7, -0.810864, 1, 0, 0.517076,0.00173781) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382775,-0.0349147) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.221649,0.00603515) , 
6, 1.1773, 1, 0, 0.305211,-0.0361523) , 
7, 1.57018, 1, 0, 0.5,-0.00131613)    );
  // itree = 501
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320261,0.00136832) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.736929,-0.0110239) , 
5, 1611.51, 1, 0, 0.526966,-0.00860792) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486917,0.00859228) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.183007,-0.0231323) , 
7, 1.85464, 1, 0, 0.469027,0.0133823) , 
1, 2.66667, 1, 0, 0.497017,0.00275892)    );
  // itree = 502
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364486,0.0167657) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.701671,-0.00319799) , 
2, 68364.4, 1, 0, 0.475294,0.022948) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524321,-0.00488303) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375,0.010235) , 
6, 3.89583, 1, 0, 0.516631,-0.00832933) , 
7, -0.702981, 1, 0, 0.506096,-0.000358384)    );
  // itree = 503
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.207469,-0.0166256) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.43385,0.0111324) , 
8, -0.0252024, 1, 0, 0.383333,0.0145956) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319515,-0.00956191) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.765322,-0.000831655) , 
4, 0.158946, 1, 0, 0.538462,-0.0113715) , 
4, 0.0384374, 1, 0, 0.504731,-0.00572537)    );
  // itree = 504
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.436975,-0.0142686) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.171257,0.00335774) , 
6, 1.02407, 1, 0, 0.312815,-0.0168897) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68984,0.010773) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565984,-0.000574722) , 
1, 1.47619, 1, 0, 0.595044,0.00422309) , 
4, 0.0580042, 1, 0, 0.493668,-0.00336056)    );
  // itree = 505
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.301968,-0.00152612) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.814346,0.0119392) , 
2, 37617.2, 1, 0, 0.559898,0.00920215) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41289,-0.00857858) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.792,0.0239361) , 
1, 12.3333, 1, 0, 0.448588,-0.0105438) , 
1, 2.95238, 1, 0, 0.500898,-0.00126409)    );
  // itree = 506
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321171,-0.00179059) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.197183,0.0307134) , 
6, 2.95689, 1, 0, 0.314821,-0.000949139) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.684129,0.0155706) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.831933,-0.00396678) , 
4, 0.277074, 1, 0, 0.746667,0.015869) , 
4, 0.11429, 1, 0, 0.508262,0.00658435)    );
  // itree = 507
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.369398,-0.00245322) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.679105,-0.0297257) , 
4, 0.212492, 1, 0, 0.391408,-0.00912211) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.817771,-0.00658098) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.87,0.0208473) , 
8, 0.0061117, 1, 0, 0.840206,0.00857732) , 
4, 0.247838, 1, 0, 0.497264,-0.00494741)    );
  // itree = 508
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.928371,0.018968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432203,-0.00156499) , 
6, 0.439217, 1, 0, 0.506986,0.000336241) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372951,0.0192295) , 
6, 3.89551, 1, 0, 0.500403,0.00256854)    );
  // itree = 509
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366881,0.0110188) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601484,8.19069e-05) , 
4, 0.0574203, 1, 0, 0.52124,0.00911171) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419737,-0.00354923) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379147,-0.0326396) , 
0, 59126.5, 1, 0, 0.410917,-0.0205646) , 
7, 0.994354, 1, 0, 0.500099,0.00342478)    );
  // itree = 510
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.153488,-0.0177377) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47463,0.0149759) , 
8, -0.0866058, 1, 0, 0.415159,0.0191882) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581296,-0.00241161) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421266,0.00782852) , 
8, 0.0245727, 1, 0, 0.529535,0.00116414) , 
8, -0.0224613, 1, 0, 0.502817,0.00537458)    );
  // itree = 511
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319608,0.0156075) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403285,-0.00572243) , 
5, 569.036, 1, 0, 0.362949,0.0131535) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530999,-0.00767734) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548753,0.0028433) , 
7, 0.141817, 1, 0, 0.539077,-0.00561597) , 
4, 0.0388467, 1, 0, 0.501317,-0.00159203)    );
  // itree = 512
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.413985,-0.00325487) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404878,-0.0210927) , 
1, 5.90476, 1, 0, 0.412596,-0.012682) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.817844,-0.0113538) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.869919,0.0151328) , 
7, -0.563832, 1, 0, 0.854072,0.00977298) , 
4, 0.285868, 1, 0, 0.491967,-0.00864495)    );
  // itree = 513
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475952,-0.0139956) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577536,0.00117006) , 
7, -0.716935, 1, 0, 0.550559,-0.00589167) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38705,0.0177031) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337615,-0.00147121) , 
7, 0.15761, 1, 0, 0.365323,0.0188361) , 
6, 1.76259, 1, 0, 0.504602,0.000243275)    );
  // itree = 514
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.64791,0.0132357) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.443248,-0.00833028) , 
0, 26580.5, 1, 0, 0.476117,-0.0103065) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574468,-0.0182186) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557062,0.0164531) , 
6, 1.01017, 1, 0, 0.560112,0.0215623) , 
0, 58149.8, 1, 0, 0.494339,-0.00339277)    );
  // itree = 515
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404198,-0.0106762) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.96374,0.00285675) , 
5, 4918.1, 1, 0, 0.527288,-0.0228882) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.245408,-0.00470117) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.707917,0.00788726) , 
2, 64281.8, 1, 0, 0.47145,0.00178284) , 
1, 2.95238, 1, 0, 0.497819,-0.00986792)    );
  // itree = 516
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420154,-0.00738802) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551265,0.00378579) , 
7, -0.79782, 1, 0, 0.519596,0.00241506) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.180791,-0.0307557) , 
7, 2.1399, 1, 0, 0.507662,0.000536718)    );
  // itree = 517
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.10989,-0.0246497) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.352838,0.00720619) , 
7, -1.85986, 1, 0, 0.338274,0.0133365) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.755807,-0.011687) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.719243,0.0182735) , 
7, 0.996545, 1, 0, 0.749738,-0.011013) , 
4, 0.152657, 1, 0, 0.497169,0.00393346)    );
  // itree = 518
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.269499,-0.00975493) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.84316,0.00189634) , 
5, 3931.91, 1, 0, 0.482487,-0.0140395) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357986,0.0109287) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.646333,-0.00153129) , 
4, 0.0765537, 1, 0, 0.512088,0.0103913) , 
7, -0.143978, 1, 0, 0.498604,-0.000737511)    );
  // itree = 519
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.691037,0.0134511) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507295,-0.00113949) , 
0, 37756.6, 1, 0, 0.634349,0.0182178) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302504,-0.00315644) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.828283,0.029451) , 
4, 0.361392, 1, 0, 0.350812,-0.00103093) , 
6, 1.1867, 1, 0, 0.513187,0.00999231)    );
  // itree = 520
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491845,0.00720868) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56391,-0.0147054) , 
7, -0.279493, 1, 0, 0.500449,0.00950443) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540741,0.0192523) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470158,-0.00819082) , 
7, 0.00641948, 1, 0, 0.476805,-0.0112856) , 
7, -0.143337, 1, 0, 0.487144,-0.00219428)    );
  // itree = 521
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.989189,0.0555842) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473304,-0.00302633) , 
6, 0.262007, 1, 0, 0.493375,-0.00449837) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32618,-0.0159399) , 
6, 3.89932, 1, 0, 0.485565,-0.00598534)    );
  // itree = 522
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480211,0.0186182) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52109,0.00194323) , 
4, 0.0198916, 1, 0, 0.517398,0.008161) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358916,-0.00539479) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.261261,-0.0358012) , 
0, 48090.4, 1, 0, 0.326316,-0.0304049) , 
7, 1.28916, 1, 0, 0.491257,0.00288506)    );
  // itree = 523
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308209,-0.00528628) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.886216,0.00468528) , 
5, 4517.01, 1, 0, 0.511916,-0.00639653) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.441176,0.0280646) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323887,-0.0178739) , 
8, 0.0142609, 1, 0, 0.399129,0.0239065) , 
7, 1.27972, 1, 0, 0.496537,-0.00226457)    );
  // itree = 524
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512064,-0.00233306) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.427989,0.00579586) , 
8, 0.0153583, 1, 0, 0.485288,0.00032507) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.722222,0.00366732) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.654321,-0.0357131) , 
7, 0.174082, 1, 0, 0.690058,-0.0290631) , 
1, 11.8095, 1, 0, 0.499396,-0.00169966)    );
  // itree = 525
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.378378,0.027574) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.163265,0.0126246) , 
6, 1.43986, 1, 0, 0.285714,0.0352833) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381316,0.000486639) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.794987,-0.00956642) , 
4, 0.190656, 1, 0, 0.522349,-0.00445969) , 
8, -0.0556158, 1, 0, 0.500897,-0.00085677)    );
  // itree = 526
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.947284,0.0308477) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401996,0.000457185) , 
6, 0.415826, 1, 0, 0.482636,0.00577538) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.229412,-0.0086751) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.755282,0.0243064) , 
4, 0.0589095, 1, 0, 0.634146,0.0301767) , 
0, 73369.4, 1, 0, 0.50513,0.00939803)    );
  // itree = 527
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.817674,-0.00659054) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320388,0.0116382) , 
6, 0.907468, 1, 0, 0.551709,0.0113146) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470701,-0.00418311) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302,-0.0263073) , 
8, 0.0332725, 1, 0, 0.438033,-0.0142085) , 
1, 2.66667, 1, 0, 0.491723,-0.00215374)    );
  // itree = 528
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580552,-0.00829826) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368692,0.000903573) , 
6, 1.38153, 1, 0, 0.504614,-0.00994077) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554305,0.00706405) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329897,-0.00439546) , 
7, 1.50674, 1, 0, 0.506189,0.00967856) , 
7, 0.15103, 1, 0, 0.505331,-0.0010132)    );
  // itree = 529
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0467836,0.00496649) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47619,0.034235) , 
5, 2374.46, 1, 0, 0.228956,0.0347681) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503622,-0.00170112) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.732824,-0.0281948) , 
4, 0.381024, 1, 0, 0.51003,-0.00483433) , 
8, -0.0735627, 1, 0, 0.493277,-0.00247392)    );
  // itree = 530
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.240664,-0.00332605) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389009,0.0103963) , 
5, 957.311, 1, 0, 0.319938,0.0087978) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28,-0.0263445) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.718378,-0.00589938) , 
4, 0.109964, 1, 0, 0.686989,-0.0143918) , 
4, 0.0953715, 1, 0, 0.498211,-0.00246521)    );
  // itree = 531
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485483,-0.00374257) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.276423,0.0264853) , 
6, 4.30311, 1, 0, 0.479851,-0.00608281) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.764045,0.0350546) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.79021,0.00799857) , 
1, 14.1429, 1, 0, 0.775701,0.0420903) , 
1, 11.5714, 1, 0, 0.499284,-0.00291859)    );
  // itree = 532
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.125874,-0.058935) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4178,-0.00554266) , 
8, -0.037946, 1, 0, 0.37395,-0.0217699) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561178,0.00609742) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484568,-0.00405768) , 
7, -0.238293, 1, 0, 0.505371,-0.00257565) , 
7, -0.997992, 1, 0, 0.480121,-0.00626342)    );
  // itree = 533
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.632953,-0.0101155) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577922,0.02758) , 
7, 1.20005, 1, 0, 0.626812,-0.0129068) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482288,0.00580432) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202985,-0.0254438) , 
8, 0.0663533, 1, 0, 0.457528,0.00722073) , 
1, 1.47619, 1, 0, 0.502811,0.00183676)    );
  // itree = 534
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306906,-0.00918298) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.207483,0.013397) , 
7, 1.57033, 1, 0, 0.296242,-0.0168309) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.769625,0.00491978) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35468,-0.0142532) , 
6, 3.89904, 1, 0, 0.730483,0.00427978) , 
4, 0.114871, 1, 0, 0.487227,-0.00754617)    );
  // itree = 535
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475188,-0.000216372) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.788194,0.0355547) , 
1, 10.7143, 1, 0, 0.493961,0.00334412) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.676923,-0.0323579) , 
1, 16, 1, 0, 0.498783,0.00153678)    );
  // itree = 536
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471329,-0.00373294) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474845,0.00898053) , 
1, 3.28571, 1, 0, 0.472471,-0.000461166) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613636,-0.0385694) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.804196,0.0255176) , 
1, 13.3333, 1, 0, 0.674058,-0.032575) , 
0, 96457.2, 1, 0, 0.490953,-0.00340553)    );
  // itree = 537
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.619403,-0.0150418) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.639932,0.00934127) , 
4, 0.0196872, 1, 0, 0.637825,0.0143909) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363304,-0.00527888) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629475,0.00806427) , 
1, 5.85714, 1, 0, 0.45067,-0.00289098) , 
1, 1.38095, 1, 0, 0.499899,0.00165487)    );
  // itree = 538
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527513,0.000803381) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390977,-0.0254868) , 
7, 1.6159, 1, 0, 0.523689,0.00018366) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296443,0.0286739) , 
7, 1.85146, 1, 0, 0.512195,0.00279607)    );
  // itree = 539
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54908,0.00338804) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354198,-0.0129047) , 
6, 1.98589, 1, 0, 0.50996,-9.77597e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341079,0.011867) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893701,-0.00249641) , 
5, 4832.09, 1, 0, 0.504962,0.0188765) , 
7, 0.42984, 1, 0, 0.50824,0.00643416)    );
  // itree = 540
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.735327,0.00159797) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347027,-0.00707461) , 
6, 0.751532, 1, 0, 0.493125,-0.00857065) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2,-0.0242596) , 
6, 4.81081, 1, 0, 0.484818,-0.00990813)    );
  // itree = 541
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504727,0.0130284) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.724868,-0.00432235) , 
1, 8, 1, 0, 0.540096,0.0219503) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582511,0.00315338) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.274276,-0.0142412) , 
6, 1.16148, 1, 0, 0.442901,-0.00917002) , 
7, 0.70925, 1, 0, 0.51399,0.0135914)    );
  // itree = 542
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355589,-0.000433672) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.630751,0.0132383) , 
4, 0.0578706, 1, 0, 0.53612,0.0160365) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288462,-0.0136802) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.968354,0.0443778) , 
5, 7604.31, 1, 0, 0.39697,-0.0171031) , 
7, 0.996203, 1, 0, 0.507809,0.0092942)    );
  // itree = 543
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309412,-0.00382406) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.19084,-0.0310521) , 
4, 0.0655637, 1, 0, 0.295195,-0.0155778) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.579268,-0.0100791) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.682749,0.00667301) , 
7, -1.00396, 1, 0, 0.663816,0.00666037) , 
4, 0.0764921, 1, 0, 0.498564,-0.00330895)    );
  // itree = 544
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558173,0.00139098) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423116,0.0130862) , 
8, 0.0282183, 1, 0, 0.528435,0.00783226) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.365772,-0.0127656) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.110236,-0.0490372) , 
7, 2.31674, 1, 0, 0.289412,-0.0421171) , 
7, 1.56893, 1, 0, 0.507888,0.00353848)    );
  // itree = 545
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513501,-0.00142966) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445141,0.0172887) , 
6, 2.40261, 1, 0, 0.508659,-0.000313527) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175,-0.0300612) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.696203,0.00253774) , 
0, 130286, 1, 0, 0.363014,-0.0425098) , 
6, 3.14427, 1, 0, 0.495751,-0.0040533)    );
  // itree = 546
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376737,0.00573931) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.67033,-0.00563889) , 
4, 0.266612, 1, 0, 0.41475,0.00967935) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.880503,-0.0339718) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.98004,0.0104064) , 
4, 0.264549, 1, 0, 0.941392,-0.0111926) , 
5, 9612.62, 1, 0, 0.500397,0.00628496)    );
  // itree = 547
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510955,0.0125702) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489256,-0.00568828) , 
1, 4, 1, 0, 0.503436,0.0148298) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531818,-0.0120276) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485363,0.00529648) , 
1, 2.7619, 1, 0, 0.507389,-0.00804568) , 
7, -0.431698, 1, 0, 0.506007,-4.79796e-05)    );
  // itree = 548
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.34745,0.0109839) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.723655,-0.00306402) , 
2, 50884.3, 1, 0, 0.491134,0.0147516) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392272,-0.0169949) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.861111,0.00901991) , 
4, 0.286358, 1, 0, 0.581119,-0.0146603) , 
1, 4.14286, 1, 0, 0.516958,0.00631113)    );
  // itree = 549
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419301,0.00318238) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321121,-0.0156419) , 
4, 0.0256728, 1, 0, 0.376526,-0.0107969) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57043,0.00544107) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2,-0.0231449) , 
8, 0.0831569, 1, 0, 0.55243,0.00880267) , 
4, 0.0384374, 1, 0, 0.514774,0.00460697)    );
  // itree = 550
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439781,0.000233183) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305785,0.0238053) , 
6, 3.23243, 1, 0, 0.431829,0.00377572) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.8064,-0.00691496) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.795053,-0.0492764) , 
1, 10, 1, 0, 0.802863,-0.0279842) , 
4, 0.285608, 1, 0, 0.499398,-0.00200808)    );
  // itree = 551
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469481,0.000863525) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.783784,0.0254859) , 
1, 13.2857, 1, 0, 0.479237,0.00325847) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.858639,0.0427675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.854962,-0.00466525) , 
1, 8.42857, 1, 0, 0.857143,0.0423075) , 
4, 0.361388, 1, 0, 0.503143,0.00572876)    );
  // itree = 552
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.287582,0.0105124) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396461,-0.00527621) , 
7, -1.28762, 1, 0, 0.38288,-0.00807671) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.767742,-0.016781) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.844075,0.0185744) , 
7, -0.682538, 1, 0, 0.825472,0.0162115) , 
4, 0.228729, 1, 0, 0.496567,-0.00183789)    );
  // itree = 553
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.553313,0.00021914) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414462,0.0141581) , 
7, 1.27972, 1, 0, 0.534719,0.00423105) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360465,-0.021033) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.272727,0.0130231) , 
7, 1.30299, 1, 0, 0.346341,-0.034896) , 
6, 2.30027, 1, 0, 0.504155,-0.00211721)    );
  // itree = 554
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.315491,-0.000952603) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.410596,0.0286651) , 
4, 0.0873559, 1, 0, 0.325867,0.00494975) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453368,-0.0196071) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.767895,-0.00215567) , 
4, 0.15538, 1, 0, 0.714786,-0.0103652) , 
4, 0.114577, 1, 0, 0.501781,-0.00197743)    );
  // itree = 555
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516652,-0.00221849) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421488,0.0154737) , 
8, 0.0530685, 1, 0, 0.511799,-0.00297723) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.353383,0.0493401) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.197674,0.00721601) , 
1, 2.2381, 1, 0, 0.265574,0.0474918) , 
8, 0.0788427, 1, 0, 0.496931,7.02989e-05)    );
  // itree = 556
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0701754,-0.0255034) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358586,0.00618716) , 
8, -0.0753619, 1, 0, 0.340289,0.0125586) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.811475,-0.0329482) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.954321,0.00726121) , 
4, 0.255429, 1, 0, 0.892958,-0.0168958) , 
5, 5305.1, 1, 0, 0.496809,0.00421692)    );
  // itree = 557
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.63913,0.0103474) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.441363,-0.0102982) , 
0, 26707, 1, 0, 0.475418,-0.0140803) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.324138,-0.0266098) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.61,0.014227) , 
7, -1.28432, 1, 0, 0.570335,0.017286) , 
0, 60739.3, 1, 0, 0.495051,-0.00759224)    );
  // itree = 558
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341865,-0.00706001) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559157,0.00501146) , 
7, -1.39514, 1, 0, 0.526432,0.00691458) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544855,0.00116511) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.259804,-0.0135533) , 
6, 1.1735, 1, 0, 0.417518,-0.0105499) , 
7, 0.716868, 1, 0, 0.496601,0.00213122)    );
  // itree = 559
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35497,0.000967861) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321569,0.0255302) , 
4, 0.0490993, 1, 0, 0.350058,0.0106857) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464611,-0.0103094) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.964912,0.0161193) , 
5, 10390.1, 1, 0, 0.584611,-0.0152289) , 
4, 0.0573759, 1, 0, 0.504248,-0.00635002)    );
  // itree = 560
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.109375,-0.0282195) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343869,0.0062573) , 
2, 15862.9, 1, 0, 0.32304,0.00872194) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69682,-0.00960292) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.765903,0.0176756) , 
6, 1.73418, 1, 0, 0.709066,-0.00672792) , 
2, 55524, 1, 0, 0.490881,0.00200448)    );
  // itree = 561
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380994,0.012169) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283358,-0.00496725) , 
7, 0.44112, 1, 0, 0.345094,0.0144907) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602151,-0.00455554) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42619,-0.02258) , 
7, 1.27423, 1, 0, 0.579128,-0.0130457) , 
4, 0.0575017, 1, 0, 0.494626,-0.0031032)    );
  // itree = 562
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433198,0.0366484) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472843,0.00560449) , 
7, -1.27152, 1, 0, 0.467439,0.0187839) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475297,-0.00538839) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.713615,0.0118828) , 
1, 6.42857, 1, 0, 0.522154,-0.00558721) , 
8, -0.00926542, 1, 0, 0.502568,0.00313672)    );
  // itree = 563
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0646766,-0.000492597) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580882,0.0365363) , 
5, 2589.96, 1, 0, 0.272997,0.0297761) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.162791,-0.0343708) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518343,-0.00355091) , 
7, -2.14379, 1, 0, 0.508713,-0.00862951) , 
8, -0.0705262, 1, 0, 0.493137,-0.00609173)    );
  // itree = 564
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.369863,-0.00927662) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40044,0.0013636) , 
4, 0.0221278, 1, 0, 0.396211,-0.000829835) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.823529,0.0192892) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.902564,-0.0342325) , 
2, 156432, 1, 0, 0.835082,0.0229941) , 
4, 0.228711, 1, 0, 0.512627,0.00548973)    );
  // itree = 565
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440844,-0.00353044) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.88665,0.017721) , 
2, 98644.8, 1, 0, 0.527921,-0.00211803) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536122,0.0262738) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.34072,0.00241989) , 
1, 1.28571, 1, 0, 0.392893,0.0206015) , 
8, 0.0331882, 1, 0, 0.501584,0.00231339)    );
  // itree = 566
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479304,-0.000385116) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.186335,-0.0288469) , 
6, 3.17624, 1, 0, 0.465808,-0.00440308) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516539,0.0222105) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.690397,0.00247708) , 
1, 9, 1, 0, 0.592086,0.0228791) , 
1, 4.95238, 1, 0, 0.50174,0.00335992)    );
  // itree = 567
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561914,0.00807614) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35575,-0.00143048) , 
0, 35262.5, 1, 0, 0.474673,0.00823129) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.454829,-0.0136427) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.731107,0.00556328) , 
1, 9.57143, 1, 0, 0.557441,-0.0109563) , 
1, 4.14286, 1, 0, 0.499802,0.0024058)    );
  // itree = 568
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.290598,0.0208116) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664948,-0.0112731) , 
4, 0.190289, 1, 0, 0.400302,0.0234038) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.490138,-0.0018058) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.787755,-0.0260022) , 
4, 0.36134, 1, 0, 0.507091,-0.00595223) , 
7, -1.26856, 1, 0, 0.492847,-0.00203652)    );
  // itree = 569
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.277363,-0.0114473) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.610309,0.00554789) , 
4, 0.0574647, 1, 0, 0.491811,-0.00303161) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.373684,0.0135012) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580733,0.00133442) , 
4, 0.0576083, 1, 0, 0.509903,0.0126984) , 
7, -0.140498, 1, 0, 0.501787,0.00564238)    );
  // itree = 570
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464795,-0.00626134) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583333,0.0186085) , 
0, 90832.4, 1, 0, 0.470588,-0.0105733) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601307,0.0171872) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.838565,-0.0133815) , 
4, 0.306256, 1, 0, 0.701323,0.0140632) , 
1, 9.66667, 1, 0, 0.495252,-0.00793987)    );
  // itree = 571
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32362,-0.0110383) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.620703,-0.000895255) , 
4, 0.0575015, 1, 0, 0.519687,-0.0101434) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.478982,0.0136036) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325397,-0.0089784) , 
7, 0.99433, 1, 0, 0.445502,0.0161416) , 
8, 0.0258102, 1, 0, 0.502505,-0.00405532)    );
  // itree = 572
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532189,-0.00890264) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.705773,0.0148273) , 
7, -1.00255, 1, 0, 0.674828,0.0250376) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.263201,-0.00504561) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.786416,0.00441941) , 
4, 0.209726, 1, 0, 0.437653,-0.00465946) , 
1, 1.47619, 1, 0, 0.5,0.00314708)    );
  // itree = 573
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488281,0.00529065) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5,0.0437244) , 
7, 0.348649, 1, 0, 0.492424,0.0472257) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347826,0.0309411) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507188,-0.00200705) , 
7, -1.83931, 1, 0, 0.498618,-0.00128473) , 
4, 0.0193969, 1, 0, 0.498138,0.00248122)    );
  // itree = 574
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296453,-0.00150598) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503529,0.0211489) , 
2, 47571.4, 1, 0, 0.327963,0.00414427) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518459,-0.0125596) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.92437,-0.00450188) , 
5, 6680.38, 1, 0, 0.694268,-0.0180751) , 
2, 55524, 1, 0, 0.489281,-0.00564099)    );
  // itree = 575
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.425974,-0.000717945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337017,0.0169823) , 
7, 1.28916, 1, 0, 0.413922,0.00339809) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.807568,-0.0166184) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.885496,0.0358859) , 
1, 13.381, 1, 0, 0.817235,-0.0162067) , 
4, 0.266795, 1, 0, 0.498025,-0.000690105)    );
  // itree = 576
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540555,-0.00114195) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395693,0.0106477) , 
8, 0.0369837, 1, 0, 0.516784,0.0012753) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.139706,-0.0336854) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567073,0.0113636) , 
4, 0.0980328, 1, 0, 0.300459,-0.0298389) , 
7, 1.56439, 1, 0, 0.497784,-0.00145754)    );
  // itree = 577
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.281985,-0.00774478) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504587,0.00895946) , 
2, 47064.9, 1, 0, 0.32408,-0.0114324) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75606,0.00919779) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674699,-0.00869269) , 
6, 3.23498, 1, 0, 0.749644,0.0115045) , 
2, 58265.6, 1, 0, 0.50371,-0.00175078)    );
  // itree = 578
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327838,-0.00238265) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.710225,0.00455961) , 
4, 0.0953707, 1, 0, 0.521608,0.00143391) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.34717,-0.00459812) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328571,-0.0276352) , 
0, 59126.5, 1, 0, 0.343284,-0.0191706) , 
7, 1.28989, 1, 0, 0.497587,-0.00134152)    );
  // itree = 579
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480465,0.00104986) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76087,-0.0469893) , 
4, 0.344515, 1, 0, 0.488709,0.000276909) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.748299,0.0367961) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.929487,-0.0270002) , 
2, 64722.7, 1, 0, 0.841584,0.0377196) , 
4, 0.361911, 1, 0, 0.510106,0.0025473)    );
  // itree = 580
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518672,-0.0016605) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390411,0.0406754) , 
6, 2.70028, 1, 0, 0.514496,-0.000999694) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483516,0.0334786) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334821,0.000419043) , 
7, -0.118392, 1, 0, 0.401478,0.0326674) , 
6, 3.13803, 1, 0, 0.505112,0.00179557)    );
  // itree = 581
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531511,0.0124285) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534653,0.00102421) , 
7, -0.398453, 1, 0, 0.533547,0.0102647) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.239826,-0.0127371) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.646091,0.00532702) , 
2, 56976.7, 1, 0, 0.408007,-0.0116846) , 
8, 0.0244739, 1, 0, 0.503561,0.00502188)    );
  // itree = 582
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384085,0.00190024) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.78481,-0.00826758) , 
4, 0.209808, 1, 0, 0.495647,-0.000538166) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664474,-0.0403107) , 
1, 14.6667, 1, 0, 0.500804,-0.00260854)    );
  // itree = 583
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521648,-0.00536416) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447154,0.00344922) , 
7, 0.997963, 1, 0, 0.50792,-0.00765965) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426357,0.0359213) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.19797,0.00180949) , 
8, 0.0932872, 1, 0, 0.288344,0.0298694) , 
8, 0.0736867, 1, 0, 0.493597,-0.00521178)    );
  // itree = 584
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434315,0.000180513) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.271795,0.0517056) , 
6, 3.66018, 1, 0, 0.426585,0.0045984) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.861505,-0.00541927) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484076,-0.0246996) , 
6, 3.30381, 1, 0, 0.806331,-0.01461) , 
4, 0.266766, 1, 0, 0.505412,0.000611189)    );
  // itree = 585
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175439,-0.0217575) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500627,0.0148085) , 
7, -2.13751, 1, 0, 0.443182,0.0186454) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319454,-0.0119809) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.604175,-0.000749532) , 
4, 0.0580879, 1, 0, 0.501234,-0.0112916) , 
7, -0.997742, 1, 0, 0.49004,-0.00551888)    );
  // itree = 586
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50683,0.00263214) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515035,-0.00674573) , 
0, 54092.7, 1, 0, 0.509009,0.000810922) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.180905,-0.0278012) , 
7, 2.13332, 1, 0, 0.496164,-0.00106012)    );
  // itree = 587
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500964,0.000162162) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393484,0.0218081) , 
0, 50515.1, 1, 0, 0.490318,0.00455917) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504505,-0.0242705) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551935,0.00623542) , 
6, 2.19879, 1, 0, 0.526769,-0.0168704) , 
0, 60732.1, 1, 0, 0.497832,0.000141488)    );
  // itree = 588
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.595028,0.00460246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389489,-0.00536112) , 
0, 31804, 1, 0, 0.489539,-0.00130136) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514403,0.0168642) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578591,0.00271604) , 
1, 2.95238, 1, 0, 0.562691,0.0162363) , 
0, 60728.7, 1, 0, 0.504042,0.00217569)    );
  // itree = 589
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372807,0.0413193) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492243,0.00904094) , 
7, -1.93463, 1, 0, 0.46318,0.0322385) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510204,0.0131794) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5214,-0.00416691) , 
4, 0.0193969, 1, 0, 0.520579,-0.00514357) , 
7, -0.985406, 1, 0, 0.509705,0.00193831)    );
  // itree = 590
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.196296,0.00399607) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.576389,0.0297219) , 
4, 0.114329, 1, 0, 0.328502,0.0245681) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492293,-0.00121217) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.822581,0.0216687) , 
3, 0.047619, 1, 0, 0.519067,-6.72495e-05) , 
7, -1.55547, 1, 0, 0.503298,0.00197133)    );
  // itree = 591
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505928,-0.0026685) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.737931,-0.0592337) , 
0, 170086, 1, 0, 0.513792,-0.00863203) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22963,4.09259e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548913,0.0310945) , 
4, 0.0587801, 1, 0, 0.413793,0.0345396) , 
7, 1.28848, 1, 0, 0.500814,-0.0030292)    );
  // itree = 592
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491835,-0.0012701) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.437685,-0.0175251) , 
8, 0.0106199, 1, 0, 0.470554,-0.0157612) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5299,0.00719855) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350427,-0.00982351) , 
6, 3.23275, 1, 0, 0.516954,0.0118781) , 
7, -0.429463, 1, 0, 0.500907,0.00231943)    );
  // itree = 593
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.64027,-5.85536e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.416667,-0.0468576) , 
0, 60332.2, 1, 0, 0.617892,-0.0137913) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.260704,0.0117158) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.751167,-0.00476241) , 
4, 0.152602, 1, 0, 0.464871,0.011119) , 
1, 1.38095, 1, 0, 0.505894,0.0044408)    );
  // itree = 594
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497935,0.00295302) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.659574,-0.0204251) , 
0, 96457.2, 1, 0, 0.512236,0.00233998) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.406897,0.0201421) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25,0.0485555) , 
6, 1.1835, 1, 0, 0.330961,0.0572531) , 
7, 1.85382, 1, 0, 0.502173,0.0053883)    );
  // itree = 595
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50887,-0.00626488) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.440129,0.0138107) , 
6, 2.79919, 1, 0, 0.50441,-0.0101307) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354582,0.0159912) , 
6, 3.89972, 1, 0, 0.496908,-0.00780531)    );
  // itree = 596
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.140065,-0.0244716) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527778,-0.00181568) , 
2, 45146.6, 1, 0, 0.349325,-0.0229812) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528571,0.00019326) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421053,0.0210964) , 
6, 3.66047, 1, 0, 0.523475,0.00278908) , 
7, -1.27163, 1, 0, 0.500591,-0.00059721)    );
  // itree = 597
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400804,-0.00472508) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.574257,0.0233456) , 
7, -1.14756, 1, 0, 0.470823,0.014462) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.391447,-0.0140783) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514472,-0.00342887) , 
4, 0.0201782, 1, 0, 0.504702,-0.00946166) , 
7, -0.712911, 1, 0, 0.496358,-0.00356907)    );
  // itree = 598
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522818,-0.0103475) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515244,0.00330256) , 
7, 0.424176, 1, 0, 0.52021,-0.0115823) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264085,0.0217674) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569472,-0.00515331) , 
1, 4.42857, 1, 0, 0.408712,0.0211684) , 
6, 1.98622, 1, 0, 0.495602,-0.0043542)    );
  // itree = 599
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.292169,-0.0094245) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.709513,0.00346052) , 
4, 0.0953678, 1, 0, 0.504621,-0.0073873) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557075,0.00918976) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383013,-0.000970368) , 
7, 1.37362, 1, 0, 0.509974,0.0141618) , 
7, 0.156109, 1, 0, 0.507084,0.00252932)    );
  // itree = 600
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304991,-0.0173524) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.846705,-0.00229885) , 
2, 32749.2, 1, 0, 0.610169,-0.026073) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.412325,0.010481) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515844,-0.00496396) , 
1, 3.28571, 1, 0, 0.466038,0.0068407) , 
1, 1.38095, 1, 0, 0.502122,-0.00139937)    );
  // itree = 601
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341338,0.00648378) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.29207,-0.0051773) , 
7, 0.424013, 1, 0, 0.323033,0.00478674) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.737135,-0.0206426) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.710047,-0.00469131) , 
1, 2.66667, 1, 0, 0.718892,-0.0171477) , 
4, 0.114955, 1, 0, 0.497894,-0.00490226)    );
  // itree = 602
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491924,0.00877711) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.708889,-0.0114841) , 
1, 8.28571, 1, 0, 0.521528,0.0139324) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310345,-0.0270393) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471292,-0.0041859) , 
4, 0.0199019, 1, 0, 0.458448,-0.0130004) , 
7, 0.431745, 1, 0, 0.49912,0.00436505)    );
  // itree = 603
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37333,-0.00165893) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395833,-0.0256833) , 
3, 0.047619, 1, 0, 0.374388,-0.00640274) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.924812,0.0326066) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.958968,0.0167598) , 
8, -0.0427771, 1, 0, 0.954361,0.0172966) , 
5, 7967.79, 1, 0, 0.487179,-0.00179375)    );
  // itree = 604
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.443529,-0.010254) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.736842,0.0141158) , 
3, 0.047619, 1, 0, 0.46598,-0.0187034) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582288,0.0131888) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474815,0.00221234) , 
7, 0.600032, 1, 0, 0.524412,0.0152945) , 
7, -0.145745, 1, 0, 0.4983,0.000101201)    );
  // itree = 605
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513672,0.00391246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528853,-0.00354444) , 
7, -0.222956, 1, 0, 0.522213,-0.000798751) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380952,0.0278425) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.21374,0.0113941) , 
7, 2.29334, 1, 0, 0.29572,0.0364577) , 
7, 1.85568, 1, 0, 0.510427,0.00113988)    );
  // itree = 606
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523918,-0.00805746) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.951852,0.0157069) , 
4, 0.133288, 1, 0, 0.686883,-0.00793585) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.117647,-0.0324821) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.368846,0.00596191) , 
7, -1.85151, 1, 0, 0.354886,0.00976825) , 
6, 0.886223, 1, 0, 0.49959,0.00205173)    );
  // itree = 607
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.735849,0.000244886) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401522,0.0089374) , 
6, 0.76248, 1, 0, 0.605662,0.00839322) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.223947,-0.0211893) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355897,-0.00329459) , 
1, 1.28571, 1, 0, 0.32431,-0.0202108) , 
6, 1.27492, 1, 0, 0.497968,-0.00255556)    );
  // itree = 608
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311828,-0.00777972) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.604928,0.000706997) , 
4, 0.0575015, 1, 0, 0.500547,-0.00597991) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.39661,0.00882647) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.878981,-0.0565681) , 
5, 10626.2, 1, 0, 0.453254,0.0112241) , 
7, 0.720786, 1, 0, 0.487883,-0.0013731)    );
  // itree = 609
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519204,-0.00102112) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463158,0.0160035) , 
8, 0.0409299, 1, 0, 0.514675,0.000839112) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409483,0.0232998) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.121951,0.0120895) , 
8, 0.108443, 1, 0, 0.290404,0.0352892) , 
8, 0.0679255, 1, 0, 0.497254,0.00351511)    );
  // itree = 610
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.722938,0.0237324) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492813,-0.00742294) , 
0, 35272.9, 1, 0, 0.634204,0.0213461) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.425937,-0.00363338) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.766234,0.0181859) , 
1, 13.9048, 1, 0, 0.447176,-0.00491858) , 
1, 1.28571, 1, 0, 0.494762,0.00176399)    );
  // itree = 611
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494777,0.00458273) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507213,-0.00758034) , 
7, -0.232032, 1, 0, 0.501688,-0.00499556) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.397351,0.0264836) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230159,0.00891209) , 
7, 2.28471, 1, 0, 0.3213,0.0396337) , 
7, 1.84959, 1, 0, 0.491728,-0.00253148)    );
  // itree = 612
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448845,-0.0108369) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.95283,0.0147795) , 
2, 56425.9, 1, 0, 0.609152,-0.0176391) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494949,0.00226864) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404286,0.0120383) , 
7, 1.00576, 1, 0, 0.477657,0.00804777) , 
1, 1.38095, 1, 0, 0.512692,0.00120377)    );
  // itree = 613
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286486,0.00393477) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.631045,-0.00418317) , 
2, 42592, 1, 0, 0.478582,-0.000243421) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.452229,-0.0358433) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.871508,0.00460928) , 
4, 0.26875, 1, 0, 0.675595,-0.0374386) , 
0, 121724, 1, 0, 0.491996,-0.00277586)    );
  // itree = 614
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.324717,0.00174347) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485294,-0.0429867) , 
2, 55432.4, 1, 0, 0.332095,-0.000176836) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492823,-0.00686246) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.783403,0.0139053) , 
8, -0.044122, 1, 0, 0.754824,0.0186949) , 
2, 58265.6, 1, 0, 0.508751,0.00770957)    );
  // itree = 615
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522182,-0.00127703) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.413636,0.018885) , 
8, 0.0527386, 1, 0, 0.517033,-0.000649022) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.219697,-0.0186809) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0229008,-0.0640336) , 
8, 0.118784, 1, 0, 0.121673,-0.0478376) , 
8, 0.0791842, 1, 0, 0.495817,-0.00318128)    );
  // itree = 616
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355658,-0.0113133) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550918,0.00983835) , 
8, -0.030918, 1, 0, 0.513004,0.0126505) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304718,-0.00703946) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.738655,0.00394655) , 
4, 0.114572, 1, 0, 0.494845,-0.00578939) , 
7, -0.140498, 1, 0, 0.503033,0.00252461)    );
  // itree = 617
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325891,-0.000893047) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.127778,-0.0289036) , 
6, 3.66979, 1, 0, 0.315419,-0.0053681) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.870093,-0.0290968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.843902,0.00964464) , 
6, 2.60489, 1, 0, 0.86675,-0.0256055) , 
5, 4810.98, 1, 0, 0.492117,-0.0118541)    );
  // itree = 618
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52404,-0.00146018) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316109,0.0185137) , 
8, 0.071974, 1, 0, 0.50941,-0.000909091) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.211429,-0.0246778) , 
7, 2.14276, 1, 0, 0.49866,-0.00267633)    );
  // itree = 619
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527253,-0.0111327) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578638,0.00720571) , 
1, 4.28571, 1, 0, 0.539401,-0.0165368) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.252708,0.0141987) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457587,-0.00197371) , 
1, 2.95238, 1, 0, 0.375988,0.0119966) , 
6, 1.61087, 1, 0, 0.493894,-0.00859082)    );
  // itree = 620
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508772,-0.00186415) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.119403,-0.020233) , 
1, 2.90476, 1, 0, 0.35039,-0.018455) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302281,0.0147174) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.640625,0.00153709) , 
4, 0.0728654, 1, 0, 0.551552,0.01019) , 
4, 0.03845, 1, 0, 0.506506,0.00377561)    );
  // itree = 621
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.192308,0.0409153) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506124,0.00201711) , 
8, -0.0857795, 1, 0, 0.490793,0.00641149) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614357,0.0029055) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.413714,-0.0102973) , 
1, 1.28571, 1, 0, 0.464879,-0.0138266) , 
7, 0.138776, 1, 0, 0.478643,-0.00307737)    );
  // itree = 622
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395652,-0.00861665) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508053,0.0104361) , 
7, -0.699742, 1, 0, 0.479737,0.0124829) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475417,-0.00427212) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616592,0.00677132) , 
1, 4.14286, 1, 0, 0.514392,-0.00368283) , 
8, -0.00935821, 1, 0, 0.501879,0.00215437)    );
  // itree = 623
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4681,0.00825953) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.639566,0.0278794) , 
7, -0.679042, 1, 0, 0.503968,0.0243509) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54508,-0.00276027) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485571,0.00815912) , 
7, 0.544094, 1, 0, 0.516256,0.0052466) , 
7, -0.433711, 1, 0, 0.511968,0.0119133)    );
  // itree = 624
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.344524,0.00297923) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.71048,-0.00405479) , 
4, 0.0954385, 1, 0, 0.52233,3.88669e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.165939,-0.0298108) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.3,-0.000467203) , 
1, 3.42857, 1, 0, 0.216802,-0.0306638) , 
8, 0.071974, 1, 0, 0.4998,-0.00222518)    );
  // itree = 625
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42381,0.00713675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514124,0.0282361) , 
4, 0.0140425, 1, 0, 0.465116,0.0428322) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.300047,0.0035941) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.674912,-0.00593725) , 
4, 0.0919751, 1, 0, 0.504936,-0.0024558) , 
4, 0.0194949, 1, 0, 0.501882,0.00101685)    );
  // itree = 626
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466899,-0.00905306) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530023,0.000578976) , 
8, -0.00907199, 1, 0, 0.506911,-0.00638569) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.155039,0.0315035) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.44,0.0227079) , 
4, 0.079702, 1, 0, 0.295276,0.0508862) , 
7, 1.85442, 1, 0, 0.496066,-0.00345104)    );
  // itree = 627
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.206573,-0.0219382) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477681,0.00319092) , 
7, -1.83821, 1, 0, 0.463634,0.00460093) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512777,-0.0212093) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.891239,0.0169898) , 
4, 0.324941, 1, 0, 0.649237,-0.0182729) , 
1, 6.66667, 1, 0, 0.497514,0.000425511)    );
  // itree = 628
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.412341,0.0051988) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483359,-0.00824571) , 
4, 0.0383684, 1, 0, 0.463245,-0.0082219) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47541,0.0175867) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.833689,-0.00230572) , 
4, 0.304802, 1, 0, 0.591695,0.0216385) , 
1, 4.14286, 1, 0, 0.5,0.000322311)    );
  // itree = 629
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.275695,-0.000804243) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.624355,0.0140004) , 
4, 0.0765961, 1, 0, 0.463808,0.0121362) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403226,-0.0146333) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523957,-0.00143074) , 
4, 0.0193969, 1, 0, 0.514449,-0.0059837) , 
8, -0.00907199, 1, 0, 0.496057,0.000597345)    );
  // itree = 630
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507794,-0.00408418) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526882,-0.023617) , 
7, 0.274679, 1, 0, 0.509411,-0.0117276) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273191,-0.00751894) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69125,0.0160175) , 
4, 0.0960451, 1, 0, 0.460977,0.00345225) , 
7, 0.437409, 1, 0, 0.492414,-0.00640042)    );
  // itree = 631
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463215,-0.00104558) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.713945,0.0162612) , 
1, 6.66667, 1, 0, 0.507595,0.00270794) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.279661,-0.0227032) , 
6, 3.89583, 1, 0, 0.496785,8.73955e-05)    );
  // itree = 632
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52982,-0.00769628) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516484,0.0213376) , 
0, 63107.4, 1, 0, 0.528785,-0.0112207) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393189,-0.0024926) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509926,0.00863916) , 
8, -0.0109483, 1, 0, 0.466098,0.00835105) , 
1, 2.7619, 1, 0, 0.49594,-0.000965987)    );
  // itree = 633
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25641,0.00357064) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.210784,-0.0347854) , 
7, -0.162325, 1, 0, 0.233083,-0.0272345) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554963,0.00502084) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316024,-0.00959868) , 
8, 0.0463981, 1, 0, 0.520052,0.00688555) , 
8, -0.058551, 1, 0, 0.497207,0.00416929)    );
  // itree = 634
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472488,-0.000608862) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.771552,0.0316069) , 
0, 112278, 1, 0, 0.486536,0.00115029) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680412,-0.0302403) , 
1, 13.8095, 1, 0, 0.493863,-0.000934114)    );
  // itree = 635
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.805195,0.0344499) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.287149,0.00613939) , 
6, 0.628964, 1, 0, 0.409509,0.0239357) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356144,0.00296906) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.759838,-0.00393609) , 
4, 0.15268, 1, 0, 0.515664,0.00163744) , 
7, -1.28266, 1, 0, 0.501891,0.00453066)    );
  // itree = 636
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519654,0.00378808) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.55838,-0.0135744) , 
8, 0.00920203, 1, 0, 0.529774,-0.00162388) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473934,0.0221961) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327586,0.00205685) , 
1, 2.57143, 1, 0, 0.393008,0.0260429) , 
8, 0.0332725, 1, 0, 0.503994,0.00359127)    );
  // itree = 637
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.265823,0.00706437) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.415254,-0.0185429) , 
7, -2.08282, 1, 0, 0.377778,-0.0250586) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529221,0.00586869) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537748,-0.0019238) , 
1, 4, 1, 0, 0.532361,0.00740803) , 
7, -1.26982, 1, 0, 0.512953,0.00333191)    );
  // itree = 638
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479343,-0.000421049) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.931035,0.0298897) , 
2, 153989, 1, 0, 0.511753,0.00154817) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.183333,-0.0259811) , 
7, 2.14041, 1, 0, 0.5,-0.000158332)    );
  // itree = 639
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463478,-0.00205254) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.777132,0.0120905) , 
1, 9, 1, 0, 0.497479,-0.00183366) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.386266,0.0181943) , 
6, 3.90282, 1, 0, 0.492289,7.90788e-05)    );
  // itree = 640
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552976,0.00655947) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341463,0.0490103) , 
7, 2.13236, 1, 0, 0.546103,0.0164593) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.224215,-0.0198731) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394608,-0.00011001) , 
7, -0.981808, 1, 0, 0.358037,-0.00876306) , 
6, 1.98961, 1, 0, 0.505597,0.0110269)    );
  // itree = 641
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298013,-0.0149228) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548523,0.00668003) , 
7, -1.76218, 1, 0, 0.514104,0.00899957) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357895,0.0172712) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507549,-0.00827655) , 
8, -0.06498, 1, 0, 0.497295,-0.0148676) , 
7, -0.13875, 1, 0, 0.504727,-0.00431438)    );
  // itree = 642
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499894,0.000469305) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.856061,0.0323885) , 
0, 203643, 1, 0, 0.50957,0.00266616) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.185629,-0.0267261) , 
7, 2.1399, 1, 0, 0.498806,0.00096013)    );
  // itree = 643
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247788,0.0301365) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466292,-0.00655814) , 
2, 50036.3, 1, 0, 0.344059,0.0261057) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501171,-0.0109865) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53406,0.002246) , 
7, -0.702947, 1, 0, 0.527851,-0.000725267) , 
7, -1.5727, 1, 0, 0.512784,0.00147435)    );
  // itree = 644
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505859,-0.0128443) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409524,0.00990957) , 
8, 0.0221711, 1, 0, 0.477839,-0.0137127) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550021,0.00664724) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.331906,-0.0204098) , 
8, 0.0369837, 1, 0, 0.513849,0.00542673) , 
7, -0.143093, 1, 0, 0.498194,-0.00289444)    );
  // itree = 645
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537843,-0.000355434) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351533,-0.0144487) , 
8, 0.0284785, 1, 0, 0.498164,-0.00644744) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.383459,0.032724) , 
6, 4.81051, 1, 0, 0.495134,-0.00445921)    );
  // itree = 646
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500925,0.00427382) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.748538,-0.0295109) , 
0, 121727, 1, 0, 0.515658,0.00583566) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486434,-0.00963679) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4829,0.00996213) , 
8, 0.01642, 1, 0, 0.485301,-0.00778727) , 
7, 0.141508, 1, 0, 0.502232,-0.00018931)    );
  // itree = 647
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296353,-0.00167865) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.585198,0.0125624) , 
4, 0.0980314, 1, 0, 0.384818,0.00566497) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.850387,-0.00693519) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.412162,-0.0303678) , 
6, 3.66352, 1, 0, 0.800915,-0.0172213) , 
4, 0.228553, 1, 0, 0.491675,-0.000212373)    );
  // itree = 648
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395773,-0.00599618) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.148773,0.00829249) , 
6, 1.76649, 1, 0, 0.348351,-0.00869616) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.770053,0.0198407) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.82504,0.00276024) , 
7, -0.720454, 1, 0, 0.812346,0.0113455) , 
4, 0.190525, 1, 0, 0.498206,-0.00222338)    );
  // itree = 649
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.144487,-0.0134778) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.435196,0.00750051) , 
2, 16278.7, 1, 0, 0.415301,0.0139873) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.837535,-0.00200784) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.604651,-0.0242727) , 
7, 1.32481, 1, 0, 0.8125,-0.00750664) , 
2, 85465, 1, 0, 0.509816,0.00887277)    );
  // itree = 650
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.243243,-0.0127838) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349214,-0.00183556) , 
7, -0.70477, 1, 0, 0.321198,-0.0106565) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.758186,0.0102455) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.670121,-0.0102806) , 
0, 73365.4, 1, 0, 0.734656,0.00737444) , 
2, 58265.6, 1, 0, 0.496671,-0.00300415)    );
  // itree = 651
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.318925,0.00100366) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46594,0.0191011) , 
4, 0.0953205, 1, 0, 0.337308,0.00752914) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.571158,-0.0146683) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785018,-0.00185702) , 
4, 0.196753, 1, 0, 0.733057,-0.0101742) , 
4, 0.133362, 1, 0, 0.505486,5.89583e-06)    );
  // itree = 652
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.476079,-0.00871491) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.573984,0.00902218) , 
0, 60733.9, 1, 0, 0.494978,-0.0114491) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345029,-0.0116729) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501875,0.00778623) , 
4, 0.0209405, 1, 0, 0.486731,0.0110444) , 
7, 0.426726, 1, 0, 0.492031,-0.00341275)    );
  // itree = 653
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.365672,-0.0184605) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384085,0.00584914) , 
4, 0.0103316, 1, 0, 0.383402,0.0107693) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.68956,-0.0212776) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.823843,-0.00337179) , 
4, 0.254619, 1, 0, 0.790995,-0.0134806) , 
4, 0.209358, 1, 0, 0.502254,0.00369821)    );
  // itree = 654
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.331894,-0.00390409) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.758459,0.00590535) , 
4, 0.133385, 1, 0, 0.498073,-0.00151295) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.651163,-0.0335163) , 
1, 16, 1, 0, 0.501976,-0.00304833)    );
  // itree = 655
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.673565,-0.0086274) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.254405,0.00453743) , 
6, 0.916167, 1, 0, 0.480467,-0.00444965) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393398,0.0128204) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.904225,-0.0130366) , 
5, 9327.58, 1, 0, 0.560998,0.0157533) , 
0, 60729.6, 1, 0, 0.497811,-9.86126e-05)    );
  // itree = 656
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.489329,0.00110364) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305556,0.0363174) , 
7, 2.13236, 1, 0, 0.483685,0.00418394) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.220779,-0.0496762) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.934959,0.00932944) , 
5, 5466.19, 1, 0, 0.66,-0.0378087) , 
3, 0.047619, 1, 0, 0.497544,0.000883284)    );
  // itree = 657
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518328,0.00456267) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721154,-0.0278196) , 
1, 13.2857, 1, 0, 0.527339,0.00709935) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.277966,-0.0256429) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0852713,-0.00370638) , 
8, 0.122567, 1, 0, 0.21934,-0.0343827) , 
8, 0.0625038, 1, 0, 0.501763,0.0036547)    );
  // itree = 658
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466759,0.000463453) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497594,0.00616919) , 
7, -0.133503, 1, 0, 0.483262,0.00745577) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.775641,-0.0460749) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.808642,0.00127499) , 
4, 0.380125, 1, 0, 0.792453,-0.0304616) , 
4, 0.361902, 1, 0, 0.503013,0.00503356)    );
  // itree = 659
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32909,0.00140082) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.714443,-0.00937665) , 
4, 0.114918, 1, 0, 0.485307,-0.00486057) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.568627,0.0208966) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.911765,0.00548951) , 
5, 10250.4, 1, 0, 0.740196,0.0296815) , 
0, 96457.2, 1, 0, 0.506531,-0.00198441)    );
  // itree = 660
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.459459,-0.0297699) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.643077,-0.00275454) , 
7, -0.7085, 1, 0, 0.600315,-0.0202636) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466362,0.00109114) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.435226,0.0116346) , 
7, 0.434002, 1, 0, 0.45505,0.00979041) , 
1, 1.38095, 1, 0, 0.491589,0.00223082)    );
  // itree = 661
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374679,0.00411895) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.898305,-0.00829335) , 
5, 4816.21, 1, 0, 0.538345,0.00469705) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.108844,-0.0195884) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.693548,0.00317163) , 
5, 2637.73, 1, 0, 0.357143,-0.0194351) , 
6, 1.98589, 1, 0, 0.501203,-0.000249416)    );
  // itree = 662
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507929,-0.00373517) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314465,0.0222813) , 
8, 0.0559068, 1, 0, 0.488815,-0.00381658) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.849515,0.0397964) , 
0, 157589, 1, 0, 0.503576,-0.00107287)    );
  // itree = 663
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359952,0.0113) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.889706,-0.0410735) , 
5, 10240.8, 1, 0, 0.433846,0.0158505) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513889,-0.0216939) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.510655,-0.000809108) , 
7, -0.806253, 1, 0, 0.510825,-0.00409172) , 
7, -0.997742, 1, 0, 0.496068,-0.000268748)    );
  // itree = 664
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525968,0.00167813) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283843,-0.0190415) , 
6, 3.90219, 1, 0, 0.514352,0.00115231) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.206452,-0.00161372) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.261194,-0.0481815) , 
4, 0.0613309, 1, 0, 0.231834,-0.045159) , 
7, 1.84959, 1, 0, 0.498222,-0.0014917)    );
  // itree = 665
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.345455,-0.0156509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518854,0.00620279) , 
4, 0.0194378, 1, 0, 0.506195,0.0084649) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546956,-0.0015561) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332805,-0.0145697) , 
6, 2.00221, 1, 0, 0.497818,-0.00963005) , 
7, -0.146817, 1, 0, 0.501597,-0.00146746)    );
  // itree = 666
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.214689,0.00564534) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552349,-0.00195881) , 
2, 25442.1, 1, 0, 0.469064,-0.000247924) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.564551,0.0126374) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.899281,-0.0549827) , 
5, 21567.1, 1, 0, 0.595364,0.0168109) , 
1, 4.14286, 1, 0, 0.506473,0.00480481)    );
  // itree = 667
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357664,0.0250771) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466978,-0.0054971) , 
7, -1.55547, 1, 0, 0.458874,-0.00740867) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504249,0.00370827) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.792398,0.0218179) , 
1, 9.57143, 1, 0, 0.535376,0.0111343) , 
8, -0.00935821, 1, 0, 0.50718,0.00429995)    );
  // itree = 668
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494864,-0.00156816) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.748768,-0.0255449) , 
1, 11.4286, 1, 0, 0.505875,-0.00496518) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.342723,0.0262579) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56875,0.00307118) , 
1, 9, 1, 0, 0.439678,0.0399772) , 
6, 3.23498, 1, 0, 0.500989,-0.0016483)    );
  // itree = 669
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513399,0.0039459) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392308,0.0320533) , 
6, 3.86176, 1, 0, 0.506424,0.0118514) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.740132,0.0057022) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332423,-0.00962101) , 
6, 0.889311, 1, 0, 0.517344,-0.0070707) , 
7, -0.143978, 1, 0, 0.512353,0.001578)    );
  // itree = 670
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511203,0.000300206) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.786765,0.0310433) , 
1, 14.6667, 1, 0, 0.519121,0.00228054) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.117188,-0.0105094) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348684,-0.0312746) , 
2, 40867.5, 1, 0, 0.242857,-0.0385112) , 
7, 1.85442, 1, 0, 0.50369,2.13088e-06)    );
  // itree = 671
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.580172,-0.00522063) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359643,0.00373704) , 
1, 1.38095, 1, 0, 0.426157,0.00154808) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.784452,-0.0363312) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.816901,0.00114977) , 
0, 47654.2, 1, 0, 0.799624,-0.0257349) , 
4, 0.266401, 1, 0, 0.507028,-0.0043598)    );
  // itree = 672
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537728,-0.00154005) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.397938,-0.0141902) , 
8, 0.0277045, 1, 0, 0.507828,-0.00889888) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382838,0.0299151) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348993,-0.0164046) , 
1, 3.28571, 1, 0, 0.371681,0.0300672) , 
7, 1.57052, 1, 0, 0.495488,-0.00536716)    );
  // itree = 673
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485597,0.0221318) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384615,-0.00502447) , 
4, 0.0148687, 1, 0, 0.444175,0.029015) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327869,-0.00608136) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.801813,0.00481502) , 
4, 0.182607, 1, 0, 0.49677,-0.00614613) , 
4, 0.0194949, 1, 0, 0.492484,-0.00328095)    );
  // itree = 674
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471503,0.0261295) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536256,0.00132456) , 
4, 0.0193969, 1, 0, 0.531511,0.0078145) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.415076,-0.00644139) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.851406,0.0210139) , 
4, 0.323443, 1, 0, 0.462478,-0.00902349) , 
7, 0.141817, 1, 0, 0.499391,-1.99858e-05)    );
  // itree = 675
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.478203,-0.00294085) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.875862,0.0181794) , 
4, 0.342394, 1, 0, 0.51296,-0.00361731) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356061,0.0355843) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.12766,0.0158855) , 
8, 0.122954, 1, 0, 0.238095,0.0393849) , 
8, 0.0831569, 1, 0, 0.498667,-0.00138119)    );
  // itree = 676
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.490219,-0.00389733) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448826,0.0105815) , 
0, 50604.2, 1, 0, 0.480511,-0.00122506) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565657,-0.0375618) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.772021,-0.0111761) , 
3, 0.047619, 1, 0, 0.667519,-0.0474602) , 
1, 10.6667, 1, 0, 0.495337,-0.0048905)    );
  // itree = 677
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492994,-0.00214252) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431515,-0.0113385) , 
7, 0.424013, 1, 0, 0.471498,-0.0110274) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.808081,0.0250536) , 
1, 13.8095, 1, 0, 0.485052,-0.00895341)    );
  // itree = 678
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338731,0.0120551) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.724012,0.00248918) , 
2, 50884.3, 1, 0, 0.485372,0.0205405) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.573676,-0.0105128) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47549,0.0202644) , 
7, 1.26731, 1, 0, 0.55949,-0.0102889) , 
1, 4.14286, 1, 0, 0.506299,0.011836)    );
  // itree = 679
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320988,0.0214611) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485955,-0.0105773) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511139,0.00129122) , 
7, -0.467038, 1, 0, 0.503436,-0.00500194) , 
7, -1.85689, 1, 0, 0.494387,-0.00304937)    );
  // itree = 680
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484275,-0.00472632) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.675188,0.00797879) , 
0, 73365.4, 1, 0, 0.512019,-0.00647268) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.202899,-0.0100891) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511811,-0.0530771) , 
4, 0.151432, 1, 0, 0.286017,-0.0446283) , 
7, 1.56654, 1, 0, 0.490887,-0.0100403)    );
  // itree = 681
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.554088,0.00333996) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394531,-0.00818493) , 
7, 1.28616, 1, 0, 0.534021,0.00408131) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.228097,-0.0184794) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.714286,0.0121536) , 
4, 0.247494, 1, 0, 0.31644,-0.0258154) , 
8, 0.0369837, 1, 0, 0.497951,-0.000874921)    );
  // itree = 682
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530089,-0.00660357) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.425331,0.0128147) , 
8, 0.0371595, 1, 0, 0.512884,-0.00787203) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583578,0.0164915) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407301,6.71399e-06) , 
7, 0.916553, 1, 0, 0.477075,0.0138112) , 
7, 0.42686, 1, 0, 0.500405,-0.000315359)    );
  // itree = 683
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38247,0.0119576) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.253623,-0.0130625) , 
0, 77567.4, 1, 0, 0.3669,0.0215728) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401361,-0.0130451) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575941,0.00298525) , 
8, -0.0230261, 1, 0, 0.536029,-0.000852837) , 
4, 0.0383782, 1, 0, 0.4974,0.00426918)    );
  // itree = 684
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50763,0.00513801) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.761329,0.0241178) , 
1, 11.0476, 1, 0, 0.525172,0.0131373) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222857,-0.0278485) , 
7, 2.14085, 1, 0, 0.51451,0.0109531)    );
  // itree = 685
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509609,-0.00852853) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.661972,0.0132781) , 
1, 5.7619, 1, 0, 0.536232,-0.0116791) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360524,0.000722162) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339523,0.0277863) , 
7, 0.711635, 1, 0, 0.354745,0.0148597) , 
6, 1.65468, 1, 0, 0.486771,-0.00444656)    );
  // itree = 686
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539814,-0.00148336) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347204,-0.0137095) , 
6, 1.98622, 1, 0, 0.499455,-0.00860518) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528796,0.0123165) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.261421,-0.0133949) , 
7, 1.69291, 1, 0, 0.450704,0.0121252) , 
7, 0.715009, 1, 0, 0.486352,-0.00303331)    );
  // itree = 687
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.137405,0.0204822) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447552,0.0304811) , 
5, 1420.42, 1, 0, 0.29927,0.0429663) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50748,0.000222994) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75814,0.0196215) , 
0, 96458, 1, 0, 0.530052,0.00363728) , 
7, -1.85788, 1, 0, 0.517528,0.00577159)    );
  // itree = 688
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565674,0.00687507) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420382,-0.00619707) , 
7, 1.002, 1, 0, 0.539477,0.00898837) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422917,-0.00047068) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448276,-0.0219) , 
1, 3.47619, 1, 0, 0.43276,-0.0152294) , 
8, 0.0173647, 1, 0, 0.506334,0.00146704)    );
  // itree = 689
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354657,-0.00408586) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544404,0.00467642) , 
4, 0.0365878, 1, 0, 0.502978,0.00492849) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.881481,0.0382721) , 
4, 0.380667, 1, 0, 0.513189,0.00644337)    );
  // itree = 690
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.229597,0.0163535) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.57911,0.000645225) , 
2, 25442.1, 1, 0, 0.487443,0.0108824) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532091,-0.019675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.589928,-0.00249363) , 
7, -0.431793, 1, 0, 0.570742,-0.0140683) , 
1, 4.42857, 1, 0, 0.511895,0.00355815)    );
  // itree = 691
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.188764,-0.0201803) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572354,-0.000307036) , 
2, 48198.9, 1, 0, 0.384361,-0.0216765) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.581395,0.0284522) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517601,-0.00119884) , 
7, -0.810535, 1, 0, 0.520988,0.000915523) , 
7, -1.00225, 1, 0, 0.495966,-0.00322193)    );
  // itree = 692
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466598,-0.000503153) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.222,-0.0170706) , 
6, 2.5454, 1, 0, 0.43856,-0.00507233) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.809668,0.0029759) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.96732,0.0398121) , 
4, 0.228809, 1, 0, 0.8854,0.0187614) , 
2, 116531, 1, 0, 0.495499,-0.00203531)    );
  // itree = 693
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390071,-0.0165036) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523376,0.000520542) , 
4, 0.0194572, 1, 0, 0.512864,-0.00245699) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366337,-0.0178905) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.918919,0.037234) , 
4, 0.30445, 1, 0, 0.445216,-0.027558) , 
7, 0.70925, 1, 0, 0.494869,-0.0091341)    );
  // itree = 694
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.621622,0.00843452) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.846667,-0.0226704) , 
4, 0.261952, 1, 0, 0.646927,0.0150528) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396821,-0.00262368) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.841727,0.0175338) , 
4, 0.342875, 1, 0, 0.447126,-0.00191011) , 
1, 1.33333, 1, 0, 0.500199,0.00259576)    );
  // itree = 695
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288947,-0.00729304) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.705499,0.00323714) , 
2, 49322.4, 1, 0, 0.504103,-0.00556436) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333333,0.0240558) , 
6, 4.67289, 1, 0, 0.499386,-0.00377963)    );
  // itree = 696
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49465,0.00621747) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.460751,-0.00681384) , 
0, 58148.4, 1, 0, 0.488196,0.00806272) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.710963,-0.029391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.909091,0.0146286) , 
0, 85949, 1, 0, 0.781116,-0.0270836) , 
4, 0.342881, 1, 0, 0.51505,0.00484057)    );
  // itree = 697
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319652,-0.00326168) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.6141,0.00657997) , 
4, 0.0574127, 1, 0, 0.511193,0.00547435) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.174797,-0.0220756) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.697183,-0.000726649) , 
0, 118563, 1, 0, 0.365979,-0.0315449) , 
6, 3.23275, 1, 0, 0.4999,0.00259532)    );
  // itree = 698
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.656513,0.00117724) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562691,0.0139034) , 
8, 0.0221711, 1, 0, 0.632525,0.0110102) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.427775,-0.00533378) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.78534,-0.0341766) , 
0, 170088, 1, 0, 0.445857,-0.012838) , 
1, 1.47619, 1, 0, 0.493078,-0.00680521)    );
  // itree = 699
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472656,-0.0273823) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.229167,0.01815) , 
1, 2.14286, 1, 0, 0.385,-0.0392984) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439135,-0.00786457) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.535646,0.00407187) , 
7, -0.98423, 1, 0, 0.517075,0.00378628) , 
4, 0.0194509, 1, 0, 0.506441,0.000317307)    );
  // itree = 700
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356043,0.00509243) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471245,-0.0101123) , 
4, 0.0547365, 1, 0, 0.423873,-0.007211) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.858447,0.0384554) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.865649,0.0156474) , 
4, 0.313158, 1, 0, 0.863844,0.0319621) , 
4, 0.285608, 1, 0, 0.501105,-0.000334662)    );
  // itree = 701
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346363,-0.010348) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563551,0.00183624) , 
4, 0.0384917, 1, 0, 0.517161,-0.00268893) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434889,0.0273997) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309804,-0.00853204) , 
0, 42866.4, 1, 0, 0.386707,0.027991) , 
7, 1.28535, 1, 0, 0.499799,0.00139432)    );
  // itree = 702
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54728,-0.0057242) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.352313,0.00416953) , 
6, 1.57853, 1, 0, 0.500743,-0.00735007) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422819,0.00228022) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.29,-0.0317935) , 
7, -0.129104, 1, 0, 0.346705,-0.0388862) , 
6, 3.23275, 1, 0, 0.490115,-0.00952605)    );
  // itree = 703
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.262611,-0.00189847) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.677433,0.00840414) , 
2, 42592, 1, 0, 0.482958,0.0062671) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.661017,0.0316456) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62754,0.00255865) , 
7, -0.355526, 1, 0, 0.640921,0.0273771) , 
0, 73362.1, 1, 0, 0.506038,0.00935147)    );
  // itree = 704
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508016,0.000452582) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453416,-0.0279068) , 
7, 1.35544, 1, 0, 0.506075,-0.00138535) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.18,0.00697192) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49,0.0273238) , 
4, 0.0767244, 1, 0, 0.317778,0.0318991) , 
7, 1.5737, 1, 0, 0.48905,0.0016241)    );
  // itree = 705
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.617618,0.00687934) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.248826,-0.0170697) , 
6, 1.25285, 1, 0, 0.593403,0.0104258) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.200965,0.000553858) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.651341,-0.0151635) , 
4, 0.267654, 1, 0, 0.334088,-0.00947989) , 
6, 1.37781, 1, 0, 0.501996,0.00340915)    );
  // itree = 706
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.391858,0.000250881) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.582796,0.01716) , 
7, -1.13409, 1, 0, 0.46283,0.0134597) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519256,-0.0106184) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496142,0.00300833) , 
7, 0.180548, 1, 0, 0.505527,-0.00533037) , 
7, -0.699902, 1, 0, 0.494758,-0.000591188)    );
  // itree = 707
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463222,-0.00314238) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497193,0.0056619) , 
7, -0.431799, 1, 0, 0.485673,0.00577314) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.693431,-0.0494164) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.809859,-0.00879158) , 
0, 193552, 1, 0, 0.752688,-0.046058) , 
0, 132186, 1, 0, 0.500195,0.00295426)    );
  // itree = 708
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329032,0.018827) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50897,-0.00818276) , 
8, -0.0627184, 1, 0, 0.495726,-0.0140139) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384946,0.0124244) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584958,-0.00163211) , 
4, 0.0578212, 1, 0, 0.516697,0.00853551) , 
7, -0.146461, 1, 0, 0.507555,-0.00129456)    );
  // itree = 709
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.45498,0.00716654) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.551712,-0.00356595) , 
7, -0.700271, 1, 0, 0.52137,-0.000569315) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266667,-0.0041932) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575916,0.0231699) , 
4, 0.0578657, 1, 0, 0.453586,0.0240118) , 
7, 1.00607, 1, 0, 0.508386,0.00413929)    );
  // itree = 710
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.257042,-0.0205581) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541752,0.00796167) , 
7, -1.80253, 1, 0, 0.512231,0.01111) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503739,-0.00178968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.310881,-0.0164328) , 
6, 2.30314, 1, 0, 0.470771,-0.00925718) , 
7, 0.141508, 1, 0, 0.493496,0.00190665)    );
  // itree = 711
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.279102,0.0165369) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.609148,-0.0123538) , 
2, 55938.8, 1, 0, 0.41206,0.0103045) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506446,-0.00314983) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.776062,-0.029653) , 
0, 132188, 1, 0, 0.524693,-0.00941387) , 
8, -0.0230261, 1, 0, 0.497909,-0.00472481)    );
  // itree = 712
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501335,-0.000839446) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.270588,0.0289549) , 
7, 2.13479, 1, 0, 0.492928,1.20207e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485294,-0.0307735) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.881081,-0.00532623) , 
4, 0.287164, 1, 0, 0.713396,-0.0349963) , 
1, 11.0476, 1, 0, 0.507119,-0.00224137)    );
  // itree = 713
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515643,-0.00602231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532405,0.00326543) , 
7, 0.141508, 1, 0, 0.523116,-0.0037717) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.224138,-0.00880311) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.131944,-0.0521855) , 
0, 45319.7, 1, 0, 0.18239,-0.0448879) , 
8, 0.071974, 1, 0, 0.501403,-0.00639193)    );
  // itree = 714
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501609,-0.00362482) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511494,0.00530082) , 
7, 0.188993, 1, 0, 0.505834,0.000815407) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.324468,0.036323) , 
7, 2.13845, 1, 0, 0.499113,0.00323183)    );
  // itree = 715
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.611111,-0.00790142) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477997,0.00306522) , 
1, 1.47619, 1, 0, 0.514341,-0.00075144) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569136,0.0197706) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323829,-0.00240039) , 
7, 1.476, 1, 0, 0.476557,0.0240663) , 
7, 0.717692, 1, 0, 0.504364,0.00580181)    );
  // itree = 716
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.676349,0.0107736) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503597,-0.00893274) , 
7, 1.28824, 1, 0, 0.658482,0.0193174) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47336,-0.00412589) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381264,0.00830087) , 
8, 0.0244739, 1, 0, 0.450367,-0.00268684) , 
1, 1.47619, 1, 0, 0.506074,0.00320316)    );
  // itree = 717
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.637427,0.00776225) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393831,-0.00134345) , 
1, 1.90476, 1, 0, 0.462006,0.00308969) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.679012,0.0294706) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591346,-0.00548489) , 
7, 0.441928, 1, 0, 0.649266,0.0289439) , 
0, 79836.4, 1, 0, 0.485481,0.00633071)    );
  // itree = 718
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422118,0.0163156) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.295597,-0.00471702) , 
4, 0.0257361, 1, 0, 0.368186,0.0204457) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521617,-0.00566822) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.752941,-0.0329683) , 
4, 0.364953, 1, 0, 0.537071,-0.0138402) , 
4, 0.0384156, 1, 0, 0.498784,-0.00606756)    );
  // itree = 719
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521026,0.0146985) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288591,-0.0151397) , 
8, 0.0282183, 1, 0, 0.466614,0.016028) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.30868,-0.011281) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.759191,0.00231605) , 
2, 55524, 1, 0, 0.51411,-0.0132225) , 
7, -0.70307, 1, 0, 0.501649,-0.00554816)    );
  // itree = 720
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.241011,-0.0039643) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.471302,0.0174736) , 
5, 1788.08, 1, 0, 0.327466,0.0118931) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.880328,0.000207626) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.817043,-0.0246401) , 
7, 0.683223, 1, 0, 0.864731,-0.00868921) , 
5, 4674.87, 1, 0, 0.504477,0.00511189)    );
  // itree = 721
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.283627,0.00473581) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.640333,-0.00601677) , 
2, 42592, 1, 0, 0.479043,-0.000906698) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38961,-0.0226369) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.916376,-0.00595994) , 
5, 10439.1, 1, 0, 0.643698,-0.0301937) , 
1, 8.28571, 1, 0, 0.498696,-0.00440234)    );
  // itree = 722
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491422,0.0085899) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54512,0.000202763) , 
7, -0.520736, 1, 0, 0.523646,0.00709187) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.400264,-0.00845808) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336585,-0.027511) , 
0, 59100.9, 1, 0, 0.386694,-0.0264597) , 
7, 1.00018, 1, 0, 0.497521,0.000691588)    );
  // itree = 723
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528017,0.00102934) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.195946,-0.0351809) , 
7, 2.13543, 1, 0, 0.518013,0.000420141) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404669,0.0235349) , 
6, 3.89551, 1, 0, 0.512379,0.003024)    );
  // itree = 724
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247423,-0.0165516) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493266,0.0169507) , 
7, -1.76451, 1, 0, 0.412429,0.0135258) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.398878,-0.00518399) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.845921,0.0059014) , 
4, 0.247738, 1, 0, 0.509195,-0.00717167) , 
7, -1.00242, 1, 0, 0.49175,-0.00344031)    );
  // itree = 725
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.397059,0.0630152) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.261194,-0.00221764) , 
0, 39079.8, 1, 0, 0.32963,0.0496288) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507312,0.000369374) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.759399,-0.0345345) , 
4, 0.380932, 1, 0, 0.514322,-0.000762369) , 
7, -1.85265, 1, 0, 0.504453,0.00193021)    );
  // itree = 726
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.367778,-0.00410978) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208955,-0.0292696) , 
0, 62865.7, 1, 0, 0.338783,-0.0209363) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552916,0.00295245) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.319444,0.0351905) , 
7, 2.14085, 1, 0, 0.544179,0.00796146) , 
4, 0.0384374, 1, 0, 0.498485,0.0015326)    );
  // itree = 727
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343705,0.00272127) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.725707,-0.0114971) , 
2, 58265.6, 1, 0, 0.510902,-0.0041085) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.200297,-0.0231651) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62426,0.00135042) , 
2, 47647.1, 1, 0, 0.412593,-0.0244298) , 
7, 0.711781, 1, 0, 0.484699,-0.00952483)    );
  // itree = 728
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.212644,0.00394419) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313953,-0.0394398) , 
4, 0.0573735, 1, 0, 0.273148,-0.0439491) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540987,0.00284809) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362595,0.0362844) , 
7, 1.9027, 1, 0, 0.530996,0.00940353) , 
7, -1.5687, 1, 0, 0.509198,0.00489308)    );
  // itree = 729
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664577,0.0188683) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.462998,-6.62769e-05) , 
0, 26579.1, 1, 0, 0.496842,0.00658199) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497537,-0.0240259) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528653,-0.00470593) , 
6, 1.47518, 1, 0, 0.51721,-0.022344) , 
0, 58148.4, 1, 0, 0.501427,7.01079e-05)    );
  // itree = 730
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53188,0.00686212) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469971,-0.00330679) , 
7, 0.424013, 1, 0, 0.50949,0.0063252) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289916,-0.0191554) , 
6, 3.89583, 1, 0, 0.498996,0.00364413)    );
  // itree = 731
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512086,-0.00679334) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561181,0.00384482) , 
0, 53285.5, 1, 0, 0.524194,-0.00900341) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.354582,-0.0174528) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432632,0.00956106) , 
7, -1.02616, 1, 0, 0.41632,0.00766458) , 
8, 0.0258102, 1, 0, 0.498513,-0.00503547)    );
  // itree = 732
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.446565,0.00407985) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.532755,-0.00547847) , 
8, -0.0124458, 1, 0, 0.503841,-0.00500984) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308824,-0.023772) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235714,-0.0200126) , 
7, 2.23567, 1, 0, 0.271739,-0.0376512) , 
7, 1.85442, 1, 0, 0.490931,-0.00682544)    );
  // itree = 733
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517957,0.002423) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529825,-0.0127962) , 
7, 0.00382678, 1, 0, 0.519169,0.0015475) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49218,0.0061449) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.782353,0.0304077) , 
0, 112277, 1, 0, 0.51444,0.0164906) , 
7, 0.153081, 1, 0, 0.517076,0.00816104)    );
  // itree = 734
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545087,-0.00279398) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405882,-0.0278353) , 
7, 1.57731, 1, 0, 0.535223,-0.0106433) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488541,0.00784729) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420126,-0.00481435) , 
6, 1.65807, 1, 0, 0.467492,0.00777485) , 
1, 2.57143, 1, 0, 0.5001,-0.00109232)    );
  // itree = 735
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505732,0.00128009) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.450382,-0.00666951) , 
7, 0.430357, 1, 0, 0.485913,-0.00320147) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.841727,0.0301334) , 
4, 0.380338, 1, 0, 0.496016,-0.00170759)    );
  // itree = 736
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405343,0.00445143) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.211055,0.0509815) , 
1, 3.47619, 1, 0, 0.368868,0.0256747) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.485635,0.0102027) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541931,-0.00788073) , 
8, -0.0169638, 1, 0, 0.525784,-0.00526456) , 
4, 0.0383832, 1, 0, 0.49129,0.00153668)    );
  // itree = 737
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.639098,0.0277636) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.233596,3.26682e-05) , 
6, 0.890163, 1, 0, 0.400309,0.0229524) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517834,-0.0113759) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519442,-0.000676604) , 
7, -0.661478, 1, 0, 0.519171,-0.00545235) , 
7, -1.27163, 1, 0, 0.504189,-0.00187201)    );
  // itree = 738
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333333,0.00535888) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313916,-0.0232488) , 
8, -0.0125431, 1, 0, 0.320346,-0.0284223) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.241935,-0.0226587) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528714,0.00315018) , 
8, -0.0661916, 1, 0, 0.509063,0.00370083) , 
7, -1.54564, 1, 0, 0.491576,0.000724317)    );
  // itree = 739
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358974,-0.0202367) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337268,0.00579723) , 
4, 0.013549, 1, 0, 0.338944,0.00778641) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.768813,-0.00226007) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.704846,-0.0237713) , 
8, 0.0133848, 1, 0, 0.746701,-0.0167233) , 
4, 0.13392, 1, 0, 0.4996,-0.00187043)    );
  // itree = 740
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388783,0.0172929) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.232558,-0.0287275) , 
0, 73793.3, 1, 0, 0.371719,0.0298457) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.245245,-0.0116571) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.629114,0.00179281) , 
4, 0.0728916, 1, 0, 0.531931,-0.00377233) , 
4, 0.0384374, 1, 0, 0.495026,0.00397156)    );
  // itree = 741
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493572,-0.00228583) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.476834,-0.0217919) , 
7, -0.154256, 1, 0, 0.490356,-0.0124579) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47998,0.00571798) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608871,-0.0179312) , 
0, 96467.9, 1, 0, 0.494055,0.0063349) , 
7, 0.144671, 1, 0, 0.492048,-0.00386553)    );
  // itree = 742
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.209901,0.00126942) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.609091,0.0212911) , 
4, 0.0955124, 1, 0, 0.395767,0.0197756) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.512381,-0.0014939) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.757576,0.0155363) , 
1, 10.3333, 1, 0, 0.531992,-0.000925601) , 
8, -0.030918, 1, 0, 0.506606,0.00293215)    );
  // itree = 743
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407602,-0.0144924) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.626263,0.0237965) , 
0, 79846.4, 1, 0, 0.432715,-0.0199843) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550104,0.000555323) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.406863,0.0135186) , 
7, 1.29404, 1, 0, 0.532405,0.00452725) , 
8, -0.0126392, 1, 0, 0.498209,-0.00388062)    );
  // itree = 744
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469388,0.00933867) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.35461,-0.0169842) , 
4, 0.0108892, 1, 0, 0.393939,-0.0200769) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561463,0.0078982) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486826,0.001641) , 
1, 2.7619, 1, 0, 0.5207,0.00993047) , 
4, 0.0199342, 1, 0, 0.509705,0.00732773)    );
  // itree = 745
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.39,0.031692) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539394,-0.00910778) , 
2, 49589, 1, 0, 0.457534,0.0455136) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517171,-0.0010221) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.405797,0.0106597) , 
7, 1.28162, 1, 0, 0.501879,0.00121194) , 
4, 0.0194378, 1, 0, 0.498568,0.00452006)    );
  // itree = 746
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488039,-0.00198991) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.349693,0.0214687) , 
6, 3.89583, 1, 0, 0.483175,-0.00208159) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.761905,0.0448841) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.735294,0.00127879) , 
1, 11.5714, 1, 0, 0.752044,0.0426405) , 
3, 0.047619, 1, 0, 0.502898,0.00119904)    );
  // itree = 747
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499506,-0.00279801) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442882,-0.0149353) , 
7, 0.423585, 1, 0, 0.47914,-0.0159195) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360856,-0.0120718) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.568059,0.0103709) , 
7, -0.985968, 1, 0, 0.530646,0.0108669) , 
1, 4, 1, 0, 0.497889,-0.00616875)    );
  // itree = 748
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464567,0.0106269) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516761,-0.00255387) , 
4, 0.01941, 1, 0, 0.512454,-0.00236821) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375,-0.0262426) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.224299,-0.00441649) , 
6, 1.1773, 1, 0, 0.30137,-0.0360365) , 
7, 1.56893, 1, 0, 0.494164,-0.00528546)    );
  // itree = 749
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.232143,0.0255594) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523626,0.00145507) , 
8, -0.0847363, 1, 0, 0.510304,0.0046373) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.208333,-0.0350142) , 
6, 4.8145, 1, 0, 0.501685,0.00217916)    );
  // itree = 750
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464257,-0.00135193) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.911877,0.0254527) , 
2, 134816, 1, 0, 0.507161,-0.000123744) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306306,0.0156156) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.672269,0.00256433) , 
2, 43680, 1, 0, 0.513865,0.0188373) , 
7, 0.141508, 1, 0, 0.510237,0.00857475)    );
  // itree = 751
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.491503,0.0052291) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.308057,-0.0100552) , 
0, 56732.5, 1, 0, 0.469271,0.00707677) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.577438,-0.000760887) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.476804,-0.0198945) , 
7, 0.718364, 1, 0, 0.550209,-0.0116073) , 
1, 4.42857, 1, 0, 0.49288,0.0016266)    );
  // itree = 752
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521384,-0.0080091) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320388,0.0118369) , 
7, 1.85389, 1, 0, 0.510704,-0.0147152) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428571,0.00827797) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258427,-0.0192996) , 
7, 1.18933, 1, 0, 0.402098,0.00823388) , 
8, 0.0283027, 1, 0, 0.485959,-0.00948638)    );
  // itree = 753
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513032,-0.00257925) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498199,0.00567586) , 
7, 0.437409, 1, 0, 0.507771,0.000732117) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395918,0.0291429) , 
6, 3.98089, 1, 0, 0.502226,0.00379073)    );
  // itree = 754
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.69612,-0.00705533) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341138,0.00610672) , 
6, 0.886223, 1, 0, 0.495626,0.00163281) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.74,-0.0367496) , 
0, 190736, 1, 0, 0.502863,8.57874e-06)    );
  // itree = 755
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504667,-0.00146916) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.369287,0.0120094) , 
7, 1.27637, 1, 0, 0.486038,0.000639962) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464567,-0.0259131) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543974,-0.0105056) , 
1, 1.33333, 1, 0, 0.534351,-0.0262576) , 
0, 60731, 1, 0, 0.496118,-0.00497195)    );
  // itree = 756
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285394,-0.00131835) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.680921,0.00759526) , 
2, 47118.9, 1, 0, 0.491638,0.00585014) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.753968,0.0352418) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.893491,0.0307711) , 
2, 170526, 1, 0, 0.833898,0.0540894) , 
0, 132186, 1, 0, 0.511998,0.00871978)    );
  // itree = 757
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492444,0.00137667) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428302,-0.0144236) , 
0, 66339.9, 1, 0, 0.48521,-0.000839384) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.723757,0.0231858) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.888889,0.00104161) , 
4, 0.305509, 1, 0, 0.794304,0.0317595) , 
0, 121729, 1, 0, 0.504686,0.0012147)    );
  // itree = 758
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501885,-0.00147088) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.687266,0.0156019) , 
0, 85395.8, 1, 0, 0.52382,0.000490713) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356688,-0.00712323) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.206349,-0.0473411) , 
8, 0.0196411, 1, 0, 0.313636,-0.034271) , 
7, 1.56893, 1, 0, 0.505148,-0.00259734)    );
  // itree = 759
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.613149,-0.00102335) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314495,-0.0120624) , 
6, 1.19687, 1, 0, 0.494272,-0.0113) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296296,0.026522) , 
6, 4.81051, 1, 0, 0.488857,-0.00953573)    );
  // itree = 760
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.21875,5.73432e-06) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614943,0.0237989) , 
4, 0.0761856, 1, 0, 0.439232,0.0239822) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53211,-0.017997) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508049,-0.0017831) , 
7, -0.619484, 1, 0, 0.511258,-0.00821256) , 
7, -1.00043, 1, 0, 0.497811,-0.00220167)    );
  // itree = 761
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.327957,-0.0121081) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392714,-0.00595611) , 
4, 0.0329559, 1, 0, 0.376327,-0.0174161) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.791887,0.00501616) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.902778,-0.0353217) , 
2, 177384, 1, 0, 0.804382,0.00403712) , 
4, 0.228553, 1, 0, 0.486776,-0.0118806)    );
  // itree = 762
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328859,-0.0061367) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.600181,0.00810083) , 
4, 0.0547667, 1, 0, 0.510578,0.00550931) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.714286,-0.0331413) , 
4, 0.380671, 1, 0, 0.516979,0.00335163)    );
  // itree = 763
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513992,-0.00375744) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.346977,0.0130065) , 
0, 40453.8, 1, 0, 0.462767,0.00334496) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.105495,-0.0313502) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.732407,-0.00306366) , 
4, 0.153044, 1, 0, 0.54658,-0.0192779) , 
1, 4.42857, 1, 0, 0.488294,-0.00354515)    );
  // itree = 764
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379878,0.00369645) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.794341,-0.00782422) , 
4, 0.171362, 1, 0, 0.521452,0.00147384) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390698,-0.0290175) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.306156,-0.00309968) , 
1, 1.38095, 1, 0, 0.328431,-0.0234381) , 
8, 0.0368993, 1, 0, 0.490312,-0.00254517)    );
  // itree = 765
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411581,-0.00736345) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567229,0.0057992) , 
8, -0.02587, 1, 0, 0.53605,0.00697981) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507082,-0.0207862) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.454019,-0.00157131) , 
7, 0.670574, 1, 0, 0.464821,-0.0113523) , 
7, 0.424013, 1, 0, 0.510967,0.000524115)    );
  // itree = 766
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504087,0.0174074) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536568,0.00356309) , 
4, 0.0194238, 1, 0, 0.533972,0.0104846) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.109375,-0.0505005) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.22449,-0.0103845) , 
7, -0.641185, 1, 0, 0.189573,-0.0343358) , 
8, 0.0625038, 1, 0, 0.504986,0.00671228)    );
  // itree = 767
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53681,0.0119145) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.157534,-0.000130149) , 
1, 3, 1, 0, 0.384404,0.0197666) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.318721,-0.00655267) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.790846,0.00459855) , 
4, 0.175909, 1, 0, 0.526813,-0.00458363) , 
4, 0.0384167, 1, 0, 0.495805,0.000718369)    );
  // itree = 768
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500235,0.00570727) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.556962,-0.00170532) , 
7, -0.228099, 1, 0, 0.519629,0.00659625) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.435761,-0.00912132) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.702899,0.0186881) , 
1, 10.2857, 1, 0, 0.455939,-0.0150508) , 
7, 0.423879, 1, 0, 0.496642,-0.00121671)    );
  // itree = 769
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340042,0.000342483) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302296,0.0217789) , 
4, 0.0473605, 1, 0, 0.326742,0.0167194) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323777,-0.0148234) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.735308,-0.00136319) , 
4, 0.122482, 1, 0, 0.647776,-0.00909904) , 
4, 0.0763266, 1, 0, 0.505286,0.00236039)    );
  // itree = 770
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.758184,0.00105834) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298658,0.0178511) , 
6, 1.59933, 1, 0, 0.648193,0.0136896) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463686,-0.00221727) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266187,-0.0237047) , 
6, 4.51666, 1, 0, 0.456164,-0.00623984) , 
1, 1.33333, 1, 0, 0.505005,-0.00117097)    );
  // itree = 771
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56056,-0.00119846) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.249383,0.0105329) , 
6, 1.4859, 1, 0, 0.476561,0.00418838) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517949,0.0442403) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.881503,0.00318451) , 
4, 0.229027, 1, 0, 0.750462,0.0414649) , 
0, 91297.9, 1, 0, 0.50595,0.0081881)    );
  // itree = 772
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303405,-0.00220072) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.64,-0.0230593) , 
2, 101769, 1, 0, 0.326982,-0.00809276) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.923213,0.0157261) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.885906,-0.01435) , 
7, 0.699379, 1, 0, 0.915444,0.0103881) , 
5, 5382.4, 1, 0, 0.4954,-0.00280352)    );
  // itree = 773
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470315,-0.00619233) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338182,-0.0229033) , 
8, 0.0339472, 1, 0, 0.443459,-0.0201601) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590734,0.019992) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509983,-0.000521925) , 
7, -0.540737, 1, 0, 0.515538,0.00163947) , 
7, -0.719146, 1, 0, 0.496483,-0.00412349)    );
  // itree = 774
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432653,-0.00279402) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285714,-0.0270454) , 
8, 0.0080063, 1, 0, 0.372881,-0.0341807) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480704,0.0026435) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.737952,-0.0211137) , 
0, 117593, 1, 0, 0.499777,0.00250871) , 
4, 0.0194238, 1, 0, 0.489062,-0.000589375)    );
  // itree = 775
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530269,0.0087916) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432941,-0.00388985) , 
7, 0.716405, 1, 0, 0.503118,0.0123539) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422222,-0.00638847) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.811594,0.0138975) , 
4, 0.342913, 1, 0, 0.490585,-0.00540415) , 
1, 4, 1, 0, 0.498204,0.00539172)    );
  // itree = 776
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534279,-0.0215403) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448335,-0.00773854) , 
1, 1.28571, 1, 0, 0.471142,-0.0248715) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376831,0.00650927) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.520817,-0.00191955) , 
4, 0.0386484, 1, 0, 0.487535,0.00082331) , 
7, -0.431698, 1, 0, 0.482139,-0.00763373)    );
  // itree = 777
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363322,-0.0237186) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.352941,0.00776306) , 
8, 0.0157868, 1, 0, 0.36,-0.0343616) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503685,-0.000433048) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.683099,-0.0299748) , 
1, 14.1429, 1, 0, 0.509201,-0.00243672) , 
4, 0.01941, 1, 0, 0.49663,-0.00512666)    );
  // itree = 778
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380776,-0.0042796) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545455,0.00595114) , 
8, -0.0230261, 1, 0, 0.509165,0.00813421) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.21519,-0.0328793) , 
6, 4.6692, 1, 0, 0.5,0.00551249)    );
  // itree = 779
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519407,-0.00226076) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492063,-0.0259021) , 
7, 1.07876, 1, 0, 0.518243,-0.00659033) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333952,0.0220155) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.717391,-0.00294891) , 
4, 0.247571, 1, 0, 0.412112,0.0327174) , 
7, 1.28345, 1, 0, 0.504202,-0.00138976)    );
  // itree = 780
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422062,0.00973555) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482866,-0.00270075) , 
4, 0.01941, 1, 0, 0.477342,-0.00265744) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550725,0.0282137) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.92562,0.0106978) , 
5, 9215.09, 1, 0, 0.752784,0.0380875) , 
1, 10.6667, 1, 0, 0.501885,0.000973144)    );
  // itree = 781
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.240356,-0.0245174) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538313,-0.0022201) , 
8, -0.0556158, 1, 0, 0.512905,-0.00757379) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474053,0.00557235) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359375,0.0338308) , 
6, 1.77282, 1, 0, 0.443756,0.0250776) , 
7, 1.00576, 1, 0, 0.499289,-0.00114437)    );
  // itree = 782
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.803571,0.0116799) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28629,-0.0135463) , 
6, 0.60139, 1, 0, 0.405992,-0.0166954) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.58312,0.00346073) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428886,-0.00582566) , 
7, 0.712603, 1, 0, 0.531821,0.000848322) , 
7, -0.997821, 1, 0, 0.507792,-0.00250191)    );
  // itree = 783
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381579,-0.0105662) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511929,0.00778435) , 
4, 0.0199473, 1, 0, 0.501454,0.0125739) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217391,-0.0150448) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.768621,0.00424279) , 
4, 0.152496, 1, 0, 0.505804,-0.0111028) , 
0, 55864.2, 1, 0, 0.502506,0.00685052)    );
  // itree = 784
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326768,0.0027621) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531444,0.0133685) , 
4, 0.0764837, 1, 0, 0.407226,0.0156635) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.802469,-0.00989863) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.863192,0.021886) , 
3, 0.047619, 1, 0, 0.816176,-0.00605216) , 
4, 0.228711, 1, 0, 0.517556,0.00980489)    );
  // itree = 785
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.33683,0.00260104) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53933,-0.00839578) , 
4, 0.0573406, 1, 0, 0.456496,-0.00713639) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534351,-0.0197513) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.752066,0.0177406) , 
7, -0.979991, 1, 0, 0.713315,0.0184648) , 
1, 7.38095, 1, 0, 0.494829,-0.00331516)    );
  // itree = 786
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.436435,0.0113009) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.520051,-0.00234101) , 
8, -0.0227476, 1, 0, 0.499681,0.0013153) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.137177,0.00066925) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.648533,-0.0143708) , 
4, 0.0764921, 1, 0, 0.513158,-0.0181892) , 
1, 4, 1, 0, 0.50477,-0.00604929)    );
  // itree = 787
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426871,0.00311667) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381418,-0.0177707) , 
7, -0.149783, 1, 0, 0.400427,-0.019008) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550459,-0.0029684) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5184,0.0144331) , 
7, 0.997963, 1, 0, 0.544843,0.000751378) , 
8, -0.01725, 1, 0, 0.504021,-0.00483401)    );
  // itree = 788
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390181,-0.0025282) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483871,0.0316272) , 
1, 3.85714, 1, 0, 0.426772,0.0156835) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529776,-0.005996) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.410309,0.00557694) , 
7, 0.962875, 1, 0, 0.50321,-0.00743772) , 
7, -1.27005, 1, 0, 0.493496,-0.00449957)    );
  // itree = 789
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496434,0.00290734) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515798,-0.0139156) , 
7, -0.224739, 1, 0, 0.50336,-0.0070961) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.343895,0.00840208) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.861053,-0.00942211) , 
5, 5335.28, 1, 0, 0.482759,0.0111567) , 
7, 0.426726, 1, 0, 0.496133,-0.000693321)    );
  // itree = 790
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526608,0.00397391) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508971,-0.00784983) , 
7, 0.480466, 1, 0, 0.522438,0.00231048) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456311,0.023853) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.232323,-0.00908996) , 
7, 2.02308, 1, 0, 0.383607,0.0282657) , 
7, 1.29221, 1, 0, 0.505797,0.00542163)    );
  // itree = 791
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302789,-0.00373156) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.408555,0.0176258) , 
7, -0.701838, 1, 0, 0.379978,0.0214106) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431548,-0.00687886) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533983,0.00282229) , 
4, 0.0198751, 1, 0, 0.525441,0.0036659) , 
8, -0.030918, 1, 0, 0.498185,0.0069908)    );
  // itree = 792
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360771,-0.0111639) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.544427,0.0015112) , 
7, -1.3678, 1, 0, 0.519953,-1.51658e-05) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.184932,-0.0301725) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477387,-0.00218477) , 
4, 0.0583693, 1, 0, 0.353623,-0.0312159) , 
7, 1.28345, 1, 0, 0.496884,-0.00434251)    );
  // itree = 793
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399313,-0.00191936) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.449839,0.00628555) , 
7, -0.422284, 1, 0, 0.432566,0.00786091) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.665962,-0.0172594) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.982097,0.0217928) , 
5, 10852.3, 1, 0, 0.809028,-0.01671) , 
4, 0.285793, 1, 0, 0.496094,0.00371457)    );
  // itree = 794
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.467635,0.00388624) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.656566,0.0245643) , 
7, -0.540498, 1, 0, 0.489486,0.013494) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439515,-0.00471115) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.855072,0.0152111) , 
4, 0.304956, 1, 0, 0.499109,-0.00590111) , 
7, -0.418036, 1, 0, 0.495866,0.00063519)    );
  // itree = 795
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428161,0.0158082) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486679,-0.00244116) , 
4, 0.0181425, 1, 0, 0.482348,-0.00139548) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.744526,0.0334316) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.992248,0.0450124) , 
5, 8732.59, 1, 0, 0.864662,0.052467) , 
4, 0.361957, 1, 0, 0.502818,0.00148846)    );
  // itree = 796
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495265,0.00336853) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472423,-0.00623193) , 
7, -0.146573, 1, 0, 0.482599,-0.00433401) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.851282,0.0299069) , 
0, 170086, 1, 0, 0.497164,-0.00233605)    );
  // itree = 797
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534356,-0.00860928) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480683,0.00343442) , 
7, 0.716405, 1, 0, 0.520273,-0.0112005) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42521,0.0114945) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.258772,-0.0114572) , 
7, 0.630911, 1, 0, 0.379101,0.0100823) , 
8, 0.0371595, 1, 0, 0.497335,-0.00774228)    );
  // itree = 798
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527501,0.00637736) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72327,-0.0233167) , 
1, 14.7619, 1, 0, 0.534613,0.0115268) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.39779,-0.0393556) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322772,-0.0154738) , 
7, 1.53063, 1, 0, 0.342566,-0.0440872) , 
7, 1.28527, 1, 0, 0.508592,0.00399155)    );
  // itree = 799
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326841,-0.00180606) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.748535,0.00741284) , 
4, 0.133542, 1, 0, 0.488178,0.00265266) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75969,-0.0325663) , 
0, 218449, 1, 0, 0.495134,0.00118729)    );
  // itree = 800
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474088,-0.003179) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.771739,0.0185258) , 
0, 94609, 1, 0, 0.498236,-0.0038534) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.446322,0.00242762) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550481,0.0114185) , 
8, -0.00926542, 1, 0, 0.511236,0.0166114) , 
7, -0.135986, 1, 0, 0.505265,0.00721201)    );
  // itree = 801
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351037,0.00580206) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721782,-0.00256707) , 
4, 0.114577, 1, 0, 0.519082,0.00542101) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302491,-0.026638) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.465205,-0.00544858) , 
4, 0.0388952, 1, 0, 0.430827,-0.022683) , 
7, 0.709104, 1, 0, 0.49535,-0.00213627)    );
  // itree = 802
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492971,-0.00647576) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516421,0.00347281) , 
7, -0.357714, 1, 0, 0.507589,-0.000128795) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445752,-0.00938001) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.740933,0.022734) , 
3, 0.047619, 1, 0, 0.472287,-0.0155673) , 
8, 0.00728363, 1, 0, 0.492369,-0.00678471)    );
  // itree = 803
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28777,0.020238) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517609,-0.00717728) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470588,0.00164625) , 
7, 0.550016, 1, 0, 0.502621,-0.00896196) , 
7, -2.14237, 1, 0, 0.496764,-0.00775897)    );
  // itree = 804
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338604,0.00144247) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.193452,-0.0265108) , 
0, 61577.7, 1, 0, 0.316129,-0.00571414) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509477,0.0129335) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.785815,-0.000902947) , 
4, 0.21502, 1, 0, 0.652935,0.0128199) , 
4, 0.0764743, 1, 0, 0.504173,0.00463367)    );
  // itree = 805
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.265176,-0.0158547) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517533,0.00744885) , 
7, -1.5407, 1, 0, 0.495719,0.0127253) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497492,-0.0134157) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.883598,0.0283488) , 
2, 177454, 1, 0, 0.55018,-0.0145662) , 
1, 4.42857, 1, 0, 0.510787,0.00517463)    );
  // itree = 806
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.51431,0.000443786) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458686,-0.0114871) , 
7, 0.700006, 1, 0, 0.502662,-0.00437098) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.150183,0.00214823) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614458,0.0228039) , 
5, 2519.19, 1, 0, 0.32574,0.0211124) , 
7, 1.56954, 1, 0, 0.486962,-0.00210957)    );
  // itree = 807
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499003,-0.000204366) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419459,0.0125337) , 
0, 50603.4, 1, 0, 0.482417,0.00543385) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.678261,-0.023974) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72,0.00932565) , 
7, 0.410519, 1, 0, 0.692308,-0.0177024) , 
1, 9.33333, 1, 0, 0.504439,0.00300632)    );
  // itree = 808
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336232,0.00708973) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.658806,-0.00211647) , 
4, 0.0764055, 1, 0, 0.516706,0.00511686) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322835,-0.0344615) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.158824,-0.0031854) , 
6, 1.01866, 1, 0, 0.228956,-0.034703) , 
7, 1.84321, 1, 0, 0.4996,0.00274967)    );
  // itree = 809
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361049,-0.00611509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.735829,0.00358614) , 
4, 0.0769126, 1, 0, 0.55243,-0.00434711) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.407108,0.0069429) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.255172,0.0434588) , 
8, 0.0679255, 1, 0, 0.391179,0.0205155) , 
6, 1.65468, 1, 0, 0.508226,0.00246854)    );
  // itree = 810
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52381,0.0387358) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.436441,-0.00751982) , 
4, 0.01214, 1, 0, 0.472772,0.0332842) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494183,-0.00163766) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.775676,0.02154) , 
3, 0.047619, 1, 0, 0.517349,-0.000697613) , 
4, 0.0194206, 1, 0, 0.513673,0.00210416)    );
  // itree = 811
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529336,-0.00272982) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.288,0.0244373) , 
7, 2.13977, 1, 0, 0.521815,-0.00408935) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456876,0.0196485) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321429,-0.000976492) , 
1, 2.57143, 1, 0, 0.381894,0.0195178) , 
8, 0.0331882, 1, 0, 0.494771,0.000473489)    );
  // itree = 812
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.36164,0.00420032) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473893,-0.011733) , 
8, -0.0286523, 1, 0, 0.451734,-0.0203953) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423935,0.0180114) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.626374,-0.00567789) , 
1, 6.14286, 1, 0, 0.559572,0.00427293) , 
1, 4.14286, 1, 0, 0.484255,-0.012956)    );
  // itree = 813
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396947,-0.0160387) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375256,0.0109198) , 
4, 0.0112213, 1, 0, 0.377818,0.01843) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52844,-0.000141234) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.742188,-0.0390111) , 
4, 0.382478, 1, 0, 0.535602,-0.00216787) , 
4, 0.0384111, 1, 0, 0.500101,0.00246656)    );
  // itree = 814
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.4215,-0.00680403) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543539,0.00356399) , 
8, -0.0169638, 1, 0, 0.508628,0.00162454) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.365169,-0.0175662) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.429752,0.0352397) , 
7, -0.118392, 1, 0, 0.402381,0.0297016) , 
6, 3.23597, 1, 0, 0.499595,0.00401165)    );
  // itree = 815
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.406559,-0.00883665) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.658163,0.0229857) , 
0, 91303.2, 1, 0, 0.433775,-0.0120028) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608755,0.00921969) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.460655,-0.0016082) , 
8, 0.0148942, 1, 0, 0.528255,0.00780799) , 
8, -0.00935821, 1, 0, 0.494118,0.000650024)    );
  // itree = 816
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.278689,-0.0228602) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588235,0.0193241) , 
2, 61417.2, 1, 0, 0.397985,-0.0316836) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445572,-3.49846e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.84264,-0.0226844) , 
2, 111048, 1, 0, 0.497352,-0.00353591) , 
4, 0.0194212, 1, 0, 0.489349,-0.00580303)    );
  // itree = 817
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483553,0.000806675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558177,0.010698) , 
7, -0.350711, 1, 0, 0.52639,0.0137729) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304348,-0.0249845) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395299,3.54216e-05) , 
8, -0.0135596, 1, 0, 0.36533,-0.0142271) , 
7, 1.27919, 1, 0, 0.503815,0.0098484)    );
  // itree = 818
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.205714,-0.0147574) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499355,0.013317) , 
7, -2.03063, 1, 0, 0.445263,0.0179469) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.528552,-0.004) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328671,0.0175051) , 
8, 0.0562658, 1, 0, 0.508107,-0.00440452) , 
7, -0.98871, 1, 0, 0.496501,-0.000276633)    );
  // itree = 819
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37723,0.00222179) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.3222,0.0199399) , 
4, 0.0411762, 1, 0, 0.360617,0.0172652) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539731,-0.00412564) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.699085,0.0120316) , 
1, 6.42857, 1, 0, 0.583569,-9.04122e-05) , 
4, 0.0575411, 1, 0, 0.506272,0.00592677)    );
  // itree = 820
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.428771,0.0120399) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.381974,-0.014569) , 
0, 55874.8, 1, 0, 0.417281,0.0106267) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.435631,0.00620109) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.520071,-0.0101428) , 
8, -0.0281419, 1, 0, 0.504356,-0.0153645) , 
7, -0.997742, 1, 0, 0.488093,-0.01051)    );
  // itree = 821
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.228178,-0.0181904) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.643815,0.000985021) , 
4, 0.0953453, 1, 0, 0.438822,-0.0182122) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.547995,0.00483647) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363215,-0.0100148) , 
6, 2.18208, 1, 0, 0.515587,0.00457891) , 
7, -0.71722, 1, 0, 0.495312,-0.00144052)    );
  // itree = 822
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.257143,0.0352521) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508377,-0.00152776) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41688,0.0124604) , 
6, 3.23243, 1, 0, 0.501116,-0.000671152) , 
7, -2.11414, 1, 0, 0.492748,0.00118785)    );
  // itree = 823
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.139535,-0.0353282) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.566144,0.00714967) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46176,-0.000864684) , 
1, 2.7619, 1, 0, 0.512474,0.0074341) , 
7, -2.14237, 1, 0, 0.499388,0.00531115)    );
  // itree = 824
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340633,-0.013912) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.363636,0.00696937) , 
4, 0.0311574, 1, 0, 0.34657,-0.0214584) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325843,0.0090065) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.753929,-0.00195908) , 
4, 0.141652, 1, 0, 0.54904,0.00772965) , 
4, 0.0384111, 1, 0, 0.504289,0.00127835)    );
  // itree = 825
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32371,0.00221578) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.231293,-0.0248178) , 
3, 0.047619, 1, 0, 0.319718,0.00309295) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.765217,-0.0285448) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.909619,-0.00853984) , 
4, 0.179976, 1, 0, 0.877498,-0.0173255) , 
5, 4801.39, 1, 0, 0.494348,-0.00329966)    );
  // itree = 826
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453184,0.0224237) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549618,0.00290521) , 
5, 580.876, 1, 0, 0.484925,0.045881) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505592,0.00241535) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336493,-0.0182501) , 
6, 3.89551, 1, 0, 0.497822,0.00265601) , 
4, 0.0193606, 1, 0, 0.496794,0.00610361)    );
  // itree = 827
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238806,0.0294395) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52349,-0.00688325) , 
2, 56931, 1, 0, 0.340528,0.0294441) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.548986,0.00121078) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362086,-0.0114474) , 
6, 1.98622, 1, 0, 0.508024,-0.003438) , 
7, -1.55423, 1, 0, 0.493959,-0.000676852)    );
  // itree = 828
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266026,-0.0151456) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42203,0.00961604) , 
5, 335.681, 1, 0, 0.378571,0.00418724) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.287582,-0.00837267) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.885173,0.000772992) , 
5, 4888.06, 1, 0, 0.531701,-0.0116366) , 
4, 0.0384374, 1, 0, 0.4974,-0.00809209)    );
  // itree = 829
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.338721,0.00113447) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.765312,0.0137276) , 
4, 0.133413, 1, 0, 0.497406,0.0105297) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.62585,-0.0273907) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.772947,0.00321748) , 
1, 12.4286, 1, 0, 0.686627,-0.0270833) , 
0, 91295.6, 1, 0, 0.516619,0.00671045)    );
  // itree = 830
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.297619,-0.00860832) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.264423,0.00960451) , 
0, 73771.5, 1, 0, 0.294922,-0.016807) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.712974,-0.000184071) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.683623,0.0127606) , 
7, 0.42984, 1, 0, 0.703279,0.00759044) , 
4, 0.0954538, 1, 0, 0.4942,-0.00490105)    );
  // itree = 831
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522087,0.00343509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28169,-0.0168207) , 
6, 3.98717, 1, 0, 0.509754,0.00484048) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.316847,-0.00148742) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.679959,-0.021036) , 
4, 0.115284, 1, 0, 0.473151,-0.0184436) , 
7, 0.148299, 1, 0, 0.493254,-0.00565582)    );
  // itree = 832
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493317,0.00204702) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.872263,0.0275892) , 
4, 0.361653, 1, 0, 0.516577,0.00675709) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336364,-0.0247319) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.259804,-0.00227282) , 
7, 1.97672, 1, 0, 0.299528,-0.0314488) , 
7, 1.57075, 1, 0, 0.49775,0.003443)    );
  // itree = 833
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.445019,0.00289574) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26183,0.0302014) , 
6, 1.491, 1, 0, 0.391743,0.0257871) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614865,-0.0164624) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.51001,0.00356267) , 
1, 1.28571, 1, 0, 0.534289,-0.0027994) , 
4, 0.0386747, 1, 0, 0.502741,0.00352735)    );
  // itree = 834
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320017,-0.00845519) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2331,0.00861788) , 
7, 1.28331, 1, 0, 0.306733,-0.0137609) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.737545,0.0071812) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.6125,-0.0230106) , 
7, 1.31543, 1, 0, 0.723823,0.00665472) , 
4, 0.114468, 1, 0, 0.489387,-0.00482036)    );
  // itree = 835
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333333,-0.0217937) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31767,-0.00175951) , 
4, 0.011253, 1, 0, 0.318467,-0.00719035) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.601093,0.0322927) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.76332,0.00418335) , 
7, -1.47704, 1, 0, 0.749415,0.0121213) , 
4, 0.114547, 1, 0, 0.508251,0.00131426)    );
  // itree = 836
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519177,-0.00226546) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.578988,0.00924452) , 
8, -0.00368214, 1, 0, 0.552044,0.00981358) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.123989,-0.0182437) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565428,0.000318913) , 
4, 0.0580651, 1, 0, 0.4394,-0.00885396) , 
1, 2.7619, 1, 0, 0.493162,5.55462e-05)    );
  // itree = 837
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.688991,0.0115736) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.392405,-0.015237) , 
8, 0.0458486, 1, 0, 0.651442,0.01801) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433233,-0.0109238) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.447266,0.00136057) , 
7, -0.132636, 1, 0, 0.440994,-0.00741505) , 
1, 1.33333, 1, 0, 0.494042,-0.00100615)    );
  // itree = 838
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.493949,0.000811738) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273632,0.0299721) , 
6, 3.85856, 1, 0, 0.484619,0.00447231) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72549,-0.0276339) , 
0, 167915, 1, 0, 0.494545,0.00253162)    );
  // itree = 839
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.0787402,-0.0380326) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.494398,0.00522744) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.721379,0.0192345) , 
1, 7.38095, 1, 0, 0.527846,0.0143309) , 
8, -0.115083, 1, 0, 0.516544,0.0128921)    );
  // itree = 840
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5,0.0289747) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.425532,0.00130938) , 
7, -0.243782, 1, 0, 0.456359,0.0386835) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337553,0.0309804) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52646,-0.00159626) , 
7, -1.83864, 1, 0, 0.516732,-0.0006912) , 
4, 0.019383, 1, 0, 0.511893,0.00246476)    );
  // itree = 841
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506943,-0.00389743) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.811828,0.0291601) , 
1, 9.90476, 1, 0, 0.521638,-0.00549196) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.235816,0.0144137) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.576087,-0.00189531) , 
1, 5.52381, 1, 0, 0.388672,0.015766) , 
6, 1.98589, 1, 0, 0.493754,-0.00103402)    );
  // itree = 842
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523121,-0.00497201) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.277273,-0.027535) , 
6, 3.66018, 1, 0, 0.509687,-0.0128214) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.324074,0.0157809) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46114,0.00195066) , 
4, 0.0384252, 1, 0, 0.431174,0.0112721) , 
7, 0.996545, 1, 0, 0.494216,-0.00807377)    );
  // itree = 843
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.628809,-0.0110141) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479574,0.00344095) , 
1, 1.47619, 1, 0, 0.52002,-0.00184207) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434722,0.0193295) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.552174,-0.00505519) , 
1, 5.95238, 1, 0, 0.463158,0.0283241) , 
7, 0.996701, 1, 0, 0.509098,0.00395208)    );
  // itree = 844
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305118,-0.00562994) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.395385,0.010045) , 
7, -0.138223, 1, 0, 0.355786,0.00796035) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458248,0.00898109) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541382,-0.00555956) , 
7, -1.26982, 1, 0, 0.530813,-0.00725917) , 
4, 0.0386484, 1, 0, 0.490438,-0.00374837)    );
  // itree = 845
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.191083,-0.024909) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357751,-0.000636518) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.758048,0.008657) , 
2, 61935.8, 1, 0, 0.516355,0.00458183) , 
7, -2.14312, 1, 0, 0.506178,0.00334562)    );
  // itree = 846
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335945,0.00641887) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.666667,-0.000648713) , 
4, 0.0764743, 1, 0, 0.519211,0.00623719) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.365517,-0.00966398) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.157233,-0.0311102) , 
7, 2.2853, 1, 0, 0.256579,-0.0379285) , 
7, 1.8502, 1, 0, 0.503771,0.00364072)    );
  // itree = 847
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.242647,0.0203732) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.291188,-0.0304029) , 
7, -2.09489, 1, 0, 0.274559,-0.0306788) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.556448,0.00637284) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484429,-0.00524872) , 
7, -0.0362345, 1, 0, 0.515673,-0.000468815) , 
7, -1.55289, 1, 0, 0.496494,-0.00287182)    );
  // itree = 848
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.389474,-0.00345475) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472131,-0.0206128) , 
7, -1.2597, 1, 0, 0.42902,-0.0239165) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356667,0.0259068) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53287,-0.000608388) , 
8, -0.0555145, 1, 0, 0.518785,0.00226368) , 
7, -0.714948, 1, 0, 0.496022,-0.0043751)    );
  // itree = 849
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.824561,0.0120072) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.246544,-0.0104691) , 
6, 0.512509, 1, 0, 0.366788,-0.0174375) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524024,0.00333107) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.851351,0.02832) , 
0, 189506, 1, 0, 0.536398,0.00815242) , 
4, 0.0384374, 1, 0, 0.499302,0.00255543)    );
  // itree = 850
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.399035,-0.00109621) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.799841,-0.0126785) , 
4, 0.209229, 1, 0, 0.520308,-0.00760458) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.575342,0.0264895) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336973,0.00308055) , 
1, 1.28571, 1, 0, 0.397674,0.0209476) , 
8, 0.0371595, 1, 0, 0.499303,-0.00271414)    );
  // itree = 851
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.424161,-0.0123014) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.678571,0.0213883) , 
1, 8, 1, 0, 0.467742,-0.0161425) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.559573,0.0111743) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.487156,-0.000678797) , 
7, 0.232565, 1, 0, 0.5131,0.00783328) , 
7, -0.418036, 1, 0, 0.497401,-0.000464791)    );
  // itree = 852
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526258,0.00114344) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.465936,0.0108574) , 
7, 0.716405, 1, 0, 0.510582,0.00761521) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.740566,-0.0218939) , 
0, 167915, 1, 0, 0.520094,0.0057533)    );
  // itree = 853
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289362,-0.00369089) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.42953,0.0375366) , 
7, -1.83853, 1, 0, 0.34375,0.0281737) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516094,-0.00176237) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.289062,-0.0253181) , 
6, 4.81051, 1, 0, 0.509904,-0.00539353) , 
7, -1.56634, 1, 0, 0.497342,-0.00285567)    );
  // itree = 854
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.282609,-0.00112078) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.666059,0.00485956) , 
2, 49322.4, 1, 0, 0.469855,0.00308027) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.93188,-0.00712766) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.688525,-0.0215624) , 
6, 2.01765, 1, 0, 0.834697,-0.0225538) , 
4, 0.323127, 1, 0, 0.513514,1.28114e-05)    );
  // itree = 855
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.290598,-0.011899) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549763,0.00689688) , 
7, -1.69739, 1, 0, 0.522239,0.0107048) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488768,-0.0108425) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.335793,0.0171856) , 
7, 1.88267, 1, 0, 0.464943,-0.015214) , 
7, 0.418095, 1, 0, 0.502478,0.00176553)    );
  // itree = 856
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375297,0.0156514) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500116,-0.000922081) , 
7, -1.55547, 1, 0, 0.488978,0.000899553) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.627907,0.0339991) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.895349,0.0108777) , 
4, 0.267863, 1, 0, 0.780731,0.0385939) , 
1, 11.8095, 1, 0, 0.506475,0.00316016)    );
  // itree = 857
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372263,-0.0213377) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455224,0.00371206) , 
7, 0.559894, 1, 0, 0.39951,-0.0361334) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.503523,0.000842619) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572954,0.0122928) , 
0, 55865, 1, 0, 0.520751,0.00695189) , 
4, 0.0196302, 1, 0, 0.510733,0.00339198)    );
  // itree = 858
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.314831,0.00890004) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.774453,-0.00359102) , 
5, 2475.36, 1, 0, 0.486126,0.0114184) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.549788,-0.0176926) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546125,0.00854331) , 
8, 0.0157929, 1, 0, 0.548452,-0.0142666) , 
1, 4.14286, 1, 0, 0.504068,0.00402443)    );
  // itree = 859
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53706,0.00513811) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375,0.0266783) , 
7, 1.85224, 1, 0, 0.528346,0.0135468) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.467669,-0.00857505) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357466,0.022789) , 
7, 1.27956, 1, 0, 0.451966,-0.00912006) , 
8, 0.01642, 1, 0, 0.504524,0.00647739)    );
  // itree = 860
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.155172,-0.028446) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.328846,-0.00132476) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.735519,0.00625363) , 
2, 55524, 1, 0, 0.51647,0.00319234) , 
7, -2.14323, 1, 0, 0.503899,0.00161605)    );
  // itree = 861
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.355076,-0.00791449) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.154908,0.00599017) , 
1, 4, 1, 0, 0.308943,-0.0130729) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.484848,-0.015889) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.758041,0.00778636) , 
7, -1.54694, 1, 0, 0.73742,0.00981631) , 
4, 0.114468, 1, 0, 0.495713,-0.00309569)    );
  // itree = 862
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480287,-7.60459e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423841,0.0261791) , 
0, 53366.5, 1, 0, 0.460465,0.0247512) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483971,-0.00329678) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.919298,0.0220411) , 
2, 166572, 1, 0, 0.511566,-0.00499082) , 
4, 0.0194817, 1, 0, 0.507105,-0.00239458)    );
  // itree = 863
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.43196,-0.00139644) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312121,-0.0309993) , 
7, 0.720468, 1, 0, 0.396994,-0.0198855) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.351313,-0.00143613) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.640721,0.00556417) , 
4, 0.0582151, 1, 0, 0.534805,0.00547469) , 
8, -0.0230261, 1, 0, 0.503513,-0.000283669)    );
  // itree = 864
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.807185,-0.00702523) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.397805,0.00492647) , 
6, 0.625208, 1, 0, 0.537194,0.00387518) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375,-0.0137207) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273504,0.00797372) , 
8, 0.0334484, 1, 0, 0.353211,-0.0184738) , 
6, 1.98961, 1, 0, 0.497841,-0.000905114)    );
  // itree = 865
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464442,-0.00122985) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522523,0.0134179) , 
1, 4.28571, 1, 0, 0.475792,0.00196845) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.678218,0.00432527) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.67341,-0.0325686) , 
7, -0.311011, 1, 0, 0.675182,-0.0300949) , 
1, 9.33333, 1, 0, 0.497251,-0.0014822)    );
  // itree = 866
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.476552,0.00691609) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537957,-0.00428219) , 
7, -0.60858, 1, 0, 0.518813,-0.00173195) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.194346,0.00529774) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.666667,0.0343502) , 
4, 0.114718, 1, 0, 0.372247,0.031771) , 
7, 1.56496, 1, 0, 0.505779,0.00124755)    );
  // itree = 867
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347222,-0.0080712) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312265,0.0121277) , 
4, 0.0330405, 1, 0, 0.326711,0.00742331) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.623482,-0.0108671) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.668127,0.00135058) , 
7, -0.416664, 1, 0, 0.652452,-0.00569663) , 
4, 0.0765117, 1, 0, 0.507186,0.00015426)    );
  // itree = 868
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.223938,-0.0276878) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522143,-0.00184472) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.320574,0.0266296) , 
7, 2.06882, 1, 0, 0.513228,-0.00154989) , 
7, -1.85788, 1, 0, 0.498194,-0.00359863)    );
  // itree = 869
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523831,0.00096825) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.334483,-0.00703951) , 
1, 2.95238, 1, 0, 0.434358,-0.00501776) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.558011,0.01382) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.943878,0.00213508) , 
5, 4752.09, 1, 0, 0.853056,0.012133) , 
4, 0.304397, 1, 0, 0.497927,-0.00241382)    );
  // itree = 870
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.37099,0.0130257) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.378049,-0.00107689) , 
7, 0.364534, 1, 0, 0.373558,0.0193426) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567,6.01801e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.429178,-0.0128348) , 
7, 1.00018, 1, 0, 0.541415,-0.0044028) , 
4, 0.0386747, 1, 0, 0.503043,0.0010254)    );
  // itree = 871
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506247,0.000946185) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.286082,-0.0167403) , 
7, 1.56636, 1, 0, 0.48811,-0.00108322) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.863636,0.0339828) , 
0, 157592, 1, 0, 0.50326,0.0010094)    );
  // itree = 872
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.268456,0.0276658) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.48079,-0.0080381) , 
7, -2.11417, 1, 0, 0.474065,-0.0154911) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827586,0.0232254) , 
0, 145775, 1, 0, 0.490681,-0.0128847)    );
  // itree = 873
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.254576,-0.00181406) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530822,-0.0161519) , 
5, 2597.76, 1, 0, 0.309581,-0.0105142) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565,0.0223925) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.780161,0.00359843) , 
4, 0.159351, 1, 0, 0.759322,0.0101926) , 
4, 0.13395, 1, 0, 0.495398,-0.00195887)    );
  // itree = 874
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323232,-0.00495253) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.634349,0.0113031) , 
4, 0.0581692, 1, 0, 0.531528,0.0101961) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.356201,0.0136831) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513613,-0.0066301) , 
8, -0.0343143, 1, 0, 0.487549,-0.00740436) , 
7, 0.136315, 1, 0, 0.511334,0.00211436)    );
  // itree = 875
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516044,-0.0100227) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522624,0.00839935) , 
7, 0.973732, 1, 0, 0.517286,-0.0169184) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.225,0.00747609) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.874257,-0.0057469) , 
5, 5321.28, 1, 0, 0.472453,0.00679463) , 
1, 2.95238, 1, 0, 0.493491,-0.00433287)    );
  // itree = 876
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466637,-0.00141106) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.687285,0.0380468) , 
1, 9.14286, 1, 0, 0.479967,0.000798322) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.537931,-0.049194) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.878788,-0.0155907) , 
4, 0.270777, 1, 0, 0.719355,-0.0566699) , 
0, 134673, 1, 0, 0.494441,-0.00267645)    );
  // itree = 877
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.417404,0.0140674) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541336,0.001294) , 
7, -1.25647, 1, 0, 0.52301,0.0064005) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.337079,-0.0324844) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.238318,-0.0142741) , 
7, 1.90895, 1, 0, 0.283163,-0.0485981) , 
7, 1.56636, 1, 0, 0.504119,0.00206869)    );
  // itree = 878
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.479504,-0.00198037) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.779006,0.0223012) , 
1, 10.6667, 1, 0, 0.501744,-0.00103245) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.413043,0.0280571) , 
6, 4.81081, 1, 0, 0.499302,0.00085978)    );
  // itree = 879
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.605263,0.0250629) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.666058,0.00398488) , 
8, -0.0242408, 1, 0, 0.654185,0.0185871) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.465276,-0.000115387) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.229412,-0.0216212) , 
7, 1.56636, 1, 0, 0.443572,-0.00375901) , 
1, 1.33333, 1, 0, 0.500297,0.00225947)    );
  // itree = 880
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488652,0.00836823) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522444,-0.000821832) , 
7, -0.537202, 1, 0, 0.511687,0.0041003) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.20339,-0.0229018) , 
7, 2.13981, 1, 0, 0.500512,0.00235799)    );
  // itree = 881
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.305263,-0.0397267) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.277778,0.00894327) , 
1, 2.61905, 1, 0, 0.290094,-0.0327197) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463235,0.0180566) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533702,0.00210574) , 
8, -0.0290861, 1, 0, 0.525221,0.00833659) , 
8, -0.0555145, 1, 0, 0.505057,0.00481558)    );
  // itree = 882
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.184762,-0.00927007) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602729,0.00319857) , 
2, 27747.3, 1, 0, 0.511069,0.000375006) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.25,-0.0270391) , 
6, 4.29483, 1, 0, 0.501408,-0.00181311)    );
  // itree = 883
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.209344,-0.0103377) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382812,0.00202594) , 
5, 966.896, 1, 0, 0.297572,-0.00927184) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.421281,0.0114167) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.776568,0.000571892) , 
4, 0.153718, 1, 0, 0.661754,0.00873377) , 
4, 0.0767044, 1, 0, 0.500489,0.000760609)    );
  // itree = 884
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217722,-0.0230403) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.317726,-0.00506141) , 
7, -0.98884, 1, 0, 0.29968,-0.0184835) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.665428,-0.00179251) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.643991,0.0144306) , 
7, 0.437409, 1, 0, 0.658589,0.00652989) , 
4, 0.0764185, 1, 0, 0.5,-0.00452266)    );
  // itree = 885
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524351,0.0210748) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.257143,-0.0132258) , 
6, 1.61087, 1, 0, 0.440848,0.0231447) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.539924,-0.014918) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52692,0.00377966) , 
7, -0.609152, 1, 0, 0.528554,0.00293677) , 
7, -0.98884, 1, 0, 0.513088,0.0065003)    );
  // itree = 886
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.291385,-0.0048285) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.347935,0.00895346) , 
7, -0.146461, 1, 0, 0.323868,0.0069589) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527687,-0.0176291) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.805211,-0.00107833) , 
4, 0.196142, 1, 0, 0.728661,-0.0117657) , 
4, 0.114547, 1, 0, 0.503794,-0.00136398)    );
  // itree = 887
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53706,0.00975726) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.296774,-0.0239501) , 
6, 3.45145, 1, 0, 0.51638,0.0140974) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.438662,0.0123446) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5,-0.00563937) , 
4, 0.0196467, 1, 0, 0.494986,-0.00791979) , 
7, -0.431698, 1, 0, 0.502553,-0.000132467)    );
  // itree = 888
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.647059,-0.0102509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.376761,0.0259312) , 
1, 1.33333, 1, 0, 0.464286,0.0356075) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.294072,-0.00637261) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.587941,0.00230992) , 
4, 0.0555286, 1, 0, 0.503111,-0.0011554) , 
4, 0.0193672, 1, 0, 0.499797,0.00198289)    );
  // itree = 889
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321897,0.00178439) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329114,0.0304282) , 
0, 78569, 1, 0, 0.322311,0.00789598) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.608911,-0.0219742) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.750434,-0.00130351) , 
7, -0.996004, 1, 0, 0.723604,-0.00990879) , 
4, 0.114433, 1, 0, 0.49744,0.000125764)    );
  // itree = 890
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.214058,-0.00438065) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.557143,-0.0301272) , 
4, 0.172279, 1, 0, 0.320088,-0.0228359) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505826,0.00207938) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.79562,-0.0219624) , 
4, 0.38093, 1, 0, 0.514148,0.00325722) , 
7, -1.57265, 1, 0, 0.49732,0.000994552)    );
  // itree = 891
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561246,0.0039841) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332893,-0.00542468) , 
8, 0.0369837, 1, 0, 0.523212,0.00515952) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.28223,-0.0216426) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31875,0.00574577) , 
0, 48084.5, 1, 0, 0.295302,-0.0233207) , 
7, 1.56496, 1, 0, 0.502804,0.00260931)    );
  // itree = 892
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.3714,0.0171536) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.673469,-0.0218769) , 
2, 101769, 1, 0, 0.409879,0.0337822) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.461318,-0.00953369) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561568,0.0057825) , 
7, -0.996004, 1, 0, 0.543076,0.00566833) , 
4, 0.038417, 1, 0, 0.511948,0.0122385)    );
  // itree = 893
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434298,-0.011423) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.950617,0.0100534) , 
2, 56425.9, 1, 0, 0.594781,-0.0211055) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.475925,-0.00204287) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.290411,0.0147399) , 
7, 1.56496, 1, 0, 0.457969,-0.00100921) , 
1, 1.47619, 1, 0, 0.493102,-0.00616993)    );
  // itree = 894
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.541171,-0.00209188) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.197452,-0.0280172) , 
7, 2.13236, 1, 0, 0.528021,-0.00636473) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.216401,-0.00252744) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591371,0.0257096) , 
2, 46177.8, 1, 0, 0.393757,0.0191225) , 
8, 0.0368993, 1, 0, 0.505368,-0.00206437)    );
  // itree = 895
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499355,-0.0023769) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.388406,0.0120827) , 
0, 50404.5, 1, 0, 0.479167,0.000694355) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.545852,-0.0217312) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.857143,0.0129442) , 
4, 0.362255, 1, 0, 0.599095,-0.0299426) , 
1, 5.90476, 1, 0, 0.506228,-0.00621883)    );
  // itree = 896
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50882,0.00522386) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.477767,-0.00310865) , 
7, 0.145838, 1, 0, 0.494748,0.00303328) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.6,-0.0515487) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.814815,0.00312404) , 
0, 126509, 1, 0, 0.721557,-0.0322806) , 
1, 11.8095, 1, 0, 0.509902,0.000673847)    );
  // itree = 897
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505882,0.00464595) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.137037,-0.0287655) , 
6, 1.30522, 1, 0, 0.342623,-0.0159263) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.590228,0.0145647) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.521284,0.00113413) , 
7, -0.268727, 1, 0, 0.541522,0.0103595) , 
7, -1.28762, 1, 0, 0.516927,0.00710911)    );
  // itree = 898
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303846,0.021875) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572433,0.00444683) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.362866,-0.00452061) , 
6, 1.65836, 1, 0, 0.516382,0.00430067) , 
7, -1.85689, 1, 0, 0.505574,0.00582213)    );
  // itree = 899
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.644928,0.00627507) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466119,-0.00750311) , 
1, 1.28571, 1, 0, 0.512889,-0.00673326) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.508442,0.00450238) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.205742,-0.0189272) , 
8, 0.0634011, 1, 0, 0.480719,0.0058202) , 
7, 0.14194, 1, 0, 0.497967,-0.000910704)    );
  // itree = 900
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.609782,-0.0101576) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.245211,0.00938724) , 
6, 1.76649, 1, 0, 0.530587,-0.0138245) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.139955,-0.0110895) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.527256,0.00529675) , 
4, 0.0383832, 1, 0, 0.461919,0.00421739) , 
1, 2.66667, 1, 0, 0.494731,-0.00440357)    );
  // itree = 901
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.191781,-0.012781) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.47505,0.014356) , 
7, -2.25904, 1, 0, 0.411128,0.0176509) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483945,-0.0146605) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.518704,-0.00349306) , 
7, -0.872727, 1, 0, 0.515275,-0.00941711) , 
7, -1.28117, 1, 0, 0.501974,-0.00596015)    );
  // itree = 902
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.397408,0.00666248) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.773672,-0.012184) , 
2, 83242, 1, 0, 0.486828,0.00662695) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.529374,-0.0038929) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384615,-0.0271447) , 
6, 3.89972, 1, 0, 0.522953,-0.0103071) , 
8, -0.00926542, 1, 0, 0.509909,-0.00419261)    );
  // itree = 903
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536632,0.00463612) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.448075,-0.00676125) , 
7, 0.438948, 1, 0, 0.50518,0.00120817) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.234043,-0.0293359) , 
6, 4.51666, 1, 0, 0.495014,-0.00133006)    );
  // itree = 904
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505829,-0.00534142) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473373,-0.0269573) , 
7, 1.35789, 1, 0, 0.504622,-0.012776) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.231231,0.0238592) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.690476,-0.00948486) , 
5, 4073.98, 1, 0, 0.357298,0.026508) , 
7, 1.57699, 1, 0, 0.491105,-0.00917187)    );
  // itree = 905
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.524906,0.00278319) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455,0.0177393) , 
8, 0.0153583, 1, 0, 0.502558,0.0168791) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509576,-0.00760055) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322917,0.0170777) , 
7, 1.57301, 1, 0, 0.490862,-0.0085938) , 
1, 4, 1, 0, 0.498116,0.00720618)    );
  // itree = 906
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322959,-0.0118415) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326323,-0.00132762) , 
7, 0.141508, 1, 0, 0.324465,-0.0164625) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.776821,-0.000178896) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75286,0.0208018) , 
7, 0.726879, 1, 0, 0.771443,0.0087931) , 
4, 0.152523, 1, 0, 0.497514,-0.00668466)    );
  // itree = 907
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.415233,-0.00686096) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.496084,0.00351791) , 
4, 0.0196467, 1, 0, 0.488961,0.0049098) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.24812,-0.0296759) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.941634,0.00167125) , 
5, 4815.51, 1, 0, 0.705128,-0.0205406) , 
3, 0.047619, 1, 0, 0.505788,0.00292863)    );
  // itree = 908
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411483,0.0224531) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358566,-0.0106261) , 
0, 54106.7, 1, 0, 0.396355,0.0222463) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.542533,0.00369495) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.507862,-0.00569367) , 
8, -0.00870504, 1, 0, 0.516517,-0.00673185) , 
8, -0.0331072, 1, 0, 0.495895,-0.00175867)    );
  // itree = 909
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509683,0.000868307) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.191043,0.0193594) , 
6, 0.917515, 1, 0, 0.332164,0.0228365) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.666258,-0.00321452) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.733803,0.00962111) , 
1, 7.38095, 1, 0, 0.686752,0.000435804) , 
4, 0.0955522, 1, 0, 0.501325,0.0121499)    );
  // itree = 910
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.670085,0.0121899) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.637662,-0.00301182) , 
7, -0.12823, 1, 0, 0.651661,0.00761472) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.453883,-0.0104053) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.282857,0.0112512) , 
7, 1.5743, 1, 0, 0.437466,-0.0167697) , 
1, 1.33333, 1, 0, 0.495501,-0.0101628)    );
  // itree = 911
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.63945,-0.0069928) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.358403,0.00337432) , 
6, 0.98441, 1, 0, 0.501648,-0.00358183) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.373913,0.0184373) , 
6, 3.89583, 1, 0, 0.495869,-0.00154234)    );
  // itree = 912
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.110236,-0.0169042) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393103,0.0232441) , 
8, -0.117785, 1, 0, 0.306954,0.0199001) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321429,0.0192374) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.514528,-0.00627382) , 
7, -1.85689, 1, 0, 0.50624,-0.0116126) , 
8, -0.058551, 1, 0, 0.489567,-0.00897601)    );
  // itree = 913
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.360604,0.00278222) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.757829,-0.0125682) , 
4, 0.132995, 1, 0, 0.470081,-0.00118383) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505958,0.0129786) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.744898,-0.00425609) , 
3, 0.047619, 1, 0, 0.569117,0.0167443) , 
1, 4.42857, 1, 0, 0.499698,0.00417762)    );
  // itree = 914
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.246637,0.000342408) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.563246,-0.0196917) , 
4, 0.095373, 1, 0, 0.4,-0.0179222) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509886,2.5451e-06) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.815972,0.022728) , 
1, 11.8095, 1, 0, 0.53122,0.00250196) , 
7, -0.997821, 1, 0, 0.508505,-0.00103353)    );
  // itree = 915
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.329767,-0.0069623) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.616285,0.00635928) , 
4, 0.0574647, 1, 0, 0.520624,0.00276252) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483474,-0.0130958) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.46238,0.00354307) , 
7, 0.423879, 1, 0, 0.475886,-0.0139779) , 
8, 0.00947285, 1, 0, 0.502837,-0.00389303)    );
  // itree = 916
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.364027,0.0136001) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.224138,-0.00585165) , 
0, 49390.5, 1, 0, 0.327297,0.0201186) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.641066,-0.00646675) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.492462,0.0227479) , 
7, 1.57699, 1, 0, 0.630316,-0.00785444) , 
4, 0.0769126, 1, 0, 0.495363,0.00460372)    );
  // itree = 917
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52493,0.00103485) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.268182,-0.0243045) , 
6, 3.90282, 1, 0, 0.512411,-0.000782557) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.339286,-0.0308907) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.255814,-0.00806435) , 
1, 2.57143, 1, 0, 0.288732,-0.035816) , 
7, 1.56496, 1, 0, 0.493115,-0.00380488)    );
  // itree = 918
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455189,0.0185118) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.561996,-0.00519041) , 
7, -1.28504, 1, 0, 0.549589,-0.00547547) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390129,0.0125385) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.322702,-0.00389291) , 
7, 0.42984, 1, 0, 0.364162,0.0131583) , 
6, 1.65468, 1, 0, 0.498609,-0.000352489)    );
  // itree = 919
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.219251,-0.0181098) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.688341,0.00802756) , 
4, 0.133256, 1, 0, 0.394472,-0.016625) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.516259,0.00422386) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.67757,-0.0312092) , 
1, 11.1429, 1, 0, 0.525617,0.00562459) , 
8, -0.0230261, 1, 0, 0.493549,0.000184076)    );
  // itree = 920
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394877,0.0019394) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.231884,0.021272) , 
6, 1.85949, 1, 0, 0.365385,0.0128123) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.26,-0.00707233) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.682784,0.00194674) , 
4, 0.0901056, 1, 0, 0.526981,-0.00356552) , 
4, 0.0384374, 1, 0, 0.489581,0.000224931)    );
  // itree = 921
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.632075,0.00983687) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.19708,-0.0252759) , 
6, 0.744529, 1, 0, 0.345104,-0.0253821) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.49381,-0.00412553) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533272,0.00613916) , 
8, 0.00118907, 1, 0, 0.513464,0.00220359) , 
7, -1.28117, 1, 0, 0.492351,-0.00125573)    );
  // itree = 922
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.431976,0.00613282) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584677,0.0369161) , 
7, -0.938045, 1, 0, 0.462151,0.0251772) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.416938,-0.0137939) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519611,-0.000347303) , 
4, 0.0196467, 1, 0, 0.511087,-0.00377647) , 
7, -0.716935, 1, 0, 0.498688,0.00355987)    );
  // itree = 923
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.33112,0.00573761) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.652256,-0.00103986) , 
4, 0.0764085, 1, 0, 0.510277,0.00471562) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.333333,0.0431638) , 
7, 2.14085, 1, 0, 0.503737,0.0074971)    );
  // itree = 924
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.455038,-0.0158372) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.943529,0.00465796) , 
2, 56425.9, 1, 0, 0.60905,-0.0309115) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.430992,-0.00449725) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.864286,0.0330113) , 
4, 0.380339, 1, 0, 0.44696,-0.00676864) , 
1, 1.47619, 1, 0, 0.489411,-0.0130916)    );
  // itree = 925
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.540965,-0.00118708) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.414553,0.0109106) , 
6, 1.99032, 1, 0, 0.515666,0.00243331) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.147541,-0.00538668) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.357488,-0.0437965) , 
4, 0.0765283, 1, 0, 0.243902,-0.0375296) , 
8, 0.0625038, 1, 0, 0.49107,-0.00118365)    );
  // itree = 926
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.321056,-0.00573536) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565611,0.00286447) , 
4, 0.0574125, 1, 0, 0.477121,-0.00148892) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.562264,0.0280423) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.902954,-0.0179465) , 
5, 10725.9, 1, 0, 0.723108,0.0268776) , 
0, 96462, 1, 0, 0.501799,0.0013568)    );
  // itree = 927
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.278481,-0.0018404) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505435,-0.0396053) , 
2, 52297.3, 1, 0, 0.377672,-0.0400902) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526991,0.00262006) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.312336,-0.0117323) , 
7, 1.5743, 1, 0, 0.508865,0.00302842) , 
4, 0.01941, 1, 0, 0.497669,-0.000651477)    );
  // itree = 928
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.586038,0.00384754) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.323636,-0.02113) , 
7, 1.56152, 1, 0, 0.565659,0.0043604) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.184588,-0.0160726) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439356,-0.00288893) , 
1, 2.66667, 1, 0, 0.335286,-0.0191238) , 
6, 1.65807, 1, 0, 0.501528,-0.00217708)    );
  // itree = 929
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.517787,-0.00499137) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533505,0.00503473) , 
8, 0.0186689, 1, 0, 0.520611,-0.0064437) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.230469,0.00695554) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.72449,0.0358606) , 
4, 0.190789, 1, 0, 0.367232,0.02839) , 
8, 0.0426282, 1, 0, 0.499005,-0.00153677)    );
  // itree = 930
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.352181,0.00495143) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.665414,-0.00117164) , 
4, 0.0765117, 1, 0, 0.528582,0.0039906) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.530201,0.0349006) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.275956,-0.00321172) , 
7, 1.69354, 1, 0, 0.39006,0.0308368) , 
7, 1.28535, 1, 0, 0.509868,0.00761743)    );
  // itree = 931
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.303318,0.00145405) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.666667,0.0379457) , 
2, 49123.9, 1, 0, 0.472081,0.0404494) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.515292,-0.00777573) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473314,0.00380785) , 
1, 2.66667, 1, 0, 0.493115,-0.00498678) , 
4, 0.0194949, 1, 0, 0.491447,-0.00138407)    );
  // itree = 932
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.543664,-0.0109733) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.384025,0.00734027) , 
6, 1.59272, 1, 0, 0.49586,-0.0118797) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.41619,0.00570174) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.78125,-0.0171984) , 
4, 0.228504, 1, 0, 0.50469,0.00333227) , 
7, -0.146461, 1, 0, 0.500809,-0.0033541)    );
  // itree = 933
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.467944,0.00522802) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.573585,0.0151957) , 
7, -0.581729, 1, 0, 0.517266,0.0206931) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470221,-0.00260149) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.838462,0.0246887) , 
0, 140103, 1, 0, 0.491863,-0.00251469) , 
7, 0.161475, 1, 0, 0.506139,0.0105276)    );
  // itree = 934
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501151,0.000639471) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.880597,0.0384584) , 
0, 210183, 1, 0, 0.5115,0.00292041) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.172414,-0.0301619) , 
7, 2.13523, 1, 0, 0.501779,0.001272)    );
  // itree = 935
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.32449,-0.0052619) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404412,-0.0286524) , 
7, -1.44857, 1, 0, 0.341853,-0.0206869) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.426746,-0.00282357) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.565832,0.00614593) , 
8, -0.019069, 1, 0, 0.527752,0.00794478) , 
7, -1.28562, 1, 0, 0.50407,0.00429736)    );
  // itree = 936
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525872,0.00416423) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534884,0.0173039) , 
7, 0.664014, 1, 0, 0.527408,0.0133005) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.161111,-0.0394049) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40404,-0.00290438) , 
4, 0.0408581, 1, 0, 0.339259,-0.0273918) , 
7, 1.27637, 1, 0, 0.501814,0.00776499)    );
  // itree = 937
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.52958,4.06216e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.435897,0.0179559) , 
6, 2.46586, 1, 0, 0.516571,0.00489007) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.420742,-0.0127363) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.304124,0.00988117) , 
7, 1.27113, 1, 0, 0.404348,-0.020498) , 
8, 0.0207628, 1, 0, 0.485788,-0.00207386)    );
  // itree = 938
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.274809,-0.0189224) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53862,0.000753954) , 
8, -0.0556158, 1, 0, 0.51688,-0.000791565) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.482993,0.034015) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167939,0.0110761) , 
6, 1.19556, 1, 0, 0.334532,0.0465773) , 
7, 1.85823, 1, 0, 0.506836,0.00181762)    );
  // itree = 939
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.478864,0.00378427) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536331,-0.00663524) , 
7, -0.524296, 1, 0, 0.513984,-0.00564334) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572917,0.0263038) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.397333,0.00493253) , 
7, 1.18692, 1, 0, 0.433121,0.0199513) , 
7, 0.996545, 1, 0, 0.498804,-0.000838596)    );
  // itree = 940
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.509149,-0.000456509) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522394,0.0075355) , 
7, -0.142981, 1, 0, 0.516497,0.00836547) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.285714,-0.0250852) , 
6, 4.29104, 1, 0, 0.507638,0.00581925)    );
  // itree = 941
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.519396,2.18856e-05) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469287,0.019388) , 
7, 1.40263, 1, 0, 0.515183,0.00324608) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.175824,-0.024891) , 
7, 2.1399, 1, 0, 0.502887,0.00166879)    );
  // itree = 942
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348269,0.0116815) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53708,-0.00468728) , 
7, -1.55834, 1, 0, 0.515953,-0.00634711) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.459184,0.0303008) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374677,-0.00513819) , 
1, 2.47619, 1, 0, 0.41116,0.024649) , 
7, 1.28527, 1, 0, 0.501874,-0.00218291)    );
  // itree = 943
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.372694,-0.0221699) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.550122,-0.00160148) , 
7, -1.28306, 1, 0, 0.529361,-0.0090641) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.506214,0.00882984) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.168675,-0.0272354) , 
8, 0.071974, 1, 0, 0.484496,0.0126816) , 
1, 2.57143, 1, 0, 0.505719,0.00239505)    );
  // itree = 944
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.467719,0.0144321) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.54937,0.00176442) , 
7, -0.979991, 1, 0, 0.534051,0.00840688) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488722,-0.0143525) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.331699,0.00452685) , 
8, 0.0471143, 1, 0, 0.413469,-0.0120808) , 
8, 0.0244739, 1, 0, 0.503205,0.00316595)    );
  // itree = 945
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.361323,-0.0166207) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.920145,0.00931684) , 
2, 43541.9, 1, 0, 0.591623,-0.0255152) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390526,-0.0119972) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480713,0.00570171) , 
7, -0.710835, 1, 0, 0.457545,0.0028763) , 
1, 1.33333, 1, 0, 0.493148,-0.00466282)    );
  // itree = 946
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480296,-0.0105701) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.145522,-0.000589168) , 
6, 0.934683, 1, 0, 0.304926,-0.0135417) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.466357,0.0169515) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.760298,-0.00173372) , 
4, 0.13895, 1, 0, 0.708504,0.00467383) , 
4, 0.0954538, 1, 0, 0.502198,-0.00463781)    );
  // itree = 947
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464115,0.0178688) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.439285,-0.00665578) , 
4, 0.0149091, 1, 0, 0.44051,-0.0112314) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.9,0.00438053) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.703226,0.0268295) , 
6, 3.04841, 1, 0, 0.860131,0.0180821) , 
4, 0.304621, 1, 0, 0.504699,-0.00674734)    );
  // itree = 948
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.276065,0.00560965) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.350453,-0.00746873) , 
7, -0.979628, 1, 0, 0.335236,-0.0116452) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.775168,0.0186207) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.800141,0.0038805) , 
4, 0.215277, 1, 0, 0.795812,0.0112635) , 
4, 0.171779, 1, 0, 0.492076,-0.00384406)    );
  // itree = 949
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.456589,-0.00170447) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.169405,0.0103298) , 
6, 1.36869, 1, 0, 0.370336,0.00301863) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.644444,-0.0486224) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.803425,-0.00665735) , 
4, 0.210603, 1, 0, 0.789969,-0.0162695) , 
4, 0.190656, 1, 0, 0.508681,-0.00334032)    );
  // itree = 950
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.419918,0.0127747) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488827,-0.0147219) , 
1, 4.7619, 1, 0, 0.438438,0.0124955) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.531091,-0.000586054) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.214286,-0.0283383) , 
7, 2.1399, 1, 0, 0.520196,-0.00315904) , 
8, -0.019153, 1, 0, 0.498399,0.00101467)    );
  // itree = 951
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.504052,0.00072811) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.273927,0.0171506) , 
8, 0.071974, 1, 0, 0.489357,0.00323717) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.731844,-0.00523347) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.555556,-0.0271912) , 
7, 0.156109, 1, 0, 0.656051,-0.0268174) , 
1, 11.0476, 1, 0, 0.499703,0.00137176)    );
  // itree = 952
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468674,0.00523186) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526873,-0.00321759) , 
7, -0.692228, 1, 0, 0.511741,-0.00224688) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.432624,0.0458326) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.20155,0.00240786) , 
6, 1.1835, 1, 0, 0.322222,0.0471272) , 
7, 1.85568, 1, 0, 0.501501,0.000420925)    );
  // itree = 953
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.638149,0.0101972) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.614565,-0.00393404) , 
7, 0.142763, 1, 0, 0.627743,0.00939535) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.313732,-0.01118) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.804662,-0.00298588) , 
4, 0.266612, 1, 0, 0.43197,-0.0190817) , 
1, 1.47619, 1, 0, 0.481762,-0.011839)    );
  // itree = 954
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.272796,0.00567602) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.463158,-0.00690695) , 
5, 2511.94, 1, 0, 0.31531,0.00594755) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.865741,-0.0233374) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.864111,0.0104684) , 
6, 1.98622, 1, 0, 0.865445,-0.0185611) , 
5, 4801.39, 1, 0, 0.489972,-0.00183369)    );
  // itree = 955
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371367,0.0176568) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.592593,-0.00721511) , 
5, 1357.19, 1, 0, 0.4131,0.0341321) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.522479,-0.00118067) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.904459,0.0340376) , 
2, 197290, 1, 0, 0.537794,-0.00058477) , 
4, 0.038518, 1, 0, 0.509583,0.00726957)    );
  // itree = 956
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.480258,0.00153705) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.662069,-0.0141046) , 
1, 8, 1, 0, 0.507997,-0.00078281) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.143939,-0.0286665) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.3125,-0.0321038) , 
4, 0.0601871, 1, 0, 0.226923,-0.0567215) , 
7, 1.85568, 1, 0, 0.493416,-0.00368466)    );
  // itree = 957
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.332621,-0.00070101) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.779789,0.017697) , 
4, 0.133366, 1, 0, 0.476052,0.00893518) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.659696,-0.00332083) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.569061,-0.0287081) , 
7, 0.724159, 1, 0, 0.636492,-0.0183929) , 
1, 8, 1, 0, 0.499484,0.00494407)    );
  // itree = 958
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560677,0.00411534) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.371429,-0.00582284) , 
6, 1.87972, 1, 0, 0.520041,0.00427853) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.193798,-0.0207397) , 
6, 4.81051, 1, 0, 0.511656,0.00298998)    );
  // itree = 959
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.612947,0.00546147) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325644,-0.00721345) , 
6, 1.20674, 1, 0, 0.50207,0.0014497) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.27027,0.0258891) , 
6, 4.81386, 1, 0, 0.495179,0.00291731)    );
  // itree = 960
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442396,0.0152732) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.411734,-0.00697468) , 
4, 0.0147474, 1, 0, 0.413383,-0.0120632) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.864748,0.0161971) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.801324,-0.0297245) , 
4, 0.378274, 1, 0, 0.853428,0.0102793) , 
4, 0.286028, 1, 0, 0.489654,-0.00819068)    );
  // itree = 961
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.193089,0.00687709) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.609334,-0.00604375) , 
2, 20686.3, 1, 0, 0.523968,-0.0078337) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.396401,0.00715563) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.808102,-0.013165) , 
2, 119365, 1, 0, 0.469651,0.00778928) , 
1, 2.66667, 1, 0, 0.495531,0.000345484)    );
  // itree = 962
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.366903,-0.00702501) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.152466,0.00705124) , 
1, 4, 1, 0, 0.317824,-0.0111656) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.625,0.0381739) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.767838,0.00410908) , 
7, -1.53263, 1, 0, 0.757666,0.0116462) , 
4, 0.13339, 1, 0, 0.497674,-0.00183791)    );
  // itree = 963
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.385614,-0.00367103) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.138095,-0.0354761) , 
8, 0.0440084, 1, 0, 0.342692,-0.019991) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.336131,0.00820928) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.900474,-0.00494805) , 
5, 5386.69, 1, 0, 0.552073,0.0101737) , 
4, 0.0383621, 1, 0, 0.502071,0.00297007)    );
  // itree = 964
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.469529,-0.00525996) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.588909,0.00921674) , 
4, 0.040411, 1, 0, 0.552709,0.00892403) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.242513,-0.0104251) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.803842,-0.000809835) , 
4, 0.228711, 1, 0, 0.448737,-0.0133743) , 
1, 2.95238, 1, 0, 0.497536,-0.00290863)    );
  // itree = 965
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664122,0.00315027) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.246212,-0.0244044) , 
1, 1.33333, 1, 0, 0.38481,-0.0402418) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.513342,-0.00141745) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.309091,0.0223236) , 
7, 2.1399, 1, 0, 0.505995,-0.00119359) , 
4, 0.0193672, 1, 0, 0.496387,-0.00428954)    );
  // itree = 966
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.486762,-0.0031426) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.764302,0.0112303) , 
0, 96457.2, 1, 0, 0.513395,-0.00425568) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.375527,0.0360747) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341346,-0.00283715) , 
8, -0.00105044, 1, 0, 0.359551,0.0365459) , 
7, 1.56654, 1, 0, 0.4997,-0.000623618)    );
  // itree = 967
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.227273,0.0528881) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.340351,0.00621517) , 
4, 0.0563988, 1, 0, 0.300683,0.0360262) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.567129,0.00225823) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.390205,-0.00818159) , 
8, 0.0237261, 1, 0, 0.519012,-0.000662903) , 
8, -0.0556158, 1, 0, 0.500196,0.00249895)    );
  // itree = 968
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.219955,-0.0180489) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.784181,-0.00690048) , 
2, 27291.6, 1, 0, 0.596531,-0.0269889) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.270703,0.00524037) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.75813,-0.00861511) , 
4, 0.171629, 1, 0, 0.463998,0.00125349) , 
1, 1.47619, 1, 0, 0.498811,-0.00616516)    );
  // itree = 969
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.418552,-0.00416334) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.534487,0.00803569) , 
7, -1.00043, 1, 0, 0.513193,0.0124597) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.23913,-0.0286654) , 
6, 4.81051, 1, 0, 0.505554,0.0103735)    );
  // itree = 970
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.38553,0.000560698) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.404817,0.0102246) , 
7, 0.138776, 1, 0, 0.394471,0.011361) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.794466,-0.00070362) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.813793,-0.031329) , 
0, 112278, 1, 0, 0.798771,-0.010029) , 
4, 0.228711, 1, 0, 0.49842,0.00586145)    );
  // itree = 971
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.591733,0.0108428) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.533436,-0.00397031) , 
8, -0.00158088, 1, 0, 0.561186,0.0066258) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.195939,-0.013328) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.659674,0.00876697) , 
0, 82610.4, 1, 0, 0.336634,-0.0144872) , 
6, 1.60748, 1, 0, 0.499219,0.00079955)    );
  // itree = 972
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.498276,0.000149136) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.596639,0.0139923) , 
0, 60736.5, 1, 0, 0.518638,0.00583295) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.269481,-0.0262075) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.461897,-0.00301731) , 
8, -0.0183844, 1, 0, 0.399579,-0.019559) , 
7, 0.991355, 1, 0, 0.495879,0.00097914)    );
  // itree = 973
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.2249,-0.0295897) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.53842,0.00531815) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50632,-0.00152285) , 
7, -0.237228, 1, 0, 0.51869,0.0023777) , 
7, -1.85265, 1, 0, 0.504091,-0.000110054)    );
  // itree = 974
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.762774,0.0105929) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.298308,-0.00313011) , 
6, 0.642358, 1, 0, 0.396304,-0.00149894) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.740933,0.0202507) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.957328,0.0134351) , 
5, 10297.8, 1, 0, 0.845259,0.0248979) , 
2, 87360, 1, 0, 0.49641,0.0043869)    );
  // itree = 975
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458836,0.00518638) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.952675,-0.0258643) , 
5, 5359.18, 1, 0, 0.559131,0.00855948) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472716,-0.00604123) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.418534,0.00190456) , 
7, 0.424013, 1, 0, 0.452774,-0.00536327) , 
1, 2.95238, 1, 0, 0.503063,0.00121985)    );
  // itree = 976
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266667,-0.0112022) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.348323,0.00192561) , 
7, -0.146461, 1, 0, 0.313206,-0.00792011) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.676619,0.00741859) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.584071,0.0316412) , 
7, 1.57472, 1, 0, 0.669162,0.0177885) , 
4, 0.0768963, 1, 0, 0.508714,0.00620026)    );
  // itree = 977
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.495902,0.00320166) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.386487,0.02236) , 
8, 0.0224313, 1, 0, 0.465825,0.0167103) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.470588,-0.0196522) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.50865,-0.000772503) , 
7, -0.52335, 1, 0, 0.505965,-0.00454509) , 
7, -0.700994, 1, 0, 0.495579,0.00095467)    );
  // itree = 978
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247839,0.000636013) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.483821,-0.0140179) , 
4, 0.0582884, 1, 0, 0.401606,-0.0169629) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.472507,0.000278641) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.722573,0.0199764) , 
1, 6.71429, 1, 0, 0.521934,0.00658282) , 
7, -1.00225, 1, 0, 0.498003,0.0019)    );
  // itree = 979
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.359084,-0.000369683) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.801296,0.00910383) , 
4, 0.152951, 1, 0, 0.535284,0.00533348) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.266129,-0.0300361) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.189873,-0.0121566) , 
1, 2.2381, 1, 0, 0.223404,-0.0427779) , 
7, 1.85442, 1, 0, 0.517444,0.00258147)    );
  // itree = 980
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.488134,-0.00225052) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.902357,0.0212058) , 
4, 0.361392, 1, 0, 0.514907,-0.00273511) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.403941,0.0304977) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.257778,0.0041829) , 
1, 2.57143, 1, 0, 0.327103,0.0333887) , 
8, 0.063064, 1, 0, 0.498905,0.000342937)    );
  // itree = 981
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.468642,-0.00251641) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5,-0.0202644) , 
0, 115582, 1, 0, 0.469887,-0.00694892) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.217687,-0.0456837) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.94403,-0.00594023) , 
5, 5466.19, 1, 0, 0.686747,-0.0340308) , 
3, 0.047619, 1, 0, 0.488076,-0.00922034)    );
  // itree = 982
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.602955,0.00161073) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.341943,-0.0103326) , 
6, 1.37781, 1, 0, 0.513399,-0.00525336) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.423358,0.0505026) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.124031,0.00615411) , 
8, 0.123479, 1, 0, 0.278196,0.0466393) , 
8, 0.0833911, 1, 0, 0.500899,-0.00249542)    );
  // itree = 983
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.374764,-0.000612204) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.827427,0.015662) , 
4, 0.190457, 1, 0, 0.523701,0.00656271) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31405,-0.0127248) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.711462,0.0141737) , 
2, 76022.3, 1, 0, 0.416752,-0.0143391) , 
7, 0.99433, 1, 0, 0.502437,0.00240698)    );
  // itree = 984
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.302752,-0.0283679) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.497207,-0.00214719) , 
5, 368.708, 1, 0, 0.390428,-0.0495236) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.31873,0.00656936) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.747936,-0.00852071) , 
4, 0.128046, 1, 0, 0.513086,0.0014543) , 
4, 0.0196184, 1, 0, 0.503236,-0.0026392)    );
  // itree = 985
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.326087,-0.0202665) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.505753,-0.00481007) , 
4, 0.0193672, 1, 0, 0.491189,-0.0129606) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.442035,0.00162191) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.858469,0.0216932) , 
4, 0.304409, 1, 0, 0.505479,0.0078595) , 
7, -0.136098, 1, 0, 0.499117,-0.0014093)    );
  // itree = 986
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.379167,-0.0124753) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.311993,0.00493688) , 
4, 0.0139701, 1, 0, 0.318235,0.00684836) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.664059,-0.00885813) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.802993,0.0170213) , 
3, 0.047619, 1, 0, 0.686836,-0.0117075) , 
4, 0.0955195, 1, 0, 0.497514,-0.0021768)    );
  // itree = 987
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.434806,-0.00839342) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.191249,0.00215895) , 
1, 3, 1, 0, 0.328615,-0.0104392) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.86148,0.0172793) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.772141,0.000926238) , 
1, 2.33333, 1, 0, 0.8,0.00957354) , 
4, 0.171436, 1, 0, 0.489879,-0.00359272)    );
  // itree = 988
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.135135,-0.0355968) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.422018,0.0150435) , 
7, -1.24999, 1, 0, 0.384411,0.0248049) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.538892,0.0059962) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.526676,-0.00644445) , 
7, -0.143337, 1, 0, 0.531842,-0.00238175) , 
4, 0.0384111, 1, 0, 0.498073,0.00384543)    );
  // itree = 989
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.452555,0.0350155) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.499032,0.00729639) , 
4, 0.0194015, 1, 0, 0.495255,0.0208237) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.380569,-0.00490439) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.830612,0.007855) , 
4, 0.209808, 1, 0, 0.512736,-0.0046127) , 
7, -0.429463, 1, 0, 0.506868,0.00392518)    );
  // itree = 990
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.457746,0.00228531) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.40146,0.0259059) , 
0, 53505.6, 1, 0, 0.43943,0.02522) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.265364,-0.00897617) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.686905,-0.00157496) , 
4, 0.0920737, 1, 0, 0.495345,-0.0103278) , 
4, 0.0196467, 1, 0, 0.490675,-0.00735846)    );
  // itree = 991
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.409091,-0.0172171) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.382069,-0.005474) , 
1, 2.57143, 1, 0, 0.394718,-0.0230094) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.536251,-0.000508173) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.523848,0.00869184) , 
7, 0.426666, 1, 0, 0.531951,0.00573908) , 
8, -0.0193465, 1, 0, 0.494017,-0.00220742)    );
  // itree = 992
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.393382,0.0101579) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.525238,-0.000596072) , 
4, 0.0386205, 1, 0, 0.494413,0.00511762) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.593333,-0.0373983) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.897959,-0.00735583) , 
3, 0.047619, 1, 0, 0.744108,-0.0475822) , 
0, 132186, 1, 0, 0.509392,0.00195627)    );
  // itree = 993
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.251208,-0.0282943) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.560811,0.00247321) , 
5, 388.322, 1, 0, 0.380282,-0.0460397) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511351,-0.000752244) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.572407,0.0112898) , 
0, 58150.9, 1, 0, 0.525077,0.00317028) , 
4, 0.01941, 1, 0, 0.514589,-0.000394206)    );
  // itree = 994
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.247363,0.0132634) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.546143,0.00123019) , 
2, 49322.4, 1, 0, 0.376941,0.019412) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.583942,-0.0530878) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.793996,-0.00445707) , 
4, 0.193099, 1, 0, 0.778322,-0.0134592) , 
4, 0.171386, 1, 0, 0.519097,0.00777009)    );
  // itree = 995
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.474764,-0.00491128) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.860169,0.0309196) , 
4, 0.342651, 1, 0, 0.508792,-0.00576245) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.5048,0.0094062) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.501027,-0.0118425) , 
0, 60728.7, 1, 0, 0.503986,0.00993802) , 
7, 0.136315, 1, 0, 0.506591,0.00142709)    );
  // itree = 996
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.500477,0.00254223) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.511541,-0.00598911) , 
7, -0.143978, 1, 0, 0.506692,-0.00495499) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.167598,0.0422567) , 
8, 0.105021, 1, 0, 0.494457,-0.00318586)    );
  // itree = 997
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.473898,-0.00397927) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.56391,0.00518416) , 
7, -0.392551, 1, 0, 0.515218,0.000688289) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.464746,-0.00496855) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.433333,-0.024756) , 
0, 56733.1, 1, 0, 0.457159,-0.0192059) , 
7, 0.423585, 1, 0, 0.494722,-0.00633486)    );
  // itree = 998
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.325786,0.000423792) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.259358,0.0205543) , 
7, 1.28544, 1, 0, 0.315997,0.00696979) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.401501,-0.0156435) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.761526,-0.00352279) , 
4, 0.153545, 1, 0, 0.682231,-0.0127402) , 
4, 0.0955217, 1, 0, 0.494756,-0.00265063)    );
  // itree = 999
  fBoostWeights.push_back(1);
  fForest.push_back( 
new BDTGNode(
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.435615,0.0129081) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.899506,-0.00380903) , 
2, 62058.9, 1, 0, 0.556414,0.0255281) , 
new BDTGNode(
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.394477,0.0142618) , 
new BDTGNode(
0, 
0, 
-1, 0, 1, -99, 0.458924,-0.00954055) , 
7, -0.974217, 1, 0, 0.446476,-0.00990642) , 
1, 2.95238, 1, 0, 0.498184,0.00675981)    );
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
