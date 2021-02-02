// O(nlogn) time | O(n) space
vector<int> solve(vector<int>& nums) {
    vector<pair<int,int>> v;
    for(int i = 0; i < nums.size(); i++)
        v.push_back({nums[i],i});
    sort(v.rbegin(), v.rend());
    int rank = -1, prev = 0;
    vector<int> res(v.size());
    for(int i = 0; i < v.size(); i++){
        if(i && v[prev].first == v[i].first){
            int id = v[i].second;
            res[id] = rank;
        }
        else{
            rank++;
            int id = v[i].second;
            res[id] = rank;
            prev = i;
        }
    }
    return res;
}


// another method
vector<int> solve(vector<int>& a) {
    vector<int> v(a);
    sort(v.rbegin(), v.rend());
    unordered_map<int,int> rank;
    int r = 0;
    for(int i = 0; i < v.size(); i++){
        if(rank.count(v[i])) continue;
        rank[v[i]] = r++;
    }
    vector<int> res;
    for(int i = 0; i < a.size(); i++){
        res.push_back(rank[a[i]]);
    }
    return res;
}
