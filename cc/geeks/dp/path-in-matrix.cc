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

int pathUtil(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp){
  int n = sz(v);
  if(i >= n || j >= n || i < 0 || j < 0) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  int x = i + 1;
  int y = j;
  return dp[i][j] = v[i][j] +
   max({ pathUtil(x,y,v,dp), pathUtil(x,y-1,v,dp), pathUtil(x,y+1,v,dp) });
}

int max_path_sum(vector<vector<int>> &v){
  int n = sz(v);
  std::vector<vector<int>> dp(n, vector<int> (n, -1));
  for (int i = n-1; i >=0; i--) {
    for (int j = n-1; j >= 0; j--) {
      if(dp[i][j] == -1)
        pathUtil(i,j,v,dp);
    }
  }
  int ans = 1;
  REP(i, n) ans = max(ans, dp[0][i]);
  return ans;
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n;
    cin>>n;
    std::vector<vector<int>> v(n, vector<int> (n));
    REP(i,n) REP(j,n) cin>>v[i][j];
    cout << max_path_sum(v) << endl;
  }
  return 0;
}
