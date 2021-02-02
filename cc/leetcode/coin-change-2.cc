class Solution {
    vector<int> d;
    int util(int n, int i){
        if(n == 0)
            return 1;
        if(n < 0)
            return 0;
        if(i < 0)
            return 0;
        if(d[i] <= n)
            return util(n-d[i], i) + util(n, i-1);
        else
            return util(n,i-1);
    }
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());
        // d = coins;
        // return util(amount, d.size()-1);

        vector<vector<int>> change(coins.size()+1, vector<int> (amount+1));
        for(int i = 0; i <= coins.size(); i++){
            for(int j = 0; j <= amount; j++){
                if(j == 0)
                    change[i][j] = 1;
                else if(i == 0)
                    change[i][j] = 0;
                else{
                    if(j >= coins[i-1])
                        change[i][j] = (change[i-1][j] + change[i][j-coins[i-1]]);
                    else
                        change[i][j] = change[i-1][j];
                }
            }
        }
        return change[coins.size()][amount];
    }
};

//
class Solution {

public:
    int change(int amount, vector<int>& coins) {
        vector<int> ways(amount+1, 0);
        ways[0] = 1;
            for(int val = 1; val <= amount; val++){
        for(int coin: coins){
                if(coin <= val)
                    ways[val] += ways[val-coin];
            }
        }
        return ways[amount];
    }
};

// unbound knapsack O(n * amount) time and space
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1));

        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < amount + 1; j++){
                if(j == 0)
                    dp[i][j] = 1;
                else if(i == 0)
                    dp[i][j] = 0;
                else if(j >= coins[i-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount];
    }
};
