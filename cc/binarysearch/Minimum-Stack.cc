class MinimumStack {
    stack<int> st;
    public:
    int minEle;
    MinimumStack() {

    }

    void append(int val) {
        if(st.empty()){
            minEle = val;
        }
        if(val < minEle){
            st.push(2 * val - minEle);
            minEle = val;
        }
        else st.push(val);
    }

    int peek() {
        return st.top() > minEle ? st.top() : minEle;
    }

    int min() {
        return minEle;
    }

    int pop() {
        int x = st.top();
        if(x < minEle){
            int temp = minEle;
            minEle = 2 * minEle - x;
            x = temp;
        }
        st.pop();
        return x;
    }
};
