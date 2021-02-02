// O(N) time and space
string solve(string s) {
    if(s == "") return "";
    reverse(s.begin(), s.end());
    string res, t;
    stringstream ss(s);
    while(getline(ss, t, ' ')){
        reverse(t.begin(), t.end());
        res += t + ' ';
    }
    res.pop_back();
    return res;
}

// alternate
string solve(string s) {
    reverse(s.begin(), s.end());
    int l = 0;
    for(int r = 0; r < s.size(); r++){
        if(s[r] == ' '){
            reverse(s.begin() + l, s.begin() + r);
            l = r+1;
        }
    }
    reverse(s.begin() + l, s.end());
    return s;
}

// alternate
string solve(string s) {
    stack<string> st;
    stringstream ss(s);
    string res;
    while(getline(ss, s, ' ')){
        st.push(s);
    }
    while(st.size()){
        res += st.top();
        st.pop();
        if(st.size()) res += " ";
    }
    return res;
}
