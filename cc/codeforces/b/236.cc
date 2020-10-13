#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
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

map<ll,ll> mp;
ll d(ll n){
  if(mp[n]) return mp[n];
  if(n == 1)
    return 1;
  if(n == 2)
    return 2;

  ll divisor = 0;
  for (int i = 1; i*i <= n; i++) {
    if(n % i == 0)
      divisor += i*i == n ? 1 : 2;
  }
  return mp[n] = divisor;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int a,b,c;
  cin>>a>>b>>c;
  int M = pow(2,30);
  ll res = 0;
  // for (int i = 1; i < 20; i++) {
  //   cout << i<<':'<<d(i) << endl;
  // }
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
          res = (res + d((ll) i * j * k)) % M;
      }
    }
  }
  cout << res << endl;
  return 0;
}
