// O(V + E) time | O(V)
// BFS
int solve(vector<vector<int>>& graph, int target) {
    queue<pair<int,int>> q;
    vector<int> vis(251, false);
    q.push({target, 0});
    while(q.size()){
        auto it = q.front(); q.pop();
        if(it.second and it.first == target)
            return it.second;
        
        if(vis[it.first]) continue;
        vis[it.first] = true;
        
        for(int v : graph[it.first]){
            q.push({v, it.second + 1});
        }
    }
    return -1;
}