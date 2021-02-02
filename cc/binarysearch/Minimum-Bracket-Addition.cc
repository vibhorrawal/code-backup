// O(N) time | O(1) space
int solve(string s) {
    int bal = 0, ans = 0;
    for(char c : s){
        if(c == '('){
            bal++;
        }
        else{
            if(bal <= 0) {
                ans++;
                bal = 0;
            }
            else bal--;
        }
    }
    return bal + ans;
}

// alternative approach O(n^2)
int solve(string s) {
    while(s.find("()") != string::npos){
        s.erase(s.find("()"), 2);
    }
    return s.size();
}
