// O(n) time 
int solve(string s) {
    int res = 0;
    int i = 0;
    while(i < s.size()){
        res *= 3;
        res += s[i++] - '0';
    }
    return res;
}

int solve(string s) {
    int i = s.size()-1;
    int res = 0, p = 1;
    while(i >= 0){
        res += p * (s[i--] - '0');
        p *= 3;
    }
    return res;
}
