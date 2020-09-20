// O(n) time | O(1) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev = prices[0], profit = 0;
        for(int price: prices){
            profit += max(0, price - prev);
            prev = price;
        }
        return profit;
    }
};

// O(n) time | O(1) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int peak = prices[0], valley = prices[0], profit = 0;
        int i = 0, n = prices.size();
        while(i < n){
            while(i+1 < n && prices[i] >= prices[i+1])
                i++;
            valley = prices[i];
            while(i+1 < n && prices[i] <= prices[i+1])
                i++;
            peak = prices[i];
            profit += peak - valley;
            i++;
        }
        return profit;
    }
};