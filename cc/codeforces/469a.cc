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
  int n,q,p;
  cin>>n>>p;
  vector<bool> v(n+1);
  int t;
  REP(i,p) {
    cin>>t;
    v[t]=1;
  }
  cin>>q;
  REP(i,q) {
    cin>>t;
    v[t]=1;
  }
  bool win=true;
  for (int i = 1; i <= n; i++) {
    win &= v[i];
  }
  if(win) cout << "I become the guy." << endl;
  else cout << "Oh, my keyboard!" << endl;
  return 0;
}
