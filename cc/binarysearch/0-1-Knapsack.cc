// O(N * capacity) time and space
int solve(vector<int>& weights, vector<int>& values, int capacity) {
    vector<vector<int>> dp(capacity + 1, vector<int>(weights.size()+1));
    for(int c = 0; c <= capacity; c++){
        for(int j = 0; j < weights.size(); j++){
            if(c - weights[j] >= 0)
                dp[c][j] = max(dp[c][j-1], dp[c-weights[j]][j-1] + values[j]);
            else
                dp[c][j] = dp[c][j-1];
        }
    }
    return *max_element(dp[capacity].begin(), dp[capacity].end());
}

// this is standard way of doing 01 knapsack
// O(NW) space and time
int solve(vector<int>& w, vector<int>& v, int W) {
    const int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if(j >= w[i-1]) dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j-w[i-1]]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

// O(NW) time | O(W) space
int solve(vector<int>& w, vector<int>& v, int W) {
    const int n = w.size();
    vector<vector<int>> dp(2, vector<int>(W + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if(j >= w[i-1]) dp[i % 2][j] = max(dp[(i-1) % 2][j], v[i-1] + dp[(i-1) % 2][j-w[i-1]]);
            else dp[i % 2][j] = dp[(i-1) % 2][j];
        }
    }
    return dp[n % 2][W];
}
