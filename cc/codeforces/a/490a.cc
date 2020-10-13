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

int32_t main(int argc, char const *argv[]){
  clr();
  int n;
  cin>>n;
  v1d t1,t2,t3;
  REP(i,n){
    int t;
    cin>>t;
    if(t==1) t1.pb(i+1);
    if(t==2) t2.pb(i+1);
    if(t==3) t3.pb(i+1);
  }
  int mn = min({t1.size(), t2.size(), t3.size()});
  cout << mn << endl;
  REP(i,mn){
      cout<<t1[i]<<' '<<t2[i]<<' '<<t3[i]<<endl;
  }
  return 0;
}
