// O(NlogN) time | O(N) space
vector<int> solve(vector<vector<int>>& tasks) {
    // order is duration, id, qt
    for(int i = 0; i < tasks.size(); i++){
        int id = tasks[i][0], qt = tasks[i][1], dur = tasks[i][2];
        tasks[id][0] = dur;
        tasks[id][1] = id;
        tasks[id][2] = qt;
    }
    sort(tasks.begin(), tasks.end(), 
    [](const vector<int> &a, const vector<int> &b){
        if(a[2] == b[2]) return a[0] < b[0];
        return a[2] < b[2];
    });
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minpq;
    int curr_time = tasks[0][2];
    int i = 0;
    vector<int> res;
    while(i < tasks.size() or minpq.size()){
        if(minpq.empty()){
            curr_time = tasks[i][2];
            while(i < tasks.size() and tasks[i][2] <= curr_time){
                minpq.push(tasks[i++]);
            }
        }
        auto it = minpq.top(); minpq.pop();
        curr_time += it[0];
        res.push_back(it[1]);
        while(i < tasks.size() and tasks[i][2] <= curr_time){
                minpq.push(tasks[i++]);
        }
    }
    return res;
}