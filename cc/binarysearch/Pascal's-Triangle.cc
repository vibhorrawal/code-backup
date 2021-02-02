long ncr(int r, int n){
    if(r == 0 || r == n) return 1;
    long long ans = 1;
    for(int i = 0; i < min(r,n-r); i++) {
        ans *= (n-i);
        ans /= i+1;
        // cout<<i<<' '<<ans<<endl;
    }
    // for(int i = 1; i <= r; i++) {
    //     ans /= i;
    //     cout<<i<<' '<<ans<<endl;
    // }
    return ans;
}
vector<int> solve(int n) {
    // cout<<ncr(15,20); return {};
    vector<int> res;
    for(int i = 0; i <= n; i++){
        // cout<<i<<' '<<ncr(i,n)<<endl;
        res.push_back(ncr(i,n));
    }
    return res;
}

// another cleaner implementation
vector<int> solve(int n) {
    vector<int> v = {1};
    for(int i = 1; i <= n; i++){
        vector<int> t = {1};
        for(int j = 1; j < v.size(); j++) t.push_back(v[j-1] + v[j]);
        t.push_back(1);
        v = t;
    }
    return v;
}


// even cleaner
vector<int> solve(int n) {
    vector<int> v = {1};
    while(n--){
        for(int i = v.size()-1; i > 0; i--) v[i] += v[i-1];
        v.push_back(1);
    }
    return v;
}

// lmao even smaller
// binom(n, i) = binom(n, i - 1) * (n - i + 1) / i
vector<int> solve(int n) {
    vector<int> v = {1};
    for(int i = 1; i <= n; i++)
        v.push_back(v.back() * (n - i + 1) / i);
    return v;
}
