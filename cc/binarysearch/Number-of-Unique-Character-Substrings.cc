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
