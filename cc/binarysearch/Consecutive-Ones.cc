// O(N) time | O(1) space
bool solve(vector<int>& a) {
    bool one_used = false, one = false;
    for(int x : a){
        if(x == 1){
            if(one_used) return false;
            one = true;
        }
        else {
            if(one) {
                one = false;
                one_used = true;
            }
        }
    }
    return true;
}

// elegant
bool solve(vector<int>& a) {
    int seen = 0;
    // 0 -> not seen
    // 1 -> currently 1
    // 2 -> one seen already
    for(int x : a){
        if(x == 1){
            if(seen == 2) return false;
            seen = 1;
        }
        else {
            if(seen == 1) seen = 2;
        }
    }
    return true;
}

// another
bool solve(vector<int>& a) {
    int i = 0;
    while(i < a.size() and a[i] != 1) i++;
    while(i < a.size() and a[i] == 1) i++;
    while(i < a.size()) if(a[i++] == 1) return false;
    return true;
}
