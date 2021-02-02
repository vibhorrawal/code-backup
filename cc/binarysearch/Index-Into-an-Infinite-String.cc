string solve(string s, int i, int j) {
    int n = s.size();
    int start = i;
    while(start % n) start++;
    int end = j;
    string res;
    while(end % n) end--;
    if(i % n >= j % n){
        if(i%n) res += s.substr(i%n);
        for(int i = start; i < end; i += n) res += s;
        if(j%n) res += s.substr(0, j % n);
        return res;
    }
    else{
        if(j - i <= n){
            return s.substr(i%n,j%n - i%n);
        }
        if(i%n) res += s.substr(i%n);
        for(int i = start; i < end; i += n) res += s;
        if(j%n) res += s.substr(0, j % n);
        return res;
    }
}

// simpler
string solve(string s, int i, int j) {
    string res;
    int n = s.size();
    for(int c = i; c < j; c++)
        res += s[c % n];
    return res;
}
