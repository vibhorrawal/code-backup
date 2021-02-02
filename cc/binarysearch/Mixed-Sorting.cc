// O(nlogn) time | O(n) space
vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    vector<bool> iseven(n);
    vector<int> even, odd;
    for(int i = 0; i < n; i++){
        if(nums[i] & 1){
            iseven[i] = false;
            odd.push_back(nums[i]);
        }
        else{
            iseven[i] = true;
            even.push_back(nums[i]);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.rbegin(), odd.rend());
    int e = 0, o = 0;
    for(int i = 0; i < n; i++){
        if(iseven[i]) nums[i] = even[e++];
        else nums[i] = odd[o++];
    }
    return nums;
}
