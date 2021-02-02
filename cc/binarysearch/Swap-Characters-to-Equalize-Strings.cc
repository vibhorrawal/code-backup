// O(|S| * |T|) space and time
bool solve(string s, string t) {
    map<char,int> count;
    for(char c : s) count[c]++;
    for(char c : t) count[c]++;
    for(auto it : count) if(it.second % 2) return false;
    return true;
}
