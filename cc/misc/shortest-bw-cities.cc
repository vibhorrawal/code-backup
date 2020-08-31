#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(auto i=0;i<(n);i++)
#define INF 1e9

void floyd(vector<vector<int> > &graph, int q){
  int V = graph.size();
  int i, j, k;
  vector<vector<int> > dist(V,vector<int> (V));
  for (i = 0; i < V; i++)
      for (j = 0; j < V; j++)
          dist[i][j] = graph[i][j];

  for (k = 1; k < V; k++)
    {
        for (i = 1; i < V; i++)
        {
            for (j = 1; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    //queries
    REP(i,q){
      int c1,c2;
      cin>>c1>>c2;
      cout<<(dist[c1][c2] == INF? -1: dist[c1][c2])<<endl;
    }
}
int32_t main(int argc, char const *argv[]){
  int n,m,q;
  cin>>n>>m>>q;
  vector<vector<int> > graph(n+1,vector<int> (n+1,INF));
  for (int i = 0; i < m; i++) {
      int x,y,d;
      cin>>x>>y>>d;
      graph[x][y] = d;
  }
  REP(i,n+1) graph[i][i]  = 0;

  floyd(graph,q);
  return 0;
}
