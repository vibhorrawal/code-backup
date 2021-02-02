// O(s + d) time | O(d) space
bool solve(string d, string s) {
    map<char,int> mp;
    for(int i = 0; i < d.size(); i++){
        mp[d[i]] = i+1;
    }
    int max_usable = 0;
    for(char c : s){
        if(!mp.count(c)) continue;
        if(mp[c] < max_usable) return false;
        max_usable = max(max_usable, mp[c]);
    }
    return true;
}

// O(s + d) time | O(d) space
bool solve(string d, string s) {
    int i = 0;
    set<char> sd (d.begin(), d.end());
    for(int j = 0; j < s.size(); j++){
        if(not sd.count(s[j]) or d[i] == s[j]) continue;
        while(i < d.size() and d[i] != s[j]) i++;
        if(i == d.size()) return false;
    }
    return true;
}
