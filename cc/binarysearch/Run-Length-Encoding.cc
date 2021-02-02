// O(N) time and space
string solve(string s) {
    string res;
    char prev = '#';
    int count = 0;
    for(char c : s){
        if(c == prev){
            count++;
        }
        else{
            if(count) res += to_string(count) + prev;
            count = 1;
            prev = c;
        }
    }
    res += to_string(count) + prev;
    return res;
}

// cleaner
string solve(string s) {
    string res;
    int i = 0;
    while(i < s.size()){
        int j = i;
        while(j < s.size() and s[i] == s[j]) j++;
        res += to_string(j - i) + s[i];
        i = j;
    }
    return res;
}
