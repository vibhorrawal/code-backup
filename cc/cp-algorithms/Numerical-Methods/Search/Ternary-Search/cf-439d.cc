#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

vi a,b;
int n,m;

double f(ll k){
  ll res = 0;
  for(int i = 0; i < n; i++){
    if(k > a[i]) res += k - a[i];
  }
  for (int i = 0; i < m; i++) {
    if(k < b[i]) res += b[i] - k;
  }
  return res;
}

ll ternary_search(ll l, ll r){
  REP(c,100){
    ll m1 = l + (r-l)/3;
    ll m2 = r - (r-l)/3;
    if(f(m1) > f(m2))
      l = m1;
    else
      r = m2;
  }
  db(l);db(r);
  // assert(f(l) == f(r));
  return min({f(l), f(l+1), f(r)});
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  cin>>n>>m;
  a.resize(n);
  b.resize(m);
  REP(i,n) cin>>a[i];
  REP(i,m) cin>>b[i];
  db(f(3));
  cout << ternary_search(1, INT_MAX) << endl;
  return 0;
}
