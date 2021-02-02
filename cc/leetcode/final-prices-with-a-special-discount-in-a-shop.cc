// O(n) time and space
class Solution {
public:
    vector<int> finalPrices(vector<int>& a) {
        int n = a.size();
        vector<int> res(a.begin(), a.end());
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(st.size() and a[st.top()] > a[i]) st.pop();
            res[i] -= (st.size() ? a[st.top()] : 0);
            st.push(i);
        }
        return res;
    }
};
