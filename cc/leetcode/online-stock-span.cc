// O(n) time and space
class StockSpanner {
public:
    stack<int> st;
    vector<int> v;
    int i;
    StockSpanner() {
        // st.clear();
        while(st.size()) st.pop();
        v = vector<int> (1e4);
        i = -1;
    }

    int next(int price) {
        v[++i] = price;
        while(st.size() and v[st.top()] <= v[i]) st.pop();
        // cout<<i<<' '<<(st.size() ? st.top() : -1)<<endl;
        int ans = st.size() ? i - st.top() : i + 1;
        st.push(i);
        return ans;
    }
};
