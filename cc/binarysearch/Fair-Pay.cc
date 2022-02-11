// O(N) space time
int solve(vector<int>& ratings) {
    vector<int> dp(ratings.size(),1);
    int n = ratings.size();
    for(int i = 1; i < n; i++){
        if(ratings[i] > ratings[i-1])  
            dp[i] = dp[i-1] + 1;
    }
    for(int i = n-2; i >= 0; i--){
        if(ratings[i] > ratings[i+1])
            dp[i] = max(dp[i], dp[i+1] + 1);
    }
    return accumulate(dp.begin(), dp.end(),0);
}