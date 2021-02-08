// O(nlogn) time | O(1) space
int solve(vector<int>& nums, int k) {
    k = nums.size() - k;
    sort(nums.begin(), nums.end());
    int amp = INT_MAX;
    for(int i = k-1; i < nums.size(); i++){
        amp = min(nums[i] - nums[i-k+1], amp);
    }
    return amp;
}
