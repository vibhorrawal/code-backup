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

ll w, n;
vi v;
vector<ll> val;
ll calc(ll a, ll b){
  ll res = abs(a - b);
  return min(res, (n - res));
}
ll f(ll a){
  a = ((a-1) % n) + 1;
  if(a < 1) a += n;
  return val[a];
}
ll f2(ll selected){
  ll dist = 0;
  for (int j = 0; j < w; j++) {
    dist += calc(selected, v[j]);
  }
  return dist;
}
ll ternary_search(double l, double r) {
    while (r - l > 3) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        ll f1 = f(m1);      //evaluates the function at m1
        ll f2 = f(m2);      //evaluates the function at m2
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    // return min({f(l), f(l+1), f(l+2), f(l+3), f(l-1), f(l-2), f(l-3)});
                     //return the maximum of f(x) in [l, r]
   ll minv = INT_MAX;
   for (int i = l-(0.01 * n); i < l+(0.01 * n); i++) {
     minv = min(minv, f(i));
   }
   // for (int i = r-3; i < r+3; i++) {
   //   minv = min(minv, f(i));
   // }
   return minv;
}
void precompute(){
  val.resize(n+1);
  for (ll i = 1; i <= n; i++) {
    val[i] = f2(i);
    // db(val[i]);
  }
}
ll solve(){
  cin>>w>>n;
  if(w == 1) return 0;
  v.resize(w);
  REP(i,w) cin>>v[i];
  // precompute();
  // return *min_element(val.begin()+1, val.end());
  ll minDist = INT_MAX, dist = 0;

  for (int i = 1; i <= n; i++) {
    minDist = min(minDist, f2(i));
  }
  return minDist;
  // ll minDist = INT_MAX, dist = 0;
  // for (int i = 0; i < w; i++) {
  //   for (int j = 0; j < w; j++) {
  //     if(i == j) continue;
  //     dist = ternary_search(v[i], v[j]);
  //   }
  //   minDist = min(dist, minDist);
  // }
  // return minDist;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int tc;
  cin>>tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i<<": "<<solve();
    cout<<endl;
  }
  return 0;
}
