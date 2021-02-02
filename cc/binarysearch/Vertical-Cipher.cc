// O(|S|) time and space
vector<string> solve(string s, int n) {
    vector<string> res(n);
    int i = 0;
    while(i < s.size()){
        for(int j = 0; j < n; j++) {
            if(i == s.size()) break;
            res[j] += s[i++];
        }
    }
    return res;
}

// cleaner
vector<string> solve(string s, int n) {
    vector<string> res(n);
    for(int i = 0; i < s.size(); i++)
        res[i % n] += s[i];
    return res;
}
