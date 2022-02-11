// O(N^3 logN) time [O(N^2 + NlogN~sorting)]
vector<string> solve(string s) {
    const int n = s.size();
    map<string, int> mp;
    vector<string> res;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            string t = s.substr(i, j - i + 1);
            sort(t.begin(), t.end());
            mp[t]++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            string t = s.substr(i, j - i + 1);
            string tt = t;
            sort(t.begin(), t.end());
            if(mp[t] > 1) res.push_back(tt);
        }
    }
    sort(res.begin(), res.end());
    return res;
}