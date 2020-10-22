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

const int MOD = 1e7+7;
int binpow(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b /= 2;
  }
  return res;
}

void solve(int n, int k){
  ll s = binpow(n,k) + 2 * binpow(n-1,k);
  ll p = binpow(n,n) + 2 * binpow(n-1,n-1);
  ll res = (s + p) % MOD;
  cout << res << endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  while(1){
    int n, k;
    cin >> n >> k;
    if(n == 0 && k == 0) break;
    solve(n,k);
  }
  return 0;
}
