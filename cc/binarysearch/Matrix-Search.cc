// O((NM) * Log(NM)) space time 
int solve(vector<vector<int>>& a, int n) {
    vector<int> v;
    for(auto it : a)
        for(int x : it) v.push_back(x);
    sort(v.begin(), v.end());
    return v[n];
}