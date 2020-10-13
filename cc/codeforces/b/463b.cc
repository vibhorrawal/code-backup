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

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


int32_t main(int argc, char const *argv[]){
  clr();
  int n;
  cin>>n;
  int height[n];
  REP(i,n) cin>>height[i];
  int h=0, energy=0,ans=0;
  REP(i,n){
    energy -= height[i] - h;
    if(energy<0) {
      ans += -energy;
      energy = 0;
    }
    h = height[i];
  }
  cout << ans << endl;
  return 0;
}
