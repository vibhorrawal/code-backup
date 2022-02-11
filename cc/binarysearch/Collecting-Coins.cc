// O(MN) time and space
int solve(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(not i and not j)
                dp[i][j] = a[i][j];
            else if(not i)
                dp[i][j] = max(dp[i][j], dp[i][j-1] + a[i][j]);
            else if(not j)
                dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i][j]);
            else
                dp[i][j] = max({dp[i][j], dp[i-1][j] + a[i][j], dp[i][j-1] + a[i][j]});
        }
    }
    return dp[n-1][m-1];
}