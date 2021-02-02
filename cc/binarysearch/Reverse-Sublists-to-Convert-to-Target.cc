// O(NlogN) time | O(1) space
bool solve(vector<int>& nums, vector<int>& target) {
    sort(nums.begin(), nums.end());
    sort(target.begin(), target.end());
    if(nums.size() != target.size()) return false;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != target[i])
            return false;
    }
    return true;
}

// O(n) time and space
bool solve(vector<int>& nums, vector<int>& target) {
    unordered_map<int,int> freq;
    for(int x : nums) freq[x]++;
    for(int x : target) freq[x]--;
    for(auto [i,c] : freq) if(c) return false;
    return true;
}
