// O(NM) time | O(1) space
vector<vector<int>> solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    return matrix;
}

// O(MN) time and space
vector<vector<int>> solve(vector<vector<int>>& b) {
    if(b.empty() or b[0].empty()) return b;
    vector<vector<int>> a(b[0].size(), vector<int> (b.size()));
    for(int i = 0; i < b.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            a[j][i] = b[i][j];
        }
    }
    return a;
}
