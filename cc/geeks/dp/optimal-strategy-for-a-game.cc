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

int rec(v1d &v, int i, int j){
  if(i==j) return v[i];
  if(i == j - 1) return max(v[i],v[j]);

  int vi = v[i] + min(rec(v, i+2, j), rec(v, i+1, j-1));
  int vj = v[j] + min(rec(v, i+1, j-1), rec(v, i, j-2));
  return max(vi, vj);
}
int max_amount(v1d &v){
  int n = sz(v);
  // return rec(v, 0, n-1);
  int dp[n][n];

  for (int gap = 0; gap < n; gap++) {
    for (int i = 0, j = gap; j < n; i++, j++) {
      int x = (i+2 <= j) ? dp[i+2][j] : 0;
      int y = (i+1 <= j-1) ? dp[i+1][j-1] : 0;
      int z = (i <= j-2) ? dp[i][j-2] : 0;

      dp[i][j] = max(v[i] + min(x,y),
                     v[j] + min(y,z));
    }
  }
  return dp[0][n-1];
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n;
    cin>>n;
    v1d v(n);
    REP(i, n) cin >> v[i];
    cout << max_amount(v) << endl;
  }
  return 0;
}
