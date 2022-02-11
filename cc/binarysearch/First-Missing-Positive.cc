// O(N) time | O(1) space
// modifying i/p
int solve(vector<int>& nums) {
    for(int &x : nums) if(x <= 0) x = nums.size() + 1;
    for(int i = 0; i < nums.size(); i++){
        int id = abs(nums[i])-1;
        if(id < 0 || id >= nums.size()) continue;
        nums[id] = -abs(nums[id]);
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0) return i+1;
    }
    return nums.size() + 1;
}

// another with O(1) space
// O(NlogN) time
int solve(vector<int>& a) {
    sort(a.begin(), a.end());
    auto it = lower_bound(a.begin(), a.end(), 0);
    for(int i = 1; i <= a.size(); i++) {
        if(!binary_search(it, a.end(), i)) return i;
    }
    return a.size() + 1;
}

// swap sort O(N) time | O(1) space
int solve(vector<int>& a) {
    // swapping to correct place
    int n = a.size();
    for(int i = 0; i < n; i++) {
        int val = a[i];
        if(val < 1 or val > n or val == a[val - 1]) continue;
        swap(a[i], a[val - 1]);
        i--;
    }
    
    for(int i = 0; i < n; i++) {
        if(a[i]-1 != i) return i + 1;
    }
    return n + 1;
}