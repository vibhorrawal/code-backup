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



// TLE
// MCM
// O(N^3) time 
class Solution {
    map<pair<int,int>, int> memo;
    vector<vector<bool>> isPalin;
    int solve(const string &s, int i, int j){
        if(i >= j)
            return 0;
        if(memo.count({i,j}))
            return memo[{i,j}];

        if(isPalin[i][j])
            return 0;
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            int t = solve(s, i, k) + solve(s, k + 1, j) + 1;
            ans = min(ans, t);
        }
        return memo[{i,j}] = ans;
    }

    vector<vector<bool>> palindrome(const string &s){
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n));
        for(int i = 0; i < n; i++) dp[i][i] = true;
        for(int gap = 1; gap < n; gap++){
            for(int i = 0, j = i + gap; j < n; j++,i++){
                if(i + 1 == j)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = (s[i] == s[j]) and dp[i+1][j-1];
            }
        }
        return dp;
    }
public:
    int minCut(string s) {
        memo.clear();
        isPalin = palindrome(s);
        return solve(s, 0, s.size()-1);
    }
};
