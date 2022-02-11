// O(N) space time
int solve(string s) {
    unordered_set<char> us;
    int n = s.size();
    vector<int> left(n), right(n);
    for(int i = 1; i < s.size(); i++){
        us.insert(s[i-1]);
        left[i] = us.size();
    }
    us.clear();
    for(int i = n-2; i >= 0; i--){
        us.insert(s[i+1]);
        right[i] = us.size();
    }
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(left[i] == right[i-1]) ans++;
    }
    return ans;
}