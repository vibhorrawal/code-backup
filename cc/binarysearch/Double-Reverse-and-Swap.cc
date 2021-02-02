// O(2^n) space and time
void change(string &s){
    for(char &c : s) if(c == 'x') c = 'y';
    else c = 'x';
}
string solve(int n) {
    string res = "xxy";
    if(n == 0) return res;
    // n++;
    while(1){
        res = res + res;
        if(--n <=0) return res;

        reverse(res.begin(), res.end());
        if(--n <=0) return res;

        change(res);
        if(--n <=0) return res;
    }
    return res;
}
