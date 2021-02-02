// O(N) time and space
string solve(string s) {
    string res;
    int i = 0;
    while(i < s.size()){

        int start = i;
        while('0' <= s[i] && s[i] <= '9') i++;
        // cout<<s.substr(start, i-start)<<endl;
        int c = s[i++];
        int count = stoi(s.substr(start, i-start));
        for(int k = 0; k < count; k++) res += c;
    }
    return res;
}

// cleaner
string solve(string s) {
    string res;
    int i = 0;
    while(i < s.size()){
        int d = 0;
        while(isdigit(s[i])) {
            d = d * 10 + s[i] - '0';
            i++;
        }
        for(int rep = 0; rep < d; rep++) res += s[i];
        i++;
    }
    return res;
}
