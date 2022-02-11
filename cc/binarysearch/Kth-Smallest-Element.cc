// O(N) time | O(1) space
// using library function
int solve(vector<int>& nums, int k) {
    nth_element(nums.begin(), nums.begin() + k, nums.end());
    return nums[k];
}

