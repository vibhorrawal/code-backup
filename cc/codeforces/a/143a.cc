#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define v2d  vector<vector<int> >
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define endl '\n'

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool diff(int g1, int g2, int g3, int g4){
  if(g1>0 && g1<10 && g2>0 && g2<10 &&
      g3>0 && g3<10 && g4>0 && g4<10 &&
      g1 != g2 && g1 != g3 && g1 != g4 &&
      g2 != g3 && g2 != g4 &&
      g3 != g4)
        return true;
      else return false;
}
int32_t main(int argc, char const *argv[]){
  clr();
  int r1,r2,c1,c2,d1,d2;
  cin>>r1>>r2>>c1>>c2>>d1>>d2;
  int seed=1;
  int g1,g2,g3,g4;
  while(seed<10){
    g1 = seed;
    g2 = r1 - g1;
    g3 = c1 - g1;
    g4 = c2 - g2;

    if(g1 + g3 == c1 && g2 + g4 == c2 &&
       g1 + g4 == d1 && g2 + g3 == d2 &&
        g1 + g2 == r1 && g3 + g4 == r2 &&
        diff(g1,g2,g3,g4)){
          cout << g1<<' '<<g2<<'\n'<<g3<<' '<<g4 << endl;
          return 0;
        }
        seed++;
  }
  cout << "-1" << endl;
  return 0;
}
