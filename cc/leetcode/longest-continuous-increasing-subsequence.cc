class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int maxLength = 1, length = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1])
                length++;
            else
                length = 1;
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};
