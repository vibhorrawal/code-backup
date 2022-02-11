#include "solution.hpp"
using namespace std;

// O(n) space and time
class Solution {
    public:
    string solve(string s) {
        stack<char> st;
        for (char c : s) {
            if (st.empty() || st.top() != c) st.push(c);
        }
        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

string solve(string s) {
    return (new Solution())->solve(s);
}

// O(N) time | O(1) space, excluding returned string
string solve(string s) {
    char prev = -1;
    string res;
    for(char c : s){
        if(c == prev) continue;
        res.push_back(c);
        prev = c;
    }
    return res;
}