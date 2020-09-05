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

// make Rs "n" from v coins (set)
int change_count(v1d v, int n){
  int m = sz(v);
  vector<vector<int>> dp(n+1, vector<int> (m+1,0));

  REP(j,m+1) dp[0][j] = 1;

  for (int i = 1; i < n+1; i++) {
    for (int j = 1; j < m+1; j++) {
        dp[i][j] = dp[i][j-1] + (i-v[j-1] >= 0 ? dp[i-v[j-1]][j] : 0);
    }
  }
  return dp[n][m];
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int m,n;
    cin>>m;
    v1d v(m);
    REP(i,m) cin>>v[i];
    cin>>n;
    cout << change_count(v,n) << endl;
  }
  return 0;
}
