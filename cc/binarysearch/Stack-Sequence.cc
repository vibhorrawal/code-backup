// O(N) space time
bool solve(vector<int>& pushes, vector<int>& pops) {
    stack<int> st;
    int j = 0;
    for(int i = 0; i < pushes.size(); i++){
        st.push(pushes[i]);
        while(st.size() && st.top() == pops[j]){
            st.pop();
            j++;
        }
    }
    return st.empty();
}