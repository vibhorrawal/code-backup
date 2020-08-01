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

//wrong sol
int min_additions(string s){
  int i=0,j=s.size()-1,count=0;
  while(i<=j){
    if(s[i]!=s[j]){
      count++;
      i--;
    }
    j--,i++;
  }
  return count;
}
int min_additions_dp(string s){
  int n=s.size();
  int dp[n][n]={0};
  for (int gap = 1; gap < n; gap++) {
    for (int l = 0, h=gap; h < n; l++,h++) {
      if(s[l]==s[h]){
        dp[l][h]=dp[l+1][h-1];
      }
      else
      dp[l][h]=min(dp[l][h-1],dp[l+1][h]) + 1;
    }
  }
  return dp[0][n-1];
}
int main(int argc, char const *argv[]){
T(){
  string s;cin>>s;
  cout << min_additions_dp(s) << endl;
  }
  return 0;
}
