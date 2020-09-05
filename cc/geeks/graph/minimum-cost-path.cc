// go to minimum-cost-path-optimised.cc
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;

void clr(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct Point{
  int x;
  int y;
};

struct PointComparator{
  bool operator()(const Point &a, const Point &b){
    if(a.x != b.x)
      return a.x < b.x;
    return a.y < b.y;
  }
};

int x[] = {0,0,1,-1};
int y[] = {1,-1,0,0};

bool isInside(int x, int y, int n){
  if(x < 0 || x >= n || y < 0 || y >= n)
    return false;
  return true;
}
int min_cost(vector<vector<int>> &grid){
  int n = grid.size();
  set<Point, PointComparator> vis;
  vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
  dist[0][0] = 0;

  auto min_index = [&](){
    int minv = INT_MAX;
    Point mini;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if(minv > dist[i][j] && vis.find({i,j}) == vis.end()){
          mini = {i,j};
          minv = dist[i][j];
        }
      }
    }
    return mini;
  };

  for(int k = 0; k < n * n; k++){
    Point p = min_index();
    vis.insert(p);

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int X = p.x + x[i], Y = p.y + y[i];
        if(isInside(X,Y,n) && /* vis.find({X,Y}) == vis.end() && */
        dist[p.x][p.y] != INT_MAX && dist[X][Y] > dist[p.x][p.y] + grid[X][Y]){
          dist[X][Y] = dist[p.x][p.y] + grid[X][Y];
        }
      }
    }
  }
  return dist[n-1][n-1] + grid[0][0];
}
int32_t main(int argc, char const *argv[]){
  clr();
  T(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int> (n));
    REP(i,n) REP(j,n) cin >> grid[i][j];
    cout << min_cost(grid) << endl;
  }
  return 0;
}
