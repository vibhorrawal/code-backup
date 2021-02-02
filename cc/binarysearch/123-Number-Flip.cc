// O(logn) time and space
int solve(int n) {
    string s = to_string(n);
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '3'){
            s[i] = '3';
            return stoi(s);
        }
    }
    return n;
}
