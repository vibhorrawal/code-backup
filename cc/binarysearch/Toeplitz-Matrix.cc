// O(MN) time | O(1) space
bool solve(vector<vector<int>>& matrix) {
    for(int i = 1; i < matrix.size(); i++){
        for(int j = 1; j < matrix[0].size(); j++){
            if(matrix[i][j] != matrix[i-1][j-1])
                return false;
        }
    }
    return true;
}
