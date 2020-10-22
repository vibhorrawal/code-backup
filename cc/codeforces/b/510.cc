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

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
const int VISITED = '*', VISITING = '-';

bool dfs(int i, int j, vector<vector<char>> &graph, int k, int pi, int pj){
  int color = graph[i][j];
  graph[i][j] = VISITING;
  // REP(i,graph.size()) {
  //   REP(j,graph[0].size()) cout<<graph[i][j]<<' ';
  //   cout<<endl;
  // }
  // cout  << endl;

  for (int kk = 0; kk < 4; kk++) {
    int ii = i + dx[kk];
    int jj = j + dy[kk];
    if(ii >= graph.size() || ii < 0 || jj >= graph[0].size() || jj < 0)
      continue;
    if(k >= 3 && ii == pi && jj == pj) return true;
    if(color == graph[ii][jj]){
      if(dfs(ii,jj,graph,k+1, pi, pj)) return true;
    }
  }
  graph[i][j] = color;
  return false;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n, m;
  cin>>n>>m;
  vector<vector<char>> graph(n, vector<char>(m));
  REP(i,n) REP(j,m) cin>>graph[i][j];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(graph[i][j] != VISITED){
        if(dfs(i,j,graph,0, i, j)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
