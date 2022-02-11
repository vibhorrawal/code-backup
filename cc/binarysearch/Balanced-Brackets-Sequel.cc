// O(N) space time
bool solve(string s) {
    stack<char> st;
    for(char c : s){
        if(c == '(' || c == '{' || c == '[') st.push(c);
        else{
            if(st.empty())
                return false;
            if(
            (c == ')' and st.top() != '(') ||
            (c == '}' and st.top() != '{') ||
            (c == ']' and st.top() != '['))
                return false;
            st.pop();
        }
    }
    return st.empty();
}