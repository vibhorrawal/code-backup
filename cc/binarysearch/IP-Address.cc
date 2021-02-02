// O(N) time 
bool check(string s){
    for(char c : s)
        if('9' < c || c < '0') return true;
    int n = stoi(s);
    if(255 < n || n < 0) return true;
    return false;
}
bool solve(string s) {
    stringstream ss(s);
    int count = 0;
    while(getline(ss, s, '.')){
        count++;
        if(s.size() > 1 && s[0] == '0')
            return false;
        bool fail = check(s);
        if(fail) return false;
    }
    return count==4;
}
