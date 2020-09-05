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

int max_cut(int n, int x, int y, int z){
  int dp[n+1];
  REP(i,n+1) dp[i] = INT_MIN;
  dp[0] = 0;
  for (int i = 0; i < n+1; i++) {
    if(i-x>=0) dp[i] = max(dp[i], dp[i-x] + 1);
    if(i-y>=0) dp[i] = max(dp[i], dp[i-y] + 1);
    if(i-z>=0) dp[i] = max(dp[i], dp[i-z] + 1);
  }
  return dp[n];
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    cout << max_cut(n,x,y,z) << endl;
  }
  return 0;
}
