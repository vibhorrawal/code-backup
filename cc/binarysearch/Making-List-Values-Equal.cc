// O(n) time | O(1) space
#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        return mx - mn;
    }
};

int solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}
