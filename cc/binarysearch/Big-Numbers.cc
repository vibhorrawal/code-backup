// O(NM) space and time
int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> row(n, -1), col(m, -1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int a = matrix[i][j];
            row[i] = max(row[i], a);
            col[j] = max(col[j], a);
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == row[i] && row[i] == col[j])
                count++;
        }
    }
    return count;
}
