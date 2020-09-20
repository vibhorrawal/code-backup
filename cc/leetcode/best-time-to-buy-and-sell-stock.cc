//O(n) time | O(1) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int profit = 0, minCost = prices[0];
        for(int price: prices){
            profit = max(price - minCost, profit);
            minCost = min(price, minCost);
        }
        return profit;
    }
};
