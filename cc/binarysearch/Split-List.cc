// O(N) time and space
bool solve(vector<int>& nums) {
    vector<int> rightmx(nums.size()); // rightmx is confusing; i mean right_minimum
    rightmx[nums.size()-1] = nums.back();
    for(int i = nums.size()-2; i >= 0; i--)
        rightmx[i] = min(rightmx[i+1], nums[i]);
    int maxn = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(maxn < rightmx[i]) return true;
        maxn = max(maxn, nums[i]);
    }
    return false;
}
