class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int l = 1;
        while(l < nums.size() && nums[l-1] <= nums[l]) l++;
        if(l == nums.size())
            return 0;
        int r = nums.size() -1;
        while(r > 0 && nums[r-1] <= nums[r]) r--;
        
        int leftEle = *min_element(nums.begin() + l, nums.begin() + r + 1);
        l = 0;
        while(nums[l] <= leftEle) l++;
        int rightEle = *max_element(nums.begin() + l, nums.begin() + r + 1);
        r = nums.size()-1;
        while(nums[r] >= rightEle) r--;
        
        return abs(r - l) + 1;
    }
};
