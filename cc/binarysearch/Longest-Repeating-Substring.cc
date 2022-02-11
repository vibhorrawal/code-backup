// O(N^3) time | O(N) space
int find(const string &sub, const string &s){ // O(N) time
    int pos = s.find(sub);
    int cnt = 0;
    while(pos != -1){ 
        cnt++;
        pos = s.find(sub, pos+1);
    }
    return cnt;
}
int solve(string s) {
    int n = s.size();
    for(int sz = n; sz > 0; sz--){
        for(int i = 0; i + sz < n; i++){
            string sub = s.substr(i, sz);
            if(find(sub,s) >= 2) return sz;
        }
    }
    return 0;
}

// O(N^2) time | O(1) space
// using lps (longest proper prefix, which is also suffix)
int find(const string &s){  //O(N)
    vector<int> lps(s.size());
    lps[0] = 0;
    int len = 0, i = 1;
    while(i < s.size()){
        if(s[i] == s[len]){
            lps[i] = ++len;
            i++;
        }
        else {
            if(len) len = lps[len-1];
            else i++;
        }
    }
    return *max_element(lps.begin(), lps.end());
}
int solve(string s) {
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        string sub = s.substr(i);
        ans = max(ans, find(sub));
    }
    return ans;
}