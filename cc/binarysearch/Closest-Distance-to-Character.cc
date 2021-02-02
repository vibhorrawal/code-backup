// O(n) space and time
vector<int> solve(string s, string c) {
    vector<int> dp(s.size(), 1e9);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == c[0]) dp[i] = 0;
    }
    for(int i = 1; i < s.size(); i++){
        dp[i] = min(dp[i], dp[i-1] + 1);
    }
    for(int i = s.size()-2; i >= 0; i--){
        dp[i] = min(dp[i], dp[i+1] + 1);
    }
    return dp;
}
