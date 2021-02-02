// O(N) time | O(1) space
int solve(vector<int>& a) {
    int l = 1, n = a.size();
    if(n == 0) return 0;
    while(l < n and a[l-1] <= a[l]) l++;
    if(l == n) return 0;
    int r = n-1;
    while(r > 0 and a[r-1] <= a[r]) r--;
    cout<<l<<' '<<r;
    int mine = *min_element(a.begin() + l, a.begin() + r + 1);
    l = 0;
    while(a[l] <= mine) l++;

    int maxe = *max_element(a.begin() + l, a.begin() + r + 1);
    r = n-1;
    while(maxe <= a[r]) r--;
    return abs(r - l) + 1;
}

// cleaner
int solve(vector<int>& a) {
    if(a.empty()) return 0;
    int l = 0, r = a.size()-1;
    while(l+1 < a.size() and a[l] <= a[l+1]) l++;
    if(l == a.size()-1) return 0;
    while(r-1 >= l and a[r-1] <= a[r]) r--;
    int min_ele = *min_element(a.begin() + l, a.begin() + r + 1);
    int max_ele = *max_element(a.begin() + l, a.begin() + r + 1);
    l = 0, r = a.size()-1;
    while(a[l] <= min_ele) l++;
    while(max_ele <= a[r]) r--;
    return r - l + 1;
}
