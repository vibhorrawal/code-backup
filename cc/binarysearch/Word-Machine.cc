// O(N) time and space
int solve(vector<string>& ops) {
    stack<int> st;
    for(string s : ops){
        if(s == "POP"){
            if(st.empty()) return -1;
            st.pop();
        }
        else if(s == "DUP"){
            if(st.empty()) return -1;
            st.push(st.top());
        }
        else if(s == "+"){
            if(st.size() < 2) return -1;
            int top = st.top(); st.pop();
            int sec = st.top(); st.pop();
            st.push(top+sec);
        }
        else if(s == "-"){
            if(st.size() < 2) return -1;
            int top = st.top(); st.pop();
            int sec = st.top(); st.pop();
            st.push(top-sec);
        }
        else{
            int n = stoi(s);
            if(n < 0) return -1;
            st.push(n);
        }
    }
    return st.empty() ? -1 : st.top();
}
