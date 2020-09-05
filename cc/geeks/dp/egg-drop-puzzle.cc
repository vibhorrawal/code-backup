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
int rec(int n, int k){
  if(k == 1||k==0) return k;
  if(n==1) return k;

  int ans = INT_MAX;
  for (int x = 1; x <= k; x++) {
    int res = 1 + max(rec(n-1, x-1), rec(n, k-x)); // find worst case
    ans = min(ans, res); // least of those worst cases
  }
  return ans;
}
int min_attempts(int n, int k){
  // return rec(n,k);
  int dp[n+1][k+1];
  REP(i, n+1) REP(j, k+1) dp[i][j] = INT_MAX;
  REP(i,n+1) dp[i][1] = 1, dp[i][0] = 0;
  REP(i,k+1) dp[1][i] = i;

  for (int i = 2; i < n+1; i++) {
    for (int j = 2; j < k+1; j++) {
      for (int x = 1; x <= j; x++) {
        dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][x-1], dp[i][j-x]));
      }
    }
  }
  return dp[n][k];
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int egg, floor;
    cin >> egg >> floor;
    cout << min_attempts(egg, floor) << endl;
  }
  return 0;
}
