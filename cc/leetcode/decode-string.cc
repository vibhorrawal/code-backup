// O(n) time | O(n) space
class Solution {
public:
    string decode(string &s, int &i) {
        string res;
        while(i < s.size() && s[i] != ']'){
            if(!isdigit(s[i])){
                res += s[i++];
            }
            else{
                int n = 0;
                while(isdigit(s[i])){
                    n = n * 10 + s[i] - '0';
                    i++;
                }
                i++; // [
                string t = decode(s, i);
                i++; // ]
                while(n-- > 0) res += t;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};

// O(n) time | O(n) space
class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(char c : s){
            if(c == ']'){
                string t;
                while(st.size()){
                    string ss = st.top(); st.pop();
                    if(ss == "[")
                        break;
                    t = ss + t;
                }
                int n = 0, d = 1;
                while(!st.empty() && isdigit(st.top()[0])){
                    n = n + d * stoi(st.top());
                    d *= 10;
                    st.pop();
                }
                string top;
                while(n -- > 0) top += t;
                st.push(top);
            }
            else st.push(string(1,c));
        }
        string res;
        while(st.size()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
