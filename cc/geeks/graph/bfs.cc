// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {
    // res.clear();
    std::vector<int> res;
    bool vis[N];
    memset(vis, false, sizeof vis);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
      int t = q.front();
      q.pop();
      if(!vis[t])
        res.push_back(t);
      vis[t] = true;
      for(int i = 0; i < g[t].size(); i++){
        int v = g[t][i];
        if(!vis[v]){
          q.push(v);
        }
      }
    }
    return res;
}
