bool solve(string s0, string s1) {
    if(s0.size() != s1.size() + 1)
        return false;
    int i = 0, j = 0;
    bool removed = false;
    while(i < s0.size() && j < s1.size()){
        if(s0[i] == s1[j]){
            i++;
            j++;
        }
        else{
            if(removed) return false;
            removed = true;
            i++;
        }
    }
    return true;
}

// cleaner
bool solve(string a, string b) {
    bool removed = false;
    int j = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[j])
            j++;
        else if(removed)
            return false;
        else
            removed = true;
    }
    return removed and j == b.size();
}
