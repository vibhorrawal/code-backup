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
#define pb push_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  clr();
  int n,m;
  cin>>n>>m;
  // int a[m],b[m]; // a is matchbox
  std::vector<pair<int, int>> v;
  REP(i,m) {
    int t,tt;
    cin>>t>>tt;
    v.pb({tt,t}); // match, matchbox
  }
  sort(v.rbegin(), v.rend());
  int ans=0;
  int i=0;
  while(n>=0 && i<m){
    int t = v[i].second;
    if(t <= n){
      n -= t;
      ans += t * v[i].first;
    }
    else{
      t = n;
      n = 0;
      ans += t * v[i].first;

    }
    i++;
  }
  cout << ans << endl;
  return 0;
}
