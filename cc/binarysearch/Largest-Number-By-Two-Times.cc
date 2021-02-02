// O(n) time | O(1) space
bool solve(vector<int>& nums) {
    int max1 = 0, max2 = 0;
    for(int x : nums){
        if(x >= max1){
            max2 = max1;
            max1 = x;
        }
        else if(x > max2) max2 = x;
    }
    return max1 > max2 * 2;
}

// O(nlogn) time | O(1) space
bool solve(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());
    return nums[0] > 2 * nums[1];
}
