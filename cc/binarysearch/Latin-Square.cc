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
