vector<string> solve(string s, int n) {
    vector<string> res;
    for(int i = 0; i < s.size(); i+= n){
        string t(s.begin() + i, s.begin() + min(i + n, (int) s.size()));
        res.push_back(t);
    }
    return res;
}

vector<string> solve(string s, int n) {
    vector<string> res;
    for(int i = 0; i < s.size(); i += n) res.push_back(s.substr(i, n));
    return res;
}
