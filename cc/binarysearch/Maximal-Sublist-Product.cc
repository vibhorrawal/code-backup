// O(N) time | O(1) space
// 3 possibilities +ve, 0, -ve => max, current, min
int solve(vector<int>& nums) {
    int lo = 1, hi = 1;
    int ans = INT_MIN;
    for(int x : nums){
        int lo_ = min({x, lo * x, hi * x});
        int hi_ = max({x, lo * x, hi * x});
        lo = lo_;
        hi = hi_;
        ans = max(ans,hi);
    }
    return ans;
}