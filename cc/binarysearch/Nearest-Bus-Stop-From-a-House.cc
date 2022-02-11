// multi source BFS
struct co {
    int x, y, dist;
    // vector<vector<bool>> vis;
};
int solve(vector<vector<int>>& a) {
    queue<co> q;
    vector<vector<bool>> vis(250,vector<bool> (250));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            if(a[i][j] == 2) {
                q.push({i,j,0});
            }
        }
    }
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    while(q.size()){
        auto it = q.front(); q.pop();
        if(a[it.x][it.y] == 3) return it.dist;
        if(vis[it.x][it.y]) continue;
        vis[it.x][it.y] = true;
        
        for(int k = 0; k < 4; k++){
            int x = it.x + dx[k], y = it.y + dy[k];
            if(x < 0 or x >= a.size() or y < 0 or y >= a[0].size())
                continue;
            if(a[x][y] != 1) q.push({x,y,it.dist+1});
        }
    }
    return -1;
}