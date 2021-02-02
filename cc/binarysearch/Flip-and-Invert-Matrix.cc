// O(mn) time
vector<vector<int>> solve(vector<vector<int>>& a) {
    for(int r = 0; r < a.size(); r++){
        vector<int> b(a[0].size());
        for(int c = 0, j = a[0].size()-1; j >= 0; c++, j--)
            b[j] = !a[r][c];
        for(int c = 0, j = a[0].size()-1; j >= 0; c++, j--)
            a[r][c] = b[c];
    }
    return a;
}
