// O(N) time | O(1) space
bool equal(string a, string b){
    bool changed = false;
    for(int i = 0, j = 0; i < a.size(); i++, j++){
        if(a[i] != b[j]){
            if(changed) return false;
            changed = true;
        }
    }
    return true;
}

bool removing(string b, string a){
    bool removed = false;
    int j = 0;
    for(int i = 0; i < a.size(); i++, j++){
        if(a[i] != b[j]){
            if(removed) return false;
            removed = true;
            j--;
        }
    }
    return j == b.size();
}
bool solve(string s0, string s1) {
    if(s0.size() == s1.size())
        return equal(s0,s1);
    if(s0.size() > s1.size())
        swap(s0,s1);
    return removing(s0,s1);
}