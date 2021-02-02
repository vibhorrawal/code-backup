#include "solution.hpp"
using namespace std;

class Solution {
    public:
    vector<int> solve(vector<int>& nums, string op, int val) {
        if (op == "+") {
            for (int i = 0; i < nums.size(); i++) nums[i] += val;
            return nums;
        }
        if (op == "-") {
            for (int i = 0; i < nums.size(); i++) nums[i] -= val;
            return nums;
        }
        if (op == "*") {
            for (int i = 0; i < nums.size(); i++) nums[i] *= val;
            return nums;
        }
        if (op == "/") {
            for (int i = 0; i < nums.size(); i++) nums[i] /= val;
            return nums;
        }
        return nums;
    }
};

vector<int> solve(vector<int>& nums, string op, int val) {
    return (new Solution())->solve(nums, op, val);
}
