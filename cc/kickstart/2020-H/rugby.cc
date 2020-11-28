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
const int INF = 1e9 + 5;

ll distance(int x, int y, pair<int,int> p){
  return abs(x - p.first) + abs(y - p.second);
}
ll check(pair<int,int> p, vector<pair<int,int>> &v){
  ll cost = 0;
  for (int i = 0; i < sz(v); i++) {
    int x = p.first + i;
    int y = p.second;
    // ll dist = INT_MAX, ind = 0;

    cost += distance(x,y,v[i]);
    // v[ind] = {INF, INF};
  }
  return cost;
}
void solve(){
  int n;
  cin>>n;
  vector<pair<int,int>> v(n);
  int ymin = INT_MAX, ymax = INT_MIN;
  REP(i,n){
    cin>>v[i].first>>v[i].second;
    ymin = min(ymin, v[i].second);
    ymax = max(ymax, v[i].second);
  }
  sort(all(v));
  ll cost = INT_MAX;

  for (int x = -500; x <= 500; x++) {
    for (int y = ymin; y <= ymax; y++) {
      cost = min(cost, check({x,y}, v));
    }
  }
  // for (int i = 0; i < n; i++) {
  //   cost = min(cost, check(v[i], v));
  // }
  cout << cost;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int tc;
  cin>>tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" <<i<<": ";
    solve();
    cout << "\n";
  }
  return 0;
}
