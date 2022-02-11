// O(n) space time
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int INF = 1e9 + 5, n = cost.size();
        vector<int> dp(n, INF);
        dp[0] = cost[0], dp[1] = cost[1];
        for(int i = 0; i < n; i++) {
            if(i + 1 < n) dp[i+1] = min(dp[i] + cost[i+1], dp[i+1]);
            if(i + 2 < n) dp[i+2] = min(dp[i] + cost[i+2], dp[i+2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};