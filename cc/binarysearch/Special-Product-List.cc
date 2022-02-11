// O(N) space time
vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> right(n);
    right[n-1] = 1;
    for(int i = n-2; i >= 0; i--)
        right[i] = right[i+1] * nums[i+1];
    
    int left = 1;
    vector<int> res(n);
    for(int i = 0; i < n; i++){
        res[i] = left * right[i];
        left *= nums[i];
    }
    return res;
}