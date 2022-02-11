// O(N) space | O(logN) time
string solve(int n) {
    string res;
    while(n){
        res += string(1, 'A' + ((n-1) % 26) % 26);
        n = (n-1) / 26;
    }
    reverse(res.begin(), res.end());
    return res;
}

// cleaner, but i think mathematical way is the above one or below one
string solve(int n) {
    string res;
    while(n) {
        int val = n % 26;
        if(val == 0) {
            val = 26;
            n--;
        }
        res += string(1, 'A' + val - 1);
        n /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}

// mapping 1-27 -> 0-26
string solve(int n) {
    string res;
    while(n) {
        n--;
        int val = n % 26;
        res += string(1, 'A' + val);
        n /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}