#include "solution.hpp"
using namespace std;

class Solution {
    public:
    vector<int> solve(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
        return nums;
    }
};

vector<int> solve(vector<int>& nums, int k) {
    return (new Solution())->solve(nums, k);
}
