// O(n) time
string solve(string s) {
    stringstream ss(s);
    string res, t;
    while(getline(ss, t, ' ')){
        if(t == "and") continue;
        res += toupper(t[0]);
    }
    return res;
}
