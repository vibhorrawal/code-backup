// O(n * logn) time and space | max n times we need to insert which is O(logn)
int solve(vector<int>& cells) {
    multiset<int, greater<int>> s;
    for(int i : cells) s.insert(i);
    while(s.size() > 1){
        int a = *s.begin(); s.erase(s.find(a));
        int b = *s.begin(); s.erase(s.find(b));
        if(a == b) continue;
        s.insert((a+b)/3);
    }
    return s.size() ? *s.begin() : -1;
}

// using standard priority queue
// O(NlogN) time | O(N) space
int solve(vector<int>& cells) {
    priority_queue<int> pq;
    for(int cell : cells) pq.push(cell);
    while(pq.size()) {
        if(pq.size() == 1) return pq.top();
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        if(a == b) continue;
        pq.push((a+b)/3);
    }
    return -1;
}

// same as above, but saves by instantiating the heap with values with O(N)
// ref: https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/
int solve(vector<int>& cells) {
    priority_queue<int> pq (cells.begin(), cells.end());
    while(pq.size()) {
        if(pq.size() == 1) return pq.top();
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        if(a == b) continue;
        pq.push((a+b)/3);
    }
    return -1;
}