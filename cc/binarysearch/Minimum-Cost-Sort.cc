// O(nlogn) time | O(n) space
int cost(vector<int> &a, vector<int> &b){
    int c = 0;
    for(int i = 0; i < a.size(); i++) c += abs(a[i] - b[i]);
    return c;
}
int solve(vector<int>& nums) {
    vector<int> t(nums.begin(), nums.end());
    sort(t.begin(), t.end());
    int asc = cost(nums, t);
    reverse(t.begin(), t.end());
    int des = cost(nums, t);
    return min(asc, des);
}
