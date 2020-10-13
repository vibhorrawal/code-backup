#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 0
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

double distance(int x1, int y1, int x2, int y2){
  double dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return sqrt(dist);
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int xa,ya,xb,yb;
  cin>>xa>>ya>>xb>>yb;
  vector<pair<int,int>> chairs;
  int minx = min(xa,xb), maxx = max(xa,xb), miny = min(ya,yb), maxy = max(ya,yb);
  for (int x = minx; x <= maxx; x++) {
    chairs.push_back({x, miny});
    chairs.push_back({x,maxy});
  }
  for (int y = miny+1; y < maxy; y++) {
    chairs.push_back({minx, y});
    chairs.push_back({maxx, y});
  }

  db(chairs.size());
  int n;
  cin>>n;
  vvi heaters(n, vi(3)); // x, y, ri
  REP(i,n){
    cin>>heaters[i][0]>>heaters[i][1]>>heaters[i][2];
  }
  vector<bool> reqd(chairs.size(), true);
  for (int i = 0; i < chairs.size(); i++) {
    for (int j = 0; j < heaters.size(); j++) {
      if(distance(chairs[i].first, chairs[i].second, heaters[j][0], heaters[j][1]) <= heaters[j][2]){
        reqd[i] = false;
        break;
      }
    }
  }
  cout << accumulate(all(reqd), 0) << endl;
  return 0;
}
