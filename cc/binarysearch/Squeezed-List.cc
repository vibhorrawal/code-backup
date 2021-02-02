// O(N) space and time
vector<vector<int>> solve(vector<int>& nums) {
    deque<int> dq;
    for(int i : nums) dq.push_back(i);
    vector<vector<int>> res;
    while(!dq.empty()){
        vector<int> t;
        for(int i : dq){
            t.push_back(i);
        }
        res.push_back(t);
        if(dq.size() == 1) break;
        int f = dq.front(); dq.pop_front();
        f += dq.front(); dq.pop_front();
        dq.push_front(f);

        int b = dq.back(); dq.pop_back();
        b += dq.back(); dq.pop_back();
        dq.push_back(b);
    }
    vector<int> t = res.back();
    if(t.size() > 1) res.push_back({t[0] + t[1]});
    return res;
}

// alternate to deque
vector<vector<int>> solve(vector<int>& a) {
    vector<vector<int>> res;
    res.push_back(a);
    while(true){
        if(res.back().size() <= 3){
            res.push_back({accumulate(res.back().begin(), res.back().end(), 0)});
            return res;
        }
        vector<int> t;
        for(int i = 1; i < res.back().size()-1; i++){
            if(i == 1) t.push_back(res.back()[i] + res.back()[i-1]);
            else if(i == res.back().size()-2) t.push_back(res.back()[i] + res.back()[i+1]);
            else t.push_back(res.back()[i]);
        }
        res.push_back(t);
    }
    return {{}};
}
