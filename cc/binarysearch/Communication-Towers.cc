// O(N) space time
// Union find
vector<vector<int>> a;
int n, m;
vector<int> parent;
vector<int> child;
int cell(const pair<int,int> &p){
    return p.first * m + p.second;
}
int find(int i){
    if(parent[i] == -1) return i;
    return find(parent[i]);
}

void Union(int ax, int bx){
    int pa = find(ax), pb = find(bx);
    if(pa == pb)
        return;
    if(child[pa] > child[pb]){
        parent[pb] = pa;
        child[pa] += child[pb];
    }
    else{
        parent[pa] = pb;
        child[pb] += child[pa];
    }
}

void Union(const pair<int,int> &aa, const pair<int,int> &bb){
    Union(cell(aa), cell(bb));
}
int solve(vector<vector<int>>& a_) {
    a = a_;
    n = a.size(), m = a[0].size();
    
    parent = vector<int> (m * n, -1);
    child = vector<int> (m * n, 1); 
    
    unordered_map<int,set<pair<int,int>>> row, col;
    for(int r = 0; r < a.size(); r++){
        for(int c = 0; c < a[r].size(); c++){
            if(a[r][c] == 0) 
                continue;
            
            for(auto i : row[r]){
                Union(i, {r,c});
            }
            
            for(auto i : col[c]){
                Union(i, {r,c});
            }
            row[r].insert({r,c});
            col[c].insert({r,c});
        }
    } 
    
    unordered_set<int> group;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            if(a[i][j] == 0) continue;
            
            int g = find(cell({i,j}));
            // cout<<g<<' ';
            group.insert(g);
        }
    }
    return group.size();
}

// O(N) space time
// multi source BFS
int solve(vector<vector<int>>& a) {
    int ans = 0;
    queue<pair<int,int>> q;
    set<int> row, col;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            if(a[i][j] == 0) continue;
            q.push({i,j});
            ans++;
            while(q.size()){
                auto it = q.front(); q.pop();
                a[it.first][it.second] = 0;
                if(not col.count(it.second))
                    for(int r = 0; r < a.size(); r++){
                        if(a[r][it.second] == 1)
                            q.push({r, it.second});
                    }
                if(not row.count(it.first))
                    for(int c = 0; c < a[0].size(); c++){
                        if(a[it.first][c] == 1)
                            q.push({it.first, c});
                    }
                row.insert(it.first);
                col.insert(it.second);
            }
        }
    }
    return ans;
}