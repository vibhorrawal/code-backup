// O(logn)
string solve(int n) {
    string res;
    bool neg = false;
    if(n < 0) {
        neg = true;
        n = -n;
    }
    while(n){
        res += to_string(n % 3);
        n /= 3;
    }
    if(neg) res += "-";
    reverse(res.begin(), res.end());
    return res;
}
