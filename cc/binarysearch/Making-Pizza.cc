// O(n) time | O(n) space
int solve(string s) {
    map<char,int> freq;
    for(char c : s) freq[c]++;
    return min({freq['p'], freq['i'], freq['z']/2, freq['a']});
}
