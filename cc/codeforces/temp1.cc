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
// just counting positive
// no cout vs cout<<a vs cout<<a<<endl vs cout<<a (without clr())
// 4s vs 1m30s vs 21m vs 2m
int32_t main(int argc, char const *argv[]){
  // clr();
  int a=1;
  while(a>0) {
    a++;
    cout<<a;
  }
  return 0;
}