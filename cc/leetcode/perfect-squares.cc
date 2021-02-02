// O(n * n) space and time
// tle
class Solution {
public:
    int numSquares(int n) {
        const int INF = 1e9 + 5;
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, INF));

        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < n + 1; j++){
                if(j == 0)
                    dp[i][j] = 0;
                else if(i == 0)
                    dp[i][j] = INF;
                else if(j >= i * i)
                    dp[i][j] = min(dp[i-1][j], 1 + dp[i][j - i * i]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][n];
    }
};

// O(n * sqrt(n)) time and O(n) space
class Solution {
public:
    int numSquares(int n) {
        const int INF = 1e9 + 5;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j * j <= i; j++){
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};
