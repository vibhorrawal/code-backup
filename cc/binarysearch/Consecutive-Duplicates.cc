// O(N) space time
string solve(string s) {
    string res;
    for(char c : s){
        if(res.empty() or res.back() != c) res += c;
    }
    return res;
}

// one liner; technically 2
string solve(string s) {
    s.erase(unique(s.begin(), s.end()), s.end());
    return s;
}