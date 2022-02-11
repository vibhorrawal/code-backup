// O(nlogn) time | O(1) space
bool solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int d = nums[1] - nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] - nums[i-1] != d)
            return false;
    }
    return true;
}

// O(N) time and space
bool solve(vector<int>& nums) {
    int min = *min_element(nums.begin(), nums.end());
    int max = *max_element(nums.begin(), nums.end());
    int d = (max - min) / (nums.size() - 1);
    set<int> exist(nums.begin(), nums.end());
    if(d == 0) return exist.size() == 1;
    for(int num = min; num <= max; num += d) {
        if(!exist.count(num)) return false;
    }
    return true;
}