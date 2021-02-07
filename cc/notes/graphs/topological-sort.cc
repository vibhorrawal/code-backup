
// Kahn's algorithm, can detect cycle too and hence if top sort is possible or not
vector<int> topological_sort(vvi graph) {
    const int n = graph.size();
    vector<int> res, indegree(n, 0);
    for(int i = 0; i < n; i++) {
        for(int v : graph[i]){
            indegree[v]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0)
            q.push(i);
    while(!q.empty()){
        int u = q.front(); q.pop();
        res.push_back(u);
        for(int v: graph[u])
            if(--indegree[v] == 0)
                q.push(v);
    }
    if(res.size() == n)
        return res;

    // there is a cycle in graph
    return {};
}

//------------------------------------------------------------------------------
// other way
void dfs(int u, vector<bool> vis, vvi graph, vector<int> res){
    vis[u] = true;
    for(int v : graph[u]){
        if(not vis[v]) dfs(v, vis, graph, res);
    }
    res.push_back(u);
}
vector<int> topsort(vvi graph){
    vector<int> res; // will behave as a stack
    const int n = graph.size();
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if(not vis[i]) dfs(i, vis, graph, res);
    }
    reverse(res.begin(), res.end());
    return res;
}
