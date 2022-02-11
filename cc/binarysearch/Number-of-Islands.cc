// O(MN) space time; here modifying i/p, use a visited array if constrained
// flood fill
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector<vector<int>> a;

void dfs(int x, int y){
    if(not a[x][y]) return;
    a[x][y] = 0;
    for(int k = 0; k < 4; k++){
        int r = x + dx[k];
        int c = y + dy[k];
        if(r < 0 || r >= a.size() || c < 0 || c >= a[0].size())
            continue;
        dfs(r,c);
    }
}
int solve(vector<vector<int>>& matrix) {
    a = matrix;
    int ans = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            if(a[i][j]){
                ans +=1;
                dfs(i,j);
            }
        }
    }
    return ans;
}