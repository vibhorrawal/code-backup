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

int32_t main(int argc, char const *argv[]){
  fastIO;
  int n, d, m;
  cin>>n>>d>>m;
  // D = (x2 - x1) * (yp - y1) - (xp - x1) * (y2 - y1)
// If D > 0, the point is on the left-hand side. If D < 0, the point is on the right-hand side. If D = 0, the point is on the line.
  pair<int,int> points[5] = {{d,0}, {n,n-d}, {n-d, n}, {0,d}, {d,0}};
  REP(i,m){
    int x, y; cin>>x>>y;
    bool possible = true;
    for (int j = 0; j < 4; j++) {
      double D = (points[j+1].first - points[j].first) * (y - points[j].second);
      D -= (x - points[j].first) * (points[j+1].second - points[j].second);
      if(D < 0){
        possible = false;
      }
    }
    cout << (possible ? "YES" : "NO" )<< endl;
  }
  return 0;
}
