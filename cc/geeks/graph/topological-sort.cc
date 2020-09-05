// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/

// method 2 (0.61)
vector<int> topoSort(int V, vector<int> adj[]) {
  std::vector<int> res, in_degree(V, 0);

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
        int u = adj[i][j];
        in_degree[u]++;
    }
  }

  queue<int> q;

  for (int i = 0; i < V; i++) {
    if(in_degree[i] == 0)
      q.push(i);
  }
  int vis = 0;

  while (!q.empty()) {
    int t = q.front();
    q.pop();

    res.push_back(t);
    vis++;

    for (int i = 0; i < adj[t].size(); i++) {
      int u =  adj[t][i];
      in_degree[u]--;
      if(in_degree[u] == 0)
        q.push(u);
    }
  }
  assert(vis == V);

  return res;
}
/*
//method 1 (0.5)
void dfs(int v, vector<int> adj[], bool vis[], stack<int> &st){
  vis[v] = true;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    if(!vis[u])
      dfs(u,adj,vis,st);
  }
  st.push(v);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    stack<int> st;
    bool vis[V];
    memset(vis, false, sizeof vis);
    for (int u = 0; u < V; u++) {
      if(!vis[u])
        dfs(u, adj,vis,st);
    }
    vector<int> res;
    while(!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    return res;
}
*/
