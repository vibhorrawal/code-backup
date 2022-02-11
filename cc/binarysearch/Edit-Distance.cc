// O(N^2) time and space
int solve(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(not i or not j)
                dp[i][j] = i + j;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    return dp[n][m];
}

// O(N) space
int solve(string a, string b) {
    // save space as we only use last row and curr row
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(2, vector<int>(m + 1, 0));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++){
            int curr_i = i % 2;
            if(i == 0 or j == 0) dp[curr_i][j] = i + j;
            else if(a[i-1] == b[j-1]) dp[curr_i][j] = dp[curr_i ^ 1][j - 1];
            else dp[curr_i][j] = 1 + min({dp[curr_i ^ 1][j], dp[curr_i][j-1], dp[curr_i ^ 1][j-1]});
        }
    }
    return dp[n % 2][m];
}