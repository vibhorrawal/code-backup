// greedy
// O(NlogN) time | O(1) space
int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), mx = INT_MIN;
    for(int i = 0; i < n; i++)
        mx = max(mx, nums[i] + (n - i));
    int ans = 0;
    for(int x : nums) if(x + n >= mx) ans++;
    return ans;
}
