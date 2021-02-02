// O(n) time | O(1) space
// this is improper way to do it
int solve(vector<int>& nums, vector<int>& values) {
    int minv = INT_MAX, maxv = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
        minv = min(minv, nums[i] - values[i]);
        maxv = max(maxv, nums[i] + values[i]);
    }
    return maxv - minv;
}

// this is proper way [Greedy]
int solve(vector<int>& nums, vector<int>& values) {
    int ans = INT_MIN, maxval = INT_MIN;
    // values[i] + values[j] + nums[j] - nums[i]
    // equals
    // (values[j] + nums[j]) + (values[i] - nums[i])
    for(int i = 0; i < nums.size(); i++){
        maxval = max(maxval, values[i] - nums[i]);
        ans = max(ans, values[i] + nums[i] + maxval);
    }
    return ans;
}
