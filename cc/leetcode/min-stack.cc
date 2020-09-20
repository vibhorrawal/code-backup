class MinStack {
    stack<long long> st;
    long long minEle;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(st.size() == 0){
            minEle = x;
            st.push(x);
        }
        else if(x > minEle)
            st.push(x);
        else{
            st.push(2 * (long long)(x) - minEle);
            minEle = x;
        }
    }
    
    void pop() {
        if(st.size() == 0)
            return;
        long long x = st.top();
        st.pop();
        
        if(x < minEle)
            minEle = 2 * minEle - x;
    }
    
    int top() {
        if(st.empty())
            return -1;
        long long x = st.top();
        if(x < minEle)
            return minEle;
        return x;
    }
    
    int getMin() {
        if(st.size())
            return minEle;
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//
class MinStack {
    stack<int> st;
    stack<int> minst;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(st.size() == 0){
            st.push(x);
            minst.push(x);
        }
        else {
            st.push(x);
            if(x < minst.top())
                minst.push(x);
            else
                minst.push(minst.top());
        }
    }
    
    void pop() {
        if(st.size() == 0)
            return;
        st.pop();
        minst.pop();
    }
    
    int top() {
        if(st.empty())
            return -1;
        return st.top();
    }
    
    int getMin() {
        if(st.size())
            return minst.top();
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
