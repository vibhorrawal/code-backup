// O(N) space time
vector<int> solve(vector<int>& nums) {
    vector<int> dp(nums.size());
    int curr = 0;
    int balls = 0; 
    for(int i = 0; i < nums.size(); i++){
        dp[i] = curr;
        if(nums[i]) balls++;
        curr += balls;
    }
    balls = curr = 0;
    for(int i = nums.size()-1; i>= 0; i--){
        dp[i] += curr;
        if(nums[i]) balls++;
        curr += balls;
    }
    return dp;
}