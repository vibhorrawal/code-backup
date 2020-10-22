#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

ll solve(){
  int n;
  cin>>n;
  vvi matrix(n, vi(n));
  REP(i,n) REP(j,n) cin>>matrix[i][j];
  ll maxcoins = 0, coins = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(i & j) continue;
      coins = 0;
      for(int k = 0; k < n; k++){
        int row = i + k;
        int col = j + k;
        if(row >= n || col >= n) break;
        coins += matrix[row][col];
      }
      maxcoins = max(coins, maxcoins);
    }
  }
  return maxcoins;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int tc;
  cin>>tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i<<": "<<solve();
    cout<<endl;
  }
  return 0;
}
