// O(N) time and space
unordered_map<int,int> mp;

int solve(string &s, int pos) {
    if(pos > s.size()) return 0;
    if(pos == s.size()) return 1;
    if(mp[pos]) return mp[pos];

    if(s[pos] > '2') 
        return mp[pos] = solve(s, pos + 1);

    if(s[pos] == '2' and pos < s.size()-1 and s[pos+1] > '6') 
        return mp[pos] = solve(s, pos + 1);

    if(s[pos] == '0') 
        return mp[pos] = 0;
        
    return mp[pos] = solve(s, pos + 1) + solve(s, pos + 2);
}
int solve(string s) {
    mp.clear();
    return solve(s, 0);
}