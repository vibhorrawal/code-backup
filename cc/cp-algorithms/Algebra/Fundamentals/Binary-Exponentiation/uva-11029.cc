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

int binpow(ll n, ll k){
  ll res = 1;
  while(k){
    if(k & 1) res = (res * n) % 1000;
    n = (n * n) % 1000;
    k >>= 1;
  }
  return res;
}
int starting(int n, int k){
  /*
  * n ^ k = r (we need first 3 digits of r)
  * k * log(n) = log(r) = exp (base 10)
  * now all the part before . will make 100...
  * we need after that, and we'll convert it back to 10 ^ exp
  */
  double val = k * log10(n);
  double exp = val - floor(val);
  int res = pow(10, exp) * 100.0;
  return res;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n,k;
    cin>>n>>k;
    // cout<<starting(n,k)<<"..."<<binpow(n,k)<<endl;
    printf("%03d...%03d\n", starting(n,k), binpow(n,k));
  }
  return 0;
}
