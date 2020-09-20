// O(mn) time | O(n+m) space
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row, col(m);
        for(auto vec: mat){
            row.push_back(accumulate(vec.begin(), vec.end(), 0));
        }
        for(int i = 0; i < m; i++){
            int count = 0;
            for(int j = 0; j < n ; j++)
                count += mat[j][i];
            col[i] = count;
        }
        int count = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(row[i] == 1 && col[j] == 1 && mat[i][j] == 1)
                    count++;
        return count;
    }
};
