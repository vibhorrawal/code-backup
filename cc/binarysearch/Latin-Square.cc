bool solve(vector<vector<string>>& matrix) {
    set<string> s;
    for(auto it : matrix) for(string c : it) s.insert(c);
    if(s.size() != matrix.size())
        return false;
    for(string c : s){
        for(int i = 0; i < matrix.size(); i++){
            bool present = true;
            for(int j = 0; j < matrix.size(); j++){
                if(c == matrix[i][j]){
                    if(present) present = false;
                    else return false;
                }
            }
            if(present) return false;
        }

        for(int i = 0; i < matrix.size(); i++){
            bool present = true;
            for(int j = 0; j < matrix.size(); j++){
                if(c == matrix[j][i]){
                    if(present) present = false;
                    else return false;
                }
            }
            if(present) return false;
        }
    }
    return true;
}

// O(n^2) time | O(n) space
bool solve(vector<vector<string>>& a) {
    int n = a.size(), cnt = 0;
    map<string,int> mp;
    for(auto it : a) {
        for(string s : it) {
            if(not mp.count(s)) cnt++;
            mp[s]++;
        }
    }
    if(cnt != n or mp.size() != n) return false;
    for(int i = 0; i < n; i++){
        set<string> s;
        for(int j = 0; j < n; j++){
            s.insert(a[i][j]);
        }
        if(s.size() != n) return false;
    }
    for(int j = 0; j < n;j++){
        set<string> s;
        for(int i = 0; i < n; i++){
            s.insert(a[i][j]);
        }
        if(s.size() != n) return false;
    }
    return true;
}

// cleaner and shorter
bool solve(vector<vector<string>>& m) {
    int n = m.size();
    set<string> row[n], col[n], seen;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            row[i].insert(m[i][j]);
            col[j].insert(m[i][j]);
            seen.insert(m[i][j]);
        }
    }
    for(int i = 0; i < n; i++) {
        if(row[i].size() != n or col[i].size() != n) return false;
    }
    return seen.size() == n;
}

// using bits saving O(N) space (chars-> 26 < 32)
bool insertAndCheck(int &set, string s) {
    int c = s[0] - 'a';
    if(set & (1<<c)) return true; // exists already
    set |= (1<<c);
    return false;
}

bool solve(vector<vector<string>>& m) {
    int n = m.size(), seen = 0;
    for(int i = 0; i < n; i++) {
        int row = 0;
        for(int j = 0; j < n; j++) {
            if(insertAndCheck(row, m[i][j])) return false;
            insertAndCheck(seen, m[i][j]);
        }
    }

    for(int j = 0; j < n; j++) {
        int col = 0;
        for(int i = 0; i < n; i++) {
            if(insertAndCheck(col, m[i][j])) return false;
        }
    }
    return __builtin_popcount(seen) == n;
}