// O(N) space time
int solve(vector<int>& a) {
    if(a.size() < 1) return 0;
    
    vector<int> dp(a.size() + 1);
    dp[1] = max(0, a[0]);
    for(int i = 2; i <= a.size(); i++) {
        dp[i] = max(dp[i-1], dp[i-2] + a[i - 1]);
    }
    return dp.back();
}

// O(N) time | O(1) space
int solve(vector<int>& nums) {
    int with = 0, without = 0;
    for(int x : nums){
        int temp = without;
        without = max(without, with);
        with = max(with, temp + x);
    }
    return max(with, without);
}

// another way
int solve(vector<int>& nums) {
    int odd = 0, even = 0;
    for(int i = 0; i < nums.size(); i++){
        if(i & 1){
            odd = max(odd + nums[i], even);
        }
        else{
            even = max(even + nums[i], odd);
        }
    }
    return max(odd, even);
}