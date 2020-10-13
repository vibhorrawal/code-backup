// O(n) time | O(1) space
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), x = 0;
        for(int i = 1; i <= n; i++)
            x = x ^ i;
        for(int num : nums)
            x = x ^ num;
        return x;
    }
};
