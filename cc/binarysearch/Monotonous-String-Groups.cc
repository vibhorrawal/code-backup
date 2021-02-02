int solve(string s) {
    int prev = 0, count = 0;
    bool just = false;
    for(int i = 1; i < s.size(); i++){
        if(just){
            just = false;
            prev = 0;
            // continue;
        }
        if(s[i] > s[i-1]){
            // cout<<i<<' '<<1<<' '<<s[i-1]<<' '<<s[i]<<endl;
            if(prev < 0) {
                count++;
                just = true;
            }
            prev = 1;
        }
        else if(s[i] < s[i-1]){
            // cout<<i<<' '<<2<<' '<<s[i-1]<<' '<<s[i]<<endl;
            if(prev > 0) {
                count++;
                just = true;
            }
            prev = -1;
        }
    }
    return count + !s.empty();
}

// cleanest and best method
int solve(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        ans++;
        int j = i;
        bool non_inc = true;
        bool non_dec = true;
        while(j+1 < s.size()){
            if(s[j+1] > s[j]) non_inc = false;
            if(s[j+1] < s[j]) non_dec = false;
            if(!non_dec && !non_inc) break;
            j++;
        }
        i = j;
    }
    return ans;
}

int solve(string t) {
    if(t.empty()) return 0;
    int ans = 0, i = 0;
    string s;
    s += t[0];
    for(int i = 1; i < t.size(); i++){
        if(t[i] == t[i-1]) continue;
        s += t[i];
    }
    while(i < s.size()){
        ans++;
        if(i + 1 == s.size()) break;
        if(s[i] < s[i+1]){
            while(i+1 < s.size() && s[i] < s[i+1]) i++;
        }
        else{
            while(i+1 < s.size() && s[i] > s[i+1]) i++;
        }
        i++;
    }
    return ans;
}

int solve(string s) {
    s.erase(unique(s.begin(), s.end()), s.end());
    if(s.size() < 2) return s.size();
    // cout<<s;
    int ans = 0, i = 0;
    while(i < s.size()){
        if(s[i] < s[i+1]){
            while(i+1 < s.size() and s[i] < s[i+1]) i++;
        }
        else{
            while(i+1 < s.size() and s[i] > s[i+1]) i++;
        }
        i++;
        ans++;
    }
    return ans;
}
