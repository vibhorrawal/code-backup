// O(N) time | O(1) space
int solve(vector<int>& nums, int k) {
    int idx = -1;
    long sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        if(sum <= k) idx = i;
    }
    return idx;
}
