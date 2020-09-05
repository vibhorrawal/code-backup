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

bool sub_sum(v1d &v){
  int sum = accumulate(all(v), 0);
  if(sum & 1) return false;
  sum = sum / 2;
  int n = sz(v);

  bool dp[n+1][sum+1];

  REP(i,sum+1) dp[0][i] = false;
  REP(i,n+1) dp[i][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if(j - v[i-1] >= 0)
        dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n][sum];
}

int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n;
    cin>>n;
    v1d a(n);
    REP(i,n) cin>>a[i];
    cout << (sub_sum(a) ? "YES" : "NO") << endl;
  }
  return 0;
}
