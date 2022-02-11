// O(N) time and O(1) space
bool odd(int n){
    int cnt = 0;
    while(n){
        n /= 10;
        cnt++;
    }
    return cnt & 1;
}
int solve(vector<int>& a) {
    int ans = 0;
    for(int &x : a) ans += odd(x);
    return ans;
}

// cleaner
int solve(vector<int>& nums) {
    int ans = 0;
    for(int num : nums) ans += int(1 + log10(num)) % 2;
    return ans;
}