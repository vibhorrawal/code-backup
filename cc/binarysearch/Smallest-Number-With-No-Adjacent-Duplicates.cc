string solve(string s) {
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '?') continue;
        set<char> nbr;
        if(i) nbr.insert(s[i-1]);
        if(i+1 < s.size()) nbr.insert(s[i+1]);
        for(int v : {'1','2','3'}){
            if(not nbr.count(v)) {
                s[i] = v;
                break;
            }
        }
    }
    return s;
}
