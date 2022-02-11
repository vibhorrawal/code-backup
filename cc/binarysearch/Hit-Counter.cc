// O(N) time and space
class HitCounter {
    deque<int> dq;
    public:
    HitCounter() {
        dq.clear();
    }
// O(1) time
    void add(int timestamp) {
        dq.push_back(timestamp);
    }

// O(N) time
    int count(int timestamp) {
        while(dq.size() and dq.front() < timestamp - 60)
            dq.pop_front();
        return dq.size();
    }
};