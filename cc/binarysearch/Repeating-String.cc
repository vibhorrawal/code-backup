// best algo: KMP
// O(N) time and space
vector<int> create(string s){
    vector<int> lps(s.size(), 0);
    lps[0] = 0;
    int len = 0, i = 1;
    while(i < s.size()){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len) len = lps[len-1];
            else i++;
        }
    }
    for(int i : lps) cout<<i<<' ';
    return lps;
}
bool solve(string s) {
    vector<int> lps = create(s);
    int len = s.size() - lps.back();
    return s.size() % len == 0 && lps.back();
}


// alternative
// O(N) time and space
bool solve(string s) {
    string t = s + s;
    t.erase(t.begin());
    t.erase(--t.end());
    return t.find(s) != string::npos;
}

// alternative
// O(N^2) time | O(N) space
string create_string(const string &s, int t){
    string res;
    while(t--){
        res += s;
    }
    return res;
}
bool solve(string s) {
    for(int n = 1; n < s.size(); n++){
        int d = s.size() / n;
        string sub = s.substr(0,n);
        if(create_string(sub, d) == s)
            return true;
    }
    return false;
}
