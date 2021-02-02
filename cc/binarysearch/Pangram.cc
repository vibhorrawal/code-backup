// O(n) time | O(A) space, A is size of alphabets ie 26
bool solve(string s) {
    bool alpha[26] = {0};
    for(char c : s){
        if('a' <= c && c <= 'z') alpha[c-'a'] = 1;
        if('A' <= c && c <= 'Z') alpha[c-'A'] = 1;
    }
    int a = 1;
    for(int i = 0; i < 26; i++) a *= alpha[i];
    return a;
}

// shorter code
bool solve(string s) {
    set<char> ss;
    for(char c : s) if(isalpha(c)) ss.insert(tolower(c));
    return ss.size() == 26;
}
