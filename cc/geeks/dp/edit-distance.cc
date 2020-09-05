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

int cost(string s1, string s2){
  int n = s1.length(), m = s2.length();
  int dp[n+1][m+1] = {0};

  for (int i = 0; i < n+1; i++) {
    for (int j = 0; j < m+1; j++) {
      if(!i)
        dp[i][j] = j;
      else if(!j)
        dp[i][j] = i;
      else if(s1[i-1] == s2[j-1])
        dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]})+1;
    }
  }
  return dp[n][m];
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int t;
    cin>>t>>t;
    string s2,s1;
    cin>>s1>>s2;
    cout << cost(s1,s2) << endl;
  }
  return 0;
}
