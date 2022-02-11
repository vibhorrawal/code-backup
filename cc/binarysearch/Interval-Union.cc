// O(NlogN) time | O(1) space
vector<vector<int>> solve(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        if(res.back()[1] >= intervals[i][0]){
            res.back()[1] = max(intervals[i][1], res.back()[1]);
        }
        else{
            res.push_back(intervals[i]);
        }
    }
    return res;
}

// same complexity
// line sweep
vector<vector<int>> solve(vector<vector<int>>& intervals) {
    vector<pair<int,int>> events;
    // can't use else [0,3], [3,5] are separate, START should come before
    // const int START = 1, END = -1; 
    const int START = 0, END = 1;
    for(auto it : intervals) {
        events.push_back({it[0], START});
        events.push_back({it[1], END});
    }
    int curr = 0, prev = -1;
    sort(events.begin(), events.end());
    vector<vector<int>> res;
    for(auto [time, type] : events) {
        if(curr == 0) prev = time;

        type == START ? curr++ : curr--;

        if(curr == 0 and type == END) {
            res.push_back({prev, time});
        }
    }
    return res;
}