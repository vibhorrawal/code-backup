// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

int find(int i, int parent[]){
  if(parent[i] == -1) return i;
  return find(parent[i], parent);
}

void Union (int x, int y, int parent[]){
  int xi = find(x, parent);
  int yi = find(y, parent);
  if(xi == yi) return;
  parent[xi] = yi;
}

bool isCyclic(vector<int> g[], int V){
  int parent[V];
  memset(parent, -1, sizeof parent);

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      int u = g[i][j];
      if(i >= u) continue;
      int x = find(i,parent);
      int y = find(u,parent);

      if(x == y)
        return true;

      Union(x,y,parent);
    }
  }
  return false;
}

  //other method 3
/*
bool cyclicUtil(vector<int> g[],bool vis[],int v, int parent){
  vis[v] = true;

  for (int i = 0; i < g[v].size(); i++) {
    int u = g[v][i];
    if(!vis[u]){
      if(cyclicUtil(g,vis,u,v))
        return true;
      }
      else if(parent != u)
        return true;
  }
  return false;
}
bool isCyclic(vector<int> g[], int V){
  bool vis[V];
  memset(vis, false, sizeof vis);

  for (int u = 0; u < V; u++) {
    if(!vis[u])
      if(cyclicUtil(g,vis,u,-1))
        return true;
  }
  return false;
}
*/

/*
// method 2
bool dfs(vector<int> g[], int e, bool vis[], bool visiting[]){
  if(visiting[e]) return true;
  if(vis[e]) return false;

  vis[e] = true;
  for (int i = 0; i < g[e].size(); i++) {
    int el = g[e][i];
    if(!vis[el]){
      visiting[el] = true;
      if(dfs(g,el,vis, visiting))
      return true;
      visiting[el] = false;
    }
  }
  return false;
}
bool isCyclic(vector<int> g[], int V)
{
   // Your code here
   bool vis[SIZE], visiting[SIZE];
   memset(vis, false, sizeof vis);
   memset(visiting, false, sizeof visiting);
   for (int u = 0; u < V; u++) {
     if(!vis[u]){
       // visiting[u] = true;
       if(dfs(g,u,vis, visiting)) return true;
       // visiting[u] = false;
     }
   }
   return false;
}
*/
// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
