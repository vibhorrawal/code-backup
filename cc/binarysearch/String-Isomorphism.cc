// O(N) time and space
bool solve(string s, string t) {
    if(s.size() != t.size()) return false;
    map<char,char> st, ts;
    for(int i = 0; i < s.size(); i++){
        if(st.count(s[i]) || ts.count(t[i])){
            if(st[s[i]] != t[i] || ts[t[i]] != s[i])
                return false;
        }
        else{
            st[s[i]] = t[i];
            ts[t[i]] = s[i];
        }
    }
    return true;
}
