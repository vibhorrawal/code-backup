#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

const int INF = 1e7;

struct cell{
  int x;
  int y;
  int dist;
  cell(int x, int y, int dist) : x(x), y(y), dist(dist) {};
};
bool operator<(const cell &a, const cell &b){
  if(a.dist != b.dist)
    return a.dist < b.dist;
  if(a.x != b.x)
    return a.x < b.x;
  return a.y < b.y;
}

bool isInside(int x, int y, int n){
  if(x < 0 || x >= n || y < 0 || y >= n)
    return false;
  return true;
}

int min_cost(vector<vector<int>> &grid){
  int n = grid.size();
  set<cell> st;
  vvi dist(n, vi(n, INF));
  int dx[] = {0,0,1,-1};
  int dy[] = {-1,1,0,0};

  st.insert({0,0,0});
  dist[0][0] = grid[0][0];

  while(!st.empty()){
    auto p = *st.begin();
    st.erase(st.begin());
    for (int i = 0; i < 4; i++) {
      int x = p.x + dx[i];
      int y = p.y + dy[i];

      if(!isInside(x,y,n))
        continue;

      if(dist[x][y] > dist[p.x][p.y] + grid[x][y]){
        if(dist[x][y] != INF)
          st.erase(st.find({x,y,dist[x][y]}));

        dist[x][y] = dist[p.x][p.y] + grid[x][y];
        st.insert({x,y,dist[x][y]});
      }
    }
  }

  return dist[n-1][n-1];
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int> (n));
    REP(i,n) REP(j,n) cin >> grid[i][j];
    cout << min_cost(grid) << endl;
  }
  return 0;
}
