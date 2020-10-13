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
#define DEBUG 00
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define endl '\n'

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main(int argc, char const *argv[]){
  clr();
  int n,k;
  cin>>n>>k;
  n = 2*n+1;
  int a[n+1];
  bool vis[n+1] = {0};
  REP(i,n) cin>>a[i+1];
  // for (int i = 3; i <= n && k>0; i+=2) {
  //   if(a[i]>=a[i-1]) {
  //     a[i]--;
  //     k--;
  //     vis[i] = 1;
  //   }
  // }
  db(k);
  for (int i = 1; i <= n && k; i++) {
    if(i%2 == 0){
      if(a[i] -1 > a[i-1] && a[i] - 1 > a[i+1] && !vis[i]) a[i]--,k--;
    }
    else {
      // if(!vis[i]) a[i]--,k--;
    }
  }
  db(k);
  // assert(k==0);
  for(int i = 1; i <= n ; i++){ cout<<a[i]<<' ';}cout<<endl;
  return 0;
}
