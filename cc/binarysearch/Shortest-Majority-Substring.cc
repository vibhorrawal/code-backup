int solve(string s) {
    bool is2 = false, is3 = false;
    for(int i = 0; i < s.size(); i++){
        if(i+1 < s.size() && s[i] == s[i+1])
            is2 = true;
        if(i+2 < s.size() && s[i] == s[i+2])
            is3 = true;
    }
    if(is2) return 2;
    if(is3) return 3;
    return -1;
}
