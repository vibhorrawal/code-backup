// O(MN) time and space
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
vector<vector<int>> a;

bool isOutside(int x, int y){
    if(x < 0 || x >= a.size() || y < 0 || y >= a[0].size()) 
        return true;
    return a[x][y] == 0;
}
int dfs(int x, int y, vector<vector<bool>> &vis){
    if(vis[x][y]) return 0;
    vis[x][y] = true;
    int count = 0;
    for(int k = 0; k < 4; k++){
        int xx = x + dx[k];
        int yy = y + dy[k];
        if(isOutside(xx,yy))
            count++;
        else if (a[xx][yy])
            count += dfs(xx,yy, vis);
    }
    return count;
}
int solve(vector<vector<int>>& b) {
    a = b;
    int n = a.size(), m = a[0].size();
    vector<vector<bool>> vis(n,vector<bool> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j]) return dfs(i,j,vis);
        }
    }
    return 0;
}


// cleaner O(1) space
int solve(vector<vector<int>>& a) {
    int ans = 0;
    int n = a.size(), m = a[0].size();
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            if(a[i][j] == 0) continue;
            ans += i == 0 or !a[i-1][j];
            ans += i == n-1 or !a[i+1][j];
            ans += j == 0 or !a[i][j-1];
            ans += j == m-1 or !a[i][j+1];
        }
    }
    return ans;
}

// found this beautiful impl
int solve(vector<vector<int>>& a) {
    int perimeter = 0, n = a.size(), m = a[0].size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!a[i][j]) continue;
            int surrounding = 4;
            if(i > 0 and a[i-1][j]) surrounding--;
            if(i+1 < n and a[i+1][j]) surrounding--;
            if(j > 0 and a[i][j-1]) surrounding--;
            if(j+1 < m and a[i][j+1]) surrounding--;
            perimeter += surrounding;
        }
    }
    return perimeter;
}