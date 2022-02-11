// O(N) time and space
bool solve(vector<int>& nums) {
    set<int> s;
    for(int n : nums){
        if(s.count(n*3) || (n % 3 == 0 && s.count(n/3)))
            return true;
        s.insert(n);
    }
    return false;
}

// same
bool solve(vector<int>& nums) {
    set<char> exists(nums.begin(), nums.end());
    int zero_count = 0;
    for(int num : nums) {
        if(num == 0) {
            zero_count++;
            if(zero_count > 1) return true;
        } else if(exists.count(num * 3)) {
            return true;
        }
    }
    return false;
}