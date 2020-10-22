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

typedef vector<vector<long long>> matrix;

matrix ones(int n){
  matrix res(n, vector<long long> (n, 0));
  for (int i = 0; i < n; i++) {
    res[i][i] = 1;
  }
  return res;
}
matrix mul(const matrix &a, const matrix &b, int mod){
  assert(a.size() && b.size());
  int n = a.size(), m = b[0].size(), p = b.size();
  assert(a[0].size() == b.size());
  matrix res(n, vector<long long> (m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < p; k++) {
        res[i][j] += (a[i][k] * b[k][j]) % mod;
      }
      res[i][j] = (res[i][j] + mod) % mod;
    }
  }
  return res;
}

matrix mul(const matrix &a, int n, int mod){
  matrix res(a.size(), vector<long long> (a[0].size(), 0));
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) a[0].size(); j++) {
      res[i][j] = (a[i][j] * n + mod) % mod;
    }
  }
  return res;
}

matrix binpow(matrix &a, int n, int mod){
  matrix res = ones(2);
  while(n){
    if(n & 1) res = mul(res, a, mod);
    a = mul(a, a, mod);
    n = n>>1;
  }
  return res;
}
void solve(int x, int a, int n, int c){
  // matrix multiplication
  // [x 1] * [a -a]
  matrix res = {{x,1},{0,0}};
  matrix change = {{a,0},{-a,0}};
  matrix fin = binpow(change, n, c);
  res = mul(res, fin, c);
  cout << res[0][0] << endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  while(1){
    int x, a, n, c;
    cin>>x>>a>>n>>c;
    if(x == 0) break;
    solve(x,a,n,c);
  }
  return 0;
}
