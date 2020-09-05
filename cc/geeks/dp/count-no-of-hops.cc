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
// 1 or 2 or 3 hops
int hops(int n){
  int dp[n+1] = {0};
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (int i = 4; i < n+1; i++) {
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  }
  return dp[n];
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n;
    cin>>n;
    cout << hops(n) << endl;
  }
  return 0;
}
