
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

// top down DP
class Solution {
    vector<vector<int>> cache;
    bool knapsack(vector<int> &weight, int n, int W) {
        if(W == 0)
            return true;
        if(n == 0)
            return false;
        if(cache[n][W] != -1)
            return cache[n][W];
        if(W >= weight[n-1])
            return cache[n][W] = knapsack(weight, n-1, W) or knapsack(weight, n-1, W - weight[n-1]);

        return cache[n][W] = knapsack(weight, n-1, W);
}
public:
    bool canPartition(vector<int>& nums) {
        vector<vector<int>> t(202, vector<int> (20200, -1));
        cache = t;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int n = nums.size();

        return knapsack(nums, n, sum/2);
    }
};

// bottom up DP
class Solution {
    bool knapsack(vector<int> &arr, int n, int W) {
        vector<vector<bool>> dp(n+1, vector<bool> (W+1, false));
        for(int i = 0; i < n + 1; i++) dp[i][0] = true;

        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < W + 1; j++){
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j] or dp[i-1][j - arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][W];
}
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int n = nums.size();

        return knapsack(nums, n, sum/2);
    }
};
