// O(N) time and space
bool solve(string s) {
    string r;
    for(char c : s) if(islower(c)) r += c;
    for(int i = 0; i < r.size(); i++) if(r[i]!=r[r.size()-i-1]) return false;
    return true;
}

// O(N) time | O(1) space
// two pointer approach
bool solve(string s) {
    int l = 0, r = s.size()-1;
    while(l <= r) {
        while(l < r and !islower(s[l])) l++;
        while(r > l and !islower(s[r])) r--;
        if(s[l] != s[r]) return false;
        l++,r--;
    }
    return true;
}