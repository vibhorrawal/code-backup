// https://medium.com/@palak001/spoj-locker-magic-of-the-locker-a758bccf432f
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

const int MOD = 1e9+7;

ll binpow(ll a, ll b){
  ll res = 1;
  while(b){
    if(b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b = b>>1;
  }
  return res;
}

int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    ll n;
    cin>>n;
    // we need to find a num k, where k (n/k)times is n, and k ^ (n/k) is maximum
    // derivating the given eqn k = e, but since question asks for integer k,
    // we will use k = 3
    if(n < 3) {
      cout << n << endl;
      continue;
    }
    ll res = 0;
    if(n % 3 == 1){
      n-= 4;
      res = (binpow(3, n / 3) * 4) % MOD;
    }
    else if(n % 3 == 2){
      n -= 2;
      res = (binpow(3, n / 3) * 2) % MOD;
    }
    else{
      res = (binpow(3, n / 3)) % MOD;
    }
    assert(n >= 0);
    cout << res << endl;
  }
  return 0;
}
