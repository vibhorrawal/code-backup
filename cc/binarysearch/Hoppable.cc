// O(N) time | O(1) space
bool solve(vector<int>& nums) {
    int n = nums.size();
    int left_most_good_idx = n-1;
    for(int i = n-1; i >= 0; i--){
        if(nums[i] + i >= left_most_good_idx)
            left_most_good_idx = i;
    }
    return left_most_good_idx == 0;
}

// easier to understand
bool solve(vector<int>& nums) {
    int steps = nums[0], i = 1;
    while(i < nums.size() and steps > 0){
        steps--;
        if(nums[i] > steps) steps = nums[i];
        i++;
    }
    return i >= nums.size();
}

// same thing
bool solve(vector<int>& a) {
    if(a.size() < 2) return true;
    int curr = a[0];
    for(int i = 0; i < a.size(); i++) {
        if(curr == 0) return false;
        curr--;
        curr = max(curr, a[i]);
    }
    return true;
}

// shorter same approach as 1
bool solve(vector<int>& a) {
    int reach = 0;
    for(int i = 0; i < a.size(); i++) {
        if(i > reach) return false;
        reach = max(reach, i + a[i]);
    }
    return true;
}