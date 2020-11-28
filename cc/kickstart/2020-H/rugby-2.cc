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
#define pb push_back
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
ll check(vector<pair<int,int>> line, const vi &x, const vi &y){
  sort(all(line));
  ll cost = INT_MAX;
  do {
    ll tcost = 0;
    for (int i = 0; i < sz(line); i++) {
      tcost += distance(x[i],y[i], line[i]);
    }
    cost = min(cost, tcost);
  } while(next_permutation(all(line)));
  return cost;
}
void solve(){
  int n;
  cin>>n;
  vi x(n), y(n), xx(n), yy(n);
  REP(i,n){
    cin>>x[i]>>y[i];
    xx[i] = x[i];
    yy[i] = y[i];
  }
  sort(all(x));
  sort(all(y));
  int xmed = x[sz(x)/2];
  int ymed = y[sz(y)/2];
  if(n % 2 == 0){
    xmed = (x[n/2] + x[n/2-1])/2;
    ymed = (y[n/2] + y[n/2-1])/2;
  }
  ll cost = INT_MAX;
  vector<pair<int,int>> line;
  line.pb({xmed, ymed});
  if(n & 1){
    for (int i = 1; i <= n/2; i++) {
      line.pb({xmed-i, ymed});
      line.pb({xmed+i, ymed});
    }
    cost = check(line, xx, yy);
  }
  else{
    int i;
    for (i = 1; i < n/2; i++) {
      line.pb({xmed-i, ymed});
      line.pb({xmed+i, ymed});
    }
    line.pb({xmed-i, ymed});
    cost = check(line, xx, yy);
    line.pop_back();
    line.pb({xmed + i, ymed});
    cost = min(cost, check(line, xx, yy));
  }
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
