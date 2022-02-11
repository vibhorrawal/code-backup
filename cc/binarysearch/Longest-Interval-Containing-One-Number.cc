// O(nlogn) time | O(1) space
int solve(vector<int>& nums) {
    nums.push_back(0);
    nums.push_back(100'001);
    sort(nums.begin(), nums.end());
    int ans = 0;
    for(int i = 0; i < nums.size() - 2; i++){
        ans = max(ans, nums[i+2] - nums[i] - 1);
    }
    return ans;
}

// if input is immutable
// lol i read this again, and i am sorting an immutable input; not cool
int solve(vector<int>& a) {
    if(a.size() == 1) return 1e5;

    int ans = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++){
        if(i == 0){
            int a1 = 1 < a.size() ? a[1] : 1e5;
            ans = max(ans, a1-1);
        }
        else if(i == a.size()-1){
            int as = a.size() - 2 >= 0 ? a[a.size()-2] : 0;
            ans = max(ans, (int) 1e5 - as);
        }
        else {
            ans = max(ans, a[i+1]-1 - a[i-1]);
        }
    }
    return ans;
}
