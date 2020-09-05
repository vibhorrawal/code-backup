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

int lcs(string a, string b){
  int n = a.length();
  int m = b.length();
  int dp[n+1][m+1];

  for (int i = 0; i < n+1; i++) {
    for (int j = 0; j < m+1; j++) {
      if(!i || !j)
        dp[i][j] = 0;
      else if(a[i-1] == b[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[n][m];
}
int shortest_length(string a, string b){
  return a.length() + b.length() - (lcs(a,b));
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    string a,b;
    cin >> a >> b;
    cout << shortest_length(a,b) << endl;
  }
  return 0;
}
