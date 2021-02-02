// O(26 + n) space | O(n) time
string solve(string text) {
    int i = 0, j = 25;
    map<char,char> mp;
    for(int c = 0; c < 26; c++){
        mp['a' + i++] = 'a' + j--;
    }
    string res;
    for(char c : text) res += mp[c];
    return res;
}

// O(n) time | O(1) space
string solve(string s) {
    for(char &c : s){
        c = 'z' - c + 'a';
    }
    return s;
}
