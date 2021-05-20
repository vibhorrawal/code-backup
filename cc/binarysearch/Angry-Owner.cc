// O(N) time and space
int solve(vector<int>& c, vector<int>& m, int k) {
    const int n = c.size();
    if(n == 0) return 0;
    vector<int> pre(n), mc(n);
    pre[0] = c[0];
    for(int i = 1; i < n; i++)
        pre[i] = pre[i-1] + c[i];

    mc[0] = m[0] * c[0];
    for(int i = 1; i < n; i++)
        mc[i] = mc[i-1] + m[i] * c[i];

    if(k == 0) return mc.back();
    if(k == n) return pre.back();

    int ans = pre[k-1] + mc.back() - mc[k-1];
    cout<<ans<<endl;
    for(int i = k; i < n; i++){
        int t = mc[i-k] + pre[i] - pre[i-k] + (mc[n-1] - mc[i]);
        ans = max(t, ans);
    }
    return ans;
}

// O(N) time | O(1) space
int solve(vector<int>& c, vector<int>& m, int k) {
    const int n = c.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(m[i]){
            sum += c[i];
            c[i] = 0;
        }
    }
    int sub = 0, maxsub = 0;
    for(int i = 0; i < n; i++){
        sub += c[i];
        if(i >= k) sub -= c[i-k];
        maxsub = max(maxsub, sub);
    }
    return sum + maxsub;
}

// alternate solution
int solve(vector<int>& c, vector<int>& m, int k) {
    int ans = 0, n = c.size();
    for(int i = 0; i < n; i++) ans += m[i] * c[i];
    int max_ans = 0;
    for(int i = 0; i < k; i++){
        if(m[i] == 0) ans += c[i];
        max_ans = max(ans, max_ans);
    }
    for(int i = k; i < n; i++){
        if(m[i-k] == 0) ans -= c[i-k];
        if(m[i] == 0) ans += c[i];
        max_ans = max(ans, max_ans);
    }
    return max_ans;
}
