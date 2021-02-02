// O(n) time | O(1) space
vector<int> solve(vector<int>& nums) {
    reverse(nums.begin(), nums.end());
    nums[0]++;
    int i = 0, c = 0;
    while(nums[i] > 9){
        c = nums[i] / 10;
        nums[i] %= 10;
        i++;
        if(i == nums.size()) break;
        nums[i] += c;
        c--;
    }
    if(c) nums.push_back(1);
    reverse(nums.begin(), nums.end());
    return nums;
}
