// O(n) time | O(1) space
vector<int> solve(vector<int>& nums) {
    int i = 0, j = 0;
    for(i = 0; i < nums.size(); i++){
        if(nums[i])
            nums[j++] = nums[i];
    }

    for(i = j; i < nums.size(); i++)
        nums[i] = 0;

    return nums;
}
