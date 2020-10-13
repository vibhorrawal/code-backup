// O(n^2)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> newRow = {1};
        for(int i = 0; i < rowIndex; i++){
            vector<int> prevRow =  newRow;
            newRow.clear();
            newRow.push_back(1);
            for(int j = 0; j < prevRow.size()-1; j++)
                newRow.push_back(prevRow[j] + prevRow[j+1]);
            newRow.push_back(1);
        }
        return newRow;
    }
};
