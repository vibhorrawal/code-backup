// O(N) time and space
int solve(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> maxsale(nums.size());
    maxsale[nums.size()-1] = nums.back();
    for(int i = nums.size()-2; i >= 0; i--){
        maxsale[i] = max(maxsale[i+1], nums[i]);
    }
    int profit = 0;
    for(int i = 0; i < nums.size(); i++){
        profit += max(0, maxsale[i] - nums[i]);
    }
    return profit;
}

// O(N) time | O(1) space
int solve(vector<int>& a) {
    if(a.empty()) return 0;
    int profit = 0, maxsell = a.back();
    for(int i = a.size()-2; i >= 0; i--){
        profit += max(0, maxsell - a[i]);
        maxsell = max(maxsell, a[i]);
    }
    return profit;
}
