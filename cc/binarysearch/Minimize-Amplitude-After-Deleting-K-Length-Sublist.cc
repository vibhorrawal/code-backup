// O(N) time and space
int solve(vector<int>& a, int k) {
    if(k == 0){
        return *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
    }
    const int n = a.size();
    vector<int> left_max(n), right_max(n), left_min(n), right_min(n);
    left_min[0] = left_max[0] = a[0];
    right_max.back() = right_min.back() = a.back();

    for(int i = 1; i < n; i++){
        left_min[i] = min(left_min[i-1], a[i]);
        left_max[i] = max(left_max[i-1], a[i]);
    }

    for(int i = n-2; i >= 0; i--){
        right_min[i] = min(right_min[i+1], a[i]);
        right_max[i] = max(right_max[i+1], a[i]);
    }

    int ans = INT_MAX;
    for(int i = 0; i <= n - k; i++){
        int mx = max(i ? left_max[i-1] : 0, i+k < n ? right_max[i+k] : 0);
        int mn = min(i ? left_min[i-1] : INT_MAX, i+k < n ? right_min[i+k] : INT_MAX);
        ans = min(ans, mx - mn);
    }
    return ans;
}
