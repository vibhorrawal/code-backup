// O(N * ALPHA) space time
int equal(string a, string b){
    map<char,int> freq;
    for(char c : a) freq[c]++;
    for(char c : b) freq[c]++;
    int mx = 0,ch;
    for(auto [i,c] : freq){
        if(mx < c){
            ch = i, mx = c;
        }
    }
    int ans = 0;
    for(auto [i,c] : freq){
        if(i == ch) continue;
        ans += c;
    }
    return ans;
}

int lesser(string a, string b){
    int ans = INT_MAX;
    for(char c = 'a'-1; c <= 'z'+1; c++){
        int t = 0;
        for(char x : a) {
            if(x >= c) t++;
        }
        for(char x : b) {
            if(x < c) t++;
        }
        ans = min(ans, t);
    }
    return ans;
}

int greater1(string a, string b){
    return lesser(b,a);
}

int solve(string s) {
    int n = s.size();
    string s1 = s.substr(0,n/2);
    string s2 = s.substr(n/2);
    return min({equal(s1,s2), lesser(s1,s2), greater1(s1,s2)});
}
