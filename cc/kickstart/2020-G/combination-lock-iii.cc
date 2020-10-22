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
ll calc(ll a, ll b){
  ll res = abs(a - b);
  return min(res, (n - res));
}

ll f(ll selected){
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
    // return min({f(l), f(l+1), f(l+2)});                    //return the maximum of f(x) in [l, r]
    ll minv = INT_MAX;
    for (int i = l-10; i < r+10; i++) {
      minv = min(minv, f(i));
    }
    return minv;
}
ll solve(){
  cin>>w>>n;
  if(w == 1) return 0;
  v.resize(w);
  REP(i,w) cin>>v[i];

  return ternary_search(1, n);
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int tc;
  cin>>tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i<<": "<<solve();
    cout<<endl;
  }
//
// int a = 2;
// n = 3;
//   for (int i = 0; i < 10; i++) {
//      wrapDown(a);
//     cout <<a << endl;
//   }
  return 0;
}
