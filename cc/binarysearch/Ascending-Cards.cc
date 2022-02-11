// O(NlogN) time | O(N) space
vector<int> solve(vector<int>& cards) {
    const int n = cards.size();
    sort(cards.begin(), cards.end());
    deque<int> dq;
    for(int i = 0; i < n; i++) dq.push_back(i);
    vector<int> pos(n);
    int i = 0;
    while(dq.size()){
        // simulating
        int popped_index = dq.front(); dq.pop_front(); // O(N/2 + N/4 + N/8.... = 2N = N)
        pos[popped_index] = cards[i++];
        if(dq.size()) {
            int front = dq.front(); dq.pop_front();
            dq.push_back(front);
        }
    }
    return pos;
}