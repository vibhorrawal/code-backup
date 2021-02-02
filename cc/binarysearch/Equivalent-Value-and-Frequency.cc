#include "solution.hpp"
using namespace std;

// O(n) space and time
class Solution {
    public:
    bool solve(vector<int>& nums) {
        map<int, int> freq;
        for (int i : nums) freq[i]++;
        for (auto it : freq)
            if (it.first == it.second) return true;
        return false;
    }
};

bool solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}
