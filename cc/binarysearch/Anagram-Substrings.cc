int hash2(char c){
    return c * c + c * c * c + 1e5+1;
}

int solve(string s0, string s1) {
    if(s0.size() > s1.size())
        return 0;
    long hashval = 0;
    for(char c : s0) hashval += hash2(c);
    long hs = 0;
    for(int i = 0; i < s0.size(); i++){
        hs += hash2(s1[i]);
    }

    int k = s0.size(), ans = 0;
    if(hs == hashval) ans++;
    for(int i = s0.size(); i < s1.size(); i++){
        hs += hash2(s1[i]) - hash2(s1[i-k]);
        if(hs == hashval)
            ans++;
    }
    return ans;
}


// same as above
// O(N) time | O(1) space (Rolling Hash)
hash<long> h;

long hs(long i){
    return h(i * i * i + (1e9 + 5) * i + i);
}
int solve(string s0, string s1) {
    if(s0.size() > s1.size()) return 0;
    long h0 = 0, h1 = 0, ans = 0, n = s0.size();
    for(char c : s0) h0 += hs(c);
    for(int i = 0; i < n; i++) h1 += hs(s1[i]);
    ans += h0 == h1;
    for(int i = n; i < s1.size(); i++){
        h1 += hs(s1[i]) - hs(s1[i-n]);
        ans += h0 == h1;
    }
    return ans;
}

// O(N * ALPHABET) time | O(ALPHABET) space
int solve(string s0, string s1) {
    if(s0.size() > s1.size()) return 0;
    vector<int> v0(26), v1(26);
    int n = s0.size(), ans = 0;
    for(char c : s0) v0[c - 'a']++;
    for(int i = 0; i < n; i++) v1[s1[i] - 'a']++;
    ans += v0 == v1;
    for(int i = n; i < s1.size(); i++){
        v1[s1[i] - 'a']++;
        v1[s1[i-n] - 'a']--;
        ans += v0 == v1;
    }
    return ans;
}
