// O(n^2) time | O(n^2) space
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
            return {};
        vector<vector<int>> res = {{1}};
        for(int i = 1; i < numRows; i++){
            vector<int> row;
            row.push_back(1);
            for(int j = 0; j < res[i-1].size() - 1; j++)
                row.push_back(res[i-1][j] + res[i-1][j+1]);
            row.push_back(1);
            res.push_back(row);
        }
      return res;
    }
};
