// O(n^2) time | O(n^2) space
class Solution {
    vector<vector<bool>> isPalindrome(string s){
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        for(int i = 0; i< n; i++) dp[i][i] = true;
        
        for(int gap = 2; gap <= n; gap++){
            for(int i = 0; i <= n - gap; i++){
                int j = i + gap - 1;
                if(gap == 2)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
            }
        }
        return dp;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> palindrome = isPalindrome(s);
        vector<int> cuts(n, INT_MAX);
        cuts[0] = 0;
        for(int i = 1; i < n; i++){
            if(palindrome[0][i]){
                cuts[i] = 0;
                continue;
            }
            for(int j = 1; j <= i; j++){
                if(palindrome[j][i]){
                    cuts[i] = min(cuts[i], cuts[j-1] + 1);
                }
            }
        }
        return cuts[n-1];
    }
};
