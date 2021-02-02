string solve(int n) {
    string res = to_string(n);
    while(res.size() < 3) res = "0" + res;
    reverse(res.begin(), res.end());
    res.insert(2, ".");
    int i = 6;
    while(i < res.size()){
        res.insert(i, ",");
        i += 4;
    }
    reverse(res.begin(), res.end());
    return res;
}

// neater implementation with same O(n) time and space
string solve(int n) {
    int cents = n % 100;
    int dollars = n / 100;
    string s;
    int i = 1;
    while(dollars){
        s = to_string(dollars % 10) + s;
        dollars /= 10;
        if(i % 3 == 0 and dollars) s = ","+ s;
        i++;
    }
    if(s.empty()) s = '0';
    s += ".";
    s += to_string(cents/10) + to_string(cents % 10);
    return s;
}
