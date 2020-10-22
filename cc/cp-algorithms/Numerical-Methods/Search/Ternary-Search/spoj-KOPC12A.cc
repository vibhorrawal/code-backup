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

vi h, c;
int n;

ll f(ll m){
  ll cost = 0;
  for (int i = 0; i < n; i++) {
    cost += abs(h[i] - m) * c[i];
  }
  return cost;
}
ll ternary_search(ll l, ll r){
  // ll l = min(h[i], h[j]), r = max(h[i], h[j]);
  while(r-l > 3){
    ll m1 = l + (r-l)/3;
    ll m2 = r - (r-l)/3;
    if(f(m1) > f(m2))
      l = m1;
    else
      r = m2;
  }
  return min({f(l), f(l+1), f(l+2), f(r)});
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    cin>>n;
    h.resize(n);
    c.resize(n);
    REP(i,n) cin>>h[i];
    REP(i,n) cin>>c[i];
    int min = *min_element(h.begin(), h.end());
    int max = *max_element(h.begin(), h.end());
    ll mincost = ternary_search(min, max);
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //     if(i == j) continue;
    //     mincost = min(ternary_search(i,j), mincost);
    //   }
    // }
    cout << mincost << endl;
  }
  return 0;
}
