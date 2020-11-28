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
