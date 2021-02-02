// using stack
// O(m) space and O(mn) time
class Solution {
    int MAH(vector<int> v){
        stack<int> st;
        int n = v.size();
        vector<int> left(n), right(n);
        for(int i = 0; i < n; i++){
            while(st.size() and v[st.top()] >= v[i]) st.pop();
            left[i] = st.size() ? st.top() : -1;
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(st.size() and v[st.top()] >= v[i]) st.pop();
            right[i] = st.size() ? st.top() : n;
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int area = v[i] * (right[i] - left[i] - 1);
            ans = max(ans, area);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& a) {
        if(a.empty()) return 0;
        vector<int> v(a[0].size());
        for(int j = 0; j < a[0].size(); j++) v[j] = a[0][j] - '0';
        int ans = MAH(v);
        for(int i = 1; i < a.size(); i++){
            for(int j = 0; j < a[0].size(); j++){
                if(a[i][j] == '0') v[j] = 0;
                else v[j]++;
            }
            ans = max(ans, MAH(v));
        }
        return ans;
    }
};
