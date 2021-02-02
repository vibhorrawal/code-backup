// O(|L| + |W| * |N|) time | O(|L| + |N|) space
int solve(vector<string>& words, string letters) {
    map<char, int> freq;
    for(char c : letters) freq[c]++;
    int maxlen = 0;
    for(string t : words){
        map<char, int> f;
        for(char c : t) f[c]++;
        bool flag = true;
        for(auto it : f){
            if(it.second > freq[it.first])
                flag = false;
        }
        if(flag) maxlen = max((int) t.size(), maxlen);
    }
    return maxlen;
}

// elegant
// O(|L| + |W| * |N|) time | O(1) space
int solve(vector<string>& w, string l) {
    vector<int> dl(26);
    for(char c : l) dl[c - 'a']++;
    int ans = 0;
    for(string &s : w){
        int len = 0;
        vector<int> ds = dl;
        for(char c : s) {
            if(ds[c - 'a']-- > 0){
                len++;
            }
            else {
                len = 0;
                break;
            }
        }
        ans = max(ans, len);
    }
    return ans;
}
