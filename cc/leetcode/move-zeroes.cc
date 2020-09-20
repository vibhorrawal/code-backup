class Solution {
    void move(vector<int> &nums, int ele){
        int i = 0, j = nums.size()-1;
        while(i < j){
            while(i < j && nums[i] != ele) i++;
            while(i < j && nums[j] == ele) j--;
            swap(nums[i],nums[j]);
        }
    }
public:
    void moveZeroes(vector<int>& nums) {
        // move(nums, 0);
        // return;
        int i = 0, j = 0;
        for(i;i < nums.size(); i++){
            if(nums[i] != 0)
                nums[j++] = nums[i];
        }
        for(;j< nums.size(); j++)
            nums[j] = 0;
    }
};
