inline string next(string s){
    return s.substr(1, s.size()-1) + s[0];
}
// O(N ^ 2) time | O(1) space
bool solve(string s0, string s1) {
    if(s0.size() != s1.size())
        return false;
    if(s0 == s1)
        return true;
    for(int i = 0; i < s0.size(); i++){
        s0 = next(s0);
        // cout<<s0<<endl;
        if(s0 == s1) return true;
    }
    return false;
}

// cleaner
// O(N) space and time
bool solve(string s0, string s1) {
    if(s0.size() != s1.size())
        return false;
    string ss = s0 + s0;
    return ss.find(s1) != -1;
}
