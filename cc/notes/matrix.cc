
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
typedef int matrix_t;
typedef vector<vector<matrix_t>> Matrix;
Matrix add(Matrix a, Matrix b);
Matrix mul(const Matrix &a, const Matrix &b);
Matrix mul(const Matrix &a, int n);
Matrix ones(int n);
Matrix binpow(Matrix a, int n);

Matrix add(const Matrix &a, const Matrix &b){
  assert(a.size() == b.size() && a[0].size() == b.size());
  Matrix res(a.size(), vector<matrix_t> (a[0].size(), 0));
  for (int i = 0; i < (int) a.size(); i++) {
    for (int j = 0; j < (int) a[0].size(); j++) {
      res[i][j] = a[i][j] + b[i][j];
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
        res[i][j] += a[i][k] * b[k][j];
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

Matrix binpow(Matrix a, int n){
  Matrix res = ones(a.size());
  while(n){
    if(n & 1) res = mul(res, a);
    a = mul(a, a);
    n = n>>1;
  }
  return res;
}
