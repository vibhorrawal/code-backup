#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG true
#define pb(a) push_back(a)
#define mp(i,j) make_pair(i,j)

int knapsack(int n, int w, int wt[], int v[]){
  int dp[n+1][w+1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= w; j++) {
      if(!i || !j)
        dp[i][j] = 0;
      else if(wt[i-1] <= j)
        dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j-wt[i-1]]);
      else
        dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n][w];
}
int main(int argc, char const *argv[]){
T(){
  int n,w;cin>>n>>w;
  int wt[n],v[n];
  REP(i,n) cin>>v[i];
  REP(i,n) cin>>wt[i];
  cout<< knapsack(n,w,wt,v)<< endl;
  }
  return 0;
}
