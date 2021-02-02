// O(n) time and space
int solve(string s) {
    int n = s.size();
    vector<int> ones(n);
    ones.back() = s.back() == '1';
    for(int i = n-2; i >= 0; i--){
        ones[i] = ones[i+1] + (s[i] == '1');
    }
    int ans = 0, z = 0;
    for(int i = 0; i < n-1; i++){
        z += s[i] == '0';
        ans = max(ans, z + ones[i+1]);
    }
    return ans;
}

// O(n) time | O(1) sapce
int solve(string s) {
    int ones = 0, zeros = 0, ans = 0;
    for(char c : s) ones += c == '1';
    for(int i = 0; i < s.size()-1; i++){
        s[i] == '1' ? ones-- : zeros++;
        ans = max(ans, ones + zeros);
    }
    return ans;
}
