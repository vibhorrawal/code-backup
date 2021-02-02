// O(MN) time | O(M + N) space
int solve(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    vector<int> row(n), col(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans += (a[i][j] and row[i] == 1 and col[j] == 1);
        }
    }
    return ans;
}
