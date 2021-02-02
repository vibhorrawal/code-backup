vector<vector<int>> solve(vector<vector<int>>& a) {
    int dir = 1;
    int t = 0;
    sort(a.begin(), a.end());
    vector<vector<int>> res;
    for(int i = 0; i < a.size(); i++){
        if(a[i][0] > t){
            t = a[i][0];
            dir = 1;
        }
        int end = i;
        while(end+1 < a.size() && a[end][0] == a[end+1][0]){
            end++;
        }
        int temp = dir;
        for(int s = i; s <= end; s++){
            if(a[s][1] == temp){
                dir = temp;
                res.push_back({t++, dir});
            }
        }
        temp = !temp;
        for(int s = i; s <= end; s++){
            if(a[s][1] == temp){
                dir = temp;
                res.push_back({t++, dir});
            }
        }
        i = max(i, end);
    }
    // res.pop_back();
    return res;
}

// cleaner
vector<vector<int>> solve(vector<vector<int>>& requests) {
    map<pair<int,int>, int> events;
    for(auto it : requests){
        int time = it[0], direction = it[1];
        events[{time, direction}]++;
    }
    int t = 0, dir = 1;
    vector<vector<int>> res;
    sort(requests.begin(), requests.end());
    for(int i = 0; i < requests.size(); ){
        int time = requests[i][0];
        if(time > t){
            dir = 1;
            t = time;
        }
        int x = events[{time, dir}];
        int y = events[{time, dir ^ 1}];

        for(int j = 0; j < x; j++)
            res.push_back({t++, dir});

        for(int j = 0; j < y; j++)
            res.push_back({t++, dir ^ 1});

        i += x + y;
        if(y) dir = dir ^ 1;
    }
    return res;
}
