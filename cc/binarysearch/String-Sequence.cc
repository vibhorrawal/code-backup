// O(n) time and space
string solve(string s0, string s1, int n) {
    if(n == 0) return s0;
    if(n == 1) return s1;
    string b = s1, a = s0;
    for(int i = 2; i <= n; i++){
        string new_b;
        if(i % 2 == 0)
            new_b = b + a;
        else
            new_b = a + b;
        a = b;
        b = new_b;
    }
    return b;
}
