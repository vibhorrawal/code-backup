// O(n) time
string solve(string s) {
    string res;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'y') continue;
        if(i < s.size() -1 && s[i] == 'x' && s[i+1] == 'z') {
            i++;
            continue;
        }
        res += s[i];
    }
    return res;
}
