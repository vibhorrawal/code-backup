// O(STRING_SIZE) time [pow is O(1) architecture dependent but independent of passed values]
int solve(string s, int k) {
    set<char> use;
    for(char c : s) use.insert(c);
    k = (k+1) / 2;
    return pow(use.size(),k);
}
