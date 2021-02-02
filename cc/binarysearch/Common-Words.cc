// O(s0) space and O(s0 + s1) time
int solve(string s0, string s1) {
    set<string> s;
    stringstream ss0(s0);
    string t;
    while(getline(ss0, t, ' ')){
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        s.insert(t);
    }
    stringstream ss1(s1);
    int count = 0;
    while(getline(ss1, t, ' ')){
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        if(s.count(t)){
            count++;
            s.erase(t);
        }

    }
    return count;
}
