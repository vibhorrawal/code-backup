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

int binpow(ll x, ll y, ll mod){
  ll res = 1;
  while(y > 0){
    if(y & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    y = y>>1;
  }
  return res;
}
int32_t main(int argc, char const *argv[]){
  int B,P,M;
  while(cin>>B>>P>>M){
    cout << binpow(B,P,M) << endl;
  }
  return 0;
}
