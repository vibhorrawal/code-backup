// O(nlogn) time | O(1) space
bool solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int d = nums[1] - nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] - nums[i-1] != d)
            return false;
    }
    return true;
}
