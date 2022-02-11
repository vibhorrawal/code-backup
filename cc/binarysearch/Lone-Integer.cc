// O(N) space time
int solve(vector<int>& nums) {
    map<int,int> freq;
    for(int i : nums) freq[i]++;
    for(int i : nums) if(freq[i] == 1) return i;
    return -1;
}

// O(1) space, but O(NlogN) time
int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    for(int i = 0; i < nums.size(); i += 3) {
        if(i + 2 < n and nums[i] == nums[i+1] and nums[i] == nums[i+2])
            continue;
        return nums[i];
    }
    return -1;
}

// bit manipulation to the rescue
// O(N) time | O(1) space
int solve(vector<int>& nums) {
    int ans = 0;
    for(int bit = 0; bit < 32; bit++) {
        int cnt = 0;
        for(auto num : nums) cnt += ((num >> bit) & 1);
        ans |= ((cnt % 3) << bit);
    }
    return ans;
}