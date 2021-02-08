string solve(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int c = 0, s = 0;
    string res;
    int i = 0, j = 0;
    for(;i < a.size() or j < b.size(); i++,j++){
        bool ai = i >= a.size() ? 0 : a[i] - '0',
        bj = j >= b.size() ? 0 : b[j] - '0';
        s = ai ^ bj ^ c;
        c = (ai & bj) or (ai & c) or (bj & c);
        res += to_string(s);
    }
    if(c) res += to_string(c);
    reverse(res.begin(), res.end());
    return res;
}

// O(A + B) time | space
string solve(string a, string b) {
    string res;
    int i = a.size()-1, j = b.size()-1, carry = 0;
    while(i >= 0 or j >= 0){
        int x = i >= 0 ? a[i--] - '0' : 0;
        int y = j >= 0 ? b[j--] - '0' : 0;
        int digit = x + y + carry;
        carry = digit / 2;
        digit %= 2;
        res += char(digit + '0');
    }
    if(carry) res += '1';
    reverse(res.begin(), res.end());
    return res;
}
