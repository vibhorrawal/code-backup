// O(NlogN) time | O(N) space
int size(const vector<int> &a){
    return a[1] - a[0] + 1;
}
int solve(vector<vector<int>>& a) {
    if(a.size() < 2) return 0;
    sort(a.begin(), a.end());
    if(a.size() == 2){
        int i = 0;
        if(a[i][0] <= a[i+1][0] && a[i+1][0] <= a[i][1]) return 0;
        return size(a[0]) + size(a[1]);
    }
    vector<int> right_min_sz(a.size());
    int n = a.size();
    right_min_sz[n-1] = size(a.back());
    for(int i = n - 2; i >= 0; i--)
        right_min_sz[i] = min(right_min_sz[i+1], size(a[i]));

    // right_min_sz[n-1] = 1e9;
    // for(int i : right_min_sz) cout<<i<<' ';
    cout<<endl;
    int min_size = INT_MAX, i = 0;
    while(i<n){
        int id = i;
        int ans = n, l = i+1, r = n-1;
        while(l <= r){
            int m = (l+r)/2;
            if(not(a[id][0] <= a[m][0] && a[m][0] <= a[id][1])){
                r = m - 1;
                ans = min(m, ans);
                // cout<<ans<<' ';
            }
            else l = m + 1;
        }
        if(id == n-1) break;
        if(ans != n)
            min_size = min(size(a[id]) + right_min_sz[ans], min_size);
        i = id + 1;
    }
    return min_size > 1e9 ? 0 : min_size;
}

// cleaner same solution (SORT -> BS)
int size_(const vector<int> &a){
    return a[1] - a[0] + 1;
}

inline bool intersect(const vector<int> &a, const vector<int> &b) {
    return (a[0] <= b[0] and b[0] <= a[1]) or (b[0] <= a[0] and a[0] <= b[1]);
}

int upper_bound(vector<vector<int>>& a, int i){
    int l = i, r = a.size()-1;
    int ans = r + 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(intersect(a[i], a[m])){
            l = m + 1;
        }
        else{
            r = m - 1;
            ans = m;
        }
    }
    return ans;
}
int solve(vector<vector<int>>& a) {
    sort(a.begin(), a.end());
    int ans = 1e9;
    vector<int> right_min(a.size());
    right_min.back() = size_(a.back());
    for(int i = a.size()-2; i >= 0; i--)
        right_min[i] = min(right_min[i+1] , size_(a[i]));
    for(int i = 0, j = 0; i < a.size(); i++){
        int id = upper_bound(a, i);
        if(id < a.size())
            ans = min(ans, right_min[id] + size_(a[i]));
    }
    return ans == 1e9 ? 0 : ans;
}
