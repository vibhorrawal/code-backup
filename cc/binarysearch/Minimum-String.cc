// O(n) time and space
int solve(string s, string t) {
    map<char,int> freq;
    for(char c : s) freq[c]++;
    int res = 0;
    for(char c : t){
        if(freq[c] == 0) res++;
        else{
            if(freq[c] == 1) freq.erase(freq.find(c));
            else freq[c]--;
        }
    }
    return res;
}

// cleaner
int solve(string s, string t) {
    unordered_map<char,int> freq;
    for(char c : s) freq[c]++;
    for(char c : t) freq[c]--;
    // at this moment, either count +ve or -ve
    int ans = 0;
    for(char c = 'a'; c <= 'z'; c++) {
        if(freq[c] <= 0) continue;
        ans += freq[c];
    }
    return ans;
}