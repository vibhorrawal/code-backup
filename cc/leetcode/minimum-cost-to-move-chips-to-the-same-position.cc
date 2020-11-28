// O(n) time | O(1) space
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int countOdd = 0, countEven = 0;
        for(int x : position)
            if(x & 1) countOdd++;
            else countEven++;
        return min(countOdd, countEven);
    }
};
