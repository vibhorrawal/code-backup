#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

int cost(vvi &matrix, int n, int m){
  int k = (n+1)/2, l = (m+1)/2;
  vvi diff(k,vi(l));
  for(int i = 0; i < (n+1)/2; i++){
    for(int j = 0; j < (m+1)/2; j++){
      int ii = i,jj = j;
      if(i >= k) ii = k-i+1;
      if(j >= l) jj = l-j+1;
      diff[i][j] = matrix[ii][jj];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout<<diff[i][j]<<' ';
    }
    cout<<endl;
  }
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n, m;
    cin>>n>>m;
    vvi matrix(n, vi(m));
    REP(i,n) REP(j,m) cin>>matrix[i][j];
    cost(matrix, n, m);
  }
  return 0;
}
