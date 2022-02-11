// O(NlogN) time | O(N) space
int solve(vector<string>& shows, vector<int>& durations, int k) {
    map<string,int> dur;
    for(int i = 0; i < shows.size(); i++){
        dur[shows[i]] += durations[i];
    }
    vector<int> v;
    for(auto it : dur) v.push_back(it.second);
    sort(v.rbegin(), v.rend());
    return accumulate(v.begin(), v.begin() + min(k, (int) v.size()), 0);
}

// O(KLogN) time | O(N) space
int solve(vector<string>& s, vector<int>& d, int k) {
    unordered_map<string,int> mp;
    for(int i = 0; i < s.size(); i++)
        mp[s[i]] += d[i];
    priority_queue<int> pq;
    for(auto [ss,dd] : mp) pq.push(dd);
    int ans = 0;
    while(k--) {
        ans += pq.top();
        pq.pop();
    }
    return ans;
}