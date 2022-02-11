// O(N) space time
int solve(vector<string>& exp) {
    stack<string> st;
    for(string s : exp){
        if(s == "+"){
            long b = stol(st.top()); st.pop();
            long a = stol(st.top()); st.pop();
            st.push(to_string(a + b));
        }
        else if(s == "-"){
            long b = stol(st.top()); st.pop();
            long a = stol(st.top()); st.pop();
            st.push(to_string(a - b));
        }
        else if(s == "*"){
            long b = stol(st.top()); st.pop();
            long a = stol(st.top()); st.pop();
            st.push(to_string(a * b));
        }
        else if(s == "/"){
            long b = stol(st.top()); st.pop();
            long a = stol(st.top()); st.pop();
            st.push(to_string(a / b));
        }
        else st.push(s);
    }
    assert(st.size() == 1);
    return stoi(st.top());
}