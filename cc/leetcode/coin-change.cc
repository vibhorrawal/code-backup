// O(amount * n) time | O(amount) space
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;
        for(int c : coins){
            for(int i = 0; i <= amount; i++){
                if(i-c >= 0)
                    dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};

// O(amount * n) time and space
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int n = coins.size(), INF = 1e9 + 5;
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, INF));

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= amount; j++){
                if(j == 0)
                    dp[i][j] = 0;
                else if(j >= coins[i-1])
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - coins[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        int ans = dp[n][amount];
        if(ans == INF) return -1;
        return ans;
    }
};
