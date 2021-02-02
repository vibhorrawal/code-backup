// O(nk) time and space
int solve(string s, int k) {
    unordered_set<string> seen, more_than_once;
    for(int i = 0; i < s.size(); i++){
        string t = s.substr(i,k);
        if(t.size() != k) break;
        if(seen.count(t)){
            more_than_once.insert(t);
        }
        seen.insert(t);
    }
    return more_than_once.size();
}

// cleaner
int solve(string s, int k) {
    unordered_map<string,int> freq;
    string t = s.substr(0, k);
    freq[t]++;
    for(int i = k; i < s.size(); i++){
        t.erase(t.begin());
        t.push_back(s[i]);
        freq[t]++;
    }
    int cnt = 0;
    for(auto [i,c] : freq) {
        if(c > 1) cnt++;
    }
    return cnt;
}

// rabin karp rolling hash
int solve(string s, int k) {
    unordered_map<long long,int> freq;
    long long rolling = 0, p = 1;
    for(int i = 0; i < k; i++){
        rolling = rolling * 26 + s[i];
        p *= 26;
    }
    p /= 26;
    freq[rolling]++;
    for(int i = k; i < s.size(); i++){
        rolling -= p * s[i-k];
        rolling = rolling * 26 + s[i];
        freq[rolling]++;
    }
    int cnt = 0;
    for(auto [i,c] : freq) {
        if(c > 1) cnt++;
    }
    return cnt;
}
