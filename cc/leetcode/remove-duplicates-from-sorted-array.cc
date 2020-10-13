// O(n) time | O(1) space
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return {};
        int i = 0, j = 0;
        while(j < nums.size()){
            if(nums[i] != nums[j])
                nums[++i] = nums[j];
            j++;
        }
        return i+1;
    }
};
