// O(N) time | O(1) space
bool solve(vector<int>& nums) {
    bool strictly_inc = true, strictly_dec = true;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] - nums[i-1] >= 0) strictly_dec = false;
        if(nums[i] - nums[i-1] <= 0) strictly_inc = false;
    }
    return strictly_inc | strictly_dec;
}
