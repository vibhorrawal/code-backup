// O(n) time
string solve(string s, int k) {
    for(char &c : s){
        int al = c - 'a';
        al = (((al + k) % 26) + 26) % 26;
        c = al + 'a';
    }
    return s;
}
