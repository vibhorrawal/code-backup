// WA
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

typedef ll matrix_t;
typedef vector<vector<matrix_t>> Matrix;
Matrix add(Matrix a, Matrix b);
Matrix mul(const Matrix &a, const Matrix &b);
Matrix mul(const Matrix &a, int n);
Matrix ones(int n);
Matrix binpow(Matrix a, ll n);
const ll MOD = 2LL<<32;

int32_t main(int argc, char const *argv[]){
  fastIO;
  int k;
  cin>>k;
  Matrix chess(8, vector<ll>(8));
  chess[0][0] = chess[1][2] = chess[2][1] = 1;
  REP(i,k) chess = binpow(chess, k);
  ll count = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      count += chess[i][j];
    }
    count %= MOD;
  }
  cout << count << endl;
  return 0;
}


Matrix add(Matrix a, Matrix b){
  assert(a.size() == b.size() && a[0].size() == b.size());
  Matrix res(a.size(), vector<matrix_t> (a[0].size(), 0));
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) a[0].size(); j++) {
      res[i][j] = (a[i][j] + b[i][j]) % MOD;
    }
  }
  return res;
}

Matrix mul(const Matrix &a, const Matrix &b){
  assert(a.size() && b.size());
  int n = a.size(), m = b[0].size(), p = b.size();
  assert(a[0].size() == b.size());
  Matrix res(n, vector<matrix_t> (m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < p; k++) {
        res[i][j] = (res[i][j] + (ll) a[i][k] * b[k][j]) % MOD;
      }
    }
  }
  return res;
}

Matrix mul(const Matrix &a, int n){
  Matrix res(a.size(), vector<matrix_t> (a[0].size(), 0));
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) a[0].size(); j++) {
      res[i][j] = a[i][j] * n;
    }
  }
  return res;
}

Matrix ones(int n){
  Matrix res(n, vector<matrix_t> (n, 0));
  for (int i = 0; i < n; i++) {
    res[i][i] = 1;
  }
  return res;
}

Matrix binpow(Matrix a, ll n){
  Matrix res = ones(a.size());
  while(n){
    if(n & 1) res = mul(res, a);
    a = mul(a, a);
    n = n>>1;
  }
  return res;
}
