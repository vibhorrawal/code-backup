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

int lcs(string x, string y){
  int n = x.size();
  int m = y.size();
  int dp[n+1][m+1];
  int result = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
        if(i==0||j==0) dp[i][j] = 0;
        else if(x[i-1] == y[j-1]){
          dp[i][j] = dp[i-1][j-1] + 1;
          result = max(result, dp[i][j]);
        }
        else dp[i][j] = 0;
    }
  }
  return result;
}
int main(int argc, char const *argv[]){
T(){
  int n,m;cin>>n>>m;
  string x,y;
  cin>>x>>y;
  cout<<lcs(x,y)<<endl;
  }
  return 0;
}
