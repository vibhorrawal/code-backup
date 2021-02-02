// O(N * logN) time | O(N) space
vector<vector<int>> solve(vector<vector<int>>& fractions) {
    set<pair<int,int>> s;
    for(int i = 0; i < fractions.size(); i++){
        int n = fractions[i][0], d = fractions[i][1];
        int x = __gcd(abs(n), abs(d));
        s.insert({n / x, d / x});
    }
    vector<vector<int>> res;
    for(auto it : s){
        res.push_back({it.first, it.second});
    }
    sort(res.begin(), res.end(), [](const vector<int> &a, const vector<int> &b){
        return a[0] * b[1] < b[0] * a[1];
    });
    return res;
}

// with own hash function
hash<int> hs;
class MyHash {
    public:
    size_t operator()(const pair<int,int> &p) const
    {
        return hs(p.first) + hs(p.second);
    }
};
vector<vector<int>> solve(vector<vector<int>>& fractions) {
    unordered_set<pair<int,int>, MyHash> s;
    for(int i = 0; i < fractions.size(); i++){
        int n = fractions[i][0], d = fractions[i][1];
        int x = __gcd(abs(n), abs(d));
        s.insert({n / x, d / x});
    }
    vector<vector<int>> res;
    for(auto it : s){
        res.push_back({it.first, it.second});
    }
    sort(res.begin(), res.end(), [](const vector<int> &a, const vector<int> &b){
        return a[0] * b[1] < b[0] * a[1];
    });
    return res;
}
