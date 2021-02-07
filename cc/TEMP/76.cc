// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Tarjan {
private:
    int V, scc_count, id = 0;
    bool solved = false;
    const int UNVISITED = -1;
    stack<int> st;
    vector<bool> on_stack;
    vector<int> ids, low, sccs;
    vector<vector<int>> g;
public:
    Tarjan(){

    }
    Tarjan(vector<vector<int>> &adj_list){
        g = adj_list;
    }

    int count_SCC(){
        if(not solved) solve();
        return scc_count;
    }

    void solve(){
        if(solved) return;
        V = g.size();
        on_stack = vector<bool>(V);
        ids = vector<int>(V, UNVISITED);
        low = vector<int>(V);
        sccs = vector<int>(V);
        for(int i = 0; i < V; i++) {
            if(ids[i] == UNVISITED)
                dfs(i);
        }
        solved = true;
    }

    void dfs(int u){
        ids[u] = low[u] = id++;
        st.push(u);
        on_stack[u] = true;

        for(int v : g[u]){
            if(ids[v] == UNVISITED)
                dfs(v);

            if(on_stack[v])
                low[u] = min(low[u], low[v]);
        }

        // On recursive callback, if we're at the root node (start of SCC)
        // empty the seen stack until back to root.
        if(ids[u] == low[u]){
            while(true){
                int node = st.top(); st.pop();
                on_stack[node] = false;
                sccs[node] = scc_count;
                if(node == u) break;
            }
            scc_count++;
        }
    }
};

class Solution{
	public:
	/*  Function to find the members of strongly connected components
    *   using Tarjan's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        //code here
        vector<vector<int>> g(V);
        for(int i = 0; i < V; i++) g[i] = adj[i];
        Tarjan solver = Tarjan(g);
        cout<<": " << solver.count_SCC()<<"; ";
        return {{}};

    }
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
