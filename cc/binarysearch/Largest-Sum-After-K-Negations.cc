// O(nlogn) time | O(1) space
int solve(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0) break;
        if(k == 0) break;
        if(nums[i] == 0){
            k = 0;
            break;
        }
        k--;
        nums[i] = - nums[i];
    }
    sort(nums.begin(), nums.end());
    if(k && nums.size()){
        nums[0] *= pow(-1, k); // or (-1) * (k % 2 == 1)
    }
    return accumulate(nums.begin(), nums.end(), 0);
}
