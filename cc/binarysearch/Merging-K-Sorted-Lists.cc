// O(NMLog(NM)) space time
vector<int> solve(vector<vector<int>>& lists) {
    vector<int> res;
    for (auto v : lists)
        for (int i : v) res.push_back(i);

    sort(res.begin(), res.end());
    return res;
}

// total elem: N * M
// O(NM * LogM) time 
#define pi pair<int, int>
vector<int> solve(vector<vector<int>>& lists) {
    vector<int> res;
    priority_queue<pi, vector<pi>, greater<pi>> minpq;
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i].size()) minpq.push({lists[i][0], i});
    }
    vector<int> ptr(lists.size(), 1);
    while (minpq.size()) {
        auto it = minpq.top();
        minpq.pop();
        res.push_back(it.first);
        int idx = it.second;
        if (ptr[idx] < lists[idx].size()) {
            minpq.push({lists[idx][ptr[idx]], idx});
            ptr[idx]++;
        }
    }
    return res;
}