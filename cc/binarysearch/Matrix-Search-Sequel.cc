// O(M + N) time | O(1) space
bool solve(vector<vector<int>>& matrix, int target) {
    int i = matrix.size() - 1, j = 0;
    while (i >= 0 && j < matrix[0].size()) {
        if (matrix[i][j] == target) return true;
        if (matrix[i][j] < target)
            j++;
        else
            i--;
    }
    return false;
}

// O(NlogM) time 
bool solve(vector<vector<int>>& a, int target) {
    for(auto &row : a) {
        if(binary_search(row.begin(), row.end(), target)) 
            return true;
    }
    return false;
}