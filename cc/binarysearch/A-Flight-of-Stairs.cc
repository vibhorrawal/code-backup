// O(N) time and space
int solve(int n) {
    if(n < 3) return n;
    const int M = 1e9 + 7;
    vector<int> dp(n + 1);
    dp[0] = 0, dp[1] = 1, dp[2] = 2;
    for(int i = 3; i <= n; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % M;
    return dp[n];
}

// O(N) time | O(1) space
int solve(int n) {
    if(n < 3) return n;
    const int M = 1e9 + 7;
    int a = 2, b = 1;
    for(int i = 3; i <= n; i++){
        int new_a = (a + b) % M;
        b = a;
        a = new_a;
    }
    return a;
}
