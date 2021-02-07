#include<bits/stdc++.h>
using namespace std;

class Tarjan {
private:
    const int UNVISITED = -1;
    bool solved = false;
    long long scc_count = 0, id = 0;

    int V;
    vector<vector<int>> g;
    stack<int> st;
    vector<bool> on_stack;
    vector<int> ids, low, sccs;
    /*
     * sccs is similar to low, just that low may have some values that don't
     * have any components hence, starting from 0, there may not be some ints which
     * can be problematic when inserting components in vector, eg: [0,2,2,2],
     * where as sccs would be like [0,1,1,1] or [1,0,0,0] depending on who is
     * encountered first
     */

    void dfs(int u){
        ids[u] = low[u] = id++;
        st.push(u);
        on_stack[u] = true;
        for(int v : g[u]){
            if(ids[v] == UNVISITED) dfs(v);
            if(on_stack[v]) low[u] = min(low[u], low[v]);
        }

        // On recursive callback, if we're at the root node (start of SCC)
        // empty the seen stack until back to root.
        if(ids[u] == low[u]){
            while(true){
                int node = st.top(); st.pop();
                on_stack[node] = false;
                sccs[node] = scc_count; // low[node] = ids[u] // use this if you dont want sccs
                if(node == u) break;
            }
            scc_count++;
        }
    }

    void solve(){
        if(solved) return;
        V = g.size();
        on_stack = vector<bool>(V);
        ids = vector<int>(V, UNVISITED);
        low = vector<int>(V);
        sccs = vector<int>(V);
        for(int i = 0; i < V; i++) if(ids[i] == UNVISITED) dfs(i);
        solved = true;
    }

public:
    Tarjan(vector<vector<int>> &adj_list){
        // swap(g, adj_list); // use this to not create a new graph
        g = adj_list;
    }

    int count_SCC(){
        if(not solved) solve();
        return scc_count;
    }

    vector<vector<int>> get_components(){
        if(not solved) solve();
        vector<vector<int>> components(scc_count);
        for(int i = 0; i < V; i++) components[sccs[i]].push_back(i);
        return components;
    }
};


int main(){
    vector<vector<int>> g = {{1}, {0}};
    Tarjan solver = Tarjan(g);
    cout << solver.count_SCC() << endl;
}
