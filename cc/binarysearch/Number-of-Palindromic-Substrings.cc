// O(N^2) space time
int solve(string s) {
    int count = 0, n = s.size();
    for(int i = 0; i < n; i++){
        int l = i, r = i + 1; // expand palindromes of even size
        while(l >= 0 && r < n && s[l] == s[r]) {
            l--; r++;
            count++;
        }
        l = i-1, r = i + 1; // expand palindromes of odd size
        while(l >= 0 && r < n && s[l] == s[r]) {
            l--; r++;
            count++;
        }
        count++;
    }
    return count;
}

// alternate
int solve(string s) {
    int n = s.size();
    bool dp[n][n];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            dp[i][j] = false;
            
    for(int i = 0; i < n; i++) 
        dp[i][i] = true;
        
    for(int gap = 1; gap < n; gap++){
        for(int i = 0, j = gap + i; j < n; i++,j++){
            if(gap == 1) dp[i][j] = s[i] == s[j];
            else if(dp[i+1][j-1] && s[i] == s[j]) 
                dp[i][j] = true;
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) 
        count += dp[i][j];
    return count;
}