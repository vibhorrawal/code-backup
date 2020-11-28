#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define v2d  vector<vector<int> >
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define FOR(i,a) for(auto i=a.begin();i!=a.end();i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[ "<<#x<<" : "<<x<<" ]"<<endl;
#define endl '\n'

bool check(ll n){
  while(n){
    int s = n % 10;
    if(s & 1) return false;
    n /= 10;
  }
  return true;
}
ll solve(ll n){
  ll l = n, r = n;
  ll count = 0;
  while(!check(l) && !check(r)){
    l--;
    r++;
    count++;
  }
  return count;
}
int32_t main(int argc, char const *argv[]){
  int tc;
  cin>>tc;
  for (int i = 1; i <= tc; i++) {
    ll n; cin>>n;
    cout<<"Case #"<<i<<": "<<solve(n)<<"\n";
  }
  return 0;
}
