// O(N^2 * logN) time | O(1) space
bool solve(vector<int>& nums) {
    for(int &x : nums) x = x*x;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            int c = nums[i] + nums[j];
            if(binary_search(nums.begin(), nums.end(), c))
                return true;
        }
    }
    return false;
}

// O(N ^ 2) time
bool solve(vector<int>& nums) {
    for(int &x : nums) x = x*x;

    sort(nums.rbegin(), nums.rend());
    for(int i = 0; i < nums.size(); i++){
        int target = nums[i];
        int l = i + 1, r = nums.size() - 1;
        while(l < r){
            int value = nums[l] + nums[r];
            if(value == target) return true;
            else if(value > target) l++;
            else r--;
        }
    }
    return false;
}
