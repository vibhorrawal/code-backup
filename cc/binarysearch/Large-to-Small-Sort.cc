// O(nlogn) time and O(n) space
vector<int> solve(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());
    vector<int> res;
    int i = 0, j = nums.size()-1;
    while(i<j){
        res.push_back(nums[i++]);
        res.push_back(nums[j--]);
    }
    if(res.size() != nums.size()) res.push_back(nums[i++]);
    return res;
}
1
