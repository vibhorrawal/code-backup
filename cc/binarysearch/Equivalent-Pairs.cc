// O(N) time and space
int solve(vector<int>& a) {
    int ans = 0;
    unordered_map<int,int> mp;
    for(int x : a){
        ans += mp[x]++;
    }
    return ans;
}

// alternate, using nC2
int solve(vector<int>& nums) {
    unordered_map<int,int> freq;
    for(int num : nums) freq[num]++;
    int ans = 0;
    for(auto pair : freq) {
        int c = pair.second;
        ans += c * (c - 1) / 2;
    }
    return ans;
}