class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int> res, temp(a.begin(), a.end());
        for(int i = 0; i < n; i++) temp.push_back(a[i]);
        stack<int> st;
        for(int i = temp.size()-1 ; i >= 0; i--){
            int x = temp[i];
            while(st.size() and st.top() <= x) st.pop();
            res.push_back( (st.empty() ? -1 : st.top()) );
            st.push(x);
        }
        // for(int i : temp) cout<<i<<' ';cout<<endl;
        reverse(res.begin(), res.end());

        // for(int i : res) cout<<i<<' ';cout<<endl;
        res.resize(n);
        return res;
    }
};

// O(n) time and space
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int> res(n);
        stack<int> st;
        for(int i = 2 * n - 1; i >= 0; i--){
            while(st.size() and a[st.top() % n] <= a[i % n]) st.pop();
            res[i % n] = st.empty() ? -1 : a[st.top() % n];
            st.push(i);
        }
        return res;
    }
};
