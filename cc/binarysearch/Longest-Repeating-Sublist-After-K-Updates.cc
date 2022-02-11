// O(NlogN) time | O(N) space
bool possible(int m, int k, vector<int> &a){
    unordered_map<int,int> cnt;
    for(int i = 0; i < m; i++) cnt[a[i]]++;
    for(auto [val,c] : cnt) if(c + k >= m) return true;
    for(int i = m; i < a.size(); i++) {
        cnt[a[i-m]]--;
        if(++cnt[a[i]] + k >= m) return true;;
    }
    return false;
}

int solve(vector<int>& nums, int k) {
    const int n = nums.size();
    int l = 0, r = n, ans = 0;
    while(l <= r) {
        int m = l + (r-l)/2;
        if(possible(m, k, nums)) {
            l = m + 1;
            ans = m;
        } else {
            r = m - 1;
        }
    }
    return ans;
}