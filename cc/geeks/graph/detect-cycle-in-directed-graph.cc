// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// method 1
/*
std::vector<int> *gg;

bool cycleUtil(int v, bool visiting[], bool visited[]){

  visited[v] = true;
  visiting[v] = true;

  for (int u = 0; u < gg[v].size(); u++) {
    int i = gg[v][u];
    if(!visited[i]){
      if(cycleUtil(i,visiting, visited))
        return true;
    }
    if(visiting[i] == true)
      return true;
  }
    visiting[v] = false;
    return false;
}
 bool isCyclic(int V, vector<int> g[]){
   gg = g;
   bool visiting[V], visited[V];
   memset(visiting, false, sizeof visiting);
   memset(visited, false, sizeof visited);
   for (int u = 0; u < V; u++) {
     if(!visited[u]){

       if(cycleUtil(u, visiting, visited))
         return true;
     }
   }
   return false;
 }

 
*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
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

bool isCyclic(int V, vector<int> g[])
{
    // Your code here
    int parent[V];
  memset(parent, -1, sizeof parent);

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      int u = g[i][j];
      int x = find(i,parent);
      int y = find(u,parent);

    //   cout << "[*] "<<i<<' '<<u<<' '<<x<<' '<<y << endl;
      if(x == y)
        return true;

      Union(x,y,parent);
    }
  }
  return false;
}

// { Driver Code Starts.

int main() {

	int t;
	cin >> t;

	while(t--){

	    int v, e;
	    cin >> v >> e;

	    vector<int> adj[v];

	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }

	    cout << isCyclic(v, adj) << endl;

	}

	return 0;
}  // } Driver Code Ends
