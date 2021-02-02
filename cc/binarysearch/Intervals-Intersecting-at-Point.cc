// O(n) time | O(1) space
#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<vector<int>>& intervals, int point) {
        int count = 0;
        for (auto it : intervals) {
            if (it[0] <= point && point <= it[1]) count++;
        }
        return count;
    }
};

int solve(vector<vector<int>>& intervals, int point) {
    return (new Solution())->solve(intervals, point);
}
