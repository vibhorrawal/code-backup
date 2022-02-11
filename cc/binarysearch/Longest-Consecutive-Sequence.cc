// O(NlogN) time | O(N) space
int solve(vector<int>& a) {
    unordered_set<int> s (a.begin(), a.end());
    sort(a.begin(), a.end());
    int ans = 0;
    for(int x : a){
        int l = 0;
        while(s.count(x)){
            s.erase(x);
            l++;
            x++;
        }
        ans = max(ans, l);
    }
    return ans;
}

// without space, same as above
// O(NlogN) time | O(1) space
int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = 0, i = 0, n = nums.size();
    while(i < n) {
        int cnt = 1;
        while(i + 1 < n and ((nums[i] + 1 == nums[i+1]) or nums[i] == nums[i+1])) {
            cnt += (nums[i] != nums[i+1]);
            i++;
        }
        ans = max(ans, cnt);
        if(cnt == 1) i++;
    }
    return ans;
}

// O(N) space time
int solve(vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end());
    int ans = 0;
    for(int x : a) {
        if(!s.count(x - 1)) {
            // this is the first element
            int y = x;
            while(s.count(y)) y++;
            ans = max(ans, y - x);
        }
    }
    return ans;
}