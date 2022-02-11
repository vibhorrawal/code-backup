// O(V + E) space time
bool is_topological(vector<vector<int>> &graph, vector<int> &inorder){
    int s;
    vector<bool> vis(251);
    queue<int> q;
    for(int i = 0; i < 251; i++){
        if(inorder[i] == 0)
            q.push(i);
    }
    int count = 0;
    while(q.size()){
        int u = q.front(); q.pop();
        if(vis[u]) return false;
        vis[u] = true;
        count++;
        for(int v : graph[u]){
            if(--inorder[v] == 0)
                q.push(v);
        }
    }
    cout<<count;
    return count == 251;
}
bool solve(vector<vector<int>>& matrix) {
    vector<vector<int>> graph(251);
    vector<int> inorder(251); // i meant indegree
    for(int v = 0; v < matrix.size(); v++){
        for(int u : matrix[v]){
            graph[u].push_back(v);
            inorder[v]++;
        }
    }
    return is_topological(graph, inorder);
}