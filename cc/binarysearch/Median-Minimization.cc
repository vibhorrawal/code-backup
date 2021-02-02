int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n/2] - nums[n/2-1];
}
