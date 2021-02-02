// O(NlogN) time | O(1) space
int solve(vector<int>& nums, int target) {
    int ans = INT_MIN;
    int l = 0, r = nums.size()-1;
    sort(nums.begin(), nums.end());
    while(l < r){
        if(nums[l] + nums[r] < target){
            ans = max(ans, nums[l] + nums[r]);
            l++;
        }
        else{
            r--;
        }
    }
    return ans;
}
