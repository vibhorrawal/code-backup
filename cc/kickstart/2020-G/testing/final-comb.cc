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

ll f2(ll selected){
  ll dist = 0;
  for (int j = 0; j < w; j++) {
    dist += calc(selected, v[j]);
  }
  return dist;
}

ll solve(){
  cin>>w>>n;
  if(w == 1) return 0;
  v.resize(w);
  REP(i,w) cin>>v[i];
  ll minDist = INT_MAX, dist = 0;
  for (int i = 1; i <= n; i++) {
    minDist = min(minDist, f2(i));
  }
  return minDist;

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
