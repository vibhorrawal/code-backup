// O(NlogN) time | O(N) space
int solve(vector<vector<int>>& intervals) {
    map<int,int> mp;
    for(auto i : intervals){
        mp[i[0]] += 1;
        mp[i[1]] -= 1;
    }
    int count = 0;
    int ans = 0;
    for(auto [i,c] : mp){
        count += c;
        ans = max(ans, count);
    }
    return ans;
}