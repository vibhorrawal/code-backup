// O(N) time | O(1) space
int solve(vector<int>& nums, int k, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int diff = abs(target - sum);
    return ceil(1.0 * diff / k);
}