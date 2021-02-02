// O(N^2) time | O(1) space
int solve(vector<vector<int>>& matrix) {
    int res = 0, n = matrix.size();
    if(n == 0) return 0;
    for(int i = 0; i < matrix[0].size(); i++)
        res += matrix[0][i] + matrix[n-1][i];
    for(int i = 0, j = n-1; i < n; i++,j--)
        res += matrix[i][j];
    res -= matrix[0][n-1];
    res -= matrix[n-1][0];
    return res;
}


// elegant
int solve(vector<vector<int>>& a) {
    int ans = 0, n = a.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 or i == n-1 or i + j == n-1)
                ans += a[i][j];
        }
    }
    return ans;
}
