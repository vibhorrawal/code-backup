// O(N) space and time
int solve(vector<int>& nums) {
    set<int> s;
    for(int x : nums) s.insert(x);
    int mx = INT_MIN;
    for(int x : nums){
        if(s.count(-x)) mx = max(x,mx);
    }
    return mx == INT_MIN ? -1 : mx;
}

// O(nlogn) time | O(1) space
int solve(vector<int>& a) {
    sort(a.begin(), a.end());
    int index = upper_bound(a.begin(), a.end(), 0) - a.begin();
    for(int i = 0; i < index; i++){
        if(binary_search(a.begin() + index, a.end(), -a[i]))
            return -a[i];
    }
    if(binary_search(a.begin(), a.end(), 0)) return 0;
    return -1;
}
