// O(N) time | O(1) space
bool solve(vector<int>& nums, int k) {
    long long sum = accumulate(nums.begin(), nums.end(), 0ll);
    long long req = k * (nums.size() - 1);
    for(int i : nums){
        if(sum - i == req) return true;
    }
    return false;
}
