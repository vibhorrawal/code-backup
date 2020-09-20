
// O(n*sum) time and space
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1)
            return false;
        sum /= 2;
        vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(j == 0)
                    dp[i][j] = true;
                else if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};
