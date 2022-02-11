// O(N) space time
vector<int> solve(vector<int>& nums) {
    stack<int> st;
    for(int i = 0; i < nums.size();){
        int x = nums[i];
        if(x >= 0 or st.empty()){
            st.push(x);
            i++;
        }
        else{
            if(st.top() == -x) {
                st.pop();
                i++;
                continue;
            }
            while(st.size() and st.top() > 0 and st.top() < -x){
                st.pop();
            }
            if(st.size() && st.top() == -x) {
                st.pop();
                i++;
                continue;
            }
            if(st.size() and st.top() > 0 and st.top() > -x){
                i++;
                continue;
            }
            st.push(x);
            i++;
        }
    }
    vector<int> res;
    while(st.size()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

// cleaner
vector<int> solve(vector<int>& nums) {
    stack<int> st;
    for(int x : nums){
        while(st.size() and 0 < st.top() and st.top() < -x) st.pop();
        if(st.size() and 0 < -x and -x < st.top()){
            continue;
        }
        if(st.size() and x < 0 and st.top() == -x){
            st.pop();
            continue;
        }
        st.push(x);
    }
    vector<int> res;
    while(st.size()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}