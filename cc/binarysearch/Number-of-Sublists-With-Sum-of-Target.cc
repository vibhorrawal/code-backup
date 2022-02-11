// O(N) time and space
int solve(vector<int>& a, int target) {
    const int n = a.size();
    vector<int> pre(n + 1);
    map<int,int> seen;
    pre[0] = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    for(int i = 0; i < n + 1; i++) {
        // pre[i] - x = target => x = pre[i] - target
        int required = pre[i] - target;
        ans += seen[required];
        seen[pre[i]]++;
    }
    return ans;
}

// cleaner
int solve(vector<int>& nums, int target) {
    int n = nums.size(), ans = 0, sum = 0;
    unordered_map<int,int> seen;
    seen[0] = 1;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        int comp = sum - target;
        if(seen.count(comp))
            ans += seen[comp];
        seen[sum]++;
    }
    return ans;
}