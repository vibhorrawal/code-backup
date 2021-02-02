// O(mn) time | O(m + n) space
int solve(vector<vector<int>>& a) {
    vector<int> r(a.size()), c(a[0].size());
    int total = 0;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            total += a[i][j];
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }
    int ans = 0;
    int n = a.size(), m = a[0].size();
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[0].size(); j++){
            int p = total - r[i] + (n - r[i]);
            p = p - c[j] + (m - c[j]);
            if(a[i][j]) p += 2;
            else p -= 2;
            ans = max(p, ans);
        }
    }
    return ans;
}
