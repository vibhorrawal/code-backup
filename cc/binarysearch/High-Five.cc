// O(31)
int solve(int n) {
    string s = to_string(n);
    int i = 0;
    if(s[0] == '-') {
        i = 1;
        while(i < s.size() && s[i] <= '5') i++;
    }
    else while(i < s.size() && s[i] >= '5') i++;
    s.insert(i, "5");
    return stoi(s);
}
