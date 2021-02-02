// O(N) time | O(1) space
int solve(vector<int>& nums) {
    int res = 0;
    int odd = 0, even = 0;
    for(int x : nums){
        if(x & 1){
            res += even;
            odd++;
        }
        else{
            res += odd;
            even++;
        }
    }
    return res;
}

// shorter code odd only with odd + even
int solve(vector<int>& a) {
    int cnt = 0, n = a.size();
    for(int x : a) cnt += x & 1;
    return (n - cnt) * cnt;
}
