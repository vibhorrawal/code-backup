// O(nk) time | O(n) space
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2)
            return 0;
        if (2 * k > n) {
            int res = 0;
            for (int i = 1; i < n; i++) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }
        vector<vector<int>> profit(2, vector<int> (n, 0));
        
        for(int i = 1; i <= k; i++){
            int maxThusFar = INT_MIN;
            for(int j = 1; j < n; j++){
                maxThusFar = max(profit[(i-1)%2][j-1] - prices[j-1], maxThusFar);
                profit[i % 2][j] = max(profit[i % 2][j-1], prices[j] + maxThusFar);
            }
        }
        return profit[k % 2][n-1];
    }
};
