// O(MN) time and space
vector<vector<int>> a;
int n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int dfs(int r, int c){
    a[r][c] = 0;
    int count = 1;
    bool flag = true;
    for(int i = 0; i < 4; i++){
        int xi = dx[i] + r;
        int yi = dy[i] + c;
        if(xi >= n or xi < 0 or yi >= m or yi < 0){
            flag = false;
            continue;
        }
        if(not a[xi][yi]) continue;
        int d = dfs(xi,yi);
        if(d == 0) flag = false;
        count += d;
    }
    return count * flag;
}
int solve(vector<vector<int>>& a_) {
    a = a_;
    n = a.size(), m = a[0].size();
    int ans = 0;
    for(int i =0;i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j])
                ans += dfs(i,j);
        }
    }
    return ans;
}