// O(N) time | O(1) space
vector<int> solve(vector<int>& nums) {
    int prev = 0;
    while(nums[prev] & 1) prev++;
    for(int i = prev + 1; i < nums.size(); i++){
        if(nums[i] % 2 == 0){
            swap(nums[prev], nums[i]);
            i++;
            while(nums[i] & 1) i++;
            prev = i;
        }
    }
    return nums;
}

// alternate
vector<int> solve(vector<int>& a) {
    for(int i = 0, last = -1; i < a.size(); i++){
        if(a[i] % 2) continue;
        if(last >= 0) {
            swap(a[i], a[last]);
            last = -1;
        }
        else last = i;
    }
    return a;
}
