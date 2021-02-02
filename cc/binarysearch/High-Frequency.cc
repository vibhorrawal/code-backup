// O(n) time and space
#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<int>& nums) {
        map<int, int> freq;
        for (int i : nums) freq[i]++;
        int mx = 0;
        for (auto it : freq) mx = max(mx, it.second);
        return mx;
    }
};

int solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}
