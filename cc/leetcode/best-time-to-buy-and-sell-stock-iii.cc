// O(n) time | O(n) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> firstProfit(n);
        int minStockToBuy = prices[0];
        for(int i = 1; i < n; i++){
            firstProfit[i] = max(firstProfit[i-1], prices[i] - minStockToBuy);
            minStockToBuy = min(prices[i], minStockToBuy);
        }
        //now for second transaction
        int maxprofit = 0, secondStock = -prices[0] + firstProfit[0];
        for(int i = 1; i < n; i++){
            secondStock = max(secondStock, -prices[i-1] + firstProfit[i-1]);
            maxprofit = max(maxprofit, prices[i] + secondStock);
        }
        return maxprofit;
    }
};

//O(n) time | O(n) space
// divide and conquer
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> leftProfit(n, 0), rightProfit(n, 0);
        int leftMin = prices[0]; // best buying price
        for(int i = 1; i < n; i++){
            leftProfit[i] = max(leftProfit[i-1], prices[i] - leftMin);
            leftMin = min(prices[i], leftMin);
        }
        
        int rightMax = prices[n-1]; //best selling price
        for(int i = n-2; i >= 0; i--){
            rightProfit[i] = max(rightProfit[i+1], rightMax - prices[i]);
            rightMax = max(prices[i], rightMax);
        }
        
        int profit = rightProfit[0];
        for(int i = 1; i < n; i++){
            profit = max(leftProfit[i-1] + rightProfit[i], profit);
        }
        return profit;
    }
};