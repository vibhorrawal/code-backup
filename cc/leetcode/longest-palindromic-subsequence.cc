// O(n^2) time | O(n^2) space
class Solution {
    int lcs(string s, string t){
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s,t);
    }
};

// O(n^2) time | O(n^2) space
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        for(int gap = 1; gap < n; gap++){
            for(int i = 0, j = gap + i; j < n; i++, j++){
                if(gap == 1)
                    dp[i][j] = s[i] == s[j] ? 2 : 1;
                else{
                    if(s[i] == s[j])
                        dp[i][j] = dp[i+1][j-1] + 2;
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};