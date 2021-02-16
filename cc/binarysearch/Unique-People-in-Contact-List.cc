// O(N) time and space
int solve(vector<vector<string>>& c) {
    unordered_set<string> s;
    int ans = 0;
    for(int i = 0; i < c.size(); i++){
        int j = 0;
        for(; j < c[i].size(); j++){
            if(s.count(c[i][j])) break;
            s.insert(c[i][j]);
            if(j == c[i].size()-1) ans++;
        }
        for(; j < c[i].size(); j++){
            s.insert(c[i][j]);
        }
    }
    return ans;
}

// cleaner
int solve(vector<vector<string>>& contact) {
    unordered_set<string> s;
    int ans = 0;
    for(auto &c : contact){
        bool seen = false;
        for(string &email : c){
            if(not s.insert(email).second)
                seen = true;
        }
        if(not seen) ans++;
    }
    return ans;
}
