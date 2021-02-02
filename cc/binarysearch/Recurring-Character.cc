// O(N) time and space
int solve(string s) {
    set<char> vis;
    int i = 0;
    for(char c : s){
        if(vis.count(c)) return i;
        vis.insert(c);
        i++;
    }
    return -1;
}
