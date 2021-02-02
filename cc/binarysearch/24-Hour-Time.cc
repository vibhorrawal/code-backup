// O(n) time and space
string solve(string s) {
    if(s[0] == '1' && s[1] == '2'){
        s[0] = s[1] = '0';
    }
    if(s[5] == 'p') {
        int c = (s[0] - '0') * 10 + (s[1] - '0');
        c += 12;
        s[0] = c/10 + '0';
        s[1] = c % 10 + '0';
    }

    s.erase(5);
    return s;
}
