// O(n + m) space and time
string solve(string s0, string s1) {
    string res;
    while(s0.size() && s1.size()){
        res += s0[0];
        s0.erase(0,1);
        res += s1[0];
        s1.erase(0,1);
    }
    res += s0 + s1;
    return res;
}
