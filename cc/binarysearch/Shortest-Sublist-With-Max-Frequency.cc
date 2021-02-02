int solve(vector<int>& nums) {
    map<int,int> freq;
    for(int x : nums) freq[x]++;
    int mf = 0;
    for(auto it : freq) mf = max(it.second, mf);
    map<int,int> lastId;
    for(int i = 0; i < nums.size(); i++)
        lastId[nums[i]] = i;
    int minlen = INT_MAX;
    for(int i = 0; i < nums.size(); i++){
        if(freq[nums[i]] == mf){
            minlen = min(lastId[nums[i]] - i + 1, minlen);
            lastId[nums[i]] = INT_MAX;
        }
    }
    return minlen;
}

// alternate
bool possible(unordered_map<int,int> &mp, int k){
    for(auto [i,c] : mp) if(c >= k) return true;
    return false;
}
int solve(vector<int>& a) {
    int l = 0, r = 0, ans = INT_MAX, k = 0;
    unordered_map<int,int> freq, f;
    for(int x : a) f[x]++;
    for(auto [i,c] : f) k = max(k, c);
    while(r < a.size()) {
        freq[a[r++]]++;
        while(r < a.size() and not possible(freq, k)) {
            freq[a[r++]]++;
        }
        while(l < r and possible(freq, k)){
            freq[a[l++]]--;
        }
        ans = min(ans, r - l + 1);
    }
    return ans;
}

// more elegant
int solve(vector<int>& a) {
    unordered_map<int,int> leftmost, rightmost, freq;
    for(int i = 0; i < a.size(); i++){
        freq[a[i]]++;
        rightmost[a[i]] = i;
        if(not leftmost.count(a[i])) leftmost[a[i]] = i;
    }
    int max_freq = 0, ans = INT_MAX;
    for(auto [i,c] : freq) max_freq = max(c, max_freq);
    for(int x : a) {
        if(freq[x] == max_freq){
            ans = min(ans, rightmost[x] - leftmost[x] + 1);
        }
    }
    return ans;
}
