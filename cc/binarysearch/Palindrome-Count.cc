int solve(string s, int k) {
    set<char> use;
    for(char c : s) use.insert(c);
    k = (k+1) / 2;
    return pow(use.size(),k);
}
