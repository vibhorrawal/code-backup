// O(NlogN) time | O(1) space
#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<int>& nums) {
        vector<int> sorted(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == sorted[i]) count++;
        return count;
    }
};

int solve(vector<int>& nums) {
    return (new Solution())->solve(nums);
}
