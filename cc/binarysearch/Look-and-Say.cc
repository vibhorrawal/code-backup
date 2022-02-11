// O(N^2) time | O(N) space
string solve(int n) {
    if(n <= 1) return "1";
    string s = solve(n-1);
    string res;
    for(int i = 0; i < s.size();){
        int cnt = 0; char c = s[i];
        while(c == s[i]) {
            i++; cnt++;
        }
        res += to_string(cnt) + string(1,c);
    }
    return res;
}