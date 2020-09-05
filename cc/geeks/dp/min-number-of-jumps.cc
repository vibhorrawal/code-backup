#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define v1d  vector<int>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define sz(x) (int) x.size()
void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int jumps(v1d &a){
  v1d jumps(sz(a), INT_MAX);
  int n = sz(a);
  jumps[0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if(j + a[j] >= i && jumps[j] != INT_MAX)
        jumps[i] = min(jumps[i], jumps[j]+1);
    }
  }
  return (jumps[n-1] == INT_MAX ? -1 : jumps[n-1]);
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n; cin>>n;
    v1d a(n);
    REP(i,n) cin>>a[i];
    cout<<jumps(a)<<endl;
  }
  return 0;
}
