// O(N) time | O(N) space
int solve(vector<int>& nums, int k) {
    vector<int> vis(nums.size());
    int count = 0;
    while(0 <= k && k < nums.size()){
        if(vis[k]) return -1;
        vis[k] = true;
        count++;
        k = nums[k];
    }
    return count;
}
