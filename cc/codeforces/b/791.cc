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

const int nmax = 150001;
vector<int> edges[nmax];
bool vis[nmax];

void dfs(int u, int &count_edges, int &count_vertices){
  assert(!vis[u]);
  vis[u] = true;
  count_vertices++;
  count_edges += edges[u].size();
  for(int v : edges[u])
    if(!vis[v]) dfs(v, count_edges, count_vertices);
}
// check if each connected component is clique
// a clique is where every vertex is connected to other vertex
// so count_edges = nC2
// => count_vertices * (count_vertices - 1) / 2
int32_t main(int argc, char const *argv[]){
  fastIO;
  int n, m;
  cin >> n >> m;
  REP(i,m){
    int a, b;
    cin>>a>>b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if(!vis[i]){
      int count_edges = 0, count_vertices = 0;
      dfs(i, count_edges, count_vertices);
      if(count_edges != (ll) count_vertices * (count_vertices - 1)){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
