//O(n) time | O(1) space
class Solution {
    https://stackoverflow.com/questions/56555654/buy-sell-stock-with-transaction-fee
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, holding = -prices[0];
        for(int i = 0; i< prices.size(); i++){
            cash = max(holding + prices[i] - fee, cash);
            holding = max(cash - prices[i], holding);
        }
        return cash;
    }
};
