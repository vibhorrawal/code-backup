// O(nlogn) time | O(1) space
int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int val = nums[0];
    int cost = 0;
    for(int x : nums) cost += abs(x - val);
    return cost;
}
// doing the opposite of what is asked, decrease max ele by 1
// O(n) time | O(1) space
int solve(vector<int>& a) {
    int cost = 0;
    int val = *min_element(a.begin(), a.end());
    for(int x : a) cost += x - val;
    return cost;
}
