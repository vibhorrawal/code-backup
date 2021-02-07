// find root such that it gives maximum height

// undirected graph g
vector<int> find_tree_centers(vector<vector<int>> g){ // will return either 1 or 2 center
    const int n = g.size();
    vector<int> degree(n);
    vector<int> levels;
    for(int i = 0; i < n; i++) {
        degree[i] = g[i].size();
        if(degree[i] <= 1) {
            levels.push_back(i);
            degree[i] = 0;
        }
    }
    int processed_leafs = levels.size();
    while(processed_leafs < n){
        new_levels = vector<int>;
        for(int u : levels){
            for(int v : g[u]){
                if(--degree[v] == 1){
                    new_levels.push_back(v);
                }
            }
            degree[u] = 0;
        }
        levels = new_levels;
        processed_leafs += levels.size();
    }
    return levels;
}
