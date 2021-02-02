// O(N^2) time and space
int solve(vector<string>& words) {
    set<string> s;
    int ans = 0;
    for(string t : words){
        if(s.count(t)) continue;
        ans++;
        for(int i = 0; i < t.size(); i++){
            string y = t.substr(i) + t.substr(0, i);
            s.insert(y);
        }
    }
    return ans;
}

// alternate
// O(N ^ 2) time | O(N) space
int solve(vector<string>& words) {
    unordered_set<string> s;
    int ans = 0;
    for(string ss : words){
        bool found = false;
        for(int i = 0; i <= ss.size(); i++){
            rotate(ss.begin(), ss.begin() + 1, ss.end());
            if(s.count(ss))
                found = true;
        }
        if(not found) ans++;
        s.insert(ss);
    }
    return ans;
}
