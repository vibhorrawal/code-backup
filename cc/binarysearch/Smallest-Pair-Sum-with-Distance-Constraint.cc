int solve(vector<int>& nums) {
    int minv = nums[0], sum = INT_MAX;
    for(int i = 2; i < nums.size(); i++){
        sum = min(sum, nums[i] + minv);
        minv = min(minv, nums[i-1]);
    }
    return sum;
}
