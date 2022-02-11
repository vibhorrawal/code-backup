// O(N) space time where N is num of elements
// O(nm) n->rows, m->cols in input
const int SZ = 1e5 + 1;
void dfs(vector<vector<int>> &g, int u, vector<bool> &vis, vector<int> &res){
    if(vis[u]) return;
    vis[u] = true;
    for(int v : g[u]){
        dfs(g,v,vis,res);
    }
    res.push_back(u);
}
vector<int> solve(vector<vector<int>>& lists) {
    vector<vector<int>> g(SZ);
    unordered_set<int> s;
    for(auto it : lists){
        for(int i = 0; i < it.size()-1; i++){
            int u = it[i], v = it[i+1];
            g[u].push_back(v);
            s.insert(u);
            s.insert(v);
        }
    }
    vector<int> res;
    vector<bool> vis(SZ, false);
    for(int i = 0; i < SZ; i++){
        if(not s.count(i)) vis[i] = true;
    }
    for(int i = 0; i < SZ; i++){
        if(not vis[i]){
            dfs(g, i, vis, res);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

// same
unordered_map<int,int> mp, pm;

inline int getNode(int i) {
    if(!mp.count(i)) {
        mp[i] = mp.size() + 1;
        pm[mp.size()] = i;
    }
    return mp[i];
}

inline int getVal(int i) {
    return pm[i];
}

void dfs(int u, vector<bool> &vis, vector<vector<int>> &g, vector<int>& res) {
    if(vis[u]) return;
    vis[u] = true;
    for(int v : g[u]) {
        dfs(v, vis, g, res);
    }
    res.push_back(getVal(u));
}
vector<int> solve(vector<vector<int>>& lists) {
    mp.clear(); 
    for(auto it : lists) for(int i : it) getNode(i);
    const int n = mp.size() + 1;
    vector<vector<int>> g(n);
    for(auto list : lists) {
        for(int i = 0; i < list.size() - 1; i++) {
            int u = getNode(list[i]), v = getNode(list[i + 1]);
            g[u].push_back(v);
        }
    }
    vector<bool> vis(n, false);
    vector<int> res;
    for(int u = 1; u < n; u++) {
            dfs(u, vis, g, res);
    }
    reverse(res.begin(), res.end());
    return res;
}

// cleaner
vector<int> solve(vector<vector<int>>& lists) {
    unordered_map<int,vector<int>> edges;
    unordered_set<int> vertices;
    unordered_map<int,int> num_of_parents;

    for(auto &list: lists) {
        vertices.insert(list[0]);
        for(int i = 1; i < list.size(); i++) {
            int u = list[i-1], v = list[i];
            vertices.insert(v);
            edges[u].push_back(v);
            num_of_parents[v]++;
        }
    }

    vector<int> res;

    for(int vertex: vertices) 
        if(num_of_parents[vertex] == 0) 
            res.push_back(vertex);

    for(int i = 0; i < res.size(); i++) 
        for(int v: edges[res[i]]) 
            if(--num_of_parents[v] == 0) res.push_back(v);

    return res;
}
