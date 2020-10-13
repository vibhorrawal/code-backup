// O(1) space and time
class RecentCounter {
    deque<int> dq;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int old = t - 3000;
        dq.push_back(t);
        while(dq.front() < old) dq.pop_front();
        return dq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
