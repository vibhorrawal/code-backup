// O(N) time | O(N) space
// caching`
vector<vector<int>> v = {{1, 2}, {7, 7}, {30,25}};
unordered_map<int,int> mp;

int solve(vector<int> &a, int pos) {
    if(mp[pos]) return mp[pos];
    if(pos >= a.size()) return 0;
    int curr = a[pos];
    int cost = INT_MAX;
    for(int vi = 0; vi < 3; vi++) {
        int i = pos;
        int costv = v[vi][1], days = v[vi][0];
        while(i < a.size() and a[i] <= curr + days - 1) i++;
        cost = min(cost, costv + solve(a, i));
    }
    return mp[pos] = cost;
}

int solve(vector<int>& days) {
    mp.clear();
    return solve(days, 0);
}