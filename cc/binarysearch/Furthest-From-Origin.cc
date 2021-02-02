// O(n) time | O(1) space
int solve(string s) {
    int pos = 0, q = 0;
    for(char c : s){
        if(c == 'L') pos--;
        else if(c == 'R') pos++;
        else q++;
    }
    return abs(pos) + q;
}
