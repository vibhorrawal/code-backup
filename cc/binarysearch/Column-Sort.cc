// O(M * logM * N) time and O(M * N) space
vector<vector<int>> solve(vector<vector<int>>& matrix) {
    vector<vector<int>> cols(matrix[0].size());
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cols[j].push_back(matrix[i][j]);
        }
    }
    for(auto &v : cols) sort(v.begin(), v.end());
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            matrix[i][j] = cols[j][i];
        }
    }
    return matrix;
}
