// O(N) time | O(1) space
const int MOD = 1e9+7;

int solve(vector<int>& a) {
    long long l = 0, r = a.size()-1;
    long long n = a.size();
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + (n - i) * (i + 1) * a[i]) % MOD;
    }
    return ans;
}
