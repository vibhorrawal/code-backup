// O(2^MN) time and space <-- this is very loosely bound, ATM unable to think of a definitive tighter bound
int ans;
vector<vector<int>> a;

void dfs(int r, int c){
    if(r < 0 || r >= a.size() || c < 0 || c >= a[0].size())
        return;
    if(a[r][c] == 1)
        return;
    if(r == a.size()-1 and c == a[0].size()-1){
        ans++;
        return;
    }
    dfs(r+1,c);
    dfs(r,c+1);
}
int solve(vector<vector<int>>& matrix) {
    ans = 0;
    a = matrix;
    if(a.front().front() == 1 or a.back().back() == 1) return 0;
    dfs(0,0);
    return ans;
}

// O(N^2) time | O(N) space
int solve(vector<vector<int>>& a) {
    vector<int> dp(a[0].size());
    dp[0] = 1;
    for(int r = 0; r < a.size(); r++){
        for(int c = 0; c < a[0].size(); c++){
            if(a[r][c]) dp[c] = 0;
            else if(c) dp[c] += dp[c-1];
        }
    }
    return dp.back();
}
