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

int dx[] = {0,0,-1,-1,-1,1,1,1};
int dy[] = {-1,1,1,0,-1,1,0,-1};
int dfs(int x, int y, vvi &v, vvi &vis, int n, int m){
  if(x < 0 || x >= n || y < 0 || y >= m)
    return 0;
  if(v[x][y] == 0) return 0;

  vis[x][y] = 1;
  int ans = 0;
  for (int i = 0; i < 8; i++) {
      int xi = x + dx[i];
      int yi = y + dy[i];
      if(!vis[xi][yi] && v[xi][yi])
        ans += dfs(xi,yi, v, vis, n, m);
    }
  return ans;
}
int max_area(vvi &v, int n, int m){
  vvi vis(n, vi (m, 0));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(!vis[i][j] && v[i][j])
        ans = max(ans, dfs(i, j, v, vis, n, m));
    }
  }
  return ans;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    int n, m;
    cin >> n >> m;
    vvi v(n, vi (m));
    REP(i, n) REP(j, m) cin >> v[i][j];
    cout << max_area(v, n, m) << endl;
  }
  return 0;
}
