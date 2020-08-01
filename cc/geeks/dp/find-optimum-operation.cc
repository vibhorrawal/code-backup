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

int main(int argc, char const *argv[]){
T(){
  int n;cin>>n;
  int dp[n+1];
  dp[0]=0;
  dp[1]=1;
  dp[2]=2;

  for(int i=3;i<=n;i++){
    dp[i]=min(dp[i-1]+1,dp[i/2] + 1 + i%2);
  }
  cout << dp[n] << endl;
}
  return 0;
}
