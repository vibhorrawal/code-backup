// O(N + UlogU) time | O(N) space
vector<int> solve(vector<vector<int>>& r) {
    unordered_map<int, unordered_set<int>> follower;
    vector<int> users;
    for(auto i : r){
        int u = i[0], v = i[1];
        if(follower[v].count(u)){
            users.push_back(u);
            users.push_back(v);
        }
        follower[u].insert(v);
    }
    sort(users.begin(), users.end());
    users.resize(unique(users.begin(), users.end()) - users.begin());
    return users;
}
