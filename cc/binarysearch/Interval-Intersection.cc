// O(n) time | O(1) space
#include "solution.hpp"
using namespace std;

class Solution {
    public:
    vector<int> solve(vector<vector<int>>& intervals) {
        int start = 0, end = INT_MAX;
        for (auto it : intervals) {
            start = max(it[0], start);
            end = min(it[1], end);
        }
        return {start, end};
    }
};

vector<int> solve(vector<vector<int>>& intervals) {
    return (new Solution())->solve(intervals);
}
