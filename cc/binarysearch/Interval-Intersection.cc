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

// line sweep
// O(NlogN) time | O(N) space
vector<int> solve(vector<vector<int>>& intervals) {
    map<int,int> cursor;
    for(auto it : intervals) {
        cursor[it[0]]++;
        cursor[it[1]]--;
    }
    int n = intervals.size();
    int start = -1, end = -1, current = 0;
    for(auto it : cursor) {
        current += it.second;
        if(current == n and start == -1) {
            start = it.first;
        }
        if(current != n and start != -1 and end == -1) {
            end = it.first;
        }
    }
    return {start, end};
}