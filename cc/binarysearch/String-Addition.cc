// O(N) time and space
string solve(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string res;
    int i = 0, j = 0, n = 0, c = 0;
    while(i < a.size() && j < b.size()){
        n = (a[i++] - '0') + (b[j++] - '0') + c;
        c = n/10;
        n %= 10;
        res += n + '0';
    }
    while(i < a.size()){
        n = (a[i++] - '0') + c;
        c = n/10;
        n %= 10;
        res += n + '0';
    }
    while(j < b.size()){
        n = (b[j++] - '0') + c;
        c = n/10;
        n %= 10;
        res += n + '0';
    }
    if(c) res += c + '0';
    reverse(res.begin(), res.end());
    return res;
}

// cleaner
string solve(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string res;
    int i = 0, j = 0, c = 0;
    while(i < a.size() or j < b.size()){
        int x = i == a.size() ? 0 : a[i++] - '0';
        int y = j == b.size() ? 0 : b[j++] - '0';
        int d = x + y + c;
        c = d / 10;
        d %= 10;
        res += char(d + '0');
    }
    if(c) res += char(c + '0');
    reverse(res.begin(), res.end());
    return res;
}
