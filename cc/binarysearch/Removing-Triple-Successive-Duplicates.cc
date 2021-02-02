int solve(string s) {
    int count = 0, freq = 0, curr = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != curr){
            curr = s[i];
            freq = 1;
        }
        else{
            freq++;
        }
        if(freq == 3){
            if(i < s.size() && s[i+1] != curr){
                count++;
                freq = 1;
            }
            else{
                count++;
                freq = 1;
                curr = -1;
            }
        }
    }
    return count;
}

// same
int solve(string s) {
    char prev = '#';
    int count = 0, last_same = 0;
    for(char c : s){
        if(prev == c){
            last_same++;
        }
        else{
            last_same = 1;
        }
        prev = c;
        if(last_same == 3){
            count++;
            last_same = 1;
            prev = -1;
        }
    }
    return count;
}

// alternative
int solve(string s) {
    int cnt = 0;
    for(int i = 0; i < s.size();){
        int j = i;
        while(j < s.size() and s[i] == s[j]) j++;
        cnt += (j - i) / 3;
        i = j;
    }
    return cnt;
}


// alternative
int count_substr(const string &s, const string &sub) {
    int cnt = 0, pos = 0;
    while((pos = s.find(sub, pos)) != string::npos){
        pos += sub.size();
        cnt++;
    }
    return cnt;
}
int solve(string s) {
    return count_substr(s, "000") + count_substr(s, "111");
}
