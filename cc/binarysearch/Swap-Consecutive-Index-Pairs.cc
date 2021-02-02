// O(N) time | O(1) space
vector<int> solve(vector<int>& nums) {
    int e = 0, o = 1;
    while(e+2 < nums.size()){
        swap(nums[e], nums[e+2]);
        e += 4;
    }
    while(o+2 < nums.size()){
        swap(nums[o], nums[o+2]);
        o += 4;
    }
    return nums;
}
