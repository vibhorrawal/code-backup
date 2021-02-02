// O(nlogn) time | O(1) space
int solve(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());
    int n = nums.size();
    return max(nums[0] * nums[1], nums[n-1] * nums[n-2]);
}


// O(n) time | O(1) space
int solve(vector<int>& a) {
    int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for(int x : a){
        if(x > max1){
            max2 = max1;
            max1 = x;
        }
        else if(x > max2){
            max2 = x;
        }

        if(x < min1){
            min2 = min1;
            min1 = x;
        }
        else if(x < min2){
            min2 = x;
        }
    }
    return max(max1 * max2, min1 * min2);
}
