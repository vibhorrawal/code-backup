bool solve(vector<int>& nums, int k) {
    int l = 0, r = nums.size()-1;
    while(l < r){
        if(nums[l] + nums[r] == k)
            return true;
        if(nums[l] + nums[r] > k)
            r--;
        else
            l++;
    }
    return false;
}
