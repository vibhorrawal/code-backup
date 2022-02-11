// O(N) time and space
int solve(vector<int>& nums, vector<vector<int>>& queries) {
    if(nums.size() == 0 or queries.size() == 0) return 0;
    vector<int> d;
    for(int i = 1; i <= nums.size(); i++) {
        d.push_back(nums[i] - nums[i-1]);
    }
    vector<int> diff_d(d.size(), -1);
    diff_d.back() = d.size()-1;
    for(int i = d.size() - 2; i >= 0; i--) {
        diff_d[i] = d[i+1] == d[i] ? diff_d[i+1] : i;
    }
    int ans = 0;
    for(auto query : queries) {
        int start = query[0], end = query[1];
        int start_ptr = diff_d[start], end_ptr = diff_d[end-1];
        if(start_ptr == end_ptr) {
            ans++;
        } 
        else if(start == end) {
            ans++;
        }
    }
    return ans;
}