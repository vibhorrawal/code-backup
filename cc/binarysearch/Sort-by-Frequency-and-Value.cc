// O(NlogN) time | O(N) space
vector<int> solve(vector<int>& a) {
    map<int,int> mp;
    for(int x : a) mp[x]++;
    vector<pair<int,int>> t;
    for(auto [i,c] : mp) t.push_back({c,i});
    sort(t.rbegin(), t.rend());
    vector<int> res;
    for(auto it : t){
        for(int i = 0; i < it.first; i++) res.push_back(it.second);
    }
    return res;
}

// using comparator function
vector<int> solve(vector<int>& a) {
    unordered_map<int,int> freq;
    for(int x : a) freq[x]++;
    sort(a.begin(), a.end(), [&](int a, int b){
        if(freq[a] == freq[b])
            return a > b;
        return freq[a] > freq[b];
    });
    return a;
}