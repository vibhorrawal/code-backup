// O(n) time | O(1) space
int solve(string s) {
    int maxl = 0, l = 0, ch = '#';
    for(char c : s){
        if(ch == c) l++;
        else {
            ch = c;
            l = 1;
        }
        maxl = max(l,maxl);
    }
    return maxl;
}

// another way [same]
int solve(string s) {
    int ans = 0;
    for(int i = 0; i < s.size();){
        int j = i, len = 0;
        char ch = s[i];
        while(ch == s[j]){
            len++, j++;
        }
        ans = max(ans, len);
        i = j;
    }
    return ans;
}
