// multisource BFS
// O(MN) space time
int solve(vector<vector<int>>& b) {
    int n = b.size();
    vector<vector<int>> vis(n, vector<int>(n, -1));
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(b[i][j] == 1) {
                q.push({i,j});
                vis[i][j] = 0;
            }
        }
    }
    int dx[8] = {1,1,-1,-1,2,2,-2,-2};
    int dy[8] = {2,-2,2,-2,1,-1,1,-1};
    while(q.size()){
        auto it = q.front(); q.pop();
        int x = it.first, y = it.second;
        if(b[x][y] == 2) return vis[x][y];
        for(int k = 0; k < 8; k++){
            int xi = x + dx[k], yi = y + dy[k];
            if(xi < 0 or xi >= n or yi < 0 or yi >= n)
                continue;
            if(vis[xi][yi] != -1) continue;
            q.push({xi,yi});
            vis[xi][yi] = vis[x][y] + 1;
        }
    }
    return -1;
}