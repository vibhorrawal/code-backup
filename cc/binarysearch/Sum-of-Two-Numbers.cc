// O(N) time and space
bool solve(vector<int>& nums, int k) {
    set<int> s;
    for(int n : nums){
        if(s.count(k-n))
            return true;
        s.insert(n);
    }
    return false;
}

// O(NlogN) time | O(1) space
bool solve(vector<int>& a, int k) {
    sort(a.begin(), a.end());
    int l = 0, r = a.size()-1;
    while(l < r){
        int val = a[l] + a[r];
        if(val == k) return true;
        if(val > k) r--;
        else l++;
    }
    return false;
}
