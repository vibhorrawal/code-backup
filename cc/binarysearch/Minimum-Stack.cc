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

// or simply, push/pop pair
class MinimumStack {
    stack<pair<int,int>> st;
    public:
    MinimumStack() {
        st = stack<pair<int,int>>();
    }

    void append(int val) {
        if(st.size()) {
            st.push({val, std::min(val, st.top().second)});
        } else{
            st.push({val, val});
        }
    }

    int peek() {
        return st.top().first;
    }

    int min() {
        return st.top().second;
    }

    int pop() {
        int val = st.top().first;
        st.pop();
        return val;
    }
};