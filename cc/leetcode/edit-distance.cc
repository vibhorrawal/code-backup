class Solution {
    string s1;
    string s2;
    
    int util(int i, int j){
        if(!i && !j)
            return 0;
        if(i == 0)
            return j;
        if(j == 0)
            return i;
        
        if(s1[i-1] == s2[j-1])
            return util(i-1,j-1);
        else 
            return 1 + min({util(i, j-1), util(i-1, j), util(i-1,j-1)});
        
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1],dp[i-1][j-1]});
            }
        }
        return dp[n][m];
    }
};