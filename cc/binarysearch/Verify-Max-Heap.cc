// O(N) time | O(1) space 
bool solve(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(i*2 + 1 < n && nums[i] < nums[2*i+1]) return false;
        if(2*i+2 < n && nums[i] < nums[2*i+2]) return false;
    }
    return true;
}
