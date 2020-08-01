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

int lis(int a[], int n){
  int dp[n] = {1};
  int res=0;
  for (int i = 1; i < n; i++) {
    dp[i]=1;
    for (int j = 0; j < i; j++) {
      if(a[i] > a[j] && dp[i] < dp[j] + 1)
      dp[i] = dp[j] + 1;
      res=max(dp[i],res);
    }
  }
  return *max_element(dp,dp+n);
}
int main(int argc, char const *argv[]){
T(){
  int n;cin>>n;
  int a[n];
  REP(i,n) cin>>a[i];
  cout<<lis(a,n)<<endl;
  }
  return 0;
}
