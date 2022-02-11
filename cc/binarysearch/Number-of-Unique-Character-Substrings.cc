// O(n) time | O(1) space
int solve(string s) {
    int len = 0;
    char prev = -1;
    int ans = 0;
    for(char c : s){
        if(c == prev) len++;
        else{
            if(len)
                ans += len * (len + 1) /2;
            len = 1;
            prev = c;
        }
    }
    return ans + len * (len + 1) /2;
}

// O(n) time | O(1) space
int solve(string s) {
    int ans = 0, len = 0;
    char prev = '#';
    for(char c : s){
        if(prev == c) len++;
        else len = 0;
        prev = c;
        ans += len + 1;
    }
    return ans;
}

// O(N) time | O(1) space
// aaaa => a a a a + aa aa aa + aaa aaa + aaaa
// Sn(4)=>     4   +    3     +    2    +  1
int sn(int n) { return n * (n+1) / 2; }
int solve(string s) {
    int ans = 0;
    for(int i = 0; i < s.size();) {
        int cnt = 0;
        while(i+cnt < s.size() and s[i] == s[i+cnt]) cnt++;
        ans += sn(cnt);
        i += cnt;
    }
    return ans;
}