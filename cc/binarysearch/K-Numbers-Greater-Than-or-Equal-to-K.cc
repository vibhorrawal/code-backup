// O(N) space and time
int solve(vector<int>& nums) {
    map<int,int> freq;
    for(int x : nums) freq[x]++;
    long total = 0;
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());
    for(int i = mx; i >= mn; i--){
        total += freq[i];
        if(i == total) return i;
    }
    return -1;
}

// elegant
int solve(vector<int>& nums) {
    int n = nums.size(), k = 0;
    vector<int> bucket(n + 1);
    for(int x : nums) if(x < n) bucket[x]++; else bucket[n]++;
    for(int i = n; i >= 0; i--){
        k += bucket[i];
        if(i == k) return i;
    }
    return -1;
}
