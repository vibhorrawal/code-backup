// O(nlogn) time | O(n) space
int solve(vector<vector<int>>& a) {
    vector<pair<int,int>> e;
    const int OPEN = 0, CLOSE = 1;
    for(auto it : a){
        e.push_back({it[0], OPEN});
        e.push_back({it[1], CLOSE});
    }
    sort(e.begin(), e.end());
    int max_active = 0, active = 0;
    for(auto [x,cmd] : e){
        active += (cmd == OPEN ? 1 : -1);
        max_active = max(active, max_active);
    }
    active = 0;
    for(auto [x,cmd] : e){
        active += (cmd == OPEN ? 1 : -1);
        if(active == max_active)
            return x;
    }
    return -1;
}

// using ordered map, same complexity
int solve(vector<vector<int>>& a) {
    map<int,int> t;
    for(auto it : a){
        t[it[0]] += 1;
        t[it[1]+1] -= 1;
    }
    int ans = 0, freq = 0, curr = 0;
    for(auto [i,c] : t){
        curr += c;
        if(freq < curr){
            ans = i;
            freq = curr;
        }
    }
    return ans;
}
