// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

void dfs2(int v, vector<vector<int>> &tr, bool vis[]){
  vis[v] = true;
  for (auto u: tr[v]){
    if(!vis[u])
      dfs2(u, tr, vis);
  }
}
vector<int> *ga;
void dfs(int v, stack<int> &st, bool vis[]){
  vis[v] = true;
  for(auto u: ga[v]){
    if(!vis[u])
      dfs(u, st, vis);
  }
  st.push(v);
}
int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    ga = adj;
    stack<int> st;
    bool vis[V];
    memset(vis, false, sizeof vis);

    for (int u = 0; u < V; u++) {
      if(!vis[u])
        dfs(u, st, vis);
    }

    vector<vector<int>> tr (V);
    for (int i = 0; i < V; i++) {
      for (auto u: adj[i]){
        tr[u].push_back(i);
      }
    }

    memset(vis, false, sizeof vis);
    int count = 0;
    while(!st.empty()){
      int t = st.top();
      st.pop();
        if(!vis[t]){
          count++;
          dfs2(t, tr, vis);
        }

    }
    return count;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
  // } Driver Code Ends
