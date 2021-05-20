int solve(vector<int>& a) {
    unordered_set<int> s;
    for(int i = 1; i < a.size(); i++) s.insert(a[i] - a[i-1]);
    int d = INT_MAX;
    for(int i : s) d = min(abs(i), d);
    if(*s.begin() < 0) d *= -1;
    for(int i = 1; i < a.size(); i++)
        if(a[i-1] + d != a[i])
            return a[i-1] + d;
    return (a[0] + a[1]) / 2;
}
