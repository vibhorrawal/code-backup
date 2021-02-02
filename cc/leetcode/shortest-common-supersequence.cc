// O(mn) time and space
class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int> (m+1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(a[i-1]  == b[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        string res;
        int i = n, j = m;
        while(i and j){
            if(a[i-1] == b[j-1]){
                res += a[i-1];
                i--,j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    res += a[i-1];
                    i--;
                }
                else{
                    res += b[j-1];
                    j--;
                }
            }
        }
        while(i){
            res += a[i-1];
            i--;
        }
        while(j){
            res += b[j-1];
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
