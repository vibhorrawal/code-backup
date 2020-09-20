class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s){
            switch(c){
                case '(':
                    st.push(c);
                    break;
                case ')':
                    if(st.empty() || st.top() != '(') return false;
                    st.pop();
                    break;
                case '{':
                    st.push(c);
                    break;
                case '}':
                    if(st.empty() || st.top() != '{') return false;
                    st.pop();
                    break;
                case '[':
                    st.push(c);
                    break;
                case ']':
                    if(st.empty() || st.top() != '[') return false;
                    st.pop();
                    break;
            };

        }
        return st.empty();
    }
};
