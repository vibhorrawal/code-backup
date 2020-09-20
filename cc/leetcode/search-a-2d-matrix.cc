// O(logm + logn) time | O(1) space
class Solution {
    int binsearchRow(vector<vector<int>>& matrix, int target){
        if(matrix[0].size() == 0)
            return -1;
        int l = 0, r = matrix.size()-1;
        int ans = -1;
        while(l <= r){
            int m = (l+r)/2;
            if(matrix[m][0] == target)
                return m;
            else if(matrix[m][0] < target){
                ans = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        return ans;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        
        int row = binsearchRow(matrix, target);

        if(row < 0)
            return false;
        int l = 0, r = matrix[0].size()-1;
        while(l <= r){
            int m = (l+r)/2;
            if(matrix[row][m] == target)
                return true;
            
            if(matrix[row][m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return false;
    }
};
