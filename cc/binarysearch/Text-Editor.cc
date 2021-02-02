string solve(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '<'){
            if(i+1 < s.size() && s[i+1] == '-') {
                if(!st.empty())
                    st.pop();
                i++;
            }
            else st.push(s[i]);
        }
        else st.push(s[i]);
    }
    string res;
    while(st.size()){
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

// cleaner
string solve(string s) {
    string res;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '<' and i+1 < s.size() and s[i+1] == '-') {
            if(res.size()) res.pop_back();
            i++;
        }
        else res += s[i];
    }
    return res;
}
