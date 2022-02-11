// O(MN) space time
int dx[8] = {0,0,-1,-1,-1,1,1,1};
int dy[8] = {-1,1,0,-1,1,0,-1,1};
vector<vector<int>> a;
int n,m;

int count_neighbors(int r, int c){
    int ans = 0;
    for(int k = 0; k < 8; k++){
        int x = r + dx[k];
        int y = c + dy[k];
        if(x < 0 || x >= n || y < 0 || y >= m)
            continue;
        ans += a[x][y] == 1;
    }
    return ans;
}

vector<vector<int>> solve(vector<vector<int>>& matrix) {
    a = matrix;
    n = a.size();
    m = a[0].size();
    vector<vector<int>> res(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int c = count_neighbors(i,j);
            if(a[i][j] && (c == 2 || c == 3)) res[i][j] = 1;
            else if(not a[i][j] && c == 3) res[i][j] = 1;
            else res[i][j] = 0;
        }
    }
    return res;
}