// O(MN) time | O(1) space
int dx[8] = {-1,1,-1,1,2,2,-2,-2};
int dy[8] = {-2,-2,2,2,1,-1,1,-1};
bool solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == 0) continue;
            for(int k = 0; k < 8; k++){
                int ii = i + dx[k];
                int jj = j + dy[k];
                if(ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                if(matrix[ii][jj]) return true;
            }
        }
    }
    return false;
}
