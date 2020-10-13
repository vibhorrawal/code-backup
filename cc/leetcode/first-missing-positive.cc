// O(n) time | O(1) space 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0)
                nums[i] = INT_MAX;
        }
        for(int i = 0; i < nums.size(); i++){
            if(abs(nums[i]) - 1 < nums.size())
                nums[abs(nums[i])-1] = - abs(nums[abs(nums[i]) -1]);
        }
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0)
                return i+1;
        return nums.size()+1;
    }
};
