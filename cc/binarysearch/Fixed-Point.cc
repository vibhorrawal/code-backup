// O(logn) time | O(1) space
int solve(vector<int>& nums) {
    int l = 0, r = nums.size()-1, ans = -1;
    while(l <= r){
        int m = (l+r)/2;
        // if(nums[m] == m) return m;
        if(nums[m] >= m){
            r = m - 1;
            if(nums[m] == m) ans = m;
        }
        else {
            l = m + 1;
        }

    }
    return ans;
}
