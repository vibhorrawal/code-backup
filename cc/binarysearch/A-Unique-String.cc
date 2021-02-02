// O(nlogn) time | O(1) space
bool solve(string s) {
    sort(s.begin(), s.end());
    for(int i = 1; i < s.size(); i++) if(s[i] == s[i-1]) return false;
    return true;
}

// O(n) time | O(n) space
bool solve(string s) {
    unordered_set<char> us(s.begin(), s.end());
    return s.size() == us.size();
}
