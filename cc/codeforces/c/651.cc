#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define sz(x) (int) x.size()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

ll manhattan(ll x1, ll y1, ll x2, ll y2){
  return abs(x2 - x1) + abs(y2 - y1);
}
double dist(ll x1, ll y1, ll x2, ll y2){
  ll d = (x2 - x1)  * (x2 - x1) + (y2 - y1) * (y2 - y1);
  return pow(d, 0.5);
}

const double eps = 1e-9;
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n;
  cin>>n;
  vi x(n), y(n);
  REP(i,n) cin>>x[i]>>y[i];
  ll count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      // ll m = manhattan(x[i], y[i], x[j], y[j]);
      double d = dist(x[i], y[i], x[j], y[j]);
      // if(abs(d - m) < eps) count++;
      if(ceil(d) == floor(d)) count++;
    }
  }
  cout << count << endl;
  return 0;
}
