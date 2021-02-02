#include "solution.hpp"
using namespace std;
// O(n) time 
class Solution {
    public:
    int solve(vector<int>& nums) {
        int odd = 0;
        for (int i : nums)
            if (i % 2) odd++;
        if (odd % 2)
            return -1;
        else
            return odd / 2;
    }
};

int solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}
