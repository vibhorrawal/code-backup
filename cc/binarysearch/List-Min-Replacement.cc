// O(n) time | O(1) space
vector<int> solve(vector<int>& nums) {
    if(nums.empty()) return nums;
    int minv = nums[0];
    for(int i = 1; i < nums.size(); i++){
        int val = nums[i];
        nums[i] = minv;
        minv = min(val, minv);
    }
    nums[0] = 0;
    return nums;
}
